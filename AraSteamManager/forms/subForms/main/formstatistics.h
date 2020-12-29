#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
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
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/threads/threading.h"

#include "subWidgets/charts/donutbreakdownchart.h"

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget {
    Q_OBJECT

public slots:
    void onFinish();
    void createThread();

    void updateSettings();
    void setIcons();
public:
    explicit FormStatistics(const QString &id, SGames &games, const QString &name, QWidget *parent = nullptr);
    ~FormStatistics();

signals:
    void s_statisticsLoaded(int progress, int row);
    void s_finish();
    void s_return_to_profile(QWidget*);

private slots:
    void changeEvent(QEvent *event);
    void retranslate();

private:
    Ui::FormStatistics *ui;
    QString _id;
    QVector<QPair<QString,QString>> _complete;
    QVector<QPair<QString,QString>> _started;
    QVector<QPair<QString,QString>> _notStarted;
    QVector<double> _averagePercent;
    QVector<int> _numof = {0, 0, 0};
    int _summcolumn = 0;
    SGames _games;
    QString _name;
    QVector<int> _times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<int> _months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<QPair<QString,int>> _years;
    double _totalAverage;
    DonutBreakdownChart *_donutBreakdown;
    QChart *_chartT;
    QChart *_chartM;
    QChart *_chartY;
};

#endif // FORMSTATISTICS_H
