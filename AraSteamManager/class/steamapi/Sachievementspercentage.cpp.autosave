#include "Sachievementspercentage.h"

SAchievementsPercentage::SAchievementsPercentage(QString key, QString appid, QObject* parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid);
}
SAchievementsPercentage::SAchievementsPercentage(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SAchievementsPercentage::SAchievementsPercentage(){
    manager = new QNetworkAccessManager();
}
SAchievementsPercentage::~SAchievementsPercentage(){
    delete manager;
}

void SAchievementsPercentage::Set(QString key, QString appid){
connect(manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
this->key=key;
this->appid=appid;
manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+appid));
}
void SAchievementsPercentage::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size()>0){
        count=DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SAchievementPercentage(DocAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: game is not exist";
    }
}

void SAchievementsPercentage::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    qDebug()<<"Percent load";
    emit finished(*this);
    emit finished();
}

void SAchievementsPercentage::Update(){
    Set(key,appid);
}
void SAchievementsPercentage::Clear(){
    achievements.clear();
    count=0;
}

SAchievementsPercentage::SAchievementsPercentage( const SAchievementsPercentage & achievementss){
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    key=achievementss.key;
    count=achievementss.count;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
}
SAchievementsPercentage & SAchievementsPercentage::operator=(const SAchievementsPercentage & achievementss) {
    delete manager;
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    key=achievementss.key;
    count=achievementss.count;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
    return* this;
}
