#ifndef PROGRESSBARGOOD_H
#define PROGRESSBARGOOD_H

#include <QObject>
#include "./progressbarlight.h"

class ProgressBarGood : public ProgressBarLight {
    Q_OBJECT
public:
    ProgressBarGood(QWidget *parent = nullptr);

private:
    ProgressBarLight &setColor(int red, int green, int blue, int alpha = 255) override;
    ProgressBarLight &setBlurRadius(int radius) override;

};

#endif // PROGRESSBARGOOD_H
