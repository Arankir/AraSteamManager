#include "steamapiachievementsplayer.h"

SteamAPIAchievementsPlayer::SteamAPIAchievementsPlayer(QString key, QString appid, QString id, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid, id);
}
SteamAPIAchievementsPlayer::SteamAPIAchievementsPlayer(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SteamAPIAchievementsPlayer::SteamAPIAchievementsPlayer(){
    manager = new QNetworkAccessManager();
}
SteamAPIAchievementsPlayer::~SteamAPIAchievementsPlayer(){
    delete manager;
}

void SteamAPIAchievementsPlayer::Set(QString key, QString appid, QString id){
connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsPlayer::Load);
this->key=key;
this->appid=appid;
this->id=id;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id));
}
void SteamAPIAchievementsPlayer::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        appid=DocAchievements.object().value("playerstats").toObject().value("steamID").toString();
        gamename=DocAchievements.object().value("playerstats").toObject().value("gameName").toString();
        count=DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SteamAPIAchievementPlayer(DocAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIAchievementsPlayer::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsPlayer::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    emit finished(this);
    emit finished();
}

void SteamAPIAchievementsPlayer::Update(){
    Set(key,appid,id);
}
void SteamAPIAchievementsPlayer::Clear(){
    achievements.clear();
    count=0;
}

SteamAPIAchievementsPlayer::SteamAPIAchievementsPlayer( const SteamAPIAchievementsPlayer & achievementss){
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    id=achievementss.id;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
}
SteamAPIAchievementsPlayer & SteamAPIAchievementsPlayer::operator=(const SteamAPIAchievementsPlayer & achievementss) {
    delete manager;
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    id=achievementss.id;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
    return *this;
}
