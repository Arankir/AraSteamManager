#include "progressbarbad.h"

ProgressBarBad::ProgressBarBad(QWidget *aParent): ProgressBarLight(aParent) {
    this->ProgressBarBad::setColor(255, 0, 0, 255 * 0.7);
    this->ProgressBarBad::setBlurRadius(50);
}

ProgressBarLight &ProgressBarBad::setColor(const int &red, const int &green, const int &blue, const int &alpha) {
    return ProgressBarLight::setColor(red, green, blue, alpha);
}

ProgressBarLight &ProgressBarBad::setBlurRadius(const int &radius) {
    return ProgressBarLight::setBlurRadius(radius);
}
