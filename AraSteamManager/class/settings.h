#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
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
    void SetDefault();
    QString GetMyProfile() {return MyProfile;}
    int GetLanguage() {return language;}
    int GetTheme() {return theme;}
    int GetSaveimages() {return SaveImages;}
    QString GetStatus() {return status;}
    QStringList GetWords(QString form);

signals:

public slots:

private:
    QString MyProfile="";
    int language=1;
    int theme=1;
    int SaveImages=0;
    QString status="none";
};

#endif // SETTINGS_H
