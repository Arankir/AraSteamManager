#include "formreachedfilter.h"
#include "ui_formreachedfilter.h"

FormReachedFilter::FormReachedFilter(QWidget *parent): Form(parent),
ui(new Ui::FormReachedFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    updateIcons();
//    ui->RadioButtonAll->setChecked(true);
//    connect(ui->RadioButtonReached, &QRadioButton::pressed, this, [=, this]() {emit s_radioButtonChange(ReachedType::reached);});
//    connect(ui->RadioButtonAll, &QRadioButton::pressed, this, [=, this]() {emit s_radioButtonChange(ReachedType::all);});
//    connect(ui->RadioButtonNotReached, &QRadioButton::pressed, this, [=, this]() {emit s_radioButtonChange(ReachedType::notReached);});
//    connect(ui->Slider, &QSlider::valueChanged, this, &FormReachedFilter::slideValueChanged);
    connect(ui->pushButton, &QPushButton::pressed, this, &FormReachedFilter::onButtonClick);
}

FormReachedFilter::~FormReachedFilter() {
    delete ui;
}

void FormReachedFilter::updateIcons() {
//    ui->LabelReached    ->setPixmap(QPixmap(Images::reached())          .scaled(15, 15));
//    ui->LabelNotReached ->setPixmap(QPixmap(Images::notReached())       .scaled(15, 15));
//    ui->LabelAll        ->setPixmap(QPixmap(Images::allAchievements())  .scaled(15, 15));
    switch (type_) {
    case ReachedType::reached: {
        ui->pushButton->setIcon(QIcon(Images::reached()));
        break;
    }
    case ReachedType::all: {
        ui->pushButton->setIcon(QIcon(Images::allAchievements()));
        break;
    }
    case ReachedType::notReached: {
        ui->pushButton->setIcon(QIcon(Images::notReached()));
        break;
    }
    default: {

    }
    }
}

void FormReachedFilter::retranslate() {
    ui->retranslateUi(this);
}

void FormReachedFilter::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormReachedFilter::onButtonClick() {
    switch (type_) {
    case ReachedType::reached: {
        type_ = ReachedType::all;
        emit s_radioButtonChange(ReachedType::all);;
        break;
    }
    case ReachedType::all: {
        type_ = ReachedType::notReached;
        emit s_radioButtonChange(ReachedType::notReached);
        break;
    }
    case ReachedType::notReached: {
        type_ = ReachedType::reached;
        emit s_radioButtonChange(ReachedType::reached);
        break;
    }
    default: {

    }
    }
    updateIcons();
}

void FormReachedFilter::setType(const ReachedType &aType) {
//    if (aType != ReachedType::none) {
//        ui->Slider->setValue(static_cast<int>(aType));
//    }
    type_ = aType;
    updateIcons();
//    switch (aType) {
//    case ReachedType::reached: {
//        ui->RadioButtonReached->setChecked(true);
//        break;
//    }
//    case ReachedType::all: {
//        ui->RadioButtonAll->setChecked(true);
//        break;
//    }
//    case ReachedType::notReached: {
//        ui->RadioButtonNotReached->setChecked(true);
//        break;
//    }
//    default: {

//    }
//    }
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
