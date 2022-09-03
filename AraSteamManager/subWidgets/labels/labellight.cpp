#include "labellight.h"

LabelLight::LabelLight(QWidget *aParent): QLabel(aParent) {
    _light = new QGraphicsDropShadowEffect;
    _light->setColor(QColor(93, 170, 224, 255 * 0.7));
    _light->setOffset(0);
    _light->setBlurRadius(10);
    setGraphicsEffect(_light);
}

LabelLight::LabelLight(const QString &aTitle, QWidget *aParent): LabelLight(aParent) {
    setText(aTitle);
}

LabelLight::~LabelLight() {
    delete _light;
}

LabelLight &LabelLight::setLightColor(int aRed, int aGreen, int aBlue, int aAlpha) {
    aRed    = std::max(0, std::min(255, aRed));
    aGreen  = std::max(0, std::min(255, aGreen));
    aBlue   = std::max(0, std::min(255, aBlue));
    aAlpha  = std::max(0, std::min(255, aAlpha));
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

LabelLight *LabelLight::setlightningColor(const QColor &aColor) {
    setStyleSheet("color: " + aColor.name());
    setLightColor(aColor);
    return this;
}
