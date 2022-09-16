#include "labellight.h"

LabelLight::LabelLight(QWidget *aParent): QLabel(aParent) {
    light_ = new QGraphicsDropShadowEffect;
    light_->setColor(QColor(93, 170, 224, 255 * 0.7));
    light_->setOffset(0);
    light_->setBlurRadius(10);
    setGraphicsEffect(light_);
}

LabelLight::LabelLight(const QString &aTitle, QWidget *aParent): LabelLight(aParent) {
    setText(aTitle);
}

LabelLight::~LabelLight() {
    delete light_;
}

LabelLight &LabelLight::setLightColor(const int &aRed, const int &aGreen, const int &aBlue, const int &aAlpha) {
    light_->setColor(QColor(std::max(0, std::min(255, aRed)),
                            std::max(0, std::min(255, aGreen)),
                            std::max(0, std::min(255, aBlue)),
                            std::max(0, std::min(255, aAlpha))));
    return *this;
}

LabelLight &LabelLight::setLightColor(const QColor &aColor) {
    light_->setColor(aColor);
    return *this;
}

LabelLight &LabelLight::setBlurRadius(const int &aRadius) {
    light_->setBlurRadius(aRadius);
    return *this;
}

LabelLight *LabelLight::setlightningColor(const QColor &aColor) {
    setStyleSheet("color: " + aColor.name());
    setLightColor(aColor);
    return this;
}
