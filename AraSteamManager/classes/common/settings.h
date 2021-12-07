#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QRect>
#include <QLoggingCategory>
#include <QFontDatabase>
#include <QApplication>
#include <QStandardPaths>
#include <QGradient>
#include <QLinearGradient>
#include <QRadialGradient>
#include "./theme.h"

//Q_DECLARE_LOGGING_CATEGORY(logDebug)
//Q_DECLARE_LOGGING_CATEGORY(logInfo)
//Q_DECLARE_LOGGING_CATEGORY(logFunc)
//Q_DECLARE_LOGGING_CATEGORY(logWarning)
//Q_DECLARE_LOGGING_CATEGORY(logCritical)

enum changedSettings {
    myProfile = 0x01,
    language = 0x02,
    theme = 0x04,
    saveImages = 0x08,
    visibleHiddenGame = 0x10,
    profileInfo = 0x20
};

class Settings {
public:
    static const QString c_organizationName;
    static const QString c_organizationDomain;
    static const QString c_applicationName;

    static void setMyProfile(const QString &myProfiles);
    static QString myProfile();
    static void setLanguage(const int &language);
    static int language();
    static void setTheme(const int &theme);
    static int theme();
    static void setSaveimage(const int &saveImage);
    static int saveImages();
    static void setVisibleHiddenGames(const int &visibleHiddenGames);
    static int visibleHiddenGames();
    static void setVisibleProfileInfo(const int &visibleProfileInfo);
    static int profileInfoSize();

    static void setMainWindowParams(QRect geometry);
    static QRect mainWindowGeometry();
    static void setMainWindowPos(const QPoint &pos);
    static QPoint mainWindowPos();
    static void setMainWindowIsMaximize(bool maximize);
    static bool isMainWindowMaximize();

    static void setGamesTableIconWidth(const int &width);
    static int gamesTableIconWidth();
    static void setGamesTableTitleWidth(const int &width);
    static int gamesTableTitleWidth();
    static void setGamesTableCommentWidth(const int &width);
    static int gamesTableCommentWidth();
    static void setGamesTableProgressWidth(const int &width);
    static int gamesTableProgressWidth();

    static void setFriendsTableIconWidth(const int &width);
    static int friendsTableIconWidth();
    static void setFriendsTableNameWidth(const int &width);
    static int friendsTableNameWidth();
    static void setFriendsTableAddedWidth(const int &width);
    static int friendsTableAddedWidth();
    static void setFriendsTableStatusWidth(const int &width);
    static int friendsTableStatusWidth();
    static void setFriendsTableIsOpenWidth(const int &width);
    static int friendsTableIsOpenWidth();

    static void setAchievementContainerParams(QRect geometry);
    static QRect achievementContainerGeometry();
    static QPoint achievementContainerPos();

    static void setAchievementsTableIconWidth(const int &width);
    static int achievementsTableIconWidth();
    static void setAchievementsTableTitleWidth(const int &width);
    static int achievementsTableTitleWidth();
    static void setAchievementsTableDescriptionWidth(const int &width);
    static int achievementsTableDescriptionWidth();
    static void setAchievementsTableCommentWidth(const int &width);
    static int achievementsTableCommentWidth();
    static void setAchievementsTablePercentWidth(const int &width);
    static int achievementsTablePercentWidth();
    static void setAchievementsTableAchievedWidth(const int &width);
    static int achievementsTableAchievedWidth();

    static void setAchievementsCompareIconVisible(const int &width);
    static int achievementsCompareIconVisible();
    static void setAchievementsCompareTitleVisible(const int &width);
    static int achievementsCompareTitleVisible();
    static void setAchievementsCompareDescriptionVisible(const int &width);
    static int achievementsCompareDescriptionVisible();
    static void setAchievementsComparePercentVisible(const int &width);
    static int achievementsComparePercentVisible();

//    static QString iconsColor();
//    static QString defaultFont();
//    static QString qssTheme();

    static void syncronizeSettings();

    static const QString dateTimeFormat();
    static const QString dateFormat();
    static const QString dateTimeFormatShort();
private:
    static QSettings *_settings;
//    static QString defaultFontPath();
};

class Paths {
public:
    static QString documents();
    static QString temp();
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

#endif // SETTINGS_H
