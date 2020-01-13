#include "Sachievementspercentage.h"

SAchievementsPercentage::SAchievementsPercentage(QString Aappid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+Aappid));
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _count=Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPercentage(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i++).toObject())));
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}
SAchievementsPercentage::SAchievementsPercentage(){
    _manager = new QNetworkAccessManager();
}
SAchievementsPercentage::~SAchievementsPercentage(){
    delete _manager;
}

void SAchievementsPercentage::Set(QString Aappid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+_setting.GetKey()+"&gameid="+Aappid));
}
void SAchievementsPercentage::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _count=Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPercentage(Aachievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i++).toObject())));
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="game is not exist";
    }
}

void SAchievementsPercentage::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPercentage::Update(){
    Set(_appid);
}
void SAchievementsPercentage::Clear(){
    _achievements.clear();
    _count=0;
}

SAchievementsPercentage::SAchievementsPercentage( const SAchievementsPercentage & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _count=AnewAchievements._count;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
}
SAchievementsPercentage & SAchievementsPercentage::operator=(const SAchievementsPercentage & AnewAchievements) {
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _count=AnewAchievements._count;
    _status=AnewAchievements._status;
    _error=AnewAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
