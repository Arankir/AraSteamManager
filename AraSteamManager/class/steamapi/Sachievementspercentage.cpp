#include "Sachievementspercentage.h"

SAchievementsPercentage::SAchievementsPercentage(QString AKey, QString AAppid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _key=AKey;
    _appid=AAppid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+AKey+"&gameid="+AAppid));
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument AAchievements){
    _manager = new QNetworkAccessManager();
    if(AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _count=AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPercentage(AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: game is not exist";
    }
}
SAchievementsPercentage::SAchievementsPercentage(){
    _manager = new QNetworkAccessManager();
}
SAchievementsPercentage::~SAchievementsPercentage(){
    delete _manager;
}

void SAchievementsPercentage::Set(QString AKey, QString AAppid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    _key=AKey;
    _appid=AAppid;
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+AKey+"&gameid="+AAppid));
}
void SAchievementsPercentage::Set(QJsonDocument AAchievements){
    Clear();
    if(AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        _count=AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementPercentage(AAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: game is not exist";
    }
}

void SAchievementsPercentage::Load(QNetworkReply *AReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(AReply->readAll());
    AReply->deleteLater();
    Set(localAchievements);
    qDebug()<<"Percent load";
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPercentage::Update(){
    Set(_key,_appid);
}
void SAchievementsPercentage::Clear(){
    _achievements.clear();
    _count=0;
}

SAchievementsPercentage::SAchievementsPercentage( const SAchievementsPercentage & ANewAchievements){
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _key=ANewAchievements._key;
    _count=ANewAchievements._count;
    _status=ANewAchievements._status;
    _manager = new QNetworkAccessManager;
}
SAchievementsPercentage & SAchievementsPercentage::operator=(const SAchievementsPercentage & ANewAchievements) {
    delete _manager;
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _key=ANewAchievements._key;
    _count=ANewAchievements._count;
    _status=ANewAchievements._status;
    _manager = new QNetworkAccessManager;
    return *this;
}
