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
    switch (_setting.GetLanguage()) {
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
    switch (_setting.GetVisibleHiddenGames()) {
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
    switch (_setting.GetTheme()) {
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

    QVBoxLayout *layout = new QVBoxLayout;
    QDir dirHiddenGames("Files/Hide");
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()){
        QPair<QString,QList<QString>> pair;
        pair.first="All.txt";
        pair.second=QList<QString>();
        if(QFile("Files/Hide/All.txt").exists()){
            QRadioButton *allHidden = new QRadioButton;
            connect(allHidden,SIGNAL(clicked()),this,SLOT(RadiobuttonHiddenGamesClicked()));
            allHidden->setObjectName("HiddenGames0");
            allHidden->setText(tr("Все профили"));
            layout->addWidget(allHidden);
            QFile fileHide1("Files/Hide/All.txt");
            if(fileHide1.open(QIODevice::ReadOnly)){
                while(!fileHide1.atEnd()){
                    pair.second << QString::fromLocal8Bit(fileHide1.readLine()).remove("\r\n").remove("\n");
                }
                fileHide1.close();
            }
        }
        _hiddenGames.append(pair);

        QFileInfoList list = dirHiddenGames.entryInfoList();
        for (int i=0;i<list.size();++i){
            if(list.at(i).fileName()!="All.txt"){
                QFile fileHide("Files/Hide/"+list.at(i).fileName());
                fileHide.open(QFile::ReadOnly);
                SProfile profile(list.at(i).fileName().remove(".txt"),false,"url");
                QList<QString> hide;
                QRadioButton *profileHidden = new QRadioButton;
                profileHidden->setObjectName("HiddenGames"+QString::number(i+1));
                profileHidden->setText(profile.GetPersonaname());
                layout->addWidget(profileHidden);
                QFile fileHide2("Files/Hide/"+list.at(i).fileName());
                if(fileHide2.open(QIODevice::ReadOnly)){
                    while(!fileHide2.atEnd()){
                        hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n");
                    }
                    fileHide2.close();
                }
                QPair<QString,QList<QString>> pair;
                pair.first=list.at(i).fileName();
                pair.second=hide;
                _hiddenGames.append(pair);
            }
            }
    }
    ui->ScrollAreaProfilesHideGames->setLayout(layout);
}

void FormSettings::on_RadioButtonLanguageEnglish_clicked(){
    _setting.SetLanguage(1);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLanguageRussian_clicked(){
    _setting.SetLanguage(5);
    QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_CheckBoxVisibleHiddenGames_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        _setting.SetVisibleHiddenGames(0);
        break;
    }
    case 2:{
        _setting.SetVisibleHiddenGames(1);
        break;
    }
    }
}

void FormSettings::on_RadioButtonDarkTheme_clicked(){
    _setting.SetTheme(1);
    QMessageBox::information(this,tr("Тема изменена"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLightTheme_clicked(){
    _setting.SetTheme(2);
    QMessageBox::information(this,tr("Тема изменена"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::RadiobuttonHiddenGamesClicked(){

}
