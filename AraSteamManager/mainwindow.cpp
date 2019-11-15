#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    Words=Setting.GetWords("mainwindow");
    switch(Setting.GetTheme()){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,???               ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
        qApp->setPalette(darkPalette);
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
        break;
        }
    }
    InitComponents();
    if(Setting.GetStatus()=="success"){
        if(Setting.GetMyProfile()!="none")
            GoToProfile(Setting.GetMyProfile(),"url",true);
    }
}

void MainWindow::InitComponents(){
    ui->LabelAvatar->setText("");
    ui->LabelLogo->setText("(WIP)");
    ui->LabelTimeCreated->setText("");
    ui->LabelPersonaState->setText("");
    ui->LabelLocCountryCode->setText("");
    ui->LabelProfileUrl->setText("");
    ui->LabelRealName->setText("");
    ui->Labellvl->setText("");
    ui->LabelBans->setText("");
    ui->LabelPersonaState->setWordWrap(true);
    ui->ButtonGames->setVisible(false);
    ui->ButtonFriends->setVisible(false);
    ui->ButtonFavorites->setVisible(false);
    ui->ButtonSetProfile->setVisible(false);
    ui->ButtonStatistics->setVisible(false);
    ui->ButtonGoToMyProfile->setVisible(false);
    ui->ScrollAreaForm->setVisible(false);
    ui->LabelNick->setVisible(false);
    ui->line->setVisible(false);
    ui->LabelProfileVisibility->setVisible(false);
    ui->ScrollAreaProfileInfo->setVisible(false);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonFindProfile->setText(" "+Words[0]);
    ui->LineEditIdProfile->setPlaceholderText(Words[1]);
    ui->ButtonSettings->setText(Words[2]);
    ui->ButtonExit->setText(" "+Words[3]);
    ui->ButtonStatistics->setText(" "+Words[6]);
    ui->ButtonFavorites->setText(" "+Words[7]);
    ui->ButtonSetProfile->setText(Words[8]);
    ui->ButtonGoToMyProfile->setText(Words[9]);
    ui->ButtonFindProfile->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonFavorites->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon(":/"+theme+"/program/"+theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon(":/"+theme+"/program/"+theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon(":/"+theme+"/program/"+theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon(":/"+theme+"/program/"+theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon(":/"+theme+"/program/"+theme+"/games.png"));
    //        ui->LabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //        ui->LabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //    QPixmap pixmap2("images/program/statistic_white.png","PNG");
    //    QIcon ButtonIcon2(pixmap2);
    //    ui->ButtonStatistics->setIcon(ButtonIcon2);
    //    ui->ButtonSettings->setIconSize(pixmap.rect().size());
    //    ui->ButtonStatistics->setIconSize(QSize(13,13));
}

void MainWindow::ProgressLoading(int p,int){
    ui->FormProgressBar->setValue(p);
}

void MainWindow::ShowGames(){
    ui->FormProgressBar->setVisible(false);
    gamesform->setVisible(true);
}
void MainWindow::ShowFriends(){
    ui->FormProgressBar->setVisible(false);
    friendsform->setVisible(true);
}

void MainWindow::keyPressEvent(QKeyEvent* event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(event->key() == 16777220)
        on_ButtonFindProfile_clicked();
}

MainWindow::~MainWindow(){
    delete ui;
    //if(gamesform)
    //    delete gamesform;
    //if(friendsform)
    //    delete friendsform;
}
void MainWindow::returnfromgames(){
    this->setVisible(true);
    disconnect(gamesform,SIGNAL(return_to_profile()),this,SLOT(returnfromgames()));
    windowchildcount--;
    delete gamesform;
}
void MainWindow::returnfromfriends(){
    this->setVisible(true);
    disconnect(friendsform,SIGNAL(return_to_profile()),this,SLOT(returnfromfriends()));
    disconnect(friendsform,SIGNAL(go_to_profile(QString,QString,bool)),this,SLOT(GoToProfile(QString,QString,bool)));
    windowchildcount--;
    delete friendsform;
}

void MainWindow::on_ButtonFindProfile_clicked(){
    QString id=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove("/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        id=ui->LineEditIdProfile->text().remove("id");
        GoToProfile(id,"vanity",true);
        } else {
            if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
                id=ui->LineEditIdProfile->text().remove("profiles");
            GoToProfile(id,"url",true);
            }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}
void MainWindow::GoToProfile(QString id, QString type, bool UpdateBuffer){
    SProfile Profiles(key,id,false,type);
    if(Profiles.GetStatus()=="success"){
        qDebug()<<BufferProfiles.size()<<BufferProfiles<<CurrentBufferProfile;
        if(UpdateBuffer){
            if(CurrentBufferProfile!=BufferProfiles.size())
                while(BufferProfiles.size()!=CurrentBufferProfile)
                    BufferProfiles.takeAt(CurrentBufferProfile);
            BufferProfiles.append(id);
            CurrentBufferProfile=BufferProfiles.size();
        }
        qDebug()<<BufferProfiles.size()<<BufferProfiles<<CurrentBufferProfile;
        Profile=Profiles;
        Games.Clear();
        Friends.Clear();
        SBans Bans(key,Profile.GetSteamid(),false);
        SLevels Levels(key,Profile.GetSteamid());
        Games.Set(key,Profile.GetSteamid(),true,true,false);
        Friends.Set(key,Profile.GetSteamid(),false);
        //ui->LabelProfileUrl->setTextFormat(Qt::RichText);
        //ui->LabelProfileUrl->setText("<img src=\":/"+theme+"/program/"+theme+"/link.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
        ui->ButtonGames->setText(Games.GetStatus()=="success"?" "+Words[4]+"("+QString::number(Games.GetCount())+")":" "+Words[4]+" (error)");
        ui->ButtonFriends->setText(Friends.GetStatus()=="success"?" "+Words[5]+"("+QString::number(Friends.GetCount())+")":" "+Words[5]+" (error)");if(!Profile.GetGameextrainfo().isEmpty()){
            ui->LabelPersonaState->setText(Words[10]+":"+Profile.GetGameextrainfo());
            ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (Profile.GetPersonastate()) {
            case 0:{
                    ui->LabelPersonaState->setText(Words[11]+": "+Profile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
            }
            case 1:{
                    ui->LabelPersonaState->setText(Words[12]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
            }
            case 2:{
                    ui->LabelPersonaState->setText(Words[13]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
            }
            case 3:{
                    ui->LabelPersonaState->setText(Words[14]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 4:{
                    ui->LabelPersonaState->setText(Words[15]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 5:{
                    ui->LabelPersonaState->setText(Words[16]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            case 6:{
                    ui->LabelPersonaState->setText(Words[17]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            }
        ui->LabelProfileUrl->setText(Profile.GetProfileurl());
        ui->Labellvl->setText(Words[18]+": "+QString::number(Levels.GetPlayer_level()));
        ui->LabelRealName->setText(Words[19]+": "+Profile.GetRealname());
        ui->LabelTimeCreated->setText(Words[20]+" "+Profile.GetTimecreated().toString("yyyy.MM.dd"));
        ui->LabelLocCountryCode->setText(Words[21]+": "+Profile.GetLoccountrycode());
        switch (Profile.GetCommunityvisibilitystate()) {
            case 1:{
                ui->LabelProfileVisibility->setText(Words[22]);
                ui->LabelProfileVisibility->setStyleSheet("color:red");
                break;
            }
            case 3:{
                ui->LabelProfileVisibility->setText(Words[23]);
                ui->LabelProfileVisibility->setStyleSheet("color:green");
                break;
            }
            case 8:{
                ui->LabelProfileVisibility->setText(Words[24]);
                ui->LabelProfileVisibility->setStyleSheet("color:yellow");
                break;
            }
            default:{
                ui->LabelProfileVisibility->setText(Words[25]);
                ui->LabelProfileVisibility->setStyleSheet("color:white");
            }
            }
        ui->LabelBans->setText(Bans.GetVACBanned()?Words[26]+": "+QString::number(Bans.GetNumberOfVACBans())+"\n"+Words[28]+" "+QString::number(Bans.GetDaysSinceLastBan())+" "+Words[29]:Words[26]+": "+Words[27]);

        if(Setting.GetStatus()=="success"){
            if(Setting.GetMyProfile()==Profile.GetSteamid()){
                ui->ButtonSetProfile->setEnabled(false);
                ui->ButtonGoToMyProfile->setEnabled(false);
            } else {
                ui->ButtonSetProfile->setEnabled(true);
                ui->ButtonGoToMyProfile->setEnabled(Setting.GetMyProfile()=="none"?false:true);
            }
        }
                QNetworkAccessManager imagemanager;
                QEventLoop imageloop;  //Ждем ответ от сервера.
                connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Profile.GetAvatarmedium()));
                imageloop.exec();
                disconnect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                QPixmap img;
                img.loadFromData(imagereply.readAll());
                ui->LabelAvatar->setPixmap(img);
                qDebug()<<img;
                ui->LabelNick->setText(Profile.GetPersonaname());
                //img.save("images/profiles/main.png", "PNG");
        //ui->LabelAvatar->setTextFormat(Qt::RichText);
        //ui->LabelAvatar->setText("<img src=\"images/profiles/main.png\"> "+Profile.GetPersonaname());
        //ui->LabelNick->setFont(QFont("MS Shell Dlg 2",14));
        ui->ButtonGames->setVisible(true);
        ui->ButtonFriends->setVisible(true);
        ui->ButtonFavorites->setVisible(true);
        ui->ButtonSetProfile->setVisible(true);
        ui->ButtonStatistics->setVisible(true);
        ui->ButtonGoToMyProfile->setVisible(true);
        ui->LabelNick->setVisible(true);
        ui->line->setVisible(true);
        ui->LabelProfileVisibility->setVisible(true);
        ui->ScrollAreaProfileInfo->setVisible(true);
        } else {
            QMessageBox::warning(this,Words[30],Words[32]);
        }
}
void MainWindow::on_ButtonGames_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        ui->FormProgressBar->setMaximum(Games.GetCount());
        gamesform = new FormGames(Profile.GetSteamid(),key,Games,this);
        connect(gamesform,SIGNAL(return_to_profile()),this,SLOT(returnfromgames()));
        //QFormLayout* lay = new QFormLayout;
        //lay->addWidget(gamesform);
        //ui->ScrollAreaForm->setLayout(lay);
        ui->ScrollAreaForm->setWidget(gamesform);
        ui->ScrollAreaForm->setVisible(true);
        ui->FormProgressBar->setVisible(true);
        gamesform->setVisible(false);
        //this->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        ui->FormProgressBar->setMaximum(Friends.GetCount());
        friendsform = new FormFriends(Profile.GetSteamid(),key,Friends,this);
        connect(friendsform,SIGNAL(return_to_profile()),this,SLOT(returnfromfriends()));
        connect(friendsform,SIGNAL(go_to_profile(QString,QString,bool)),this,SLOT(GoToProfile(QString,QString,bool)));
        //QFormLayout* lay = new QFormLayout;
        //lay->addWidget(friendsform);
        ui->ScrollAreaForm->setWidget(friendsform);//setLayout(lay);
        ui->ScrollAreaForm->setVisible(true);
        ui->FormProgressBar->setVisible(true);
        friendsform->setVisible(false);
        //friendsform->show();
        //this->setVisible(false);
    }
}
void MainWindow::on_ButtonFavorites_clicked(){

}
void MainWindow::on_ButtonStatistics_clicked(){

}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(Setting.GetStatus()=="success"){
        GoToProfile(Setting.GetMyProfile(),"url",true);
    } else {
        QMessageBox::warning(this,Words[30],Words[32]);
    }
}

void MainWindow::on_ButtonSetProfile_clicked(){
    if(Setting.SetMyProfile(Profile.GetSteamid()))
        ui->ButtonSetProfile->setEnabled(false);
}
void MainWindow::on_ButtonExit_clicked(){
    close();
}

void MainWindow::on_ButtonBack_clicked(){
    if(CurrentBufferProfile>1)
        GoToProfile(BufferProfiles[--CurrentBufferProfile-1],"url",false);
}

void MainWindow::on_ButtonNext_clicked(){
    if(CurrentBufferProfile<BufferProfiles.size())
        GoToProfile(BufferProfiles[++CurrentBufferProfile-1],"url",false);
}



