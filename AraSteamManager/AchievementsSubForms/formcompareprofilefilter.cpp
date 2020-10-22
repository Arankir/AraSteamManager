#include "formcompareprofilefilter.h"
#include "ui_formcompareprofilefilter.h"

FormCompareProfileFilter::FormCompareProfileFilter(QWidget *aParent): FormCompareProfileFilter("", "", "", aParent) {

}

FormCompareProfileFilter::FormCompareProfileFilter(const QString &all, const QString &reached, const QString &notReached, QWidget *parent): QWidget(parent),
ui(new Ui::FormCompareProfileFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    setIcons();
    ui->RadioButtonAll->setReachedType(ReachedType::all);
    ui->RadioButtonReached->setReachedType(ReachedType::reached);
    ui->RadioButtonNotReached->setReachedType(ReachedType::notReached);
    connect(ui->RadioButtonAll,        &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    connect(ui->RadioButtonReached,    &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    connect(ui->RadioButtonNotReached, &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    setTitles(all, reached, notReached);
}

void FormCompareProfileFilter::updateSettings() {
    setIcons();
}

void FormCompareProfileFilter::setIcons() {
    QString iconsColor = Settings::getIconsColor();
    ui->RadioButtonAll          ->setIcon(QIcon(Images::allAchievements()));
    ui->RadioButtonReached      ->setIcon(QIcon(Images::reached()));
    ui->RadioButtonNotReached   ->setIcon(QIcon(Images::notReached()));
}

FormCompareProfileFilter::~FormCompareProfileFilter() {
    delete ui;
}

void FormCompareProfileFilter::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormCompareProfileFilter::setTitles(const QString &aTitleAll, const QString &aTitleReached, const QString &aTitleNotReached) {
    ui->RadioButtonAll->setText(aTitleAll);
    ui->RadioButtonReached->setText(aTitleReached);
    ui->RadioButtonNotReached->setText(aTitleNotReached);
}

void FormCompareProfileFilter::setType(ReachedType aType) {
    switch (aType) {
    case ReachedType::all:
        ui->RadioButtonAll->setChecked(true);
        ui->RadioButtonAll->click();
        break;
    case ReachedType::reached:
        ui->RadioButtonReached->setChecked(true);
        ui->RadioButtonReached->click();
        break;
    case ReachedType::notReached:
        ui->RadioButtonNotReached->setChecked(true);
        ui->RadioButtonNotReached->click();
        break;
    default:
        break;
    }
}

void FormCompareProfileFilter::update() {
    if(ui->RadioButtonAll->isChecked()) {
        ui->RadioButtonAll->click();
    } else if(ui->RadioButtonReached->isChecked()) {
        ui->RadioButtonReached->click();
    } else if(ui->RadioButtonNotReached->isChecked()) {
        ui->RadioButtonNotReached->click();
    }
}

void FormCompareProfileFilter::radioButtonClick() {
    QRadioButtonWithData *rb = static_cast<QRadioButtonWithData*>(sender());
    if (rb) {
        emit s_radioButtonChange(_name, rb->getReachedType());
    }
}
