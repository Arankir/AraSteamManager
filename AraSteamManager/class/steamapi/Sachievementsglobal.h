#ifndef SACHIEVEMENTSGLOBAL_H
#define SACHIEVEMENTSGLOBAL_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievementglobal.h>
#include <QObject>

class SAchievementsGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsGlobal(QString key, QString appid, QObject *parent = nullptr);
    SAchievementsGlobal(QJsonDocument DocAchievements);
    SAchievementsGlobal();
    ~SAchievementsGlobal();
    void Set(QString key, QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { achievements.remove(index); count--;}
    SAchievementGlobal GetAchievementInfo(int index) {return achievements[index];}
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
    SAchievementsGlobal(const SAchievementsGlobal &);
    SAchievementsGlobal & operator=(const SAchievementsGlobal & friends);

signals:
    void finished(SAchievementsGlobal);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SAchievementGlobal> achievements;
    QString status="none";
    QString appid="";
    QString key="";
    QString gamename="";
    QString gameversion="";
    int count=0;
};

#endif // SACHIEVEMENTSGLOBAL_H
