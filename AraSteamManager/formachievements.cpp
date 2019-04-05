#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, int languages, QString ids, QString appids, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAchievements)
{
    ui->setupUi(this);
    key=keys;
    language=languages;
    id=ids;
    appid=appids;
    QEventLoop loop;
    QNetworkAccessManager manager;
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
    switch (language) {
    case 1:{
        ui->FormAchievementsButtonReturn->setText("Return");
        ui->FormAchievementsButtonCompare->setText("Compare with friends");
        ui->FormAchievementsLabelGameLogo->setText("");
        ui->FormAchievementsGroupBoxFilter->setTitle("Filter");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Achievement name");
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
        ui->FormAchievementsGroupBoxFilter->setTitle("Фильтр");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Название достижения");
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
    ui->FormAchievementsLabelGameName->setText(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("gameName").toString());
    QNetworkReply &gamereply = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id)));
    loop.exec();
    QJsonDocument JsonDocGame = QJsonDocument::fromJson(gamereply.readAll());
    //{"appid":218620,
    //"name":"PAYDAY 2",
    //"playtime_2weeks":329,
    //"playtime_forever":45501,
    //"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
    //"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
    //"has_community_visible_stats":true}
    int k=0;
    for (;k<JsonDocGame.object().value("response").toObject().value("games").toArray().size();k++) {
        if(JsonDocGame.object().value("response").toObject().value("games").toArray().at(k).toObject().value("appid").toString()==appid)
            break;
    }
    QNetworkReply &logoreply = *manager.get(QNetworkRequest(QString("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonDocGame.object().value("response").toObject().value("games").toArray().at(k).toObject().value("appid").toInt())+"/"+JsonDocGame.object().value("response").toObject().value("games").toArray().at(k).toObject().value("img_icon_url").toString())+".jpg"));
    loop.exec();
    QPixmap pixmap;
    pixmap.loadFromData(logoreply.readAll());
    ui->FormAchievementsLabelGameLogo->setPixmap(pixmap);

    int total=0;
    switch (language) {
    case 1:{
        for(int i=0;i<JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();i++){
            if(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent")!=0){
                int j=0;
                for(;j<JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();j++){
                    if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname")==JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("name"))
                        break;
                }
                QNetworkReply &imagereply = *manager.get(QNetworkRequest(QString(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString())));
                loop.exec();
                QPixmap pixmap;
                pixmap.loadFromData(imagereply.readAll());
                QLabel *label = new QLabel("");
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
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("achieved").toInt()==1){
                    QDateTime date;
                    date.setDate(QDate::fromString("1970-01-01","yyyy-MM-dd"));
                    date=date.addSecs(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("unlocktime").toInt());
                    QTableWidgetItem *item5 = new QTableWidgetItem("Reached "+date.toString("yyyy-MM-dd"));
                    total++;
                    ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                } else {
                    QTableWidgetItem *item5 = new QTableWidgetItem("Not reached");
                    ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                }
                QPushButton *button1 = new QPushButton;
                button1->setText("Favorite");
                connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
                button1->setObjectName("FormGamesButtonFavorites"+appid+"%"+JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,5,button1);
            }
            }
        double percent= 1.0*total/JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()*100;
        ui->FormAchievementsLabelTotalPersent->setText("Total percent = "+QString::number(percent)+"%");
        break;
    }
    case 5:{
        for(int i=0;i<JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();i++){
            if(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent")!=0){
                int j=0;
                for(;j<JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();j++){
                    if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname")==JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("name"))
                        break;
                }
                QNetworkReply &imagereply = *manager.get(QNetworkRequest(QString(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString())));
                loop.exec();
                QPixmap pixmap;
                pixmap.loadFromData(imagereply.readAll());
                QLabel *label = new QLabel("");
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
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("achieved").toInt()==1){
                    QDateTime date;
                    date.setDate(QDate::fromString("1970-01-01","yyyy-MM-dd"));
                    date=date.addSecs(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("unlocktime").toInt());
                    QTableWidgetItem *item5 = new QTableWidgetItem("Получено "+date.toString("yyyy-MM-dd"));
                    total++;
                    ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                } else {
                    QTableWidgetItem *item5 = new QTableWidgetItem("Не получено");
                    ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                }
                QPushButton *button1 = new QPushButton;
                button1->setText("Избранное");
                connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
                button1->setObjectName("FormGamesButtonFavorites"+appid+"%"+JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,5,button1);
            }
            }
        double percent= 1.0*total/JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()*100;
        ui->FormAchievementsLabelTotalPersent->setText("Общий процент = "+QString::number(percent)+"%");
    }
    }
    ui->FormAchievementsTableWidgetAchievements->setRowHeight(ui->FormAchievementsTableWidgetAchievements->rowCount(),64);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(4,70);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(5);
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
    connect(newcategoryform,SIGNAL(return_to_games()),this,SLOT(on_return()));
    newcategoryform->show();
    this->setEnabled(false);
}

void FormAchievements::on_return(){
    this->setEnabled(true);
}
