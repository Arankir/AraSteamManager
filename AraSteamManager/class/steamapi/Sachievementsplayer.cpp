#include "Sachievementsplayer.h"

SAchievementsPlayer::SAchievementsPlayer(QString AKey, QString AAppid, QString AID, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _key=AKey;
    _appid=AAppid;
    _id=AID;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+AKey+"&appid="+AAppid+"&steamid="+AID));
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument AAchievements){
    _manager = new QNetworkAccessManager();
    if(AAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=AAchievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=AAchievements.object().value("playerstats").toObject().value("gameName").toString();
        _count=AAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPlayer(AAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SAchievementsPlayer::SAchievementsPlayer(){
    _manager = new QNetworkAccessManager();
}
SAchievementsPlayer::~SAchievementsPlayer(){
    delete _manager;
}

void SAchievementsPlayer::Set(QString AKey, QString AAppid, QString AID){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _key=AKey;
    _appid=AAppid;
    _id=AID;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+AKey+"&appid="+AAppid+"&steamid="+AID));
}
void SAchievementsPlayer::Set(QJsonDocument AAchievements){
    Clear();
    if(AAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=AAchievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=AAchievements.object().value("playerstats").toObject().value("gameName").toString();
        _count=AAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPlayer(AAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SAchievementsPlayer::Load(QNetworkReply *AReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(AReply->readAll());
    AReply->deleteLater();
    Set(localAchievements);
    qDebug()<<"Player load";
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPlayer::Update(){
    Set(_key,_appid,_id);
}
void SAchievementsPlayer::Clear(){
    _achievements.clear();
    _count=0;
}

SAchievementsPlayer::SAchievementsPlayer( const SAchievementsPlayer & ANewAchievements){
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _id=ANewAchievements._id;
    _key=ANewAchievements._key;
    _count=ANewAchievements._count;
    _gameName=ANewAchievements._gameName;
    _status=ANewAchievements._status;
    _index=ANewAchievements._index;
    _manager = new QNetworkAccessManager;
}
SAchievementsPlayer & SAchievementsPlayer::operator=(const SAchievementsPlayer & ANewAchievements) {
    delete _manager;
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _id=ANewAchievements._id;
    _key=ANewAchievements._key;
    _count=ANewAchievements._count;
    _gameName=ANewAchievements._gameName;
    _status=ANewAchievements._status;
    _index=ANewAchievements._index;
    _manager = new QNetworkAccessManager;
    return *this;
}
