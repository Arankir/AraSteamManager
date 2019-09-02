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
    SteamAPIAchievementGlobal GetAchievementInfo(int index);
    QString GetApiname(int index);
    int GetDefaultvalue(int index);
    QString GetDisplayname(int index);
    int GetHidden(int index);
    QString GetDescription(int index);
    QString GetIcon(int index);
    QString GetIcongray(int index);
    QString GetAppid();
    QString GetStatus();
    QString GetGamename();
    QString GetGameversion();
    int GetAchievementsCount();
    void Update();
    SteamAPIAchievementsGlobal(const SteamAPIAchievementsGlobal &);
    SteamAPIAchievementsGlobal & operator=(const SteamAPIAchievementsGlobal & friends);
    void Clear();

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
