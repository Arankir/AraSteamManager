#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sachievements.h"
#include "class/Network/requestdata.h"
#include <QEventLoop>

class ThreadStatistics : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadStatistics(SGames &games, const QString &id, QVector<int> &aNumOf, QVector<QPair<QString,QString> > &aComplete,
                              QVector<QPair<QString,QString>> &aStarted, QVector<QPair<QString,QString>> &aNotStarted,
                              QVector<double> &aAveragePercent, int &aSummColumn, QVector<int> &aTimes,
                              QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears, QObject *parent = nullptr): QObject(parent), _id(id), _games(games),
        _averagePercent(&aAveragePercent), _numof(&aNumOf), _summcolumn(&aSummColumn), _times(&aTimes), _months(&aMonths), _years(&aYears), _complete(&aComplete),
        _started(&aStarted), _notStarted(&aNotStarted) {}

signals:
    void s_finished();
    void s_progress(int p, int row);

private slots:
    void onResultAchievements(SAchievementsPlayer *ach);

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

    int _colgames = 0;
    void updateTimes(const QDateTime &achievementTime);
};

#endif // THREADSTATISTICS_H
