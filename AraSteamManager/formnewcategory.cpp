#include "formnewcategory.h"
#include "ui_formnewcategory.h"

FormNewCategory::FormNewCategory(QString ids, QString keys, int languages, QString appids, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNewCategory)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    appid=appids;
    QEventLoop loop;
    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
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
    ui->FormAddCategoryTableWidgetAchievements->setColumnCount(9);
    switch (language) {
    case 1:{
        ui->FormAddCategoryButtonCancel->setText("Cancel");
        ui->FormAddCategoryButtonAddCategory->setText("Add category");
        ui->FormAddCategoryLabelNameCategory->setText("Name of category");
        ui->FormAddCategoryLineEditNameCategory->setPlaceholderText("None");
        ui->FormAddCategoryLabelParameterValue->setText("Name of value");
        ui->FormAddCategoryButtonAddParameterValue->setText("Add value");
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=english")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        break;
    }
    case 5:{
        ui->FormAddCategoryButtonCancel->setText("Отмена");
        ui->FormAddCategoryButtonAddCategory->setText("Добавить категорию");
        ui->FormAddCategoryLabelNameCategory->setText("Название категории");
        ui->FormAddCategoryLineEditNameCategory->setPlaceholderText("Не выбрано");
        ui->FormAddCategoryLabelParameterValue->setText("Название значения");
        ui->FormAddCategoryButtonAddParameterValue->setText("Добавить значение");
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=russian")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        qDebug() << "rus";
        //{"name":"hot_wheels",
        //"defaultvalue":0,
        //"displayName":"В полымя",
        //"hidden":0,
        //"description":"Выполняя первый день контракта \"Сторожевые псы\", не дайте полицейским убить водителя пикапа.",
        //"icon":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/f6ed9cd6ec9750bcd36193c74e6f16104f6c1267.jpg",
        //"icongray":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/c336adacd88a21a6010c9b5596192322aecaf265.jpg"}
    }
    }
    ui->FormAddCategoryLabelGame->setText(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("gameName").toString());
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
            int row = ui->FormAddCategoryTableWidgetAchievements->rowCount();
            ui->FormAddCategoryTableWidgetAchievements->insertRow(row);
            ui->FormAddCategoryTableWidgetAchievements->setCellWidget(row,0,label);
            QTableWidgetItem *item1 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("displayName").toString());
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,1,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("description").toString());
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,2,item2);
            QTableWidgetItem *item3 = new QTableWidgetItem(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("name").toString());
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,3,item3);
            QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent").toDouble()));
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,4,item4);
            QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("achieved").toInt()));
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,5,item5);
            QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("unlocktime").toInt()));
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,6,item6);
            QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("hidden").toInt()));
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,7,item7);
            QTableWidgetItem *item8 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString());
            ui->FormAddCategoryTableWidgetAchievements->setItem(row,8,item8);
            }
        }
    ui->FormAddCategoryTableWidgetAchievements->setRowHeight(ui->FormAddCategoryTableWidgetAchievements->rowCount(),64);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAddCategoryTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(4,70);
    ui->FormAddCategoryTableWidgetAchievements->resizeColumnToContents(5);
}

FormNewCategory::~FormNewCategory()
{
    delete ui;
}

void FormNewCategory::on_FormAddCategoryButtonAddParameterValue_clicked(){
    //QVector <QPair<QString, QVector<QPair <int,QCheckBox*>>>> variants;
    if(ui->FormAddCategoryLineEditNameValue->text()!=""){
        QVector<QCheckBox*> valuebool(ui->FormAddCategoryTableWidgetAchievements->rowCount());
        QPair<QString, QVector<QCheckBox*>> value;
        value.first=ui->FormAddCategoryLineEditNameValue->text();
        value.second=valuebool;
        variants.append(value);
        //добавить справа значение
        ui->FormAddCategoryTableWidgetAchievements->setColumnCount(ui->FormAddCategoryTableWidgetAchievements->columnCount()+1);
        //название нового столбца
        for (int i=0;i<ui->FormAddCategoryTableWidgetAchievements->rowCount();i++){
            QCheckBox *chb = new QCheckBox;
            chb->setObjectName(ui->FormAddCategoryLineEditNameValue->text()+"_number_"+QString::number(i));
            chb->setText("Add");
            ui->FormAddCategoryTableWidgetAchievements->setCellWidget(i,ui->FormAddCategoryTableWidgetAchievements->columnCount()-1,chb);
            //connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbCook3Change(int)));
            value.second[i]=chb;
        }
    } else
        switch(language){
        case 1:{
            QMessageBox::warning(this,"Warning","Title of value is empty!");
            break;
            }
        case 5:
            QMessageBox::warning(this,"Ошибка","Название значения пустое!");
        }
}
