#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <QEventLoop>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/network/requestdata.h"
#include "../threadloading.h"
#include "classes/steamApi/structures/sprofile.h"

struct GameWithPercent {
    GameWithPercent(const SGame &aGame, double aPercent, SAchievementsPlayer aAchievements): game(aGame), percent(aPercent), achievements(aAchievements) {};
    SGame game;
    double percent;
    SAchievementsPlayer achievements;
};

struct YearCount {
    YearCount(const QString &aYear, int aCount): year(aYear), count(aCount) {};
    QString year;
    int count;
};

struct Statistics {
    Statistics(const SProfile &aProfile, const SGames &aGame): _profile(aProfile), _games(aGame) {};
    SProfile _profile;
    SGames _games;
    double _summAverages = 0.0;
    int _achievementCount = 0;

    QList<GameWithPercent> _complete;
    QList<GameWithPercent> _started;
    QList<GameWithPercent> _notStarted;
    QList<GameWithPercent> _noAchievements;

    QVector<int> _times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<int> _months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<YearCount> _years;
};

class ThreadStatistics : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();
    void onResultAchievements(const QList<SAchievementPlayer> &ach, const SGame &aGame);
    void updateTimes(const QDateTime &unlockedTime);

public:
//    explicit ThreadStatistics(SGames &games, const QString &id, int &aAchievementsCount,
//                              SGames &aNoAchievements, SGames &aComplete, QList<QPair<SGame, double>> &aStarted, SGames &aNotStarted,
//                              QVector<int> &aTimes, QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears):
//        _id(id), _games(games), _achievementsCount(aAchievementsCount),
//        _times(aTimes), _months(aMonths), _years(aYears),
//        _noAchievements(aNoAchievements), _complete(aComplete), _started(aStarted), _notStarted(aNotStarted) {}
    ThreadStatistics(Statistics &statistic): _statistics(statistic) {};

    ~ThreadStatistics() {qInfo() << "Thread statistic deleted";}

signals:
    void s_progress(const QString &text, int progress, int max);

private:
//    QString _id;
//    SGames _games;
//    int &_achievementsCount;

//    QVector<int> &_times;
//    QVector<int> &_months;
//    QVector<QPair<QString, int>> &_years;

//    SGames &_noAchievements;
//    SGames &_complete;
//    QList<QPair<SGame, double>> &_started;
//    SGames &_notStarted;

    Statistics &_statistics;

    int countReachedAchievements(const QList<SAchievementPlayer> &aAchievements);
};

#endif // THREADSTATISTICS_H
