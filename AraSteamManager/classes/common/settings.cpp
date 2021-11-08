#include "settings.h"
#include <QDir>

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

QSettings *      Settings::_settings                      = new QSettings(c_organizationName, c_applicationName);

#define SettingsStart {
void Settings::setMyProfile(const QString &aMyProfiles) {
    return _settings->setValue(settings().myProfile, aMyProfiles);
}

void Settings::setLanguage(const int &aLanguage) {
    return _settings->setValue(settings().language, aLanguage);
}

void Settings::setTheme(const int &aTheme) {
    return _settings->setValue(settings().theme, aTheme);
}

void Settings::setSaveimage(const int &aSaveImage) {
    return _settings->setValue(settings().saveImage, aSaveImage);
}

void Settings::setVisibleHiddenGames(const int &aVisibleHiddenGames) {
    return _settings->setValue(settings().visibleHiddenGames, aVisibleHiddenGames);
}

void Settings::setVisibleProfileInfo(const int &aVisibleProfileInfo) {
    return _settings->setValue(settings().profileInfoSize, aVisibleProfileInfo);
}

//void Settings::setMaximumTableRows(const int &rows){
//    return _settings->setValue(c_MaxTableRows, rows);
//}

void Settings::setMainWindowParams(QRect aGeometry) {
    _settings->setValue(mainWindow().Height, aGeometry.height());
    _settings->setValue(mainWindow().Width, aGeometry.width());
    _settings->setValue(mainWindow().X, aGeometry.x());
    _settings->setValue(mainWindow().Y, aGeometry.y());
}

void Settings::setMainWindowPos(const QPoint &aPos) {
    _settings->setValue(mainWindow().X, aPos.x());
    _settings->setValue(mainWindow().Y, aPos.y());
}

void Settings::setMainWindowIsMaximize(bool aMaximize) {
    _settings->setValue(mainWindow().isMaximize, aMaximize);
}

void Settings::setAchievementContainerParams(QRect aGeometry){
    _settings->setValue(achievementContainer().Height, aGeometry.height());
    _settings->setValue(achievementContainer().Width, aGeometry.width());
    _settings->setValue(achievementContainer().X, aGeometry.x());
    _settings->setValue(achievementContainer().Y, aGeometry.y());
}

QString Settings::myProfile() {
    return _settings->value(settings().myProfile, "none").toString();
}

int Settings::language() {
    return _settings->value(settings().language, 1).toInt();
}

int Settings::theme() {
    return _settings->value(settings().theme, 1).toInt();
}

int Settings::saveImages() {
    return _settings->value(settings().saveImage, 1).toInt();
}

int Settings::visibleHiddenGames() {
    return _settings->value(settings().visibleHiddenGames, 0).toInt();
}

int Settings::profileInfoSize() {
    return _settings->value(settings().profileInfoSize, 2).toInt();
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
    return (QRect(0, 0, _settings->value(mainWindow().Width, 623).toInt(), _settings->value(mainWindow().Height, 479).toInt()));
}

QPoint Settings::mainWindowPos() {
    return (QPoint(_settings->value(mainWindow().X, 100).toInt(), _settings->value(mainWindow().Y, 100).toInt()));
}

bool Settings::isMainWindowMaximize() {
    return _settings->value(mainWindow().isMaximize, false).toBool();
}

void Settings::setGamesTableIconWidth(const int &width) {
    _settings->setValue(games().table.icon, width);
}

int Settings::gamesTableIconWidth() {
    return _settings->value(games().table.icon, 50).toInt();
}

void Settings::setGamesTableTitleWidth(const int &width) {
    _settings->setValue(games().table.title, width);
}

int Settings::gamesTableTitleWidth() {
    return _settings->value(games().table.title, 400).toInt();
}

void Settings::setGamesTableCommentWidth(const int &width) {
    _settings->setValue(games().table.comment, width);
}

int Settings::gamesTableCommentWidth() {
    return _settings->value(games().table.comment, 50).toInt();
}

void Settings::setGamesTableProgressWidth(const int &width) {
    _settings->setValue(games().table.progress, width);
}

int Settings::gamesTableProgressWidth() {
    return _settings->value(games().table.progress, 100).toInt();
}

void Settings::setFriendsTableIconWidth(const int &width) {
    _settings->setValue(friends().table.icon, width);
}

int Settings::friendsTableIconWidth() {
    return _settings->value(friends().table.icon, 50).toInt();
}

void Settings::setFriendsTableNameWidth(const int &width) {
    _settings->setValue(friends().table.name, width);
}

int Settings::friendsTableNameWidth() {
    return _settings->value(friends().table.name, 400).toInt();
}

void Settings::setFriendsTableAddedWidth(const int &width) {
    _settings->setValue(friends().table.dateAdded, width);
}

int Settings::friendsTableAddedWidth() {
    return _settings->value(friends().table.dateAdded, 200).toInt();
}

void Settings::setFriendsTableStatusWidth(const int &width) {
    _settings->setValue(friends().table.status, width);
}

int Settings::friendsTableStatusWidth() {
    return _settings->value(friends().table.status, 200).toInt();
}

void Settings::setFriendsTableIsOpenWidth(const int &width) {
    _settings->setValue(friends().table.isOpenProfile, width);
}

int Settings::friendsTableIsOpenWidth() {
    return _settings->value(friends().table.isOpenProfile, 200).toInt();
}

QRect Settings::achievementContainerGeometry() {
    return (QRect(0, 0, _settings->value(achievementContainer().Width, 623).toInt(), _settings->value(achievementContainer().Height, 479).toInt()));
}

QPoint Settings::achievementContainerPos() {
    return (QPoint(_settings->value(achievementContainer().X, 100).toInt(), _settings->value(achievementContainer().Y, 100).toInt()));
}

void Settings::setAchievementsTableIconWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.icon, width);
}

int Settings::achievementsTableIconWidth() {
    return _settings->value(achievementContainer().achievements.table.icon, 50).toInt();
}

void Settings::setAchievementsTableTitleWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.title, width);
}

int Settings::achievementsTableTitleWidth() {
    return _settings->value(achievementContainer().achievements.table.title, 400).toInt();
}

void Settings::setAchievementsTableDescriptionWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.description, width);
}

int Settings::achievementsTableDescriptionWidth() {
    return _settings->value(achievementContainer().achievements.table.description, 600).toInt();
}

void Settings::setAchievementsTableCommentWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.comment, width);
}

int Settings::achievementsTableCommentWidth() {
    return _settings->value(achievementContainer().achievements.table.comment, 50).toInt();
}

void Settings::setAchievementsTablePercentWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.percent, width);
}

int Settings::achievementsTablePercentWidth() {
    return _settings->value(achievementContainer().achievements.table.percent, 100).toInt();
}

void Settings::setAchievementsTableAchievedWidth(const int &width) {
    _settings->setValue(achievementContainer().achievements.table.isAchieved, width);
}

int Settings::achievementsTableAchievedWidth() {
    return _settings->value(achievementContainer().achievements.table.isAchieved, 150).toInt();
}

void Settings::setAchievementsCompareIconVisible(const int &width) {
    _settings->setValue(achievementContainer().achievementsCompare.isIconVisible, width);
}

int Settings::achievementsCompareIconVisible() {
    return _settings->value(achievementContainer().achievementsCompare.isIconVisible, 2).toInt();
}

void Settings::setAchievementsCompareTitleVisible(const int &width) {
    _settings->setValue(achievementContainer().achievementsCompare.isTitleVisible, width);
}

int Settings::achievementsCompareTitleVisible() {
    return _settings->value(achievementContainer().achievementsCompare.isTitleVisible, 2).toInt();
}

void Settings::setAchievementsCompareDescriptionVisible(const int &width) {
    _settings->setValue(achievementContainer().achievementsCompare.isDescriptionVisible, width);
}

int Settings::achievementsCompareDescriptionVisible() {
    return _settings->value(achievementContainer().achievementsCompare.isDescriptionVisible, 2).toInt();
}

void Settings::setAchievementsComparePercentVisible(const int &width) {
    _settings->setValue(achievementContainer().achievementsCompare.isPercentVisible, width);
}

int Settings::achievementsComparePercentVisible() {
    return _settings->value(achievementContainer().achievementsCompare.isPercentVisible, 2).toInt();
}

QString Settings::defaultFont() {
    static int id = QFontDatabase::addApplicationFont(Settings::defaultFontPath());
    static QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    return family;
}

QString Settings::defaultFontPath() {
    return "://JosefinSans-Italic-VariableFont_wght.ttf";
//    return "://DancingScript-VariableFont_wght.ttf";
//    return "://Comfortaa-VariableFont_wght.ttf";
}

#include <QColor>
QString Settings::qssTheme() {
    QString qss;
    Theme currentTheme = Theme::getCurrentTheme();

    QFile qssColorFile(":/theme/baseColor.qss");
    qssColorFile.open(QFile::ReadOnly);
    qss = QString(qssColorFile.readAll()).arg(currentTheme.text.getString(),
                                              currentTheme.disabledBackground.getString(),
                                              currentTheme.disabled.getString(),
                                              currentTheme.hover.getString(),
                                              currentTheme.border.getString(),
                                              currentTheme.alternate.getString(),
                                              currentTheme.background.getString(),
                                              currentTheme.backgroundSelectedItem.getString(),
                                              currentTheme.backgroundSecond.getString(),
                                              currentTheme.backgroundProgressbar.getString(),
                                              currentTheme.backgroundBadProgressbar.getString(),
                                              currentTheme.backgroundProgressbarProgress.getString(),
                                              currentTheme.selected.getString(),
                                              QString(QString::number(currentTheme.headerForm.getColor().red()) + ", " + QString::number(currentTheme.headerForm.getColor().green()) + ", " + QString::number(currentTheme.headerForm.getColor().blue())),
                                              QString(QString::number(currentTheme.backgroundItem.getColor().red()) + ", " + QString::number(currentTheme.backgroundItem.getColor().green()) + ", " + QString::number(currentTheme.backgroundItem.getColor().blue())),
                                              QString(QString::number(currentTheme.backgroundAlternateItem.getColor().red()) + ", " + QString::number(currentTheme.backgroundAlternateItem.getColor().green()) + ", " + QString::number(currentTheme.backgroundAlternateItem.getColor().blue())),
                                              QString(QString::number(currentTheme.forItemHover.getColor().red()) + ", " + QString::number(currentTheme.forItemHover.getColor().green()) + ", " + QString::number(currentTheme.forItemHover.getColor().blue())),
                                              QString(QString::number(currentTheme.mainProfileBackground.getColor().red()) + ", " + QString::number(currentTheme.mainProfileBackground.getColor().green()) + ", " + QString::number(currentTheme.mainProfileBackground.getColor().blue())),
                                              currentTheme.mainBackground.getString());

    QFile qssIconsFile(":/theme/baseIcons.qss");
    qssIconsFile.open(QFile::ReadOnly);
    qss += QString(qssIconsFile.readAll()).arg(currentTheme.getPathIcons());

    QFile qssFile(":/theme/globalTheme.qss");
    qssFile.open(QFile::ReadOnly);
    qss += qssFile.readAll();
    qss += " "
    "* { "
        "font-family:  " + Settings::defaultFont() + "; "
    "} ";

    return qss;
}

QString Settings::iconsColor() {
    switch(theme()) {
    case 1: {
        return "white";
    }
    case 2: {
        return "black";
    }
    case 3: {
        return "white";
    }
    case 4: {
        return "white";
    }
    case 5: {
        return "white";
    }
    case 6: {
        return "white";
    }
    case 7: {
        return "white";
    }
    case 8: {
        return "white";
    }
    default: {
        return "white";
    }
    }
}

void Settings::syncronizeSettings() {
    _settings->sync();
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

QString Paths::imagesProfiles(const QString &aUrl) {
    return QString(temp() + "images/profiles/%1.jpg")
            .arg(aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(".jpg") - aUrl.lastIndexOf("/") - 1));
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
