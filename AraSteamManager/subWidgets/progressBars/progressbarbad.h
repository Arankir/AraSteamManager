#ifndef PROGRESSBARBAD_H
#define PROGRESSBARBAD_H

#include <QObject>
#include "./progressbarlight.h"

class ProgressBarBad : public ProgressBarLight {
    Q_OBJECT
public:
    ProgressBarBad(QWidget *parent = nullptr);

private:
    ProgressBarLight &setColor(int red, int green, int blue, int alpha = 255) override;
    ProgressBarLight &setBlurRadius(int radius) override;
};

#endif // PROGRESSBARBAD_H
