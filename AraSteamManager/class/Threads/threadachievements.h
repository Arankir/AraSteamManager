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
    explicit ThreadAchievements(QObject *parent = nullptr);
    ~ThreadAchievements() {qDebug()<<"Thread deleted";}

signals:
    void s_finished();
    void s_progress(int p, int row);
    void s_is_public(bool Apublic, int Acolumn);

public slots:
    int Fill();
    void Set(SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare);
    bool AddFriend();
    void SetFriend(QTableWidget *TableWidgetAchievements, SAchievements Aachievement, int Acol, int AcolumnAppid);

private:
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
