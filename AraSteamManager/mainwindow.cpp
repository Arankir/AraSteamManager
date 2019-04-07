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
                    if(FileLine.indexOf("MyProfile=none",0)==-1){
                        ui->FormProfileLineEditIdProfile->setText(FileLine.mid(FileLine.indexOf("MyProfile=",0)+10,FileLine.length()));
                        ui->FormProfileButtonFindProfile->click();
                        }
                    }
                if(FileLine.indexOf("Theme=",0)!=-1){
                        Theme=FileLine.mid(FileLine.indexOf("Theme=",0)+6,FileLine.length()).toInt();
                        }
                if(FileLine.indexOf("Language=",0)!=-1){
                        language=FileLine.mid(FileLine.indexOf("Language=",0)+9,FileLine.length()).toInt();
                        }
                }
            settings.close();
            }
        }
    switch(language){
    case 1:{
        ui->FormProfileButtonFindProfile->setText("Find");
        ui->FormProfileLineEditIdProfile->setPlaceholderText("Insert SteamId");
        ui->FormProfileButtonFavorites->setText("Favorites");
        ui->FormProfileButtonSetProfile->setText("Set as my profile");
        ui->FormProfileButtonStatistics->setText("Statistics");
        ui->FormProfileButtonSettings->setText("Settings");
        break;
        }
    case 5:{
        ui->FormProfileButtonFindProfile->setText("Найти");
        ui->FormProfileLineEditIdProfile->setPlaceholderText("Введите SteamId");
        ui->FormProfileButtonFavorites->setText("Избранное");
        ui->FormProfileButtonSetProfile->setText("Установить как мой профиль");
        ui->FormProfileButtonStatistics->setText("Статистика");
        ui->FormProfileButtonSettings->setText("Настройки");
        }
    }
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
    if(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        id=ids;
        QNetworkReply &ReplyOwnedGames = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&format=json&steamid="+id));
        loop.exec();
        DocOwnedGames = QJsonDocument::fromJson(ReplyOwnedGames.readAll());
        QNetworkReply &ReplyFriendList = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        loop.exec();
        DocFriendList = QJsonDocument::fromJson(ReplyFriendList.readAll());
        QJsonObject Account=DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject();
        ui->FormProfileLabelPersonaName->setText(Account.value("personaname").toString());
        ui->FormProfileLabelProfileUrl->setText(Account.value("profileurl").toString());
        QDateTime date;
        date.setDate(QDate::fromString("1970.01.01","yyyy.MM.dd"));
        date=date.addSecs(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("timecreated").toInt());
        QString Error="";
        QString ErrorDescription="";
        switch (language) {
        case 1:{
            Error="Error";
            ErrorDescription="Error opening file!";
            on_FindAccount_language("Real name",Account.value("realname").toString(),"Account created",date,"Games",DocOwnedGames.object().value("response").toObject().value("game_count").toInt(),"Friends",DocFriendList.object().value("friendslist").toObject().value("friends").toArray().size(),Account.value("personastate").toInt(),"Offline","Online","Busy","Away","Snooze","Looking to trade","Looking to play","Language",Account.value("loccountrycode").toString());
            break;
            }
        case 5:{
            Error="Ошибка";
            ErrorDescription="Ошибка при открытии файла!";
            on_FindAccount_language("Настоящее имя",Account.value("realname").toString(),"Аккаунт создан",date,"Игры",DocOwnedGames.object().value("response").toObject().value("game_count").toInt(),"Друзья",DocFriendList.object().value("friendslist").toObject().value("friends").toArray().size(),Account.value("personastate").toInt(),"Не в сети","В сети","Не беспокоить","Нет на месте","Спит","Ожидает обмена","Хочет поиграть","Язык",Account.value("loccountrycode").toString());
            break;
            }
        }
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
                QMessageBox::warning(this,Error,ErrorDescription);
            }
        QPixmap pixmap;
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
            switch (language) {
            case 1:{
                QMessageBox::warning(this,"Error","Profile not exist!");
                break;
                }
            case 5:{
                QMessageBox::warning(this,"Ошибка","Профиль не существует!");
                break;
                }
                QMessageBox::warning(this,"Error","Profile not exist!");
            }
        }
    //    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
}

void MainWindow::on_FindAccount_language(QString LabelRealName, QString RealName, QString LabelTimeCreated, QDateTime TimeCreated, QString ButtonGames, int Games, QString ButtonFriends, int Friends, int personastate, QString PS0, QString PS1, QString PS2, QString PS3, QString PS4, QString PS5, QString PS6, QString LabelLocCountryCode, QString LocCountryCode){
    ui->FormProfileLabelRealName->setText(LabelRealName+": "+RealName);
    ui->FormProfileLabelTimeCreated->setText(LabelTimeCreated+" "+TimeCreated.toString("yyyy.MM.dd"));
    ui->FormProfileButtonGames->setText(ButtonGames+"("+QString::number(Games)+")");
    ui->FormProfileButtonFriends->setText(ButtonFriends+"("+QString::number(Friends)+")");
    switch (personastate) {
    case 0:{
            ui->FormProfileLabelPersonaState->setText(PS0);
            break;
    }
    case 1:{
            ui->FormProfileLabelPersonaState->setText(PS1);
            break;
    }
    case 2:{
            ui->FormProfileLabelPersonaState->setText(PS2);
            break;
    }
    case 3:{
            ui->FormProfileLabelPersonaState->setText(PS3);
            break;
    }
    case 4:{
            ui->FormProfileLabelPersonaState->setText(PS4);
            break;
    }
    case 5:{
            ui->FormProfileLabelPersonaState->setText(PS5);
            break;
    }
    case 6:{
            ui->FormProfileLabelPersonaState->setText(PS6);
            break;
    }
    }
    ui->FormProfileLabelLocCountryCode->setText(LabelLocCountryCode+": "+LocCountryCode);
}

void MainWindow::on_FormProfileButtonSetProfile_clicked(){
    QFile file("Files/Settings.txt");
    if(!QFile::exists("Files/Settings.txt"))
    {
    file.open(QIODevice::WriteOnly);
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

void MainWindow::on_FormProfileButtonGames_clicked(){
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
