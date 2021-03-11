#ifndef THREADING_H
#define THREADING_H

#include <QObject>
#include <QThread>
#include "classes/threads/thread/threadgames.h"
#include "classes/threads/thread/threadachievements.h"
#include "classes/threads/thread/threadfriends.h"
#include "classes/threads/thread/threadstatistics.h"

class Threading : public QObject {
    Q_OBJECT
public:
    explicit Threading(QObject *parent = nullptr): QObject(parent) {}

signals:
    void s_games_progress(int progress);
    void s_games_finished_model(QStandardItemModel *);
    void s_friends_progress(int progress);
    void s_friends_finished_model(QStandardItemModel *);
    void s_statistics_progress(int progress);
    void s_statistics_finished();
    void s_achievements_friends_is_public(bool isVisible, int column);
    void s_achievements_progress(int progress, int max);
    void s_achievements_finished_model(QStandardItemModel *model, int reached, int notReached);
    void s_achievements_finished(int);


public slots:
    int AddThreadGames(QList<SGame> games);
    int AddThreadAchievements(const QColor achievedColor, const QColor notAchievedColor,
                              const QList<SAchievement> &achievements, int gameAppId);
    int AddThreadFriends(QList<QPair<SFriend, SProfile> > friends);
    int AddThreadStatistics(QList<SGame> &games, const QString &id, QVector<SGame> &noAchievements, QVector<SGame> &complete,
                            QVector<QPair<SGame, double>> &started, QVector<SGame> &notStarted, int &summColumn, QVector<int> &times,
                            QVector<int> &months, QVector<QPair<QString,int>> &years);

private:
    QThread *createThread();

};

#endif // THREADING_H
