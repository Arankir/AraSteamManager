#include "formcategoryvalue.h"
#include "ui_formcategoryvalue.h"

FormCategoryValue::FormCategoryValue(int aPos, QWidget *aParent): QWidget(aParent), ui(new Ui::FormCategoryValue), _position(aPos) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    connect(ui->CheckBoxVisible, &QCheckBox::stateChanged, this, &FormCategoryValue::checkBoxVisible_StateChanged);
    connect(ui->ButtonUp, &QPushButton::clicked, this, &FormCategoryValue::buttonUp_Clicked);
    connect(ui->ButtonDown, &QPushButton::clicked, this, &FormCategoryValue::buttonDown_Clicked);
    connect(ui->ButtonSelect, &QPushButton::clicked, this, &FormCategoryValue::buttonSelect_Clicked);
    connect(ui->ButtonUnSelect, &QPushButton::clicked, this, &FormCategoryValue::buttonUnSelect_Clicked);
    connect(ui->ButtonDelete, &QPushButton::clicked, this, &FormCategoryValue::buttonDelete_Clicked);
    connect(ui->LineEditTitle, &QLineEdit::textChanged, this, &FormCategoryValue::lineEditTitle_TextChanged);
    connect(ui->ButtonReverse, &QPushButton::clicked, this, &FormCategoryValue::buttonReverse_Clicked);
    ui->LabelPosition->setText(QString::number(_position + 1));
    setIcons();
}

void FormCategoryValue::updateSettings() {
    setIcons();
}

void FormCategoryValue::setIcons() {
    QString iconsColor = _setting.getIconsColor();
    ui->ButtonUp->setIcon(QIcon("://" + iconsColor + "/up.png"));
    ui->ButtonDown->setIcon(QIcon("://" + iconsColor + "/down.png"));
    ui->ButtonSelect->setIcon(QIcon("://" + iconsColor + "/check_visible.png"));
    ui->ButtonUnSelect->setIcon(QIcon("://" + iconsColor + "/uncheck_visible.png"));
    ui->ButtonDelete->setIcon(QIcon("://delete.png"));
    ui->ButtonReverse->setIcon(QIcon("://" + iconsColor + "/reverse.png"));
}

FormCategoryValue::~FormCategoryValue() {
    delete ui;
}

void FormCategoryValue::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormCategoryValue::checkBoxVisible_StateChanged(int arg1) {
    emit s_visiblechange(_position, arg1 == 2);
}

void FormCategoryValue::buttonUp_Clicked() {
    emit s_positionchange(_position, _position - 1);
}

void FormCategoryValue::buttonDown_Clicked() {
    emit s_positionchange(_position, _position + 1);
}

void FormCategoryValue::buttonSelect_Clicked() {
    emit s_selectchange(_position, true);
}

void FormCategoryValue::buttonUnSelect_Clicked() {
    emit s_selectchange(_position, false);
}

void FormCategoryValue::buttonDelete_Clicked() {
    emit s_deleting(_position);
}

void FormCategoryValue::lineEditTitle_TextChanged(const QString &arg1) {
    emit s_valuechange(_position, arg1);
}

void FormCategoryValue::setVisible(bool aVisible) {
    ui->CheckBoxVisible->setChecked(aVisible);
}

void FormCategoryValue::setEnabledUpDown(EnabledUpDown aFirstLast) {
    _isFirstLast = aFirstLast;
    ui->ButtonUp->setEnabled(!((_isFirstLast == EnabledUpDown::none) || (_isFirstLast == EnabledUpDown::down)));
    ui->ButtonDown->setEnabled(!((_isFirstLast == EnabledUpDown::none) || (_isFirstLast == EnabledUpDown::up)));
}

int FormCategoryValue::getPosition() {
    return _position;
}

void FormCategoryValue::setPosition(int aPos) {
    _position = aPos;
    ui->LabelPosition->setText(QString::number(_position + 1));
}

void FormCategoryValue::setTitle(QString aTitle) {
    ui->LineEditTitle->setText(aTitle);
}

QString FormCategoryValue::getTitle() {
    return ui->LineEditTitle->text();
}

bool FormCategoryValue::getVisible(){
    return ui->CheckBoxVisible->isChecked();
}

void FormCategoryValue::buttonReverse_Clicked() {
    emit s_reverse(_position);
}
