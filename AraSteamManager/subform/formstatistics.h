#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
#include <class/steamapi/Sgames.h>
#include <class/settings.h>
#include <class/steamapi/Sachievements.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>
#include <class/Threads/threading.h>

#include <class/NotMine/donutbreakdownchart.h>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QVXYModelMapper>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QVBarModelMapper>
#include <QtWidgets/QHeaderView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistics(QString id, SGames games, QString name, QWidget *parent = nullptr);
    ~FormStatistics();

public slots:
    void OnFinish(QVector<int> numof, QVector<QPair<QString,QString>> complete, QVector<QPair<QString,QString>> started, QVector<QPair<QString,QString>> notStarted,
                                  QVector<double> averagePercent, int summcolumn, QVector<int> times, QVector<int> months, QVector<QPair<QString,int>> years);

private:
    Ui::FormStatistics *ui;
    Settings _setting;
    QString _id;
    QVector<QPair<QString,QString>> _complete;
    QVector<QPair<QString,QString>> _started;
    QVector<QPair<QString,QString>> _notStarted;
    QVector<double> _averagePercent;
    QVector<int> _numof = {0,0,0};
    int _summcolumn=0;
    SGames _games;
    QString _name;
    QVector<int> _times ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector<int> _months ={0,0,0,0,0,0,0,0,0,0,0,0};
    QVector<QPair<QString,int>> _years;
};

#endif // FORMSTATISTICS_H
