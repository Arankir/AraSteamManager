#ifndef ACHIEVEMENTCOMPLETEDPIECHART_H
#define ACHIEVEMENTCOMPLETEDPIECHART_H

#include "./piechart.h"
#include "classes/steamApi/structures/sachievements.h"

class AchievementCompletedPieChart: public PieChart {
    Q_OBJECT
public:
    AchievementCompletedPieChart();
    void setNoAchievements(int);
    void setNotStarted(int);
    void setStarted(int);
    void setCompleted(int);
    void clear();

signals:
    void s_noAchievementsClicked();
    void s_notStartedClicked();
    void s_startedClicked();
    void s_completedClicked();

public slots:
    void updateSettings(QFlags<changedSettings> settings);

protected:
    void changeEvent(QEvent *event);
    void retranslate();
    void updateIcons();
    void updateTheme();

    void slicesValueUpdated();
private:
    QPieSlice *completed_;
    QPieSlice *started_;
    QPieSlice *notStarted_;
    QPieSlice *noAchievements_;

};

#endif // ACHIEVEMENTCOMPLETEDPIECHART_H
