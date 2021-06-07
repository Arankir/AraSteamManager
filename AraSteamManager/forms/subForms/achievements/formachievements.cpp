#include "formachievements.h"
#include "ui_formachievements.h"

#define Init {
FormAchievements::FormAchievements(SProfile &aProfile, SGame &aGame, QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements),
                                   _profile(aProfile), _game(aGame) {
    ui->setupUi(this);
    init();
}

FormAchievements::FormAchievements(QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements) {
    ui->setupUi(this);
    init();
}

void FormAchievements::setData(SProfile &aProfile, SGame &aGame) {
    _profile = aProfile;
    _game = aGame;
    ui->TreeWidgetCategories->setGame(_game);
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(_game.appId())));
    updateModel();
}

void FormAchievements::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initingTable(ui->TableViewMyAchievements);
    ui->TabWidget->setCurrentIndex(FormAchievementsData::TabStandart);
    ui->ProgressBarLoad->setVisible(false);
    ui->splitter->setStretchFactor(0, 0);
    ui->splitter->setStretchFactor(1, 1);
    updateIcons();
#define InitFilters {
    _achievementsModel = new AchievementsModel();
    _filterReached  .setSourceModel(&_filterName);
    _filterFavorite .setSourceModel(&_filterReached);
    ui->TableViewMyAchievements->setModel(&_filterFavorite);
    _filterName     .addRow(AchievementTitle);
    _filterName     .addRow(AchievementDescription);
    _filterReached  .setFilterKeyColumn(AchievementReachedMy);
    _filterFavorite .setFilterKeyColumn(AchievementAppid);
    _filterName     .setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterReached  .setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterFavorite .setFilterCaseSensitivity(Qt::CaseInsensitive);
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
    connect(_achievementsModel, &AchievementsModel::s_progress, this, [&](const int &stage, const int &progress) {
        Q_UNUSED(stage);
        ui->ProgressBarLoad->setValue(progress);
    });
    connect(_achievementsModel, &AchievementsModel::s_finished, this, [=]() {
        _achievementsModel->sort(AchievementWorld, Qt::SortOrder::DescendingOrder);
        ui->ProgressBarLoad->setVisible(false);
//        emit s_finish(ui->TableViewMyAchievements->viewport()->width() + 22);
    });
    connect(this, &FormAchievements::s_filtersUpdated,    ui->FriendsCompare,   &FormFriendsCompare::setModel);
    connect(this, &FormAchievements::s_filtersValueUpdated, ui->FriendsCompare,   &FormFriendsCompare::filtersValueUpdated);
    connect(ui->FriendsCompare, &FormFriendsCompare::s_startLoad,      this,   [=](int max){
                                                                                    loading(true);
                                                                                    ui->ProgressBarLoad->setMaximum(max);
                                                                                });
    connect(ui->FriendsCompare, &FormFriendsCompare::s_progressLoad,    this,   &FormAchievements::progressLoading);
    connect(ui->FriendsCompare, &FormFriendsCompare::s_finishLoad,      this,   [=](){
                                                                                    loading(false);
                                                                                });
    connect(ui->FriendsCompare, &FormFriendsCompare::s_addedFriend,     this,   &FormAchievements::hideFriendsColumns);
#define ConnectsEnd }
}

void FormAchievements::updateModel() {
    int achievementsCount = SAchievementPercentage::load(_game.sAppId()).count();
    ui->ProgressBarLoad->setValue(0);
    ui->ProgressBarLoad->setMaximum(achievementsCount);
    ui->ProgressBarLoad->setVisible(true);
    loading(true);
    _achievementsModel->setAchievements(_profile.steamID(), _game.sAppId());
    updateFilters();
    loading(false);

    if (achievementsCount > 0) {
        int reachedCount = _achievementsModel->getReachedFromProfile(0);
        ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                       QString::number(reachedCount),
                                       QString::number(achievementsCount),
                                       QString::number(100.0 * reachedCount / achievementsCount)));
        ui->FilterMyProfile->update();
    }
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

void FormAchievements::progressLoading(const int &aValue, const int &aMax) {
    ui->ProgressBarLoad->setMaximum(aMax);
    ui->ProgressBarLoad->setValue(aValue);
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
    ui->ProgressBarLoad->setVisible(aIsLoading);
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

void FormAchievements::updateSettings() {
    Settings::syncronizeSettings();
    updateIcons();
    emit s_updateSettings();
}

void FormAchievements::updateCategories() {
    ui->TreeWidgetCategories->updateUi();
    for (auto filter: qAsConst(_filtersCategories)) {
        delete filter;
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::updateFilters() {
    _filterName.setSourceModel(_achievementsModel);
    _filterReached.setSourceModel(&_filterName);
    _filterFavorite.setSourceModel(&_filterReached);
    QSortFilterProxyModel *localFilter = &_filterFavorite;
    for (auto &filter: _filtersCategories) {
        filter->setSourceModel(localFilter);
        localFilter = filter;
    }
    QSortFilterProxyInvertModel *notFirstRow = new QSortFilterProxyInvertModel();
    notFirstRow->setSourceModel(localFilter);
    notFirstRow->setFilterKeyColumn(AchievementAppid);
    notFirstRow->setFilterRegExp("^$");

    if (auto model = ui->TableViewMyAchievements->model()) {
        if (auto filter = dynamic_cast<QSortFilterProxyInvertModel*>(model)) {
            filter->setSourceModel(nullptr);
            delete filter;
        }
    }
    emit s_filtersUpdated(localFilter);

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
    QString parentName = "";
    if (Category *parent = aCategory->parent()) {
        parentName = parent->title();
    }
    auto iterator = std::find_if(_filtersCategories.begin(),
                                 _filtersCategories.end(),
                                 [=](const SortFilterProxyModelCategory *lFilter) {
        return lFilter->parentName() == parentName;
    });
    if (!aIsChecked) {
        if (iterator != _filtersCategories.end()) {
            (*iterator)->removeCategory(aCategory->title());
        }
    } else {
        if (iterator != _filtersCategories.end()) {
            (*iterator)->addCategory(aCategory->title(), aCategory->achievementsApiName());
        } else {
            SortFilterProxyModelCategory *filter = new SortFilterProxyModelCategory(parentName, this);
            filter->addCategory(aCategory->title(), aCategory->achievementsApiName());
            _filtersCategories.append(filter);
            updateFilters();
        }
    }
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterWithMyProfile(const ReachedType &aType) {
    switch (aType) {
    case ReachedType::all: {
        _filterReached.setFilterRegExp("");
        break;
    }
    case ReachedType::reached: {
        _filterReached.setFilterRegExp("(:)|(^$)");
//TODO Изменить на нормальную проверку
        break;
    }
    case ReachedType::notReached: {
        _filterReached.setFilterRegExp("(" + tr("Не получено") + ")|(^$)");
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
    if (aNewText == "") {
        _filterName.setFilterRegExp(aNewText);
    } else {
        _filterName.setFilterRegExp("(" + aNewText + ")|(^$)");
    }
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    QStringList list;
    for (auto &favorite: aFavorites) {
        list.append(std::move(favorite.apiName()));
    }

    _filterFavorite.setFilterRegExp("(" + list.join(")|(") + ")|(^$)");
    ui->TableViewMyAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(const int &arg1) {
    switch (arg1) {
    case 0: {
        _filterFavorite.setFilterRegExp("()");
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
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + _game.sAppId() + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}

void FormAchievements::buttonComment_Clicked() {
    auto form = createFramelessForm<FormComments>();
    form->setData(_profile, _game, currentAchievement());
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
    ui->CategoriesEdit->setAchievements(_achievements);
    connect(this, &FormAchievements::s_updatedHiddenRows, ui->CategoriesEdit, &FormCategoriesEdit::updateHiddenItems);
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [=](bool isUpdated) {
        if (isUpdated) {
            updateCategories();
        }
    });
    _isEditCategoryLoaded = true;
}

void FormAchievements::loadCompare() {
    if (ui->TableViewMyAchievements->model()) {
        ui->ProgressBarLoad->setMaximum(0);
        ui->ProgressBarLoad->setValue(0);
        ui->FriendsCompare->setInitData(_profile, _game, _achievementsModel);
        _isCompareLoaded = true;
    }
}
#define TabsEnd }
