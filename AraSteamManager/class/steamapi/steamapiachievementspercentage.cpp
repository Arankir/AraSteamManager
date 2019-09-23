#include "steamapiachievementspercentage.h"

SteamAPIAchievementsPercentage::SteamAPIAchievementsPercentage(QString key, QString appid, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid);
}
SteamAPIAchievementsPercentage::SteamAPIAchievementsPercentage(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SteamAPIAchievementsPercentage::SteamAPIAchievementsPercentage(){
    manager = new QNetworkAccessManager();
}
SteamAPIAchievementsPercentage::~SteamAPIAchievementsPercentage(){
    delete manager;
}

void SteamAPIAchievementsPercentage::Set(QString key, QString appid){
connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsPercentage::Load);
this->key=key;
this->appid=appid;
manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+appid));
}
void SteamAPIAchievementsPercentage::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        count=DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SteamAPIAchievementPercentage(DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: game is not exist";
    }
}

void SteamAPIAchievementsPercentage::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsPercentage::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    emit finished(this);
    emit finished();
}

void SteamAPIAchievementsPercentage::Update(){
    Set(key,appid);
}
void SteamAPIAchievementsPercentage::Clear(){
    achievements.clear();
    count=0;
}

SteamAPIAchievementsPercentage::SteamAPIAchievementsPercentage( const SteamAPIAchievementsPercentage & achievementss){
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    key=achievementss.key;
    count=achievementss.count;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
}
SteamAPIAchievementsPercentage & SteamAPIAchievementsPercentage::operator=(const SteamAPIAchievementsPercentage & achievementss) {
    delete manager;
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    key=achievementss.key;
    count=achievementss.count;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
    return *this;
}
