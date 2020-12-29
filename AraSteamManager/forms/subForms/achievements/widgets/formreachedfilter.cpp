#include "formreachedfilter.h"
#include "ui_formreachedfilter.h"

FormReachedFilter::FormReachedFilter(QWidget *parent): QWidget(parent),
ui(new Ui::FormReachedFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    setIcons();
    connect(ui->Slider, &QSlider::valueChanged, this, &FormReachedFilter::slideValueChanged);
}

void FormReachedFilter::updateSettings() {
    setIcons();
}

void FormReachedFilter::setIcons() {
    ui->LabelReached    ->setPixmap(QPixmap(Images::reached())          .scaled(15, 15));
    ui->LabelNotReached ->setPixmap(QPixmap(Images::notReached())       .scaled(15, 15));
    ui->LabelAll        ->setPixmap(QPixmap(Images::allAchievements())  .scaled(15, 15));
}

FormReachedFilter::~FormReachedFilter() {
    delete ui;
}

void FormReachedFilter::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormReachedFilter::setType(ReachedType aType) {
    if (aType != ReachedType::none) {
        ui->Slider->setValue(static_cast<int>(aType));
    }
}

void FormReachedFilter::update() {
    slideValueChanged();
}

void FormReachedFilter::slideValueChanged() {
    if (ui->Slider->value() < 3) {
        emit s_radioButtonChange(static_cast<ReachedType>(ui->Slider->value()));
    } else {
        emit s_radioButtonChange(ReachedType::none);
    }
}
