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
};

struct mainWindow {
    const QString state         = "MainWindow/State";
    const QString geometry      = "MainWindow/Geometry";
};

struct achievementContainer {
    const QString state         = "AchievementContainer/State";
    const QString geometry      = "AchievementContainer/Geometry";
};

const QString    Settings::c_organizationName   = "Arankir";
const QString    Settings::c_organizationDomain = "Arankir";
const QString    Settings::c_applicationName    = "SteamAchievementsStatistic";

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

void Settings::setMainWindowState(const QByteArray &aState) {
    settings_->setValue(mainWindow().state, aState);
}

QByteArray Settings::mainWindowState() {
    return settings_->value(mainWindow().state, QByteArray()).toByteArray();
}

void Settings::setMainWindowGeometry(const QByteArray &aGeometry) {
    settings_->setValue(mainWindow().geometry, aGeometry);
}

QByteArray Settings::mainWindowGeometry() {
    return settings_->value(mainWindow().geometry, QByteArray()).toByteArray();
}

void Settings::setAchievementContainerState(const QByteArray &aState) {
    settings_->setValue(achievementContainer().state, aState);
}

QByteArray Settings::achievementContainerState() {
    return settings_->value(achievementContainer().state, QByteArray()).toByteArray();
}

void Settings::setAchievementContainerGeometry(const QByteArray &aGeometry) {
    settings_->setValue(achievementContainer().geometry, aGeometry);
}

QByteArray Settings::achievementContainerGeometry() {
    return settings_->value(achievementContainer().geometry, QByteArray()).toByteArray();
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
    return QString(documents() + "comments/games/%1%2").arg(aProfileId , aProfileId != "" ? ".json" : "");
}

QString Paths::commentsAchievements(const QString &aProfileId) {
    return QString(documents() + "comments/achievements/%1%2").arg(aProfileId, aProfileId != "" ? ".json" : "");
}
#define PathsEnd }
