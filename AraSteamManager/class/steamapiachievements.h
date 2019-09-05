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
#include <QObject>

class SteamAPIAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievements(QString key, QString appid, QString id, QString language, QObject *parent = nullptr);
    SteamAPIAchievements(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player);
    SteamAPIAchievements();
    ~SteamAPIAchievements();
    void Set(QString key, QString appid, QString id, QString language);
    void Set(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player);
    void Set(SteamAPIAchievementsPlayer Player);
    void Set(SteamAPIAchievementsGlobal Global);
    void Sort();
    SteamAPIAchievement GetAchievementInfo(int index);
    QString GetApiname(int index);
    int GetDefaultvalue(int index);
    QString GetDisplayname(int index);
    int GetHidden(int index);
    QString GetDescription(int index);
    QString GetIcon(int index);
    QString GetIcongray(int index);
    int GetAchieved(int index);
    QDateTime GetUnlocktime(int index);
    QString GetStatusGlobal();
    QString GetStatusPlayer();
    QString GetAppid();
    QString GetGamename();
    QString GetGameversion();
    int GetAchievementsCount();
    void Update();
    SteamAPIAchievements(const SteamAPIAchievements &);
    SteamAPIAchievements & operator=(const SteamAPIAchievements & friends);
    void Clear();

signals:
    void finished(SteamAPIAchievements*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QVector<SteamAPIAchievement> achievements;
    QString statusglobal="none";
    QString statusplayer="none";
    QString id="";
    QString appid="";
    QString key="";
    QString language="";
    QString gamename="";
    QString gameversion="";
    int count=0;
};

#endif // STEAMAPIACHIEVEMENTS_H
