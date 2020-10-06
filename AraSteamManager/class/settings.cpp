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

void Settings::setMaximumTableRows(int rows){
    return _settings->setValue(c_MaxTableRows, rows);
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

QString Settings::getIconsColor() {
    switch(getTheme()) {
    case 1: {
        return "white";
        break;
    }
    case 2: {
        return "black";
        break;
    }
    default: {
        return "white";
    }
    }
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

int Settings::getMaximumTableRows() {
    return _settings->value(c_MaxTableRows, 100).toInt();
}

#define IconsStart {
QString Settings::getIconLoadingColor() {
    return "://loading.png";
}

QString Settings::getIconLogoColor() {
    return "://logo.png";
}

QString Settings::getIconStateBlue() {
    return "://state_blue.png";
}

QString Settings::getIconStateGreen() {
    return "://state_green.png";
}

QString Settings::getIconStateRed() {
    return "://state_red.png";
}

QString Settings::getIconStateYellow() {
    return "://state_yellow.png";
}

QString Settings::getIconAll() {
    return "://" + getIconsColor() + "/all.png";
}

QString Settings::getIconBack() {
    return "://" + getIconsColor() + "/back.png";
}

QString Settings::getIconCancel() {
    return "://" + getIconsColor() + "/cancel.png";
}

QString Settings::getIconChange() {
    return "://" + getIconsColor() + "/change.png";
}

QString Settings::getIconCheckAll() {
    return "://" + getIconsColor() + "/check_all.png";
}

QString Settings::getIconCheckVisible() {
    return "://" + getIconsColor() + "/check_visible.png";
}

QString Settings::getIconCloseWindow() {
    return "://" + getIconsColor() + "/close_window.png";
}

QString Settings::getIconCompare() {
    return "://" + getIconsColor() + "/back.png";
}

QString Settings::getIconDeleteAll() {
    return "://" + getIconsColor() + "/delete_all.png";
}

QString Settings::getIconDown() {
    return "://" + getIconsColor() + "/down.png";
}

QString Settings::getIconExit() {
    return "://" + getIconsColor() + "/exit.png";
}

QString Settings::getIconIsFavorites() {
    return "://" + getIconsColor() + "/in_favorites.png";
}

QString Settings::getIconIsNotFavorites() {
    return "://" + getIconsColor() + "/favorites.png";
}

QString Settings::getIconFilter() {
    return "://" + getIconsColor() + "/filter.png";
}

QString Settings::getIconFind() {
    return "://" + getIconsColor() + "/find.png";
}

QString Settings::getIconFindProfile() {
    return "://" + getIconsColor() + "/find_profile.png";
}

QString Settings::getIconFriends() {
    return "://" + getIconsColor() + "/friends.png";
}

QString Settings::getIconGames() {
    return "://" + getIconsColor() + "/games.png";
}

QString Settings::getIconGoTo() {
    return "://" + getIconsColor() + "/go_to.png";
}

QString Settings::getIconHide() {
    return "://" + getIconsColor() + "/hide.png";
}

QString Settings::getIconHome() {
    return "://" + getIconsColor() + "/home.png";
}

QString Settings::getIconLeft() {
    return "://" + getIconsColor() + "/left.png";
}

QString Settings::getIconLink() {
    return "://" + getIconsColor() + "/link.png";
}

QString Settings::getIconMaximizeWindow() {
    return "://" + getIconsColor() + "/maximize_window.png";
}

QString Settings::getIconMinimizeWindow() {
    return "://" + getIconsColor() + "/minimize_window.png";
}

QString Settings::getIconNotReached() {
    return "://" + getIconsColor() + "/notreached.png";
}

QString Settings::getIconProfile() {
    return "://" + getIconsColor() + "/profile.png";
}

QString Settings::getIconReached() {
    return "://" + getIconsColor() + "/reached.png";
}

QString Settings::getIconNormalizeWindow() {
    return "://" + getIconsColor() + "/restore_window.png";
}

QString Settings::getIconReverse() {
    return "://" + getIconsColor() + "/reverse.png";
}

QString Settings::getIconRight() {
    return "://" + getIconsColor() + "/right.png";
}

QString Settings::getIconSetHome() {
    return "://" + getIconsColor() + "/set_home.png";
}

QString Settings::getIconSettings() {
    return "://" + getIconsColor() + "/settings.png";
}

QString Settings::getIconStatistic() {
    return "://" + getIconsColor() + "/statistic.png";
}

QString Settings::getIconUncheckVisible() {
    return "://" + getIconsColor() + "/uncheck_visible.png";
}

QString Settings::getIconUnhide() {
    return "://" + getIconsColor() + "/unhide.png";
}

QString Settings::getIconUp() {
    return "://" + getIconsColor() + "/up.png";
}

QString Settings::getIconUpdate() {
    return "://" + getIconsColor() + "/update.png";
}

QString Settings::getIconCreate() {
    return "://" + getIconsColor() + "/create.png";
}

QString Settings::getIconDelete() {
    return "://" + getIconsColor() + "/delete.png";
}

QString Settings::getIconEdit() {
    return "://" + getIconsColor() + "/edit.png";
}

QString Settings::getIconApply() {
    return "://" + getIconsColor() + "/apply.png";
}

QString Settings::getIconTop() {
    return "://" + getIconsColor() + "/top.png";
}

QString Settings::getIconBottom() {
    return "://" + getIconsColor() + "/bottom.png";
}

#define IconsWidgetStart {
QString Settings::getIconCheckBoxChecked() {
    return "://" + getIconsColor() + "/widgets/checkbox_checked.png";
}

QString Settings::getIconCheckBoxCheckedHover() {
    return "://" + getIconsColor() + "/widgets/checkbox_checked_hover.png";
}

QString Settings::getIconCheckBoxCheckedPress() {
    return "://" + getIconsColor() + "/widgets/checkbox_checked_press.png";
}

QString Settings::getIconCheckBoxUnchecked() {
    return "://" + getIconsColor() + "/widgets/checkbox_unchecked.png";
}

QString Settings::getIconCheckBoxUncheckedHover() {
    return "://" + getIconsColor() + "/widgets/checkbox_unchecked_hover.png";
}

QString Settings::getIconCheckBoxUncheckedPress() {
    return "://" + getIconsColor() + "/widgets/checkbox_unchecked_press.png";
}

QString Settings::getIconRadioButtonChecked() {
    return "://" + getIconsColor() + "/widgets/radiobutton_checked.png";
}

QString Settings::getIconRadioButtonCheckedHover() {
    return "://" + getIconsColor() + "/widgets/radiobutton_checked_hover.png";
}

QString Settings::getIconRadioButtonCheckedPress() {
    return "://" + getIconsColor() + "/widgets/radiobutton_checked_press.png";
}

QString Settings::getIconRadioButtonUnchecked() {
    return "://" + getIconsColor() + "/widgets/radiobutton_unchecked.png";
}

QString Settings::getIconRadioButtonUncheckedHover() {
    return "://" + getIconsColor() + "/widgets/radiobutton_unchecked_hover.png";
}

QString Settings::getIconRadioButtonUncheckedPress() {
    return "://" + getIconsColor() + "/widgets/radiobutton_unchecked_press.png";
}

QString Settings::getIconComboboxDown() {
    return "://" + getIconsColor() + "/widgets/combobox_down.png";
}

QString Settings::getIconScrollbarUp() {
    return "://" + getIconsColor() + "/widgets/scrollbar_up.png";
}

QString Settings::getIconScrollbarDown() {
    return "://" + getIconsColor() + "/widgets/scrollbar_down.png";
}

QString Settings::getIconScrollbarLeft() {
    return "://" + getIconsColor() + "/widgets/scrollbar_left.png";
}

QString Settings::getIconScrollbarRight() {
    return "://" + getIconsColor() + "/widgets/scrollbar_right.png";
}

QString Settings::getMissingImage() {
    return "://MissingImage.png";
}
#define IconsWidgetEnd }
#define IconsEnd }

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

QString Settings::getPathForImagesProfiles(const QString &url) {
    return "images/profiles/" + url.mid(url.lastIndexOf("/") + 1, url.lastIndexOf(".jpg") - url.lastIndexOf("/") - 1) + ".jpg";
}

QString Settings::getPathForImagesAchievements(const QString &gameId, const QString &url) {
    return "images/achievements/" + gameId + "/" + url.mid(url.lastIndexOf("/") + 1, url.lastIndexOf(".jpg") - url.lastIndexOf("/") - 1) + ".jpg";
}

QString Settings::getPathForIconGames(const QString &url) {
    return "images/icon_games/" + url + ".jpg";
}

bool Settings::createDir(const QString &aPath) {
    bool exist = true;
    QString path = aPath;
    path.replace("\\", "/");
    if (path.lastIndexOf("/") != path.length() - 1) {
        path += "/";
    }
    QStringList dirs = path.split("/");
    QString pathNow = "";
    for (auto &dir: dirs) {
        if (dir != dirs.last()) {
            pathNow += std::move(dir)+"/";
            exist = (QDir().mkdir(pathNow) && exist);
        }
    }
    return exist;
}

QString Settings::getUrlIconGame(const QString &appId, const QString &img_icon_url) {
    return "http://media.steampowered.com/steamcommunity/public/images/apps/" + appId + "/" + img_icon_url + ".jpg";
}
