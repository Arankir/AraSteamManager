#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>

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
    QString GetMyProfile() {return myProfile;}
    int GetLanguage() {return language;}
    int GetTheme() {return theme;}
    int GetSaveimages() {return SaveImages;}
    QString GetStatus() {return status;}
    int GetVisibleHiddenGames() {return visibleHiddenGames;}
    QStringList GetWords(QString form);
    bool CreateFile(QString path);

signals:

public slots:

private:
    QString myProfile="";
    int language=1;
    int theme=1;
    int SaveImages=0;
    int visibleHiddenGames=0;
    QString status="none";
};

#endif // SETTINGS_H
