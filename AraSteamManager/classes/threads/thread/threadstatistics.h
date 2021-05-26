#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <QEventLoop>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/network/requestdata.h"
#include "../threadloading.h"

class ThreadStatistics : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();
    void onResultAchievements(const QList<SAchievementPlayer> &ach, const SGame &aGame);
    void updateTimes(const QDateTime &unlockedTime);

public:
    explicit ThreadStatistics(SGames &games, const QString &id, int &aAchievementsCount,
                              SGames &aNoAchievements, SGames &aComplete, QList<QPair<SGame, double>> &aStarted, SGames &aNotStarted,
                              QVector<int> &aTimes, QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears):
        _id(id), _games(games), _achievementsCount(aAchievementsCount),
        _times(aTimes), _months(aMonths), _years(aYears),
        _noAchievements(aNoAchievements), _complete(aComplete), _started(aStarted), _notStarted(aNotStarted) {}

    ~ThreadStatistics() {qInfo() << "Thread statistic deleted";}

signals:
    void s_progress(const int &p);

private:
    QString _id;
    SGames _games;
    int &_achievementsCount;

    QVector<int> &_times;
    QVector<int> &_months;
    QVector<QPair<QString, int>> &_years;

    SGames &_noAchievements;
    SGames &_complete;
    QList<QPair<SGame, double>> &_started;
    SGames &_notStarted;

    int countReachedAchievements(const QList<SAchievementPlayer> &aAchievements);
};

#endif // THREADSTATISTICS_H
