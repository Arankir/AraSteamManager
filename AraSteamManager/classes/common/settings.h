#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDebug>
#include <QSettings>
//#include <QLoggingCategory>

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

    Q_PROPERTY(QString myProfile READ myProfile WRITE setMyProfile)
    Q_PROPERTY(int language READ language WRITE setLanguage)
    Q_PROPERTY(int theme READ theme WRITE setTheme)
    Q_PROPERTY(int saveImages READ saveImages WRITE setSaveimage)
    Q_PROPERTY(int visibleHiddenGames READ visibleHiddenGames WRITE setVisibleHiddenGames)
    Q_PROPERTY(int profileInfoSize READ profileInfoSize WRITE setVisibleProfileInfo)

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

    Q_PROPERTY(QByteArray mainWindowState READ mainWindowState WRITE setMainWindowState)
    Q_PROPERTY(QByteArray mainWindowGeometry READ mainWindowGeometry WRITE setMainWindowGeometry)

    static void setMainWindowState(const QByteArray &geometry);
    static QByteArray mainWindowState();
    static void setMainWindowGeometry(const QByteArray &geometry);
    static QByteArray mainWindowGeometry();

    Q_PROPERTY(QByteArray achievementContainerState READ achievementContainerState WRITE setAchievementContainerState)
    Q_PROPERTY(QByteArray achievementContainerGeometry READ achievementContainerGeometry WRITE setAchievementContainerGeometry)

    static void setAchievementContainerState(const QByteArray &geometry);
    static QByteArray achievementContainerState();
    static void setAchievementContainerGeometry(const QByteArray &geometry);
    static QByteArray achievementContainerGeometry();

    Q_PROPERTY(QString dateTimeFormat READ dateTimeFormat)
    Q_PROPERTY(QString dateFormat READ dateFormat)
    Q_PROPERTY(QString dateTimeFormatShort READ dateTimeFormatShort)

    static const QString dateTimeFormat();
    static const QString dateFormat();
    static const QString dateTimeFormatShort();

    static void syncronizeSettings();

private:
    static QSettings *settings_;
};

class Paths {
public:
    static QString documents();
    static QString temp();
    static QString categories(QString gameId = "");
    static QString favorites(QString type = "");
    static QString hiddenGames(QString steamId = "");
    static QString groupGames(QString profileId = "");
    static QString imagesProfiles(const QString &url, const QString &aFormat = "jpg");
    static QString imagesAchievements(const QString &gameId, const QString &url = "");
    static QString imagesGames(const QString &url);
    static QString commentsGames(const QString &profileId);
    static QString commentsAchievements(const QString &aProfileId = "");
};

#endif // SETTINGS_H
