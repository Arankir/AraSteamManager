#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <QEventLoop>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/network/requestdata.h"

class ThreadStatistics : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadStatistics(QList<SGame> &games, const QString &id, QVector<SGame> &aNoAchievements, QVector<SGame> &aComplete,
                              QVector<QPair<SGame, double>> &aStarted, QVector<SGame> &aNotStarted, int &aSummColumn, QVector<int> &aTimes,
                              QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears, QObject *parent = nullptr): QObject(parent), _id(id), _games(games),
        _summcolumn(aSummColumn), _times(aTimes), _months(aMonths), _years(aYears), _noAchievements(aNoAchievements), _complete(aComplete),
        _started(aStarted), _notStarted(aNotStarted) {}

signals:
    void s_finished();
    void s_progress(int p);

private slots:
    void onResultAchievements(QList<SAchievementPlayer> ach, SGame aGame);

private:
    QString _id;
    QList<SGame> _games;
    int &_summcolumn;

    QVector<int> &_times;
    QVector<int> &_months;
    QVector<QPair<QString, int>> &_years;

    QVector<SGame> &_noAchievements;
    QVector<SGame> &_complete;
    QVector<QPair<SGame, double>> &_started;
    QVector<SGame> &_notStarted;

    int _colgames = 0;
    void updateTimes(const QDateTime &achievementTime);
};

#endif // THREADSTATISTICS_H
