#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->FormProfileAvatar->setText("");
    ui->FormProfileLabelLogo->setText("(WIP)");
    ui->FormProfileLabelTimeCreated->setText("");
    ui->FormProfileLabelPersonaState->setText("");
    ui->FormProfileLabelLocCountryCode->setText("");
    ui->FormProfileLabelProfileUrl->setText("");
    ui->FormProfileLabelRealName->setText("");
    ui->FormProfileLabellvl->setText("");
    ui->FormProfileLabelBans->setText("");
    ui->FormProfileLabelPersonaState->setWordWrap(true);
    ui->FormProfileButtonGames->setVisible(false);
    ui->FormProfileButtonFriends->setVisible(false);
    ui->FormProfileButtonFavorites->setVisible(false);
    ui->FormProfileButtonSetProfile->setVisible(false);
    ui->FormProfileButtonStatistics->setVisible(false);
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
        QFile FileLanguage;
        if (settings.open(QIODevice::ReadOnly)){
            QStringList setting;
            while(!settings.atEnd()){
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n");
            }
            while (!setting.isEmpty()) {
                QString sett=setting.takeAt(0);
                if(sett.indexOf("MyProfile=",0)!=-1){
                    if(sett.indexOf("MyProfile=none",0)==-1){
                        ui->FormProfileLineEditIdProfile->setText(sett.mid(sett.indexOf("MyProfile=",0)+10,sett.length()));
                        ui->FormProfileButtonFindProfile->click();
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
                                SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n");
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
    ui->FormProfileButtonFindProfile->setText(" "+SLLanguage[0]);
    ui->FormProfileLineEditIdProfile->setPlaceholderText(SLLanguage[1]);
    ui->FormProfileButtonFavorites->setText(" "+SLLanguage[2]);
    ui->FormProfileButtonSetProfile->setText(SLLanguage[3]);
    ui->FormProfileButtonStatistics->setText(" "+SLLanguage[4]);
    ui->FormProfileButtonSettings->setText(SLLanguage[5]);
    ui->FormProfileButtonExit->setText(" "+SLLanguage[23]);
    ui->FormProfileButtonGoToMyProfile->setText(SLLanguage[24]);
    //        ui->FormProfileLabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //        ui->FormProfileLabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    QPixmap pixmap2("images/program/statistic_white.png","PNG");
//    QIcon ButtonIcon2(pixmap2);
//    ui->FormProfileButtonStatistics->setIcon(ButtonIcon2);
//    ui->FormProfileButtonSettings->setIconSize(pixmap.rect().size());
//    ui->FormProfileButtonStatistics->setIconSize(QSize(13,13));
    switch(Theme){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,???               ,???                 ,???      ,???     ,цвет текста на кнопке,???  ,поле сзади,???
        qApp->setPalette(darkPalette);
        ui->FormProfileButtonFindProfile->setIcon(QIcon("images/program/find_white.png"));
        ui->FormProfileButtonFavorites->setIcon(QIcon("images/program/favorites_white.png"));
        ui->FormProfileButtonStatistics->setIcon(QIcon("images/program/statistic_white.png"));
        ui->FormProfileButtonSettings->setIcon(QIcon("images/program/settings_white.png"));
        ui->FormProfileButtonExit->setIcon(QIcon("images/program/exit_white.png"));
        ui->FormProfileButtonFriends->setIcon(QIcon("images/program/friends_white.png"));
        ui->FormProfileButtonGames->setIcon(QIcon("images/program/games_white.png"));
        break;
        }
    case 2:{
        ui->FormProfileButtonFindProfile->setIcon(QIcon("images/program/find_black.png"));
        ui->FormProfileButtonFavorites->setIcon(QIcon("images/program/favorites_black.png"));
        ui->FormProfileButtonStatistics->setIcon(QIcon("images/program/statistic_black.png"));
        ui->FormProfileButtonSettings->setIcon(QIcon("images/program/settings_black.png"));
        ui->FormProfileButtonExit->setIcon(QIcon("images/program/exit_black.png"));
        ui->FormProfileButtonFriends->setIcon(QIcon("images/program/friends_black.png"));
        ui->FormProfileButtonGames->setIcon(QIcon("images/program/games_black.png"));
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
        on_FormProfileButtonFindProfile_clicked();
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
    ui->FormProfileLineEditIdProfile->setText(id);
    ui->FormProfileButtonFindProfile->click();
}

void MainWindow::on_FormProfileButtonFindProfile_clicked(){
    QString ids;
    if(ui->FormProfileLineEditIdProfile->text().indexOf("steamcommunity.com/profiles/",0)>-1){
        ids=ui->FormProfileLineEditIdProfile->text().remove("steamcommunity.com/profiles/").remove("https://").remove('\r').remove("/");
    } else
        if(ui->FormProfileLineEditIdProfile->text().indexOf("steamcommunity.com/id/",0)>-1){
            QString vanity=ui->FormProfileLineEditIdProfile->text().remove("https://steamcommunity.com/id/").remove("https://").remove('\r').remove("/");
            QNetworkAccessManager manager;
            QEventLoop loop;  //Ждем ответ от сервера.
            QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &Reply = *manager.get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+key+"&vanityurl="+vanity+"&url_type=1"));
            loop.exec();
            QJsonDocument Doc = QJsonDocument::fromJson(Reply.readAll());
            ids=Doc.object().value("response").toObject().value("steamid").toString();
        } else
            ids=ui->FormProfileLineEditIdProfile->text().remove('\r');
    QNetworkAccessManager manager;
    QEventLoop loop;  //Ждем ответ от сервера.
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &ReplyPlayerSummaries = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+ids));
    loop.exec();
    DocPlayerSummaries = QJsonDocument::fromJson(ReplyPlayerSummaries.readAll());
    //{"response":
    //{"players":
    //[{"steamid":"76561198065018572",
    //"communityvisibilitystate":3, (1 - the profile is not visible to you, 3 - the profile is "Public")
    //"profilestate":1,
    //"personaname":"Yuno",
    //"lastlogoff":1555174765,
    //"commentpermission":1,
    //"profileurl":"https://steamcommunity.com/id/Arankir/",
    //"avatar":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c.jpg",
    //"avatarmedium":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_medium.jpg",
    //"avatarfull":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_full.jpg",
    //"personastate":1,
    //"primaryclanid":"103582791434380590",
    //"timecreated":1339187696,
    //"personastateflags":0,
    //"gameextrainfo":"Realm of the Mad God",
    //"gameid":"200210",
    //"loccountrycode":"JP",
    //"locstatecode":"40",
    //"loccityid":26111}]}}
    if(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        id=ids;
        QNetworkReply &Replylevels = *manager.get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+key+"&steamid="+id));
        loop.exec();
        QJsonDocument Doclvl = QJsonDocument::fromJson(Replylevels.readAll());
        //{"response":{"player_level":67}}
        QNetworkReply &Replybans = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+key+"&steamids="+id));
        loop.exec();
        QJsonDocument Docban = QJsonDocument::fromJson(Replybans.readAll());
        //{"players":[{
        //"SteamId":"76561198065018572",
        //"CommunityBanned":false,
        //"VACBanned":false,
        //"NumberOfVACBans":0,
        //"DaysSinceLastBan":0,
        //"NumberOfGameBans":0,
        //"EconomyBan":"none"}]}
        QNetworkReply &ReplyOwnedGames = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id));
        loop.exec();
        DocOwnedGames = QJsonDocument::fromJson(ReplyOwnedGames.readAll());
        QNetworkReply &ReplyFriendList = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        loop.exec();
        DocFriendList = QJsonDocument::fromJson(ReplyFriendList.readAll());
        QJsonObject Account=DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject();
        switch(Theme){
        case 1:{
            ui->FormProfileLabelProfileUrl->setTextFormat(Qt::RichText);
            ui->FormProfileLabelProfileUrl->setText("<img src=\"images/program/link_white.png\" width=\"15\" height=\"15\">"+Account.value("profileurl").toString());
            break;
            }
        case 2:{
            ui->FormProfileLabelProfileUrl->setTextFormat(Qt::RichText);
            ui->FormProfileLabelProfileUrl->setText("<img src=\"images/program/link_black.png\" width=\"15\" height=\"15\">"+Account.value("profileurl").toString());
            break;
            }
        }
        QDateTime date=QDateTime::fromSecsSinceEpoch(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("timecreated").toInt(),Qt::LocalTime);
        ui->FormProfileLabelRealName->setText(SLLanguage[8]+": "+Account.value("realname").toString());
        ui->FormProfileLabelTimeCreated->setText(SLLanguage[9]+" "+date.toString("yyyy.MM.dd"));
        ui->FormProfileLabellvl->setText(SLLanguage[25]+": "+QString::number(Doclvl.object().value("response").toObject().value("player_level").toInt()));
        if(Docban.object().value("players").toArray().at(0).toObject().value("VACBanned").toBool()){
            ui->FormProfileLabelBans->setText(SLLanguage[26]+": "+QString::number(Docban.object().value("players").toArray().at(0).toObject().value("NumberOfVACBans").toInt())+"\n"+SLLanguage[28]+" "+QString::number(Docban.object().value("players").toArray().at(0).toObject().value("DaysSinceLastBan").toInt())+" "+SLLanguage[29]);
        } else {
            ui->FormProfileLabelBans->setText(SLLanguage[26]+": "+SLLanguage[27]);
        }
        ui->FormProfileButtonGames->setText(" "+SLLanguage[10]+"("+QString::number(DocOwnedGames.object().value("response").toObject().value("game_count").toInt())+")");
        ui->FormProfileButtonFriends->setText(" "+SLLanguage[11]+"("+QString::number(DocFriendList.object().value("friendslist").toObject().value("friends").toArray().size())+")");
        if(!DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("gameextrainfo").toString().isEmpty()){
            ui->FormProfileLabelPersonaState->setText(SLLanguage[12]+":\n"+DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("gameextrainfo").toString());
            ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (Account.value("personastate").toInt()) {
            case 0:{
                QDateTime date=QDateTime::fromSecsSinceEpoch(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("lastlogoff").toInt(),Qt::LocalTime);
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[13]+":\n"+date.toString("yyyy.MM.dd\nhh:mm:ss"));
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
            }
            case 1:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[14]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
            }
            case 2:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[15]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
            }
            case 3:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[16]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 4:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[17]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
            }
            case 5:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[18]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            case 6:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[19]);
                    ui->FormProfileLabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }
            }
        ui->FormProfileLabelLocCountryCode->setText(SLLanguage[20]+": "+Account.value("loccountrycode").toString());
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
                            ui->FormProfileButtonSetProfile->setEnabled(false);
                            ui->FormProfileButtonGoToMyProfile->setEnabled(false);
                        } else {
                            ui->FormProfileButtonSetProfile->setEnabled(true);
                            if(FileLine.indexOf("MyProfile=none",0)>-1){
                                ui->FormProfileButtonGoToMyProfile->setEnabled(false);
                            } else {
                                ui->FormProfileButtonGoToMyProfile->setEnabled(true);
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
                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Account.value("avatar").toString()));
                imageloop.exec();
                QImage img;
                img.loadFromData(imagereply.readAll());
                img.save("images/profiles/main.png", "PNG");
        ui->FormProfileAvatar->setTextFormat(Qt::RichText);
        ui->FormProfileAvatar->setText("<img src=\"images/profiles/main.png\"> "+Account.value("personaname").toString());
        ui->FormProfileAvatar->setFont(QFont("MS Shell Dlg 2",14));
        ui->FormProfileButtonGames->setVisible(true);
        ui->FormProfileButtonFriends->setVisible(true);
        ui->FormProfileButtonFavorites->setVisible(true);
        ui->FormProfileButtonSetProfile->setVisible(true);
        ui->FormProfileButtonStatistics->setVisible(true);
        if(Account.value("communityvisibilitystate").toInt()!=3){
            //профиль скрыт
        }
        } else {
                QMessageBox::warning(this,SLLanguage[6],SLLanguage[21]);
        }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}
void MainWindow::on_FormProfileButtonGames_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        gamesform = new FormGames(id,key,language,Theme,DocOwnedGames,SaveImages);
        connect(gamesform,SIGNAL(return_to_profile(FormGames*)),this,SLOT(on_return(FormGames*)));
        gamesform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_FormProfileButtonFriends_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        friendsform = new FormFriends(id,key,language,Theme,DocFriendList,SaveImages);
        connect(friendsform,SIGNAL(return_to_profile(FormFriends*)),this,SLOT(on_return(FormFriends*)));
        connect(friendsform,SIGNAL(go_to_profile(QString)),this,SLOT(on_go_to_profile(QString)));
        friendsform->show();
        this->setVisible(false);
    }
}
void MainWindow::on_FormProfileButtonSetProfile_clicked(){
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
        ui->FormProfileButtonSetProfile->setEnabled(false);
    }
}
void MainWindow::on_FormProfileButtonGoToMyProfile_clicked(){
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
                    ui->FormProfileLineEditIdProfile->setText(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length()));
                    ui->FormProfileButtonFindProfile->click();
                    }
                }
            }
            settings.close();
        } else
            QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
}
void MainWindow::on_FormProfileButtonExit_clicked(){
    close();
}

void MainWindow::on_FormProfileButtonStatistics_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        statisticform = new FormStatistic(/*id,key,language,Theme,DocOwnedGames,SaveImages*/);
        connect(statisticform,SIGNAL(return_to_profile(FormGames*)),this,SLOT(on_return(FormGames*)));
        statisticform->show();
        this->setVisible(false);
    }
}
