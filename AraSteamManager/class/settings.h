#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include <QScreen>

class Settings : public QObject
{
    const QString c_language="Settings/Language";
    const QString c_theme="Settings/Theme";
    const QString c_saveImage="Settings/SaveImages";
    const QString c_myProfile="Settings/MyProfile";
    const QString c_visibleHiddenGames="Settings/VisibleHiddenGames";
    const QString c_visibleProfileInfo="Settings/VisibleProfileInfo";

    const QString c_mainWindowHeight="MainWindow/Height";
    const QString c_mainWindowWidth="MainWindow/Width";
    const QString c_mainWindowX="MainWindow/X";
    const QString c_mainWindowY="MainWindow/Y";
    const QString c_mainWindowPercentX="MainWindow/PercentX";
    const QString c_mainWindowPercentY="MainWindow/PercentY";

    const QString c_achievementContainerHeight="AchievementContainer/Height";
    const QString c_achievementContainerWidth="AchievementContainer/Width";
    const QString c_achievementContainerX="AchievementContainer/X";
    const QString c_achievementContainerY="AchievementContainer/Y";
    const QString c_achievementContainerPercentX="AchievementContainer/PercentX";
    const QString c_achievementContainerPercentY="AchievementContainer/PercentY";

    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    explicit Settings(QRect geometry, QObject *parent = nullptr);
    void CustomGeometry(QRect geometry);
    void SetMyProfile(QString a_myProfiles) {return _settings->setValue(c_myProfile,a_myProfiles);}
    void SetLanguage(int a_language) {return _settings->setValue(c_language,a_language);}
    void SetTheme(int a_theme) {return _settings->setValue(c_theme,a_theme);}
    void SetSaveimage(int a_saveImage) {return _settings->setValue(c_saveImage,a_saveImage);}
    void SetVisibleHiddenGames(int a_visibleHiddenGames) {return _settings->setValue(c_visibleHiddenGames,a_visibleHiddenGames);}
    void SetVisibleProfileInfo(bool a_visibleProfileInfo) {return _settings->setValue(c_visibleProfileInfo,a_visibleProfileInfo);}

    void SetMainWindowParams(QRect geometry);
    void SetMainWindowPos(QPoint pos);
    void SetMainWindowGeometry(QSize size);

    void SetAchievementContainerParams(QRect geometry);

    QString GetMyProfile() {return _settings->value(c_myProfile,"none").toString();}
    int GetLanguage() {return _settings->value(c_language,1).toInt();}
    int GetTheme() {return _settings->value(c_theme,1).toInt();}
    int GetSaveImages() {return _settings->value(c_saveImage,0).toInt();}
    int GetVisibleHiddenGames() {return _settings->value(c_visibleHiddenGames,0).toInt();}
    bool GetVisibleProfileInfo() {return _settings->value(c_visibleProfileInfo,true).toBool();}

    QRect GetMainWindowGeometry() {return (QRect(0,0,_settings->value(c_mainWindowWidth,623).toInt(),_settings->value(c_mainWindowHeight,479).toInt()));}
    QPoint GetMainWindowPos() {return (QPoint(_settings->value(c_mainWindowX,100).toInt(),_settings->value(c_mainWindowY,100).toInt()));}
    QPoint GetMainWindowPercentPos() {return (QPoint(_settings->value(c_mainWindowPercentX,0).toInt(),_settings->value(c_mainWindowPercentY,0).toInt()));}

    QRect GetAchievementContainerGeometry() {return (QRect(0,0,_settings->value(c_achievementContainerWidth,623).toInt(),_settings->value(c_achievementContainerHeight,479).toInt()));}
    QPoint GetAchievementContainerPos() {return (QPoint(_settings->value(c_achievementContainerX,100).toInt(),_settings->value(c_achievementContainerY,100).toInt()));}
    QPoint GetAchievementContainerPercentPos() {return (QPoint(_settings->value(c_achievementContainerPercentX,0).toInt(),_settings->value(c_achievementContainerPercentY,0).toInt()));}

    QString GetKey() {return _key;}
    bool CreateFile(QString path);
    void SyncronizeSettings();
    const QString _pathImagesAchievements="images/achievements/";// /номер игры/url.jpg
    const QString _pathImagesIconGames="images/icon_games/";// /url.jpg
    const QString _pathImagesProfiles="images/profiles/";// /url.jpg
    const QString _pathCategories="files/categories/";// /номер игры.json
    const QString _pathFavorites="files/favorites/";// /тип.json
    const QString _pathHide="files/hide/";// /номер игры.json

signals:

public slots:

private:
    QSettings *_settings;
    QRect _screen;
    QString _key="3826BF60403D15613B4B0381DAB7A7BD";
};

#endif // SETTINGS_H
