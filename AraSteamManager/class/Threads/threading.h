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
    int AddThreadGames(const int columnID, const int columnIndex, const int columnName, QTableWidget *tableWidgetGames, SGames games);
    int AddThreadAchievements(const int tableColumnAppid, const int tableColumnTitle, const int tableColumnDescription, const int tableColumnWorld, const int tableColumnMy,
                              SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare);
    int AddThreadFriends(const int a_columnID, const int a_columnName, const int a_columnAdded, const int a_columnStatus, const int a_columnisPublic,
                         QTableWidget *TableWidgetFriends, SProfiles Profiles,SFriends Friends);
    int AddThreadStatistics(SGames games, QString id);
    int AddThreadFriendAchievements(QTableWidget *AtableWidgetAchievements, SAchievements Aachievement, int Acol, int AcolumnAppid);
};

#endif // THREADING_H
