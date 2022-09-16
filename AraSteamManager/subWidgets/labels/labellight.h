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

    LabelLight &setLightColor(const int &red, const int &green, const int &blue, const int &alpha);
    LabelLight &setLightColor(const QColor &color);
    LabelLight &setBlurRadius(const int &radius);

    LabelLight *setlightningColor(const QColor &color);


private:
    QGraphicsDropShadowEffect *light_;
    
};

#endif // LABELLIGHT_H
