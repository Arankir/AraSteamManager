#ifndef THREADING_H
#define THREADING_H

#include <QObject>
#include <QThread>
#include <class/Threads/threadgames.h>
#include <class/Threads/threadachievements.h>
#include <class/Threads/threadcompare.h>
#include <class/Threads/threadfriends.h>

class Threading : public QObject
{
    Q_OBJECT
public:
    explicit Threading(QObject *parent = nullptr);

signals:

public slots:
    int AddThreadGames(QTableWidget *TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation);
    int AddThreadAchievements();
    int AddThreadCompare();
    int AddThreadFriends();
};

#endif // THREADING_H
