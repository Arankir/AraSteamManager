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

struct CompletedAchievement {
    CompletedAchievement(SAchievementPlayer aAchievement, SGame aGame): achievement(aAchievement), game(aGame) {};
    SAchievementPlayer achievement;
    SGame game;
};

struct Statistics {
    Statistics(const SProfile &aProfile, const SGames &aGame): profile(aProfile), games(aGame) {};
    SProfile profile;
    SGames games;
    double summAverages = 0.0;
    int achievementCount = 0;

    QList<GameWithPercent> complete;
    QList<GameWithPercent> started;
    QList<GameWithPercent> notStarted;
    QList<GameWithPercent> noAchievements;

    QList<CompletedAchievement> completedAchievements;

//    QVector<int> times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    QVector<int> months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<YearCount> years;
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

    int countReachedAchievements(const QList<SAchievementPlayer> &aAchievements, const SGame &aGame);
};

#endif // THREADSTATISTICS_H
