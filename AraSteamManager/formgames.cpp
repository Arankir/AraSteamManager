#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, SGames Gamess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    Words=Setting.GetWords("games");
    id=ids;
    key=keys;
    SGames Games=Gamess;
    for (int i=0;i<Games.GetCount();i++) {
        games.push_back(Games.GetGame(i));
    }
    for (int i=0; i < games.size()-1; i++) {
        for (int j=0; j < games.size()-i-1; j++) {
            if (games[j].GetName() > games[j+1].GetName()) {
                SGame temp = games[j];
                games[j] = games[j+1];
                games[j+1] = temp;
            }
        }
    }
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
    for(int i=0;i<games.size();i++){
        int row = ui->TableWidgetGames->rowCount();
        ui->TableWidgetGames->insertRow(row);
        if(!QFile::exists("images/icon_games/"+games[i].GetImg_icon_url()+".jpg")){
            if(numrequests<1000){
                if(games[i].GetImg_icon_url()!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",row,"images/icon_games/"+games[i].GetImg_icon_url()+".jpg",true);
                    connect(image,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
                    requests[numrequests] = image;
                    numrequests++;
                    }
                numnow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load("images/icon_games/"+games[i].GetImg_icon_url()+".jpg");
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetGames->setCellWidget(row,0,label);
            }
        ui->TableWidgetGames->setItem(row,1,new QTableWidgetItem(games[i].GetName()));

        QPushButton *button1 = new QPushButton(Words[4]);
        button1->setMinimumSize(QSize(25,25));
        connect(button1,SIGNAL(pressed()),this,SLOT(AchievementsClicked()));
        button1->setObjectName("ButtonAchievements"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(row,2,button1);

        QPushButton *button2 = new QPushButton;
        button2->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
        button2->setMinimumSize(QSize(25,25));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button2->setObjectName("ButtonFavorites"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(row,3,button2);

        ui->TableWidgetGames->setRowHeight(i,33);
        ImageRequest *Achievements = new ImageRequest;
        connect(Achievements,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultAchievements(ImageRequest *)));
        Achievements->LoadImage("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+QString::number(games[i].GetAppid()),row,"ButtonAchievements"+QString::number(games[i].GetAppid())+"&"+games[i].GetImg_logo_url());
        }
    ui->TableWidgetGames->resizeColumnsToContents();
    ui->TableWidgetGames->setColumnWidth(0,33);
    ui->TableWidgetGames->setColumnWidth(1,300);
    //ui->TableWidgetGames->resizeRowsToContents();
    //this->setMinimumSize(33+ui->TableWidgetGames->columnWidth(1)+ui->TableWidgetGames->columnWidth(2)+ui->TableWidgetGames->columnWidth(3)+11+ui->TableWidgetGames->verticalHeader()->width(),577);
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    ui->LineEditGame->setFocus();
}

FormGames::~FormGames(){
    delete ui;
}
void FormGames::closeEvent(QCloseEvent *){
    on_ButtonReturn_clicked();
}
void FormGames::returnfromachievements(){
    windowchildcount--;
    disconnect(achievementsform,SIGNAL(return_to_games()),this,SLOT(returnfromachievements()));
    this->setVisible(true);
    delete achievementsform;
}
void FormGames::on_ButtonReturn_clicked(){
    emit return_to_profile();
    //delete this;
}

void FormGames::on_LineEditGame_textChanged(const QString){
    for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
        ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(ui->LineEditGame->text().toUpper(),0)>-1?false:true);
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
        SAchievementsPercentage Percentage(key,QString::number(games[index].GetAppid()));
        connect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        disconnect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
        qDebug()<<Percentage.GetStatus()<<Percentage.GetAchievementsCount()<<QString::number(games[index].GetAppid());
        if(Percentage.GetAchievementsCount()==0){
            windowchildcount--;
            QMessageBox::warning(this,Words[6],Words[7]);
        } else {
            achievementsform = new FormAchievements(key,id,games[index]);
            connect(achievementsform,SIGNAL(return_to_games()),this,SLOT(returnfromachievements()));
            achievementsform->show();
            this->setVisible(false);
        }
    }
}

void FormGames::FavoritesClicked(){

}

void FormGames::OnResultImage(ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetGames->setCellWidget(imgr->GetRow(),0,label);
    //imgr->deleteLater();
    if(numnow<games.size()){
        while (QFile::exists("images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg")||games[numnow].GetImg_icon_url()=="") {
            numnow++;
        }
        imgr->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(games[numnow].GetAppid())+"/"+games[numnow].GetImg_icon_url()+".jpg",imgr->GetRow(),"images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg",true);
        numnow++;
    } else
        disconnect(imgr,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
}

void FormGames::OnResultAchievements(ImageRequest *imgr){
    disconnect(imgr,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultAchievements(ImageRequest *)));
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(imgr->GetRow(),2))->setEnabled(false);
    }
    imgr->deleteLater();
}
