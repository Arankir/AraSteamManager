#ifndef ACHIEVEMENTCOUNTCHART_H
#define ACHIEVEMENTCOUNTCHART_H

#include <QChart>
#include <QtCharts/QLineSeries>
#include "classes/common/settings.h"

#define AcSeries QLineSeries

class AchievementCountChart : public QChart {
public:
    AchievementCountChart();
    void addAxisX(const QStringList &aList);

    void setSeriesColor(AcSeries *aSeries, const QColor &aColor);
    AcSeries *getSeries(const QString &aName);
public slots:
    void updateSettings(QFlags<changedSettings> aSettings);

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
