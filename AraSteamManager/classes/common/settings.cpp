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

QString Settings::iconsColor() {
    switch(theme()) {
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
    static int id = QFontDatabase::addApplicationFont(Paths::defaultFont());
    static QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    return family;
}

QString Settings::qssTheme() {
    QString qss;
    switch(theme()) {
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
    }
    case 1:{
        QFile qssFile(":/theme/blueTheme.qss");
        qssFile.open(QFile::ReadOnly);
        qss = qssFile.readAll();
        break;
    }
    case 2:{
        break;
    }
    case 3:{
        QFile qssFile(":/theme/blackTheme.qss");
        qssFile.open(QFile::ReadOnly);
        qss = qssFile.readAll();
        break;
    }
    }
    QFile qssFile(":/theme/globalTheme.qss");
    qssFile.open(QFile::ReadOnly);
    qss += qssFile.readAll();
    qss += " "
    "QWidget, QStandardItem, QAbstractItemModel, QLabel { "
        "font: " + Settings::defaultFont() + "; "
    "} ";
    return qss;
}

void Settings::syncronizeSettings() {
    _settings->sync();
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

QString Images::levels(const int &aHundreds) {
    return QString("://levels/%1.png").arg(QString::number(aHundreds));
}

#define AchievementsDir {
#define AchievementsCheckBox {
QString Images::allAchievements() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/all.png";
}

QString Images::reached() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/reached.png";
}

QString Images::notReached() {
    return "://" + Settings::iconsColor() + "/achievements/checkbox/notreached.png";
}
#define AchievementsCheckBoxEnd }

#define AchievementsCategories {
QString Images::checkVisible() {
    return "://" + Settings::iconsColor() + "/achievements/categories/check_visible.png";
}

QString Images::uncheckVisible() {
    return "://" + Settings::iconsColor() + "/achievements/categories/uncheck_visible.png";
}

QString Images::reverse() {
    return "://" + Settings::iconsColor() + "/achievements/categories/reverse.png";
}

QString Images::deleteCategory() {
    return "://" + Settings::iconsColor() + "/achievements/categories/delete_category.png";
}

QString Images::deleteAllCategories() {
    return "://" + Settings::iconsColor() + "/achievements/categories/delete_all_categories.png";
}
#define AchievementCategoriesEnd }

QString Images::category() {
    return "://" + Settings::iconsColor() + "/achievements/category.png";
}

QString Images::checkAll() {
    return "://" + Settings::iconsColor() + "/achievements/check_all.png";
}

QString Images::guides() {
    return "://" + Settings::iconsColor() + "/achievements/guides.png";
}

QString Images::guide() {
    return "://" + Settings::iconsColor() + "/achievements/guide.png";
}
#define AchievementsDirEnd }

#define Comments {
QString Images::isComment() {
    return "://" + Settings::iconsColor() + "/comments/isComment.png";
}

QString Images::isNotComment() {
    return "://" + Settings::iconsColor() + "/comments/isNotComment.png";
}
#define CommentsEnd }

#define Direction {
QString Images::first() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/first.png";
}

QString Images::back() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/left.png";
}

QString Images::next() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/right.png";
}

QString Images::last() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/last.png";
}

QString Images::top() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/top.png";
}

QString Images::up() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/up.png";
}

QString Images::down() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/down.png";
}

QString Images::bottom() {
    return "://" + Settings::iconsColor() + "/dirrection arrows/bottom.png";
}
#define DirectionEnd }

#define Favorites {
QString Images::isFavorites() {
    return "://" + Settings::iconsColor() + "/favorites/in_favorites.png";
}

QString Images::isNotFavorites() {
    return "://" + Settings::iconsColor() + "/favorites/favorites.png";
}
#define FavoritesEnd }

#define Hide {
QString Images::hide() {
    return "://" + Settings::iconsColor() + "/hide/hide.png";
}

QString Images::visible() {
    return "://" + Settings::iconsColor() + "/hide/visible.png";
}
#define HideEnd }

#define Main {
QString Images::findProfile() {
    return "://" + Settings::iconsColor() + "/main/find_profile.png";
}

QString Images::home() {
    return "://" + Settings::iconsColor() + "/main/home.png";
}

QString Images::left() {
    return "://" + Settings::iconsColor() + "/main/left.png";
}

QString Images::right() {
    return "://" + Settings::iconsColor() + "/main/right.png";
}

QString Images::settings() {
    return "://" + Settings::iconsColor() + "/main/settings.png";
}
#define MainEnd }

#define Management {
QString Images::apply() {
    return "://" + Settings::iconsColor() + "/management/apply.png";
}

QString Images::cancel() {
    return "://" + Settings::iconsColor() + "/management/cancel.png";
}

QString Images::change() {
    return "://" + Settings::iconsColor() + "/management/change.png";
}

QString Images::compare() {
    return "://" + Settings::iconsColor() + "/management/back.png";
}

QString Images::create() {
    return "://" + Settings::iconsColor() + "/management/create.png";
}

QString Images::deleteIcon() {
    return "://" + Settings::iconsColor() + "/management/delete.png";
}

QString Images::deleteAll() {
    return "://" + Settings::iconsColor() + "/management/delete_all.png";
}

QString Images::moveItem() {
    return "://" + Settings::iconsColor() + "/management/move_item.png";
}

QString Images::moveInTree() {
    return "://" + Settings::iconsColor() + "/management/move_in_tree.png";
}

QString Images::download() {
    return "://" + Settings::iconsColor() + "/management/download.png";
}

QString Images::edit() {
    return "://" + Settings::iconsColor() + "/management/edit.png";
}

QString Images::find() {
    return "://" + Settings::iconsColor() + "/management/find.png";
}

QString Images::update() {
    return "://" + Settings::iconsColor() + "/management/update.png";
}
#define ManagementEnd }

#define ProfileIcon {
QString Images::friends() {
    return "://" + Settings::iconsColor() + "/profile icons/friends.png";
}

QString Images::games() {
    return "://" + Settings::iconsColor() + "/profile icons/games.png";
}

QString Images::setHome() {
    return "://" + Settings::iconsColor() + "/profile icons/set_home.png";
}

QString Images::statistic() {
    return "://" + Settings::iconsColor() + "/profile icons/statistic.png";
}
#define ProfileIconEnd }

#define Widgets {
QString Images::checkBoxChecked() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked.png";
}

QString Images::checkBoxCheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked_hover.png";
}

QString Images::checkBoxCheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_checked_press.png";
}

QString Images::checkBoxUnchecked() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked.png";
}

QString Images::checkBoxUncheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked_hover.png";
}

QString Images::checkBoxUncheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/checkbox_unchecked_press.png";
}

QString Images::radioButtonChecked() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked.png";
}

QString Images::radioButtonCheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked_hover.png";
}

QString Images::radioButtonCheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_checked_press.png";
}

QString Images::radioButtonUnchecked() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked.png";
}

QString Images::radioButtonUncheckedHover() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked_hover.png";
}

QString Images::radioButtonUncheckedPress() {
    return "://" + Settings::iconsColor() + "/widgets/radiobutton_unchecked_press.png";
}

QString Images::comboBoxDown() {
    return "://" + Settings::iconsColor() + "/widgets/combobox_down.png";
}

QString Images::scrollBarUp() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_up.png";
}

QString Images::scrollBarDown() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_down.png";
}

QString Images::scrollBarLeft() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_left.png";
}

QString Images::scrollBarRight() {
    return "://" + Settings::iconsColor() + "/widgets/scrollbar_right.png";
}
#define WidgetsEnd }

#define WindowButtons {
QString Images::closeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/close_window.png";
}

QString Images::maximizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/maximize_window.png";
}

QString Images::minimizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/minimize_window.png";
}

QString Images::normalizeWindow() {
    return "://" + Settings::iconsColor() + "/window buttons/restore_window.png";
}
#define WindowButtonsEnd }

#define Other {
QString Images::achievement() {
    return "://" + Settings::iconsColor() + "/achievement.png";
}

QString Images::backRounded() {
    return "://" + Settings::iconsColor() + "/back.png";
}

QString Images::exit() {
    return "://" + Settings::iconsColor() + "/exit.png";
}

QString Images::filter() {
    return "://" + Settings::iconsColor() + "/filter.png";
}

QString Images::goTo() {
    return "://" + Settings::iconsColor() + "/go_to.png";
}

QString Images::group1() {
    return "://" + Settings::iconsColor() + "/group1.png";
}

QString Images::group2() {
    return "://" + Settings::iconsColor() + "/group2.png";
}

QString Images::link() {
    return "://" + Settings::iconsColor() + "/link.png";
}

QString Images::profile() {
    return "://" + Settings::iconsColor() + "/profile.png";
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
    return "://JosefinSans-Italic-VariableFont_wght.ttf";
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
    return QString(documents() + "files/comments/games/%1%2").arg(aProfileId, ".json");
}

QString Paths::commentsAchievements(const QString &aProfileId) {
    return QString(documents() + "files/comments/achievements/%1%2").arg(aProfileId, aProfileId != "" ? ".json" : "");
}
#define PathsEnd }
