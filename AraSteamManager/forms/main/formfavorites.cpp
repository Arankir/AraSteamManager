#include "formfavorites.h"
#include "ui_formfavorites.h"
#include "subWidgets/models/gamesmodel.h"
#include "subWidgets/models/friendsmodel.h"
#include "subWidgets/models/achievementsmodel.h"

#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>

using namespace FormFavoriteData;

FormFavorites::FormFavorites(QWidget *parent): Form(parent), ui(new Ui::FormFavorites) {
    ui->setupUi(this);
    init();
    ui->tabWidget->setCurrentIndex(0);
}

void FormFavorites::init() {
    initingTable(ui->TableViewGames);
    initingTable(ui->TableViewFriends);
    ui->treeWidgetAchievements->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->treeWidgetAchievements->setWordWrap(true);

    ui->TableViewGames->setModel(new QStandardItemModel());
    ui->TableViewFriends->setModel(new QStandardItemModel());

    connect(ui->TableViewGames, &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        GameID gameId = ui->TableViewGames->model()->data(ui->TableViewGames->currentIndex().siblingAtColumn(tableGames::Columns::gameId)).toString().toInt();
        ProfileID profileId = ui->TableViewGames->model()->data(ui->TableViewGames->currentIndex().siblingAtColumn(tableGames::Columns::profileId)).toString();
        QMenu *menu = createMenuGames(gameId, profileId);
        menu->popup(ui->TableViewGames->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewGames, &QTableView::doubleClicked,             this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        GameID gameId = ui->TableViewGames->model()->data(ui->TableViewGames->currentIndex().siblingAtColumn(tableGames::Columns::gameId)).toInt();
        ProfileID profileId = ui->TableViewGames->model()->data(ui->TableViewGames->currentIndex().siblingAtColumn(tableGames::Columns::profileId)).toString();
        goToGame(gameId, profileId);
    });

    connect(ui->TableViewFriends, &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        ProfileID profileId = ui->TableViewFriends->model()->data(ui->TableViewFriends->currentIndex().siblingAtColumn(tableProfiles::Columns::profileId)).toString();
        QMenu *menu = createMenuProfiles(profileId);
        menu->popup(ui->TableViewFriends->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableViewFriends, &QTableView::doubleClicked,             this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        ProfileID profileId = ui->TableViewFriends->model()->data(ui->TableViewFriends->currentIndex().siblingAtColumn(tableProfiles::Columns::profileId)).toString();
        emit s_goToProfile(profileId);
    });

    connect(ui->treeWidgetAchievements, &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        ProfileID profileId = "";
        GameID gameId = 0;
        AchievementID achievementId = ui->treeWidgetAchievements->model()->data(ui->treeWidgetAchievements->currentIndex().siblingAtColumn(treeAchievements::Columns::achievementId)).toString();
        QModelIndex game = ui->treeWidgetAchievements->currentIndex().parent();
        if (game.isValid()) {
            gameId = ui->treeWidgetAchievements->model()->data(game.siblingAtColumn(treeAchievements::Columns::achievementId)).toString().toInt();
            QModelIndex profile = game.parent();
            if (profile.isValid()) {
                profileId = ui->treeWidgetAchievements->model()->data(profile.siblingAtColumn(treeAchievements::Columns::achievementId)).toString();
            }
        }
        if (gameId > 0 && !profileId.isEmpty()) {
            QMenu *menu = createMenuAchievements(gameId, profileId, achievementId);
            menu->popup(ui->treeWidgetAchievements->viewport()->mapToGlobal(pos));
        }
    });
    connect(ui->treeWidgetAchievements, &QTableView::doubleClicked,             this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        QModelIndex parentIndex = ui->treeWidgetAchievements->currentIndex().parent();
        GameID gameId = ui->treeWidgetAchievements->model()->data(parentIndex.siblingAtColumn(treeAchievements::Columns::achievementId)).toInt();
        QModelIndex parentParentIndex = parentIndex.parent();
        ProfileID profileId = ui->treeWidgetAchievements->model()->data(parentParentIndex.siblingAtColumn(treeAchievements::Columns::achievementId)).toString();
        goToGame(gameId, profileId);
    });
    retranslate();
}

void FormFavorites::update() {
    updateGames();
    updateFriends();
    updateAchievements();
    retranslate();
}

void FormFavorites::updateGames() {
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->TableViewGames->model())) {
        model->clear();
        gamesFavorites_.update();
        int row = 0;
        for (const FavoriteGame &game: gamesFavorites_) {
            QStandardItem *itemProfileId = new QStandardItem(game.steamId());
            QStandardItem *itemGameId = new QStandardItem(QString::number(game.appId()));
            QStandardItem *itemIcon = new QStandardItem();
            itemIcon->setData(SGame::pixmapIcon(game.appId(), game.icon()), Qt::DecorationRole);
            QStandardItem *itemTitle = new QStandardItem(game.name());

            model->setItem(row, tableGames::Columns::profileId, itemProfileId);
            model->setItem(row, tableGames::Columns::gameId, itemGameId);
            model->setItem(row, tableGames::Columns::icon, itemIcon);
            model->setItem(row, tableGames::Columns::title, itemTitle);

            ++row;
        }
    }
    ui->TableViewGames->setColumnHidden(tableGames::Columns::profileId, true);
    ui->TableViewGames->setColumnHidden(tableGames::Columns::gameId, true);
    ui->TableViewGames->resizeRowsToContents();
    ui->TableViewGames->resizeColumnsToContents();
}

void FormFavorites::updateFriends() {
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->TableViewFriends->model())) {
        model->clear();
        int row = 0;
        friendsFavorites_.update();
        ProfileIDs friendsId;
        for (const FavoriteProfile &steamFriend: friendsFavorites_) {
            friendsId << steamFriend.profileId();
        }
        SProfiles profiles = SProfile::load(friendsId);
        for (const SProfile &steamFriend: profiles) {
            QStandardItem *itemProfileId = new QStandardItem(steamFriend.steamId());
            QStandardItem *itemIcon = new QStandardItem();
            itemIcon->setData(SProfile::pixmapAvatar(steamFriend.avatarUrl()), Qt::DecorationRole);
            QStandardItem *itemTitle = new QStandardItem(steamFriend.personaName());
            QStandardItem *itemStatus = new QStandardItem();
            itemStatus->setText(steamFriend.stateText());
            itemStatus->setForeground(steamFriend.stateColor());

            model->setItem(row, tableProfiles::Columns::profileId, itemProfileId);
            model->setItem(row, tableProfiles::Columns::icon, itemIcon);
            model->setItem(row, tableProfiles::Columns::title, itemTitle);
            model->setItem(row, tableProfiles::Columns::status, itemStatus);

            ++row;
        }
    }
    ui->TableViewFriends->setColumnHidden(tableProfiles::Columns::profileId, true);
    ui->TableViewFriends->resizeRowsToContents();
    ui->TableViewFriends->resizeColumnsToContents();
}

void FormFavorites::updateAchievements() {
    ui->treeWidgetAchievements->clear();
    achievementsFavorites_.update();
    SProfiles profiles = getProfilesFavoriteAchievements();
    for (const auto &profile: profiles) {
        QTreeWidgetItem *itemProfile = new QTreeWidgetItem();
        itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::DisplayRole, profile.personaName());
        itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
        itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::ToolTipRole, profile.personaName());
        itemProfile->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, profile.steamId());
        auto games = achievementsFavorites_.games(profile.steamId());
        for (const auto &game: games) {
            QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
            itemGame->setText(treeAchievements::Columns::profile, game.name);
            itemGame->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, QString::number(game.appId));
            auto achievements = achievementsFavorites_.achievements(profile.steamId(), game);
            for (const FavoriteAchievement &achievement: achievements) {
                QTreeWidgetItem *itemAchievement = new QTreeWidgetItem(itemGame);
                itemAchievement->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, achievement.apiName());
                itemAchievement->setData(treeAchievements::Columns::icon, Qt::ItemDataRole::DecorationRole, SAchievementSchema::icon(game.appId, achievement.icon()));
                itemAchievement->setData(treeAchievements::Columns::title, Qt::ItemDataRole::DisplayRole, achievement.title());
                itemAchievement->setData(treeAchievements::Columns::description, Qt::ItemDataRole::DisplayRole, achievement.description());
                itemAchievement->setData(treeAchievements::Columns::achieved, Qt::ItemDataRole::DisplayRole, achievement.achieved() ? tr("Получена") : tr("Не получена"));
            }
        }
        ui->treeWidgetAchievements->addTopLevelItem(itemProfile);
    }
//    QMap<ProfileID, QList<FavoriteAchievementsGame>> profilesFavorite;
//    for (const FavoriteAchievementsGame &achievementsGame: achievementsFavorites_) {
//        if (profilesFavorite.find(achievementsGame.steamId()) == profilesFavorite.end()) {
//            profilesFavorite.insert(achievementsGame.steamId(), QList<FavoriteAchievementsGame>());
//        }
//        auto iterator = profilesFavorite.find(achievementsGame.steamId());
//        if (iterator != profilesFavorite.end()) {
//            iterator.value().append(achievementsGame);
//        }
//    }
//    for (auto iterator = profilesFavorite.begin(); iterator != profilesFavorite.end(); ++iterator) {
//        auto iteratorProfiles = std::find_if(profiles.begin(),
//                                             profiles.end(),
//                                             [=](const SProfile &lProfile) {
//                                                return lProfile.steamId() == iterator.key();
//                                             });
//        if (iteratorProfiles != profiles.end()) {
//            QTreeWidgetItem *itemProfile = new QTreeWidgetItem();
//            itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::DisplayRole, iteratorProfiles->personaName());
//            itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::DecorationRole, iteratorProfiles->pixmapAvatar());
//            itemProfile->setData(treeAchievements::Columns::profile, Qt::ItemDataRole::ToolTipRole, iteratorProfiles->personaName());
//            itemProfile->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, iteratorProfiles->steamId());
//            for (const FavoriteAchievementsGame &achievementsGame: iterator.value()) {
//                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
//                itemGame->setText(treeAchievements::Columns::profile, achievementsGame.name());
//                itemGame->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, QString::number(achievementsGame.appId()));
//                for (const FavoriteAchievement &achievement: achievementsGame) {
//                    QTreeWidgetItem *itemAchievement = new QTreeWidgetItem(itemGame);
//                    itemAchievement->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, achievement.apiName());
//                    itemAchievement->setData(treeAchievements::Columns::icon, Qt::ItemDataRole::DecorationRole, SAchievementSchema::icon(achievementsGame.appId(), achievement.icon()));
//                    itemAchievement->setData(treeAchievements::Columns::title, Qt::ItemDataRole::DisplayRole, achievement.title());
//                    itemAchievement->setData(treeAchievements::Columns::description, Qt::ItemDataRole::DisplayRole, achievement.description());
//                    itemAchievement->setData(treeAchievements::Columns::achieved, Qt::ItemDataRole::DisplayRole, achievement.achieved() ? tr("Получена") : tr("Не получена"));
//                }
//            }
//            ui->treeWidgetAchievements->addTopLevelItem(itemProfile);
//        }
//    }
    ui->treeWidgetAchievements->expandAll();
    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::profile);
    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::icon);
    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::title);
    ui->treeWidgetAchievements->setColumnWidth(treeAchievements::Columns::title, std::min(150, ui->treeWidgetAchievements->columnWidth(treeAchievements::Columns::title)));
    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::description);
    ui->treeWidgetAchievements->setColumnWidth(treeAchievements::Columns::description, std::min(400, ui->treeWidgetAchievements->columnWidth(treeAchievements::Columns::description)));
    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::achieved);
    ui->treeWidgetAchievements->setColumnCount(5);
    ui->treeWidgetAchievements->setColumnHidden(treeAchievements::Columns::achievementId, true);
    ui->treeWidgetAchievements->collapseAll();
}

void FormFavorites::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::favorites)) {
        update();
    }
    Form::updateSettings(aSettings);
}

SProfiles FormFavorites::getProfilesFavoriteAchievements() {
//    QSet<ProfileID> usersId;
//    for (const FavoriteAchievementsGame &achievementsGame: achievementsFavorites_) {
//        usersId.insert(achievementsGame.steamId());
//    }
//    QStringList ids;
//    for (const QString &id: usersId) {
//        ids << id;
//    }
    return SProfile::load(achievementsFavorites_.profiles());
}

QMenu *FormFavorites::createMenuGames(const GameID &aGameId, const ProfileID &aProfileId) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoTo = new QAction(tr("Перейти на игру"));
    QAction *actionRemove = new QAction(tr("Удалить из избранного"));

    connect(actionGoTo, &QAction::triggered, this, [this, aGameId, aProfileId]() {
        goToGame(aGameId, aProfileId);
    });

    connect(actionRemove, &QAction::triggered, this, [this, aGameId, aProfileId]() {
        gamesFavorites_.remove(aProfileId, aGameId);
        gamesFavorites_.save();
        updateGames();
        emit s_settingsUpdated(changedSettings::favorites);
    });

    menu->addAction(actionGoTo);
    menu->addAction(actionRemove);

    return menu;
}

QMenu *FormFavorites::createMenuProfiles(const ProfileID &aProfileId) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoTo = new QAction(tr("Перейти на профиль"));
    QAction *actionRemove = new QAction(tr("Удалить из избранного"));

    connect(actionGoTo, &QAction::triggered, this, [this, aProfileId]() {
        emit s_goToProfile(aProfileId);
    });

    connect(actionRemove, &QAction::triggered, this, [this, aProfileId]() {
        friendsFavorites_.remove(aProfileId);
        friendsFavorites_.save();
        updateFriends();
        emit s_settingsUpdated(changedSettings::favorites);
    });

    menu->addAction(actionGoTo);
    menu->addAction(actionRemove);

    return menu;
}

QMenu *FormFavorites::createMenuAchievements(const GameID &aGameId, const ProfileID &aProfileId, const AchievementID &aAchievementId) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoTo = new QAction(tr("Перейти на игру"));
    QAction *actionRemove = new QAction(tr("Удалить из избранного"));

    connect(actionGoTo, &QAction::triggered, this, [this, aGameId, aProfileId]() {
        goToGame(aGameId, aProfileId);
    });

    connect(actionRemove, &QAction::triggered, this, [this, aGameId, aProfileId, aAchievementId]() {
        achievementsFavorites_.remove(aProfileId, aGameId, aAchievementId);
        achievementsFavorites_.save();
        updateAchievements();
        emit s_settingsUpdated(changedSettings::favorites);
    });

    menu->addAction(actionGoTo);
    menu->addAction(actionRemove);

    return menu;
}

void FormFavorites::goToGame(const GameID &aGameId, const ProfileID &aProfileId) {
    SGames games = SGame::load(aProfileId, true, true);
    for (const SGame &game: games) {
        if (game.appId() == aGameId) {
            emit s_showAchievements(aProfileId, game);
            return;
        }
    }
}

FormFavorites::~FormFavorites() {
    delete ui;
}

bool FormFavorites::isInit() {
    return true;
}

bool FormFavorites::isLoaded() {
    return true;
}

void FormFavorites::updateIcons() {

}

void FormFavorites::retranslate() {
    ui->retranslateUi(this);
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->TableViewGames->model())) {
        model->setHorizontalHeaderItem(0, new QStandardItem(tr("ID профиля")));
        model->setHorizontalHeaderItem(1, new QStandardItem(tr("ID игры")));
        model->setHorizontalHeaderItem(2, new QStandardItem(tr("")));
        model->setHorizontalHeaderItem(3, new QStandardItem(tr("Название")));
    }
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->TableViewFriends->model())) {
        model->setHorizontalHeaderItem(0, new QStandardItem(tr("ID профиля")));
        model->setHorizontalHeaderItem(1, new QStandardItem(tr("")));
        model->setHorizontalHeaderItem(2, new QStandardItem(tr("Ник")));
        model->setHorizontalHeaderItem(3, new QStandardItem(tr("Статус")));
    }
    ui->treeWidgetAchievements->setHeaderLabels(QStringList{tr("Профиль"),tr("ID"),tr("Название"),tr("Описание"),tr("Получено")});
}
