#ifndef STEAMAPIACHIEVEMENTSPERCENTAGE_H
#define STEAMAPIACHIEVEMENTSPERCENTAGE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapiachievementpercentage.h>
#include <QObject>

class SteamAPIAchievementsPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementsPercentage(QString key, QString appid, QObject *parent = nullptr);
    SteamAPIAchievementsPercentage(QJsonDocument DocAchievements);
    SteamAPIAchievementsPercentage();
    ~SteamAPIAchievementsPercentage();
    void Set(QString key, QString appid);
    void Set(QJsonDocument DocAchievements);
    SteamAPIAchievementPercentage GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    double GetPercent(int index) {return achievements[index].GetPercent();}
    QString GetAppid() {return appid;}
    int GetAchievementsCount() {return count;}
    QString GetStatus() {return status;}
    void Update();
    void Clear();
    SteamAPIAchievementsPercentage(const SteamAPIAchievementsPercentage &);
    SteamAPIAchievementsPercentage & operator=(const SteamAPIAchievementsPercentage & friends);

signals:
    void finished(SteamAPIAchievementsPercentage*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SteamAPIAchievementPercentage> achievements;
    QString status="none";
    QString appid="";
    QString key="";
    int count=0;
};

#endif // STEAMAPIACHIEVEMENTSPERCENTAGE_H
