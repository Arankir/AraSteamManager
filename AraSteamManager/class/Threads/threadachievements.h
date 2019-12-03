#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QLabel>
#include <class/imagerequest.h>
#include <class/steamapi/Sachievements.h>

class ThreadAchievements : public QObject
{
    Q_OBJECT
public:
    explicit ThreadAchievements(QObject *parent = nullptr);
    ~ThreadAchievements() {qDebug()<<"Thread deleted";}

signals:
    void finished();
    void progress(int p, int row);

public slots:
    int Fill();
    void Set(SAchievements achievements, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare, QTableWidget *TableWidgetCompareAchievements);

private:
    int num;
    SAchievements achievements;
    QLabel *LabelTotalPersent;
    QTableWidget *TableWidgetAchievements;
    QLabel *LabelTotalPersentCompare;
    QTableWidget *TableWidgetCompareAchievements;
};

#endif // THREADACHIEVEMENTS_H
