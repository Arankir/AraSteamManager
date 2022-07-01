#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <QEventLoop>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/network/requestdata.h"
#include "../threadloading.h"
#include "classes/steamApi/structures/sprofile.h"
#include "subWidgets/models/gameswithpercentmodel.h"

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
    Statistics(const SProfile &aProfile): profile(aProfile), games(SGame::load(aProfile.steamID(), true, true)) {};
    Statistics() {};
    void changeProfile(const SProfile &aProfile);
    void sortAllLists();
    SProfile profile;
    SGames games;
    double summAverages = 0.0;
    int achievementCount = 0;

    QList<GameWithPercentModelItem> complete;
    QList<GameWithPercentModelItem> started;
    QList<GameWithPercentModelItem> notStarted;
    QList<GameWithPercentModelItem> noAchievements;

    QList<CompletedAchievement> completedAchievements;

//    QVector<int> times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    QVector<int> months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<YearCount> years;
};

class ThreadStatistics : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();
    void onResultAchievements(const SAchievementsPlayer &ach, const SGame &aGame);
    void updateTimes(const QDateTime &unlockedTime);

public:
    ThreadStatistics(Statistics &statistic): statistics_(statistic) {};

    ~ThreadStatistics() {qInfo() << "Thread statistic deleted";}

signals:
    void s_progress(const QString &text, int progress, int max);
    void s_finish(Statistics&);

private:
    Statistics &statistics_;

    int countReachedAchievements(const SAchievementsPlayer &aAchievements, const SGame &aGame);
};

#endif // THREADSTATISTICS_H
