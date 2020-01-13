#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <class/statusvalue.h>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    bool SetMyProfile(QString MyProfiles);
    bool SetLanguage(int Language);
    bool SetTheme(int Theme);
    bool SetSaveimage(int SaveImage);
    bool SetVisibleHiddenGames(int VisibleHiddenGames);
    void SetDefault();
    QString GetMyProfile() {return _myProfile;}
    int GetLanguage() {return _language;}
    int GetTheme() {return _theme;}
    int GetSaveimages() {return _saveImages;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetVisibleHiddenGames() {return _visibleHiddenGames;}
    QString GetKey() {return _key;}
    bool CreateFile(QString path);

signals:

public slots:

private:
    QString _myProfile="";
    int _language=1;
    int _theme=1;
    int _saveImages=0;
    int _visibleHiddenGames=0;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _key="3826BF60403D15613B4B0381DAB7A7BD";
};

#endif // SETTINGS_H
