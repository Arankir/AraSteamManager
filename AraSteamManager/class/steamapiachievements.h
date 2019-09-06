#ifndef STEAMAPIACHIEVEMENTS_H
#define STEAMAPIACHIEVEMENTS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapiachievement.h>
#include <class/steamapiachievementsglobal.h>
#include <class/steamapiachievementsplayer.h>
#include <class/steamapiachievementspercentage.h>
#include <QObject>

class SteamAPIAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievements(QString key, QString appid, QString id, QString language, QObject *parent = nullptr);
    SteamAPIAchievements(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player, SteamAPIAchievementsPercentage Percent);
    SteamAPIAchievements();
    ~SteamAPIAchievements();
    void Set(QString key, QString appid, QString id, QString language);
    void Set(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player, SteamAPIAchievementsPercentage Percent);
    void Set(SteamAPIAchievementsPlayer Player);
    void Set(SteamAPIAchievementsGlobal Global);
    void Set(SteamAPIAchievementsPercentage Percent);
    SteamAPIAchievement GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    int GetDefaultvalue(int index) {return achievements[index].GetDefaultvalue();}
    QString GetDisplayname(int index) {return achievements[index].GetDisplayname();}
    int GetHidden(int index) {return achievements[index].GetHidden();}
    QString GetDescription(int index) {return achievements[index].GetDescription();}
    QString GetIcon(int index) {return achievements[index].GetIcon();}
    QString GetIcongray(int index) {return achievements[index].GetIcongray();}
    int GetAchieved(int index) {return achievements[index].GetAchieved();}
    QDateTime GetUnlocktime(int index) {return achievements[index].GetUnlocktime();}
    double GetPercent(int index) {return achievements[index].GetPercent();}
    QString GetStatusGlobal() {return statusglobal;}
    QString GetStatusPlayer() {return statusplayer;}
    QString GetStatusPercent() {return statuspercent;}
    QString GetAppid() {return appid;}
    QString GetGamename() {return gamename;}
    QString GetGameversion() {return gameversion;}
    int GetAchievementsCount() {return count;}
    void Update();
    void Clear();
    void Sort();
    SteamAPIAchievements(const SteamAPIAchievements &);
    SteamAPIAchievements & operator=(const SteamAPIAchievements & friends);

signals:
    void finished(SteamAPIAchievements*);
    void finished();

public slots:
    //void Load(QNetworkReply *Reply);

private:
    QVector<SteamAPIAchievement> achievements;
    QString statusglobal="none";
    QString statusplayer="none";
    QString statuspercent="none";
    QString id="";
    QString appid="";
    QString key="";
    QString language="";
    QString gamename="";
    QString gameversion="";
    int count=0;
};

#endif // STEAMAPIACHIEVEMENTS_H
