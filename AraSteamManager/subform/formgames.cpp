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
    InitComponents();
    ui->LineEditGame->setFocus();
}

#define Init {
void FormGames::InitComponents(){
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
    ui->LineEditGame->setPlaceholderText(Words[0]);
    ui->ButtonFind->setText(" "+Words[1]);
    //ui->ButtonReturn->setText(" "+Words[2]);
    ui->TableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[3]));
    ui->TableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->TableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[5]));
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    //ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    //Achievement = ;
    Favorite = QIcon(":/"+theme+"/program/"+theme+"/favorites.png");
    ui->TableWidgetGames->setRowCount(games.count());
    for (int i=0;i<games.count();i++) {
        ui->TableWidgetGames->setRowHeight(i,33);
        QPushButton *button1 = new QPushButton(Words[4]);
        button1->setMinimumSize(QSize(25,25));
        connect(button1,&QPushButton::pressed,this,&FormGames::AchievementsClicked);
        button1->setObjectName("ButtonAchievements"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,2,button1);

        QPushButton *button2 = new QPushButton;
        button2->setIcon(Favorite);
        button2->setMinimumSize(QSize(25,25));
        connect(button2,&QPushButton::pressed,this,&FormGames::FavoritesClicked);
        button2->setObjectName("ButtonFavorites"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,3,button2);
    }
    ui->TableWidgetGames->setColumnWidth(0,33);
    ui->TableWidgetGames->setColumnWidth(1,300);
    Threading LoadTable(this);
    LoadTable.AddThreadGames(ui->TableWidgetGames,games);
}
void FormGames::ProgressLoading(int p,int row){

}
void FormGames::OnFinish(){
    ui->TableWidgetGames->resizeColumnsToContents();
    for(int i=0;i<games.size();i++){
        QString path = "images/icon_games/"+games[i].GetImg_icon_url()+".jpg";
        if(!QFile::exists(path)){
            if(numrequests<500){
                if(games[i].GetImg_icon_url()!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",i,path,true);
                    connect(image,&ImageRequest::onReady,this,&FormGames::OnResultImage);
                    request.append(image);
                    numrequests++;
                    }
                numnow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load(path);
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetGames->setCellWidget(i,0,label);
            }
        ImageRequest *Achievements = new ImageRequest();
        connect(Achievements,&ImageRequest::onReady,this,&FormGames::OnResultAchievements);
        Achievements->LoadImage("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+
                                "&gameid="+QString::number(games[i].GetAppid()),i,
                                "ButtonAchievements"+QString::number(games[i].GetAppid())+"&"+games[i].GetImg_logo_url());
        }
}
void FormGames::OnResultImage(ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetGames->setCellWidget(imgr->GetRow(),0,label);
    if(numrequests==500&&numnow<games.size()){
        while (QFile::exists("images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg")||games[numnow].GetImg_icon_url()=="") {
            numnow++;
        }
        imgr->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                        QString::number(games[numnow].GetAppid())+"/"+games[numnow].GetImg_icon_url()+".jpg",numnow,
                        "images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg",true);
        numnow++;
    } else {
        disconnect(imgr,&ImageRequest::onReady,this,&FormGames::OnResultImage);
        imgr->deleteLater();
    }
}
void FormGames::OnResultAchievements(ImageRequest *imgr){
    disconnect(imgr,&ImageRequest::onReady,this,&FormGames::OnResultAchievements);
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(imgr->GetRow(),2))->setEnabled(false);
    }
    imgr->deleteLater();
}
#define InitEnd }

#define System {
FormGames::~FormGames(){
    qDebug()<<numrequests<<"запросов на картинки";
    //if(numrequests)
    //    for (int i=0;i<=numrequests;i++) {
    //        delete request[numrequests];
    //    }
    //if(achievementsform)
    //    delete achievementsform;
    //delete all ukazateli
    delete ui;
}
void FormGames::closeEvent(QCloseEvent*){
    emit return_to_profile();
    //delete this;
}
void FormGames::returnfromachievements(int num){
    //windowchildcount--;
    disconnect(achievementsforms[num],&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
    //delete achievementsforms[num];
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString){
    for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
        ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(ui->LineEditGame->text().toUpper(),0)>-1?false:true);
    }
}
void FormGames::on_ButtonFind_clicked(){
    on_LineEditGame_textChanged(ui->LineEditGame->text());
}
#define FilterEnd }

#define Functions {
void FormGames::AchievementsClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(18,4).toInt();
    QEventLoop loop;
    SAchievementsPercentage Percentage(key,QString::number(games[index].GetAppid()));
    connect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    if(Percentage.GetAchievementsCount()==0){
        QMessageBox::warning(this,Words[6],Words[7]);
    } else {
        FormAchievements *fa = new FormAchievements(key,id,games[index],windowchildcount++);
        achievementsforms.append(fa);
        connect(fa,&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
        fa->show();
    }
}
void FormGames::FavoritesClicked(){

}
#define FunctionsEnd }
