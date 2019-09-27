#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievement.h>
#include <class/steamapi/Sachievementsglobal.h>
#include <class/steamapi/Sachievementsplayer.h>
#include <class/steamapi/Sachievementspercentage.h>
#include <QObject>

class SAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SAchievements(QString key, QString appid, QString id, QString language, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    SAchievements();
    ~SAchievements();
    void Set(QString key, QString appid, QString id, QString language);
    void Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    void Set(SAchievementsPlayer Player);
    void Set(SAchievementsGlobal Global);
    void Set(SAchievementsPercentage Percent);
    SAchievement GetAchievementInfo(int index) {return achievements[index];}
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
    SAchievements(const SAchievements &);
    SAchievements & operator=(const SAchievements & friends);

signals:
    void finished(SAchievements*);
    void finished();

public slots:
    //void Load(QNetworkReply *Reply);

private:
    QVector<SAchievement> achievements;
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

#endif // SACHIEVEMENTS_H
