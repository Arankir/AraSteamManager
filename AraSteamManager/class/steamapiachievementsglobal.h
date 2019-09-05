#ifndef STEAMAPIACHIEVEMENTSGLOBAL_H
#define STEAMAPIACHIEVEMENTSGLOBAL_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapiachievementglobal.h>
#include <QObject>

class SteamAPIAchievementsGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementsGlobal(QString key, QString appid, QString id, QObject *parent = nullptr);
    SteamAPIAchievementsGlobal(QJsonDocument DocAchievements);
    SteamAPIAchievementsGlobal();
    ~SteamAPIAchievementsGlobal();
    void Set(QString key, QString appid, QString language);
    void Set(QJsonDocument DocAchievements);
    SteamAPIAchievementGlobal GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    int GetDefaultvalue(int index) {return achievements[index].GetDefaultvalue();}
    QString GetDisplayname(int index) {return achievements[index].GetDisplayname();}
    int GetHidden(int index) {return achievements[index].GetHidden();}
    QString GetDescription(int index) {return achievements[index].GetDescription();}
    QString GetIcon(int index) {return achievements[index].GetIcon();}
    QString GetIcongray(int index) {return achievements[index].GetIcongray();}
    QString GetAppid() {return appid;}
    QString GetStatus() {return status;}
    QString GetGamename() {return gamename;}
    QString GetGameversion() {return gameversion;}
    int GetAchievementsCount() {return count;}
    void Update();
    void Clear();
    SteamAPIAchievementsGlobal(const SteamAPIAchievementsGlobal &);
    SteamAPIAchievementsGlobal & operator=(const SteamAPIAchievementsGlobal & friends);

signals:
    void finished(SteamAPIAchievementsGlobal*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SteamAPIAchievementGlobal> achievements;
    QString status="none";
    QString language="english";
    QString appid="";
    QString key="";
    QString gamename="";
    QString gameversion="";
    int count=0;
};

#endif // STEAMAPIACHIEVEMENTSGLOBAL_H
