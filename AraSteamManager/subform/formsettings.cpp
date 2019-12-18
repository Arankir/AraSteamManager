#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSettings)
{
    ui->setupUi(this);
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

    QFormLayout *layout = new QFormLayout;
    QDir dirHiddenGames("Files/Hide");
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()){
        QPair<QString,QList<QString>> pair;
        pair.first="All";
        pair.second=QList<QString>();
        if(QFile("Files/Hide/All.txt").exists()){
            QRadioButton *allHidden = new QRadioButton;
            connect(allHidden,SIGNAL(clicked()),this,SLOT(RadiobuttonHiddenGamesClicked()));
            allHidden->setObjectName("HiddenGames0");
            allHidden->setText(tr("Все профили"));
            allHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
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
                connect(profileHidden,SIGNAL(clicked()),this,SLOT(RadiobuttonHiddenGamesClicked()));
                profileHidden->setObjectName("HiddenGames"+QString::number(i+1));
                profileHidden->setText(profile.GetPersonaname());
                profileHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
                layout->addWidget(profileHidden);
                QFile fileHide2("Files/Hide/"+list.at(i).fileName());
                if(fileHide2.open(QIODevice::ReadOnly)){
                    while(!fileHide2.atEnd()){
                        hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n");
                    }
                    fileHide2.close();
                }
                QPair<QString,QList<QString>> pair;
                pair.first=list.at(i).fileName().remove(".txt");
                pair.second=hide;
                _hiddenGames.append(pair);
            }
            }
    }
    ui->ScrollAreaProfilesHideGames->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
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
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int index=rb->objectName().mid(11).toInt();
    if(index!=0){
        SGames games;
        games.Set(_hiddenGames[index].first,true,true,false);
        ui->TableWidgetGames->setRowCount(0);
        ui->TableWidgetGames->setRowCount(_hiddenGames[index].second.size());
        for (int i=0;i<games.GetCount();i++) {
            if(_hiddenGames[index].second.indexOf(QString::number(games.GetAppid(i)))>-1){
                int setTo=_hiddenGames[index].second.indexOf(QString::number(games.GetAppid(i)));
                QString path = "images/icon_games/"+games.GetImg_icon_url(i)+".jpg";
                if(!QFile::exists(path)){
                    if(games.GetImg_icon_url(i)!=""){
                        ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                               QString::number(games.GetAppid(i))+"/"+games.GetImg_icon_url(i)+".jpg",setTo,path,true);
                        connect(image,&ImageRequest::s_finished,this,&FormSettings::OnResultImage);
                        }
                    } else {
                    QPixmap pixmap;
                    pixmap.load(path);
                    QLabel *label = new QLabel;
                    label->setPixmap(pixmap);
                    ui->TableWidgetGames->setCellWidget(setTo,0,label);
                    }
                ui->TableWidgetGames->setItem(setTo,1,new QTableWidgetItem(games.GetName(i)));

                ui->TableWidgetGames->setRowHeight(setTo,33);
                QPushButton *button1 = new QPushButton(tr("Достижения"));
                button1->setMinimumSize(QSize(25,25));
                connect(button1,&QPushButton::pressed,this,&FormSettings::AchievementsClicked);
                button1->setObjectName("ButtonAchievements"+QString::number(index)+"_"+QString::number(setTo));
                ui->TableWidgetGames->setCellWidget(setTo,2,button1);

                QPushButton *button3 = new QPushButton;
                button3->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/hide.png"));
                button3->setMinimumSize(QSize(25,25));
                connect(button3,&QPushButton::pressed,this,&FormSettings::HideClicked);
                button3->setObjectName("ButtonHide"+QString::number(index)+"_"+QString::number(setTo));
                ui->TableWidgetGames->setCellWidget(setTo,3,button3);
            }
        }
    } else {
        ui->TableWidgetGames->setRowCount(0);
        ui->TableWidgetGames->setRowCount(_hiddenGames[index].second.size());
        for (int i=0;i<_hiddenGames[index].second.size();i++) {
            QStringList list = _hiddenGames[index].second[i].split("%%");
            //_games[gamei].GetAppid()<<(save=="Files/Hide/All.txt"?"%%"+_games[gamei].GetImg_icon_url()+"%%"+_games[gamei].GetName()
            int setTo=_hiddenGames[index].second.indexOf(list[0]);
            QString path = "images/icon_games/"+list[1]+".jpg";
            if(!QFile::exists(path)){
                if(list[1]!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           list[0]+"/"+list[1]+".jpg",setTo,path,true);
                    connect(image,&ImageRequest::s_finished,this,&FormSettings::OnResultImage);
                    }
                } else {
                QPixmap pixmap;
                pixmap.load(path);
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetGames->setCellWidget(i,0,label);
                }
            ui->TableWidgetGames->setItem(i,1,new QTableWidgetItem(list[2]));

            ui->TableWidgetGames->setRowHeight(i,33);
            QPushButton *button1 = new QPushButton(tr("Достижения"));
            button1->setMinimumSize(QSize(25,25));
            connect(button1,&QPushButton::pressed,this,&FormSettings::AchievementsClicked);
            button1->setObjectName("ButtonAchievements"+QString::number(index)+"_"+QString::number(setTo));
            ui->TableWidgetGames->setCellWidget(i,2,button1);

            QPushButton *button3 = new QPushButton;
            button3->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/hide.png"));
            button3->setMinimumSize(QSize(25,25));
            connect(button3,&QPushButton::pressed,this,&FormSettings::HideClicked);
            button3->setObjectName("ButtonHide"+QString::number(index)+"_"+QString::number(setTo));
            ui->TableWidgetGames->setCellWidget(i,3,button3);
        }
    }
    ui->TableWidgetGames->resizeColumnsToContents();
}

void FormSettings::OnResultImage(ImageRequest *){

}

void FormSettings::AchievementsClicked(){
    QPushButton *pb = qobject_cast<QPushButton*>(sender());
    //int index=pb->objectName().mid(11).toInt();

}

void FormSettings::HideClicked(){
    QPushButton *pb = qobject_cast<QPushButton*>(sender());
    //int index=pb->objectName().mid(11).toInt();

}
