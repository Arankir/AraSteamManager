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
    switch (setting.GetLanguage()) {
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
    switch (setting.GetVisibleHiddenGames()) {
    case 0:{
        ui->CheckBoxVisibleHiddenGames->setChecked(false);
        break;
    }
    case 1:{
        ui->CheckBoxVisibleHiddenGames->setChecked(true);
        break;
    }
    default:{
    }
    }
    switch (setting.GetTheme()) {
    case 1:{
        ui->RadioButtonDarkTheme->setChecked(true);
        break;
    }
    case 2:{
        ui->RadioButtonLightTheme->setChecked(true);
        break;
    }
    default:{
    }
    }

    QPalette darkPalette;
    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    ui->GroupBoxDarkTheme->setPalette(darkPalette);
    ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());
}

void FormSettings::on_RadioButtonLanguageEnglish_clicked(){
    setting.SetLanguage(1);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLanguageRussian_clicked(){
    setting.SetLanguage(5);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_CheckBoxVisibleHiddenGames_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        setting.SetVisibleHiddenGames(0);
        break;
    }
    case 2:{
        setting.SetVisibleHiddenGames(1);
        break;
    }
    }
}

void FormSettings::on_RadioButtonDarkTheme_clicked(){
    setting.SetTheme(1);
    QMessageBox::information(this,tr("Тема изменена"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLightTheme_clicked(){
    setting.SetTheme(2);
    QMessageBox::information(this,tr("Тема изменена"),tr("Для применения изменений перезапустите приложение!"));
}
