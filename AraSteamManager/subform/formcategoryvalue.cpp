#include "formcategoryvalue.h"
#include "ui_formcategoryvalue.h"

FormCategoryValue::FormCategoryValue(int a_pos, QWidget *parent) : QWidget(parent), ui(new Ui::FormCategoryValue),_position(a_pos){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    switch(_setting.getTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    connect(ui->CheckBoxVisible,&QCheckBox::stateChanged,this,&FormCategoryValue::CheckBoxVisible_StateChanged);
    connect(ui->ButtonUp,&QPushButton::clicked,this,&FormCategoryValue::ButtonUp_Clicked);
    connect(ui->ButtonDown,&QPushButton::clicked,this,&FormCategoryValue::ButtonDown_Clicked);
    connect(ui->ButtonSelect,&QPushButton::clicked,this,&FormCategoryValue::ButtonSelect_Clicked);
    connect(ui->ButtonUnSelect,&QPushButton::clicked,this,&FormCategoryValue::ButtonUnSelect_Clicked);
    connect(ui->ButtonDelete,&QPushButton::clicked,this,&FormCategoryValue::ButtonDelete_Clicked);
    connect(ui->LineEditTitle,&QLineEdit::textChanged,this,&FormCategoryValue::LineEditTitle_TextChanged);
    connect(ui->ButtonReverse,&QPushButton::clicked,this,&FormCategoryValue::ButtonReverse_Clicked);
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
void FormCategoryValue::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}
void FormCategoryValue::CheckBoxVisible_StateChanged(int arg1){
    emit s_visiblechange(_position, arg1==2);
}
void FormCategoryValue::ButtonUp_Clicked(){
    emit s_positionchange(_position, _position-1);
}
void FormCategoryValue::ButtonDown_Clicked(){
    emit s_positionchange(_position, _position+1);
}
void FormCategoryValue::ButtonSelect_Clicked(){
    emit s_selectchange(_position, true);
}
void FormCategoryValue::ButtonUnSelect_Clicked(){
    emit s_selectchange(_position, false);
}
void FormCategoryValue::ButtonDelete_Clicked(){
    emit s_deleting(_position);
}
void FormCategoryValue::LineEditTitle_TextChanged(const QString &arg1){
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

void FormCategoryValue::ButtonReverse_Clicked(){
    emit s_reverse(_position);
}
