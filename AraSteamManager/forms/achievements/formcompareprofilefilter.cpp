#include "formcompareprofilefilter.h"
#include "ui_formcompareprofilefilter.h"

FormCompareProfileFilter::FormCompareProfileFilter(QWidget *parent): QWidget(parent),
ui(new Ui::FormCompareProfileFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    setIcons();
    connect(ui->Slider, &QSlider::valueChanged, this, &FormCompareProfileFilter::slideValueChanged);
}

void FormCompareProfileFilter::updateSettings() {
    setIcons();
}

void FormCompareProfileFilter::setIcons() {
    ui->LabelReached    ->setPixmap(QPixmap(Images::reached())          .scaled(15, 15));
    ui->LabelNotReached ->setPixmap(QPixmap(Images::notReached())       .scaled(15, 15));
    ui->LabelAll        ->setPixmap(QPixmap(Images::allAchievements())  .scaled(15, 15));
}

FormCompareProfileFilter::~FormCompareProfileFilter() {
    delete ui;
}

void FormCompareProfileFilter::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormCompareProfileFilter::setType(ReachedType aType) {
    if (aType != ReachedType::none) {
        ui->Slider->setValue(static_cast<int>(aType));
    }
}

void FormCompareProfileFilter::update() {
    slideValueChanged();
}

void FormCompareProfileFilter::slideValueChanged() {
    if (ui->Slider->value() < 3) {
        emit s_radioButtonChange(_name, static_cast<ReachedType>(ui->Slider->value()));
    } else {
        emit s_radioButtonChange(_name, ReachedType::none);
    }
}
