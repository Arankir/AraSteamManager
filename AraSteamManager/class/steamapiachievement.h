#ifndef STEAMAPIACHIEVEMENT_H
#define STEAMAPIACHIEVEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>
#include <class/steamapiachievementglobal.h>
#include <class/steamapiachievementplayer.h>

class SteamAPIAchievement : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievement(QJsonObject ObjGlobal, QJsonObject ObjPlayer, QObject *parent = nullptr);
    SteamAPIAchievement(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player);
    SteamAPIAchievement();
    void Set(QJsonObject ObjGlobal, QJsonObject ObjPlayer);
    void Set(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player);
    QString GetApiname();
    int GetDefaultvalue();
    QString GetDisplayname();
    int GetHidden();
    QString GetDescription();
    QString GetIcon();
    QString GetIcongray();
    int GetAchieved();
    QDateTime GetUnlocktime();
    QString GetStatusGlobal();
    QString GetStatusPlayer();
    void SetGlobal(QJsonObject ObjAchievement);
    void SetPlayer(QJsonObject ObjAchievement);
    void SetGlobal(SteamAPIAchievementGlobal Global);
    void SetPlayer(SteamAPIAchievementPlayer Player);
    SteamAPIAchievement(const SteamAPIAchievement &);
    SteamAPIAchievement & operator=(const SteamAPIAchievement & achievement);

signals:

public slots:

private:
    QString apiname="";
    int defaultvalue=0;
    QString displayname="";
    int hidden=0;
    QString description="";
    QString icon="";
    QString icongray="";
    int achieved=0;
    QDateTime unlocktime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
    QString statusglobal="none";
    QString statusplayer="none";
};

#endif // STEAMAPIACHIEVEMENT_H
