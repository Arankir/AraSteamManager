#include "settings.h"

Q_LOGGING_CATEGORY(logFunc,     "Function")

const QString    Settings::c_organizationName             = "Arankir";
const QString    Settings::c_organizationDomain           = "Arankir";
const QString    Settings::c_applicationName              = "SteamAchievementsStatistic";

QSettings *Settings::_settings = new QSettings(c_organizationName, c_applicationName);

const QString    Settings::c_language                     = "Settings/Language";
const QString    Settings::c_theme                        = "Settings/Theme";
const QString    Settings::c_saveImage                    = "Settings/SaveImages";
const QString    Settings::c_myProfile                    = "Settings/MyProfile";
const QString    Settings::c_visibleHiddenGames           = "Settings/VisibleHiddenGames";
const QString    Settings::c_ProfileInfoSize              = "Settings/VisibleProfileInfo";
const QString    Settings::c_MaxTableRows                 = "Settings/MaxTableRows";

const QString    Settings::c_mainWindowHeight             = "MainWindow/Height";
const QString    Settings::c_mainWindowWidth              = "MainWindow/Width";
const QString    Settings::c_mainWindowX                  = "MainWindow/X";
const QString    Settings::c_mainWindowY                  = "MainWindow/Y";
const QString    Settings::c_mainWindowMaximize           = "MainWindow/Maximize";

const QString    Settings::c_achievementContainerHeight   = "AchievementContainer/Height";
const QString    Settings::c_achievementContainerWidth    = "AchievementContainer/Width";
const QString    Settings::c_achievementContainerX        = "AchievementContainer/X";
const QString    Settings::c_achievementContainerY        = "AchievementContainer/Y";
const QString    Settings::c_achievementContainerMaximize = "achievementContainer/Maximize";

#define SettingsStart {
void Settings::setMyProfile(const QString &aMyProfiles) {
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
}

void Settings::setMainWindowPos(QPoint aPos) {
    _settings->setValue(c_mainWindowX, aPos.x());
    _settings->setValue(c_mainWindowY, aPos.y());
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

QRect Settings::getMainWindowGeometry() {
    return (QRect(0, 0, _settings->value(c_mainWindowWidth, 623).toInt(), _settings->value(c_mainWindowHeight, 479).toInt()));
}

QPoint Settings::getMainWindowPos() {
    return (QPoint(_settings->value(c_mainWindowX, 100).toInt(), _settings->value(c_mainWindowY, 100).toInt()));
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

QString Settings::getFontDefaultName() {
    static int id = QFontDatabase::addApplicationFont(Paths::defaultFont());
    static QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    return family;
}

const QString Settings::getKey() {
    return "3826BF60403D15613B4B0381DAB7A7BD";
}

void Settings::syncronizeSettings() {
    _settings->sync();
}

bool Settings::createDir(const QString &aPath) {
    bool exist = true;
    QString path = aPath;
    path.replace("\\", "/");
    QStringList dirs = path.split("/");
    if (dirs.last() != "") {
        dirs.removeLast();
    }
    QString pathNow = "";
    for (auto &dir: dirs) {
        pathNow += std::move(dir) + "/";
        exist = (QDir().mkdir(pathNow) && exist);
    }
    return exist;
}

#define SettingsEnd }

#define ImagesStart {
QString Images::loading() {
    return "://loading.png";
}

QString Images::logo() {
    return "://logo.png";
}

QString Images::stateBlue() {
    return "://state_blue.png";
}

QString Images::stateGreen() {
    return "://state_green.png";
}

QString Images::stateRed() {
    return "://state_red.png";
}

QString Images::stateYellow() {
    return "://state_yellow.png";
}

QString Images::allAchievements() {
    return "://" + Settings::getIconsColor() + "/all.png";
}

QString Images::back() {
    return "://" + Settings::getIconsColor() + "/back.png";
}

QString Images::cancel() {
    return "://" + Settings::getIconsColor() + "/cancel.png";
}

QString Images::change() {
    return "://" + Settings::getIconsColor() + "/change.png";
}

QString Images::checkAll() {
    return "://" + Settings::getIconsColor() + "/check_all.png";
}

QString Images::checkVisible() {
    return "://" + Settings::getIconsColor() + "/check_visible.png";
}

QString Images::closeWindow() {
    return "://" + Settings::getIconsColor() + "/close_window.png";
}

QString Images::compare() {
    return "://" + Settings::getIconsColor() + "/back.png";
}

QString Images::deleteAll() {
    return "://" + Settings::getIconsColor() + "/delete_all.png";
}

QString Images::down() {
    return "://" + Settings::getIconsColor() + "/down.png";
}

QString Images::exit() {
    return "://" + Settings::getIconsColor() + "/exit.png";
}

QString Images::isFavorites() {
    return "://" + Settings::getIconsColor() + "/in_favorites.png";
}

QString Images::isNotFavorites() {
    return "://" + Settings::getIconsColor() + "/favorites.png";
}

QString Images::filter() {
    return "://" + Settings::getIconsColor() + "/filter.png";
}

QString Images::find() {
    return "://" + Settings::getIconsColor() + "/find.png";
}

QString Images::findProfile() {
    return "://" + Settings::getIconsColor() + "/find_profile.png";
}

QString Images::friends() {
    return "://" + Settings::getIconsColor() + "/friends.png";
}

QString Images::games() {
    return "://" + Settings::getIconsColor() + "/games.png";
}

QString Images::goTo() {
    return "://" + Settings::getIconsColor() + "/go_to.png";
}

QString Images::hide() {
    return "://" + Settings::getIconsColor() + "/hide.png";
}

QString Images::home() {
    return "://" + Settings::getIconsColor() + "/home.png";
}

QString Images::left() {
    return "://" + Settings::getIconsColor() + "/left.png";
}

QString Images::link() {
    return "://" + Settings::getIconsColor() + "/link.png";
}

QString Images::maximizeWindow() {
    return "://" + Settings::getIconsColor() + "/maximize_window.png";
}

QString Images::minimizeWindow() {
    return "://" + Settings::getIconsColor() + "/minimize_window.png";
}

QString Images::notReached() {
    return "://" + Settings::getIconsColor() + "/notreached.png";
}

QString Images::profile() {
    return "://" + Settings::getIconsColor() + "/profile.png";
}

QString Images::reached() {
    return "://" + Settings::getIconsColor() + "/reached.png";
}

QString Images::normalizeWindow() {
    return "://" + Settings::getIconsColor() + "/restore_window.png";
}

QString Images::reverse() {
    return "://" + Settings::getIconsColor() + "/reverse.png";
}

QString Images::right() {
    return "://" + Settings::getIconsColor() + "/right.png";
}

QString Images::setHome() {
    return "://" + Settings::getIconsColor() + "/set_home.png";
}

QString Images::settings() {
    return "://" + Settings::getIconsColor() + "/settings.png";
}

QString Images::statistic() {
    return "://" + Settings::getIconsColor() + "/statistic.png";
}

QString Images::uncheckVisible() {
    return "://" + Settings::getIconsColor() + "/uncheck_visible.png";
}

QString Images::unhide() {
    return "://" + Settings::getIconsColor() + "/unhide.png";
}

QString Images::up() {
    return "://" + Settings::getIconsColor() + "/up.png";
}

QString Images::update() {
    return "://" + Settings::getIconsColor() + "/update.png";
}

QString Images::create() {
    return "://" + Settings::getIconsColor() + "/create.png";
}

QString Images::deleteIcon() {
    return "://" + Settings::getIconsColor() + "/delete.png";
}

QString Images::edit() {
    return "://" + Settings::getIconsColor() + "/edit.png";
}

QString Images::apply() {
    return "://" + Settings::getIconsColor() + "/apply.png";
}

QString Images::top() {
    return "://" + Settings::getIconsColor() + "/top.png";
}

QString Images::bottom() {
    return "://" + Settings::getIconsColor() + "/bottom.png";
}

QString Images::isComment() {
    return "://" + Settings::getIconsColor() + "/isComment.png";
}

QString Images::isNotComment() {
    return "://" + Settings::getIconsColor() + "/isNotComment.png";
}

QString Images::achievement() {
    return "://" + Settings::getIconsColor() + "/achievement.png";
}

QString Images::download() {
    return "://" + Settings::getIconsColor() + "/download.png";
}

QString Images::visible() {
    return "://" + Settings::getIconsColor() + "/visible.png";
}

QString Images::category() {
    return "://" + Settings::getIconsColor() + "/category.png";
}

QString Images::group1() {
    return "://" + Settings::getIconsColor() + "/group1.png";
}

QString Images::group2() {
    return "://" + Settings::getIconsColor() + "/group2.png";
}

#define IconsWidgetStart {
QString Images::checkBoxChecked() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_checked.png";
}

QString Images::checkBoxCheckedHover() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_checked_hover.png";
}

QString Images::checkBoxCheckedPress() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_checked_press.png";
}

QString Images::checkBoxUnchecked() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_unchecked.png";
}

QString Images::checkBoxUncheckedHover() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_unchecked_hover.png";
}

QString Images::checkBoxUncheckedPress() {
    return "://" + Settings::getIconsColor() + "/widgets/checkbox_unchecked_press.png";
}

QString Images::radioButtonChecked() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_checked.png";
}

QString Images::radioButtonCheckedHover() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_checked_hover.png";
}

QString Images::radioButtonCheckedPress() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_checked_press.png";
}

QString Images::radioButtonUnchecked() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_unchecked.png";
}

QString Images::radioButtonUncheckedHover() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_unchecked_hover.png";
}

QString Images::radioButtonUncheckedPress() {
    return "://" + Settings::getIconsColor() + "/widgets/radiobutton_unchecked_press.png";
}

QString Images::comboBoxDown() {
    return "://" + Settings::getIconsColor() + "/widgets/combobox_down.png";
}

QString Images::scrollBarUp() {
    return "://" + Settings::getIconsColor() + "/widgets/scrollbar_up.png";
}

QString Images::scrollBarDown() {
    return "://" + Settings::getIconsColor() + "/widgets/scrollbar_down.png";
}

QString Images::scrollBarLeft() {
    return "://" + Settings::getIconsColor() + "/widgets/scrollbar_left.png";
}

QString Images::scrollBarRight() {
    return "://" + Settings::getIconsColor() + "/widgets/scrollbar_right.png";
}

QString Images::missingImage() {
    return "://MissingImage.png";
}
#define IconsWidgetEnd }
#define SettingsEnd }

#define PathsStart {
QString Paths::documents() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::temp() {
    return QDir::tempPath() + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::defaultFont() {
    return "C:/JosefinSans-Italic-VariableFont_wght.ttf";
}

QString Paths::categories(QString aGameId) {
    return QString(documents() + "files/categories/%1%2").arg(aGameId , aGameId != "" ? ".json" : "");
}

QString Paths::favorites(QString aType) {
    return QString(documents() + "files/favorites/%1%2").arg(aType , aType != "" ? ".json" : "");
}

QString Paths::hiddenGames(QString aGameId) {
    return QString(documents() + "files/hide/%1%2").arg(aGameId, aGameId != "" ? ".txt" : "");
}

QString Paths::groupGames(QString aProfileId) {
    return QString(documents() + "files/groups/%1%2").arg(aProfileId, aProfileId != "" ? ".txt" : "");
}

QString Paths::imagesProfiles(const QString &aUrl) {
    return QString(temp() + "images/profiles/%1.jpg").arg(aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(".jpg") - aUrl.lastIndexOf("/") - 1));
}

QString Paths::imagesAchievements(const QString &aGameId, const QString &aUrl) {
    return QString(temp() + "images/achievements/%1/%2.jpg").arg(aGameId, aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(".jpg") - aUrl.lastIndexOf("/") - 1));
}

QString Paths::imagesGames(const QString &aUrl) {
    return QString(temp() + "images/games/%1.jpg").arg(aUrl);
}

QString Paths::commentsGames(const QString &aProfileId) {
    return QString(documents() + "files/comments/games/%1%2").arg(aProfileId, ".json");
}

QString Paths::commentsAchievements(const QString &aProfileId) {
    return QString(documents() + "files/comments/achievements/%1%2").arg(aProfileId, aProfileId != "" ? ".json" : "");
}
#define PathsEnd }
