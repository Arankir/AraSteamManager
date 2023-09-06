#include "formimportexport.h"
#include "ui_formimportexport.h"
#include "classes/common/images.h"
#include "forms/widgets/formimportitem.h"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>

namespace ExportData {
    enum Rows {
        categories = 0,
        favorites = 1,
        comments = 2,
        groups = 3,
        settings = 4
    };
    enum Columns {
        mainData = 0,
        sideData = 1,
        id = 2,
        type = 3,
        path = 4,
        profileId = 5,
        gameId = 6,
        achievementId = 7,
        subType = 8
    };
    namespace Favorite {
        enum Rows {
            games = 1,
            profiles = 2,
            achievements = 3
        };
    }
    namespace Comments {
        enum Rows {
            games = 0,
            achievements = 1
        };
    }
}

FormImportExport::FormImportExport(QWidget *aParent): Form(aParent), ui(new Ui::FormImportExport) {
    ui->setupUi(this);
    init();
}

void FormImportExport::update() {
    updateExportData();
}

void FormImportExport::init() {
    updateExportData();

    connect(ui->ButtonExport, &QPushButton::clicked, this, &FormImportExport::buttonExport_Clicked);
    connect(ui->ButtonImport, &QPushButton::clicked, this, [this]() {
        showImportTable(getFileFromPath(""));
    });
}

FormImportExport::~FormImportExport() {
    delete ui;
}

void FormImportExport::retranslate() {
    ui->retranslateUi(this);
    updateExportData();
}

void FormImportExport::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormImportExport::updateIcons() {

}

void FormImportExport::resizeEvent(QResizeEvent* aEvent) {
   Form::resizeEvent(aEvent);
}

QList<ImportExportData*> FormImportExport::getFileFromPath(const QString &aPath) {
    QString path;
    if (aPath == "") {
        path = QFileDialog::getOpenFileName(this, tr("Выбор файла для загрузки"), "", "*.sas;; *.*");
        if (path == "") {
            return QList<ImportExportData*>();
        }
    } else {
        path = aPath;
    }
    ImportExportFile file(path);
    if (file.load(path)) {
        return file.datas;
    }
    QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно найти указанный файл, или файл открыт в другом приложении!"));
    return QList<ImportExportData*>();
}

#define ExportFunc {
QList<QVariant> stringListToVariantList(const QStringList &aList) {
    QList<QVariant> variantPath;
    for (const QString &category: aList) {
        variantPath << QVariant(category);
    }
    return variantPath;
}

QStringList variantListToStringList(const QList<QVariant> &aList) {
    QStringList path;
    for (QVariant vTitle: aList) {
        path << vTitle.toString();
    }
    return path;
}

QTreeWidgetItem *treeItem(const QString &aTitle = "", QTreeWidgetItem *aRoot = nullptr) {
    QTreeWidgetItem *item = new QTreeWidgetItem(aRoot);
    item->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, aTitle);
    item->setFlags(Qt::ItemFlags (item->flags() | Qt::ItemFlag::ItemIsUserCheckable));
    item->setCheckState(ExportData::Columns::mainData, Qt::CheckState::Unchecked);
    return item;
}

#define ExportTree {
QTreeWidgetItem *recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot, const QString &aMain, const QString &aId, const QString &aSide, const QVariant &aPath) {
    QTreeWidgetItem *itemGame = treeItem("", aRoot);
    itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::DisplayRole, aMain);
    itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::ToolTipRole, aMain);
    itemGame->setData(ExportData::Columns::gameId,      Qt::ItemDataRole::DisplayRole, aId);
    itemGame->setData(ExportData::Columns::sideData,    Qt::ItemDataRole::DisplayRole, aSide);
    itemGame->setData(ExportData::Columns::path,        Qt::ItemDataRole::DisplayRole, aPath);
    itemGame->setData(ExportData::Columns::type,        Qt::ItemDataRole::DisplayRole, ExportData::Rows::categories);
    for (Category *category: aCategory->categories()) {
        recursAddCategoryToTree(category, itemGame,
                                category->title(),
                                QString::number(category->gameID()),
                                category->gameName(),
                                QVariant(stringListToVariantList(category->getPathFromRoot())));
    }
    return itemGame;
}

QTreeWidgetItem *exportCategories() {
    QTreeWidgetItem *itemTop = treeItem(QObject::tr("Категории"));
    itemTop->setData(ExportData::Columns::type, Qt::ItemDataRole::DisplayRole, ExportData::Rows::categories);

    QDir dir(Paths::categories());
    for (const QFileInfo &file: dir.entryInfoList(QDir::Files)) {
        QFile fileCategory(file.filePath());
        if (fileCategory.exists()) {
            if(fileCategory.open(QFile::ReadOnly)) {
                Category categories(QJsonDocument().fromJson(fileCategory.readAll()).object());
                categories.update();
                auto item = recursAddCategoryToTree(&categories, itemTop, categories.gameName(), QString::number(categories.gameID()), "", QVariant(stringListToVariantList(categories.getPathFromRoot())));
                item->setData(0, Qt::ItemDataRole::DecorationRole, QPixmap::fromImage(loadImage(Sapi::gameImageUrl(categories.gameID(), categories.gameIcon()), Paths::imagesGames(categories.gameIcon()), QSize(32, 32))));
                fileCategory.close();
            }
        }
    }
    return itemTop;
}

QTreeWidgetItem *exportFavoriteGames() {
    QTreeWidgetItem *item = treeItem(QObject::tr("Игры"));
    item->setData(ExportData::Columns::type,    Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
    item->setData(ExportData::Columns::subType, Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::games);

    FavoriteGames games;
    QStringList profilesIdList;
    for (const FavoriteGame &profile: games) {
        profilesIdList << profile.steamId();
    }
    profilesIdList.removeDuplicates();

    SProfiles profiles = SProfile::load(profilesIdList);
    QMap<ProfileID, QList<FavoriteGame>> profilesFavorite;
    for (const FavoriteGame &achievementsGame: games) {
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
            QTreeWidgetItem *itemProfile = treeItem("", item);
            itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorProfiles->personaName());
            itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorProfiles->pixmapAvatar());
            itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorProfiles->personaName());
            itemProfile->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole, iteratorProfiles->steamId());
            itemProfile->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
            itemProfile->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::games);
            for (const FavoriteGame &game: iterator.value()) {
                QTreeWidgetItem *itemGame = treeItem("", itemProfile);
                itemGame->setText(ExportData::Columns::mainData,    game.name());
                itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::DecorationRole, SGame::pixmapIcon(game.appId(), game.icon()));
                itemGame->setData(ExportData::Columns::profileId,   Qt::ItemDataRole::DisplayRole, iteratorProfiles->steamId());
                itemGame->setData(ExportData::Columns::gameId,      Qt::ItemDataRole::DisplayRole, QString::number(game.appId()));
                itemGame->setData(ExportData::Columns::type,        Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
                itemGame->setData(ExportData::Columns::subType,     Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::games);
            }
        }
    }

    return item;
}

QTreeWidgetItem *exportFavoriteProfiles() {
    QTreeWidgetItem *item = treeItem(QObject::tr("Профили"));
    item->setData(ExportData::Columns::type,    Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
    item->setData(ExportData::Columns::subType, Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::profiles);

    FavoriteProfiles fProfiles;
    QStringList profilesId;
    for (const FavoriteProfile &profile: fProfiles) {
        profilesId << profile.profileId();
    }

    SProfiles profiles = SProfile::load(profilesId);
    for (auto iterator = profiles.begin(); iterator != profiles.end(); ++iterator) {
        QTreeWidgetItem *itemProfile = treeItem("", item);
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, iterator->personaName());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole, iterator->pixmapAvatar());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iterator->personaName());
        itemProfile->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole, iterator->steamId());
        itemProfile->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
        itemProfile->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::profiles);
    }
    return item;
}

QTreeWidgetItem *exportFavoriteAchievements() {
    QTreeWidgetItem *item = treeItem(QObject::tr("Достижения"));
    item->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
    item->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::achievements);

    FavoriteAchievements fAchievements;
    SProfiles profiles = SProfile::load(fAchievements.profiles());
    for (const auto &profile: profiles) {
        QTreeWidgetItem *itemProfile = treeItem("", item);
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole,      profile.personaName());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole,   profile.pixmapAvatar());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole,      profile.personaName());
        itemProfile->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole,      profile.steamId());
        itemProfile->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole,      ExportData::Rows::favorites);
        itemProfile->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole,      ExportData::Favorite::Rows::achievements);
        auto games = fAchievements.games(profile.steamId());
        for (const auto &game: games) {
            QTreeWidgetItem *itemGame = treeItem("", itemProfile);
            itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::DisplayRole, game.name);
            itemGame->setData(ExportData::Columns::profileId,   Qt::ItemDataRole::DisplayRole, profile.steamId());
            itemGame->setData(ExportData::Columns::gameId,      Qt::ItemDataRole::DisplayRole, QString::number(game.appId));
            itemGame->setData(ExportData::Columns::type,        Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
            itemGame->setData(ExportData::Columns::subType,     Qt::ItemDataRole::DisplayRole, ExportData::Favorite::Rows::achievements);
            auto achievements = fAchievements.achievements(profile.steamId(), game);
            for (const FavoriteAchievement &achievement: achievements) {
                QTreeWidgetItem *itemAchievement = treeItem("", itemGame);
                itemAchievement->setData(ExportData::Columns::mainData,         Qt::ItemDataRole::DecorationRole,   SAchievementSchema::icon(game.appId, achievement.icon()));
                itemAchievement->setData(ExportData::Columns::mainData,         Qt::ItemDataRole::DisplayRole,      achievement.title());
                itemAchievement->setData(ExportData::Columns::profileId,        Qt::ItemDataRole::DisplayRole,      profile.steamId());
                itemAchievement->setData(ExportData::Columns::gameId,           Qt::ItemDataRole::DisplayRole,      QString::number(game.appId));
                itemAchievement->setData(ExportData::Columns::achievementId,    Qt::ItemDataRole::DisplayRole,      achievement.apiName());
                itemAchievement->setData(ExportData::Columns::type,             Qt::ItemDataRole::DisplayRole,      ExportData::Rows::favorites);
                itemAchievement->setData(ExportData::Columns::subType,          Qt::ItemDataRole::DisplayRole,      ExportData::Favorite::Rows::achievements);
            }
        }
    }
    return item;
}

QTreeWidgetItem *exportCommentsGames() {
    QTreeWidgetItem *item = treeItem(QObject::tr("Игры"));
    item->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
    item->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Comments::Rows::games);

    QDir dir(Paths::commentsGames());
    for (const QFileInfo &file: dir.entryInfoList(QDir::Files)) {
        QString profileId = file.fileName();
        profileId = profileId.left(profileId.lastIndexOf("."));
        GameComments comments(profileId);
        SProfile profile = SProfile::load(profileId);
        SGames games = SGame::load(profileId, true, true);

        QTreeWidgetItem *itemProfile = treeItem("", item);
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, profile.personaName());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole, profile.personaName());
        itemProfile->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole, profile.steamId());
        itemProfile->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
        itemProfile->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Comments::Rows::games);
        for (const GameComment &comment: comments) {
            auto iteratorGame = std::find_if(games.begin(),
                                             games.end(),
                                             [=](const SGame &lGame) {
                                                return lGame.appId() == comment.gameId();
                                             });
            if (iteratorGame != games.end()) {
                QTreeWidgetItem *itemGame = treeItem("", itemProfile);
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, iteratorGame->name());
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole, iteratorGame->pixmapIcon());
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole, iteratorGame->name());
                itemGame->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole, profile.steamId());
                itemGame->setData(ExportData::Columns::gameId,   Qt::ItemDataRole::DisplayRole, comment.gameId());
                itemGame->setData(ExportData::Columns::sideData, Qt::ItemDataRole::DisplayRole, comment.comment().join("\n"));
                itemGame->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
                itemGame->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Comments::Rows::games);
            }
        }
    }
    return item;
}

QTreeWidgetItem *exportCommentsAchievements() {
    QTreeWidgetItem *item = treeItem(QObject::tr("Достижения"));
    item->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
    item->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Comments::Rows::achievements);

    QDir dir(Paths::commentsAchievements());
    for (const QFileInfo &file: dir.entryInfoList(QDir::Files)) {
        QString profileId = file.fileName();
        profileId = profileId.left(profileId.lastIndexOf("."));
        AchievementComments comments(profileId);
        SProfile profile = SProfile::load(profileId);
        SGames games = SGame::load(profileId, true, true);

        QMap<GameID, QList<AchievementComment> > gamesComments;
        for (const AchievementComment &achievementsGame: comments) {
            if (gamesComments.find(achievementsGame.gameId()) == gamesComments.end()) {
                gamesComments.insert(achievementsGame.gameId(), QList<AchievementComment>());
            }
            auto iterator = gamesComments.find(achievementsGame.gameId());
            if (iterator != gamesComments.end()) {
                iterator.value().append(achievementsGame);
            }
        }

        QTreeWidgetItem *itemProfile = treeItem("", item);
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole, profile.personaName());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
        itemProfile->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole, profile.personaName());
        itemProfile->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole, profile.steamId());
        itemProfile->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
        itemProfile->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole, ExportData::Comments::Rows::achievements);

        for (auto iterator = gamesComments.begin(); iterator != gamesComments.end(); ++iterator) {
            auto iteratorGame = std::find_if(games.begin(),
                                             games.end(),
                                             [=](const SGame &lGame) {
                                                return lGame.appId() == iterator.key();
                                             });
            if (iteratorGame != games.end()) {
                QTreeWidgetItem *itemGame = treeItem("", itemProfile);
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DisplayRole,     iteratorGame->name());
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::DecorationRole,  iteratorGame->pixmapIcon());
                itemGame->setData(ExportData::Columns::mainData, Qt::ItemDataRole::ToolTipRole,     iteratorGame->name());
                itemGame->setData(ExportData::Columns::profileId,Qt::ItemDataRole::DisplayRole,     profile.steamId());
                itemGame->setData(ExportData::Columns::gameId,   Qt::ItemDataRole::DisplayRole,     iterator.key());
                itemGame->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole,     ExportData::Rows::comments);
                itemGame->setData(ExportData::Columns::subType,  Qt::ItemDataRole::DisplayRole,     ExportData::Comments::Rows::achievements);
                for (const AchievementComment &comment: iterator.value()) {
                    QTreeWidgetItem *itemAchievement = treeItem("", itemGame);
                    itemAchievement->setData(ExportData::Columns::mainData,         Qt::ItemDataRole::DisplayRole,      comment.title());
                    itemAchievement->setData(ExportData::Columns::mainData,         Qt::ItemDataRole::DecorationRole,   SAchievementSchema::icon(iteratorGame->appId(), comment.icon()));
                    itemAchievement->setData(ExportData::Columns::mainData,         Qt::ItemDataRole::ToolTipRole,      comment.title());
                    itemAchievement->setData(ExportData::Columns::profileId,        Qt::ItemDataRole::DisplayRole,      profile.steamId());
                    itemAchievement->setData(ExportData::Columns::gameId,           Qt::ItemDataRole::DisplayRole,      iterator.key());
                    itemAchievement->setData(ExportData::Columns::achievementId,    Qt::ItemDataRole::DisplayRole,      comment.achievementId());
                    itemAchievement->setData(ExportData::Columns::sideData,         Qt::ItemDataRole::DisplayRole,      comment.comment().join("\n"));
                    itemAchievement->setData(ExportData::Columns::type,             Qt::ItemDataRole::DisplayRole,      ExportData::Rows::comments);
                    itemAchievement->setData(ExportData::Columns::subType,          Qt::ItemDataRole::DisplayRole,      ExportData::Comments::Rows::achievements);
                }
            }
        }
    }
    return item;
}

QTreeWidgetItem *exportGroups() {
    QTreeWidgetItem *itemTop = treeItem(QObject::tr("Группы"));
    itemTop->setData(ExportData::Columns::type,     Qt::ItemDataRole::DisplayRole, ExportData::Rows::groups);

    QDir dir(Paths::groupGames());
    for (const QFileInfo &file: dir.entryInfoList(QDir::Files)) {
        QString profileId = file.fileName();
        profileId = profileId.left(profileId.lastIndexOf("."));

        GroupsGames groups(profileId);
        SProfile profile = SProfile::load(profileId);

        for (const GroupGames &group: groups) {
            QTreeWidgetItem *itemGame = treeItem("", itemTop);
            itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::DecorationRole,   profile.pixmapAvatar());
            itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::DisplayRole,      QObject::tr("%1 (%2)").arg(group.title(), profile.personaName()));
            itemGame->setData(ExportData::Columns::mainData,    Qt::ItemDataRole::ToolTipRole,      group.title());
            itemGame->setData(ExportData::Columns::id,          Qt::ItemDataRole::DisplayRole,      group.title());
            itemGame->setData(ExportData::Columns::profileId,   Qt::ItemDataRole::DisplayRole,      profile.steamId());
            itemGame->setData(ExportData::Columns::type,        Qt::ItemDataRole::DisplayRole,      ExportData::Rows::groups);
        }
    }
    return itemTop;
}
#define ExportTreeEnd }

void FormImportExport::updateExportData() {
    ui->treeWidgetExport->clear();

    //Категории
    QTreeWidgetItem *itemCategories = exportCategories();
    ui->treeWidgetExport->addTopLevelItem(itemCategories);

    //Избранное
    QTreeWidgetItem *itemFavorites = treeItem(tr("Избранное"));
    itemFavorites->setData(ExportData::Columns::type, Qt::ItemDataRole::DisplayRole, ExportData::Rows::favorites);
    itemFavorites->addChild(exportFavoriteGames());
    itemFavorites->addChild(exportFavoriteProfiles());
    itemFavorites->addChild(exportFavoriteAchievements());
    ui->treeWidgetExport->addTopLevelItem(itemFavorites);

    //Комментарии
    QTreeWidgetItem *itemComments = treeItem(tr("Комментарии"));
    itemComments->setData(ExportData::Columns::type, Qt::ItemDataRole::DisplayRole, ExportData::Rows::comments);
    itemComments->addChild(exportCommentsGames());
    itemComments->addChild(exportCommentsAchievements());
    ui->treeWidgetExport->addTopLevelItem(itemComments);

    //Группы
    QTreeWidgetItem *itemGroups = exportGroups();
    ui->treeWidgetExport->addTopLevelItem(itemGroups);

    QTreeWidgetItem *itemSettings = treeItem(tr("Настройки"));
    itemSettings->setData(ExportData::Columns::type, Qt::ItemDataRole::DisplayRole, ExportData::Rows::settings);

    ui->treeWidgetExport->expandAll();
    ui->treeWidgetExport->resizeColumnToContents(ExportData::Columns::mainData);
    ui->treeWidgetExport->setColumnCount(1);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::id,              true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::sideData,        true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::type,            true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::path,            true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::profileId,       true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::gameId,          true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::achievementId,   true);
    ui->treeWidgetExport->setColumnHidden(ExportData::Columns::subType,         true);
    ui->treeWidgetExport->collapseAll();
}

#define ExportTreeToData {
QList<ImportExportData*> checkAllChilds(QTreeWidgetItem *aItem);
QList<ImportExportData*> ieCategory(QTreeWidgetItem *aItem) {
    GameID gameId    =                          aItem->data(ExportData::Columns::gameId,      Qt::ItemDataRole::DisplayRole).toString().toInt();
    QString gameIcon =                          aItem->data(ExportData::Columns::mainData,    Qt::ItemDataRole::DecorationRole).toString();
    QString gameName =                          aItem->data(ExportData::Columns::sideData,    Qt::ItemDataRole::DisplayRole).toString();
    QString title    =                          aItem->data(ExportData::Columns::mainData,    Qt::ItemDataRole::DisplayRole).toString();
    QStringList path = variantListToStringList( aItem->data(ExportData::Columns::path,        Qt::ItemDataRole::DisplayRole).toList());
    Category categories(gameId, gameName, gameIcon);
    categories.update();
    if (path == categories.getPathFromRoot() && gameName.isEmpty()) {
        return checkAllChilds(aItem);
    } else {
        Category *category = categories.find(path);
        IECategory *ieCategory = new IECategory(gameId, gameIcon, gameName, *category);
        return QList<ImportExportData*>{ieCategory};
    }
    return QList<ImportExportData*>();
}

QList<ImportExportData*> ieFavorite(QTreeWidgetItem *aItem) {
    int favoriteType =              aItem->data(ExportData::Columns::subType,       Qt::ItemDataRole::DisplayRole).toInt();
    ProfileID profileId =           aItem->data(ExportData::Columns::profileId,     Qt::ItemDataRole::DisplayRole).toString();
    GameID gameId =                 aItem->data(ExportData::Columns::gameId,        Qt::ItemDataRole::DisplayRole).toString().toInt();
    AchievementID achievementId =   aItem->data(ExportData::Columns::achievementId, Qt::ItemDataRole::DisplayRole).toString();

    switch (favoriteType) {
    case 0: {
        return checkAllChilds(aItem);
    }
    case ExportData::Favorite::Rows::games: {
        if (profileId.isEmpty() || gameId == 0) {
            return checkAllChilds(aItem);
        } else {
            FavoriteGames games;
            auto it = std::find_if(games.begin(),
                                   games.end(),
                                   [&gameId, &profileId](const FavoriteGame &lFavorite) {
                                        return lFavorite.appId() == gameId && lFavorite.steamId() == profileId;
                                    });
            if (it != games.end()) {
                IEFavoriteGame *ieFavorite = new IEFavoriteGame((*it));
                return QList<ImportExportData*>{ieFavorite};
            }
        }
        break;
    }
    case ExportData::Favorite::Rows::profiles: {
        if (profileId.isEmpty()) {
            return checkAllChilds(aItem);
        } else {
            FavoriteProfiles profiles;
            auto it = std::find_if(profiles.begin(),
                                   profiles.end(),
                                   [&profileId](const FavoriteProfile &lFavorite) {
                                        return lFavorite.profileId() == profileId;
                                    });
            if (it != profiles.end()) {
                IEFavoriteProfile *ieFavorite = new IEFavoriteProfile((*it));
                return QList<ImportExportData*>{ieFavorite};
            }
        }
        break;
    }
    case ExportData::Favorite::Rows::achievements: {
        if (profileId.isEmpty() || gameId == 0 || achievementId.isEmpty()) {
            return checkAllChilds(aItem);
        } else {
            FavoriteAchievements achievements;
            auto games = achievements.games(profileId);
            auto it = std::find_if(games.begin(),
                                   games.end(),
                                   [&gameId](const FavoriteAchievement::Game &lGame) {
                                        return lGame.appId == gameId;
                                   });
            if (it != games.end()) {
                auto favorites = achievements.achievements(profileId, *it);
                auto it2 = std::find_if(favorites.begin(),
                                        favorites.end(),
                                        [&achievementId](const FavoriteAchievement &lAchievement) {
                                            return lAchievement.apiName() == achievementId;
                                        });
                if (it2 != favorites.end()) {
                    IEFavoriteAchievement *ieFavorite = new IEFavoriteAchievement((*it2));
                    return QList<ImportExportData*>{ieFavorite};
                }
            }
        }
        break;
    }
    default: {
        return checkAllChilds(aItem);
    }
    }
    return QList<ImportExportData*>();
}

QList<ImportExportData*> ieComment(QTreeWidgetItem *aItem) {
    int commentType =               aItem->data(ExportData::Columns::subType,       Qt::ItemDataRole::DisplayRole).toInt();
    ProfileID profileId =           aItem->data(ExportData::Columns::profileId,     Qt::ItemDataRole::DisplayRole).toString();
    GameID gameId =                 aItem->data(ExportData::Columns::gameId,        Qt::ItemDataRole::DisplayRole).toString().toInt();
    AchievementID achievementId =   aItem->data(ExportData::Columns::achievementId, Qt::ItemDataRole::DisplayRole).toString();
    switch (commentType) {
    case ExportData::Comments::Rows::games: {
        if (gameId == 0) {
            return checkAllChilds(aItem);
        } else {
            GameComments comments(profileId);
            auto it = std::find_if(comments.begin(),
                                   comments.end(),
                                   [&gameId](const GameComment &lComment) {
                                        return lComment.gameId() == gameId;
                                    });
            if (it != comments.end()) {
                IECommentGame *ieComment = new IECommentGame((*it));
                return QList<ImportExportData*>{ieComment};
            }
        }
        break;
    }
    case ExportData::Comments::Rows::achievements: {
        if (achievementId.isEmpty()) {
            return checkAllChilds(aItem);
        } else {
            AchievementComments comments(profileId);
            auto it = std::find_if(comments.begin(),
                                   comments.end(),
                                   [&gameId, &achievementId](const AchievementComment &lComment) {
                                        return lComment.gameId() == gameId && lComment.achievementId() == achievementId;
                                    });
            if (it != comments.end()) {
                IECommentAchievement *ieComment = new IECommentAchievement((*it));
                return QList<ImportExportData*>{ieComment};
            }
        }
        break;
    }
    }
    return QList<ImportExportData*>();
}

QList<ImportExportData*> ieGroup(QTreeWidgetItem *aItem) {
    QString groupTitle  = aItem->data(ExportData::Columns::id,          Qt::ItemDataRole::DisplayRole).toString();
    ProfileID profileId = aItem->data(ExportData::Columns::profileId,   Qt::ItemDataRole::DisplayRole).toString();
    if (!groupTitle.isEmpty() && !profileId.isEmpty()) {
        GroupsGames groups(profileId);
        auto it = std::find_if(groups.begin(),
                               groups.end(),
                               [&groupTitle](const GroupGames &lGroup) {
                                    return lGroup.title() == groupTitle;
                                });
        if (it != groups.end()) {
            IEGroup *group = new IEGroup((*it));
            return QList<ImportExportData*>{group};
        }
    } else {
        return checkAllChilds(aItem);
    }
    return QList<ImportExportData*>();
}

QList<ImportExportData*> ieSettings(QTreeWidgetItem *aItem) {
    Q_UNUSED(aItem);

    IESettings *settings = new IESettings();
    settings->addSetting(IESettings::Setting{"myProfile",       typeid(Settings::myProfile()).name(),       Settings::myProfile()});
    settings->addSetting(IESettings::Setting{"language",        typeid(Settings::language()).name(),        Settings::language()});
    settings->addSetting(IESettings::Setting{"theme",           typeid(Settings::theme()).name(),           Settings::theme()});
    settings->addSetting(IESettings::Setting{"profileInfoSize", typeid(Settings::profileInfoSize()).name(), Settings::profileInfoSize()});
    settings->addSetting(IESettings::Setting{"timeFormat",      typeid(Settings::timeFormat()).name(),      Settings::timeFormat()});
    settings->addSetting(IESettings::Setting{"dateFormat",      typeid(Settings::dateFormat()).name(),      Settings::dateFormat()});
    settings->addSetting(IESettings::Setting{"timeShortFormat", typeid(Settings::timeShortFormat()).name(), Settings::timeShortFormat()});

    return QList<ImportExportData*>{settings};
}

QList<ImportExportData*> itemToIEData(QTreeWidgetItem *aItem) {
    if (aItem == nullptr) {
        return QList<ImportExportData*>();
    }
    switch(aItem->data(ExportData::Columns::type, Qt::ItemDataRole::DisplayRole).toInt()) {
        case ExportData::Rows::categories: {
            return ieCategory(aItem);
        }
        case ExportData::Rows::favorites: {
            return ieFavorite(aItem);
        }
        case ExportData::Rows::comments: {
            return ieComment(aItem);
        }
        case ExportData::Rows::groups: {
            return ieGroup(aItem);
        }
        case ExportData::Rows::settings: {
            return ieSettings(aItem);
        }
    }
    return QList<ImportExportData*>();
}

QList<ImportExportData*> checkAllChilds(QTreeWidgetItem *aItem) {
    QList<ImportExportData*> datas;
    for (int i = 0; i < aItem->childCount(); ++i) {
        datas << itemToIEData(aItem->child(i));
    }
    return datas;
}

QList<ImportExportData*> checkItem(QTreeWidgetItem *aItem) {
    if (aItem == nullptr) {
        return QList<ImportExportData*>();
    }
    QList<ImportExportData*> list;
    QJsonArray array;
    if (aItem->checkState(0) == Qt::CheckState::Checked) {
        list << itemToIEData(aItem);
    }
    for(int i = 0; i < aItem->childCount(); ++i) {
        list << checkItem(aItem->child(i));
    }
    return list;
}
#define ExportTreeToDataEnd }

void FormImportExport::buttonExport_Clicked() {
    QString sFile = QFileDialog::getSaveFileName(this, tr("Место сохранения"), "", "*.sas");
    if (sFile == "") {
        return;
    }

    QList<ImportExportData*> dats;

    for(int i = 0; i < ui->treeWidgetExport->topLevelItemCount(); ++i) {
        dats << checkItem(ui->treeWidgetExport->topLevelItem(i));
    }

    ImportExportFile file(sFile);
    file.datas = dats;

    if (file.save()) {
        QMessageBox::information(this, tr("Успешно!"), tr("Файл успешно создан!"));
    } else {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Произошла неизвестная ошибка при создании файла!"));
    }
}
#define ExportFuncEnd }

#define ImportFunc {
bool importIEData(QList<ImportExportData*> aIEDatas) {
    bool isExported = true;
    for (auto ieData: aIEDatas) {
        if (ieData->isExist()) {
            QMessageBox deleteQuestion(QMessageBox::Question, QObject::tr("Внимание!"), ieData->existError());
            QAbstractButton *btnYes = deleteQuestion.addButton(QObject::tr("Да"), QMessageBox::YesRole);
            deleteQuestion.addButton(QObject::tr("Отмена"), QMessageBox::NoRole);
            deleteQuestion.exec();
            if (deleteQuestion.clickedButton() != btnYes) {
                continue;
            }
        }
        ieData->import();
    }
    return isExported;
}

void FormImportExport::showImportTable(QList<ImportExportData*> aFileData) {
    if (aFileData.count() == 0) {
        return;
    }

    QListWidget *listWidget = new QListWidget(this);
    listWidget->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
    for (auto item: aFileData) {
        QListWidgetItem *li = new QListWidgetItem();
        FormImportItem *importItem = new FormImportItem(item);
        listWidget->addItem(li);
        listWidget->setItemWidget(li, importItem);
        li->setSizeHint(QSize(importItem->sizeHint().width(), importItem->sizeHint().height() + 10));
    }

    SubForm *form = new SubForm(listWidget, this);

    QPushButton *buttonClose = new QPushButton(QIcon(Images::apply()), "", form);
    buttonClose->setMinimumSize(QSize(24, 24));
    form->addWidget(buttonClose, FramelessWindow::Edge::TopRight);

    connect(buttonClose, &QPushButton::clicked, this, [this, listWidget, form]() {
        QList<ImportExportData*> datas;
        for (int i = 0; i < listWidget->count(); ++i) {
            if (auto item = dynamic_cast<FormImportItem*>(listWidget->itemWidget(listWidget->item(i)))) {
                if (item->isChecked()) {
                    if (item->isNeedProfile() && !item->isProfileSelected()) {
                        QMessageBox::warning(this, tr("Ошибка!"), tr("Выберите профили для импортируемых данных!"));
                        return;
                    }
                    datas << item->importData();
                }
            }
        }
        if (!importIEData(datas)) {
            QMessageBox::warning(this, tr("Ошибка!"), tr("Некоторые данные не были импортированны!"));
        }
        form->close();
        form->deleteLater();
    });
    form->show();

}
#define ImportFuncEnd }
