#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSettings)
{
    ui->setupUi(this);
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    InitComponents();
}

FormSettings::~FormSettings(){
    delete ui;
}

void FormSettings::InitComponents(){
    switch (_setting.GetLanguage()) {
        case 1:
            ui->RadioButtonLanguageEnglish->setChecked(true);
            break;
        case 5:
            ui->RadioButtonLanguageRussian->setChecked(true);
            break;
        default:
            break;
    }
    switch (_setting.GetVisibleHiddenGames()) {
        case 0:
            ui->CheckBoxVisibleHiddenGames->setChecked(false);
            break;
        case 1:
            ui->CheckBoxVisibleHiddenGames->setChecked(true);
            break;
        default:
            break;
    }
    switch (_setting.GetTheme()) {
        case 1:
            ui->RadioButtonDarkTheme->setChecked(true);
            break;
        case 2:
            ui->RadioButtonLightTheme->setChecked(true);
            break;
        default:
            break;
    }

//    QPalette darkPalette;
//    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    //ui->GroupBoxDarkTheme->setPalette(darkPalette);
    //ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());

    QFormLayout *layout = new QFormLayout;
    QDir dirHiddenGames("Files/Hide");
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()){
        QPair<QString,QList<QString>> pair;
        pair.first="All";
        pair.second=QList<QString>();
        if(QFile("Files/Hide/All.txt").exists()){
            QRadioButtonWithData *allHidden = new QRadioButtonWithData;
            allHidden->setText(tr("Все профили"));
            allHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
            allHidden->setObjectName("HiddenGames0");
            allHidden->AddData("NumberFileHiddenGame","0");
            connect(allHidden,SIGNAL(clicked()),this,SLOT(RadiobuttonHiddenGamesClicked()));
            layout->addWidget(allHidden);
            QFile fileHide1("Files/Hide/All.txt");
            if(fileHide1.open(QIODevice::ReadOnly)){
                while(!fileHide1.atEnd())
                    pair.second << QString::fromLocal8Bit(fileHide1.readLine()).remove("\r\n").remove("\n");
                fileHide1.close();
            }
        }
        _hiddenGames.append(pair);

        QFileInfoList list = dirHiddenGames.entryInfoList();
        for (int i=0;i<list.size();++i){
            if(list.at(i).fileName()!="All.txt"){
                QFile fileHide("Files/Hide/"+list.at(i).fileName());
                fileHide.open(QFile::ReadOnly);
                SProfile profile(list.at(i).fileName().remove(".txt"),false,QueryType::url);
                QList<QString> hide;
                QRadioButtonWithData *profileHidden = new QRadioButtonWithData;
                profileHidden->setText(profile.GetPersonaname());
                profileHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
                profileHidden->setObjectName("HiddenGames"+QString::number(i+1));
                profileHidden->AddData("NumberFileHiddenGame",QString::number(i+1));
                connect(profileHidden,SIGNAL(clicked()),this,SLOT(RadiobuttonHiddenGamesClicked()));
                layout->addWidget(profileHidden);
                QFile fileHide2("Files/Hide/"+list.at(i).fileName());
                if(fileHide2.open(QIODevice::ReadOnly)){
                    while(!fileHide2.atEnd())
                        hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n");
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

void FormSettings::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}

void FormSettings::Retranslate(){
    ui->retranslateUi(this);

    QRadioButtonWithData *allHidden = this->findChild<QRadioButtonWithData*>("HiddenGames0");
    allHidden->setText(tr("Все профили"));
}

void FormSettings::on_RadioButtonLanguageEnglish_clicked(){
    _setting.SetLanguage(1);
    QTranslator *translator = new QTranslator;
        translator->load(":/AraSteamManager_en.qm");
        qApp->installTranslator(translator);
        //ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_RadioButtonLanguageRussian_clicked(){
    _setting.SetLanguage(5);
    QTranslator *translator = new QTranslator;
        translator->load(":/AraSteamManager_ru.qm");
        qApp->installTranslator(translator);
        //ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::on_CheckBoxVisibleHiddenGames_stateChanged(int arg1){
    _setting.SetVisibleHiddenGames(arg1/2);
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
    int indexHiddenGame=static_cast<QRadioButtonWithData*>(sender())->GetData(0).toInt();
    ui->TableWidgetGames->clear();
    ui->TableWidgetGames->setRowCount(_hiddenGames[indexHiddenGame].second.size());
    if(indexHiddenGame!=0){
        SGames games(_hiddenGames[indexHiddenGame].first,true,true,false);
        for (int i=0;i<games.GetCount();i++) {
            if(_hiddenGames[indexHiddenGame].second.indexOf(QString::number(games[i].GetAppid()))>-1){
                int setTo=_hiddenGames[indexHiddenGame].second.indexOf(QString::number(games[i].GetAppid()));
                QString path = "images/icon_games/"+games[i].GetImg_icon_url()+".jpg";
                if(!QFile::exists(path)){
                    if(games[i].GetImg_icon_url()!=""){
                        RequestData *image = new RequestData("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                               QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",setTo,path,true);
                        connect(image,&RequestData::s_finished,this,&FormSettings::OnResultImage);
                        }
                    } else {
                    QLabel *iconGame = new QLabel;
                    iconGame->setPixmap(QPixmap(path));
                    ui->TableWidgetGames->setCellWidget(setTo,0,iconGame);
                    }
                ui->TableWidgetGames->setItem(setTo,1,new QTableWidgetItem(games[i].GetName()));
                ui->TableWidgetGames->setRowHeight(setTo,33);

                QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
                button1->setMinimumSize(QSize(25,25));
                button1->setObjectName("ButtonAchievements"+QString::number(indexHiddenGame)+"_"+QString::number(setTo));
                button1->AddData("NumberFileHiddenGame",QString::number(indexHiddenGame));
                button1->AddData("NumberHiddenGame",QString::number(setTo));
                connect(button1,&QButtonWithData::pressed,this,&FormSettings::AchievementsClicked);
                ui->TableWidgetGames->setCellWidget(setTo,2,button1);

                QButtonWithData *button3 = new QButtonWithData("");
                button3->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/hide.png"));
                button3->setMinimumSize(QSize(25,25));
                button3->setObjectName("ButtonHide"+QString::number(indexHiddenGame)+"_"+QString::number(games[i].GetAppid()));
                button3->AddData("NumberFileHiddenGame",QString::number(indexHiddenGame));
                button3->AddData("NumberHiddenGame",QString::number(games[i].GetAppid()));
                connect(button3,&QButtonWithData::pressed,this,&FormSettings::HideClicked);
                ui->TableWidgetGames->setCellWidget(setTo,3,button3);
            }
        }
    } else {
        //list[0]=_games[gamei].GetAppid()
        //list[1]=_games[gamei].GetImg_icon_url()
        //list[2]=_games[gamei].GetName()
        for (int i=0;i<_hiddenGames[indexHiddenGame].second.size();i++) {
            QStringList list = _hiddenGames[indexHiddenGame].second[i].split("%%");
            QString path = "images/icon_games/"+list[1]+".jpg";
            if(!QFile::exists(path)){
                if(list[1]!=""){
                    RequestData *image = new RequestData("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           list[0]+"/"+list[1]+".jpg",i,path,true);
                    connect(image,&RequestData::s_finished,this,&FormSettings::OnResultImage);
                    }
                } else {
                QLabel *iconGame = new QLabel;
                iconGame->setPixmap(QPixmap(path));
                ui->TableWidgetGames->setCellWidget(i,0,iconGame);
                }
            ui->TableWidgetGames->setItem(i,1,new QTableWidgetItem(list[2]));

            ui->TableWidgetGames->setRowHeight(i,33);
            QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
            button1->setMinimumSize(QSize(25,25));
            button1->setObjectName("ButtonAchievements"+QString::number(indexHiddenGame)+"_"+QString::number(i));
            button1->AddData("NumberFileHiddenGame",QString::number(indexHiddenGame));
            button1->AddData("NumberHiddenGame",QString::number(i));
            connect(button1,&QButtonWithData::pressed,this,&FormSettings::AchievementsClicked);
            ui->TableWidgetGames->setCellWidget(i,2,button1);

            QButtonWithData *button3 = new QButtonWithData("");
            button3->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/hide.png"));
            button3->setMinimumSize(QSize(25,25));
            button3->setObjectName("ButtonHide"+QString::number(indexHiddenGame)+"_"+list[0]);
            button3->AddData("NumberFileHiddenGame",QString::number(indexHiddenGame));
            button3->AddData("NumberHiddenGame",list[0]);
            connect(button3,&QButtonWithData::pressed,this,&FormSettings::HideClicked);
            ui->TableWidgetGames->setCellWidget(i,3,button3);
        }
    }
    ui->TableWidgetGames->resizeColumnsToContents();
}

void FormSettings::OnResultImage(RequestData *){

}

void FormSettings::AchievementsClicked(){
    QButtonWithData *pb = static_cast<QButtonWithData*>(sender());
    //int index=pb->objectName().mid(11).toInt();

}

void FormSettings::HideClicked(){
    QButtonWithData *pb = static_cast<QButtonWithData*>(sender());
    int index=pb->GetData(0).toInt();
    int gameIndex=-1;
    QMessageBox messageBox(QMessageBox::Question,tr("Внимание!"),tr("Сделать игру видимой?"));
    QAbstractButton *btnProfile = messageBox.addButton(tr("Да"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton()!=btnProfile){
        return;
    }
    for(int i=0;i<_hiddenGames[index].second.size();i++){
        QStringList lineList = _hiddenGames[index].second[i].split("%%");
        if(lineList[0]==pb->GetData(1)){
            gameIndex=i;
            break;
        }
    }
    QString save=_hiddenGames[index].first+".txt";
    _hiddenGames[index].second.removeAt(gameIndex);
    ui->TableWidgetGames->removeRow(gameIndex);
    QFile fileSaveTo("Files/Hide/"+_hiddenGames[index].first+".txt");
    fileSaveTo.open(QIODevice::WriteOnly| QIODevice::Text);
    QTextStream writeStream(&fileSaveTo);
    foreach(QString game, _hiddenGames[index].second){
        writeStream <<game+"\n";
    }
    fileSaveTo.close();
    QMessageBox(QMessageBox::Information,tr("Успешно!"),tr("Политика видимости для игры обновлена!"));
}
