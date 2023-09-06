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

struct CompletedAchievement {
    CompletedAchievement(SAchievementPlayer achievement, SGame game);
    SAchievementPlayer achievement;
    SGame game;
};

struct Statistics {
    Statistics(const SProfile &profile);
    Statistics();
    void changeProfile(const SProfile &profile);
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

    QMap<int, int> years;
};

class ThreadStatistics : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();
    void onResultAchievements(const SAchievementsPlayer &achievements, const SGame &game);
    void updateTimes(const QDateTime &unlockedTime);

public:
    ThreadStatistics(Statistics &statistic);
    ~ThreadStatistics();

signals:
    void s_progress(const QString &text, int progress, int max);
    void s_finish(Statistics&);

private:
    Statistics &statistics_;

    int countReachedAchievements(const SAchievementsPlayer &achievements, const SGame &game);
};

#endif // THREADSTATISTICS_H
