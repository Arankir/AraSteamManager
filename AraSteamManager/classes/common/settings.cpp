#include "settings.h"
#include <QDir>
#include <QApplication>
#include <QStandardPaths>

//Q_LOGGING_CATEGORY(logFunc,     "Function")

struct settings {
    const QString language              = "Settings/Language";
    const QString theme                 = "Settings/Theme";
    const QString saveImage             = "Settings/SaveImages";
    const QString myProfile             = "Settings/MyProfile";
    const QString visibleHiddenGames    = "Settings/VisibleHiddenGames";
    const QString profileInfoSize       = "Settings/VisibleProfileInfo";
    //const QString maxTableRows = "Settings/MaxTableRows";
};

struct mainWindow {
    const QString Height        = "MainWindow/Height";
    const QString Width         = "MainWindow/Width";
    const QString X             = "MainWindow/X";
    const QString Y             = "MainWindow/Y";
    const QString isMaximize    = "MainWindow/Maximize";
};

struct achievementContainer {
    const QString Height    = "AchievementContainer/Height";
    const QString Width     = "AchievementContainer/Width";
    const QString X         = "AchievementContainer/X";
    const QString Y         = "AchievementContainer/Y";
    const QString Maximize  = "AchievementContainer/Maximize";
    struct achievements {
        struct table {
            const QString icon          = "AchievementContainer/Achievements/Table/Icon";
            const QString title         = "AchievementContainer/Achievements/Table/Title";
            const QString description   = "AchievementContainer/Achievements/Table/Description";
            const QString comment       = "AchievementContainer/Achievements/Table/Comment";
            const QString percent       = "AchievementContainer/Achievements/Table/Percent";
            const QString isAchieved    = "AchievementContainer/Achievements/Table/IsAchieved";
        };
        table table;
    };
    achievements achievements;
    struct achievementsCompare {
        const QString isIconVisible         = "AchievementContainer/AchievementsCompare/IsIconVisible";
        const QString isTitleVisible        = "AchievementContainer/AchievementsCompare/IsTitleVisible";
        const QString isDescriptionVisible  = "AchievementContainer/AchievementsCompare/IsDescriptionVisible";
        const QString isPercentVisible      = "AchievementContainer/AchievementsCompare/IsPercentVisible";
    };
    achievementsCompare achievementsCompare;
};

struct games {
    struct table {
        const QString icon      = "Games/Table/Icon";
        const QString title     = "Games/Table/Title";
        const QString comment   = "Games/Table/Comment";
        const QString progress  = "Games/Table/Progress";
    };
    table table;
};

struct friends {
    struct table {
        const QString icon          = "Friends/Table/Icon";
        const QString name          = "Friends/Table/Name";
        const QString dateAdded     = "Friends/Table/DateAdded";
        const QString status        = "Friends/Table/Status";
        const QString isOpenProfile = "Friends/Table/IsOpenProfile";
    };
    table table;
};

const QString    Settings::c_organizationName             = "Arankir";
const QString    Settings::c_organizationDomain           = "Arankir";
const QString    Settings::c_applicationName              = "SteamAchievementsStatistic";

QSettings *      Settings::settings_                      = new QSettings(c_organizationName, c_applicationName);

#define SettingsStart {
void Settings::setMyProfile(const QString &aMyProfiles) {
    return settings_->setValue(settings().myProfile, aMyProfiles);
}

void Settings::setLanguage(const int &aLanguage) {
    return settings_->setValue(settings().language, aLanguage);
}

void Settings::setTheme(const int &aTheme) {
    return settings_->setValue(settings().theme, aTheme);
}

void Settings::setSaveimage(const int &aSaveImage) {
    return settings_->setValue(settings().saveImage, aSaveImage);
}

void Settings::setVisibleHiddenGames(const int &aVisibleHiddenGames) {
    return settings_->setValue(settings().visibleHiddenGames, aVisibleHiddenGames);
}

void Settings::setVisibleProfileInfo(const int &aVisibleProfileInfo) {
    return settings_->setValue(settings().profileInfoSize, aVisibleProfileInfo);
}

void Settings::setMainWindowParams(QRect aGeometry) {
    settings_->setValue(mainWindow().Height, aGeometry.height());
    settings_->setValue(mainWindow().Width, aGeometry.width());
    settings_->setValue(mainWindow().X, aGeometry.x());
    settings_->setValue(mainWindow().Y, aGeometry.y());
}

void Settings::setMainWindowPos(const QPoint &aPos) {
    settings_->setValue(mainWindow().X, aPos.x());
    settings_->setValue(mainWindow().Y, aPos.y());
}

void Settings::setMainWindowIsMaximize(bool aMaximize) {
    settings_->setValue(mainWindow().isMaximize, aMaximize);
}

void Settings::setAchievementContainerParams(QRect aGeometry){
    settings_->setValue(achievementContainer().Height, aGeometry.height());
    settings_->setValue(achievementContainer().Width, aGeometry.width());
    settings_->setValue(achievementContainer().X, aGeometry.x());
    settings_->setValue(achievementContainer().Y, aGeometry.y());
}

QString Settings::myProfile() {
    return settings_->value(settings().myProfile, "").toString();
}

int Settings::language() {
    return settings_->value(settings().language, 1).toInt();
}

int Settings::theme() {
    return settings_->value(settings().theme, 1).toInt();
}

int Settings::saveImages() {
    return settings_->value(settings().saveImage, 1).toInt();
}

int Settings::visibleHiddenGames() {
    return settings_->value(settings().visibleHiddenGames, 0).toInt();
}

int Settings::profileInfoSize() {
    return settings_->value(settings().profileInfoSize, 2).toInt();
}

const QString Settings::dateTimeFormat() {
    return dateFormat() + " hh:mm:ss";
}

const QString Settings::dateTimeFormatShort() {
    return dateFormat() + " hh:mm";
}

const QString Settings::dateFormat() {
//TODO сделать настраиваемым
    return "yyyy.MM.dd";
}

QRect Settings::mainWindowGeometry() {
    return (QRect(0, 0, settings_->value(mainWindow().Width, 623).toInt(), settings_->value(mainWindow().Height, 479).toInt()));
}

QPoint Settings::mainWindowPos() {
    return (QPoint(settings_->value(mainWindow().X, 100).toInt(), settings_->value(mainWindow().Y, 100).toInt()));
}

bool Settings::isMainWindowMaximize() {
    return settings_->value(mainWindow().isMaximize, false).toBool();
}

void Settings::setGamesTableIconWidth(const int &width) {
    settings_->setValue(games().table.icon, width);
}

int Settings::gamesTableIconWidth() {
    return settings_->value(games().table.icon, 50).toInt();
}

void Settings::setGamesTableTitleWidth(const int &width) {
    settings_->setValue(games().table.title, width);
}

int Settings::gamesTableTitleWidth() {
    return settings_->value(games().table.title, 400).toInt();
}

void Settings::setGamesTableCommentWidth(const int &width) {
    settings_->setValue(games().table.comment, width);
}

int Settings::gamesTableCommentWidth() {
    return settings_->value(games().table.comment, 50).toInt();
}

void Settings::setGamesTableProgressWidth(const int &width) {
    settings_->setValue(games().table.progress, width);
}

int Settings::gamesTableProgressWidth() {
    return settings_->value(games().table.progress, 100).toInt();
}

void Settings::setFriendsTableIconWidth(const int &width) {
    settings_->setValue(friends().table.icon, width);
}

int Settings::friendsTableIconWidth() {
    return settings_->value(friends().table.icon, 50).toInt();
}

void Settings::setFriendsTableNameWidth(const int &width) {
    settings_->setValue(friends().table.name, width);
}

int Settings::friendsTableNameWidth() {
    return settings_->value(friends().table.name, 400).toInt();
}

void Settings::setFriendsTableAddedWidth(const int &width) {
    settings_->setValue(friends().table.dateAdded, width);
}

int Settings::friendsTableAddedWidth() {
    return settings_->value(friends().table.dateAdded, 200).toInt();
}

void Settings::setFriendsTableStatusWidth(const int &width) {
    settings_->setValue(friends().table.status, width);
}

int Settings::friendsTableStatusWidth() {
    return settings_->value(friends().table.status, 200).toInt();
}

void Settings::setFriendsTableIsOpenWidth(const int &width) {
    settings_->setValue(friends().table.isOpenProfile, width);
}

int Settings::friendsTableIsOpenWidth() {
    return settings_->value(friends().table.isOpenProfile, 200).toInt();
}

QRect Settings::achievementContainerGeometry() {
    return (QRect(0, 0, settings_->value(achievementContainer().Width, 623).toInt(), settings_->value(achievementContainer().Height, 479).toInt()));
}

QPoint Settings::achievementContainerPos() {
    return (QPoint(settings_->value(achievementContainer().X, 100).toInt(), settings_->value(achievementContainer().Y, 100).toInt()));
}

void Settings::setAchievementsTableIconWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.icon, width);
}

int Settings::achievementsTableIconWidth() {
    return settings_->value(achievementContainer().achievements.table.icon, 50).toInt();
}

void Settings::setAchievementsTableTitleWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.title, width);
}

int Settings::achievementsTableTitleWidth() {
    return settings_->value(achievementContainer().achievements.table.title, 400).toInt();
}

void Settings::setAchievementsTableDescriptionWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.description, width);
}

int Settings::achievementsTableDescriptionWidth() {
    return settings_->value(achievementContainer().achievements.table.description, 600).toInt();
}

void Settings::setAchievementsTableCommentWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.comment, width);
}

int Settings::achievementsTableCommentWidth() {
    return settings_->value(achievementContainer().achievements.table.comment, 50).toInt();
}

void Settings::setAchievementsTablePercentWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.percent, width);
}

int Settings::achievementsTablePercentWidth() {
    return settings_->value(achievementContainer().achievements.table.percent, 100).toInt();
}

void Settings::setAchievementsTableAchievedWidth(const int &width) {
    settings_->setValue(achievementContainer().achievements.table.isAchieved, width);
}

int Settings::achievementsTableAchievedWidth() {
    return settings_->value(achievementContainer().achievements.table.isAchieved, 150).toInt();
}

void Settings::setAchievementsCompareIconVisible(const int &width) {
    settings_->setValue(achievementContainer().achievementsCompare.isIconVisible, width);
}

int Settings::achievementsCompareIconVisible() {
    return settings_->value(achievementContainer().achievementsCompare.isIconVisible, 2).toInt();
}

void Settings::setAchievementsCompareTitleVisible(const int &width) {
    settings_->setValue(achievementContainer().achievementsCompare.isTitleVisible, width);
}

int Settings::achievementsCompareTitleVisible() {
    return settings_->value(achievementContainer().achievementsCompare.isTitleVisible, 2).toInt();
}

void Settings::setAchievementsCompareDescriptionVisible(const int &width) {
    settings_->setValue(achievementContainer().achievementsCompare.isDescriptionVisible, width);
}

int Settings::achievementsCompareDescriptionVisible() {
    return settings_->value(achievementContainer().achievementsCompare.isDescriptionVisible, 2).toInt();
}

void Settings::setAchievementsComparePercentVisible(const int &width) {
    settings_->setValue(achievementContainer().achievementsCompare.isPercentVisible, width);
}

int Settings::achievementsComparePercentVisible() {
    return settings_->value(achievementContainer().achievementsCompare.isPercentVisible, 2).toInt();
}

void Settings::syncronizeSettings() {
    settings_->sync();
}

#define SettingsEnd }

#define PathsStart {
QString Paths::documents() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::temp() {
    return QDir::tempPath() + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::categories(QString aGameId) {
    return QString(documents() + "categories/%1%2").arg(aGameId , aGameId != "" ? ".json" : "");
}

QString Paths::favorites(QString aType) {
    return QString(documents() + "favorites/%1%2").arg(aType , aType != "" ? ".json" : "");
}

QString Paths::hiddenGames(QString aSteamId) {
    return QString(documents() + "hide/%1%2").arg(aSteamId != "" ? aSteamId : "All", ".txt");
}

QString Paths::groupGames(QString aProfileId) {
    return QString(documents() + "groups/%1%2").arg(aProfileId, aProfileId != "" ? ".txt" : "");
}

QString Paths::imagesProfiles(const QString &aUrl, const QString &aFormat) {
    return QString(temp() + "images/profiles/%1.%2")
            .arg(aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(QString(".%2").arg(aFormat)) - aUrl.lastIndexOf("/") - 1),
                 aFormat);
}

QString Paths::imagesAchievements(const QString &aGameId, const QString &aUrl) {
    return QString(temp() + "images/achievements/%1/%2.jpg")
            .arg(aGameId,
                 aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(".jpg") - aUrl.lastIndexOf("/") - 1));
}

QString Paths::imagesGames(const QString &aUrl) {
    return QString(temp() + "images/games/%1.jpg").arg(aUrl);
}

QString Paths::commentsGames(const QString &aProfileId) {
    return QString(documents() + "comments/games/%1%2").arg(aProfileId, ".json");
}

QString Paths::commentsAchievements(const QString &aProfileId) {
    return QString(documents() + "comments/achievements/%1%2").arg(aProfileId, aProfileId != "" ? ".json" : "");
}
#define PathsEnd }
