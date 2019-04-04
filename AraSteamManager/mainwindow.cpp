#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    ui->FormProfileButtonBadges->setVisible(false);
    ui->FormProfileButtonFriends->setVisible(false);
    ui->FormProfileButtonFavorites->setVisible(false);
    ui->FormProfileButtonSetProfile->setVisible(false);
    ui->FormProfileButtonStatistics->setVisible(false);
    switch(language){
    case 1:{
        ui->FormProfileButtonFindProfile->setText("Find");
        ui->FormProfileLineEditIdProfile->setPlaceholderText("Insert SteamId");
        ui->FormProfileButtonBadges->setText("Badges");
        ui->FormProfileButtonFavorites->setText("Favorites");
        ui->FormProfileButtonSetProfile->setText("Set as my profile");
        ui->FormProfileButtonStatistics->setText("Statistics");
        ui->FormProfileButtonSettings->setText("Settings");
        break;
    }
    case 5:{
        ui->FormProfileButtonFindProfile->setText("Найти");
        ui->FormProfileLineEditIdProfile->setPlaceholderText("Введите SteamId");
        ui->FormProfileButtonBadges->setText("Значки");
        ui->FormProfileButtonFavorites->setText("Избранное");
        ui->FormProfileButtonSetProfile->setText("Установить как мой профиль");
        ui->FormProfileButtonStatistics->setText("Статистика");
        ui->FormProfileButtonSettings->setText("Настройки");
    }
    }
    QFile file("Files/Settings.txt");
    if(QFile::exists("Files/Settings.txt"))
    {
        if (!file.open(QIODevice::ReadOnly))
        {
            switch (language) {
            case 1:{
                QMessageBox::warning(this,"Error","Error opening file!");
                break;
            }
            case 5:{
                QMessageBox::warning(this,"Ошибка","Ошибка при открытии файла!");
                break;
            }
            }
        } else {
            QString FileText=QString::fromLocal8Bit(file.readAll());
            while (FileText.length()) {
                QString FileLine=FileText.mid(0,FileText.indexOf("\r\n",0));
                if(FileText.indexOf("\r\n",0)!=-1)
                    FileText=FileText.mid(FileText.indexOf("\r\n",0)+2,FileText.length()-FileText.indexOf("\r\n",0));
                else
                    FileText="";
                if(FileLine.indexOf("MyProfile=",0)!=-1){
                    if(FileLine.indexOf("MyProfile=none",0)==-1){
                        ui->FormProfileLineEditIdProfile->setText(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length()));
                        ui->FormProfileButtonFindProfile->click();
                    }
                }
            }
        }
    }
    file.close();
    //темная тема
    // Создаём палитру для тёмной темы оформления
    QPalette darkPalette;
    // Настраиваем палитру для цветовых ролей элементов интерфейса
    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),QColor(42, 130, 218),Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
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
    qApp->setPalette(darkPalette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FormProfileButtonFindProfile_clicked()
{
    if(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)>-1){
        if(ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).indexOf("/",1)>1){
            id=ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).indexOf("/",1));
        } else
            id=ui->FormProfileLineEditIdProfile->text().mid(ui->FormProfileLineEditIdProfile->text().indexOf("profiles/",0)+9,20).remove('\r');
    } else
        id=ui->FormProfileLineEditIdProfile->text().remove('\r');
    QNetworkAccessManager manager;
    QNetworkReply &reply = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id)));
    QEventLoop loop;  //Ждем ответ от сервера.
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray Data = reply.readAll();
    QJsonDocument document = QJsonDocument::fromJson(Data);
    qDebug() << document;
    QNetworkReply &gamesreply = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id)));
    loop.exec();
    QByteArray Datagames = gamesreply.readAll();
    //{"appid":218620,
    //"name":"PAYDAY 2",
    //"playtime_2weeks":329,
    //"playtime_forever":45501,
    //"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
    //"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
    //"has_community_visible_stats":true}
    QJsonDocument documentgames = QJsonDocument::fromJson(Datagames);
    QNetworkReply &friendsreply = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend")));
    loop.exec();
    QByteArray Datafriends = friendsreply.readAll();
    //{"steamid":"76561197972251526",
    //"relationship":"friend",
    //"friend_since":1490256413}
    QJsonDocument documentfriends = QJsonDocument::fromJson(Datafriends);
    ui->FormProfileLabelPersonaName->setText(document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personaname").toString());
    ui->FormProfileLabelProfileUrl->setText(document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("profileurl").toString());
    QDateTime date;
    date.setDate(QDate::fromString("1970-01-01","yyyy-MM-dd"));
    date=date.addSecs(document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("timecreated").toInt());
    switch (language) {
    case 1:{
        ui->FormProfileLabelRealName->setText("Real name: "+document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("realname").toString());
        ui->FormProfileLabelTimeCreated->setText("Account created "+date.toString("yyyy.MM.dd"));
        ui->FormProfileButtonGames->setText("Games("+QString::number(documentgames.object().value("response").toObject().value("game_count").toInt())+")");
        ui->FormProfileButtonFriends->setText("Friends("+QString::number(documentfriends.object().value("friendslist").toObject().value("friends").toArray().size())+")");
        switch (document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personastate").toInt()) {
        case 0:{
                ui->FormProfileLabelPersonaState->setText("Offline");
                break;
        }
        case 1:{
                ui->FormProfileLabelPersonaState->setText("Online");
                break;
        }
        case 2:{
                ui->FormProfileLabelPersonaState->setText("Busy");
                break;
        }
        case 3:{
                ui->FormProfileLabelPersonaState->setText("Away");
                break;
        }
        case 4:{
                ui->FormProfileLabelPersonaState->setText("Snooze");
                break;
        }
        case 5:{
                ui->FormProfileLabelPersonaState->setText("Looking to trade");
                break;
        }
        case 6:{
                ui->FormProfileLabelPersonaState->setText("Looking to play");
                break;
        }
        }
        ui->FormProfileLabelLocCountryCode->setText("Language: "+document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("loccountrycode").toString());
        break;
    }
    case 5:{
        ui->FormProfileLabelRealName->setText("Настоящее имя: "+document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("realname").toString());
        ui->FormProfileLabelTimeCreated->setText("Аккаунт создан "+date.toString("yyyy.MM.dd"));
        ui->FormProfileButtonGames->setText("Игры("+QString::number(documentgames.object().value("response").toObject().value("game_count").toInt())+")");
        ui->FormProfileButtonFriends->setText("Друзья("+QString::number(documentfriends.object().value("friendslist").toObject().value("friends").toArray().size())+")");
        switch (document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personastate").toInt()) {
        case 0:{
                ui->FormProfileLabelPersonaState->setText("Не в сети");
                break;
        }
        case 1:{
                ui->FormProfileLabelPersonaState->setText("В сети");
                break;
        }
        case 2:{
                ui->FormProfileLabelPersonaState->setText("Не беспокоить");
                break;
        }
        case 3:{
                ui->FormProfileLabelPersonaState->setText("Нет на месте");
                break;
        }
        case 4:{
                ui->FormProfileLabelPersonaState->setText("Спит");
                break;
        }
        case 5:{
                ui->FormProfileLabelPersonaState->setText("Ожидает обмена");
                break;
        }
        case 6:{
                ui->FormProfileLabelPersonaState->setText("Хочет поиграть");
                break;
        }
        }
        ui->FormProfileLabelLocCountryCode->setText("Язык: "+document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("loccountrycode").toString());
        break;
    }
    }

    QNetworkAccessManager imagemanager;
    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(QString(document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("avatar").toString())));
    QEventLoop imageloop;  //Ждем ответ от сервера.
    QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
    imageloop.exec();

    QByteArray ba=imagereply.readAll();
    QImage img;
        img.loadFromData(ba);
        img.save("images/profiles/"+id+".png", "PNG");

    QPixmap pixmap;
    pixmap.load("images/profiles/"+id+".png", "PNG");
    //pixmap=QPixmap::fromImage(img);

    ui->FormProfileAvatar->setPixmap(pixmap);
    ui->FormProfileButtonGames->setVisible(true);
    ui->FormProfileButtonBadges->setVisible(true);
    ui->FormProfileButtonFriends->setVisible(true);
    ui->FormProfileButtonFavorites->setVisible(true);
    ui->FormProfileButtonSetProfile->setVisible(true);
    ui->FormProfileButtonStatistics->setVisible(true);
    if(document.object().value("response").toObject().value("players").toArray().at(0).toObject().value("communityvisibilitystate").toInt()==3){
        //профиль скрыт
    }
    if(QFile::exists("Files/Settings.txt"))
    {
        QFile file("Files/Settings.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            switch (language) {
            case 1:{
                QMessageBox::warning(this,"Error","Error opening file!");
                break;
            }
            case 5:{
                QMessageBox::warning(this,"Ошибка","Ошибка при открытии файла!");
                break;
            }
            }
        } else {
            QString FileText=QString::fromLocal8Bit(file.readAll());
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
            file.close();
        }
    }
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}

void MainWindow::on_FormProfileButtonSetProfile_clicked()
{
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    file.open(QIODevice::ReadOnly);
            //деволтные данные
    file.close();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        switch (language) {
        case 1:{
            QMessageBox::warning(this,"Error","Error opening file!");
            break;
        }
        case 5:{
            QMessageBox::warning(this,"Ошибка","Ошибка при открытии файла!");
            break;
        }
        }
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

void MainWindow::on_FormProfileButtonGames_clicked()
{
    gamesform = new FormGames(id,key,language);
    connect(gamesform,SIGNAL(return_to_profile()),this,SLOT(on_return()));
    gamesform->show();
    this->setEnabled(false);
}

void MainWindow::on_return(){
    this->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *){
    //delete this;
}
