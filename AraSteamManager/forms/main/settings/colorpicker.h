#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QSlider>
#include <QDebug>
#include <QDialog>

namespace Ui {
class ColorPicker;
}

class ColorPicker : public QDialog {
    Q_OBJECT
    QLabel *main_bg;
    QSlider *red_slider;
    QPushButton *accept_button;

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();

signals:
    void s_pickerClose(bool isAccept, QColor color);

private:
    Ui::ColorPicker *ui;
    bool isEmited_ = false;

private slots:
    void setValueColor();
};

#endif // COLORPICKER_H
