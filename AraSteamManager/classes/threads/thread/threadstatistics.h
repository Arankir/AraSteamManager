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
    explicit ThreadStatistics(QList<SGame> &games, const QString &id, int &aAchievementsCount,
                              QList<SGame> &aNoAchievements, QList<SGame> &aComplete, QList<QPair<SGame, double>> &aStarted, QList<SGame> &aNotStarted,
                              QVector<int> &aTimes, QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears, QObject *parent = nullptr):
        QObject(parent), _id(id), _games(games), _achievementsCount(aAchievementsCount),
        _times(aTimes), _months(aMonths), _years(aYears),
        _noAchievements(aNoAchievements), _complete(aComplete), _started(aStarted), _notStarted(aNotStarted) {}

signals:
    void s_finished();
    void s_progress(int p);

private slots:
    void onResultAchievements(QList<SAchievementPlayer> ach, SGame aGame);
    void updateTimes(const QDateTime &achievementTime);

private:
    QString _id;
    QList<SGame> _games;
    int &_achievementsCount;

    QVector<int> &_times;
    QVector<int> &_months;
    QVector<QPair<QString, int>> &_years;

    QList<SGame> &_noAchievements;
    QList<SGame> &_complete;
    QList<QPair<SGame, double>> &_started;
    QList<SGame> &_notStarted;

};

#endif // THREADSTATISTICS_H
