#include "formaddcategory.h"
#include "ui_formaddcategory.h"

FormAddCategory::FormAddCategory(QString games, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormAddCategory){
    ui->setupUi(this);
    game=games;
    Words=Setting.GetWords("addcategory");
    ui->LineEditTitle->setPlaceholderText(Words[0]);
    ui->CheckBoxNoValue->setText(Words[1]);
    ui->ButtonAddValue->setText(Words[2]);
    ui->ButtonCancel->setText(Words[3]);
    ui->CheckBoxSelectAll->setText(Words[4]);
    ui->ButtonAccept->setText(Words[5]);
    QWidget *widget1 = new QWidget;
    lay = new QFormLayout;
    lay->setContentsMargins(3,1,3,1);
    lay->setSpacing(1);
    widget1->setLayout(lay);
    ui->ScrollAreaValues->setWidget(widget1);
}

FormAddCategory::~FormAddCategory(){
    delete lay;
    delete ui;
}

void FormAddCategory::on_ButtonAddValue_clicked(){
    CategoryValue *val = new CategoryValue(count++);
    Values.append(val);
    QWidget *wid = new QWidget;
    wid->setLayout(val);
    lay->addRow(wid);
    connect(val,&CategoryValue::positionchange,this,&FormAddCategory::ChangePosition);
    connect(val,&CategoryValue::valuechange,this,&FormAddCategory::ChangeValue);
    connect(val,&CategoryValue::visiblechange,this,&FormAddCategory::ChangeVisibility);
    connect(val,&CategoryValue::selectchange,this,&FormAddCategory::ChangeSelect);
    connect(val,&CategoryValue::deleting,this,&FormAddCategory::DeleteValue);
    emit addvalue(count);
}
void FormAddCategory::on_ButtonAccept_clicked(){
    if(!QDir("Files").exists()){
        QDir().mkdir("Files");
    }
    if(!QDir("Files/Categories").exists()){
        QDir().mkdir("Files/Categories");
    }
    if(!QDir("Files/Categories/"+game).exists()){
        QDir().mkdir("Files/Categories/"+game);
    }
    if(ui->LineEditTitle->text()!=""){
        QFile Category("Files/Categories/"+game+"/"+ui->LineEditTitle->text()+".json");
        if(!QFile::exists("Files/Categories/"+game+"/"+ui->LineEditTitle->text()+".json")){
            emit accept();
        } else
            QMessageBox::warning(this,Words[6],Words[7]);
    } else
        QMessageBox::warning(this,Words[6],Words[8]);
}
void FormAddCategory::on_ButtonCancel_clicked(){
    emit cancel();
}
void FormAddCategory::on_CheckBoxNoValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->ButtonAddValue->setEnabled(true);
        ui->ScrollAreaValues->setEnabled(true);
        emit novalue(false);
        break;
        }
    case 2:{
        ui->ButtonAddValue->setEnabled(false);
        ui->ScrollAreaValues->setEnabled(false);
        emit novalue(true);
        break;
        }
    }
}

QString FormAddCategory::GetTitle(){
    return ui->LineEditTitle->text();
}

void FormAddCategory::ChangePosition(int pos, int posnew){
    if(posnew>=0&&posnew<count){
        Values[pos]->SetPosition(posnew);
        std::swap(Values[pos],Values[posnew]);

        for (int i=0;i<count;i++) {
            lay->takeAt(0);
            QWidget *wid = new QWidget;
            wid->setLayout(Values[i]);
            lay->addRow(wid);
        }
        emit positionchange(pos,posnew);
    }
}
void FormAddCategory::ChangeValue(int pos, QString value){
    emit valuechange(pos,value);

}
void FormAddCategory::ChangeVisibility(int pos, bool visible){
    bool accept=true;
    for (int i=0;i<count;i++) {
        if(!Values[i]->GetVisible())
            accept=false;
    }
    if(accept)
        ui->CheckBoxSelectAll->setCheckState(Qt::Checked);
    else
        ui->CheckBoxSelectAll->setCheckState(Qt::Unchecked);
    emit visiblechange(pos,visible);

}
void FormAddCategory::ChangeSelect(int pos, bool select){
    emit selectchange(pos,select);

}
void FormAddCategory::DeleteValue(int pos){
    Values.takeAt(pos);
    for (int i=pos;i<count;i++) {
        Values[i]->SetPosition(i);
    }
    count--;
    emit deleting(pos);
}

void FormAddCategory::on_CheckBoxSelectAll_clicked(){
    for (int i=0;i<count;i++) {
        Values[i]->SetSelect(ui->CheckBoxSelectAll->isChecked());
    }
}
