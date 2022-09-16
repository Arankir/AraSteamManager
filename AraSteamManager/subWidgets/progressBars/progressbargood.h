#ifndef PROGRESSBARGOOD_H
#define PROGRESSBARGOOD_H

#include <QObject>
#include "./progressbarlight.h"

class ProgressBarGood : public ProgressBarLight {
    Q_OBJECT
public:
    ProgressBarGood(QWidget *parent = nullptr);

private:
    ProgressBarLight &setColor(const int &red, const int &green, const int &blue, const int &alpha = 255) override;
    ProgressBarLight &setBlurRadius(const int &radius) override;

};

#endif // PROGRESSBARGOOD_H
