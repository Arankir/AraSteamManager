#ifndef PIECHART_H
#define PIECHART_H

#include <QChart>
#include <QPieSlice>

#include "classes/common/settings.h"

class PieChart: public QChart {
    Q_OBJECT
public:
    PieChart();
    QPieSlice *addSlice(const QColor &color);

public slots:
    void updateSettings(QFlags<changedSettings> settings);

protected:
    void changeEvent(QEvent *event);
    void retranslate();
    void updateIcons();
    void updateTheme();

};

#endif // PIECHART_H
