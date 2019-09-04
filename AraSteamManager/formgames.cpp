#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, SteamAPIGames Gamess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    Language lan;
    Words=lan.GetLanguage("games",Setting.GetLanguage());
    id=ids;
    key=keys;
    Games=Gamess;
    Games.Sort();
    ui->FormGamesTableWidgetGames->setColumnCount(4);
    ui->FormGamesLabelLogo->setText("(WIP)");
    ui->FormGamesLineEditGame->setPlaceholderText(Words[0]);
    ui->FormGamesButtonFind->setText(" "+Words[1]);
    ui->FormGamesButtonReturn->setText(" "+Words[2]);
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[3]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->FormGamesTableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[5]));
    ui->FormGamesTableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    switch(Setting.GetTheme()){
    case 1:{
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        break;
        }
    }
    ui->FormGamesButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->FormGamesButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    for(int i=0;i<Games.GetGamesCount();i++){
        int row = ui->FormGamesTableWidgetGames->rowCount();
        ui->FormGamesTableWidgetGames->insertRow(row);
        if(!QFile::exists("images/icon_games/"+Games.GetImg_icon_url(i)+".png")){
            if(Games.GetImg_icon_url(i)!=""){
                ImageRequest *image;
                switch (Setting.GetSaveimages()) {
                    case 0:{
                        image = new ImageRequest(row,"");
                        break;
                        }
                    case 1:{
                        image = new ImageRequest(row,Games.GetImg_icon_url(i));
                        break;
                        }
                    default:{
                        image = new ImageRequest(row,"");
                        break;
                        }
                    }
                connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
                image->Get("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(Games.GetAppid(i))+"/"+Games.GetImg_icon_url(i)+".jpg");
                }
            } else {
            QPixmap pixmap;
            pixmap.load("images/icon_games/"+Games.GetImg_icon_url(i)+".png", "PNG");
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->FormGamesTableWidgetGames->setCellWidget(row,0,label);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(Games.GetName(i));
        ui->FormGamesTableWidgetGames->setItem(row,1,item2);
        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        button1->setText(Words[4]);
        button1->setMinimumSize(QSize(25,25));
        button2->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
        button2->setMinimumSize(QSize(25,25));
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button1->setObjectName("FormGamesButtonAchievements"+QString::number(Games.GetAppid(i))+"&"+Games.GetImg_logo_url(i));
        ui->FormGamesTableWidgetGames->setCellWidget(row,2,button1);
        button2->setObjectName("FormGamesButtonFavorites"+QString::number(Games.GetAppid(i)));
        ui->FormGamesTableWidgetGames->setCellWidget(row,3,button2);
        ui->FormGamesTableWidgetGames->setRowHeight(i,33);
        ImageRequest *Achievements = new ImageRequest(row,"FormGamesButtonAchievements"+QString::number(Games.GetAppid(i))+"&"+Games.GetImg_logo_url(i));
        connect(Achievements,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultAchievements(int, QString, ImageRequest *)));
        Achievements->Get("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+QString::number(Games.GetAppid(i)));
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
void FormGames::on_return(FormAchievements* a){
    windowchildcount--;
    this->setVisible(true);
    a->deleteLater();
}
void FormGames::on_FormGamesButtonReturn_clicked(){
    emit return_to_profile(this);
    //delete this;
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
    if(windowchildcount==0){
        windowchildcount++;
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyGlobalAchievementPercentagesForApp = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27))));
        loop.exec();
        QJsonDocument JsonDocGlobalAchievements = QJsonDocument::fromJson(replyGlobalAchievementPercentagesForApp.readAll());
        if(JsonDocGlobalAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
            windowchildcount--;
            QMessageBox::warning(this,Words[6],Words[7]);
        } else {
            achievementsform = new FormAchievements(key,id,btn->objectName().mid(27,btn->objectName().indexOf("&",27)-27),btn->objectName().mid(btn->objectName().indexOf("&",27)+1,btn->objectName().length()),JsonDocGlobalAchievements);
            connect(achievementsform,SIGNAL(return_to_games(FormAchievements*)),this,SLOT(on_return(FormAchievements*)));
            achievementsform->show();
            this->setVisible(false);
        }
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

void FormGames::OnResultAchievements(int i, QString, ImageRequest *imgr){
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(ui->FormGamesTableWidgetGames->cellWidget(i,2))->setEnabled(false);
    }
    imgr->deleteLater();
}
