#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievementsplayer.h>
#include <class/imagerequest.h>
#include <QEventLoop>

class ThreadStatistics : public QObject
{
    Q_OBJECT
public:
    explicit ThreadStatistics(QObject *parent = nullptr);

signals:
    void s_finished(QVector<int> numof, QVector<QPair<QString,QString>> complete, QVector<QPair<QString,QString>> started, QVector<QPair<QString,QString>> notStarted,
                    QVector<double> averagePercent, int summcolumn, QVector<QPair<QString,int>> times, QVector<QPair<QString,int>> months, QVector<QPair<QString,int>> years);
    void s_progress(int p, int row);

public slots:
    int Fill();
    void Set(SGames games, QString id);
    void OnResultAchievements(SAchievementsPlayer ach);

private:
    Settings _setting;
    QString _id;
    QVector<QPair<QString,QString>> _complete;
    QVector<QPair<QString,QString>> _started;
    QVector<QPair<QString,QString>> _notStarted;
    QVector<double> _averagePercent;
    QVector<int> _numof = {0,0,0};
    int _summcolumn=0;
    SGames _games;
    QVector<QPair<QString,int>> _times;
    QVector<QPair<QString,int>> _months;
    QVector<QPair<QString,int>> _years;

    int _nownum=0;
    int _colgames=0;
};

#endif // THREADSTATISTICS_H
