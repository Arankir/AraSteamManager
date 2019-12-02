#include "Sachievementsplayer.h"

SAchievementsPlayer::SAchievementsPlayer(QString key, QString appid, QString id, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid, id);
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SAchievementsPlayer::SAchievementsPlayer(){
    manager = new QNetworkAccessManager();
}
SAchievementsPlayer::~SAchievementsPlayer(){
    delete manager;
}

void SAchievementsPlayer::Set(QString key, QString appid, QString id){
connect(manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
this->key=key;
this->appid=appid;
this->id=id;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id));
}
void SAchievementsPlayer::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        appid=DocAchievements.object().value("playerstats").toObject().value("steamID").toString();
        gamename=DocAchievements.object().value("playerstats").toObject().value("gameName").toString();
        count=DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SAchievementPlayer(DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SAchievementsPlayer::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    qDebug()<<"Player load";
    emit finished(*this);
    emit finished();
}

void SAchievementsPlayer::Update(){
    Set(key,appid,id);
}
void SAchievementsPlayer::Clear(){
    achievements.clear();
    count=0;
}

SAchievementsPlayer::SAchievementsPlayer( const SAchievementsPlayer & achievementss){
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    id=achievementss.id;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    status=achievementss.status;
    index=achievementss.index;
    manager = new QNetworkAccessManager;
}
SAchievementsPlayer & SAchievementsPlayer::operator=(const SAchievementsPlayer & achievementss) {
    delete manager;
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    id=achievementss.id;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    status=achievementss.status;
    index=achievementss.index;
    manager = new QNetworkAccessManager;
    return *this;
}
