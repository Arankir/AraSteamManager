#include "piechart.h"
#include "classes/common/theme.h"

#include <QPieSeries>

PieChart::PieChart() {
    setBackgroundVisible(false);
    setAnimationOptions(QChart::SeriesAnimations);
    legend()->setAlignment(Qt::AlignBottom);
    setMargins(QMargins(1, 1, 1, 1));
    QPieSeries *series = new QPieSeries();
    addSeries(series);
    legend()->setLabelColor(Theme::getCurrentTheme().text.getColor());
}

QPieSlice *PieChart::addSlice(const QColor &aColor) {
    QPieSlice *slice = new QPieSlice();
    slice->setBrush(aColor);
    slice->setBorderColor(Theme::getCurrentTheme().border.color);
    slice->setLabelVisible(true);
    slice->setLabelPosition(QPieSlice::LabelOutside);
    slice->setLabelColor(Theme::getCurrentTheme().text.getColor());
    QObject::connect(slice, &QPieSlice::hovered, slice, &QPieSlice::setExploded);
    QList<QAbstractSeries*> localSeries = series();
    if (localSeries.count() > 0) {
        QPieSeries *pieSeries = dynamic_cast<QPieSeries*>(localSeries[0]);
        if (pieSeries) {
            pieSeries->append(slice);
        } else {
            qWarning() << "error series is not a pie";
        }
    } else {
        qWarning() << "error missing series";
    }
    return slice;
}

void PieChart::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateTheme();
    }
}

void PieChart::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void PieChart::retranslate() {
//    ui->retranslateUi(this);
}

void PieChart::updateIcons() {

}

void PieChart::updateTheme() {
    QList<QAbstractSeries*> localSeries = series();
    for (QAbstractSeries *oneSeries: localSeries) {
        QPieSeries *pieSeries = dynamic_cast<QPieSeries*>(oneSeries);
        if (pieSeries) {
            QList<QPieSlice*> slices = pieSeries->slices();
            for (QPieSlice *slice: slices) {
                slice->setBorderColor(Theme::getCurrentTheme().border.color);
                slice->setLabelColor(Theme::getCurrentTheme().text.color);
            }
        }
    }
    legend()->setLabelColor(Theme::getCurrentTheme().text.color);
    updateIcons();
}
