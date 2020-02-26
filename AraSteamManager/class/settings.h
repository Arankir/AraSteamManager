#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>

const QString c_language="Settings/Language";
const QString c_theme="Settings/Theme";
const QString c_saveImage="Settings/SaveImages";
const QString c_myProfile="Settings/MyProfile";
const QString c_visibleHiddenGames="Settings/VisibleHiddenGames";
const QString c_visibleProfileInfo="Settings/VisibleProfileInfo";

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    void SetMyProfile(QString MyProfiles);
    void SetLanguage(int language);
    void SetTheme(int theme);
    void SetSaveimage(int saveImage);
    void SetVisibleHiddenGames(int visibleHiddenGames);
    void SetVisibleProfileInfo(bool visibleProfileInfo);
    QString GetMyProfile() {return _settings->value(c_myProfile).toString();}
    int GetLanguage() {return _settings->value(c_language).toInt();}
    int GetTheme() {return _settings->value(c_theme).toInt();}
    int GetSaveImages() {return _settings->value(c_saveImage).toInt();}
    int GetVisibleHiddenGames() {return _settings->value(c_visibleHiddenGames).toInt();}
    bool GetVisibleProfileInfo() {return _settings->value(c_visibleProfileInfo).toBool();}
    QString GetKey() {return _key;}
    bool CreateFile(QString path);
    void SyncronizeSettings();
    const QString _pathSettings="files/settings.txt";
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

    QString _key="3826BF60403D15613B4B0381DAB7A7BD";
};

#endif // SETTINGS_H
