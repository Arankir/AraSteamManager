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
    QString GetApiname() {return _apiName;}
    int GetDefaultvalue() {return _defaultValue;}
    QString GetDisplayname() {return _displayName;}
    int GetHidden() {return _hidden;}
    QString GetDescription() {return _description;}
    QString GetIcon() {return _icon;}
    QString GetIcongray() {return _iconGray;}
    int GetAchieved() {return _achieved;}
    QDateTime GetUnlocktime() {return _unlockTime;}
    QString GetStatusGlobal() {return _statusGlobal;}
    QString GetStatusPlayer() {return _statusPlayer;}
    double GetPercent() {return _percent;}
    SAchievement(const SAchievement &);
    SAchievement & operator=(const SAchievement & achievement);

signals:

public slots:

private:
    QString _apiName="";
    int _defaultValue=0;
    QString _displayName="";
    int _hidden=0;
    QString _description="";
    QString _icon="";
    QString _iconGray="";
    int _achieved=0;
    QDateTime _unlockTime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
    double _percent=0.0;
    QString _statusGlobal="none";
    QString _statusPlayer="none";
    QString _statusPercent="none";
};

#endif // SACHIEVEMENT_H
