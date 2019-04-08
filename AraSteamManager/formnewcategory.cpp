#include "formnewcategory.h"
#include "ui_formnewcategory.h"

FormNewCategory::FormNewCategory(QString ids, QString keys, int languages, QString appids, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormNewCategory){
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    appid=appids;
    QEventLoop loop;
    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyGlobalAchievementPercentagesForApp = *manager.get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+appid));
    loop.exec();
    JsonDocGlobalAchievementPercentagesForApp = QJsonDocument::fromJson(replyGlobalAchievementPercentagesForApp.readAll());
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id));
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
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Title"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("Name"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("In the world"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Received"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(6,new QTableWidgetItem("Time received"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(7,new QTableWidgetItem("Hidden"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(8,new QTableWidgetItem("Icon url"));
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=english"));
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
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Название"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Описание"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("Имя"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("Получено по миру"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Получено"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(6,new QTableWidgetItem("Время получения"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(7,new QTableWidgetItem("Скрыто"));
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(8,new QTableWidgetItem("URL иконки"));
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=russian"));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
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
    QNetworkReply &gamereply = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id));
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
            ui->FormAddCategoryTableWidgetAchievements->setRowHeight(row,64);
            }
        }
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAddCategoryTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAddCategoryTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(3,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(4,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(5,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(6,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(7,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(8,true);
    ui->FormAddCategoryTableWidgetAchievements->setColumnHidden(9,true);
}

FormNewCategory::~FormNewCategory(){
    delete ui;
}

void FormNewCategory::closeEvent(QCloseEvent *){
    on_FormAddCategoryButtonCancel_clicked();
}

void FormNewCategory::on_FormAddCategoryButtonAddParameterValue_clicked(){
    //QVector <QPair<QString, QVector<QPair <int,QCheckBox*>>>> variants;
    bool accept=true;
    if(ui->FormAddCategoryTableWidgetAchievements->columnCount()>9)
        for (int i=9;i<ui->FormAddCategoryTableWidgetAchievements->columnCount();i++){
            if(ui->FormAddCategoryTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAddCategoryLineEditNameValue->text()){
               accept=false;
            }
        }
    if((ui->FormAddCategoryLineEditNameValue->text()!="")&&(accept)){
        QVector<QCheckBox*> valuebool(ui->FormAddCategoryTableWidgetAchievements->rowCount());
        QPair<QString, QVector<QCheckBox*>> value;
        value.first=ui->FormAddCategoryLineEditNameValue->text();
        value.second=valuebool;
        variants.append(value);
        ui->FormAddCategoryTableWidgetAchievements->setColumnCount(ui->FormAddCategoryTableWidgetAchievements->columnCount()+1);
        ui->FormAddCategoryTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAddCategoryTableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->FormAddCategoryLineEditNameValue->text()));
        for (int i=0;i<ui->FormAddCategoryTableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->FormAddCategoryTableWidgetAchievements->setItem(i,ui->FormAddCategoryTableWidgetAchievements->columnCount()-1, pItem);
//            QCheckBox *chb = new QCheckBox("Add");
//            chb->setObjectName(ui->FormAddCategoryLineEditNameValue->text()+"_number_"+QString::number(i));
//            ui->FormAddCategoryTableWidgetAchievements->setCellWidget(i,ui->FormAddCategoryTableWidgetAchievements->columnCount()-1,chb);
            //connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbCook3Change(int)));
//            value.second[i]=chb;
        }
    } else
        switch(language){
        case 1:{
            QMessageBox::warning(this,"Warning","Title of value is empty or such value already exists!");
            break;
            }
        case 5:
            QMessageBox::warning(this,"Ошибка","Название значения пустое или такое значение уже существует!");
        }
}

void FormNewCategory::on_FormAddCategoryButtonCancel_clicked(){
    emit return_to_achievements();
    delete this;
}

void FormNewCategory::on_FormAddCategoryButtonAddCategory_clicked(){
    if(!QDir("Files/Categories/"+appid).exists()){
        QDir().mkdir("Files/Categories/"+appid);
    }
    if(ui->FormAddCategoryLineEditNameCategory->text()!=""){
        QFile Category("Files/Categories/"+appid+"/"+ui->FormAddCategoryLineEditNameCategory->text()+".json");
        if(!QFile::exists("Files/Categories/"+appid+"/"+ui->FormAddCategoryLineEditNameCategory->text()+".json")){
            if(Category.open(QIODevice::WriteOnly)){
                QJsonDocument category;
                QJsonArray groups;
                QJsonObject group;
                group["name"]=ui->FormAddCategoryLineEditNameCategory->text();
//                group["language"]=language;
                QJsonArray values;
                QJsonObject val;
//                values.append("none");
                for (int i=9;i<ui->FormAddCategoryTableWidgetAchievements->columnCount();i++){
                    values.append(ui->FormAddCategoryTableWidgetAchievements->horizontalHeaderItem(i)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->FormAddCategoryTableWidgetAchievements->rowCount();j++) {
                        if(ui->FormAddCategoryTableWidgetAchievements->item(j,i)->checkState()){
//                            QJsonObject valna;
//                            valna["name"]=ui->FormAddCategoryTableWidgetAchievements->item(j,3)->text();
//                            valna["index"]=j;
//                            valna["percent"]=ui->FormAddCategoryTableWidgetAchievements->item(j,4)->text();
//                            valna["achieved"]=ui->FormAddCategoryTableWidgetAchievements->item(j,5)->text();
//                            valna["date"]=ui->FormAddCategoryTableWidgetAchievements->item(j,6)->text();
//                            valna["displayName"]=ui->FormAddCategoryTableWidgetAchievements->item(j,1)->text();
//                            valna["hidden"]=ui->FormAddCategoryTableWidgetAchievements->item(j,7)->text();
//                            valna["description"]=ui->FormAddCategoryTableWidgetAchievements->item(j,2)->text();
//                            valna["icon"]=ui->FormAddCategoryTableWidgetAchievements->item(j,8)->text();
                            valn.append(ui->FormAddCategoryTableWidgetAchievements->item(j,3)->text());
                        }
                    group[ui->FormAddCategoryTableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                    }
                }
                group["values"]=values;
                category.setObject(group);
                Category.write(category.toJson());
                Category.close();
            }
        } else
            switch(language){
            case 1:{
                QMessageBox::warning(this,"Warning","Category with this name already exist!");
                break;
                }
            case 5:
                QMessageBox::warning(this,"Ошибка","Такая категория уже есть!");
            }
    } else
        switch(language){
        case 1:{
            QMessageBox::warning(this,"Warning","Category name is empty!");
            break;
            }
        case 5:
            QMessageBox::warning(this,"Ошибка","Название категории пустое!");
        }
}
