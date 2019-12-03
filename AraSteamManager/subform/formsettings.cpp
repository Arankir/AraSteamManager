#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSettings)
{
    ui->setupUi(this);
    InitComponents();
}

FormSettings::~FormSettings()
{
    delete ui;
}

void FormSettings::InitComponents(){
    switch (Setting.GetLanguage()) {
    case 1:{
        ui->RadioButtonLanguageEnglish->setChecked(true);
        break;
    }
    case 5:{
        ui->RadioButtonLanguageRussian->setChecked(true);
        break;
    }
    default:{
    }
    }
    qDebug()<<Setting.GetLanguage();
}

void FormSettings::on_RadioButtonLanguageEnglish_clicked(){
    Setting.SetLanguage(1);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLanguageRussian_clicked(){
    Setting.SetLanguage(5);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}
