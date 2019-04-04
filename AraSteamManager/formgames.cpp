#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, int languages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGames)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;

    QNetworkAccessManager manager;
    QNetworkReply &gamesreply = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+id)));
    QEventLoop loop;  //Ждем ответ от сервера.
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    JsonDocGames = QJsonDocument::fromJson(gamesreply.readAll());
    //{"appid":218620,
    //"name":"PAYDAY 2",
    //"playtime_2weeks":329,
    //"playtime_forever":45501,
    //"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
    //"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
    //"has_community_visible_stats":true}
    QJsonArray JsonArayGames=JsonDocGames.object().value("response").toObject().value("games").toArray();
    ui->FormGamesTableWidgetGames->setColumnCount(4);
    switch(language){
    case 1:{
        ui->FormGamesLabelLogo->setText("");
        ui->FormGamesLineEditGame->setPlaceholderText("Find game");
        ui->FormGamesButtonFind->setText("Find");
        ui->FormGamesButtonReturn->setText("Return");
        for(int i=0;i<JsonArayGames.size();i++){
            QNetworkAccessManager imagemanager;
            QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(QString("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"/"+JsonArayGames[i].toObject().value("img_icon_url").toString())+".jpg"));
            QEventLoop imageloop;  //Ждем ответ от сервера.
            QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
            imageloop.exec();
            QPixmap pixmap;
            pixmap.loadFromData(imagereply.readAll());
            QIcon icon = QIcon(pixmap);
            int row = ui->FormGamesTableWidgetGames->rowCount();
            ui->FormGamesTableWidgetGames->insertRow(row);
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setIcon(icon);
            ui->FormGamesTableWidgetGames->setItem(row,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(JsonArayGames[i].toObject().value("name").toString());
            ui->FormGamesTableWidgetGames->setItem(row,1,item2);
            QPushButton *button1 = new QPushButton;
            QPushButton *button2 = new QPushButton;
            button1->setText("Achievements");
            button2->setText("Favorite");
            connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
            connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
            button1->setObjectName("FormGamesButtonAchievements"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
            ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
            button2->setObjectName("FormGamesButtonFavorites"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
            ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
            }
        break;
    }
    case 5:{
        ui->FormGamesLabelLogo->setText("");
        ui->FormGamesLineEditGame->setPlaceholderText("Найти игру");
        ui->FormGamesButtonFind->setText("Найти");
        ui->FormGamesButtonReturn->setText("Вернуться");
        for(int i=0;i<JsonArayGames.size();i++){
            QNetworkAccessManager imagemanager;
            QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(QString("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"/"+JsonArayGames[i].toObject().value("img_icon_url").toString())+".jpg"));
            QEventLoop imageloop;  //Ждем ответ от сервера.
            QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
            imageloop.exec();
            QPixmap pixmap;
            pixmap.loadFromData(imagereply.readAll());
            QIcon icon = QIcon(pixmap);
            int row = ui->FormGamesTableWidgetGames->rowCount();
            ui->FormGamesTableWidgetGames->insertRow(row);
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setIcon(icon);
            ui->FormGamesTableWidgetGames->setItem(row,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(JsonArayGames[i].toObject().value("name").toString());
            ui->FormGamesTableWidgetGames->setItem(row,1,item2);
            QPushButton *button1 = new QPushButton;
            QPushButton *button2 = new QPushButton;
            button1->setText("Достижения");
            button2->setText("Избранное");
            connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
            connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
            button1->setObjectName("FormGamesButtonAchievements"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
            ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
            button2->setObjectName("FormGamesButtonFavorites"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
            ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
            }
    }
    }


    ui->FormGamesTableWidgetGames->resizeColumnsToContents();
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
}

FormGames::~FormGames()
{
    delete ui;
}

void FormGames::closeEvent(QCloseEvent *){
    on_FormGamesButtonReturn_clicked();
}

void FormGames::on_FormGamesButtonReturn_clicked()
{
    emit return_to_profile();
    delete this;
}

void FormGames::AchievementsClicked(){
    QPushButton *btn = (QPushButton*) sender();
    if(true){
        achievementsform = new FormAchievements(key,language,id,btn->objectName().mid(27,btn->objectName().length()));
        connect(achievementsform,SIGNAL(return_to_games()),this,SLOT(on_return()));
        achievementsform->show();
        this->setEnabled(false);
    }
}

void FormGames::FavoritesClicked(){

}

void FormGames::on_return(){
    this->setEnabled(true);
}

void FormGames::on_FormGamesLineEditGame_textChanged(const QString){
    for (int i=0;i<ui->FormGamesTableWidgetGames->rowCount();i++) {
        if(ui->FormGamesTableWidgetGames->item(i,1)->text().toUpper().indexOf(ui->FormGamesLineEditGame->text().toUpper(),0)>-1)
            ui->FormGamesTableWidgetGames->setRowHidden(i,false); else
            ui->FormGamesTableWidgetGames->setRowHidden(i,true);
    }
}
