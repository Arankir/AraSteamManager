#ifndef THREADSTATISTICS_H
#define THREADSTATISTICS_H

#include <QObject>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/Network/requestdata.h>
#include <QEventLoop>

class ThreadStatistics : public QObject
{
    Q_OBJECT
public:
    explicit ThreadStatistics(SGames a_games, QString a_id, QObject *a_parent = nullptr):QObject(a_parent),_id(a_id),_games(a_games), _averagePercent(a_games.GetCount()){};

signals:
    void s_finished(QVector<int> numof, QVector<QPair<QString,QString>> complete, QVector<QPair<QString,QString>> started, QVector<QPair<QString,QString>> notStarted,
                    QVector<double> averagePercent, int summcolumn, QVector<int> times, QVector<int> months, QVector<QPair<QString,int>> years);
    void s_progress(int p, int row);

public slots:
    int Fill();
    void OnResultAchievements(SAchievementsPlayer ach);

private:
    Settings _setting;
    QString _id;
    SGames _games;
    QVector<double> _averagePercent;
    QVector<int> _numof = {0,0,0};
    int _summcolumn=0;
    QVector<int> _times ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector<int> _months ={0,0,0,0,0,0,0,0,0,0,0,0};
    QVector<QPair<QString,int>> _years;
    QVector<QPair<QString,QString>> _complete;
    QVector<QPair<QString,QString>> _started;
    QVector<QPair<QString,QString>> _notStarted;

    int _nownum=0;
    int _colgames=0;
};

#endif // THREADSTATISTICS_H
