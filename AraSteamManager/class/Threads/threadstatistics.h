#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/Network/requestdata.h>
#include <QEventLoop>

class ThreadStatistics : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadStatistics(SGames a_games, QString a_id, QVector<int> &aNumOf, QVector<QPair<QString,QString> > &aComplete,
                              QVector<QPair<QString,QString>> &aStarted, QVector<QPair<QString,QString>> &aNotStarted,
                              QVector<double> &aAveragePercent, int &aSummColumn, QVector<int> &aTimes,
                              QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears, QObject *a_parent = nullptr);

signals:
    void s_finished();
    void s_progress(int p, int row);

private slots:
    void onResultAchievements(SAchievementsPlayer ach);

private:
    QString _id;
    SGames _games;
    QVector<double> *_averagePercent;
    QVector<int> *_numof;
    int *_summcolumn;
    QVector<int> *_times;
    QVector<int> *_months;
    QVector<QPair<QString,int>> *_years;
    QVector<QPair<QString,QString>> *_complete;
    QVector<QPair<QString,QString>> *_started;
    QVector<QPair<QString,QString>> *_notStarted;

    int _nownum = 0;
    int _colgames = 0;
};

#endif // THREADSTATISTICS_H
