#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, int languages, QJsonDocument Games, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGames)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;

    QNetworkAccessManager manager;
    QEventLoop loop;  //Ждем ответ от сервера.
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    JsonDocGames = Games;
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
        on_FormCreate_language("","Find game","Find","Return","","Title game","Achievements","Favorites",JsonArayGames,"Achievements");
        break;
        }
    case 5:{
        on_FormCreate_language("","Найти игру","Найти","Вернуться","","Название игры","Достижения","Избранное",JsonArayGames,"Достижения");
        }
    }
    ui->FormGamesTableWidgetGames->resizeColumnsToContents();
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    ui->FormGamesLineEditGame->setFocus();
}

void FormGames::on_FormCreate_language(QString LabelLogo, QString GamePlaceholder, QString ButtonFind, QString ButtonReturn, QString HH0, QString HH1, QString HH2, QString HH3, QJsonArray Games, QString buttonAchievements){
    ui->FormGamesLabelLogo->setText(LabelLogo);
    ui->FormGamesLineEditGame->setPlaceholderText(GamePlaceholder);
    ui->FormGamesButtonFind->setText(ButtonFind);
    ui->FormGamesButtonReturn->setText(ButtonReturn);
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(HH0));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(HH1));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(HH2));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(HH3));
    for(int i=0;i<Games.size();i++){
//        QPixmap pixmap;
//        if(!QFile::exists("images/icon_games/"+Games[i].toObject().value("img_icon_url").toString()+".png")){
//            if(Games[i].toObject().value("img_icon_url").toString()!=""){
//                QNetworkAccessManager imagemanager;
//                QEventLoop imageloop;  //Ждем ответ от сервера.
//                QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
//                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(Games[i].toObject().value("appid").toInt())+"/"+Games[i].toObject().value("img_icon_url").toString()+".jpg"));
//                imageloop.exec();
//                QImage img;
//                img.loadFromData(imagereply.readAll());
//                img.save("images/icon_games/"+Games[i].toObject().value("img_icon_url").toString()+".png", "PNG");
//                pixmap=QPixmap::fromImage(img);
//            }
//        } else {
//            pixmap.load("images/icon_games/"+Games[i].toObject().value("img_icon_url").toString()+".png", "PNG");
//            }
        QNetworkAccessManager imagemanager;
        QEventLoop imageloop;  //Ждем ответ от сервера.
        QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
        QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(Games[i].toObject().value("appid").toInt())+"/"+Games[i].toObject().value("img_icon_url").toString()+".jpg"));
        imageloop.exec();
        QPixmap pixmap;
        pixmap.loadFromData(imagereply.readAll());
        QIcon icon = QIcon(pixmap);
        int row = ui->FormGamesTableWidgetGames->rowCount();
        ui->FormGamesTableWidgetGames->insertRow(row);
        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setIcon(icon);
        ui->FormGamesTableWidgetGames->setItem(row,0,item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(Games[i].toObject().value("name").toString());
        ui->FormGamesTableWidgetGames->setItem(row,1,item2);
        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        button1->setText(buttonAchievements);
        button2->setText("«");
        QFont font("Wingdings");
        button2->setFont(font);
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button1->setObjectName("FormGamesButtonAchievements"+QString::number(Games[i].toObject().value("appid").toInt())+"&"+Games[i].toObject().value("img_logo_url").toString());
        ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
        button2->setObjectName("FormGamesButtonFavorites"+QString::number(Games[i].toObject().value("appid").toInt()));
        ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
        }
}

FormGames::~FormGames(){
    delete ui;
}

void FormGames::closeEvent(QCloseEvent *){
    on_FormGamesButtonReturn_clicked();
}

void FormGames::on_FormGamesButtonReturn_clicked(){
    emit return_to_profile();
    delete this;
}

void FormGames::AchievementsClicked(){
    QPushButton *btn = (QPushButton*) sender();
    qDebug() <<btn->objectName()<< btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27)<<btn->objectName().mid(btn->objectName().indexOf("&",27)+1,btn->objectName().length());
        achievementsform = new FormAchievements(key,language,id,btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27),btn->objectName().mid(btn->objectName().indexOf("&",27)+1,btn->objectName().length()));
        connect(achievementsform,SIGNAL(return_to_games()),this,SLOT(on_return()));
        achievementsform->show();
        this->setEnabled(false);
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

void FormGames::on_FormGamesButtonFind_clicked(){
    on_FormGamesLineEditGame_textChanged(ui->FormGamesLineEditGame->text());
}
