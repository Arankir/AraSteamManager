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
    int AddThreadGames(QTableWidget *TableWidgetGames, QVector<SGame> games);
    int AddThreadAchievements(SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare, QTableWidget *TableWidgetCompareAchievements);
    int AddThreadFriends(QTableWidget *TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friendss);
    int AddThreadStatistics(SGames games, QString id);
};

#endif // THREADING_H
