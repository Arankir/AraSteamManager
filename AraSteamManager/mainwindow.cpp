#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    Words=Setting.GetWords("mainwindow");
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
    ui->ButtonFindProfile->setText(" "+Words[0]);
    ui->LineEditIdProfile->setPlaceholderText(Words[1]);
    ui->ButtonFavorites->setText(" "+Words[2]);
    ui->ButtonSetProfile->setText(Words[3]);
    ui->ButtonStatistics->setText(" "+Words[4]);
    ui->ButtonSettings->setText(Words[5]);
    ui->ButtonExit->setText(" "+Words[23]);
    ui->ButtonGoToMyProfile->setText(Words[24]);
    if(Setting.GetStatus()=="success"){
        if(Setting.GetMyProfile()!="none")
            GoToProfile(Setting.GetMyProfile(),"url");
    }
    //        ui->LabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //        ui->LabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    QPixmap pixmap2("images/program/statistic_white.png","PNG");
//    QIcon ButtonIcon2(pixmap2);
//    ui->ButtonStatistics->setIcon(ButtonIcon2);
//    ui->ButtonSettings->setIconSize(pixmap.rect().size());
//    ui->ButtonStatistics->setIconSize(QSize(13,13));
    switch(Setting.GetTheme()){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,???               ,???                 ,???      ,???     ,цвет текста на кнопке,???  ,поле сзади,???
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
    ui->ButtonFindProfile->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonFavorites->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon(":/"+theme+"/program/"+theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon(":/"+theme+"/program/"+theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon(":/"+theme+"/program/"+theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon(":/"+theme+"/program/"+theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon(":/"+theme+"/program/"+theme+"/games.png"));
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if( event->key() == 16777220)
        on_ButtonFindProfile_clicked();
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_return(FormGames* a){
    this->setVisible(true);
    windowchildcount--;
    a->deleteLater();
}
void MainWindow::on_return(FormFriends* a){
    this->setVisible(true);
    windowchildcount--;
    a->deleteLater();
}
void MainWindow::on_go_to_profile(QString id){
    ui->LineEditIdProfile->setText(id);
    ui->ButtonFindProfile->click();
}

void MainWindow::on_ButtonFindProfile_clicked(){
    QString id=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove("/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        id=ui->LineEditIdProfile->text().remove("id");
        GoToProfile(id,"vanity");
        } else {
            if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
                id=ui->LineEditIdProfile->text().remove("profiles");
            GoToProfile(id,"url");
            }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}
void MainWindow::GoToProfile(QString id, QString type){
    QEventLoop loopp;
    QObject::connect(&Profile, SIGNAL(finished()), &loopp, SLOT(quit()));
    Profile.Set(key,id,type);
    loopp.exec();
    if(Profile.GetStatus()=="success"){
        SteamAPIBans Bans(key,Profile.GetSteamid());
        QObject::connect(&Bans, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        SteamAPILevels Levels(key,Profile.GetSteamid());
        QObject::connect(&Levels, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        Games.Set(key,Profile.GetSteamid(),true,true);
        QObject::connect(&Games, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        Friends.Set(key,Profile.GetSteamid());
        QObject::connect(&Friends, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        QNetworkAccessManager manager;
        QEventLoop loop;  //Ждем ответ от сервера.
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        //ui->LabelProfileUrl->setTextFormat(Qt::RichText);
        //ui->LabelProfileUrl->setText("<img src=\":/"+theme+"/program/"+theme+"/link.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
        ui->LabelProfileUrl->setText(Profile.GetProfileurl());
        ui->LabelRealName->setText(Words[8]+": "+Profile.GetRealname());
        ui->LabelTimeCreated->setText(Words[9]+" "+Profile.GetTimecreated().toString("yyyy.MM.dd"));
        ui->Labellvl->setText(Words[25]+": "+QString::number(Levels.GetPlayer_level()));
        if(Bans.GetVACBanned()){
            ui->LabelBans->setText(Words[26]+": "+QString::number(Bans.GetNumberOfVACBans())+"\n"+Words[28]+" "+QString::number(Bans.GetDaysSinceLastBan())+" "+Words[29]);
        } else {
            ui->LabelBans->setText(Words[26]+": "+Words[27]);
        }
        if(Games.GetStatus()=="success")
            ui->ButtonGames->setText(" "+Words[10]+"("+QString::number(Games.GetGamesCount())+")");
        else
            ui->ButtonGames->setText(" "+Words[10]+" (error)");
        if(Friends.GetStatus()=="success")
            ui->ButtonFriends->setText(" "+Words[11]+"("+QString::number(Friends.GetFriendsCount())+")");
        else
            ui->ButtonFriends->setText(" "+Words[11]+" (error)");
        if(!Profile.GetGameextrainfo().isEmpty()){
            ui->LabelPersonaState->setText(Words[12]+":\n"+Profile.GetGameextrainfo());
            ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (Profile.GetPersonastate()) {
            case 0:{
                    ui->LabelPersonaState->setText(Words[13]+":\n"+Profile.GetLastlogoff().toString("yyyy.MM.dd\nhh:mm:ss"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
            }
            case 1:{
                    ui->LabelPersonaState->setText(Words[14]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
            }
            case 2:{
                    ui->LabelPersonaState->setText(Words[15]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
            }
            case 3:{
                    ui->LabelPersonaState->setText(Words[16]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 4:{
                    ui->LabelPersonaState->setText(Words[17]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 5:{
                    ui->LabelPersonaState->setText(Words[18]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            case 6:{
                    ui->LabelPersonaState->setText(Words[19]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            }
        ui->LabelLocCountryCode->setText(Words[20]+": "+Profile.GetLoccountrycode());
        if(Setting.GetStatus()=="success"){
            if(Setting.GetMyProfile()==Profile.GetSteamid()){
                ui->ButtonSetProfile->setEnabled(false);
                ui->ButtonGoToMyProfile->setEnabled(false);
            } else {
                ui->ButtonSetProfile->setEnabled(true);
                if(Setting.GetMyProfile()=="none"){
                    ui->ButtonGoToMyProfile->setEnabled(false);
                } else {
                    ui->ButtonGoToMyProfile->setEnabled(true);
                }
            }
        }
                QNetworkAccessManager imagemanager;
                QEventLoop imageloop;  //Ждем ответ от сервера.
                QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Profile.GetAvatar()));
                imageloop.exec();
                QImage img;
                img.loadFromData(imagereply.readAll());
                img.save("images/profiles/main.png", "PNG");
        ui->LabelAvatar->setTextFormat(Qt::RichText);
        ui->LabelAvatar->setText("<img src=\"images/profiles/main.png\"> "+Profile.GetPersonaname());
        ui->LabelAvatar->setFont(QFont("MS Shell Dlg 2",14));
        ui->ButtonGames->setVisible(true);
        ui->ButtonFriends->setVisible(true);
        ui->ButtonFavorites->setVisible(true);
        ui->ButtonSetProfile->setVisible(true);
        ui->ButtonStatistics->setVisible(true);
        ui->ButtonGoToMyProfile->setVisible(true);
        if(Profile.GetCommunityvisibilitystate()!=3){
            //профиль скрыт
        }
        } else {
                QMessageBox::warning(this,Words[6],Words[21]);
        }
}
void MainWindow::on_ButtonGames_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        gamesform = new FormGames(Profile.GetSteamid(),key,Games);
        connect(gamesform,SIGNAL(return_to_profile(FormGames*)),this,SLOT(on_return(FormGames*)));
        gamesform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        friendsform = new FormFriends(Profile.GetSteamid(),key,Friends);
        connect(friendsform,SIGNAL(return_to_profile(FormFriends*)),this,SLOT(on_return(FormFriends*)));
        connect(friendsform,SIGNAL(go_to_profile(QString)),this,SLOT(on_go_to_profile(QString)));
        friendsform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_ButtonSetProfile_clicked(){
    if(Setting.SetMyProfile(Profile.GetSteamid()))
        ui->ButtonSetProfile->setEnabled(false);
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(Setting.GetStatus()=="success"){
        GoToProfile(Setting.GetMyProfile(),"url");
    } else {
        QMessageBox::warning(this,Words[6],Words[7]);
    }
}
void MainWindow::on_ButtonExit_clicked(){
    close();
}
