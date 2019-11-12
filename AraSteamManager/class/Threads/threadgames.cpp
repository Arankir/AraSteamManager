#include "threadgames.h"

ThreadGames::ThreadGames(QObject *parent) : QObject(parent){
  numrequests=0;
  numnow=0;
}

void ThreadGames::Set(QTableWidget *TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation){
    this->Favorite=Favorite;
    this->AchievementsLocalisation=AchievementsLocalisation;
    this->key=key;
    this->games=games;
    this->TableWidgetGames=TableWidgetGames;
}

int ThreadGames::Fill(){
    for(int i=0;i<games.size();i++){
        int row = TableWidgetGames->rowCount();
        TableWidgetGames->insertRow(row);
        if(!QFile::exists("images/icon_games/"+games[i].GetImg_icon_url()+".jpg")){
            if(numrequests<500){
                if(games[i].GetImg_icon_url()!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",row,"images/icon_games/"+games[i].GetImg_icon_url()+".jpg",true);
                    connect(image,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
                    request.append(image);
                    numrequests++;
                    }
                numnow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load("images/icon_games/"+games[i].GetImg_icon_url()+".jpg");
            emit setimage(pixmap,row);
            }
        TableWidgetGames->setItem(row,1,new QTableWidgetItem(games[i].GetName()));

        TableWidgetGames->setRowHeight(i,33);
        ImageRequest *Achievements = new ImageRequest;
        connect(Achievements,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultAchievements(ImageRequest *)));
        Achievements->LoadImage("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+QString::number(games[i].GetAppid()),row,"ButtonAchievements"+QString::number(games[i].GetAppid())+"&"+games[i].GetImg_logo_url());
        emit progress(i,row);
        }
    TableWidgetGames->resizeColumnsToContents();
    TableWidgetGames->setColumnWidth(0,33);
    TableWidgetGames->setColumnWidth(1,300);
    //ui->TableWidgetGames->resizeRowsToContents();
    //this->setMinimumSize(33+ui->TableWidgetGames->columnWidth(1)+ui->TableWidgetGames->columnWidth(2)+ui->TableWidgetGames->columnWidth(3)+11+ui->TableWidgetGames->verticalHeader()->width(),577);
    //http://media.steampowered.com/steamcommunity/public/images/apps/{appid}/{hash}.jpg
    emit finished();
    return 1;
}

void ThreadGames::OnResultImage(ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    emit setimage(pixmap,imgr->GetRow());
    //imgr->deleteLater();
    if(numrequests==500&&numnow<games.size()){
        while (QFile::exists("images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg")||games[numnow].GetImg_icon_url()=="") {
            numnow++;
        }
        imgr->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(games[numnow].GetAppid())+"/"+games[numnow].GetImg_icon_url()+".jpg",imgr->GetRow(),"images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg",true);
        numnow++;
    } else
        disconnect(imgr,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
}

void ThreadGames::OnResultAchievements(ImageRequest *imgr){
    disconnect(imgr,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultAchievements(ImageRequest *)));
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(TableWidgetGames->cellWidget(imgr->GetRow(),2))->setEnabled(false);
    }
    imgr->deleteLater();
}

