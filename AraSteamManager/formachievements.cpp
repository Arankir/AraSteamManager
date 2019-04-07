#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, int languages, QString ids, QString appids, QString GameLogo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAchievements)
{
    ui->setupUi(this);
    key=keys;
    language=languages;
    id=ids;
    appid=appids;
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+appid)));
    loop.exec();
    JsonDocNumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
    //{"player_count":9023,
    //"result":1}
    QNetworkReply &replyGlobalAchievementPercentagesForApp = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+appid)));
    loop.exec();
    JsonDocGlobalAchievementPercentagesForApp = QJsonDocument::fromJson(replyGlobalAchievementPercentagesForApp.readAll());
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id)));
    loop.exec();
    JsonDocPlayerAchievements = QJsonDocument::fromJson(replyPlayerAchievements.readAll());
    //{"apiname":"hot_wheels",
    //"achieved":1,
    //"unlocktime":1445190378}
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(6);
    QString Reached="";
    QString NotReached="";
    QString TotalPercent="";
    switch (language) {
    case 1:{
        ui->FormAchievementsButtonReturn->setText("Return");
        ui->FormAchievementsButtonCompare->setText("Compare with friends");
        ui->FormAchievementsLabelGameLogo->setText("");
        ui->FormAchievementsRadioButtonAll->setText("All achievements");
        ui->FormAchievementsRadioButtonReached->setText("Reached achievements");
        ui->FormAchievementsRadioButtonNotReached->setText("Not reached achievements");
        ui->FormAchievementsButtonAddCategory->setText("Add category");
        ui->FormAchievementsButtonChangeCategory->setText("Change categories");
        ui->FormAchievementsCheckBoxFavorites->setText("Only Favorites");
        ui->FormAchievementsButtonFindAchievement->setText("Find");
        ui->FormAchievementsGroupBoxFilter->setTitle("Filter");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Achievement name");
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Title"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("In the world"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("Received"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Favorites"));
        Reached="Reached";
        NotReached="Not reached";
        TotalPercent="Total percent";
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=english")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        ui->FormAchievementsLabelGameOnline->setText("Now in game: "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
        break;
    }
    case 5:{
        ui->FormAchievementsButtonReturn->setText("Вернуться");
        ui->FormAchievementsButtonCompare->setText("Сравнить с друзьями");
        ui->FormAchievementsLabelGameLogo->setText("");
        ui->FormAchievementsRadioButtonAll->setText("Все достижения");
        ui->FormAchievementsRadioButtonReached->setText("Полученные достижения");
        ui->FormAchievementsRadioButtonNotReached->setText("Не полученные достижения");
        ui->FormAchievementsButtonAddCategory->setText("Добавить категорию");
        ui->FormAchievementsButtonChangeCategory->setText("Изменить категории");
        ui->FormAchievementsCheckBoxFavorites->setText("Только избранное");
        ui->FormAchievementsButtonFindAchievement->setText("Найти");
        ui->FormAchievementsGroupBoxFilter->setTitle("Фильтр");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Название достижения");
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Название"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Описание"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("По миру"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("Получено"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Избранное"));
        Reached="Получено";
        NotReached="Не получено";
        TotalPercent="Общий процент";
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=russian")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        ui->FormAchievementsLabelGameOnline->setText("Сейчас в сети: "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
        //{"name":"hot_wheels",
        //"defaultvalue":0,
        //"displayName":"В полымя",
        //"hidden":0,
        //"description":"Выполняя первый день контракта \"Сторожевые псы\", не дайте полицейским убить водителя пикапа.",
        //"icon":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/f6ed9cd6ec9750bcd36193c74e6f16104f6c1267.jpg",
        //"icongray":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/c336adacd88a21a6010c9b5596192322aecaf265.jpg"}
        }
    }
    QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+appid+"/"+GameLogo+".jpg"));
    loop.exec();
    QPixmap pixmap;
    pixmap.loadFromData(logoreply.readAll());
    ui->FormAchievementsLabelGameLogo->setPixmap(pixmap);
    int total=0;
    int dectotal=0;
    if(!QDir("images/achievements/"+appid).exists()){
        QDir().mkdir("images/achievements/"+appid);
    }
    for(int i=0;i<JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();i++){
        if(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent")!=0){
            int j=0;
            bool accept=false;
            for(;j<JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();j++){
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname")==JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("name")){
                    accept=true;
                    break;
                    }
            }
            if(accept){
                QPixmap pixmap;
                QString AchievementIcon=JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString().mid(66,JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString().length());
                if(!QFile::exists("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png")){
                    QNetworkAccessManager imagemanager;
                    QEventLoop imageloop;  //Ждем ответ от сервера.
                    QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString()));
                    imageloop.exec();
                    QImage img;
                    img.loadFromData(imagereply.readAll());
                    img.save("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    pixmap=QPixmap::fromImage(img);
                } else {
                    pixmap.load("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    }
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                int row = ui->FormAchievementsTableWidgetAchievements->rowCount();
                ui->FormAchievementsTableWidgetAchievements->insertRow(row);
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,0,label);
                QTableWidgetItem *item2 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("displayName").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("description").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent").toDouble())+"%");
                ui->FormAchievementsTableWidgetAchievements->setItem(row,3,item4);
                QTableWidgetItem *item5;
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("achieved").toInt()==1){
                    QDateTime date;
                    date.setDate(QDate::fromString("1970.01.01","yyyy.MM.dd"));
                    date=date.addSecs(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("unlocktime").toInt());
                    item5 = new QTableWidgetItem(Reached+" "+date.toString("yyyy.MM.dd"));
                    total++;
                } else {
                    item5 = new QTableWidgetItem(NotReached);
                }
                ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                QPushButton *button1 = new QPushButton;
                button1->setText("«");
                QFont font("Wingdings",24);
                button1->setFont(font);
                connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
                button1->setObjectName("FormGamesButtonFavorites"+appid+"&"+JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,5,button1);
            } else dectotal+=1;

        }
        }
    double percent= 1.0*total/(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()-dectotal)*100;
    ui->FormAchievementsLabelTotalPersent->setText(TotalPercent+" = "+QString::number(percent)+"%");
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(4,80);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(5);
    ui->FormAchievementsTableWidgetAchievements->resizeRowsToContents();
}

FormAchievements::~FormAchievements()
{
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent *){
    on_FormAchievementsButtonReturn_clicked();
}

void FormAchievements::on_FormAchievementsButtonReturn_clicked(){
    emit return_to_games();
    delete this;
}

void FormAchievements::FavoritesClicked(){

}

void FormAchievements::on_FormAchievementsButtonAddCategory_clicked()
{
    newcategoryform = new FormNewCategory(id,key,language,appid);
    connect(newcategoryform,SIGNAL(return_to_achievements()),this,SLOT(on_return()));
    newcategoryform->show();
    this->setEnabled(false);
}

void FormAchievements::on_return(){
    this->setEnabled(true);
}

void FormAchievements::on_FormAchievementsRadioButtonAll_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,false);
}

void FormAchievements::on_FormAchievementsRadioButtonReached_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if(ui->FormAchievementsTableWidgetAchievements->item(i,4)->text().indexOf(".")>-1)
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,false); else
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,true);
}

void FormAchievements::on_FormAchievementsRadioButtonNotReached_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if(ui->FormAchievementsTableWidgetAchievements->item(i,4)->text().indexOf(".")>-1)
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,true); else
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,false);
}
