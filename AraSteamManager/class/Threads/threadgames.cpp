#include "threadgames.h"

ThreadGames::ThreadGames(QObject* parent) : QObject(parent){
  numrequests=0;
  numnow=0;
}

void ThreadGames::Set(QTableWidget* TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation){
    this->Favorite=Favorite;
    this->AchievementsLocalisation=AchievementsLocalisation;
    this->key=key;
    this->games=games;
    this->TableWidgetGames=TableWidgetGames;
}

int ThreadGames::Fill(){
    images=achievements=games.size();
    TableWidgetGames->setRowCount(games.count());
    for(int i=0;i<games.size();i++){
        QString path = "images/icon_games/"+games[i].GetImg_icon_url()+".jpg";
        if(!QFile::exists(path)){
            if(numrequests<500){
                if(games[i].GetImg_icon_url()!=""){
                    ImageRequest* image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",i,path,true);
                    connect(image,&ImageRequest::onReady,this,&ThreadGames::OnResultImage);
                    request.append(image);
                    numrequests++;
                    } else
                    images--;
                numnow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load(path);
            emit setimage(pixmap,i);
            }
        TableWidgetGames->setItem(i,1,new QTableWidgetItem(games[i].GetName()));

        TableWidgetGames->setRowHeight(i,33);
        ImageRequest* Achievements = new ImageRequest();
        connect(Achievements,&ImageRequest::onReady,this,&ThreadGames::OnResultAchievements);
        Achievements->LoadImage("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+
                                "&gameid="+QString::number(games[i].GetAppid()),i,
                                "ButtonAchievements"+QString::number(games[i].GetAppid())+"&"+games[i].GetImg_logo_url());
        emit progress(i,i);
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

void ThreadGames::OnResultImage(ImageRequest* imgr){
    qDebug()<<images<<achievements;
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
        disconnect(imgr,SIGNAL(onReady(ImageRequest*)),this,SLOT(OnResultImage(ImageRequest*)));
    images--;
}

void ThreadGames::OnResultAchievements(ImageRequest* imgr){
    qDebug()<<images<<achievements;
    disconnect(imgr,SIGNAL(onReady(ImageRequest*)),this,SLOT(OnResultAchievements(ImageRequest*)));
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    qDebug()<<doc;
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(TableWidgetGames->cellWidget(imgr->GetRow(),2))->setEnabled(false);
    }
    imgr->deleteLater();
    achievements--;
}

