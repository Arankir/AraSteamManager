#ifndef SACHIEVEMENT_H
#define SACHIEVEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>
#include <class/steamapi/Sachievementglobal.h>
#include <class/steamapi/Sachievementplayer.h>
#include <class/steamapi/Sachievementpercentage.h>
#include <QDebug>

class SAchievement : public QObject
{
    Q_OBJECT
public:
    explicit SAchievement(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent, QObject *parent = nullptr);
    SAchievement();
    void Set(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent);
    void SetGlobal(SAchievementGlobal Global);
    void SetPlayer(SAchievementPlayer Player);
    void SetPercent(SAchievementPercentage Percent);
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
    SAchievement(const SAchievement &);
    SAchievement & operator=(const SAchievement & achievement);

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

#endif // SACHIEVEMENT_H
