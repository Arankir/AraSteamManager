#include "Sachievementsplayer.h"

SAchievementsPlayer::SAchievementsPlayer(QString Aappid, QString Aid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=Aappid;
    _id=Aid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+Aappid+"&steamid="+Aid));
}
SAchievementsPlayer::SAchievementsPlayer(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=Aachievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=Aachievements.object().value("playerstats").toObject().value("gameName").toString();
        _count=Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPlayer(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().at(i++).toObject())));
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

void SAchievementsPlayer::Set(QString Aappid, QString Aid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid=Aappid;
    _id=Aid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+_setting.GetKey()+"&appid="+Aappid+"&steamid="+Aid));
}
void SAchievementsPlayer::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size()>0){
        _appid=Aachievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName=Aachievements.object().value("playerstats").toObject().value("gameName").toString();
        _count=Aachievements.object().value("playerstats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPlayer(Aachievements.object().value("playerstats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SAchievementsPlayer::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
    qDebug()<<"Player load";
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPlayer::Update(){
    Set(_appid,_id);
}
void SAchievementsPlayer::Clear(){
    _achievements.clear();
    _count=0;
}

SAchievementsPlayer::SAchievementsPlayer( const SAchievementsPlayer & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _id=AnewAchievements._id;
    _count=AnewAchievements._count;
    _gameName=AnewAchievements._gameName;
    _status=AnewAchievements._status;
    _index=AnewAchievements._index;
    _manager = new QNetworkAccessManager;
}
SAchievementsPlayer & SAchievementsPlayer::operator=(const SAchievementsPlayer & AnewAchievements) {
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _id=AnewAchievements._id;
    _count=AnewAchievements._count;
    _gameName=AnewAchievements._gameName;
    _status=AnewAchievements._status;
    _index=AnewAchievements._index;
    _manager = new QNetworkAccessManager;
    return *this;
}
