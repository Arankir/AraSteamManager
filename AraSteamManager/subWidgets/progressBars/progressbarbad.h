#ifndef PROGRESSBARBAD_H
#define PROGRESSBARBAD_H

#include <QObject>
#include "./progressbarlight.h"

class ProgressBarBad : public ProgressBarLight {
    Q_OBJECT
public:
    ProgressBarBad(QWidget *parent = nullptr);

private:
    ProgressBarLight &setColor(const int &red, const int &green, const int &blue, const int &alpha = 255) override;
    ProgressBarLight &setBlurRadius(const int &radius) override;
};

#endif // PROGRESSBARBAD_H
