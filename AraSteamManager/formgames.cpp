#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, SteamAPIGames Gamess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    Words=Setting.GetWords("games");
    id=ids;
    key=keys;
    Games=Gamess;
    Games.Sort();
    ui->TableWidgetGames->setColumnCount(4);
    ui->LabelLogo->setText("(WIP)");
    ui->LineEditGame->setPlaceholderText(Words[0]);
    ui->ButtonFind->setText(" "+Words[1]);
    ui->ButtonReturn->setText(" "+Words[2]);
    ui->TableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[3]));
    ui->TableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->TableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[5]));
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    for(int i=0;i<Games.GetGamesCount();i++){
        int row = ui->TableWidgetGames->rowCount();
        ui->TableWidgetGames->insertRow(row);
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
            ui->TableWidgetGames->setCellWidget(row,0,label);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(Games.GetName(i));
        ui->TableWidgetGames->setItem(row,1,item2);
        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        button1->setText(Words[4]);
        button1->setMinimumSize(QSize(25,25));
        button2->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
        button2->setMinimumSize(QSize(25,25));
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button1->setObjectName("ButtonAchievements"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(row,2,button1);
        button2->setObjectName("ButtonFavorites"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(row,3,button2);
        ui->TableWidgetGames->setRowHeight(i,33);
        ImageRequest *Achievements = new ImageRequest(row,"ButtonAchievements"+QString::number(Games.GetAppid(i))+"&"+Games.GetImg_logo_url(i));
        connect(Achievements,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultAchievements(int, QString, ImageRequest *)));
        Achievements->Get("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+QString::number(Games.GetAppid(i)));
        }
    ui->TableWidgetGames->resizeColumnsToContents();
    ui->TableWidgetGames->setColumnWidth(0,33);
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    ui->LineEditGame->setFocus();
}

FormGames::~FormGames(){
    delete ui;
}
void FormGames::closeEvent(QCloseEvent *){
    on_ButtonReturn_clicked();
}
void FormGames::on_return(FormAchievements* a){
    windowchildcount--;
    this->setVisible(true);
    a->deleteLater();
}
void FormGames::on_ButtonReturn_clicked(){
    emit return_to_profile(this);
    //delete this;
}

void FormGames::on_LineEditGame_textChanged(const QString){
    for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
        if(ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(ui->LineEditGame->text().toUpper(),0)>-1)
            ui->TableWidgetGames->setRowHidden(i,false); else
            ui->TableWidgetGames->setRowHidden(i,true);
    }
}
void FormGames::on_ButtonFind_clicked(){
    on_LineEditGame_textChanged(ui->LineEditGame->text());
}

void FormGames::AchievementsClicked(){
    if(windowchildcount==0){
        windowchildcount++;
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int index=btn->objectName().mid(18,4).toInt();
        QEventLoop loop;
        SteamAPIAchievementsPercentage Percentage(key,QString::number(Games.GetAppid(index)));
        connect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        qDebug()<<Percentage.GetStatus()<<Percentage.GetAchievementsCount()<<QString::number(Games.GetAppid(index));
        if(Percentage.GetAchievementsCount()==0){
            windowchildcount--;
            QMessageBox::warning(this,Words[6],Words[7]);
        } else {
            achievementsform = new FormAchievements(key,id,Games.GetGameInfo(index));
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
    ui->TableWidgetGames->setCellWidget(i,0,label);
    imgr->deleteLater();
}

void FormGames::OnResultAchievements(int i, QString, ImageRequest *imgr){
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(i,2))->setEnabled(false);
    }
    imgr->deleteLater();
}
