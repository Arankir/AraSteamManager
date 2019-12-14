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
    explicit SAchievementsPercentage(QString key, QString appid, QObject *parent = nullptr);
    SAchievementsPercentage(QJsonDocument DocAchievements);
    SAchievementsPercentage();
    ~SAchievementsPercentage();
    void Set(QString key, QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.remove(index); _count--;}
    SAchievementPercentage GetAchievement(int index) {return _achievements[index];}
    QString GetApiname(int index) {return _achievements[index].GetApiname();}
    double GetPercent(int index) {return _achievements[index].GetPercent();}
    QString GetAppid() {return _appid;}
    int GetCount() {return _count;}
    QString GetStatus() {return _status;}
    void Update();
    void Clear();
    SAchievementsPercentage(const SAchievementsPercentage &);
    SAchievementsPercentage & operator=(const SAchievementsPercentage & friends);

signals:
    void s_finished(SAchievementsPercentage);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    QVector<SAchievementPercentage> _achievements;
    QString _status="none";
    QString _appid="";
    QString _key="";
    int _count=0;
};

#endif // SACHIEVEMENTSPERCENTAGE_H
