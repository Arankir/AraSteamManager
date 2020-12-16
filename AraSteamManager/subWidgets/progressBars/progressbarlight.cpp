#include "progressbarlight.h"

ProgressBarLight::ProgressBarLight(QWidget *aParent): QProgressBar(aParent) {
    _light = new QGraphicsDropShadowEffect;
    _light->setColor(QColor(93, 170, 224, 255 * 0.7));
    _light->setOffset(0);
    _light->setBlurRadius(50);
    setGraphicsEffect(_light);
}

ProgressBarLight::~ProgressBarLight() {
    delete _light;
}

ProgressBarLight &ProgressBarLight::setColor(int aRed, int aGreen, int aBlue, int aAlpha) {
    if (aRed > 255) {
        aRed = 255;
    }
    if (aGreen > 255) {
        aGreen = 255;
    }
    if (aBlue > 255) {
        aBlue = 255;
    }
    if (aAlpha > 255) {
        aAlpha = 255;
    }
    if (aRed < 0) {
        aRed = 0;
    }
    if (aGreen < 0) {
        aGreen = 0;
    }
    if (aBlue < 0) {
        aBlue = 0;
    }
    if (aAlpha < 0) {
        aAlpha = 0;
    }
    _light->setColor(QColor(aRed, aGreen, aBlue, aAlpha));
    return *this;
}

ProgressBarLight &ProgressBarLight::setBlurRadius(int aRadius) {
    _light->setBlurRadius(aRadius);
    return *this;
}
