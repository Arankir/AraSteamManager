#ifndef PROGRESSBARLIGHT_H
#define PROGRESSBARLIGHT_H

#include <QObject>
#include <QProgressBar>
#include <QGraphicsDropShadowEffect>

class ProgressBarLight : public QProgressBar {
    Q_OBJECT
public:
    ProgressBarLight(QWidget *parent = nullptr);
    ~ProgressBarLight();

    virtual ProgressBarLight &setColor(int red, int green, int blue, int alpha = 255);
    virtual ProgressBarLight &setBlurRadius(int radius);

private:
    QGraphicsDropShadowEffect *_light;

};

#endif // PROGRESSBARLIGHT_H
