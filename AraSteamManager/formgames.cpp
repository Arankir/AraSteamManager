#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, int languages, int Themes, QJsonDocument Games, int SaveImage, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    SaveImages=SaveImage;
    Theme=Themes;
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
    QIcon favorites;
    switch(Theme){
    case 1:{
        ui->FormGamesButtonFind->setIcon(QIcon("images/program/find_white.png"));
        ui->FormGamesButtonReturn->setIcon(QIcon("images/program/back_white.png"));
        favorites.addFile("images/program/favorites_white.png");
        break;
        }
    case 2:{
        break;
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
    ui->FormGamesButtonReturn->setText(" "+SLLanguage[2]);
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[3]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[4]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[5]));
    for(int i=0;i<JsonArayGames.size();i++){
        int row = ui->FormGamesTableWidgetGames->rowCount();
        ui->FormGamesTableWidgetGames->insertRow(row);
        if(!QFile::exists("images/icon_games/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".png")){
            if(JsonArayGames[i].toObject().value("img_icon_url").toString()!=""){
                ImageRequest *image;
                switch (SaveImages) {
                    case 0:{
                        image = new ImageRequest(row,"");
                        break;
                        }
                    case 1:{
                        image = new ImageRequest(row,JsonArayGames[i].toObject().value("img_icon_url").toString());
                        break;
                        }
                    default:{
                        image = new ImageRequest(row,"");
                        break;
                        }
                    }
                connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
                image->Get("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".jpg");
                }
            } else {
            QPixmap pixmap;
            pixmap.load("images/icon_games/"+JsonArayGames[i].toObject().value("img_icon_url").toString()+".png", "PNG");
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->FormGamesTableWidgetGames->setCellWidget(row,0,label);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(JsonArayGames[i].toObject().value("name").toString());
        ui->FormGamesTableWidgetGames->setItem(row,1,item2);
        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        button1->setText(SLLanguage[4]);
        button1->setMinimumSize(QSize(25,25));
        button2->setIcon(favorites);
        button2->setMinimumSize(QSize(25,25));
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button1->setObjectName("FormGamesButtonAchievements"+QString::number(JsonArayGames[i].toObject().value("appid").toInt())+"&"+JsonArayGames[i].toObject().value("img_logo_url").toString());
        ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
        button2->setObjectName("FormGamesButtonFavorites"+QString::number(JsonArayGames[i].toObject().value("appid").toInt()));
        ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
        ui->FormGamesTableWidgetGames->setRowHeight(i,33);
        }
    ui->FormGamesTableWidgetGames->resizeColumnsToContents();
    ui->FormGamesTableWidgetGames->setColumnWidth(0,33);
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    ui->FormGamesLineEditGame->setFocus();
}

FormGames::~FormGames(){
    delete ui;
}
void FormGames::closeEvent(QCloseEvent *){
    on_FormGamesButtonReturn_clicked();
}
void FormGames::on_return(){
    this->setVisible(true);
}
void FormGames::on_FormGamesButtonReturn_clicked(){
    emit return_to_profile();
    delete this;
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

void FormGames::AchievementsClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyGlobalAchievementPercentagesForApp = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27))));
    loop.exec();
    QJsonDocument JsonDocGlobalAchievements = QJsonDocument::fromJson(replyGlobalAchievementPercentagesForApp.readAll());
    if(JsonDocGlobalAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        QMessageBox::warning(this,SLLanguage[6],SLLanguage[7]);
    } else{
        achievementsform = new FormAchievements(key,language,Theme,id,btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27),btn->objectName().mid(btn->objectName().indexOf("&",27)+1,btn->objectName().length()),JsonDocGlobalAchievements,SaveImages);
        connect(achievementsform,SIGNAL(return_to_games()),this,SLOT(on_return()));
        achievementsform->show();
        this->setVisible(false);
    }

}

void FormGames::FavoritesClicked(){

}

void FormGames::OnResultImage(int i, QString Save, ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/icon_games/"+Save+".png", "PNG");
    }
    ui->FormGamesTableWidgetGames->setCellWidget(i,0,label);
    imgr->deleteLater();
}
