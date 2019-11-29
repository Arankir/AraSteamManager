#ifndef SACHIEVEMENTSPLAYER_H
#define SACHIEVEMENTSPLAYER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievementplayer.h>
#include <QObject>

class SAchievementsPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPlayer(QString key, QString appid, QString id, QObject *parent = nullptr);
    SAchievementsPlayer(QJsonDocument DocAchievements);
    SAchievementsPlayer();
    ~SAchievementsPlayer();
    void Set(QString key, QString appid, QString id);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { achievements.remove(index); count--;}
    SAchievementPlayer GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    int GetAchieved(int index) {return achievements[index].GetAchieved();}
    QDateTime GetUnlocktime(int index) {return achievements[index].GetUnlocktime();}
    QString GetAppid() {return appid;}
    QString GetStatus() {return status;}
    QString GetGamename() {return gamename;}
    int GetAchievementsCount() {return count;}
    void Update();
    void Clear();
    SAchievementsPlayer(const SAchievementsPlayer &);
    SAchievementsPlayer & operator=(const SAchievementsPlayer & friends);

signals:
    void finished(SAchievementsPlayer);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SAchievementPlayer> achievements;
    QString status="none";
    QString id="";
    QString appid="";
    QString key="";
    QString gamename="";
    int count=0;
};

#endif // SACHIEVEMENTSPLAYER_H
