#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
#include <class/steamapi/Sgames.h>
#include <class/settings.h>
#include <class/steamapi/Sachievements.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistics(QString id, SGames games, QWidget *parent = nullptr);
    ~FormStatistics();

public slots:
    void OnResultAchievements(SAchievementsPlayer ach);

private:
    //Переименовать потом
    Ui::FormStatistics *ui;
    Settings _setting;
    QString _id;
    int _numof[3] = {0,0,0};
    QVector<QPair<QString,QString>> _complete;
    QVector<QPair<QString,QString>> _started;
    QVector<QPair<QString,QString>> _notStarted;
    double *averagePercent;
    int _nownum=0;
    int _summcolumn=0;
    int _colgames=0;
    SGames _games;
    QVector<QPair<QString,int>> _times;
    QVector<QPair<QString,int>> _months;
    QVector<QPair<QString,int>> _years;
};

#endif // FORMSTATISTICS_H
