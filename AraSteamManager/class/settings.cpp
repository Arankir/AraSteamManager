#include "settings.h"


Settings::Settings(QObject *aParent): Settings(QRect(), aParent) {

}

Settings::Settings(QRect aGeometry, QObject *aParent): QObject(aParent), _settings(new QSettings("Arankir", "SteamAchievementsStatistic")) ,_screen(aGeometry) {

}

void Settings::customGeometry(QRect aGeometry) {
    _screen=aGeometry;
}

void Settings::setMyProfile(QString aMyProfiles) {
    return _settings->setValue(c_myProfile, aMyProfiles);
}

void Settings::setLanguage(int aLanguage) {
    return _settings->setValue(c_language, aLanguage);
}

void Settings::setTheme(int aTheme) {
    return _settings->setValue(c_theme, aTheme);
}

void Settings::setSaveimage(int aSaveImage) {
    return _settings->setValue(c_saveImage, aSaveImage);
}

void Settings::setVisibleHiddenGames(int aVisibleHiddenGames) {
    return _settings->setValue(c_visibleHiddenGames, aVisibleHiddenGames);
}

void Settings::setVisibleProfileInfo(int aVisibleProfileInfo) {
    return _settings->setValue(c_ProfileInfoSize, aVisibleProfileInfo);
}

void Settings::setMainWindowParams(QRect aGeometry) {
    _settings->setValue(c_mainWindowHeight, aGeometry.height());
    _settings->setValue(c_mainWindowWidth, aGeometry.width());
    _settings->setValue(c_mainWindowX, aGeometry.x());
    _settings->setValue(c_mainWindowY, aGeometry.y());
    _settings->setValue(c_mainWindowPercentX, aGeometry.x() / _screen.width());
    _settings->setValue(c_mainWindowPercentY, aGeometry.y() / _screen.height());
}

void Settings::setMainWindowPos(QPoint aPos) {
    _settings->setValue(c_mainWindowX, aPos.x());
    _settings->setValue(c_mainWindowY, aPos.y());
    _settings->setValue(c_mainWindowPercentX, aPos.x() / _screen.width());
    _settings->setValue(c_mainWindowPercentY, aPos.y() / _screen.height());
}

void Settings::setMainWindowGeometry(QSize aSize) {
    _settings->setValue(c_mainWindowHeight, aSize.height());
    _settings->setValue(c_mainWindowWidth, aSize.width());
}

void Settings::setMainWindowMaximize(bool aMaximize) {
    _settings->setValue(c_mainWindowMaximize, aMaximize);
}

void Settings::setAchievementContainerParams(QRect aGeometry){
    _settings->setValue(c_achievementContainerHeight, aGeometry.height());
    _settings->setValue(c_achievementContainerWidth, aGeometry.width());
    _settings->setValue(c_achievementContainerX, aGeometry.x());
    _settings->setValue(c_achievementContainerY, aGeometry.y());
    _settings->setValue(c_achievementContainerPercentX, aGeometry.x() / _screen.width());
    _settings->setValue(c_achievementContainerPercentY, aGeometry.y() / _screen.height());
}

QString Settings::getMyProfile() {
    return _settings->value(c_myProfile, "none").toString();
}

int Settings::getLanguage() {
    return _settings->value(c_language, 1).toInt();
}

int Settings::getTheme() {
    return _settings->value(c_theme, 1).toInt();
}

int Settings::getSaveImages() {
    return _settings->value(c_saveImage, 0).toInt();
}

int Settings::getVisibleHiddenGames() {
    return _settings->value(c_visibleHiddenGames, 0).toInt();
}

int Settings::getProfileInfoSize() {
    return _settings->value(c_ProfileInfoSize, 2).toInt();
}

QRect Settings::getMainWindowGeometry() {
    return (QRect(0, 0, _settings->value(c_mainWindowWidth, 623).toInt(), _settings->value(c_mainWindowHeight, 479).toInt()));
}

QPoint Settings::getMainWindowPos() {
    return (QPoint(_settings->value(c_mainWindowX, 100).toInt(), _settings->value(c_mainWindowY, 100).toInt()));
}

QPoint Settings::getMainWindowPercentPos() {
    return (QPoint(_settings->value(c_mainWindowPercentX, 0).toInt(), _settings->value(c_mainWindowPercentY, 0).toInt()));
}

bool Settings::getMainWindowMaximize() {
    return _settings->value(c_mainWindowMaximize, false).toBool();
}

QRect Settings::getAchievementContainerGeometry() {
    return (QRect(0, 0, _settings->value(c_achievementContainerWidth, 623).toInt(), _settings->value(c_achievementContainerHeight, 479).toInt()));
}

QPoint Settings::getAchievementContainerPos() {
    return (QPoint(_settings->value(c_achievementContainerX, 100).toInt(), _settings->value(c_achievementContainerY, 100).toInt()));
}

QPoint Settings::getAchievementContainerPercentPos() {
    return (QPoint(_settings->value(c_achievementContainerPercentX, 0).toInt(), _settings->value(c_achievementContainerPercentY, 0).toInt()));
}

QString Settings::getKey() {
    return "3826BF60403D15613B4B0381DAB7A7BD";
}

void Settings::syncronizeSettings() {
    _settings->sync();
}

bool Settings::createDir(QString aPath) {
    bool exist = true;
    QStringList dirs = aPath.split("/");
    QString pathNow = "";
    for (auto &dir: dirs) {
        if (dir != dirs.last()) {
            pathNow += std::move(dir)+"/";
            exist = (QDir().mkdir(pathNow) && exist);
        }
    }
    return exist;
}
