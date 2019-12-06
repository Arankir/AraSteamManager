#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    switch(Setting.GetTheme()){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
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
//    QTranslator lang;
//    switch(Setting.GetLanguage()){
//    case 1:{
//        lang.load(":/AraSteamManager_en.qm");
//        //qApp->installTranslator(&lang);
//        break;
//    }
//    case 5:{
//        lang.load(":/AraSteamManager_ru.qm");
//        //a->installTranslator(&lang);
//        break;
//    }
//    default:{
//        lang.load(":/AraSteamManager_en.qm");
//        //qApp->installTranslator(&lang);
//    }
//    }
    InitComponents();
    if(Setting.GetStatus()=="success"){
        if(Setting.GetMyProfile()!="none")
            GoToProfile(Setting.GetMyProfile(),"url",true);
    }
}

#define Init {
void MainWindow::InitComponents(){
    ui->LabelAvatar->setText("");
    ui->LabelLogo->setPixmap(QPixmap(":/program/program/logo.png"));
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
    //ui->ScrollAreaForm->setVisible(false);
    ui->LabelNick->setVisible(false);
    ui->line->setVisible(false);
    ui->LabelProfileVisibility->setVisible(false);
    ui->ScrollAreaProfileInfo->setVisible(false);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonFindProfile->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonFavorites->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon(":/"+theme+"/program/"+theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon(":/"+theme+"/program/"+theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon(":/"+theme+"/program/"+theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon(":/"+theme+"/program/"+theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon(":/"+theme+"/program/"+theme+"/games.png"));
    ui->ButtonBack->setIcon(QIcon(":/"+theme+"/program/"+theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon(":/"+theme+"/program/"+theme+"/right.png"));
    ui->ButtonBack->setText("");
    ui->ButtonNext->setText("");
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
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
#define InitEnd }

#define System {
void MainWindow::ShowGames(){
    ui->FormProgressBar->setVisible(false);
    gamesform->setVisible(true);
}
void MainWindow::ShowFriends(){
    ui->FormProgressBar->setVisible(false);
    friendsform->setVisible(true);
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(event->key() == 16777220)
        on_ButtonFindProfile_clicked();
}
void MainWindow::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
    //    ui->retranslateUi(this);
    }
}
MainWindow::~MainWindow(){
    delete ui;
    //if(gamesform)
    //    delete gamesform;
    //if(friendsform)
    //    delete friendsform;
}
void MainWindow::returnfromgames(){
    disconnect(gamesform);
    windowchildcount--;
    delete gamesform;
    windowchild=0;
}
void MainWindow::returnfromfriends(){
    disconnect(friendsform);
    windowchildcount--;
    delete friendsform;
    windowchild=0;
}
void MainWindow::returnfromfavorites(){
    disconnect(favoritesform);
    windowchildcount--;
    delete favoritesform;
    windowchild=0;
}
void MainWindow::returnfromstatistics(){
    disconnect(statisticsform);
    windowchildcount--;
    delete statisticsform;
    windowchild=0;
}
void MainWindow::returnfromsettings(){
    disconnect(settingsform);
    windowchildcount--;
    delete settingsform;
    windowchild=0;
}
#define SystemEnd }

#define Functions {
void MainWindow::on_ButtonFindProfile_clicked(){
    QString id=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        id=id.remove("id/").remove("/");
        GoToProfile(id,"vanity",true);
        } else {
            if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
                id=id.remove("profiles/").remove("/");
            GoToProfile(id,"url",true);
            }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}
void MainWindow::GoToProfile(QString id, QString type, bool UpdateBuffer){
    SProfile Profiles(key,id,false,type);
    if(Profiles.GetStatus()=="success"){
        if(windowchild==2)
            returnfromfriends();
        if(windowchild==1)
            returnfromgames();
        if(UpdateBuffer){
            if(CurrentBufferProfile!=BufferProfiles.size())
                while(BufferProfiles.size()!=CurrentBufferProfile)
                    BufferProfiles.takeAt(CurrentBufferProfile);
            BufferProfiles.append(Profiles.GetSteamid());
            CurrentBufferProfile=BufferProfiles.size();
        }
        if(CurrentBufferProfile==BufferProfiles.size())
            ui->ButtonNext->setEnabled(false);
        else
            ui->ButtonNext->setEnabled(true);
        if(CurrentBufferProfile<2)
            ui->ButtonBack->setEnabled(false);
        else
            ui->ButtonBack->setEnabled(true);
        qDebug()<<"Буфер профилей"<<BufferProfiles<<CurrentBufferProfile<<"/"<<BufferProfiles.size();
        Profile=Profiles;
        Games.Clear();
        Friends.Clear();
        SBans Bans(key,Profile.GetSteamid(),false);
        SLevels Levels(key,Profile.GetSteamid());
        Games.Set(key,Profile.GetSteamid(),true,true,false);
        Friends.Set(key,Profile.GetSteamid(),false);
        //ui->LabelProfileUrl->setTextFormat(Qt::RichText);
        //ui->LabelProfileUrl->setText("<img src=\":/"+theme+"/program/"+theme+"/link.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
        ui->ButtonGames->setText(tr(" Игры (%1)").arg(Games.GetStatus()=="success"?QString::number(Games.GetCount()):"error"));
        ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(Friends.GetStatus()=="success"?QString::number(Friends.GetCount()):"error"));
        if(!Profile.GetGameextrainfo().isEmpty()){
            ui->LabelPersonaState->setText(tr("В игре %1").arg(Profile.GetGameextrainfo()));
            ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (Profile.GetPersonastate()) {
            case 0:{
                    ui->LabelPersonaState->setText(tr("Был в сети %1").arg(Profile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss")));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
            }
            case 1:{
                    ui->LabelPersonaState->setText(tr("В сети"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
            }
            case 2:{
                    ui->LabelPersonaState->setText(tr("Не беспокоить"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
            }
            case 3:{
                    ui->LabelPersonaState->setText(tr("Нет на месте"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 4:{
                    ui->LabelPersonaState->setText(tr("Спит"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 5:{
                    ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            case 6:{
                    ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            }
        ui->LabelProfileUrl->setText(Profile.GetProfileurl());
        ui->Labellvl->setText(tr("Уровень: %1").arg(QString::number(Levels.GetPlayer_level())));
        ui->LabelRealName->setText(tr("Настоящее имя: %1").arg(Profile.GetRealname()));
        ui->LabelTimeCreated->setText(tr("Аккаунт создан: %1").arg(Profile.GetTimecreated().toString("yyyy.MM.dd")));
        ui->LabelLocCountryCode->setText(tr("Язык: %1").arg(Profile.GetLoccountrycode()));
        switch (Profile.GetCommunityvisibilitystate()) {
            case 1:{
                ui->LabelProfileVisibility->setText(tr("Скрытый"));
                ui->LabelProfileVisibility->setStyleSheet("color:red");
                break;
            }
            case 3:{
                ui->LabelProfileVisibility->setText(tr("Публичный"));
                ui->LabelProfileVisibility->setStyleSheet("color:green");
                break;
            }
            case 8:{
                ui->LabelProfileVisibility->setText(tr("Для друзей"));
                ui->LabelProfileVisibility->setStyleSheet("color:yellow");
                break;
            }
            default:{
                ui->LabelProfileVisibility->setText(tr("Неизвестно"));
                ui->LabelProfileVisibility->setStyleSheet("color:white");
            }
            }
        if(Bans.GetVACBanned()){
            ui->LabelBans->setText(tr("VAC баны: %1| Последний %2 дней назад").arg(QString::number(Bans.GetNumberOfVACBans())).arg(QString::number(Bans.GetDaysSinceLastBan())));
            ui->LabelBans->setStyleSheet("color:red");
        } else {
            ui->LabelBans->setText(tr("VAC баны: Отсутствуют"));
            ui->LabelBans->setStyleSheet("color:green");
        }

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
            QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
        }
}
void MainWindow::on_ButtonGames_clicked(){
    if(windowchild==2){
        returnfromfriends();
    }
    if(windowchild==3){
        returnfromfavorites();
    }
    if(windowchild==4){
        returnfromstatistics();
    }
    if(windowchild==5){
        returnfromsettings();
    }
    if(windowchild!=1){
        windowchild=1;
        ui->FormProgressBar->setMaximum(Games.GetCount());
        gamesform = new FormGames(Profile.GetSteamid(),key,Games,this);
        connect(gamesform,&FormGames::return_to_profile,this,&MainWindow::returnfromgames);
        ui->ScrollAreaForm->setWidget(gamesform);
        ui->FormProgressBar->setVisible(true);
        gamesform->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(windowchild==1){
        returnfromgames();
    }
    if(windowchild==3){
        returnfromfavorites();
    }
    if(windowchild==4){
        returnfromstatistics();
    }
    if(windowchild==5){
        returnfromsettings();
    }
    if(windowchild!=2){
        windowchild=2;
        ui->FormProgressBar->setMaximum(Friends.GetCount());
        friendsform = new FormFriends(Profile.GetSteamid(),key,Friends,this);
        connect(friendsform,&FormFriends::return_to_profile,this,&MainWindow::returnfromfriends);
        connect(friendsform,&FormFriends::go_to_profile,this,&MainWindow::GoToProfile);
        ui->ScrollAreaForm->setWidget(friendsform);
        ui->FormProgressBar->setVisible(true);
        friendsform->setVisible(false);
    }
}
void MainWindow::on_ButtonFavorites_clicked(){
    if(windowchild==1){
        returnfromgames();
    }
    if(windowchild==2){
        returnfromfriends();
    }
    if(windowchild==4){
        returnfromstatistics();
    }
    if(windowchild==5){
        returnfromsettings();
    }
    if(windowchild!=3){
        windowchild=3;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        favoritesform = new FormFavorites();
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(favoritesform);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonStatistics_clicked(){
    if(windowchild==1){
        returnfromgames();
    }
    if(windowchild==2){
        returnfromfriends();
    }
    if(windowchild==3){
        returnfromfavorites();
    }
    if(windowchild==5){
        returnfromsettings();
    }
    if(windowchild!=4){
        windowchild=4;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        statisticsform = new FormStatistics();
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(statisticsform);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonSettings_clicked(){
    if(windowchild==1){
        returnfromgames();
    }
    if(windowchild==2){
        returnfromfriends();
    }
    if(windowchild==3){
        returnfromfavorites();
    }
    if(windowchild==4){
        returnfromstatistics();
    }
    if(windowchild!=5){
        windowchild=5;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        settingsform = new FormSettings();
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(settingsform);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(Setting.GetStatus()=="success"){
        GoToProfile(Setting.GetMyProfile(),"url",true);
    } else {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
    }
}
void MainWindow::on_ButtonSetProfile_clicked(){
    if(Setting.SetMyProfile(Profile.GetSteamid())){
        ui->ButtonSetProfile->setEnabled(false);
        ui->ButtonGoToMyProfile->setEnabled(false);
    }
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
#define FunctionsEnd }

