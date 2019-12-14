#ifndef SACHIEVEMENTPLAYER_H
#define SACHIEVEMENTPLAYER_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SAchievementPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementPlayer(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementPlayer();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return _apiName;}
    int GetAchieved() {return _achieved;}
    QDateTime GetUnlocktime() {return _unlockTime;}
    SAchievementPlayer(const SAchievementPlayer &);
    SAchievementPlayer & operator=(const SAchievementPlayer & achievement);

signals:

public slots:

private:
    QString _apiName="";
    int _achieved=0;
    QDateTime _unlockTime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
};

#endif // SACHIEVEMENTPLAYER_H
