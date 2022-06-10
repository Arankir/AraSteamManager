#include "achievementcountchart.h"
#include "classes/common/theme.h"

#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

AchievementCountChart::AchievementCountChart() {
    legend()->setAlignment(Qt::AlignBottom);
    setAnimationOptions(QChart::NoAnimation);
    setBackgroundVisible(false);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");

    addAxis(axisY, Qt::AlignLeft);

    updateTheme();
}

void AchievementCountChart::addAxisX(const QStringList &aList) {
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(aList);

    addAxis(axisX, Qt::AlignBottom);
    axisX->setLabelsColor(Theme::getCurrentTheme().text.color);
}

void AchievementCountChart::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateTheme();
    }
}

void AchievementCountChart::updateTheme() {
    auto axess = axes();
    for (auto axis: axess) {
        axis->setLabelsColor(Theme::getCurrentTheme().text.color);
        axis->setGridLineColor(Theme::getCurrentTheme().border.color);
    }
    setTitleBrush(Theme::getCurrentTheme().text.color);
    legend()->setLabelColor(Theme::getCurrentTheme().text.color);
    updateIcons();
}

void AchievementCountChart::updateIcons() {

}

void AchievementCountChart::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void AchievementCountChart::retranslate() {
//    ui->retranslateUi(this);
}

int roundToDesimal(int aData) {
    const double delta = 0.1;
    static const QVector<double> logs {0, log10(1), log10(2), log10(3), log10(4), log10(5), log10(6), log10(7), log10(8), log10(9), 1};
    int newData = aData;
    double dDecimal = log10(aData);
    int iDecimal = dDecimal;
    dDecimal -= iDecimal;
    for (int i = 1; i < 11; ++i) {
        if (dDecimal < logs[i]) {
            newData = pow(10, logs[i - 1] + iDecimal);
            break;
        }
    }
    if (newData % 10 == 9) {
        ++newData;
    }
    for (int i = 0; i < 20; ++i) {
        if (abs((1.0 * aData/newData) - 0.8) < delta) {
            break;
        }
        newData += pow(10, iDecimal - 1);
    }
    return newData;
}

void AchievementCountChart::updateChartHeight() {
    if (axes(Qt::Vertical).count() > 0) {
        int max = 9;
        for (auto sery: series()) {
            if (auto realSery = dynamic_cast<AcSeries*>(sery)) {
                auto points = realSery->points();
                auto maxElement = std::max_element(points.begin(),
                                                    points.end(),
                                                    [=](const QPointF point1, const QPointF point2) {
                                                        return point1.y() < point2.y();
                                                    });
                if (maxElement < points.end()) {
                    if ((*maxElement).y() > max) {
                        max = (*maxElement).y();
                    }
                }
            }
        }
        axes(Qt::Vertical).at(0)->setRange(0, roundToDesimal(max));
    } else {
        qWarning() << "error missing vertical axis";
    }
}

void AchievementCountChart::updateChartWidth() {
    if (axes(Qt::Horizontal).count() > 0) {
        QStringList categories;
        if (auto bar = dynamic_cast<QBarCategoryAxis*>(axes(Qt::Horizontal).at(0))) {
            categories = bar->categories();
        } else {
            return;
        }
        int min = 4000;
        int max = 1;
        for (auto sery: series()) {
            if (auto realSery = dynamic_cast<AcSeries*>(sery)) {
                auto points = realSery->points();
                if (points.size() > 0) {
                    auto minMax = std::minmax_element(points.begin(),
                                                      points.end(),
                                                      [=](const QPointF &point1, const QPointF &point2) {
                                                          return point1.x() < point2.x();
                                                      });
                    min = std::min(categories.at((*(minMax.first)).x()).toInt(), min);
                    max = std::max(categories.at((*(minMax.second)).x()).toInt(), max);
                }
            }
        }
        if (min == 4000) {
            min = 0;
        }
        for (auto axis: axes(Qt::Horizontal)) {
            axis->setRange(min, max);
        }
    } else {
        qWarning() << "error missing horizontal axis";
    }
}

QColor colorForLabels(const QColor &aColor) {
    QColor label(aColor);
    label.setHsl(aColor.hue(), (int)(aColor.saturation() * 0.5), (int)(aColor.lightness() * 0.7));
    return label;
}

void AchievementCountChart::setSeriesColor(AcSeries *aSeries, const QColor &aColor) {
    aSeries->setColor(aColor);
    aSeries->setPointLabelsColor(colorForLabels(aColor));
}

void AchievementCountChart::addLineToChart(QVector<QPointF> &aDatas, const QString &aName, const QColor &aColor) {
    AcSeries *lineSeries = new QLineSeries(this);
    for (auto data: aDatas) {
        lineSeries->append(data);
    }
    addSeries(lineSeries);
    lineSeries->setName(aName);
    if (axes(Qt::Horizontal).count() > 0) {
        lineSeries->attachAxis(axes(Qt::Horizontal).at(0));
    } else {
        qWarning() << "error missing horizontal axis";
    }
    if (axes(Qt::Vertical).count() > 0) {
        lineSeries->attachAxis(axes(Qt::Vertical).at(0));
    } else {
        qWarning() << "error missing vertical axis";
    }
    lineSeries->setPointLabelsVisible(true);
    lineSeries->setPointLabelsFont(QFont(Theme::defaultFont(), 14));
    lineSeries->setPointLabelsFormat("@yPoint");

    setSeriesColor(lineSeries, aColor);
    lineSeries->setPointsVisible(true);
    lineSeries->setPointLabelsClipping(false);
    updateChartWidth();
    updateChartHeight();
}

AcSeries *AchievementCountChart::getSeries(const QString &aName) {
    auto localSeries = series();
    auto iterator = std::find_if(localSeries.begin(),
                        localSeries.end(),
                        [&](QAbstractSeries *lSeries) {
                            return lSeries->name() == aName;
                        });
    if (iterator != localSeries.end()) {
        return dynamic_cast<AcSeries *>(*iterator);
    } else {
        return nullptr;
    }
}
