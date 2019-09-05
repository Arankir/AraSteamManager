#ifndef STEAMAPIACHIEVEMENTPLAYER_H
#define STEAMAPIACHIEVEMENTPLAYER_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SteamAPIAchievementPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementPlayer(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SteamAPIAchievementPlayer();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return apiname;}
    int GetAchieved() {return achieved;}
    QDateTime GetUnlocktime() {return unlocktime;}
    SteamAPIAchievementPlayer(const SteamAPIAchievementPlayer &);
    SteamAPIAchievementPlayer & operator=(const SteamAPIAchievementPlayer & achievement);

signals:

public slots:

private:
    QString apiname="";
    int achieved=0;
    QDateTime unlocktime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
};

#endif // STEAMAPIACHIEVEMENTPLAYER_H
