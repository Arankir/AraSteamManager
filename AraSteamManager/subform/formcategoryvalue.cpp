#include "formcategoryvalue.h"
#include "ui_formcategoryvalue.h"

FormCategoryValue::FormCategoryValue(int a_pos, QWidget *parent) : QWidget(parent), ui(new Ui::FormCategoryValue){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    _position=a_pos;
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    ui->LabelPosition->setText(QString::number(_position+1));
    ui->ButtonUp->setIcon(QIcon("://"+_theme+"/up.png"));
    ui->ButtonDown->setIcon(QIcon("://"+_theme+"/down.png"));
    ui->ButtonSelect->setIcon(QIcon("://"+_theme+"/check_visible.png"));
    ui->ButtonUnSelect->setIcon(QIcon("://"+_theme+"/uncheck_visible.png"));
    ui->ButtonDelete->setIcon(QIcon("://delete.png"));
    ui->ButtonReverse->setIcon(QIcon("://"+_theme+"/reverse.png"));
}

FormCategoryValue::~FormCategoryValue(){
    delete ui;
}

void FormCategoryValue::on_CheckBoxVisible_stateChanged(int arg1){
    emit s_visiblechange(_position, arg1==2);
}
void FormCategoryValue::on_ButtonUp_clicked(){
    emit s_positionchange(_position, _position-1);
}
void FormCategoryValue::on_ButtonDown_clicked(){
    emit s_positionchange(_position, _position+1);
}
void FormCategoryValue::on_ButtonSelect_clicked(){
    emit s_selectchange(_position, true);
}
void FormCategoryValue::on_ButtonUnSelect_clicked(){
    emit s_selectchange(_position, false);
}
void FormCategoryValue::on_ButtonDelete_clicked(){
    emit s_deleting(_position);
}
void FormCategoryValue::on_LineEditTitle_textChanged(const QString &arg1){
    emit s_valuechange(_position, arg1);
}

void FormCategoryValue::SetVisible(bool a_Visible){
    ui->CheckBoxVisible->setChecked(a_Visible);
}
void FormCategoryValue::SetEnabledUpDown(EnabledUpDown a_FirstLast){
    _isFirstLast=a_FirstLast;
    ui->ButtonUp->setEnabled((_isFirstLast==EnabledUpDown::none)||(_isFirstLast==EnabledUpDown::down)?false:true);
    ui->ButtonDown->setEnabled((_isFirstLast==EnabledUpDown::none)||(_isFirstLast==EnabledUpDown::up)?false:true);
}
void FormCategoryValue::SetPosition(int a_pos){
    _position=a_pos;
    ui->LabelPosition->setText(QString::number(_position+1));
}
void FormCategoryValue::SetTitle(QString title){
    ui->LineEditTitle->setText(title);
}
QString FormCategoryValue::GetTitle(){
    return ui->LineEditTitle->text();
}
bool FormCategoryValue::GetVisible(){
    return ui->CheckBoxVisible->isChecked();
}

void FormCategoryValue::on_ButtonReverse_clicked(){
    emit s_reverse(_position);
}
