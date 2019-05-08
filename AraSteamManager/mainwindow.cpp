#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->FormProfileAvatar->setText("");
    ui->FormProfileLabelLogo->setText("");
    ui->FormProfileLabelPersonaName->setText("");
    ui->FormProfileLabelTimeCreated->setText("");
    ui->FormProfileLabelPersonaState->setText("");
    ui->FormProfileLabelLocCountryCode->setText("");
    ui->FormProfileLabelProfileUrl->setText("");
    ui->FormProfileLabelRealName->setText("");
    ui->FormProfileButtonGames->setVisible(false);
    ui->FormProfileButtonFriends->setVisible(false);
    ui->FormProfileButtonFavorites->setVisible(false);
    ui->FormProfileButtonSetProfile->setVisible(false);
    ui->FormProfileButtonStatistics->setVisible(false);
    QFile FileLanguage;
    if(QFile::exists("Files/Settings.txt")){
        QFile settings("Files/Settings.txt");
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
    ui->FormProfileButtonFindProfile->setText(SLLanguage[0]);
    ui->FormProfileLineEditIdProfile->setPlaceholderText(SLLanguage[1]);
    ui->FormProfileButtonFavorites->setText(SLLanguage[2]);
    ui->FormProfileButtonSetProfile->setText(SLLanguage[3]);
    ui->FormProfileButtonStatistics->setText(SLLanguage[4]);
    ui->FormProfileButtonSettings->setText(SLLanguage[5]);
    switch(Theme){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        qApp->setPalette(darkPalette);
        break;
        }
    case 2:{
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
        break;
        }
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_FormProfileButtonFindProfile_clicked(){
    QString ids;
    if(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)>-1){
        if(ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).indexOf("/",1)>1){
            ids=ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).indexOf("/",1));
        } else
            ids=ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).remove('\r');
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
        QNetworkReply &ReplyOwnedGames = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id));
        loop.exec();
        DocOwnedGames = QJsonDocument::fromJson(ReplyOwnedGames.readAll());
        QNetworkReply &ReplyFriendList = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        loop.exec();
        DocFriendList = QJsonDocument::fromJson(ReplyFriendList.readAll());
        QJsonObject Account=DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject();
        ui->FormProfileLabelPersonaName->setText(Account.value("personaname").toString());
        ui->FormProfileLabelProfileUrl->setText(Account.value("profileurl").toString());
        QDateTime date=QDateTime::fromSecsSinceEpoch(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("timecreated").toInt(),Qt::LocalTime);
        ui->FormProfileLabelRealName->setText(SLLanguage[8]+": "+Account.value("realname").toString());
        ui->FormProfileLabelTimeCreated->setText(SLLanguage[9]+" "+date.toString("yyyy.MM.dd"));
        ui->FormProfileButtonGames->setText(SLLanguage[10]+"("+QString::number(DocOwnedGames.object().value("response").toObject().value("game_count").toInt())+")");
        ui->FormProfileButtonFriends->setText(SLLanguage[11]+"("+QString::number(DocFriendList.object().value("friendslist").toObject().value("friends").toArray().size())+")");
        if(!DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("gameextrainfo").toString().isEmpty()){
            ui->FormProfileLabelPersonaState->setText(SLLanguage[12]+":\n"+DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("gameextrainfo").toString());
        } else
            switch (Account.value("personastate").toInt()) {
            case 0:{
                QDateTime date=QDateTime::fromSecsSinceEpoch(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("lastlogoff").toInt(),Qt::LocalTime);
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[13]+":\n"+date.toString("yyyy.MM.dd\nhh:mm:ss"));
                    break;
            }
            case 1:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[14]);
                    break;
            }
            case 2:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[15]);
                    break;
            }
            case 3:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[16]);
                    break;
            }
            case 4:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[17]);
                    break;
            }
            case 5:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[18]);
                    break;
            }
            case 6:{
                    ui->FormProfileLabelPersonaState->setText(SLLanguage[19]);
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
                        if(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length())==ui->FormProfileLineEditIdProfile->text()){
                            ui->FormProfileButtonSetProfile->setEnabled(false);
                        } else {
                            ui->FormProfileButtonSetProfile->setEnabled(true);
                        }
                    }
                }
                settings.close();
            } else
                QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
            }
        QPixmap pixmap;
        switch (SaveImages) {
        case 0:{
            QNetworkAccessManager imagemanager;
            QEventLoop imageloop;  //Ждем ответ от сервера.
            QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
            QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Account.value("avatar").toString()));
            imageloop.exec();
            pixmap.loadFromData(imagereply.readAll());
            break;
        }
        case 1:{
            if(!QFile::exists("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png")){
                QNetworkAccessManager imagemanager;
                QEventLoop imageloop;  //Ждем ответ от сервера.
                QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Account.value("avatar").toString()));
                imageloop.exec();
                QImage img;
                img.loadFromData(imagereply.readAll());
                img.save("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png", "PNG");
                pixmap=QPixmap::fromImage(img);
            } else {
                pixmap.load("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png", "PNG");
                }
        }
        }
        ui->FormProfileAvatar->setPixmap(pixmap);
        ui->FormProfileButtonGames->setVisible(true);
        ui->FormProfileButtonFriends->setVisible(true);
        ui->FormProfileButtonFavorites->setVisible(true);
        ui->FormProfileButtonSetProfile->setVisible(true);
        ui->FormProfileButtonStatistics->setVisible(true);
        if(Account.value("communityvisibilitystate").toInt()==3){
            //профиль скрыт
        }
        } else {
                QMessageBox::warning(this,SLLanguage[6],SLLanguage[21]);
        }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
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

void MainWindow::on_FormProfileButtonGames_clicked(){
    gamesform = new FormGames(id,key,language,DocOwnedGames,SaveImages);
    connect(gamesform,SIGNAL(return_to_profile()),this,SLOT(on_return()));
    gamesform->show();
    this->setVisible(false);
}

void MainWindow::on_return(){
    this->setVisible(true);
}

void MainWindow::closeEvent(QCloseEvent *){
    //delete this;
}

void MainWindow::on_FormProfileButtonFriends_clicked(){
    friendsform = new FormFriends(id,key,language,DocFriendList,SaveImages);
    connect(friendsform,SIGNAL(return_to_profile()),this,SLOT(on_return()));
    friendsform->show();
    this->setVisible(false);
}
