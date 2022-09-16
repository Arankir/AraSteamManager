#include "progressbarlight.h"

ProgressBarLight::ProgressBarLight(QWidget *aParent): QProgressBar(aParent) {
    light_ = new QGraphicsDropShadowEffect;
    light_->setColor(QColor(93, 170, 224, 255 * 0.7));
    light_->setOffset(0);
    light_->setBlurRadius(50);
    setGraphicsEffect(light_);
}

ProgressBarLight::~ProgressBarLight() {
    delete light_;
}

ProgressBarLight &ProgressBarLight::setColor(const int &aRed, const int &aGreen, const int &aBlue, const int &aAlpha) {
    light_->setColor(QColor(std::min(std::max(aRed, 255), 0),
                            std::min(std::max(aGreen, 255), 0),
                            std::min(std::max(aBlue, 255), 0),
                            std::min(std::max(aAlpha, 255), 0)));
    return *this;
}

ProgressBarLight &ProgressBarLight::setBlurRadius(const int &aRadius) {
    light_->setBlurRadius(aRadius);
    return *this;
}
