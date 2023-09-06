#ifndef LABELLIGHT_H
#define LABELLIGHT_H

#include <QObject>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

class LabelLight : public QLabel {
    Q_OBJECT
public:
    LabelLight(QWidget *parent = nullptr);
    LabelLight(const QString &title, QWidget *parent = nullptr);
    ~LabelLight();

    LabelLight &setLightColor(int red, int green, int blue, int alpha);
    LabelLight &setLightColor(const QColor &color);
    LabelLight &setBlurRadius(int radius);

    LabelLight *setlightningColor(const QColor &color);


private:
    QGraphicsDropShadowEffect *light_;
    
};

#endif // LABELLIGHT_H
