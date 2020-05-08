#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QLabel>
#include <class/Network/requestdata.h>
#include <class/steamapi/Sachievements.h>

class ThreadAchievements : public QObject
{
    Q_OBJECT
public:
    explicit ThreadAchievements(SAchievements a_achievements, QLabel *a_LabelTotalPersent, QTableWidget *a_TableWidgetAchievements, QLabel *a_LabelTotalPersentCompare,
        const int a_tableColumnAppid, const int a_tableColumnTitle, const int a_tableColumnDescription, const int a_tableColumnWorld, const int a_tableColumnMy, QObject *a_parent = nullptr) :
        QObject(a_parent), c_tableColumnAppid(a_tableColumnAppid), c_tableColumnTitle(a_tableColumnTitle), c_tableColumnDescription(a_tableColumnDescription), c_tableColumnWorld(a_tableColumnWorld), c_tableColumnMy(a_tableColumnMy),
        _achievements(a_achievements), _LabelTotalPersent(a_LabelTotalPersent), _TableWidgetAchievements(a_TableWidgetAchievements), _LabelTotalPersentCompare(a_LabelTotalPersentCompare){};
    explicit ThreadAchievements(QObject *parent = nullptr) : QObject(parent), c_tableColumnAppid(0), c_tableColumnTitle(0), c_tableColumnDescription(0), c_tableColumnWorld(0), c_tableColumnMy(0) {};
    ~ThreadAchievements() {qDebug()<<"Thread deleted";}

signals:
    void s_finished(int reached, int notreached);
    void s_progress(int p, int row);
    void s_is_public(bool a_public, int a_column);

public slots:
    int Fill();
    void Set(SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare);
    bool AddFriend();
    void SetFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnTitle;
    const int c_tableColumnDescription;
    const int c_tableColumnWorld;
    const int c_tableColumnMy;
    int num;
    SAchievements _achievements;
    QLabel *_LabelTotalPersent;
    QTableWidget *_TableWidgetAchievements;
    QLabel *_LabelTotalPersentCompare;

    SAchievements _achievement;
    int _col;
    int _columnAppid;
};

#endif // THREADACHIEVEMENTS_H
