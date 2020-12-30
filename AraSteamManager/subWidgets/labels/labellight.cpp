#include "labellight.h"

LabelLight::LabelLight(QWidget *aParent): QLabel(aParent) {
    _light = new QGraphicsDropShadowEffect;
    _light->setColor(QColor(93, 170, 224, 255 * 0.7));
    _light->setOffset(0);
    _light->setBlurRadius(10);
    setGraphicsEffect(_light);
}

LabelLight::~LabelLight() {
    delete _light;
}

LabelLight &LabelLight::setLightColor(int aRed, int aGreen, int aBlue, int aAlpha) {
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

LabelLight &LabelLight::setLightColor(QColor aColor) {
    _light->setColor(aColor);
    return *this;
}

LabelLight &LabelLight::setBlurRadius(int aRadius) {
    _light->setBlurRadius(aRadius);
    return *this;
}
