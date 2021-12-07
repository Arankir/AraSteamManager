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
    void changeProfile(const SProfile &aProfile, const SGames &aGames);
    void sortAllLists();
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
    ThreadStatistics(Statistics &statistic): _statistics(statistic) {};

    ~ThreadStatistics() {qInfo() << "Thread statistic deleted";}

signals:
    void s_progress(const QString &text, int progress, int max);
    void s_finish(Statistics&);

private:
    Statistics &_statistics;

    int countReachedAchievements(const QList<SAchievementPlayer> &aAchievements, const SGame &aGame);
};

#endif // THREADSTATISTICS_H
