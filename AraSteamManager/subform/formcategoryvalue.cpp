#include "formcategoryvalue.h"
#include "ui_formcategoryvalue.h"

FormCategoryValue::FormCategoryValue(int pos, QWidget *parent) : QWidget(parent), ui(new Ui::FormCategoryValue){
    ui->setupUi(this);
    position=pos;
    switch(Setting.GetTheme()){
    case 1:{
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        break;
        }
    }
    ui->LabelPosition->setText(QString::number(position));
    ui->ButtonUp->setIcon(QIcon(":/"+theme+"/program/"+theme+"/up.png"));
    ui->ButtonDown->setIcon(QIcon(":/"+theme+"/program/"+theme+"/down.png"));
    ui->ButtonSelect->setIcon(QIcon(":/"+theme+"/program/"+theme+"/check_visible.png"));
    ui->ButtonUnSelect->setIcon(QIcon(":/"+theme+"/program/"+theme+"/uncheck_visible.png"));
    ui->ButtonDelete->setIcon(QIcon(":/program/program/delete.png"));
}

FormCategoryValue::~FormCategoryValue(){
    delete ui;
}

void FormCategoryValue::on_CheckBoxVisible_stateChanged(int arg1){
    emit visiblechange(position, arg1==2?true:false);
}

void FormCategoryValue::on_ButtonUp_clicked(){
    emit positionchange(position, position-1);
}

void FormCategoryValue::on_ButtonDown_clicked(){
    emit positionchange(position, position+1);
}

void FormCategoryValue::on_ButtonSelect_clicked(){
    emit selectchange(position, true);
}

void FormCategoryValue::on_ButtonUnSelect_clicked(){
    emit selectchange(position, false);
}

void FormCategoryValue::on_ButtonDelete_clicked(){
    emit deleting(position);
}

void FormCategoryValue::on_LineEditTitle_textChanged(const QString &arg1){
    emit valuechange(position, arg1);
}

void FormCategoryValue::setVisibl(bool visible){
    ui->CheckBoxVisible->setChecked(visible);
}
void FormCategoryValue::setFirstLast(int firstlast){
    isfirstlast=firstlast;
    ui->ButtonUp->setEnabled((isfirstlast==-2)||(isfirstlast==-1)?false:true);
    ui->ButtonDown->setEnabled((isfirstlast==-2)||(isfirstlast==1)?false:true);
}
void FormCategoryValue::setPosition(int pos){
    position=pos;
    ui->LabelPosition->setText(QString::number(position));
}
QString FormCategoryValue::getTitle(){
    return ui->LineEditTitle->text();
}
bool FormCategoryValue::getVisible(){
    return ui->CheckBoxVisible->isChecked();
}
