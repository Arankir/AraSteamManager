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
#include <class/steamapiachievementplayer.h>
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
    SteamAPIAchievementPlayer GetAchievementInfo(int index);
    QString GetApiname(int index);
    int GetAchieved(int index);
    QDateTime GetUnlocktime(int index);
    QString GetAppid();
    QString GetStatus();
    QString GetGamename();
    int GetAchievementsCount();
    void Update();
    SteamAPIAchievementsPlayer(const SteamAPIAchievementsPlayer &);
    SteamAPIAchievementsPlayer & operator=(const SteamAPIAchievementsPlayer & friends);
    void Clear();

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
