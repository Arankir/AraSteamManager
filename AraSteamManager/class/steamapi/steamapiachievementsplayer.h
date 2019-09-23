#ifndef STEAMAPIACHIEVEMENTSPLAYER_H
#define STEAMAPIACHIEVEMENTSPLAYER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/steamapiachievementplayer.h>
#include <QObject>

class SteamAPIAchievementsPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementsPlayer(QString key, QString appid, QString id, QObject *parent = nullptr);
    SteamAPIAchievementsPlayer(QJsonDocument DocAchievements);
    SteamAPIAchievementsPlayer();
    ~SteamAPIAchievementsPlayer();
    void Set(QString key, QString appid, QString id);
    void Set(QJsonDocument DocAchievements);
    SteamAPIAchievementPlayer GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    int GetAchieved(int index) {return achievements[index].GetAchieved();}
    QDateTime GetUnlocktime(int index) {return achievements[index].GetUnlocktime();}
    QString GetAppid() {return appid;}
    QString GetStatus() {return status;}
    QString GetGamename() {return gamename;}
    int GetAchievementsCount() {return count;}
    void Update();
    void Clear();
    SteamAPIAchievementsPlayer(const SteamAPIAchievementsPlayer &);
    SteamAPIAchievementsPlayer & operator=(const SteamAPIAchievementsPlayer & friends);

signals:
    void finished(SteamAPIAchievementsPlayer*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SteamAPIAchievementPlayer> achievements;
    QString status="none";
    QString id="";
    QString appid="";
    QString key="";
    QString gamename="";
    int count=0;
};

#endif // STEAMAPIACHIEVEMENTSPLAYER_H
