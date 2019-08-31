#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
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
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        QFile FileLanguage;
        if (settings.open(QIODevice::ReadOnly)){
            QStringList setting;
            while(!settings.atEnd()){
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            while (!setting.isEmpty()) {
                QString sett=setting.takeAt(0);
                if(sett.indexOf("MyProfile=",0)!=-1){
                    if(sett.indexOf("MyProfile=none",0)==-1){
                        ui->LineEditIdProfile->setText(sett.mid(sett.indexOf("MyProfile=",0)+10,sett.length()));
                        ui->ButtonFindProfile->click();
                        }
                    }
                if(sett.indexOf("Theme=",0)!=-1){
                        Theme=sett.mid(sett.indexOf("Theme=",0)+6,sett.length()).toInt();
                        }
                if(sett.indexOf("Language=",0)!=-1){
                        switch(language=sett.mid(sett.indexOf("Language=",0)+9,sett.length()).toInt()){
                        case 1:{
                            FileLanguage.setFileName("Files/Languages/ENG/mainwindow.txt");
                            break;
                            }
                        case 5:{
                            FileLanguage.setFileName("Files/Languages/RU/mainwindow.txt");
                            }
                        }
                        if(FileLanguage.open(QIODevice::ReadOnly)){
                            while(!FileLanguage.atEnd()){
                                SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n").remove("\n");
                            }
                        }
                        }
                if(sett.indexOf("SaveImages=",0)!=-1){
                        SaveImages=sett.mid(sett.indexOf("SaveImages=",0)+11,sett.length()).toInt();
                        }
                }
            settings.close();
            }
        }
    ui->ButtonFindProfile->setText(" "+SLLanguage[0]);
    ui->LineEditIdProfile->setPlaceholderText(SLLanguage[1]);
    ui->ButtonFavorites->setText(" "+SLLanguage[2]);
    ui->ButtonSetProfile->setText(SLLanguage[3]);
    ui->ButtonStatistics->setText(" "+SLLanguage[4]);
    ui->ButtonSettings->setText(SLLanguage[5]);
    ui->ButtonExit->setText(" "+SLLanguage[23]);
    ui->ButtonGoToMyProfile->setText(SLLanguage[24]);
    //        ui->LabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //        ui->LabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    QPixmap pixmap2("images/program/statistic_white.png","PNG");
//    QIcon ButtonIcon2(pixmap2);
//    ui->ButtonStatistics->setIcon(ButtonIcon2);
//    ui->ButtonSettings->setIconSize(pixmap.rect().size());
//    ui->ButtonStatistics->setIconSize(QSize(13,13));
    switch(Theme){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,???               ,???                 ,???      ,???     ,цвет текста на кнопке,???  ,поле сзади,???
        qApp->setPalette(darkPalette);
        ui->ButtonFindProfile->setIcon(QIcon("images/program/find_white.png"));
        ui->ButtonFavorites->setIcon(QIcon("images/program/favorites_white.png"));
        ui->ButtonStatistics->setIcon(QIcon("images/program/statistic_white.png"));
        ui->ButtonSettings->setIcon(QIcon("images/program/settings_white.png"));
        ui->ButtonExit->setIcon(QIcon("images/program/exit_white.png"));
        ui->ButtonFriends->setIcon(QIcon("images/program/friends_white.png"));
        ui->ButtonGames->setIcon(QIcon("images/program/games_white.png"));
        break;
        }
    case 2:{
        ui->ButtonFindProfile->setIcon(QIcon("images/program/find_black.png"));
        ui->ButtonFavorites->setIcon(QIcon("images/program/favorites_black.png"));
        ui->ButtonStatistics->setIcon(QIcon("images/program/statistic_black.png"));
        ui->ButtonSettings->setIcon(QIcon("images/program/settings_black.png"));
        ui->ButtonExit->setIcon(QIcon("images/program/exit_black.png"));
        ui->ButtonFriends->setIcon(QIcon("images/program/friends_black.png"));
        ui->ButtonGames->setIcon(QIcon("images/program/games_black.png"));
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
    QEventLoop loopp;
    QObject::connect(&Profile, SIGNAL(finished()), &loopp, SLOT(quit()));
    QString ids=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove("/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        ids=ui->LineEditIdProfile->text().remove("id");
        Profile.Set(key,ids,"vanity");
        } else {
            if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
                ids=ui->LineEditIdProfile->text().remove("profiles");
            Profile.Set(key,ids,"url");
            }
    loopp.exec();
    if(Profile.GetStatus()=="success"){
        id=ids;
        SteamAPIBans Bans(key,id);
        QObject::connect(&Bans, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        SteamAPILevels Levels(key,id);
        QObject::connect(&Levels, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        Games.Set(key,id,true,true);
        QObject::connect(&Games, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        Friends.Set(key,id);
        QObject::connect(&Friends, SIGNAL(finished()), &loopp, SLOT(quit()));
        loopp.exec();
        QNetworkAccessManager manager;
        QEventLoop loop;  //Ждем ответ от сервера.
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &ReplyOwnedGames = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id));
            loop.exec();
            DocOwnedGames = QJsonDocument::fromJson(ReplyOwnedGames.readAll());
            QNetworkReply &ReplyFriendList = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
            loop.exec();
            DocFriendList = QJsonDocument::fromJson(ReplyFriendList.readAll());
        switch(Theme){
        case 1:{
            ui->LabelProfileUrl->setTextFormat(Qt::RichText);
            ui->LabelProfileUrl->setText("<img src=\"images/program/link_white.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
            break;
            }
        case 2:{
            ui->LabelProfileUrl->setTextFormat(Qt::RichText);
            ui->LabelProfileUrl->setText("<img src=\"images/program/link_black.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
            break;
            }
        }
        ui->LabelRealName->setText(SLLanguage[8]+": "+Profile.GetRealname());
        ui->LabelTimeCreated->setText(SLLanguage[9]+" "+Profile.GetTimecreated().toString("yyyy.MM.dd"));
        ui->Labellvl->setText(SLLanguage[25]+": "+QString::number(Levels.GetPlayer_level()));
        if(Bans.GetVACBanned()){
            ui->LabelBans->setText(SLLanguage[26]+": "+QString::number(Bans.GetNumberOfVACBans())+"\n"+SLLanguage[28]+" "+QString::number(Bans.GetDaysSinceLastBan())+" "+SLLanguage[29]);
        } else {
            ui->LabelBans->setText(SLLanguage[26]+": "+SLLanguage[27]);
        }
        if(Games.GetStatus()=="success")
            ui->ButtonGames->setText(" "+SLLanguage[10]+"("+QString::number(Games.GetGamesCount())+")");
        else
            ui->ButtonGames->setText(" "+SLLanguage[10]+"(error)");
        if(Friends.GetStatus()=="success")
            ui->ButtonFriends->setText(" "+SLLanguage[11]+"("+QString::number(Friends.GetFriendsCount())+")");
        else
            ui->ButtonFriends->setText(" "+SLLanguage[11]+"(error)");
        if(!Profile.GetGameextrainfo().isEmpty()){
            ui->LabelPersonaState->setText(SLLanguage[12]+":\n"+Profile.GetGameextrainfo());
            ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (Profile.GetPersonastate()) {
            case 0:{
                    ui->LabelPersonaState->setText(SLLanguage[13]+":\n"+Profile.GetLastlogoff().toString("yyyy.MM.dd\nhh:mm:ss"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
            }
            case 1:{
                    ui->LabelPersonaState->setText(SLLanguage[14]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
            }
            case 2:{
                    ui->LabelPersonaState->setText(SLLanguage[15]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
            }
            case 3:{
                    ui->LabelPersonaState->setText(SLLanguage[16]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 4:{
                    ui->LabelPersonaState->setText(SLLanguage[17]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 5:{
                    ui->LabelPersonaState->setText(SLLanguage[18]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            case 6:{
                    ui->LabelPersonaState->setText(SLLanguage[19]);
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            }
        ui->LabelLocCountryCode->setText(SLLanguage[20]+": "+Profile.GetLoccountrycode());
        if(QFile::exists("Files/Settings.txt")){
            QFile settings("Files/Settings.txt");
            if (settings.open(QIODevice::ReadOnly)){
                QString FileText=QString::fromLocal8Bit(settings.readAll());
                while (FileText.length()) {
                    QString FileLine=FileText.mid(0,FileText.indexOf("\r\n",0));
                    if(FileText.indexOf("\r\n",0)!=-1)
                        FileText=FileText.mid(FileText.indexOf("\r\n",0)+2,FileText.length()-FileText.indexOf("\r\n",0));
                    else
                        FileText="";
                    if(FileLine.indexOf("MyProfile=",0)!=-1){
                        if(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length())==ids){
                            ui->ButtonSetProfile->setEnabled(false);
                            ui->ButtonGoToMyProfile->setEnabled(false);
                        } else {
                            ui->ButtonSetProfile->setEnabled(true);
                            if(FileLine.indexOf("MyProfile=none",0)>-1){
                                ui->ButtonGoToMyProfile->setEnabled(false);
                            } else {
                                ui->ButtonGoToMyProfile->setEnabled(true);
                            }
                        }
                    }
                }
                settings.close();
            } else
                QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
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
        if(Profile.GetCommunityvisibilitystate()!=3){
            //профиль скрыт
        }
        } else {
                QMessageBox::warning(this,SLLanguage[6],SLLanguage[21]);
        }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}
void MainWindow::on_ButtonGames_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        gamesform = new FormGames(id,key,language,Theme,DocOwnedGames,SaveImages);
        connect(gamesform,SIGNAL(return_to_profile(FormGames*)),this,SLOT(on_return(FormGames*)));
        gamesform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        friendsform = new FormFriends(id,key,language,Theme,Friends,SaveImages);
        connect(friendsform,SIGNAL(return_to_profile(FormFriends*)),this,SLOT(on_return(FormFriends*)));
        connect(friendsform,SIGNAL(go_to_profile(QString)),this,SLOT(on_go_to_profile(QString)));
        friendsform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_ButtonSetProfile_clicked(){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    file.open(QIODevice::WriteOnly);
            //дефолтные данные
    file.close();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
    } else {
        QString FileText=QString::fromLocal8Bit(file.readAll());
        qDebug() << FileText;
        file.close();
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        while (FileText.length()) {
            QString FileLine=FileText.mid(0,FileText.indexOf("\r\n",0));
            if(FileText.indexOf("\r\n",0)!=-1)
                FileText=FileText.mid(FileText.indexOf("\r\n",0)+2,FileText.length()-FileText.indexOf("\r\n",0));
            else
                FileText="";
            if(FileLine.indexOf("MyProfile=",0)!=-1){
                writeStream << "MyProfile="+id<<'\r'<<'\n';
            } else {
                writeStream << FileLine<<'\r'<<'\n';
            }
        }
        file.close();
        ui->ButtonSetProfile->setEnabled(false);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        if (settings.open(QIODevice::ReadOnly)){
            QString FileText=QString::fromLocal8Bit(settings.readAll());
            while (FileText.length()) {
                QString FileLine=FileText.mid(0,FileText.indexOf("\r\n",0));
                if(FileText.indexOf("\r\n",0)!=-1)
                    FileText=FileText.mid(FileText.indexOf("\r\n",0)+2,FileText.length()-FileText.indexOf("\r\n",0));
                else
                    FileText="";
                if(FileLine.indexOf("MyProfile=",0)!=-1){
                    ui->LineEditIdProfile->setText(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length()));
                    ui->ButtonFindProfile->click();
                    }
                }
            }
            settings.close();
        } else
            QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
}
void MainWindow::on_ButtonExit_clicked(){
    close();
}
