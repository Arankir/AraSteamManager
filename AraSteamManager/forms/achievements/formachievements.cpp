#include "formachievements.h"
#include "ui_formachievements.h"
#include "forms/formcomments.h"
#include "classes/common/images.h"

#include <QMenu>
#include <QDesktopServices>
#include <QInputDialog>
#include <QMessageBox>
#include <QCloseEvent>

constexpr int c_friendColumnWidth = 100;

#define Init {
FormAchievements::FormAchievements(QWidget *aParent): Form(aParent), ui(new Ui::FormAchievements) {
    ui->setupUi(this);
    init();
}

void FormAchievements::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initTreeCategories();
    initAchievementsTable();
    initEditCategory();
    initFriends();

    ui->stackedWidget->setCurrentIndex(FormAchievementsData::TabStandart);
    ui->splitterFilterAchievements->setStretchFactor(0, 1);
    ui->splitterFilterAchievements->setStretchFactor(1, 10);
    ui->splitterAchievementsFriends->setStretchFactor(0, 4);
    ui->splitterAchievementsFriends->setStretchFactor(1, 1);
    updateIcons();
    connect(ui->ButtonUpdate,               &QPushButton::clicked,      this,   &FormAchievements::update);
    connect(ui->CheckBoxFavorites,          &QCheckBox::stateChanged,   this,   &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonGuides,               &QPushButton::clicked,      this,   &FormAchievements::openManual);
    connect(ui->LineEditNameAchievements,   &QLineEdit::textChanged,    this,   &FormAchievements::updateFilterTextAchievement);
    connect(ui->ButtonFindAchievement,      &QPushButton::clicked,      this,   [&]() {
        ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
    });
}

void FormAchievements::initTreeCategories() {
    ui->TreeWidgetCategories->setAcceptDrops(true);
    ui->TreeWidgetCategories->setDragEnabled(true);
    ui->TreeWidgetCategories->setDragDropMode(QAbstractItemView::InternalMove);
    categoriesModel_ = new CategoriesModel(new Category(), ui->TreeWidgetCategories);
    ui->TreeWidgetCategories->setModel(categoriesModel_);
    ui->TreeWidgetCategories->setHeaderHidden(true);
    ui->TreeWidgetCategories->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->TreeWidgetCategories, &QTreeView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QModelIndex index = ui->TreeWidgetCategories->indexAt(pos);
        QMenu *menu = createMenuCategory(index);
        menu->popup(ui->TreeWidgetCategories->viewport()->mapToGlobal(pos));
    });
    connect(categoriesModel_, &CategoriesModel::s_error, this, [this](const QString &lError) {
        QMessageBox::warning(this, tr("Ошибка!"), lError);
    });
    connect(categoriesModel_, &CategoriesModel::s_checkStateChanged, this, &FormAchievements::updateFilterCategory);
}

void FormAchievements::initAchievementsTable() {
    ui->TableViewAchievements->verticalHeader()->setVisible(false);
    auto model = new AchievementsModel(ui->TableViewAchievements);
    auto filter = new FilterModelAchievements(ui->TableViewAchievements);
    ui->TableViewAchievements->setModel(model);
    ui->TableViewAchievements->setFilter(filter);
    ui->TableViewAchievements->setColumnHidden(achievementsModel::Appid, true);
    ui->TableViewAchievements->setColumnHidden(achievementsModel::Index, true);
    ui->TableViewAchievements->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewAchievements->getFrozenTableView()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->TableViewAchievements->horizontalHeader(), &QTreeView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QMenu *menu = createMenuAchievementsHeader();
        menu->popup(ui->TableViewAchievements->horizontalHeader()->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewAchievements,    &QTableView::customContextMenuRequested,    this,   [&](QPoint pos) {
        QMenu *menu = createMenuAchievements(currentAchievement());
        menu->popup(ui->TableViewAchievements->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewAchievements->getFrozenTableView(),    &QTableView::customContextMenuRequested,    this,   [&](QPoint pos) {
        QMenu *menu = createMenuFrozenTable(ui->TableViewAchievements->getFrozenTableView()->currentIndex());
        if (menu) {
            menu->popup(ui->TableViewAchievements->getFrozenTableView()->viewport()->mapToGlobal(pos));
        }
    });
    connect(ui->TableViewAchievements,    &QTableView::doubleClicked,                 this,   [&](QModelIndex aIndex) {
        if (aIndex.column() == achievementsModel::Comments) {
            buttonComment_Clicked();
        }
    });
    connect(model, &AchievementsModel::s_progress, this, &Form::setStatus);
    connect(filter, &FilterModelAchievements::s_modelFinished, this, &FormAchievements::onAchievementsLoaded);
}

void FormAchievements::initEditCategory() {
    connect(this, &Form::s_settingsUpdated, ui->CategoriesEdit, &Form::updateSettings);
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
        ui->stackedWidget->setCurrentIndex(FormAchievementsData::TabStandart);
    });
}

void FormAchievements::initFriends() {
    ui->ListViewFriends->setModel(new QStandardItemModel());
    connect(ui->ButtonAddProfile, &QPushButton::clicked, this, &FormAchievements::buttonAddProfile_Clicked);
    connect(ui->ListViewFriends, &QListWidget::doubleClicked, this, &FormAchievements::addProfileToTable);
    connect(ui->lineEditFindFriend, &QLineEdit::textChanged, this, &FormAchievements::findFriend);
    connect(ui->ButtonFindFriend, &QPushButton::clicked, this, &FormAchievements::findFriend);
    connect(ui->checkBoxOnlyWithGame, &QCheckBox::toggled, this, &FormAchievements::checkBoxFriendsOnlyWithGame_Clicked);
}

void FormAchievements::setData(const SProfile &aProfile, const SGame &aGame) {
    profile_ = aProfile;
    game_ = aGame;

    loadedCategories_ = false;
    loadedAchievements_ = false;
    loadedFriends_ = false;
    loading(true);

    categoriesModel_->setGame(game_);
    loadedCategories_ = true;

    ui->labelProfileAvatar->setPixmap(profile_.pixmapAvatar());
    ui->labelProfileAvatar->setToolTip(profile_.personaName());
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(game_.appId())));

    updateAchievements();
    loadFriends();
}

QString FormAchievements::getProfileId() const {
    return profile_.steamId();
}

int FormAchievements::getGameAppId() const {
    return game_.appId();
}

void FormAchievements::onAchievementsLoaded() {
    loadedAchievements_ = true;
    ui->TableViewAchievements->sortByColumn(achievementsModel::World, Qt::SortOrder::DescendingOrder);
    ui->TableViewAchievements->resizeColumnsToContents();
    ui->TableViewAchievements->setColumnWidth(achievementsModel::Title, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Title), 220));
    ui->TableViewAchievements->setColumnWidth(achievementsModel::Description, std::min(ui->TableViewAchievements->columnWidth(achievementsModel::Description), 450));
    ui->TableViewAchievements->resizeRowsToContents();

    AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel());
    if (model) {
        int achievementCount = model->getAchievementsCount();
        ui->CategoriesEdit->setAchievements(model->getAchievements(), game_.appId());

        if (model->rowCount() > 0) {
            int reachedCount = model->getReachedFromProfile(0);
            if (reachedCount > -1) {
                ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                               QString::number(reachedCount),
                                               QString::number(achievementCount),
                                               QString::number(100.0 * reachedCount / achievementCount)));
            }
        }
    }

    if (loadedFriends_ && loadedAchievements_) {
        loading(false);
    }
    emit s_finishedAchievements();
}

void FormAchievements::loadFriends() {
    AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel());
    if (!model || model->getAchievementsCount() == 0) {
        return;
    }
    QStringList list;
    SFriends friends = SFriend::load(profile_.steamId());
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(sFriend.steamId());
    }

    friendsProfiles_ = SProfile::load(list);
    for(const SProfile &profileFriend: friendsProfiles_) {
        ProfileID steamId = profileFriend.steamId();
        SGame::load(steamId, true, true, std::bind(&FormAchievements::onLoadedFriendGames, this,  std::placeholders::_1, steamId));
    }
}

void FormAchievements::onLoadedFriendGames(const SGames &aGames, const ProfileID &aProfileId) {
    auto iterator = std::find_if(friendsProfiles_.begin(),
                                 friendsProfiles_.end(),
                                 [=](const SProfile &profile) {
                                     return aProfileId == profile.steamId();
                                 });
    if (iterator != friendsProfiles_.end()) {
        bool isGameExist = std::any_of(aGames.begin(),
                                       aGames.end(),
                                       [&](const SGame &game) {
                                           return game.appId() == game_.appId();
                                       });
        addFriendToList(*iterator, isGameExist ? FriendListItemData::ProfileType::FriendWithGame : FriendListItemData::ProfileType::FriendWithoutGame);

        emit s_progress(tr("Загрузка друзей"), ui->ListViewFriends->model()->rowCount(), friendsProfiles_.count());
    }
    if(ui->ListViewFriends->model()->rowCount() == friendsProfiles_.count()) {
        loadedFriends_ = true;
        if (loadedFriends_ && loadedAchievements_) {
            loading(false);
        }
        emit s_finishedFriends();
    }
}

int FormAchievements::getAchievementsCount() {
    if (AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel())) {
        return model->getAchievements().count();
    }
    return 0;
}

void FormAchievements::updateAchievements() {
    loading(true);
    if (AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel())) {
        model->setAchievements(profile_.steamId(), game_.appId());
    }
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
    if (AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel())) {
        return model->getAchievement(fIndex.toInt());
    }
    return SAchievement();
}

void FormAchievements::loading(bool aIsLoading) {
    ui->FrameFilter->setEnabled(!aIsLoading);
    ui->TreeWidgetCategories->setEnabled(!aIsLoading);
    ui->ButtonUpdate->setEnabled(!aIsLoading);
    ui->stackedWidget->setEnabled(!aIsLoading);
}

void FormAchievements::update() {
    updateAchievements();
    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(game_.appId())));
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
    updateAchievements();
}

void FormAchievements::updateIcons() {
    ui->ButtonFindAchievement   ->setIcon(QIcon(Images::find()));
    ui->ButtonUpdate            ->setIcon(QIcon(Images::update()));
    ui->ButtonGuides            ->setIcon(QIcon(Images::guide()));
    ui->ButtonFindFriend        ->setIcon(QIcon(Images::findProfile()));
}

QMenu *FormAchievements::createMenuAchievements(const SAchievement &aAchievement) {
    QMenu *menu = new QMenu(this);
    QString achievementId = aAchievement.apiName();

    QAction *actionFavorites;
    FavoriteAchievements favorites;
    if(favorites.isInFavorite(game_.appId(), profile_.steamId(), achievementId)) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), menu);
        connect (actionFavorites,   &QAction::triggered,    this,   [=, this]() {
            FavoriteAchievements favorites;
            favorites.remove(profile_.steamId(), game_.appId(), aAchievement.apiName());
            favorites.save();
//            emit s_settingsUpdated(changedSettings::favorites);
        });
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), menu);
        connect (actionFavorites,   &QAction::triggered,    this,   [=, this]() {
            FavoriteAchievements favorites;
            favorites.append(profile_.steamId(), game_, aAchievement);
            favorites.save();
//            emit s_settingsUpdated(changedSettings::favorites);
        });
    }

    QAction *actionComment = new QAction(QIcon(Images::isComment()), tr("Редактировать комментарий...     "), menu);
    QAction *actionGuides = new QAction(QIcon(Images::guide()), tr("Перейти в руководства"), menu);
    QAction *actionUpdate = new QAction(QIcon(Images::update()), tr("Обновить"), menu);

    menu->addAction (actionFavorites);
    menu->addAction (actionComment);
    menu->addAction (actionGuides);
    menu->addAction (actionUpdate);

    connect (actionComment,     &QAction::triggered,    this,   &FormAchievements::buttonComment_Clicked);
    connect (actionGuides,      &QAction::triggered,    this,   &FormAchievements::openManual);
    connect (actionUpdate,      &QAction::triggered,    this,   &FormAchievements::update);

    return menu;
}

QMenu *FormAchievements::createMenuFrozenTable(const QModelIndex &aIndex) {
    QMenu *menu = new QMenu(this);
    int friendNumber = aIndex.column() - achievementsModel::Count;
    if (friendNumber == -1) {
        QAction *actionAll = new QAction(QIcon(Images::allAchievements()), tr("Показать все достижения"), menu);
        QAction *actionNotReached = new QAction(QIcon(Images::notReached()), tr("Показать достижения неполученные у всех"), menu);
        QAction *actionReached = new QAction(QIcon(Images::reached()), tr("Показать достижения полученные у всех"), menu);

        menu->addAction (actionAll);
        menu->addAction (actionNotReached);
        menu->addAction (actionReached);

        connect (actionAll,     &QAction::triggered,    this,   [this]() {
            setAllFriendsValue(ReachedType::all);
        });
        connect (actionNotReached,      &QAction::triggered,    this,   [this]() {
            setAllFriendsValue(ReachedType::notReached);
        });
        connect (actionReached,      &QAction::triggered,    this,   [this]() {
            setAllFriendsValue(ReachedType::reached);
        });
    } else if (friendNumber == 0) {
        QAction *actionAll = new QAction(QIcon(Images::allAchievements()), tr("Показать все достижения"), menu);
        QAction *actionNotReached = new QAction(QIcon(Images::notReached()), tr("Показать неполученные достижения"), menu);
        QAction *actionReached = new QAction(QIcon(Images::reached()), tr("Показать полученные достижения"), menu);

        menu->addAction (actionAll);
        menu->addAction (actionNotReached);
        menu->addAction (actionReached);

        connect (actionAll,     &QAction::triggered,    this,   [this]() {
            updateFilterFriend(profile_.steamId(), ReachedType::all);
        });
        connect (actionNotReached,      &QAction::triggered,    this,   [this]() {
            updateFilterFriend(profile_.steamId(), ReachedType::notReached);
        });
        connect (actionReached,      &QAction::triggered,    this,   [this]() {
            updateFilterFriend(profile_.steamId(), ReachedType::reached);
        });
    } else if (friendNumber > 0) {
        QAction *actionAll = new QAction(QIcon(Images::allAchievements()), tr("Показать все достижения"), menu);
        QAction *actionNotReached = new QAction(QIcon(Images::notReached()), tr("Показать неполученные достижения"), menu);
        QAction *actionReached = new QAction(QIcon(Images::reached()), tr("Показать полученные достижения"), menu);

        menu->addAction (actionAll);
        menu->addAction (actionNotReached);
        menu->addAction (actionReached);

        qDebug() << profilesInTable_.at(friendNumber - 1).first.steamId();

        connect (actionAll,     &QAction::triggered,    this,   [this, friendNumber]() {
            updateFilterFriend(profilesInTable_.at(friendNumber - 1).first.steamId(), ReachedType::all);
        });
        connect (actionNotReached,      &QAction::triggered,    this,   [this, friendNumber]() {
            updateFilterFriend(profilesInTable_.at(friendNumber - 1).first.steamId(), ReachedType::notReached);
        });
        connect (actionReached,      &QAction::triggered,    this,   [this, friendNumber]() {
            updateFilterFriend(profilesInTable_.at(friendNumber - 1).first.steamId(), ReachedType::reached);
        });
    } else {
        return nullptr;
    }
    return menu;
}

QMenu *FormAchievements::createMenuCategory(const QModelIndex &aCategoryIndex) {
    QMenu *menu = new QMenu(this);
    QAction *actionAchievements =   new QAction(QIcon(Images::change()),        tr("Изменить категорию"),       menu);
    QAction *actionAddCategory =    new QAction(QIcon(Images::create()),        tr("Добавить категорию"),       menu);
    QAction *actionSubCategory =    new QAction(QIcon(Images::create()),        tr("Добавить подкатегорию"),    menu);
    QAction *actionDelete =         new QAction(QIcon(Images::deleteIcon()),    tr("Удалить категорию"),        menu);
    QAction *actionDeleteAll =      new QAction(QIcon(Images::deleteAll()),     tr("Удалить все категории"),    menu);
    QAction *actionExpandAll =      new QAction(QIcon(Images::expand()),        tr("Раскрыть все категории"),   menu);
    QAction *actionCollapseAll =    new QAction(QIcon(Images::collapse()),      tr("Свернуть все категории"),   menu);

    menu->addAction (actionAchievements);
    menu->addAction (actionAddCategory);
    menu->addAction (actionSubCategory);
    menu->addAction (actionDelete);
    menu->addAction (actionDeleteAll);
    menu->addSeparator();
    menu->addAction (actionExpandAll);
    menu->addAction (actionCollapseAll);

    connect (actionAchievements,    &QAction::triggered,    this,   [=, this]() {
        if (categoriesModel_) {
            ui->CategoriesEdit->changeCategory(categoriesModel_->getItem(aCategoryIndex));
            ui->stackedWidget->setCurrentIndex(FormAchievementsData::TabCategories);
        }
    });
    connect (actionAddCategory,     &QAction::triggered,    this,   [=, this]() {
        createCategory(aCategoryIndex);
    });
    connect (actionSubCategory,     &QAction::triggered,    this,   [=, this]() {
        createSubCategory(aCategoryIndex);
    });
    connect (actionDelete,          &QAction::triggered,    this,   [=, this]() {
        QMessageBox deleteQuestion(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Вы уверены, что хотите удалить категорию?"));
        QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"), QMessageBox::YesRole);
        deleteQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
        deleteQuestion.exec();
        if(deleteQuestion.clickedButton() != btnYes) {
            return;
        }
        if (categoriesModel_) {
            bool isCategoryRemoved = categoriesModel_->removeRows(aCategoryIndex.row(), 0, categoriesModel_->parent(aCategoryIndex));
            if (!isCategoryRemoved) {
                QMessageBox::warning(this, tr("Ошибка!"), tr("Не удалось удалить категорию."));
            }
        }
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

        if (categoriesModel_) {
            categoriesModel_->removeAllCategories();
            categoriesModel_->saveCategories();
        }
    });
    connect (actionExpandAll,    &QAction::triggered,    this,   [=, this]() {
        ui->TreeWidgetCategories->expandAll();
    });
    connect (actionCollapseAll,    &QAction::triggered,    this,   [=, this]() {
        ui->TreeWidgetCategories->collapseAll();
    });

    return menu;
}

QWidgetAction *FormAchievements::createCheckBoxHeaderAction(QMenu *aMenu, const QString &aText, const achievementsModel::Columns &aColumn) {
    QCheckBox *checkIcon = new QCheckBox(aText, aMenu);
    QWidgetAction *actionIcon = new QWidgetAction(aMenu);
    actionIcon->setDefaultWidget(checkIcon);
    checkIcon->setChecked(!ui->TableViewAchievements->isColumnHidden(aColumn));
    connect(checkIcon, &QCheckBox::clicked, this, [=, this](bool) {
        ui->TableViewAchievements->setColumnHidden(aColumn, !checkIcon->isChecked());
    });
    return actionIcon;
}

QMenu *FormAchievements::createMenuAchievementsHeader() {
    QMenu *menu = new QMenu(this);

    QWidgetAction *actionTitle =        createCheckBoxHeaderAction(menu, tr("Название"),    achievementsModel::Title);
    QWidgetAction *actionDescription =  createCheckBoxHeaderAction(menu, tr("Описание"),    achievementsModel::Description);
    QWidgetAction *actionComment =      createCheckBoxHeaderAction(menu, tr("Комментарий"), achievementsModel::Comments);
    QWidgetAction *actionWorld =        createCheckBoxHeaderAction(menu, tr("По миру"),     achievementsModel::World);

    menu->addAction (actionTitle);
    menu->addAction (actionDescription);
    menu->addAction (actionComment);
    menu->addAction (actionWorld);

    if (profilesInTable_.count() > 0) {
        QMenu *friendsRemoveMenu = new QMenu(tr("Убрать столбец"), this);
        for (auto profile: profilesInTable_) {
            QAction *profileAction = new QAction(QIcon(Images::deleteIcon()), tr("Убрать %1 из сравнения").arg(profile.first.personaName()), friendsRemoveMenu);
            connect (profileAction,    &QAction::triggered,    this,   [=, this]() {
                addFriendToList(profile.first, profile.second);
                removeFriendColumn(profile.first);
            });
            friendsRemoveMenu->addAction(profileAction);
        }
        menu->addMenu(friendsRemoveMenu);
    }

    return menu;
}

void FormAchievements::createCategory(const QModelIndex &aCategory) {
    if (categoriesModel_) {
        createSubCategory(categoriesModel_->parent(aCategory));
    }
}

void FormAchievements::createSubCategory(const QModelIndex &aCategory) {
    QString title = QInputDialog::getText(this, tr("Создание новой категории"), tr("Введите название:"), QLineEdit::Normal, "");
    if (title.isEmpty()) {
        return;
    }
    if (categoriesModel_) {
        int row = 0;
        if (aCategory.isValid()) {
            row = categoriesModel_->getItem(aCategory)->parent()->categories().count();
        }
        categoriesModel_->insertRows(row, aCategory, title);
    }
}

void FormAchievements::updateCategories() {
    if (categoriesModel_) {
        categoriesModel_->update();
    }
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        filter->setCategories(CategoriesFilter());
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::onUpdateFilters() {
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::updateFilterCategory(Category *aCategory, bool aIsChecked) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        if (aIsChecked) {
            filter->addCategory(aCategory);
        } else {
            filter->removeCategory(aCategory);
        }
    }
    onUpdateFilters();
}

void FormAchievements::updateFilterWithMyProfile(const ReachedType &aType) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        switch (aType) {
        case ReachedType::all: {
            filter->setReached(0);
            break;
        }
        case ReachedType::reached: {
            filter->setReached(1);
            break;
        }
        case ReachedType::notReached: {
            filter->setReached(-1);
            break;
        }
        default: {
            break;
        }
        }
    }
    onUpdateFilters();
}

void FormAchievements::updateFilterTextAchievement(const QString &aNewText) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        filter->setName(aNewText);
    }
    onUpdateFilters();
}

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        QStringList list;
        for (const FavoriteAchievement &favorite: aFavorites) {
            list.append(favorite.apiName());
        }
        filter->setFavorites(list);
    }
    onUpdateFilters();
}
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case Qt::Unchecked: {
        updateFilterFavorite(QList<FavoriteAchievement>());
        ui->TableViewAchievements->resizeRowsToContents();
        break;
    }
    case Qt::Checked: {
        FavoriteAchievements favorites;
        auto profiles = favorites.profiles();
        auto iteratorProfile = std::find_if(profiles.begin(),
                                         profiles.end(),
                                         [=, this](const ProfileID &lProfileId) {
                                            return lProfileId == profile_.steamId();
                                         });
        if (iteratorProfile != profiles.end()) {
            auto games = favorites.games(*iteratorProfile);
            auto iteratorGame = std::find_if(games.begin(),
                                                games.end(),
                                                [=, this](const FavoriteAchievement::Game &lGame) {
                                                    return lGame.appId == game_.appId();
                                                });
            if (iteratorGame != games.end()) {
                updateFilterFavorite(favorites.achievements(*iteratorProfile, *iteratorGame));
            }
        }
        break;
    }
    }
}

void FormAchievements::openManual() {
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + QString::number(game_.appId()) + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}

bool FormAchievements::isDataSetted() {
    if (AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel())) {
        return model->getAchievementsCount() > 0 && profile_.personaName() != "" && game_.appId() > 0;
    }
    return false;
}

void FormAchievements::buttonComment_Clicked() {
    FormComments *form = createFramelessForm<FormComments>();
    form->setData(profile_.steamId(), game_, currentAchievement());
    connect(this, &Form::s_settingsUpdated, this, [=](QFlags<changedSettings> lSettings) {
        if (lSettings.testFlag(changedSettings::theme)) {
            form->window()->updateSettings();
        }
    });
//    connect(this, &FormAchievements::s_settingsUpdated, form->window(), &FramelessWindow::updateSettings);
    connect(form, &FormComments::s_updateComments, this, [&]() {
        if (AchievementsModel *model = dynamic_cast<AchievementsModel*>(ui->TableViewAchievements->originalModel())) {
            return model->updateComments();
        }
    });
    form->window()->show();
}
#define FunctionEnd }

void FormAchievements::setAllFriendsValue(const ReachedType &aType) {
    updateFilterFriend(profile_.steamId(), aType);
    for (const auto &profile: profilesInTable_) {
        updateFilterFriend(profile.first.steamId(), aType);
    }
}

void FormAchievements::updateFilterFriend(const ProfileID &aSteamId, const ReachedType &aType) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        switch (aType) {
        case ReachedType::all: {
            filter->setReachedFriend(0, aSteamId);
            break;
        }
        case ReachedType::reached: {
            filter->setReachedFriend(1, aSteamId);
            break;
        }
        case ReachedType::notReached: {
            filter->setReachedFriend(-1, aSteamId);
            break;
        }
        default: {
            break;
        }
        }
    }
    ui->TableViewAchievements->resizeRowsToContents();
    emit s_filtersValueUpdated();
}

void FormAchievements::addFriendToList(const SProfile &aSteamFriend, FriendListItemData::ProfileType aType) {
    if (aType == FriendListItemData::ProfileType::NotFriend ||
        aType == FriendListItemData::ProfileType::Unknown) {
        return;
    }
    FriendListItem *item = new FriendListItem(aSteamFriend, aType);
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->ListViewFriends->model())) {
        model->appendRow(item);
        model->sort(0);
    }
}

void FormAchievements::addProfileToTable(const QModelIndex &index) {
    ProfileID id = "";
    FriendListItemData::ProfileType type = FriendListItemData::ProfileType::Unknown;
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->ListViewFriends->model())) {
        if (FriendListItem *item = dynamic_cast<FriendListItem*>(model->item(index.row()))) {
            id = item->profile().steamId();
            type = item->profileType();
        }
    }
    auto iterator = std::find_if(friendsProfiles_.begin(),
                                 friendsProfiles_.end(),
                                 [=](const SProfile &lProfile) {
                                    return lProfile.steamId() == id;
                                 });
    if (iterator != friendsProfiles_.end()) {
        addFriendColumn(*iterator, type);
        if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->ListViewFriends->model())) {
            QList<QStandardItem*> row = model->takeRow(index.row());
            for (QStandardItem *item: row) {
                delete item;
            }
        }
    }
}

int FormAchievements::addFriendColumn(const SProfile &aSteamFriend, const FriendListItemData::ProfileType &aType) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        int index = filter->addProfile(aSteamFriend);
        ui->TableViewAchievements->setColumnWidth(index + achievementsModel::Count - 1, c_friendColumnWidth);
        profilesInTable_.append(QPair<SProfile, FriendListItemData::ProfileType>(aSteamFriend, aType));
        return index;
    }
    return -1;
}

bool FormAchievements::removeFriendColumn(const SProfile &aSteamFriend) {
    if (FilterModelAchievements *filter = dynamic_cast<FilterModelAchievements*>(ui->TableViewAchievements->filter())) {
        filter->removeProfile(aSteamFriend);
        profilesInTable_.removeIf([=](QPair<SProfile, FriendListItemData::ProfileType> lPair) {
            return lPair.first.steamId() == aSteamFriend.steamId();
        });
        return true;
    }
    return false;
}

void FormAchievements::buttonAddProfile_Clicked() {
    QString id = ui->lineEditFindProfile->text();
    SProfile::LoadType type = identifyProfileType(id);
    if (type == SProfile::LoadType::unknown) {
        qWarning() << "Не распознан профиль" << ui->lineEditFindProfile->text();
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось распознать синтаксис профиля"));
        return;
    }

    SProfile profile = SProfile::load(id, type);
    if(!profile.isNull()) {
        addFriendColumn(profile, FriendListItemData::ProfileType::NotFriend);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Нет данных о профиле!"));
        qWarning() << "profileError";
    }
}

void FormAchievements::findFriend() {
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->ListViewFriends->model())) {
        QString friendName = ui->lineEditFindFriend->text();
        for (int i = 0; i < model->rowCount(); ++i) {
            if (FriendListItem *item = dynamic_cast<FriendListItem*>(model->item(i))) {
                if (item->profile().personaName().indexOf(friendName) == -1) {
                    ui->ListViewFriends->setRowHidden(i, true);
                } else {
                    ui->ListViewFriends->setRowHidden(i, false);
                }
            }
        }
    }
}

void FormAchievements::checkBoxFriendsOnlyWithGame_Clicked(bool aChecked) {
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->ListViewFriends->model())) {
        QString friendName = ui->lineEditFindFriend->text();
        for (int i = 0; i < model->rowCount(); ++i) {
            if (aChecked) {
                if (FriendListItem *item = dynamic_cast<FriendListItem*>(model->item(i))) {
                    if (item->profileType() == FriendListItemData::ProfileType::FriendWithGame) {
                        ui->ListViewFriends->setRowHidden(i, false);
                    } else {
                        ui->ListViewFriends->setRowHidden(i, true);
                    }
                }
            } else {
                ui->ListViewFriends->setRowHidden(i, false);
            }
        }
    }
}
