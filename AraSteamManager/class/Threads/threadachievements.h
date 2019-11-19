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
    explicit ThreadAchievements(QObject* parent = nullptr);

signals:
    void finished();
    void progress(int p, int row);

public slots:
    int Fill();
    void Set(SAchievements achievements, QStringList Words, QLabel* LabelTotalPersent, QTableWidget* TableWidgetAchievements, int num);

private:
    int num;
    SAchievements achievements;
    QStringList Words;
    QLabel* LabelTotalPersent;
    QTableWidget* TableWidgetAchievements;
};

#endif // THREADACHIEVEMENTS_H
