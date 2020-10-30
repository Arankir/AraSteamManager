#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include <QRect>
#include <QLoggingCategory>
#include <QFontDatabase>

Q_DECLARE_LOGGING_CATEGORY(logDebug)
Q_DECLARE_LOGGING_CATEGORY(logInfo)
Q_DECLARE_LOGGING_CATEGORY(logFunc)
Q_DECLARE_LOGGING_CATEGORY(logWarning)
Q_DECLARE_LOGGING_CATEGORY(logCritical)

class Settings : public QObject {
    Q_OBJECT
public:
    static void setMyProfile(const QString &myProfiles);
    static void setLanguage(int language);
    static void setTheme(int theme);
    static void setSaveimage(int saveImage);
    static void setVisibleHiddenGames(int visibleHiddenGames);
    static void setVisibleProfileInfo(int visibleProfileInfo);
    static void setMaximumTableRows(int rows);

    static QString getMyProfile();
    static int getLanguage();
    static int getTheme();
    static QString getIconsColor();
    static int getSaveImages();
    static int getVisibleHiddenGames();
    static int getProfileInfoSize();
    static int getMaximumTableRows();

    static void setMainWindowParams(QRect geometry);
    static void setMainWindowPos(QPoint pos);
    static void setMainWindowGeometry(QSize size);
    static void setMainWindowMaximize(bool maximize);

    static void setAchievementContainerParams(QRect geometry);

    static QRect getMainWindowGeometry();
    static QPoint getMainWindowPos();
    static bool getMainWindowMaximize();

    static QRect getAchievementContainerGeometry();
    static QPoint getAchievementContainerPos();

    static QString getFontDefaultName();

    static QString const getKey();
    static bool createDir(const QString &path);
    static void syncronizeSettings();

signals:

private:
    static QSettings *_settings;

    static const QString c_language;
    static const QString c_theme;
    static const QString c_saveImage;
    static const QString c_myProfile;
    static const QString c_visibleHiddenGames;
    static const QString c_ProfileInfoSize;
    static const QString c_MaxTableRows;

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

class Paths : public QObject {
public:
    static QString defaultFont();
    static QString categories(QString gameId = "");
    static QString favorites(QString type = "");
    static QString hiddenGames(QString gameID = "");
    static QString groupGames(QString profileId = "");
    static QString imagesProfiles(const QString &url);
    static QString imagesAchievements(const QString &gameId, const QString &url);
    static QString imagesGames(const QString &url);
    static QString commentsGames(const QString &profileId);
    static QString commentsAchievements(const QString &aProfileId = "");
};

class Images : public QObject {
public:
    static QString loading();
    static QString logo();

    static QString stateBlue();
    static QString stateGreen();
    static QString stateRed();
    static QString stateYellow();

    static QString allAchievements();

    static QString left();
    static QString right();
    static QString up();
    static QString down();

    static QString checkAll();
    static QString checkVisible();
    static QString uncheckVisible();
    static QString reverse();

    static QString maximizeWindow();
    static QString minimizeWindow();
    static QString normalizeWindow();

    static QString reached();
    static QString notReached();

    static QString isFavorites();
    static QString isNotFavorites();

    static QString hide();
    static QString unhide();

    static QString top();
    static QString bottom();

    static QString home();
    static QString setHome();

    static QString change();
    static QString create();

    static QString edit();
    static QString update();

    static QString apply();
    static QString cancel();

    static QString back();
    static QString exit();
    static QString closeWindow();

    static QString compare();
    static QString deleteAll();
    static QString filter();
    static QString find();
    static QString findProfile();
    static QString friends();
    static QString games();
    static QString goTo();
    static QString link();
    static QString profile();
    static QString settings();
    static QString statistic();
    static QString deleteIcon();

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

    static QString isComment();
    static QString isNotComment();

    static QString achievement();
    static QString download();
    static QString visible();
    static QString category();
    static QString group1();
    static QString group2();

    static QString missingImage();
};

#endif // SETTINGS_H
