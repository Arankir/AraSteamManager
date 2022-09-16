#ifndef ACHIEVEMENTCOUNTCHART_H
#define ACHIEVEMENTCOUNTCHART_H

#include <QChart>
#include <QtCharts/QLineSeries>
#include "classes/common/settings.h"

#define AcSeries QLineSeries

class AchievementCountChart : public QChart {
public:
    AchievementCountChart();
    void addAxisX(const QStringList &list);

    void setSeriesColor(AcSeries *series, const QColor &color);
    AcSeries *getSeries(const QString &name);
public slots:
    void updateSettings(QFlags<changedSettings> settings);

    void addLineToChart(QVector<QPointF> &datas, const QString &name, const QColor &color);
protected:
    void changeEvent(QEvent *event);
    void retranslate();
    void updateIcons();
    void updateTheme();
    void updateChartHeight();
    void updateChartWidth();
};

#endif // ACHIEVEMENTCOUNTCHART_H
