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

    virtual ProgressBarLight &setColor(const int &red, const int &green, const int &blue, const int &alpha = 255);
    virtual ProgressBarLight &setBlurRadius(const int &radius);

private:
    QGraphicsDropShadowEffect *light_;

};

#endif // PROGRESSBARLIGHT_H
