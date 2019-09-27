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
    QString GetApiname() {return apiname;}
    int GetAchieved() {return achieved;}
    QDateTime GetUnlocktime() {return unlocktime;}
    SAchievementPlayer(const SAchievementPlayer &);
    SAchievementPlayer & operator=(const SAchievementPlayer & achievement);

signals:

public slots:

private:
    QString apiname="";
    int achieved=0;
    QDateTime unlocktime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
};

#endif // SACHIEVEMENTPLAYER_H
