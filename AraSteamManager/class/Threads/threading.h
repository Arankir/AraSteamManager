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
    explicit Threading(QObject* parent = nullptr);

signals:

public slots:
    int AddThreadGames(QTableWidget* TableWidgetGames, QVector<SGame> games);
    int AddThreadAchievements(SAchievements achievements, QStringList Words, QLabel* LabelTotalPersent, QTableWidget* TableWidgetAchievements, int num);
    int AddThreadCompare();
    int AddThreadFriends(QTableWidget* TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friendss,QStringList Words);
};

#endif // THREADING_H
