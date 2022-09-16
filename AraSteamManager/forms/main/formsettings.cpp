#include "formsettings.h"
#include "ui_formsettings.h"

#include "version.h"
#include "classes/steamApi/sapi.h"
#include "classes/common/theme.h"
#include "classes/common/images.h"
#include "classes/files/hiddengames.h"
#include "classes/files/comments.h"
#include "classes/files/groupsgames.h"
#include "subWidgets/items/friendlistitem.h"

#include <QAction>
#include <QMenu>
#include <QColorDialog>

namespace SettingsData {
    namespace HiddenGames {
        enum Columns {
            id = 1,
            icon = 0,
            text = 0
        };
    }
    namespace Export {
        namespace Favorite {
            enum Columns {
                mainData = 0,
                id = 1
            };
        }
        namespace Comments {
            enum Columns {
                mainData = 0,
                id = 1,
                comment = 2
            };
        }
    }
}

FormSettings::FormSettings(QWidget *aParent): Form(aParent), ui(new Ui::FormSettings) {
    ui->setupUi(this);
    init();
}

FormSettings::~FormSettings() {
    delete ui;
}

void FormSettings::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::hiddenGame)) {
        updateHiddenGames();
    }
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

bool FormSettings::isInit() {
    return isInit_;
}

bool FormSettings::isLoaded() {
    return isInit_;
}

void FormSettings::init() {
    ui->tabWidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->treeWidgetExportFavoriteAchievements->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->treeWidgetExportFavoriteAchievements->setWordWrap(true);

    initCommonSettings();
    initExport();
    initHiddenGames();

    ui->tabWidget->setCurrentIndex(0);
    ui->labelVersion->setText(VER_PRODUCTVERSION_STR);

#define Connects {
    connect(ui->ButtonExportCategories, &QPushButton::clicked, this, &FormSettings::buttonExportCategories_Clicked);
    connect(ui->ButtonImportCategories, &QPushButton::clicked, this, &FormSettings::buttonImportCategories_Clicked);
#define ConnectsEnd }
    retranslate();
    isInit_ = true;
}

void FormSettings::initCommonSettings() {
    ui->comboBoxProfileInfo->addItems(QStringList {tr("Минимум"), tr("Обычные"), tr("Максимум")});
    ui->ComboBoxLanguage->addItems(QStringList {tr("English"), tr("Русский")});
    switch (Settings::language()) {
    case 1: {
        ui->ComboBoxLanguage->setCurrentIndex(0);
        break;
    }
    case 5: {
        ui->ComboBoxLanguage->setCurrentIndex(1);
        break;
    }
    default: {
        break;
    }
    }
    ui->ComboBoxTheme->addItems(QStringList {tr("Тёмная"), tr("Светлая"), tr("Синяя"), tr("Оранжевая"), tr("Малиновая"), tr("Лаймовая"), tr("Фиолетовая"), tr("Зеленая"), tr("Пользовательская")});
    ui->ComboBoxTheme->setItemData(0, blackTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(1, whiteTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(2, blueTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(3, orangeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(4, crimsonTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(5, limeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(6, purpleTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(7, greenTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(8, QColor(255, 255, 255, 20), Qt::DecorationRole);
    switch (Settings::theme()) {
    case 0: {
        ui->ComboBoxTheme->setCurrentIndex(8);
        break;
    }
    case 1: {
        ui->ComboBoxTheme->setCurrentIndex(2);
        break;
    }
    case 2: {
        ui->ComboBoxTheme->setCurrentIndex(1);
        break;
    }
    case 3: {
        ui->ComboBoxTheme->setCurrentIndex(0);
        break;
    }
    case 4: {
        ui->ComboBoxTheme->setCurrentIndex(3);
        break;
    }
    case 5: {
        ui->ComboBoxTheme->setCurrentIndex(4);
        break;
    }
    case 6: {
        ui->ComboBoxTheme->setCurrentIndex(5);
        break;
    }
    case 7: {
        ui->ComboBoxTheme->setCurrentIndex(6);
        break;
    }
    case 8: {
        ui->ComboBoxTheme->setCurrentIndex(7);
        break;
    }
    default: {
        break;
    }
    }
    ui->comboBoxProfileInfo->setCurrentIndex(Settings::profileInfoSize());
    ui->labelIcons8->setTextFormat(Qt::RichText);
    connect(ui->ComboBoxTheme,              SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxThemeIndexChanged(int)));
    connect(ui->ComboBoxLanguage,           SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxLanguageIndexChanged(int)));

    connect(ui->comboBoxProfileInfo,        SIGNAL(currentIndexChanged(int)), this, SLOT(slideProfileSize_ValueChanged(int)));
//    QPalette darkPalette;
//    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    //ui->GroupBoxDarkTheme->setPalette(darkPalette);
    //ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());

}

void FormSettings::initExport() {
    ui->TreeWidgetExportCategories->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    //Категории
    updateExportCategories();

    //Избранное
    ui->treeWidgetExportFavoriteAchievements->clear();
    updateExportFavoriteGames();
    updateExportFavoriteFriends();
    updateExportFavoriteAchievements();
    ui->treeWidgetExportFavoriteAchievements->expandAll();
    ui->treeWidgetExportFavoriteAchievements->resizeColumnToContents(SettingsData::Export::Favorite::Columns::mainData);
    ui->treeWidgetExportFavoriteAchievements->resizeColumnToContents(SettingsData::Export::Favorite::Columns::id);
    ui->treeWidgetExportFavoriteAchievements->setColumnCount(2);
    ui->treeWidgetExportFavoriteAchievements->setColumnHidden(SettingsData::Export::Favorite::Columns::id, true);
    ui->treeWidgetExportFavoriteAchievements->collapseAll();

    //Комментарии
    ui->TreeWidgetExportComments->clear();
    updateExportCommentsGames();
    updateExportCommentsAchievements();
    ui->TreeWidgetExportComments->expandAll();
    ui->TreeWidgetExportComments->resizeColumnToContents(SettingsData::Export::Comments::Columns::mainData);
    ui->TreeWidgetExportComments->resizeColumnToContents(SettingsData::Export::Comments::Columns::id);
    ui->TreeWidgetExportComments->resizeColumnToContents(SettingsData::Export::Comments::Columns::comment);
    ui->TreeWidgetExportComments->setColumnCount(3);
    ui->TreeWidgetExportComments->setColumnHidden(SettingsData::Export::Comments::Columns::id, true);
    ui->TreeWidgetExportComments->collapseAll();

    //Группы
    updateExportGroups();
}

void FormSettings::updateExportCategories() {
    ui->TreeWidgetExportCategories->clear();
    QDir dir(Paths::categories());
    for (auto &file: dir.entryInfoList(QDir::Files)) {
        QFile fileCategory(file.filePath());
        if (fileCategory.exists()) {
            if(fileCategory.open(QFile::ReadOnly)) {
                Category game(QJsonDocument().fromJson(fileCategory.readAll()).object());
                game.update();
                QTreeWidgetItem *item = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << game.gameName());
                item->setWhatsThis(0, QString::number(game.gameID()));
                QStringList path = game.getPathFromRoot();
                item->setWhatsThis(1, QVariant(path).toString());
                ui->TreeWidgetExportCategories->addTopLevelItem(item);
                for (auto &category: game.categories()) {
                    recursAddCategoryToTree(category, item, game.gameID());
                }
                fileCategory.close();
            }
        }
    }
}

void FormSettings::updateExportFavoriteGames() {
    gamesFavorites_.update();
    QTreeWidgetItem *itemTop = new QTreeWidgetItem(ui->treeWidgetExportFavoriteAchievements);
    itemTop->setText(0, tr("Игры"));

    QStringList profilesId;
    for (const auto &profile: gamesFavorites_) {
        profilesId << profile.steamId();
    }

    SProfiles profiles = SProfile::load(profilesId);
    QMap<ProfileID, QList<FavoriteGame>> profilesFavorite;
    for (const auto &achievementsGame: gamesFavorites_) {
        if (profilesFavorite.find(achievementsGame.steamId()) == profilesFavorite.end()) {
            profilesFavorite.insert(achievementsGame.steamId(), QList<FavoriteGame>());
        }
        auto iterator = profilesFavorite.find(achievementsGame.steamId());
        if (iterator != profilesFavorite.end()) {
            iterator.value().append(achievementsGame);
        }
    }
    for (auto iterator = profilesFavorite.begin(); iterator != profilesFavorite.end(); ++iterator) {
        auto iteratorProfiles = std::find_if(profiles.begin(),
                                             profiles.end(),
                                             [=](const SProfile &lProfile) {
                                                return lProfile.steamId() == iterator.key();
                                             });
        if (iteratorProfiles != profiles.end()) {
            QTreeWidgetItem *itemProfile = new QTreeWidgetItem(itemTop);
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorProfiles->personaName());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorProfiles->pixmapAvatar());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorProfiles->personaName());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, iteratorProfiles->steamId());
            for (const auto &game: iterator.value()) {
                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                itemGame->setText(SettingsData::Export::Favorite::Columns::mainData, game.name());
                itemGame->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DecorationRole, SGame::pixmapIcon(game.appId(), game.icon()));
                itemGame->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, QString::number(game.appId()));
            }
        }
    }
    ui->treeWidgetExportFavoriteAchievements->addTopLevelItem(itemTop);
}

void FormSettings::updateExportFavoriteFriends() {
    friendsFavorites_.update();
    QTreeWidgetItem *itemTop = new QTreeWidgetItem(ui->treeWidgetExportFavoriteAchievements);
    itemTop->setText(0, tr("Профили"));

    QStringList profilesId;
    for (const auto &profile: friendsFavorites_) {
        profilesId << profile.profileId();
    }

    SProfiles profiles = SProfile::load(profilesId);
    for (auto iterator = profiles.begin(); iterator != profiles.end(); ++iterator) {
        QTreeWidgetItem *itemProfile = new QTreeWidgetItem(itemTop);
        itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DisplayRole, iterator->personaName());
        itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DecorationRole, iterator->pixmapAvatar());
        itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iterator->personaName());
        itemProfile->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, iterator->steamId());
    }
    ui->treeWidgetExportFavoriteAchievements->addTopLevelItem(itemTop);
}

SProfiles FormSettings::getProfilesFavoriteAchievements() {
    QSet<ProfileID> usersId;
    for (const auto &achievementsGame: achievementsFavorites_) {
        usersId.insert(achievementsGame.steamId());
    }
    QStringList ids;
    for (const auto &id: usersId) {
        ids << id;
    }
    return SProfile::load(ids);
}

void FormSettings::updateExportFavoriteAchievements() {
    achievementsFavorites_.update();
    QTreeWidgetItem *itemTop = new QTreeWidgetItem(ui->treeWidgetExportFavoriteAchievements);
    itemTop->setText(0, tr("Достижения"));

    SProfiles profiles = getProfilesFavoriteAchievements();
    QMap<ProfileID, QList<FavoriteAchievementsGame>> profilesFavorite;
    for (const auto &achievementsGame: achievementsFavorites_) {
        if (profilesFavorite.find(achievementsGame.steamId()) == profilesFavorite.end()) {
            profilesFavorite.insert(achievementsGame.steamId(), QList<FavoriteAchievementsGame>());
        }
        auto iterator = profilesFavorite.find(achievementsGame.steamId());
        if (iterator != profilesFavorite.end()) {
            iterator.value().append(achievementsGame);
        }
    }
    for (auto iterator = profilesFavorite.begin(); iterator != profilesFavorite.end(); ++iterator) {
        auto iteratorProfiles = std::find_if(profiles.begin(),
                                             profiles.end(),
                                             [=](const SProfile &lProfile) {
                                                return lProfile.steamId() == iterator.key();
                                             });
        if (iteratorProfiles != profiles.end()) {
            QTreeWidgetItem *itemProfile = new QTreeWidgetItem(itemTop);
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorProfiles->personaName());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorProfiles->pixmapAvatar());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorProfiles->personaName());
            itemProfile->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, iteratorProfiles->steamId());
            for (const auto &achievementsGame: iterator.value()) {
                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                itemGame->setText(SettingsData::Export::Favorite::Columns::mainData, achievementsGame.name());
                itemGame->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, QString::number(achievementsGame.appId()));
                for (const auto &achievement: achievementsGame) {
                    QTreeWidgetItem *itemAchievement = new QTreeWidgetItem(itemGame);
                    itemAchievement->setData(SettingsData::Export::Favorite::Columns::id, Qt::ItemDataRole::DisplayRole, achievement.apiName());
                    itemAchievement->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DecorationRole, SAchievementSchema::icon(achievementsGame.appId(), achievement.icon()));
                    itemAchievement->setData(SettingsData::Export::Favorite::Columns::mainData, Qt::ItemDataRole::DisplayRole, achievement.title());
                }
            }
        }
    }
    ui->treeWidgetExportFavoriteAchievements->addTopLevelItem(itemTop);
}

void FormSettings::updateExportCommentsGames() {
//    if (auto model = dynamic_cast<QStandardItemModel*>(ui->TableViewGames->model())) {
//        model->clear();
//        gamesFavorites_.update();
//        int row = 0;
//        for (const auto &game: gamesFavorites_) {
//            QStandardItem *itemProfileId = new QStandardItem(game.steamId());
//            QStandardItem *itemGameId = new QStandardItem(QString::number(game.appId()));
//            QStandardItem *itemIcon = new QStandardItem();
//            itemIcon->setData(SGame::pixmapIcon(game.appId(), game.icon()), Qt::DecorationRole);
//            QStandardItem *itemTitle = new QStandardItem(game.name());

//            model->setItem(row, tableGames::Columns::profileId, itemProfileId);
//            model->setItem(row, tableGames::Columns::gameId, itemGameId);
//            model->setItem(row, tableGames::Columns::icon, itemIcon);
//            model->setItem(row, tableGames::Columns::title, itemTitle);

//            ++row;
//        }
//        ui->TableViewGames->setColumnHidden(tableGames::Columns::profileId, true);
//        ui->TableViewGames->setColumnHidden(tableGames::Columns::gameId, true);
//        ui->TableViewGames->resizeRowsToContents();
//        ui->TableViewGames->resizeColumnsToContents();
//    }

    QTreeWidgetItem *itemTop = new QTreeWidgetItem(ui->TreeWidgetExportComments);
    itemTop->setText(0, tr("Игры"));
    QDir dir(Paths::commentsGames());
    for (auto &file: dir.entryInfoList(QDir::Files)) {
        QString profileId = file.fileName().remove(".json");
        GameComments comments(profileId);
        SProfile profile = SProfile::load(profileId);
        SGames games = SGame::load(profileId, true, true);

        QTreeWidgetItem *itemProfile = new QTreeWidgetItem(itemTop);
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DisplayRole, profile.personaName());
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::ToolTipRole, profile.personaName());
        itemProfile->setData(SettingsData::Export::Comments::Columns::id, Qt::ItemDataRole::DisplayRole, profile.steamId());
        for (auto &comment: comments) {
            auto iteratorGame = std::find_if(games.begin(),
                                             games.end(),
                                             [=](const SGame &lGame) {
                                                return lGame.appId() == comment.gameId();
                                             });
            if (iteratorGame != games.end()) {
                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorGame->name());
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorGame->pixmapIcon());
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorGame->name());
                itemGame->setData(SettingsData::Export::Comments::Columns::id, Qt::ItemDataRole::DisplayRole, comment.gameId());
                itemGame->setData(SettingsData::Export::Comments::Columns::comment, Qt::ItemDataRole::DisplayRole, comment.comment().join("\n"));
            }
        }
    }
}

void FormSettings::updateExportCommentsAchievements() {
//    ui->treeWidgetAchievements->clear();
//    achievementsFavorites_.update();
//    SProfiles profiles = getProfilesFavoriteAchievements();
//    QMap<ProfileID, QList<FavoriteAchievementsGame>> profilesFavorite;
//    for (const auto &achievementsGame: achievementsFavorites_) {
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
//            for (const auto &achievementsGame: iterator.value()) {
//                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
//                itemGame->setText(treeAchievements::Columns::profile, achievementsGame.name());
//                itemGame->setData(treeAchievements::Columns::achievementId, Qt::ItemDataRole::DisplayRole, QString::number(achievementsGame.appId()));
//                for (const auto &achievement: achievementsGame) {
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
//    ui->treeWidgetAchievements->expandAll();
//    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::profile);
//    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::icon);
//    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::title);
//    ui->treeWidgetAchievements->setColumnWidth(treeAchievements::Columns::title, std::min(150, ui->treeWidgetAchievements->columnWidth(treeAchievements::Columns::title)));
//    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::description);
//    ui->treeWidgetAchievements->setColumnWidth(treeAchievements::Columns::description, std::min(400, ui->treeWidgetAchievements->columnWidth(treeAchievements::Columns::description)));
//    ui->treeWidgetAchievements->resizeColumnToContents(treeAchievements::Columns::achieved);
//    ui->treeWidgetAchievements->setColumnCount(5);
//    ui->treeWidgetAchievements->setColumnHidden(treeAchievements::Columns::achievementId, true);
//    ui->treeWidgetAchievements->collapseAll();
    QTreeWidgetItem *itemTop = new QTreeWidgetItem(ui->TreeWidgetExportComments);
    itemTop->setText(0, tr("Достижения"));
    QDir dir(Paths::commentsAchievements());
    for (auto &file: dir.entryInfoList(QDir::Files)) {
        QString profileId = file.fileName().remove(".json");
        AchievementComments comments(profileId);
        SProfile profile = SProfile::load(profileId);
        SGames games = SGame::load(profileId, true, true);

        QMap<GameID, QList<AchievementComment> > gamesComments;
        for (const auto &achievementsGame: comments) {
            if (gamesComments.find(achievementsGame.gameId()) == gamesComments.end()) {
                gamesComments.insert(achievementsGame.gameId(), QList<AchievementComment>());
            }
            auto iterator = gamesComments.find(achievementsGame.gameId());
            if (iterator != gamesComments.end()) {
                iterator.value().append(achievementsGame);
            }
        }

        QTreeWidgetItem *itemProfile = new QTreeWidgetItem(itemTop);
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DisplayRole, profile.personaName());
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
        itemProfile->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::ToolTipRole, profile.personaName());
        itemProfile->setData(SettingsData::Export::Comments::Columns::id, Qt::ItemDataRole::DisplayRole, profile.steamId());

        for (auto iterator = gamesComments.begin(); iterator != gamesComments.end(); ++iterator) {
            auto iteratorGame = std::find_if(games.begin(),
                                             games.end(),
                                             [=](const SGame &lGame) {
                                                return lGame.appId() == iterator.key();
                                             });
            if (iteratorGame != games.end()) {
                QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorGame->name());
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorGame->pixmapIcon());
                itemGame->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorGame->name());
                itemGame->setData(SettingsData::Export::Comments::Columns::id, Qt::ItemDataRole::DisplayRole, iterator.key());
                for (const auto &comment: iterator.value()) {
                    QTreeWidgetItem *itemAchievement = new QTreeWidgetItem(itemGame);
                    itemAchievement->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorGame->name());//TODO заменить на достижение
                    itemAchievement->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorGame->pixmapIcon());//TODO заменить на достижение
                    itemAchievement->setData(SettingsData::Export::Comments::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorGame->name());//TODO заменить на достижение
                    itemAchievement->setData(SettingsData::Export::Comments::Columns::id, Qt::ItemDataRole::DisplayRole, comment.achievementId());
                    itemAchievement->setData(SettingsData::Export::Comments::Columns::comment, Qt::ItemDataRole::DisplayRole, comment.comment().join("\n"));
                }
            }
        }
    }
}

void FormSettings::updateExportGroups() {
//    QDir dir(Paths::groupGames());
//    for (auto &file: dir.entryInfoList(QDir::Files)) {
//        ProfileID profileId = file.filePath().remove(".txt");
//        GroupsGames profileGroups(profileId);
//        SProfile profile = SProfile::load(profileId);
//        QTreeWidgetItem *item = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << profile.personaName());

//        QFile fileCategory(file.filePath());
//        if (fileCategory.exists()) {
//            if(fileCategory.open(QFile::ReadOnly)) {
//                Category game(QJsonDocument().fromJson(fileCategory.readAll()).object());
//                game.update();
//                QTreeWidgetItem *item = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << game.gameName());
//                item->setWhatsThis(0, QString::number(game.gameID()));
////                item->setWhatsThis(1, QString::number(-2));
//                ui->TreeWidgetExportCategories->addTopLevelItem(item);
//                for (auto &category: game.categories()) {
//                    recursAddCategoryToTree(category, item, game.gameID());
//                }
//                fileCategory.close();
//            }
//        }
//    }
}

void FormSettings::initHiddenGames() {
    ui->treeWidgetHiddenGames->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->treeWidgetHiddenGames->setWordWrap(true);
    connect(ui->treeWidgetHiddenGames, &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        GameID gameId = ui->treeWidgetHiddenGames->model()->data(ui->treeWidgetHiddenGames->currentIndex().siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toString().toInt();
        auto profile = ui->treeWidgetHiddenGames->currentIndex().parent();
        if (profile.isValid()) {
            ProfileID profileId = ui->treeWidgetHiddenGames->model()->data(profile.siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toString();
            if (gameId > 0) {
                QMenu *menu = createMenuHiddenGame(ui->treeWidgetHiddenGames->currentIndex());
                menu->popup(ui->treeWidgetHiddenGames->viewport()->mapToGlobal(pos));
            }
        }
    });
    connect(ui->treeWidgetHiddenGames, &QTableView::doubleClicked,             this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        achievementsClicked();
    });

    updateHiddenGames();
    ui->treeWidgetHiddenGames->setColumnCount(2);
    ui->treeWidgetHiddenGames->setColumnHidden(SettingsData::HiddenGames::Columns::id, true);
}

void FormSettings::updateHiddenGames() {
    ui->treeWidgetHiddenGames->clear();

    QDir dirHiddenGames(Paths::hiddenGames().remove("All.txt"));
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()) {
        QFileInfoList list = dirHiddenGames.entryInfoList();
        for(auto &file: list) {
            QString fileName = file.fileName();
            HiddenGames hGames(fileName == "All.txt" ? "" : fileName.remove(".txt"));
            if (hGames.count() > 0) {
                QTreeWidgetItem *itemProfile = new QTreeWidgetItem();
                if(fileName == "All.txt") {
                    itemProfile->setData(SettingsData::HiddenGames::Columns::text, Qt::ItemDataRole::DisplayRole, tr("Скрыто у всех"));
                } else {
                    SProfile profile = SProfile::load(fileName.remove(".txt"), SProfile::LoadType::id);
                    itemProfile->setData(SettingsData::HiddenGames::Columns::icon, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
                    itemProfile->setData(SettingsData::HiddenGames::Columns::text, Qt::ItemDataRole::DisplayRole, profile.personaName());
                    itemProfile->setData(SettingsData::HiddenGames::Columns::id, Qt::ItemDataRole::DisplayRole, profile.steamId());
                }
                itemProfile->setData(SettingsData::HiddenGames::Columns::text, Qt::ItemDataRole::ToolTipRole, textToToolTip(itemProfile->data(SettingsData::HiddenGames::Columns::text, Qt::ItemDataRole::DisplayRole).toString()));

                for(auto &game: hGames) {
                    QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                    itemGame->setData(SettingsData::HiddenGames::Columns::icon, Qt::ItemDataRole::DecorationRole, SGame::pixmapIcon(game.id(), game.iconUrl()));
                    itemGame->setText(SettingsData::HiddenGames::Columns::text, game.name());
                    itemGame->setData(SettingsData::HiddenGames::Columns::id, Qt::ItemDataRole::DisplayRole, QString::number(game.id()));
                }
                ui->treeWidgetHiddenGames->addTopLevelItem(itemProfile);
            }
        }
    }

    ui->treeWidgetHiddenGames->expandAll();
    ui->treeWidgetHiddenGames->resizeColumnToContents(SettingsData::HiddenGames::Columns::id);
    ui->treeWidgetHiddenGames->resizeColumnToContents(SettingsData::HiddenGames::Columns::icon);
    ui->treeWidgetHiddenGames->resizeColumnToContents(SettingsData::HiddenGames::Columns::text);
    ui->treeWidgetHiddenGames->setColumnWidth(SettingsData::HiddenGames::Columns::text, std::min(150, ui->treeWidgetHiddenGames->columnWidth(SettingsData::HiddenGames::Columns::text)));
    ui->treeWidgetHiddenGames->collapseAll();
}

QMenu *FormSettings::createMenuHiddenGame(const QModelIndex &aIndex) {
    Q_UNUSED(aIndex);
    QMenu *menu = new QMenu();

    QAction *actionAchievements = new QAction(QIcon(Images::achievement()), tr("Достижения"), menu);
    QAction *actionUnhidden = new QAction(QIcon(Images::visible()), tr("Убрать из скрытого"), menu);

    connect(actionAchievements, &QAction::triggered, this, &FormSettings::achievementsClicked);
    connect(actionUnhidden, &QAction::triggered, this, &FormSettings::hideClicked);

    menu->addAction(actionAchievements);
    menu->addAction(actionUnhidden);

    return menu;
}

int FormSettings::recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot, const int &aGameId) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << aCategory->title());
    } else {
        subItem = new QTreeWidgetItem(aRoot, QStringList() << aCategory->title());
    }
    subItem->setWhatsThis(0,QString::number(aGameId));
//    subItem->setWhatsThis(1,QString::number(aCategory->order()));
    for(auto subCategory: aCategory->categories()) {
        recursAddCategoryToTree(subCategory, subItem, aGameId);
    }
    return 0;
}

void FormSettings::comboBoxThemeIndexChanged(const int &aIndex) {
    switch (aIndex) {
    case 0: {
        Settings::setTheme(3);
        break;
    }
    case 1: {
        Settings::setTheme(2);
        break;
    }
    case 2: {
        Settings::setTheme(1);
        break;
    }
    case 3: {
        Settings::setTheme(4);
        break;
    }
    case 4: {
        Settings::setTheme(5);
        break;
    }
    case 5: {
        Settings::setTheme(6);
        break;
    }
    case 6: {
        Settings::setTheme(7);
        break;
    }
    case 7: {
        Settings::setTheme(8);
        break;
    }
    case 8: {
        QColor themeColor = QColorDialog::getColor(Qt::white, this, tr("Выберите цвет"));
        customTheme(themeColor).save(Paths::documents() + "theme\\custom.json");
        Settings::setTheme(0);
        break;
    }
    default: {
        break;
    }
    }
    emit s_settingsUpdated(changedSettings::theme);
}

void FormSettings::comboBoxLanguageIndexChanged(const int &aIndex) {
    switch (aIndex) {
    case 0: {
        Settings::setLanguage(1);
        emit s_settingsUpdated(changedSettings::language);
        QTranslator *translator = new QTranslator;
        if (translator->load(":/AraSteamManager_en.qm")) {
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
        } else {
            qWarning() << "error change language";
        }
        break;
    }
    case 1: {
        Settings::setLanguage(5);
        emit s_settingsUpdated(changedSettings::language);
        QTranslator *translator = new QTranslator;
        if (translator->load(":/AraSteamManager_ru.qm")) {
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
        } else {
            qWarning() << "error change language";
        }
        break;
    }
    default: {
        break;
    }
    }
}

void FormSettings::buttonExportCategories_Clicked() {
    QString sFile = QFileDialog::getSaveFileName(this, tr("Место сохранения файла"), "", ".sas");
    if (sFile == "") {
        return;
    }
    ExportFileData exportData = createExportCategoriesJson();
    if (sFile.left(4) != ".sas") {
        sFile += ".sas";
    }
    QFile fFile(sFile);
    fFile.open(QFile::WriteOnly);
    fFile.write(QJsonDocument(exportData.toJson()).toJson());
    fFile.close();
    QMessageBox::information(this, tr("Успешно!"), tr("Файл успешно создан!"));
}

ExportFileData FormSettings::createExportCategoriesJson() {
    QJsonArray jArray;
    for (auto &item: ui->TreeWidgetExportCategories->selectedItems()) {
        Category categories(item->whatsThis(0).toInt(), "");
        auto vPath = QVariant(item->whatsThis(1)).toList();
        QStringList path;
        for (auto vTitle: vPath) {
            path << vTitle.toString();
        }
        if (path == categories.getPathFromRoot()) {
            auto subCategories = categories.categories();
            for (auto category: subCategories) {
                ExportCategory eCategory(categories.gameID(), categories.title(), *category);
                jArray.append(eCategory.toJson());
            }
        } else {
            Category *category = categories.find(path);
            if (category != nullptr) {
                ExportCategory eCategory(categories.gameID(), categories.title(), *category);
                jArray.append(eCategory.toJson());
            }
        }
    }
    ExportFileData efd;
    efd.data = jArray;
    efd.type = ExportType::categories;
    efd.version = 1.0;
    efd.date = QDateTime::currentDateTime();
    return efd;
}

ExportFileData *FormSettings::getFileFromPath(QLineEdit *aLineEdit) {
    QString path;
    if (aLineEdit->text() == "") {
        path = QFileDialog::getOpenFileName(this, tr("Выбор файла для загрузки"), "", "*");
        if (path == "") {
            return nullptr;
        }
    } else {
        path = aLineEdit->text();
    }
    QFile fFile(path);
    if (!fFile.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно найти указанный файл, или файл открыт в другом приложении!"));
        return nullptr;
    }
    ExportFileData *efd = new ExportFileData(ExportFileData::fromJson(QJsonDocument::fromJson(fFile.readAll()).object()));
    fFile.close();
    return efd;
}

void FormSettings::buttonImportCategories_Clicked() {
    ExportFileData *fileData = getFileFromPath(ui->LineEditImportCategories);
    if (fileData == nullptr) {
        return;
    }

    if (fileData->type != ExportType::categories) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле нет категорий"));
        return;
    }

    QVector<ExportCategory> eCategories;
    for(const auto &category: fileData->data.toArray()) {
        eCategories.append(ExportCategory(category.toObject()));
    }

    if (eCategories.size() == 0) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле не обнаружено категорий"));
        return;
    }

    QStringList slCategories;
    for (auto &category: eCategories) {
        slCategories.append(tr("Игра: %1, категория: %2").arg(category.gameName, category.category.title()));
    }
    QString questionText = tr("Обнаружены следующие категории: \n") + slCategories.join("\n") + ".";

    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           questionText);
    QAbstractButton *btnYes = question.addButton(tr("Добавить эти категории"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();
    if(question.clickedButton() != btnYes) {
        return;
    }
    //Обновить категории
    for(const auto &eCategory: eCategories) {
        GameID gameId = eCategory.gameId;
        QString gameName = eCategory.gameName;
        Category categories(gameId, gameName);
        categories.addCategory(new Category(eCategory.category));
        categories.save();
    }
    QMessageBox::information(this, tr("Внимание!"), tr("Категории успешно добавлены!"));
}

void FormSettings::retranslate() {
    ui->retranslateUi(this);
    ui->ComboBoxTheme->setItemText(0, tr("Тёмная"));
    ui->ComboBoxTheme->setItemText(1, tr("Светлая"));
    ui->ComboBoxTheme->setItemText(2, tr("Синяя"));
    ui->ComboBoxTheme->setItemText(3, tr("Оранжевая"));
    ui->ComboBoxTheme->setItemText(4, tr("Малиновая"));
    ui->ComboBoxTheme->setItemText(5, tr("Лаймовая"));
    ui->ComboBoxTheme->setItemText(6, tr("Фиолетовая"));
    ui->ComboBoxTheme->setItemText(7, tr("Зеленая"));
    ui->ComboBoxTheme->setItemText(8, tr("Пользовательская"));

    if (this->findChild<QRadioButtonWithData*>("HiddenGames0") != 0) {
        QRadioButtonWithData *allHidden = this->findChild<QRadioButtonWithData*>("HiddenGames0");
        allHidden->setText(tr("Все профили"));
    }
    ui->labelIcons8->setText(tr("<html>"
                                    "<head/>"
                                    "<body>"
                                        "<p>"
                                            "Иконки для приложения были предоставлены сайтом "
                                            "<a href=https://icons8.ru/icons>"
                                                "<span style=\" text-decoration: underline; color:#2d7fc8;\"> "
                                                    "https://icons8.ru/icons"
                                                "</span>"
                                            "</a>"
                                        "</p>"
                                    "</body>"
                                "</html>"));
}

void FormSettings::updateIcons() {

}

void FormSettings::checkBoxVisibleHiddenGames_StateChanged(int arg1) {
    Settings::setVisibleHiddenGames(arg1 / 2);
    emit s_settingsUpdated(changedSettings::visibleHiddenGame);
}

void FormSettings::itemModelHiddenGames_Clicked(const QModelIndex &aIndex) {
//    auto model = dynamic_cast<QStandardItemModel*>(ui->tableViewHiddenGames->model());
//    if (model == nullptr) {
//        return;
//    }
//    if (aIndex.row() > listProfiles_.count()) {
//        return;
//    }

//    model->clear();

//    HiddenGames hGames(listProfiles_[aIndex.row()]);
//    if (aIndex.row() != 0) {
//        SGames games = SGame::load(listProfiles_[aIndex.row()], true, true);
//        int row = 0;
//        for(auto &game: games) {
//            if (hGames.isGameExist(game.appId())) {
//                QStandardItem *itemGameId = new QStandardItem(QString::number(game.appId()));

//                QStandardItem *itemProfileId = new QStandardItem(listProfiles_[aIndex.row()]);

//                QStandardItem *itemIcon = new QStandardItem();
//                itemIcon->setData(game.pixmapIcon(), Qt::ItemDataRole::DecorationRole);

//                QStandardItem *itemTitle = new QStandardItem(game.name());

//                model->setItem(row, gameId, itemGameId);
//                model->setItem(row, profileId, itemProfileId);
//                model->setItem(row, icon, itemIcon);
//                model->setItem(row, title, itemTitle);
//                ++row;
//            }
//        }
//    } else {
//        int row = 0;
//        for(auto &game: hGames) {
//            QStandardItem *itemGameId = new QStandardItem(QString::number(game.id()));

//            QStandardItem *itemProfileId = new QStandardItem("");

//            QStandardItem *itemIcon = new QStandardItem();
//            itemIcon->setData(SGame::pixmapIcon(game.id(), game.iconUrl()), Qt::ItemDataRole::DecorationRole);

//            QStandardItem *itemTitle = new QStandardItem(game.name());

//            model->setItem(row, gameId, itemGameId);
//            model->setItem(row, profileId, itemProfileId);
//            model->setItem(row, icon, itemIcon);
//            model->setItem(row, title, itemTitle);
//            ++row;
//        }
//    }

//    ui->tableViewHiddenGames->resizeRowsToContents();
//    ui->tableViewHiddenGames->resizeColumnsToContents();
//    ui->tableViewHiddenGames->setColumnHidden(gameId, true);
//    ui->tableViewHiddenGames->setColumnHidden(profileId, true);
}

void FormSettings::radioButtonHiddenGames_Clicked() {
//    QRadioButtonWithData *rbSender = dynamic_cast<QRadioButtonWithData*>(sender());
//    if (rbSender) {
//        int indexHiddenGame = rbSender->getData(0).toInt();
//        auto &currentGame = hiddenGames_[indexHiddenGame];
//        ui->TableWidgetGames->clear();
//        ui->TableWidgetGames->setRowCount(currentGame.second.size());
//        if(indexHiddenGame != 0) {
//            SGames games = SGame::load(currentGame.first, true, true);
//            for(auto &game: games) {
//                if(currentGame.second.indexOf(QString::number(game.appId())) > -1) {
//                    int setTo = currentGame.second.indexOf(QString::number(game.appId()));
//                    QLabel *iconGame = new QLabel;
//                    iconGame->setBaseSize(QSize(32, 32));
//                    iconGame->setPixmap(game.pixmapIcon());
//                    ui->TableWidgetGames->setCellWidget(setTo, 0, iconGame);
//                    ui->TableWidgetGames->setItem(setTo, 1, new QTableWidgetItem(game.name()));
//                    ui->TableWidgetGames->setRowHeight(setTo, 33);

//                    QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
//                    button1->setMinimumSize(QSize(25, 25));
//                    button1->setObjectName("ButtonAchievements" + QString::number(indexHiddenGame) + "_" + QString::number(setTo));
//                    button1->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
//                    button1->addData("NumberHiddenGame", QString::number(setTo));
//                    connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
//                    ui->TableWidgetGames->setCellWidget(setTo, 2, button1);

//                    QButtonWithData *button3 = new QButtonWithData("");
//                    button3->setIcon(QIcon(Images::hide()));
//                    button3->setMinimumSize(QSize(25, 25));
//                    button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + QString::number(game.appId()));
//                    button3->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
//                    button3->addData("NumberHiddenGame", QString::number(game.appId()));
//                    connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
//                    ui->TableWidgetGames->setCellWidget(setTo, 3, button3);
//                }
//            }
//        } else {
//            //list[0]=_games[gamei].GetAppid()
//            //list[1]=_games[gamei].GetImg_icon_url()
//            //list[2]=_games[gamei].GetName()
//            for (int i = 0; i < currentGame.second.size(); ++i) {
//                QStringList list = currentGame.second[i].split("%%");
//                QString path = Paths::imagesGames(list[1]);
//                QLabel *iconGame = new QLabel;
//                iconGame->setBaseSize(QSize(32, 32));
//                ui->TableWidgetGames->setCellWidget(i, 0, iconGame);
//                if(!QFile::exists(path)) {
//                    if(list[1] != "") {
//                        new RequestImageToLabel(iconGame, Sapi::gameImageUrl(list[0].toInt(), list[1]), path, true, true, this);
//                    }
//                } else {
//                    iconGame->setPixmap(QPixmap(path));
//                }
//                ui->TableWidgetGames->setItem(i, 1, new QTableWidgetItem(list[2]));

//                ui->TableWidgetGames->setRowHeight(i, 33);
//                QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
//                button1->setMinimumSize(QSize(25, 25));
//                button1->setObjectName("ButtonAchievements" + QString::number(indexHiddenGame) + "_" + QString::number(i));
//                button1->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
//                button1->addData("NumberHiddenGame", QString::number(i));
//                connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
//                ui->TableWidgetGames->setCellWidget(i, 2, button1);

//                QButtonWithData *button3 = new QButtonWithData("");
//                button3->setIcon(QIcon(Images::hide()));
//                button3->setMinimumSize(QSize(25, 25));
//                button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + list[0]);
//                button3->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
//                button3->addData("NumberHiddenGame", list[0]);
//                connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
//                ui->TableWidgetGames->setCellWidget(i, 3, button3);
//            }
//        }
//        ui->TableWidgetGames->resizeColumnsToContents();
//    }
}

void FormSettings::comboBoxMaxTableRows(int index) {
    Q_UNUSED(index);
//    _setting.setMaximumTableRows(ui->ComboBoxMaxRows->currentText().toInt());
//    emit s_updateSettings();
}

void FormSettings::achievementsClicked() {
    auto currentIdIndex = ui->treeWidgetHiddenGames->currentIndex();
    GameID gameId = ui->treeWidgetHiddenGames->model()->data(currentIdIndex.siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toInt();
    auto parentIdIndex = currentIdIndex.parent();
    ProfileID profileId = ui->treeWidgetHiddenGames->model()->data(parentIdIndex.siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toString();
//    auto index = ui->tableViewHiddenGames->currentIndex();

    auto games = SGame::load(profileId, true, true);
    auto iterator = std::find_if(games.begin(),
                                 games.end(),
                                 [=](const SGame &lGame) {
                                    return lGame.appId() == gameId;
                                 });
    if (iterator != games.end()) {
        emit s_showAchievements(*iterator);
    }
//    auto index = ui->tableViewHiddenGames->indexAt(pos);
//    QButtonWithData *pb = dynamic_cast<QButtonWithData*>(sender());
//    if (pb) {

//    }
    //int index=pb->objectName().mid(11).toInt();

}

void FormSettings::hideClicked() {
    auto currentIdIndex = ui->treeWidgetHiddenGames->currentIndex();
    GameID gameId = ui->treeWidgetHiddenGames->model()->data(currentIdIndex.siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toInt();
    auto parentIdIndex = currentIdIndex.parent();
    ProfileID profileId = ui->treeWidgetHiddenGames->model()->data(parentIdIndex.siblingAtColumn(SettingsData::HiddenGames::Columns::id)).toString();

//    auto index = ui->tableViewHiddenGames->currentIndex();
//    ProfileID profile = model->data(index.siblingAtColumn(profileId), Qt::ItemDataRole::DisplayRole).toString();
//    GameID game = model->data(index.siblingAtColumn(gameId), Qt::ItemDataRole::DisplayRole).toString().toInt();

    QMessageBox messageBox(QMessageBox::Question, tr("Внимание!"), tr("Сделать игру видимой?"));
    QAbstractButton *btnProfile = messageBox.addButton(tr("Да"), QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"), QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton() != btnProfile) {
        return;
    }

    HiddenGames hGames(profileId);
    hGames.remove(gameId);
    hGames.save();
    delete ui->treeWidgetHiddenGames->itemFromIndex(currentIdIndex);
    if (ui->treeWidgetHiddenGames->itemFromIndex(parentIdIndex) != nullptr && ui->treeWidgetHiddenGames->itemFromIndex(parentIdIndex)->childCount() == 0){
        delete ui->treeWidgetHiddenGames->itemFromIndex(parentIdIndex);
    }
    emit s_settingsUpdated(changedSettings::hiddenGame);
//    ui->treeWidgetHiddenGames->removeItemWidget(ui->treeWidgetHiddenGames->itemFromIndex(currentIdIndex), SettingsData::HiddenGames::Columns::id);
//    ui->treeWidgetHiddenGames->removeItemWidget(ui->treeWidgetHiddenGames->itemFromIndex(currentIdIndex), SettingsData::HiddenGames::Columns::text);

//    QButtonWithData *pb = dynamic_cast<QButtonWithData*>(sender());
//    if (pb) {
//        int index = pb->getData(0).toInt();
//        int gameIndex = -1;
//        QMessageBox messageBox(QMessageBox::Question, tr("Внимание!"), tr("Сделать игру видимой?"));
//        QAbstractButton *btnProfile = messageBox.addButton(tr("Да"), QMessageBox::YesRole);
//        messageBox.addButton(tr("Отмена"), QMessageBox::NoRole);
//        messageBox.exec();
//        if(messageBox.clickedButton() != btnProfile) {
//            return;
//        }
//        for(int i = 0; i < hiddenGames_[index].second.size(); ++i) {
//            QStringList lineList = hiddenGames_[index].second[i].split("%%");
//            if(lineList[0] == pb->getData(1)) {
//                gameIndex = i;
//                break;
//            }
//        }
//        //QString save=_hiddenGames[index].first+".txt";
//        hiddenGames_[index].second.removeAt(gameIndex);
//        ui->TableWidgetGames->removeRow(gameIndex);
//        QFile fileSaveTo(Paths::hiddenGames(hiddenGames_[index].first));
//        fileSaveTo.open(QIODevice::WriteOnly | QIODevice::Text);
//        QTextStream writeStream(&fileSaveTo);
//        foreach(const QString &game, hiddenGames_[index].second) {
//            writeStream << game + "\n";
//        }
//        fileSaveTo.close();
//        QMessageBox(QMessageBox::Information, tr("Успешно!"), tr("Политика видимости для игры обновлена!"));
//    }
}

void FormSettings::checkBoxSaveImage_StateChanged(int arg1) {
    Settings::setSaveimage(arg1 == 2);
    emit s_settingsUpdated(changedSettings::saveImages);
}

void FormSettings::slideProfileSize_ValueChanged(int aValue) {
    Settings::setVisibleProfileInfo(aValue);
    emit s_settingsUpdated(changedSettings::profileInfo);
}

ExportCategory::ExportCategory() {

}

ExportCategory::ExportCategory(int aGameId, const QString &aGameName, const Category &aCategory):
gameId(aGameId), gameName(aGameName), category(aCategory) {

}

ExportCategory::ExportCategory(const QJsonObject &aObject) {
    fromJson(aObject);
}

ExportCategory::ExportCategory(const QString &aPathFile) {
    QFile file(aPathFile);
    if (file.open(QFile::ReadOnly)) {
        fromJson(QJsonDocument::fromJson(file.readAll()).object());
        file.close();
    }
}

void ExportCategory::fromJson(const QJsonObject &aObject) {
    gameId = aObject["gameId"].toInt();
    gameName = aObject["gameName"].toString();
    category = Category(aObject["category"].toObject());
}

QJsonObject ExportCategory::toJson() {
    QJsonObject jObj;
    jObj["category"] = category.toJson();
    jObj["gameName"] = gameName;
    jObj["gameId"] = gameId;
    return jObj;
}

ExportFileData ExportFileData::fromJson(QJsonObject aObject) {
    ExportFileData efd;
    efd.data = aObject["data"];
    efd.type = stringToExportType(aObject["type"].toString());
    efd.version = aObject["version"].toString().toDouble();
    efd.date = QDateTime::fromString(aObject["date"].toString(), Settings::dateTimeFormat());
    return efd;
}

QJsonObject ExportFileData::toJson() {
    QJsonObject jObject;
    jObject["data"] = data;
    jObject["type"] = exportTypeToString(type);
    jObject["version"] = QString::number(version);
    jObject["date"] = date.toString(Settings::dateTimeFormat());
    return jObject;
}

QString exportTypeToString(ExportType aType) {
    switch (aType) {
    case ExportType::unknown: {
        return "unknown";
    }
    case ExportType::categories: {
        return "categories";
    }
    case ExportType::favorites: {
        return "favorites";
    }
    case ExportType::comments: {
        return "comments";
    }
    case ExportType::groups: {
        return "groups";
    }
    case ExportType::multiple: {
        return "multiple";
    }
    }
    return "";
}

ExportType stringToExportType(QString aType) {
    if (aType == "categories") {
        return ExportType::categories;
    } else if (aType == "favorites") {
        return ExportType::favorites;
    } else if (aType == "comments") {
        return ExportType::comments;
    } else if (aType == "groups") {
        return ExportType::groups;
    }  else if (aType == "multiple") {
        return ExportType::multiple;
    } else {
        return ExportType::unknown;
    }
}
