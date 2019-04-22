#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, int languages, QJsonDocument Games, int SaveImage, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGames)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    SaveImages=SaveImage;
    QFile FileLanguage;
    switch(language){
    case 1:{
        FileLanguage.setFileName("Files/Languages/ENG/games.txt");
        break;
        }
    case 5:{
        FileLanguage.setFileName("Files/Languages/RU/games.txt");
        }
    }
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n");
        }
    }
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
    ui->FormGamesLabelLogo->setText("");
    ui->FormGamesLineEditGame->setPlaceholderText(SLLanguage[0]);
    ui->FormGamesButtonFind->setText(SLLanguage[1]);
    ui->FormGamesButtonReturn->setText(SLLanguage[2]);
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[3]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[4]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[5]));
    for(int i=0;i<JsonArayGames.size();i++){
        QPixmap pixmap;
        switch (SaveImages) {
        case 0:{
            QNetworkAccessManager imagemanager;
            QEventLoop imageloop;  //Ждем ответ от сервера.
            QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
            QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".jpg"));
            imageloop.exec();
            pixmap.loadFromData(imagereply.readAll());
            break;
        }
        case 1:{
            if(!QFile::exists("images/icon_games/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".png")){
                if(JsonArayGames[i].toObject().value("img_icon_url").toString()!=""){
                    QNetworkAccessManager imagemanager;
                    QEventLoop imageloop;  //Ждем ответ от сервера.
                    QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".jpg"));
                    imageloop.exec();
                    QImage img;
                    img.loadFromData(imagereply.readAll());
                    img.save("images/icon_games/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".png", "PNG");
                    pixmap=QPixmap::fromImage(img);
                }
            } else {
                pixmap.load("images/icon_games/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".png", "PNG");
                }
            break;
        }
        }
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
        button1->setText(SLLanguage[4]);
        button1->setMinimumSize(QSize(25,25));
        button2->setText("«");
        QFont font("Wingdings");
        button2->setMinimumSize(QSize(25,25));
        button2->setFont(font);
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button1->setObjectName("FormGamesButtonAchievements"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"&"+JsonArayGames[i].toObject().value("img_logo_url").toString());
        ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
        button2->setObjectName("FormGamesButtonFavorites"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
        ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
        }
    ui->FormGamesTableWidgetGames->resizeColumnsToContents();
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    ui->FormGamesLineEditGame->setFocus();
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
        achievementsform = new FormAchievements(key,language,id,btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27),btn->objectName().mid(btn->objectName().indexOf("&",27)+1,btn->objectName().length()),SaveImages);
        connect(achievementsform,SIGNAL(return_to_games()),this,SLOT(on_return()));
        achievementsform->show();
        this->setVisible(false);
}

void FormGames::FavoritesClicked(){

}

void FormGames::on_return(){
    this->setVisible(true);
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
