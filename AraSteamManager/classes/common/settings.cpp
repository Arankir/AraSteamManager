#include "settings.h"

//Q_LOGGING_CATEGORY(logFunc,     "Function")

const QString    Settings::c_organizationName             = "Arankir";
const QString    Settings::c_organizationDomain           = "Arankir";
const QString    Settings::c_applicationName              = "SteamAchievementsStatistic";

QSettings *      Settings::_settings                      = new QSettings(c_organizationName, c_applicationName);

const QString    Settings::c_language                     = "Settings/Language";
const QString    Settings::c_theme                        = "Settings/Theme";
const QString    Settings::c_saveImage                    = "Settings/SaveImages";
const QString    Settings::c_myProfile                    = "Settings/MyProfile";
const QString    Settings::c_visibleHiddenGames           = "Settings/VisibleHiddenGames";
const QString    Settings::c_ProfileInfoSize              = "Settings/VisibleProfileInfo";
//const QString    Settings::c_MaxTableRows                 = "Settings/MaxTableRows";

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

const int c_toolTipMaxWidth = 30;

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

//void Settings::setMaximumTableRows(int rows){
//    return _settings->setValue(c_MaxTableRows, rows);
//}

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

void Settings::setMainWindowIsMaximize(bool aMaximize) {
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
    case 2: {
        return "black";
        //break;
    }
    case 1: {
        //return "white";
        //break;
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

//int Settings::getMaximumTableRows() {
//    return _settings->value(c_MaxTableRows, 100).toInt();
//}

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

QString Settings::getQssTheme() {
    QString qss;
    switch(getTheme()) {
    case 1:{
        QFile qssFile("://blackTheme.qss");
        qssFile.open(QFile::ReadOnly);
        qss = qssFile.readAll() + " "
        "QRadioButton::indicator::unchecked { "
            "image: url(" + Images::radioButtonUnchecked() + "); "
        "} "
        "QRadioButton::indicator::checked { "
            "image: url(" + Images::radioButtonChecked() + "); "
        "} "
        "QRadioButton::indicator::unchecked:hover { "
            "image: url(" + Images::radioButtonUncheckedHover() + "); "
        "} "
        "QRadioButton::indicator::checked:hover { "
            "image: url(" + Images::radioButtonCheckedHover() + "); "
        "} "
        "QRadioButton::indicator::unchecked:pressed { "
            "image: url(" + Images::radioButtonUncheckedPress() + "); "
        "} "
        "QRadioButton::indicator::checked:pressed { "
            "image: url(" + Images::radioButtonCheckedPress() + "); "
        "} "
        "QCheckBox::indicator:unchecked { "
            "image: url(" + Images::checkBoxUnchecked() + "); "
        "} "
        "QCheckBox::indicator:checked { "
            "image: url(" + Images::checkBoxChecked() + "); "
        "} "
        "QCheckBox::indicator:unchecked:hover { "
            "image: url(" + Images::checkBoxUncheckedHover() + "); "
        "} "
        "QCheckBox::indicator:checked:hover { "
            "image: url(" + Images::checkBoxCheckedHover() + "); "
        "} "
        "QCheckBox::indicator:unchecked:pressed { "
            "image: url(" + Images::checkBoxUncheckedPress() + "); "
        "} "
        "QCheckBox::indicator:checked:pressed { "
            "image: url(" + Images::checkBoxCheckedPress() + "); "
        "} "
        "QComboBox::down-arrow { "
            "image: url(" + Images::comboBoxDown() + "); "
        "} "
        "QTabBar::close-button { "
            "image: url(" + Images::closeWindow() + "); "
        "} "
        "QTableView::indicator:unchecked { "
            "image: url(" + Images::checkBoxUnchecked() + "); "
        "} "
        "QTableView::indicator:checked { "
            "image: url(" + Images::checkBoxChecked() + "); "
        "} "
        "QTableView::indicator:unchecked:hover { "
            "image: url(" + Images::checkBoxUncheckedHover() + "); "
        "} "
        "QTableView::indicator:checked:hover { "
            "image: url(" + Images::checkBoxCheckedHover() + "); "
        "} "
        "QTableView::indicator:unchecked:pressed { "
            "image: url(" + Images::checkBoxUncheckedPress() + "); "
        "} "
        "QTableView::indicator:checked:pressed { "
            "image: url(" + Images::checkBoxCheckedPress() + "); "
        "} "
        "QScrollBar::add-line:vertical { "
            "image: url(" + Images::scrollBarDown() + "); "
        "}"
        "QScrollBar::sub-line:vertical { "
            "image: url(" + Images::scrollBarUp() + "); "
        "}"
        "QScrollBar::add-line:horizontal { "
            "image: url(" + Images::scrollBarRight() + "); "
        "}"
        "QScrollBar::sub-line:horizontal { "
            "image: url(" + Images::scrollBarLeft() + "); "
        "}"
        "QGroupBox#GroupBoxFilter::title { "
            "image: url(" + Images::filter() + "); "
        "} ";
        break;
    }
    case 2:{
        break;
    }
    default: {
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
        break;
    }
    }
    return qss;
}

void Settings::syncronizeSettings() {
    _settings->sync();
}

bool createDir(const QString &aPath) {
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

#define States {
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
#define StatesEnd }

QString Images::levels(int aHundreds) {
    return QString("://levels/%1.png").arg(QString::number(aHundreds));
}

#define AchievementsDir {
#define AchievementsCheckBox {
QString Images::allAchievements() {
    return "://" + Settings::getIconsColor() + "/achievements/checkbox/all.png";
}

QString Images::reached() {
    return "://" + Settings::getIconsColor() + "/achievements/checkbox/reached.png";
}

QString Images::notReached() {
    return "://" + Settings::getIconsColor() + "/achievements/checkbox/notreached.png";
}
#define AchievementsCheckBoxEnd }

#define AchievementsCategories {
QString Images::checkVisible() {
    return "://" + Settings::getIconsColor() + "/achievements/categories/check_visible.png";
}

QString Images::uncheckVisible() {
    return "://" + Settings::getIconsColor() + "/achievements/categories/uncheck_visible.png";
}

QString Images::reverse() {
    return "://" + Settings::getIconsColor() + "/achievements/categories/reverse.png";
}

QString Images::deleteCategory() {
    return "://" + Settings::getIconsColor() + "/achievements/categories/delete_category.png";
}

QString Images::deleteAllCategories() {
    return "://" + Settings::getIconsColor() + "/achievements/categories/delete_all_categories.png";
}
#define AchievementCategoriesEnd }

QString Images::category() {
    return "://" + Settings::getIconsColor() + "/achievements/category.png";
}

QString Images::checkAll() {
    return "://" + Settings::getIconsColor() + "/achievements/check_all.png";
}

QString Images::guides() {
    return "://" + Settings::getIconsColor() + "/achievements/guides.png";
}

QString Images::guide() {
    return "://" + Settings::getIconsColor() + "/achievements/guide.png";
}
#define AchievementsDirEnd }

#define Comments {
QString Images::isComment() {
    return "://" + Settings::getIconsColor() + "/comments/isComment.png";
}

QString Images::isNotComment() {
    return "://" + Settings::getIconsColor() + "/comments/isNotComment.png";
}
#define CommentsEnd }

#define Direction {
QString Images::first() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/first.png";
}

QString Images::back() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/left.png";
}

QString Images::next() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/right.png";
}

QString Images::last() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/last.png";
}

QString Images::top() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/top.png";
}

QString Images::up() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/up.png";
}

QString Images::down() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/down.png";
}

QString Images::bottom() {
    return "://" + Settings::getIconsColor() + "/dirrection arrows/bottom.png";
}
#define DirectionEnd }

#define Favorites {
QString Images::isFavorites() {
    return "://" + Settings::getIconsColor() + "/favorites/in_favorites.png";
}

QString Images::isNotFavorites() {
    return "://" + Settings::getIconsColor() + "/favorites/favorites.png";
}
#define FavoritesEnd }

#define Hide {
QString Images::hide() {
    return "://" + Settings::getIconsColor() + "/hide/hide.png";
}

QString Images::visible() {
    return "://" + Settings::getIconsColor() + "/hide/visible.png";
}
#define HideEnd }

#define Main {
QString Images::findProfile() {
    return "://" + Settings::getIconsColor() + "/main/find_profile.png";
}

QString Images::home() {
    return "://" + Settings::getIconsColor() + "/main/home.png";
}

QString Images::left() {
    return "://" + Settings::getIconsColor() + "/main/left.png";
}

QString Images::right() {
    return "://" + Settings::getIconsColor() + "/main/right.png";
}

QString Images::settings() {
    return "://" + Settings::getIconsColor() + "/main/settings.png";
}
#define MainEnd }

#define Management {
QString Images::apply() {
    return "://" + Settings::getIconsColor() + "/management/apply.png";
}

QString Images::cancel() {
    return "://" + Settings::getIconsColor() + "/management/cancel.png";
}

QString Images::change() {
    return "://" + Settings::getIconsColor() + "/management/change.png";
}

QString Images::compare() {
    return "://" + Settings::getIconsColor() + "/management/back.png";
}

QString Images::create() {
    return "://" + Settings::getIconsColor() + "/management/create.png";
}

QString Images::deleteIcon() {
    return "://" + Settings::getIconsColor() + "/management/delete.png";
}

QString Images::deleteAll() {
    return "://" + Settings::getIconsColor() + "/management/delete_all.png";
}

QString Images::moveItem() {
    return "://" + Settings::getIconsColor() + "/management/move_item.png";
}

QString Images::moveInTree() {
    return "://" + Settings::getIconsColor() + "/management/move_in_tree.png";
}

QString Images::download() {
    return "://" + Settings::getIconsColor() + "/management/download.png";
}

QString Images::edit() {
    return "://" + Settings::getIconsColor() + "/management/edit.png";
}

QString Images::find() {
    return "://" + Settings::getIconsColor() + "/management/find.png";
}

QString Images::update() {
    return "://" + Settings::getIconsColor() + "/management/update.png";
}
#define ManagementEnd }

#define ProfileIcon {
QString Images::friends() {
    return "://" + Settings::getIconsColor() + "/profile icons/friends.png";
}

QString Images::games() {
    return "://" + Settings::getIconsColor() + "/profile icons/games.png";
}

QString Images::setHome() {
    return "://" + Settings::getIconsColor() + "/profile icons/set_home.png";
}

QString Images::statistic() {
    return "://" + Settings::getIconsColor() + "/profile icons/statistic.png";
}
#define ProfileIconEnd }

#define Widgets {
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
#define WidgetsEnd }

#define WindowButtons {
QString Images::closeWindow() {
    return "://" + Settings::getIconsColor() + "/window buttons/close_window.png";
}

QString Images::maximizeWindow() {
    return "://" + Settings::getIconsColor() + "/window buttons/maximize_window.png";
}

QString Images::minimizeWindow() {
    return "://" + Settings::getIconsColor() + "/window buttons/minimize_window.png";
}

QString Images::normalizeWindow() {
    return "://" + Settings::getIconsColor() + "/window buttons/restore_window.png";
}
#define WindowButtonsEnd }

#define Other {
QString Images::achievement() {
    return "://" + Settings::getIconsColor() + "/achievement.png";
}

QString Images::backRounded() {
    return "://" + Settings::getIconsColor() + "/back.png";
}

QString Images::exit() {
    return "://" + Settings::getIconsColor() + "/exit.png";
}

QString Images::filter() {
    return "://" + Settings::getIconsColor() + "/filter.png";
}

QString Images::goTo() {
    return "://" + Settings::getIconsColor() + "/go_to.png";
}

QString Images::group1() {
    return "://" + Settings::getIconsColor() + "/group1.png";
}

QString Images::group2() {
    return "://" + Settings::getIconsColor() + "/group2.png";
}

QString Images::link() {
    return "://" + Settings::getIconsColor() + "/link.png";
}

QString Images::profile() {
    return "://" + Settings::getIconsColor() + "/profile.png";
}
#define OtherEnd }

QString Images::missingImage() {
    return "://MissingImage.png";
}
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

QString Paths::hiddenGames(QString aSteamId) {
    return QString(documents() + "files/hide/%1%2").arg(aSteamId != "" ? aSteamId : "All", ".txt");
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

QString getToolTipText(QString aText) {
    QStringList wordsList = aText.split(" ");
    QString result;
    int currentWidth = 0;
    while (!wordsList.isEmpty()) {
        if (wordsList[0].length() + currentWidth > c_toolTipMaxWidth) {
            if (currentWidth > 0) {
                result += "\n";
                currentWidth = 0;
            } else {
                QString longWord = wordsList.takeFirst();
                while (longWord.length() > c_toolTipMaxWidth) {
                    result += longWord.left(c_toolTipMaxWidth) + "\n";
                    longWord.remove(0, c_toolTipMaxWidth);
                }
                result += longWord;
                currentWidth = longWord.length();
            }
        }
        if (currentWidth != 0) {
            result += " ";
            ++currentWidth;
        }
        currentWidth += wordsList[0].length();
        result += wordsList.takeFirst();
    }
    return result;
}
