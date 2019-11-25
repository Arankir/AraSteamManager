#ifndef SACHIEVEMENTSPERCENTAGE_H
#define SACHIEVEMENTSPERCENTAGE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievementpercentage.h>
#include <QObject>

class SAchievementsPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPercentage(QString key, QString appid, QObject* parent = nullptr);
    SAchievementsPercentage(QJsonDocument DocAchievements);
    SAchievementsPercentage();
    ~SAchievementsPercentage();
    void Set(QString key, QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { achievements.remove(index); count--;}
    SAchievementPercentage GetAchievementInfo(int index) {return achievements[index];}
    QString GetApiname(int index) {return achievements[index].GetApiname();}
    double GetPercent(int index) {return achievements[index].GetPercent();}
    QString GetAppid() {return appid;}
    int GetAchievementsCount() {return count;}
    QString GetStatus() {return status;}
    void Update();
    void Clear();
    SAchievementsPercentage(const SAchievementsPercentage &);
    SAchievementsPercentage & operator=(const SAchievementsPercentage & friends);

signals:
    void finished(SAchievementsPercentage);
    void finished();

public slots:
    void Load(QNetworkReply* Reply);

private:
    QNetworkAccessManager* manager;
    QVector<SAchievementPercentage> achievements;
    QString status="none";
    QString appid="";
    QString key="";
    int count=0;
};

#endif // SACHIEVEMENTSPERCENTAGE_H
