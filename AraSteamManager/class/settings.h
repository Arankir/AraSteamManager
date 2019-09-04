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
    QString GetMyProfile();
    int GetLanguage();
    int GetTheme();
    int GetSaveimages();
    QString GetStatus();
    bool SetMyProfile(QString MyProfiles);
    bool SetLanguage(int Language);
    bool SetTheme(int Theme);
    bool SetSaveimage(int SaveImage);
    void SetDefault();

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
