#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QLabel>
#include "classes/network/requestdata.h"
#include "classes/steamApi/structures/sachievements.h"
#include "forms/subForms/achievements/formachievements.h"

class ThreadAchievements : public QObject {
    Q_OBJECT
public slots:
    int fill();
//    void set(SAchievements achievements, QTableWidget *TableWidgetAchievements);
//    bool addFriend();
//    void setFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

public:
    explicit ThreadAchievements(const QList<SAchievement> &achievements, int gameAppId, const QColor achievedColor,
                                QColor notAchievedColor, QObject *parent = nullptr):
        QObject(parent), c_achievedColor(achievedColor),
        c_notAchievedColor(notAchievedColor), _gameAppId(gameAppId), _achievements(achievements) {}
    explicit ThreadAchievements(QObject *parent = nullptr):
        ThreadAchievements(QList<SAchievement>(), 0, QColor(), QColor(), parent) {}
    ~ThreadAchievements() {qInfo() << "Thread achievements deleted";}

signals:
    void s_finished(int reached, int notReached);
    void s_progress(int progress, int max);
    void s_finishedModel(QStandardItemModel *model, int reached, int notReached);
    void s_is_public(bool aPublic, int aColumn);

private:
    const QColor c_achievedColor;
    const QColor c_notAchievedColor;
    int _gameAppId;
    QList<SAchievement> _achievements;

    int _col;
    int _columnAppid;
};

#endif // THREADACHIEVEMENTS_H
