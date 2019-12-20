#include "formcategoryvalue.h"
#include "ui_formcategoryvalue.h"

FormCategoryValue::FormCategoryValue(int Apos, QWidget *parent) : QWidget(parent), ui(new Ui::FormCategoryValue){
    ui->setupUi(this);
    _position=Apos;
    switch(_setting.GetTheme()){
    case 1:{
        _theme="white";
        break;
        }
    case 2:{
        _theme="black";
        break;
        }
    }
    ui->LabelPosition->setText(QString::number(_position+1));
    ui->ButtonUp->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/up.png"));
    ui->ButtonDown->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/down.png"));
    ui->ButtonSelect->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/check_visible.png"));
    ui->ButtonUnSelect->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/uncheck_visible.png"));
    ui->ButtonDelete->setIcon(QIcon(":/program/program/delete.png"));
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

void FormCategoryValue::SetVisible(bool AVisible){
    ui->CheckBoxVisible->setChecked(AVisible);
}
void FormCategoryValue::SetFirstLast(int AFirstLast){
    _isFirstLast=AFirstLast;
    ui->ButtonUp->setEnabled((_isFirstLast==-2)||(_isFirstLast==-1)?false:true);
    ui->ButtonDown->setEnabled((_isFirstLast==-2)||(_isFirstLast==1)?false:true);
}
void FormCategoryValue::SetPosition(int APos){
    _position=APos;
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

