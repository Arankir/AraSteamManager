#include "colorpicker.h"
#include "ui_colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(420, 300);
    main_bg = new QLabel(this);
    red_slider = new QSlider(this);
    accept_button = new QPushButton(tr("Принять"), this);

    main_bg->setFixedSize(400, 250);
    main_bg->move(10, 12);

    accept_button->move(main_bg->x() + main_bg->width() - accept_button->sizeHint().width(), main_bg->y() + main_bg->height() + 4);

    red_slider->setOrientation(Qt::Horizontal);
    red_slider->setFixedSize(main_bg->width() - accept_button->sizeHint().width() - 4, 20);
    red_slider->setRange(0, 255);
    red_slider->move(10, main_bg->y() + main_bg->height() + 4);
    red_slider->setValue(0);
    QObject::connect(red_slider, SIGNAL(valueChanged(int)),this, SLOT(setValueColor()));
    QObject::connect(accept_button, &QPushButton::clicked, this, [=]() {
        QColor color;
        color.setHslF(1.0f * red_slider->value() / 255, 1.0f, 0.5f);
        emit s_pickerClose(true, color);
        isEmited_ = true;
        this->close();
        this->deleteLater();
    });

    QStringList stops;
    for (float stop = 0.0f; stop <= 1; stop += 0.01f) {
        QColor color;
        color.setHslF(stop, 1.0f, 0.5f);
        stops << QString("stop: %1 %2").arg(QString::number(stop, 'f', 2), color.name());
    }

    QString qss = "QSlider::groove:horizontal{"\
                  "height: 10px;"\
                  "background-color:"\
                    "qlineargradient(x1:0, x2: 1, " + stops.join(", ") + ");"
              "border-radius:4px;"\
              "}"\
              "QSlider::handle:horizontal {"\
                  "background-color:#aaa;"\
                  "border: 1px solid #5c5c5c;"\
                  "width: 18px;"\
                  "margin: -2px 0;"\
                  "border-radius: 3px;"\
              "};";

    red_slider->setStyleSheet(qss);

    setValueColor();
}

ColorPicker::~ColorPicker() {
    if (!isEmited_) {
        emit s_pickerClose(false, QColor());
    }
    delete ui;
}

void ColorPicker :: setValueColor() {
    int r = red_slider->value();

    QColor color;
    color.setHslF(1.0f * r / 255, 1.0f, 0.5f);

    main_bg->setStyleSheet("QLabel{background-color:" + color.name() + ";"
                           ";border-radius:5px;}");

}
