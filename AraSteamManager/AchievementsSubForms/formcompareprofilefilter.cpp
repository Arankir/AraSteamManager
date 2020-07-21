#include "formcompareprofilefilter.h"
#include "ui_formcompareprofilefilter.h"

FormCompareProfileFilter::FormCompareProfileFilter(QWidget *aParent): FormCompareProfileFilter("", "", "", aParent) {

}

FormCompareProfileFilter::FormCompareProfileFilter(QString aTitleAll, QString aTitleReached, QString aTitleNotReached, QWidget *parent): QWidget(parent),
ui(new Ui::FormCompareProfileFilter) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    setIcons();
    ui->RadioButtonAll->SetReachedType(ReachedType::all);
    ui->RadioButtonReached->SetReachedType(ReachedType::reached);
    ui->RadioButtonNotReached->SetReachedType(ReachedType::notReached);
    connect(ui->RadioButtonAll,        &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    connect(ui->RadioButtonReached,    &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    connect(ui->RadioButtonNotReached, &QRadioButtonWithData::clicked, this, &FormCompareProfileFilter::radioButtonClick);
    setTitles(aTitleAll, aTitleReached, aTitleNotReached);
}

void FormCompareProfileFilter::updateSettings() {
    setIcons();
}

void FormCompareProfileFilter::setIcons() {
    QString iconsColor = _setting.getIconsColor();
    ui->RadioButtonAll->setIcon(QIcon("://" + iconsColor + "/all.png"));
    ui->RadioButtonReached->setIcon(QIcon("://" + iconsColor + "/reached.png"));
    ui->RadioButtonNotReached->setIcon(QIcon("://" + iconsColor + "/notreached.png"));
}

FormCompareProfileFilter::~FormCompareProfileFilter() {
    delete ui;
}

void FormCompareProfileFilter::setName(QString aName) {
    _name = aName;
}

void FormCompareProfileFilter::setIndex(QString aIndex) {
    _index = aIndex;
}

void FormCompareProfileFilter::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormCompareProfileFilter::setTitles(QString aTitleAll, QString aTitleReached, QString aTitleNotReached) {
    ui->RadioButtonAll->setText(aTitleAll);
    ui->RadioButtonReached->setText(aTitleReached);
    ui->RadioButtonNotReached->setText(aTitleNotReached);
}

QString FormCompareProfileFilter::getName() {
    return _name;
}

QString FormCompareProfileFilter::getIndex() {
    return _index;
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
        emit s_radioButtonChange(_name, rb->GetReachedType());
    }
}
