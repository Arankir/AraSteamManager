#ifndef THREADING_H
#define THREADING_H

#include <QObject>
#include <QThread>
#include "class/Threads/threadgames.h"
#include "class/Threads/threadachievements.h"
#include "class/Threads/threadfriends.h"
#include "class/Threads/threadstatistics.h"

class Threading : public QObject {
    Q_OBJECT
public:
    explicit Threading(QObject *parent = nullptr);

signals:
    void s_games_progress(int progress, int row);
    void s_games_finished();
    void s_friends_progress(int progress, int row);
    void s_friends_finished();
    void s_statistics_progress(int progress, int row);
    void s_statistics_finished();
    void s_achievements_friends_is_public(bool isVisible, int column);
    void s_achievements_progress(int progress, int row);
    void s_achievements_finished(int, int);


public slots:
    int AddThreadGames(const int columnID, const int columnIndex, const int columnName, QTableWidget *tableWidgetGames, SGames games);
    int AddThreadAchievements(const int tableColumnAppid, const int tableColumnTitle, const int tableColumnDescription, const int tableColumnWorld, const int tableColumnMy,
                              SAchievements *achievements, QTableWidget *TableWidgetAchievements);
    int AddThreadFriends(const int columnID, const int columnName, const int columnAdded, const int columnStatus, const int columnisPublic,
                         QTableWidget *tableWidgetFriends, QList<QPair<SFriend, SProfile> > friends);
    int AddThreadStatistics(SGames &games, const QString &id, QVector<int> &numOf, QVector<QPair<QString,QString> > &complete,
                            QVector<QPair<QString,QString>> &started, QVector<QPair<QString,QString>> &notStarted,
                            QVector<double> &averagePercent, int &summColumn, QVector<int> &times,
                            QVector<int> &months, QVector<QPair<QString,int>> &years);
    int AddThreadFriendAchievements(QTableWidget *tableWidgetAchievements, SAchievements &achievement, int col, int columnAppid);
};

#endif // THREADING_H
