#include "formreachedfilter.h"
#include "ui_formreachedfilter.h"

FormReachedFilter::FormReachedFilter(QWidget *parent): Form(parent),
ui(new Ui::FormReachedFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    updateIcons();
    ui->RadioButtonAll->setChecked(true);
    connect(ui->RadioButtonReached, &QRadioButton::pressed, this, [=]() {emit s_radioButtonChange(ReachedType::reached);});
    connect(ui->RadioButtonAll, &QRadioButton::pressed, this, [=]() {emit s_radioButtonChange(ReachedType::all);});
    connect(ui->RadioButtonNotReached, &QRadioButton::pressed, this, [=]() {emit s_radioButtonChange(ReachedType::notReached);});
//    connect(ui->Slider, &QSlider::valueChanged, this, &FormReachedFilter::slideValueChanged);
}

FormReachedFilter::~FormReachedFilter() {
    delete ui;
}

void FormReachedFilter::updateIcons() {
    ui->LabelReached    ->setPixmap(QPixmap(Images::reached())          .scaled(15, 15));
    ui->LabelNotReached ->setPixmap(QPixmap(Images::notReached())       .scaled(15, 15));
    ui->LabelAll        ->setPixmap(QPixmap(Images::allAchievements())  .scaled(15, 15));
}

void FormReachedFilter::retranslate() {
    ui->retranslateUi(this);
}

void FormReachedFilter::updateSettings() {
    updateIcons();
}

void FormReachedFilter::setType(const ReachedType &aType) {
//    if (aType != ReachedType::none) {
//        ui->Slider->setValue(static_cast<int>(aType));
//    }
    switch (aType) {
    case ReachedType::reached: {
        ui->RadioButtonReached->setChecked(true);
        break;
    }
    case ReachedType::all: {
        ui->RadioButtonAll->setChecked(true);
        break;
    }
    case ReachedType::notReached: {
        ui->RadioButtonNotReached->setChecked(true);
        break;
    }
    default: {

    }
    }
}

void FormReachedFilter::update() {
    slideValueChanged();
}

void FormReachedFilter::slideValueChanged() {
//    if (ui->Slider->value() < 3) {
//        emit s_radioButtonChange(static_cast<ReachedType>(ui->Slider->value()));
//    } else {
//        emit s_radioButtonChange(ReachedType::none);
//    }
}
