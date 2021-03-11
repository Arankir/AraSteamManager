#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QRect>
#include <QLoggingCategory>
#include <QFontDatabase>
#include <QApplication>
#include <QStandardPaths>

//Q_DECLARE_LOGGING_CATEGORY(logDebug)
//Q_DECLARE_LOGGING_CATEGORY(logInfo)
//Q_DECLARE_LOGGING_CATEGORY(logFunc)
//Q_DECLARE_LOGGING_CATEGORY(logWarning)
//Q_DECLARE_LOGGING_CATEGORY(logCritical)

QString textToToolTip(QString text);
bool createDir(const QString &path);

class Settings {
public:
    static const QString c_organizationName;
    static const QString c_organizationDomain;
    static const QString c_applicationName;

    static void setMyProfile(const QString &myProfiles);
    static void setLanguage(int language);
    static void setTheme(int theme);
    static void setSaveimage(int saveImage);
    static void setVisibleHiddenGames(int visibleHiddenGames);
    static void setVisibleProfileInfo(int visibleProfileInfo);
    //static void setMaximumTableRows(int rows);

    static QString myProfile();
    static int language();
    static int theme();
    static QString iconsColor();
    static int saveImages();
    static int visibleHiddenGames();
    static int profileInfoSize();
    //static int getMaximumTableRows();

    static void setMainWindowParams(QRect geometry);
    static void setMainWindowPos(QPoint pos);
    static void setMainWindowGeometry(QSize size);
    static void setMainWindowIsMaximize(bool maximize);

    static void setAchievementContainerParams(QRect geometry);

    static QRect mainWindowGeometry();
    static QPoint mainWindowPos();
    static bool isMainWindowMaximize();

    static QRect achievementContainerGeometry();
    static QPoint achievementContainerPos();

    static QString defaultFont();
    static QString qssTheme();

    static void syncronizeSettings();

private:
    static QSettings *_settings;

    static const QString c_language;
    static const QString c_theme;
    static const QString c_saveImage;
    static const QString c_myProfile;
    static const QString c_visibleHiddenGames;
    static const QString c_ProfileInfoSize;
    //static const QString c_MaxTableRows;

    static const QString c_mainWindowHeight;
    static const QString c_mainWindowWidth;
    static const QString c_mainWindowX;
    static const QString c_mainWindowY;
    static const QString c_mainWindowMaximize;

    static const QString c_achievementContainerHeight;
    static const QString c_achievementContainerWidth;
    static const QString c_achievementContainerX;
    static const QString c_achievementContainerY;
    static const QString c_achievementContainerMaximize;

};

class Paths {
public:
    static QString documents();
    static QString temp();
    static QString defaultFont();
    static QString categories(QString gameId = "");
    static QString favorites(QString type = "");
    static QString hiddenGames(QString steamId = "");
    static QString groupGames(QString profileId = "");
    static QString imagesProfiles(const QString &url);
    static QString imagesAchievements(const QString &gameId, const QString &url = "");
    static QString imagesGames(const QString &url);
    static QString commentsGames(const QString &profileId);
    static QString commentsAchievements(const QString &aProfileId = "");
};

class Images {
public:
    static QString loading();
    static QString logo();

    //States
    static QString stateBlue();
    static QString stateGreen();
    static QString stateRed();
    static QString stateYellow();

    static QString levels(int hundreds);

    //Achievements Checkbox
    static QString allAchievements();
    static QString reached();
    static QString notReached();

    //Achievements Categories
    static QString checkVisible();
    static QString uncheckVisible();
    static QString reverse();
    static QString deleteCategory();
    static QString deleteAllCategories();

    //Achievements
    static QString category();
    static QString checkAll();
    static QString guides();
    static QString guide();

    //Comments
    static QString isComment();
    static QString isNotComment();

    //Dirrection arrows
    static QString first();
    static QString back();
    static QString next();
    static QString last();
    static QString top();
    static QString bottom();
    static QString up();
    static QString down();

    //Favorites
    static QString isFavorites();
    static QString isNotFavorites();

    //Hide
    static QString hide();
    static QString visible();

    //Main
    static QString findProfile();
    static QString home();
    static QString left();
    static QString right();
    static QString settings();

    //Management
    static QString apply();
    static QString cancel();
    static QString change();
    static QString compare();
    static QString create();
    static QString deleteIcon();
    static QString deleteAll();
    static QString moveItem();
    static QString moveInTree();
    static QString download();
    static QString edit();
    static QString find();
    static QString update();

    //Profile icon
    static QString friends();
    static QString games();
    static QString setHome();
    static QString statistic();

    //Window buttons
    static QString closeWindow();
    static QString maximizeWindow();
    static QString minimizeWindow();
    static QString normalizeWindow();

    //Other
    static QString achievement();
    static QString backRounded();
    static QString exit();
    static QString filter();
    static QString goTo();
    static QString group1();
    static QString group2();
    static QString link();
    static QString profile();

    //Widgets
    static QString checkBoxChecked();
    static QString checkBoxCheckedHover();
    static QString checkBoxCheckedPress();

    static QString checkBoxUnchecked();
    static QString checkBoxUncheckedHover();
    static QString checkBoxUncheckedPress();

    static QString radioButtonChecked();
    static QString radioButtonCheckedHover();
    static QString radioButtonCheckedPress();

    static QString radioButtonUnchecked();
    static QString radioButtonUncheckedHover();
    static QString radioButtonUncheckedPress();

    static QString comboBoxDown();

    static QString scrollBarUp();
    static QString scrollBarDown();
    static QString scrollBarLeft();
    static QString scrollBarRight();

    static QString missingImage();
};

#endif // SETTINGS_H
