#ifndef STEAMAPIACHIEVEMENT_H
#define STEAMAPIACHIEVEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>
#include <class/steamapiachievementglobal.h>
#include <class/steamapiachievementplayer.h>
#include <class/steamapiachievementpercentage.h>

class SteamAPIAchievement : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievement(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player, SteamAPIAchievementPercentage Percent, QObject *parent = nullptr);
    SteamAPIAchievement();
    void Set(SteamAPIAchievementGlobal Global, SteamAPIAchievementPlayer Player, SteamAPIAchievementPercentage Percent);
    void SetGlobal(SteamAPIAchievementGlobal Global);
    void SetPlayer(SteamAPIAchievementPlayer Player);
    void SetPercent(SteamAPIAchievementPercentage Percent);
    QString GetApiname() {return apiname;}
    int GetDefaultvalue() {return defaultvalue;}
    QString GetDisplayname() {return displayname;}
    int GetHidden() {return hidden;}
    QString GetDescription() {return description;}
    QString GetIcon() {return icon;}
    QString GetIcongray() {return icongray;}
    int GetAchieved() {return achieved;}
    QDateTime GetUnlocktime() {return unlocktime;}
    QString GetStatusGlobal() {return statusglobal;}
    QString GetStatusPlayer() {return statusplayer;}
    double GetPercent() {return percent;}
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
    double percent=0.0;
    QString statusglobal="none";
    QString statusplayer="none";
    QString statuspercent="none";
};

#endif // STEAMAPIACHIEVEMENT_H
