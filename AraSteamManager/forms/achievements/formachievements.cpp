#include "formachievements.h"
#include "ui_formachievements.h"
#include "forms/formcomments.h"
#include "subWidgets/models/categoriesmodel.h"
#include "forms/widgets/formfrienditemcompare.h"

#include <QMenu>
#include <QDesktopServices>
#include <QInputDialog>

constexpr int c_friendColumnWidth = 100;

#define Init {
FormAchievements::FormAchievements(QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements), _categories(new Category()) {
    ui->setupUi(this);
    init();
}

void FormAchievements::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initingTable(ui->TableViewAchievements);
    ui->TreeWidgetCategories->setAcceptDrops(true);
    ui->TreeWidgetCategories->setDragEnabled(true);
    ui->TreeWidgetCategories->setDragDropMode(QAbstractItemView::InternalMove);
    auto categoriesModel = new CategoriesModel(_categories, ui->TreeWidgetCategories);
    ui->TreeWidgetCategories->setModel(categoriesModel);
    ui->TreeWidgetCategories->setHeaderHidden(true);
    ui->TabWidget->setCurrentIndex(FormAchievementsData::TabStandart);
    ui->splitter->setStretchFactor(0, 0);
    ui->splitter->setStretchFactor(1, 1);
    ui->splitter_2->setStretchFactor(0, 1);
    ui->splitter_2->setStretchFactor(1, 0);
    updateIcons();
//    _achievementsModel = new AchievementsModel();
    _filterAchievements.setSourceModel(new AchievementsModel());
    ui->TableViewAchievements->setModel(&_filterAchievements);
    ui->TreeWidgetCategories->setContextMenuPolicy(Qt::CustomContextMenu);

#define Connects {
    connect(categoriesModel, &CategoriesModel::s_error, this, [this](const QString &lError) {
        QMessageBox::warning(this, tr("Ошибка!"), lError);
    });
    connect(ui->TreeWidgetCategories, &QTreeView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QModelIndex index = ui->TreeWidgetCategories->indexAt(pos);
        if (index.isValid()) {
            Category *currentItem = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())->getItem(index);
            QMenu *menu = createMenuCategory(currentItem);
            menu->popup(mapToGlobal(pos));
        } else {
            QMenu *menu = createMenuCategory(_categories);
            menu->popup(mapToGlobal(pos));
        }

//        QModelIndexList indexes = ui->TreeWidgetCategories->selectionModel()->selectedIndexes();
//        Category *currentItem = nullptr;
//        if (indexes.size() > 0) {
//            QModelIndex selectedIndex = indexes.at(0);
//            currentItem = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())->getItem(selectedIndex);
//        }
//        QMenu *menu = createMenuCategory(currentItem);
//        menu->popup(mapToGlobal(pos));
    });
    connect(ui->ButtonUpdate,               &QPushButton::clicked,                      this,   &FormAchievements::update);
    connect(ui->CheckBoxFavorites,          &QCheckBox::stateChanged,                   this,   &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonGuides,               &QPushButton::clicked,                      this,   &FormAchievements::openManual);
    connect(ui->TabWidget,                  &QTabWidget::currentChanged,                this,   &FormAchievements::tabWidget_CurrentChanged);
    connect(ui->FilterMyProfile,            &ButtonReachedType::s_radioButtonChange,    this,   &FormAchievements::updateFilterWithMyProfile);
    connect(ui->LineEditNameAchievements,   &QLineEdit::textChanged,                    this,   &FormAchievements::updateFilterTextAchievement);
    connect(ui->ButtonFindAchievement,      &QPushButton::clicked,                      this,   [&]() {
        ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
    });
    connect(dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model()), &CategoriesModel::s_checkStateChanged, this, &FormAchievements::updateFilterCategory);
    connect(ui->TableViewAchievements,    &QTableView::customContextMenuRequested,    this,   [&](QPoint pos) {
        QMenu *menu = createMenuAchievements(currentAchievement());
        menu->popup(ui->TableViewAchievements->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewAchievements,    &QTableView::doubleClicked,                 this,   [&](QModelIndex aIndex) {
        if (aIndex.column() == achievementsModel::Comments) {
            buttonComment_Clicked();
        }
    });
    connect(_filterAchievements.sourceModel(), &AchievementsModel::s_progress, this, &Form::setStatus);
    connect(&_filterAchievements, &FilterModelAchievements::s_modelFinished, this, [&]() {
        ui->TableViewAchievements->sortByColumn(achievementsModel::World, Qt::SortOrder::DescendingOrder);
        ui->TableViewAchievements->setColumnHidden(achievementsModel::Appid, true);
        ui->TableViewAchievements->setColumnHidden(achievementsModel::Index, true);
        ui->TableViewAchievements->resizeColumnsToContents();
        ui->TableViewAchievements->setColumnWidth(achievementsModel::Title, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Title), 220));
        ui->TableViewAchievements->setColumnWidth(achievementsModel::Description, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Description), 450));
        ui->TableViewAchievements->resizeRowsToContents();
        loading(false);

        if (_filterAchievements.sourceModel()->rowCount() > 0) {
            int reachedCount = _filterAchievements.sourceModel()->getReachedFromProfile(0);
            if (reachedCount > -1) {
                ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                               QString::number(reachedCount),
                                               QString::number(_filterAchievements.sourceModel()->getAchievementsCount()),
                                               QString::number(100.0 * reachedCount / _filterAchievements.sourceModel()->getAchievementsCount())));
                ui->FilterMyProfile->setType(ui->FilterMyProfile->type());
            }
        }
        emit s_finished();
//        emit s_finish(ui->TableViewMyAchievements->viewport()->width() + 22);
    });
    connect(ui->CheckBoxCompareIcon, &QCheckBox::stateChanged, ui->TableViewAchievements,
            [&](int arg1) {ui->TableViewAchievements->setColumnHidden(achievementsModel::Icon, arg1 == 0);});
    connect(ui->CheckBoxCompareTitle, &QCheckBox::stateChanged, ui->TableViewAchievements,
            [&](int arg1) {ui->TableViewAchievements->setColumnHidden(achievementsModel::Title, arg1 == 0);});
    connect(ui->CheckBoxCompareDescription, &QCheckBox::stateChanged, ui->TableViewAchievements,
            [&](int arg1) {ui->TableViewAchievements->setColumnHidden(achievementsModel::Description, arg1 == 0);});
    connect(ui->CheckBoxCompareComment, &QCheckBox::stateChanged, ui->TableViewAchievements,
            [&](int arg1) {ui->TableViewAchievements->setColumnHidden(achievementsModel::Comments, arg1 == 0);});
    connect(ui->CheckBoxCompareTotalPercent, &QCheckBox::stateChanged, ui->TableViewAchievements,
            [&](int arg1) {ui->TableViewAchievements->setColumnHidden(achievementsModel::World, arg1 == 0);});
    connect(ui->ButtonFriendsAll, &QPushButton::clicked, this, [this](){setAllFriendsValue(ReachedType::all);});
    connect(ui->ButtonFriendsReached, &QPushButton::clicked, this, [this](){setAllFriendsValue(ReachedType::reached);});
    connect(ui->ButtonFriendsNotReached, &QPushButton::clicked, this, [this](){setAllFriendsValue(ReachedType::notReached);});
    connect(ui->ComboBoxFriend, &ComboBoxFriendsWithGame::s_friendClicked, this, &FormAchievements::addFriendToList);
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [=]() {
        if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
            model->updateData(_categories);
        }
    });
    connect(this, &Form::s_settingsUpdated, ui->CategoriesEdit, &Form::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->FilterMyProfile, &ButtonReachedType::updateSettings);
#define ConnectsEnd }
}

void FormAchievements::setData(const SProfile &aProfile, const SGame &aGame) {
    _profile = aProfile;
    _game = aGame;
    _categories->setGame(_game);
    _categories->update();
    dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())->updateData(_categories);
    ui->labelProfileAvatar->setPixmap(_profile.pixmapAvatar());
    ui->labelProfileAvatar->setToolTip(_profile.personaName());
//    ui->TreeWidgetCategories->setGame(_game);
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(_game.appId())));
    loadingCompare();
    updateModel();
}

int FormAchievements::getAchievementsCount() {
    if (auto model = _filterAchievements.sourceModel()) {
        return model->rowCount() - 1;
    }
    return 0;
}

void FormAchievements::updateModel() {
    loading(true);
    _filterAchievements.sourceModel()->setAchievements(_profile.steamID(), _game.appId());
}
#define InitEnd }

#define System {
FormAchievements::~FormAchievements() {
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent *event) {
    event->accept();
}

SAchievement FormAchievements::currentAchievement() {
    QModelIndex index = ui->TableViewAchievements->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(achievementsModel::Index);
    QVariant fIndex = ui->TableViewAchievements->model()->data(index2);
    return _filterAchievements.sourceModel()->getAchievement(fIndex.toInt());
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
    ui->ButtonFriendsReached    ->setIcon(QIcon(Images::reached()));
    ui->ButtonFriendsAll        ->setIcon(QIcon(Images::allAchievements()));
    ui->ButtonFriendsNotReached ->setIcon(QIcon(Images::notReached()));
}

QMenu *FormAchievements::createMenuAchievements(const SAchievement &aAchievement) {
    QString appId = aAchievement.apiName();

    //Добавление кнопки избранного
    QAction *actionFavorites;
    bool isFavorite = false;
    FavoriteAchievementsGames favorites;
    auto iteratorGame = std::find_if(favorites.begin(),
                                     favorites.end(),
                                     [=, this](const FavoriteAchievementsGame &lGame) {
                                        return lGame == _game && lGame.steamId() == _profile.steamID();
                                     });
    if (iteratorGame != favorites.end()) {
        isFavorite = std::any_of(iteratorGame->cbegin(),
                                 iteratorGame->cend(),
                                 [appId](const FavoriteAchievement &curFavorite) {
                                     return curFavorite.apiName() == appId;
                                 });
    }

    if(isFavorite) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
        connect (actionFavorites,   &QAction::triggered,    this,   [=, this]() {
            FavoriteAchievementsGames favorites;
            favorites.remove(_profile.steamID(), _game, aAchievement);
        });
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
        connect (actionFavorites,   &QAction::triggered,    this,   [=, this]() {
            FavoriteAchievementsGames favorites;
            favorites.append(_profile.steamID(), _game, aAchievement);
        });
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

//    connect (actionFavorites,   &QAction::triggered,    this,   &FormAchievements::buttonFavorite_Clicked);
    connect (actionComment,     &QAction::triggered,    this,   &FormAchievements::buttonComment_Clicked);
    connect (actionGuides,      &QAction::triggered,    this,   &FormAchievements::openManual);
    connect (actionUpdate,      &QAction::triggered,    this,   &FormAchievements::update);

    return menu;
}

QMenu *FormAchievements::createMenuCategory(Category *aCategory) {
    //Кнопка изменения достижений
    QAction *actionAchievements = new QAction(QIcon(Images::change()), tr("Изменить категорию"), this);

    //Кнопка добавления подкатегории
    QAction *actionAddCategory = new QAction(QIcon(Images::create()), tr("Добавить категорию"), this);

    //Кнопка добавления подкатегории
    QAction *actionSubCategory = new QAction(QIcon(Images::create()), tr("Добавить подкатегорию"), this);

    //Кнопка удаления категории
    QAction *actionDelete = new QAction(QIcon(Images::deleteIcon()), tr("Удалить категорию"), this);

    //Кнопка удаления всех категорий
    QAction *actionDeleteAll = new QAction(QIcon(Images::deleteAll()), tr("Удалить все категории"), this);

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionAddCategory);
    menu->addAction (actionSubCategory);
    menu->addAction (actionDelete);
    menu->addAction (actionDeleteAll);

    connect (actionAchievements,    &QAction::triggered,    this,   [=, this]() {
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->changeCategory(aCategory);
    });
    connect (actionAddCategory,     &QAction::triggered,    this,   [=, this]() {
        if (_categories == aCategory) {
            return;
        }
        QString title = QInputDialog::getText(this, tr("Создание новой категории"), tr("Введите название:"), QLineEdit::Normal, "");
        Category *category = new Category();
        category->setTitle(title);
        if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
            model->insertCategory(category, aCategory->parent()->getPathFromRoot());
        }
//        category->setParent(aCategory->parent());
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->changeCategory(category);
    });
    connect (actionSubCategory,     &QAction::triggered,    this,   [=, this]() {
        QString title = QInputDialog::getText(this, tr("Создание новой категории"), tr("Введите название:"), QLineEdit::Normal, "");
        Category *category = new Category();
        category->setTitle(title);
        if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
            model->insertCategory(category, aCategory->getPathFromRoot());
        }
        ui->TabWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        ui->CategoriesEdit->changeCategory(category);
    });
    connect (actionDelete,          &QAction::triggered,    this,   [=, this]() {
        QMessageBox::StandardButton clickedButton = QMessageBox::question(this,
                                                                          tr("Внимание"),
                                                                          tr("Вы уверены, что хотите удалить категорию?"),
                                                                          QMessageBox::Yes |
                                                                          QMessageBox::No);
        if (clickedButton == QMessageBox::No) {
            return;
        }
        if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
            bool isCategoryRemoved = model->removeCategory(aCategory);
            qDebug() << isCategoryRemoved;
            if (!isCategoryRemoved) {
                QMessageBox::warning(this, tr("Ошибка!"), tr("Не удалось удалить категорию."));
            }
        }
//        QStringList list = aCategory->getPathFromRoot();
//        if (aCategory->root()->removeCategory(list)) {
//            aCategory->root()->save();
//            if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
//                model->updateData(_categories);
//            }
//        } else {
//            QMessageBox::warning(this, tr("Ошибка!"), tr("Не удалось удалить категорию."));
//        }
    });
    connect (actionDeleteAll,       &QAction::triggered,    this,   [=, this]() {
        QMessageBox deleteQuestion(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Вы уверены, что хотите удалить все категории?"));
        QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"), QMessageBox::YesRole);
        deleteQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
        deleteQuestion.exec();
        if(deleteQuestion.clickedButton() != btnYes) {
            return;
        }

        deleteQuestion.setText(tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        deleteQuestion.exec();
        if (deleteQuestion.clickedButton() != btnYes) {
            return;
        }

        _categories->clearCategories();
        _categories->save();
        if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
            model->removeAllCategories();
//            model->saveCategories();
        }
    });

    return menu;
}

void FormAchievements::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
    emit s_settingsUpdated(aSettings);
}

void FormAchievements::updateCategories() {
    _categories->update();
    if (auto model = dynamic_cast<CategoriesModel*>(ui->TreeWidgetCategories->model())) {
        model->updateData(_categories);
    }
    if (auto model = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->model())) {
        model->setCategories(CategoriesFilter());
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::updateFilters() {
//    _filterAchievements.setSourceModel(_achievementsModel);
//    ui->TableViewAchievements->setModel(&_filterAchievements);
    ui->TableViewAchievements->sortByColumn(achievementsModel::World, Qt::SortOrder::DescendingOrder);
    ui->TableViewAchievements->setColumnHidden(achievementsModel::Appid, true);
    ui->TableViewAchievements->setColumnHidden(achievementsModel::Index, true);
    ui->TableViewAchievements->resizeColumnsToContents();
    ui->TableViewAchievements->setColumnWidth(achievementsModel::Title, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Title), 220));
    ui->TableViewAchievements->setColumnWidth(achievementsModel::Description, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Description), 450));
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterCategory(Category *aCategory, const bool &aIsChecked) {
    auto filterCategories = _filterAchievements.getCategories();
    if (aIsChecked) {
        filterCategories.addCategory(aCategory);
    } else {
        filterCategories.removeCategory(aCategory);
    }
    _filterAchievements.setCategories(CategoriesFilter(filterCategories));
    updateFilters();
    ui->TableViewAchievements->resizeRowsToContents();
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
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterTextAchievement(const QString &aNewText) {
    _filterAchievements.setName(aNewText);
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    QStringList list;
    for (auto &favorite: aFavorites) {
        list.append(favorite.apiName());
    }
    _filterAchievements.setFavorites(list);
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(const int &arg1) {
    switch (arg1) {
    case 0: {
        _filterAchievements.setFavorites(QStringList());
        ui->TableViewAchievements->resizeRowsToContents();
        break;
    }
    case 2: {
        FavoriteAchievementsGames favorites;
        auto iteratorGame = std::find_if(favorites.begin(),
                                         favorites.end(),
                                         [=, this](const FavoriteAchievementsGame &lGame) {
                                            return lGame == _game && lGame.steamId() == _profile.steamID();
                                         });
        if (iteratorGame != favorites.end()) {
            updateFilterFavorite(*iteratorGame);
        }
        break;
    }
    }
}

void FormAchievements::openManual() {
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + QString::number(_game.appId()) + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}

void FormAchievements::buttonComment_Clicked() {
    auto form = createFramelessForm<FormComments>();
    form->setData(_profile.steamID(), _game, currentAchievement());
    connect(this, &FormAchievements::s_settingsUpdated, form->window(), &FramelessWindow::updateSettings);
    connect(form, &FormComments::s_updateComments, this, [&]() {
        _filterAchievements.sourceModel()->updateComments();
    });
    form->window()->show();
}
#define FunctionEnd }

#define Tabs {
void FormAchievements::tabWidget_CurrentChanged(const int &index) {
    switch(index) {
    case FormAchievementsData::TabStandart: {
        ui->TableViewAchievements->resizeRowsToContents();
        break;
    }
    case FormAchievementsData::TabCategories: {
        if (!_isEditCategoryLoaded) {
            loadEditCategory();
        }
        break;
    }
    default: {
        break;
    }
    }
}

void FormAchievements::loadEditCategory() {
    ui->CategoriesEdit->setGame(_game);
    ui->CategoriesEdit->setAchievements(_filterAchievements.sourceModel()->getAchievements());
    connect(this, &FormAchievements::s_filtersValueUpdated, ui->CategoriesEdit, [&]() {
        QList<QString> list;
        for (int i = 0; i < ui->TableViewAchievements->model()->rowCount(); ++i) {
            QModelIndex index = ui->TableViewAchievements->model()->index(i, achievementsModel::Appid);

            list.append(ui->TableViewAchievements->model()->data(index).toString());
        }
        ui->CategoriesEdit->setVisibleItems(list);
    });
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [&](bool isUpdated) {
        if (isUpdated) {
            updateCategories();
        }
    });
    _isEditCategoryLoaded = true;
}
#define TabsEnd }

void FormAchievements::setAllFriendsValue(const ReachedType &aType) {
    for(int i = 0; i < ui->ListWidgetFriends->count(); ++i) {
        auto item = ui->ListWidgetFriends->item(i);
        if (auto itemWidget = dynamic_cast<FormFriendItemCompare*>(ui->ListWidgetFriends->itemWidget(item))) {
            if (!itemWidget->isFilterHidden()) {
                itemWidget->setFilterValue(aType);
            }
        }
    }
}

void FormAchievements::updateFilterFriend(SProfile *aSteamId, const ReachedType &aType) {
    switch (aType) {
    case ReachedType::all: {
        _filterAchievements.setReachedFriend(0, aSteamId->steamID());
        break;
    }
    case ReachedType::reached: {
        _filterAchievements.setReachedFriend(1, aSteamId->steamID());
        break;
    }
    case ReachedType::notReached: {
        _filterAchievements.setReachedFriend(-1, aSteamId->steamID());
        break;
    }
    default: {
        break;
    }
    }
}

void FormAchievements::loadingCompare() {
    ++_loadCompare;
    auto friends = SFriend::load(_profile.steamID());
    QStringList list;
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(sFriend.steamId());
    }
    _profilesFriends = SProfile::load(list);

    for(const auto &profileFriend: qAsConst(_profilesFriends)) {
        QString steamId = profileFriend.steamID();
        SGame::load(steamId, true, true, std::bind(&FormAchievements::loadFriendGames, this,  std::placeholders::_1, steamId));
    }
}

void FormAchievements::loadFriendGames(const SGames &aGames, const QString &aUserId) {
    static int haveGame = 0;
    static int haventGame = 0;
    auto iterator = std::find_if(_profilesFriends.begin(),
                                 _profilesFriends.end(),
                                 [=](const SProfile &profile) {
                                     return aUserId == profile.steamID();
                                 });
    if (iterator != _profilesFriends.end()) {
        bool isGameExist = std::any_of(aGames.begin(),
                                       aGames.end(),
                                       [&](const SGame &game) {
                                           return game.appId() == _game.appId();
                                       });
        if (isGameExist) {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haveGame);
            ++haveGame;
        } else {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haventGame);
            ++haventGame;
        }
        emit s_progress(tr("Загрузка друзей"), haveGame + haventGame, _profilesFriends.count());
    }
    if(haveGame + haventGame == _profilesFriends.count()) {
        ++_loadCompare;
        haveGame = 0;
        haventGame = 0;
        emit s_finishedFriends();
    }
}

void FormAchievements::addFriendToList(const SProfile &aSteamFriend) {
    QListWidgetItem *item = new QListWidgetItem(aSteamFriend.pixmapAvatar(), "");

    auto friendItem = new FormFriendItemCompare(aSteamFriend, item);
    connect(friendItem, &FormFriendItemCompare::s_filterChanged, this, &FormAchievements::updateFilterFriend);
    connect(friendItem, &FormFriendItemCompare::s_delete, this, [&]() {
        auto sndr = dynamic_cast<FormFriendItemCompare*>(sender());
        if (sndr == nullptr) {
            return;
        }
        ui->ComboBoxFriend->addItem(*sndr->steamProfile(), sndr->isFilterHidden() ? FriendType::haventGame : FriendType::haveGame);
        removeFriendColumn(*sndr->steamProfile());
        delete sndr->item();
    });
    ui->ListWidgetFriends->addItem(item);
    ui->ListWidgetFriends->setItemWidget(item, friendItem);

    int friendIndex = addFriendColumn(aSteamFriend);

    int reached = _filterAchievements.sourceModel()->getReachedFromProfile(friendIndex);
    if(reached > -1) {
        friendItem->setPercent(100.0f * reached / _filterAchievements.sourceModel()->getAchievementsCount());
    } else {
        friendItem->setPercent(0.0f);
        friendItem->setHiddenFilter(true);
    }
}

int FormAchievements::addFriendColumn(const SProfile &aSteamFriend) {
    int index = _filterAchievements.addProfile(aSteamFriend);
    ui->TableViewAchievements->setColumnWidth(index + achievementsModel::Count - 1, c_friendColumnWidth);
    return index;
}

bool FormAchievements::removeFriendColumn(const SProfile &aSteamFriend) {
    _filterAchievements.removeProfile(aSteamFriend);
    return true;
}
