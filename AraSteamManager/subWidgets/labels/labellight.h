#ifndef LABELLIGHT_H
#define LABELLIGHT_H

#include <QObject>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

class LabelLight : public QLabel {
    Q_OBJECT
public:
    LabelLight(QWidget *parent = nullptr);
    ~LabelLight();

    LabelLight &setLightColor(int aRed, int aGreen, int aBlue, int aAlpha);
    LabelLight &setLightColor(QColor aColor);
    LabelLight &setBlurRadius(int radius);

private:
    QGraphicsDropShadowEffect *_light;
    
};

#endif // LABELLIGHT_H
