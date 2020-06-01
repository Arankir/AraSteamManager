#ifndef THREADING_H
#define THREADING_H

#include <QObject>
#include <QThread>
#include <class/Threads/threadgames.h>
#include <class/Threads/threadachievements.h>
#include <class/Threads/threadfriends.h>
#include <class/Threads/threadstatistics.h>

class Threading : public QObject {
    Q_OBJECT
public:
    explicit Threading(QObject *parent = nullptr);

signals:

public slots:
    int AddThreadGames(const int columnID, const int columnIndex, const int columnName, QTableWidget *tableWidgetGames, SGames games);
    int AddThreadAchievements(const int tableColumnAppid, const int tableColumnTitle, const int tableColumnDescription, const int tableColumnWorld, const int tableColumnMy,
                              SAchievements achievements, QTableWidget *TableWidgetAchievements);
    int AddThreadFriends(const int columnID, const int columnName, const int columnAdded, const int columnStatus, const int columnisPublic,
                         QTableWidget *tableWidgetFriends, SProfiles profiles,SFriends friends);
    int AddThreadStatistics(SGames games, QString id);
    int AddThreadFriendAchievements(QTableWidget *tableWidgetAchievements, SAchievements achievement, int col, int columnAppid);
};

#endif // THREADING_H
