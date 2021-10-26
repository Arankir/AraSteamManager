#include "formachievements.h"
#include "ui_formachievements.h"

#define Init {
FormAchievements::FormAchievements(const SProfile &aProfile, const SGame &aGame, QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements),
                                   _profile(aProfile), _game(aGame) {
    ui->setupUi(this);
    init();
}

FormAchievements::FormAchievements(QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements) {
    ui->setupUi(this);
    init();
}

void FormAchievements::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initingTable(ui->TableViewMyAchievements);
    ui->TabWidget->setCurrentIndex(FormAchievementsData::TabStandart);
    ui->splitter->setStretchFactor(0, 0);
    ui->splitter->setStretchFactor(1, 1);
    updateIcons();
#define InitFilters {
    _achievementsModel = new AchievementsModel();
//    _filterName     .addRow(AchievementTitle);
//    _filterName     .addRow(AchievementDescription);
//    _filterReached  .setFilterKeyColumn(AchievementReachedMy);
//    _filterFavorite .setFilterKeyColumn(AchievementAppid);
//    _filterName     .setFilterCaseSensitivity(Qt::CaseInsensitive);
//    _filterReached  .setFilterCaseSensitivity(Qt::CaseInsensitive);
//    _filterFavorite .setFilterCaseSensitivity(Qt::CaseInsensitive);
//    _filterReached  .setSourceModel(&_filterName);
//    _filterFavorite .setSourceModel(&_filterReached);
    ui->TableViewMyAchievements->setModel(&_filterAchievements);
#define InitFiltersEnd }
#define Connects {
    connect(ui->ButtonUpdate,               &QPushButton::clicked,                      this,   &FormAchievements::update);
    connect(ui->CheckBoxFavorites,          &QCheckBox::stateChanged,                   this,   &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonGuides,               &QPushButton::clicked,                      this,   &FormAchievements::openManual);
    connect(ui->TabWidget,                  &QTabWidget::currentChanged,                this,   &FormAchievements::tabWidget_CurrentChanged);
    connect(ui->FilterMyProfile,            &FormReachedFilter::s_radioButtonChange,    this,   &FormAchievements::updateFilterWithMyProfile);
    connect(ui->LineEditNameAchievements,   &QLineEdit::textChanged,                    this,   &FormAchievements::updateFilterTextAchievement);
    connect(ui->ButtonFindAchievement,      &QPushButton::clicked,                      this,   [=]() {
        ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
    });
    connect(ui->TreeWidgetCategories,       &FormCategoriesTree::s_categoryAdd,         this,   [=](Category *lCategory) {
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->addSubCategory(lCategory);
    });
    connect(ui->TreeWidgetCategories,       &FormCategoriesTree::s_categoryChange,      this,   [=](Category *lCategory) {
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->changeCategory(lCategory);
    });
    connect(ui->TreeWidgetCategories,       &FormCategoriesTree::s_categoryDelete,      this,   [=](Category *lCategory) {
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->deleteCategory(lCategory);
    });
    connect(ui->TreeWidgetCategories,       &FormCategoriesTree::s_stateChanged,        this,   &FormAchievements::updateFilterCategory);
    connect(ui->TableViewMyAchievements,    &QTableView::customContextMenuRequested,    this,   [=](QPoint pos) {
        QMenu *menu = createMenu(currentAchievement());
        menu->popup(ui->TableViewMyAchievements->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewMyAchievements,    &QTableView::doubleClicked,                 this,   [=](QModelIndex aIndex) {
        if (aIndex.column() == AchievementComments) {
            buttonComment_Clicked();
        }
    });
    connect(_achievementsModel, &AchievementsModel::s_progress, this, &Form::setStatus);
    connect(_achievementsModel, &AchievementsModel::s_finished, this, [=]() {
        _achievementsModel->sort(AchievementWorld, Qt::SortOrder::DescendingOrder);
        updateFilters();
        loading(false);

        if (_achievementsModel->rowCount() > 0) {
            int reachedCount = _achievementsModel->getReachedFromProfile(0);
            if (reachedCount > -1) {
                ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                               QString::number(reachedCount),
                                               QString::number(_achievementsModel->getAchievementsCount()),
                                               QString::number(100.0 * reachedCount / _achievementsModel->rowCount())));
                ui->FilterMyProfile->update();
            }
        }
        emit s_finished();
//        emit s_finish(ui->TableViewMyAchievements->viewport()->width() + 22);
    });
    connect(this, &FormAchievements::s_filtersUpdated,      ui->FriendsCompare, &FormFriendsCompare::setModel);
    connect(this, &FormAchievements::s_filtersValueUpdated, ui->FriendsCompare, &FormFriendsCompare::filtersValueUpdated);
    connect(ui->FriendsCompare, &FormFriendsCompare::s_startLoad,       this,   [=]() {
                                                                                    loading(true);
                                                                                });
    connect(ui->FriendsCompare, &FormFriendsCompare::s_progressLoad,    this,   &Form::setStatus);
    connect(ui->FriendsCompare, &FormFriendsCompare::s_finishLoad,      this,   [=]() {
                                                                                    clearStatus();
                                                                                    loading(false);
                                                                                });
    connect(ui->FriendsCompare, &FormFriendsCompare::s_addedFriend,     this,   &FormAchievements::hideFriendsColumns);
#define ConnectsEnd }
}

void FormAchievements::setData(const SProfile &aProfile, const SGame &aGame) {
    _profile = aProfile;
    _game = aGame;
    ui->labelProfileAvatar->setPixmap(_profile.pixmapAvatar());
    ui->labelProfileAvatar->setToolTip(_profile.personaName());
    ui->TreeWidgetCategories->setGame(_game);
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(_game.appId())));
    updateModel();
}

int FormAchievements::getAchievementsCount() {
    if (_achievementsModel) {
        return _achievementsModel->rowCount() - 1;
    }
    return 0;
}

void FormAchievements::updateModel() {
    loading(true);
    _achievementsModel->setAchievements(_profile.steamID(), _game.appId());
}
#define InitEnd }

#define System {
FormAchievements::~FormAchievements() {
    qInfo() << "Форма достижений удалилась";
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent *event) {
    event->accept();
}

SAchievement FormAchievements::currentAchievement() {
    QModelIndex index = ui->TableViewMyAchievements->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(AchievementIndex);
    QVariant fIndex = ui->TableViewMyAchievements->model()->data(index2);
    return _achievementsModel->getAchievement(fIndex.toInt());
}

void FormAchievements::loading(const bool &aIsLoading) {
    ui->FrameFilter->setEnabled(!aIsLoading);
    ui->TreeWidgetCategories->setEnabled(!aIsLoading);
    ui->ButtonUpdate->setEnabled(!aIsLoading);
    ui->TabWidget->setEnabled(!aIsLoading);
}

void FormAchievements::update() {
    updateModel();
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(_game.appId())));
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
    updateModel();
}

void FormAchievements::updateIcons() {
    ui->ButtonFindAchievement   ->setIcon(QIcon(Images::find()));
    ui->ButtonUpdate            ->setIcon(QIcon(Images::update()));
    ui->ButtonGuides            ->setIcon(QIcon(Images::guide()));
}

QMenu *FormAchievements::createMenu(const SAchievement &aAchievement) {
    QString appId = aAchievement.apiName();

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteAchievement> favorites = Favorites::achievementsGame(_profile.steamID(), _game).achievements();
    bool isFavorite = std::any_of(favorites.cbegin(),
                                  favorites.cend(),
                                  [=](FavoriteAchievement curFavorite) {
                                      return curFavorite.apiName() == appId;
                                  });
    if(isFavorite) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
    }

    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(QIcon(Images::isComment()), tr("Редактировать комментарий...     "), this);

    //Добавление кнопки руководств
    QAction *actionGuides = new QAction(QIcon(Images::guide()), tr("Перейти в руководства"), this);

    //Добавление кнопки обновления
    QAction *actionUpdate = new QAction(QIcon(Images::update()), tr("Обновить"), this);

    QMenu *menu = new QMenu(this);
    menu->addAction (actionFavorites);
    menu->addAction (actionComment);
    menu->addAction (actionGuides);
    menu->addAction (actionUpdate);

    connect (actionFavorites,   &QAction::triggered,    this,   &FormAchievements::buttonFavorite_Clicked);
    connect (actionComment,     &QAction::triggered,    this,   &FormAchievements::buttonComment_Clicked);
    connect (actionGuides,      &QAction::triggered,    this,   &FormAchievements::openManual);
    connect (actionUpdate,      &QAction::triggered,    this,   &FormAchievements::update);

    return menu;
}

void FormAchievements::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    updateIcons();
    ui->CategoriesEdit->updateSettings(aSettings);
    ui->FriendsCompare->updateSettings(aSettings);
    ui->FilterMyProfile->updateSettings(aSettings);
    emit s_settingsUpdated(aSettings);
}

void FormAchievements::updateCategories() {
    ui->TreeWidgetCategories->updateUi();
    _filterAchievements.setCategories(CategoriesFilter());
}
#define SystemEnd }

#define Filter {
void FormAchievements::updateFilters() {
    _filterAchievements.setSourceModel(_achievementsModel);
    QSortFilterProxyInvertModel *notFirstRow = new QSortFilterProxyInvertModel();
    notFirstRow->setSourceModel(&_filterAchievements);
    notFirstRow->setFilterKeyColumn(AchievementAppid);
    notFirstRow->setFilterRegExp("^$");

    if (auto model = ui->TableViewMyAchievements->model()) {
        if (auto filter = dynamic_cast<QSortFilterProxyInvertModel*>(model)) {
            filter->setSourceModel(nullptr);
            delete filter;
        }
    }
    emit s_filtersUpdated(&_filterAchievements);

    ui->TableViewMyAchievements->setModel(notFirstRow);
    ui->TableViewMyAchievements->setColumnHidden(AchievementAppid, true);
    ui->TableViewMyAchievements->setColumnHidden(AchievementIndex, true);
    ui->TableViewMyAchievements->resizeColumnsToContents();
    ui->TableViewMyAchievements->setColumnWidth(AchievementTitle, 220);
    ui->TableViewMyAchievements->setColumnWidth(AchievementDescription, 450);
    ui->TableViewMyAchievements->resizeRowsToContents();
    hideFriendsColumns();
}

void FormAchievements::updateFilterCategory(Category *aCategory, const bool &aIsChecked) {
    auto filterCategories = _filterAchievements.getCategories();
    QString parentName = "";
    if (Category *parent = aCategory->parent()) {
        parentName = parent->title();
    }
    auto iteratorParent = std::find_if(filterCategories.begin(),
                                 filterCategories.end(),
                                 [=](const QPair<QString, QList<Category>> &lLineCategories) {
                                    return lLineCategories.first == parentName;
                                });
    if (aIsChecked) {
        if (iteratorParent != filterCategories.end()) {
            (*iteratorParent).second.append(*aCategory);
        } else {
            filterCategories.append(QPair<QString, QList<Category>>(parentName, QList<Category>{*aCategory}));
        }
    } else {
        if (iteratorParent != filterCategories.end()) {
            auto iterator = std::find_if((*iteratorParent).second.begin(),
                                         (*iteratorParent).second.end(),
                                         [=](const Category &lLineCategories) {
                                            return lLineCategories.title() == aCategory->title();
                                        });
            if (iterator != (*iteratorParent).second.end()) {
                (*iteratorParent).second.removeAt(iterator - (*iteratorParent).second.begin());
            }
            if ((*iteratorParent).second.count() == 0) {
                filterCategories.removeAt(iteratorParent - filterCategories.begin());
            }
        }
    }
    _filterAchievements.setCategories(filterCategories);
    updateFilters();
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterWithMyProfile(const ReachedType &aType) {
    switch (aType) {
    case ReachedType::all: {
        _filterAchievements.setReached(0);
        break;
    }
    case ReachedType::reached: {
        _filterAchievements.setReached(1);
        break;
    }
    case ReachedType::notReached: {
        _filterAchievements.setReached(-1);
        break;
    }
    default: {
        break;
    }
    }
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterTextAchievement(const QString &aNewText) {
    _filterAchievements.setName(aNewText);
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    QStringList list;
    for (auto &favorite: aFavorites) {
        list.append(std::move(favorite.apiName()));
    }
    _filterAchievements.setFavorites(list);
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(const int &arg1) {
    switch (arg1) {
    case 0: {
        _filterAchievements.setFavorites(QStringList());
        ui->TableViewMyAchievements->resizeRowsToContents();
        break;
    }
    case 2: {
        updateFilterFavorite(Favorites::achievementsGame(_profile.steamID(), _game).achievements());
        break;
    }
    }
}

void FormAchievements::buttonFavorite_Clicked() {
    if (Favorites::addAchievement(_profile.steamID(), _game,  currentAchievement(), true)) {
        //Категория добавилась
        //ui->ButtonFavorite->setIcon(QIcon(Images::isFavorites()));
    } else {
        //Категория уже есть (удалилась)
        //ui->ButtonFavorite->setIcon(QIcon(Images::isNotFavorites()));
    }
}

void FormAchievements::openManual() {
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + QString::number(_game.appId()) + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}

void FormAchievements::buttonComment_Clicked() {
    auto form = createFramelessForm<FormComments>();
    form->setData(_profile, _game, currentAchievement());
    connect(this, &FormAchievements::s_settingsUpdated, form->window(), &FramelessWindow::updateSettings);
    connect(form, &FormComments::s_updateComments, this, [=]() {
        _achievementsModel->updateComments();
    });
    form->window()->show();
}
#define FunctionEnd }

#define Tabs {
void FormAchievements::hideFriendsColumns() {
    for (int i = AchievementCount + 1; i < ui->TableViewMyAchievements->model()->columnCount(); ++i) {
        ui->TableViewMyAchievements->setColumnHidden(i, true);
    }
}

void FormAchievements::tabWidget_CurrentChanged(const int &index) {
    switch(index) {
    case FormAchievementsData::TabStandart: {
        hideFriendsColumns();
        ui->TableViewMyAchievements->resizeRowsToContents();
        break;
    }
    case FormAchievementsData::TabCategories: {
        if (!_isEditCategoryLoaded) {
            loadEditCategory();
        }
        break;
    }
    case FormAchievementsData::TabCompare: {
        if (!_isCompareLoaded) {
            loadCompare();
        }
        break;
    }
    }
}

void FormAchievements::loadEditCategory() {
    ui->CategoriesEdit->setGame(_game);
    ui->CategoriesEdit->setAchievements(_achievementsModel->getAchievements());
    connect(this, &FormAchievements::s_filtersValueUpdated, ui->CategoriesEdit, [=]() {
        QList<QString> list;
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount(); ++i) {
            QModelIndex index = ui->TableViewMyAchievements->model()->index(i, AchievementAppid);

            list.append(ui->TableViewMyAchievements->model()->data(index).toString());
        }
        qDebug() << list;
        ui->CategoriesEdit->setVisibleItems(list);
    });
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [=](bool isUpdated) {
        if (isUpdated) {
            updateCategories();
        }
    });
    _isEditCategoryLoaded = true;
}

void FormAchievements::loadCompare() {
    if (ui->TableViewMyAchievements->model()) {
        ui->FriendsCompare->setInitData(_profile, _game, _achievementsModel);
        _isCompareLoaded = true;
    }
}
#define TabsEnd }
