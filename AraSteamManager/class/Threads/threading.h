#ifndef THREADING_H
#define THREADING_H

#include <QObject>
#include <QThread>
#include <class/Threads/threadgames.h>
#include <class/Threads/threadachievements.h>
#include <class/Threads/threadfriends.h>
#include <class/Threads/threadstatistics.h>

class Threading : public QObject
{
    Q_OBJECT
public:
    explicit Threading(QObject *parent = nullptr);

signals:

public slots:
    int AddThreadGames(QTableWidget *TableWidgetGames, SGames games);
    int AddThreadAchievements(SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare);
    int AddThreadFriends(QTableWidget *TableWidgetFriends, SProfiles Profiles,SFriends Friendss);
    int AddThreadStatistics(SGames games, QString id);
    int AddThreadFriendAchievements(QTableWidget *AtableWidgetAchievements, SAchievements Aachievement, int Acol, int AcolumnAppid);
};

#endif // THREADING_H
