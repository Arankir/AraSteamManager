#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QLabel>
#include "class/Network/requestdata.h"
#include "class/steamapi/Sachievements.h"

class ThreadAchievements : public QObject {
    Q_OBJECT
public slots:
    int fill();
//    void set(SAchievements achievements, QTableWidget *TableWidgetAchievements);
//    bool addFriend();
//    void setFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

public:
    explicit ThreadAchievements(SAchievements *achievements, QTableWidget *tableWidgetAchievements, const int tableColumnAppid, const int tableColumnTitle,
                                const int tableColumnDescription, const int tableColumnWorld, const int tableColumnMy, QObject *parent = nullptr):
        QObject(parent), c_tableColumnAppid(tableColumnAppid), c_tableColumnTitle(tableColumnTitle), c_tableColumnDescription(tableColumnDescription),
        c_tableColumnWorld(tableColumnWorld), c_tableColumnMy(tableColumnMy), _achievements(achievements), _tableWidgetAchievements(tableWidgetAchievements) {}
    explicit ThreadAchievements(QObject *parent = nullptr): ThreadAchievements(nullptr, nullptr, 0, 0, 0, 0, 0, parent) {}
    ~ThreadAchievements() {qInfo()<<"Thread achievements deleted";}

signals:
    void s_finished(int reached, int notReached);
    void s_progress(int progress, int row);
    void s_is_public(bool aPublic, int aColumn);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnTitle;
    const int c_tableColumnDescription;
    const int c_tableColumnWorld;
    const int c_tableColumnMy;
    int num;
    SAchievements *_achievements;
    QTableWidget *_tableWidgetAchievements;

    SAchievements _achievement;
    int _col;
    int _columnAppid;
};

#endif // THREADACHIEVEMENTS_H
