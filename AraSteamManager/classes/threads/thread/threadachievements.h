#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QLabel>
#include "classes/network/requestdata.h"
#include "classes/steamApi/structures/sachievements.h"
#include "../threadloading.h"
#include "forms/subForms/achievements/formachievements.h"

class ThreadAchievements : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();
//    void set(SAchievements achievements, QTableWidget *TableWidgetAchievements);
//    bool addFriend();
//    void setFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

public:
    explicit ThreadAchievements(const SAchievements &achievements, const int &gameAppId, const QColor &achievedColor,
                                const QColor &notAchievedColor):
        c_achievedColor(achievedColor), c_notAchievedColor(notAchievedColor), _gameAppId(gameAppId), _achievements(achievements) {}
    explicit ThreadAchievements(): ThreadAchievements(SAchievements(), 0, QColor(), QColor()) {}
    ~ThreadAchievements() {qInfo() << "Thread achievements deleted";}

signals:
//    void s_finished(int reached, int notReached);
    void s_progress(const int &progress, const int &max);
    void s_finishedModel(QStandardItemModel *model, const int &reached, const int &notReached);
    void s_is_public(const bool &aPublic, const int &aColumn);

private:
    const QColor c_achievedColor;
    const QColor c_notAchievedColor;
    int _gameAppId;
    SAchievements _achievements;
};

#endif // THREADACHIEVEMENTS_H
