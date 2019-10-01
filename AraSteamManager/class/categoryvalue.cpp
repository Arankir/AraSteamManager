#include "categoryvalue.h"

CategoryValue::CategoryValue(int positions)
{
    position=positions;
    //Words=Setting.GetWords("categoryvalue");
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
    ValueName = new QLineEdit;
    Visible = new QCheckBox;
    Up = new QPushButton;
    Down = new QPushButton;
    Select = new QPushButton;
    UnSelect = new QPushButton;
    Delete = new QPushButton;
    ValueName->setObjectName("ValueName");
    Visible->setObjectName("Visible");
    Up->setObjectName("Up");
    Down->setObjectName("Down");
    Select->setObjectName("Select");
    UnSelect->setObjectName("UnSelect");
    Delete->setObjectName("Delete");
    Up->setIcon(QIcon(":/"+theme+"/program/"+theme+"/up.png"));
    Down->setIcon(QIcon(":/"+theme+"/program/"+theme+"/down.png"));
    //Select->setIcon();
    //UnSelect->setIcon();
    Delete->setIcon(QIcon(":/program/program/delete.png"));
    CategoryValue::addWidget(ValueName,0,0,4,0);
    CategoryValue::addWidget(Visible,0,5);
    CategoryValue::addWidget(Up,0,6);
    CategoryValue::addWidget(Down,0,7);
    CategoryValue::addWidget(Select,0,8);
    CategoryValue::addWidget(UnSelect,0,9);
    CategoryValue::addWidget(Delete,0,10);
    connect(ValueName,&QLineEdit::editingFinished,this,&CategoryValue::OnChangeValue);
    connect(Visible,&QCheckBox::clicked,this,&CategoryValue::OnChangeVisibility);
    connect(Up,&QPushButton::clicked,this,&CategoryValue::OnChangePosition);
    connect(Down,&QPushButton::clicked,this,&CategoryValue::OnChangePosition);
    connect(Select,&QPushButton::clicked,this,&CategoryValue::OnChangeSelect);
    connect(UnSelect,&QPushButton::clicked,this,&CategoryValue::OnChangeSelect);
    connect(Delete,&QPushButton::clicked,this,&CategoryValue::OnDeleting);
}

void CategoryValue::OnChangePosition(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if(btn->objectName()=="Up")
        emit positionchange(position-1);
    else if(btn->objectName()=="Down")
        emit positionchange(position+1);
    delete btn;
}

void CategoryValue::OnChangeSelect(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    emit selectchange(btn->objectName()=="Select"?true:false);
    delete btn;
}

CategoryValue::~CategoryValue(){
    disconnect(ValueName,&QLineEdit::editingFinished,this,&CategoryValue::OnChangeValue);
    disconnect(Visible,&QCheckBox::clicked,this,&CategoryValue::OnChangeVisibility);
    disconnect(Up,&QPushButton::clicked,this,&CategoryValue::OnChangePosition);
    disconnect(Down,&QPushButton::clicked,this,&CategoryValue::OnChangePosition);
    disconnect(Select,&QPushButton::clicked,this,&CategoryValue::OnChangeSelect);
    disconnect(UnSelect,&QPushButton::clicked,this,&CategoryValue::OnChangeSelect);
    disconnect(Delete,&QPushButton::clicked,this,&CategoryValue::OnDeleting);
    delete ValueName;
    delete Visible;
    delete Up;
    delete Down;
    delete Select;
    delete UnSelect;
    delete Delete;
}
