#include "progressbargood.h"

ProgressBarGood::ProgressBarGood(QWidget *aParent): ProgressBarLight(aParent) {
    this->ProgressBarGood::setColor(93, 170, 224, 255 * 0.7);
    this->ProgressBarGood::setBlurRadius(50);
}

ProgressBarLight &ProgressBarGood::setColor(const int &red, const int &green, const int &blue, const int &alpha) {
    return ProgressBarLight::setColor(red, green, blue, alpha);
}

ProgressBarLight &ProgressBarGood::setBlurRadius(const int &radius) {
    return ProgressBarLight::setBlurRadius(radius);
}
