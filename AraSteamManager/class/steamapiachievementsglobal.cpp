#include "steamapiachievementsglobal.h"

SteamAPIAchievementsGlobal::SteamAPIAchievementsGlobal(QString key, QString appid, QString language, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid, language);
}
SteamAPIAchievementsGlobal::SteamAPIAchievementsGlobal(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SteamAPIAchievementsGlobal::SteamAPIAchievementsGlobal(){
    manager = new QNetworkAccessManager();
}
SteamAPIAchievementsGlobal::~SteamAPIAchievementsGlobal(){
    delete manager;
}

void SteamAPIAchievementsGlobal::Set(QString key, QString appid, QString language){
connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsGlobal::Load);
this->key=key;
this->appid=appid;
this->language=language;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l="+language));
}
void SteamAPIAchievementsGlobal::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("game").toObject().value("availibleGameStats").toObject().value("achievements").toArray().size()>0&&DocAchievements.object().value("game").toObject().value("gameVersion").toString()!=gameversion){
        gamename=DocAchievements.object().value("game").toObject().value("gameName").toString();
        gameversion=DocAchievements.object().value("game").toObject().value("gameVersion").toString();
        count=DocAchievements.object().value("game").toObject().value("availibleGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SteamAPIAchievementGlobal(DocAchievements.object().value("game").toObject().value("availibleGameStats").toObject().value("achievements").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIAchievementsGlobal::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIAchievementsGlobal::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    emit finished(this);
    emit finished();
}

SteamAPIAchievementGlobal SteamAPIAchievementsGlobal::GetAchievementInfo(int index){
    return achievements[index];
}
QString SteamAPIAchievementsGlobal::GetApiname(int index){
    return achievements[index].GetApiname();
}
int SteamAPIAchievementsGlobal::GetDefaultvalue(int index){
    return achievements[index].GetDefaultvalue();
}
QString SteamAPIAchievementsGlobal::GetDisplayname(int index){
    return achievements[index].GetDisplayname();
}
int SteamAPIAchievementsGlobal::GetHidden(int index){
    return achievements[index].GetHidden();
}
QString SteamAPIAchievementsGlobal::GetDescription(int index){
    return achievements[index].GetDescription();
}
QString SteamAPIAchievementsGlobal::GetIcon(int index){
    return achievements[index].GetIcon();
}
QString SteamAPIAchievementsGlobal::GetIcongray(int index){
    return achievements[index].GetIcongray();
}
QString SteamAPIAchievementsGlobal::GetAppid(){
    return appid;
}
QString SteamAPIAchievementsGlobal::GetGamename(){
    return gamename;
}
QString SteamAPIAchievementsGlobal::GetGameversion(){
    return gameversion;
}
QString SteamAPIAchievementsGlobal::GetStatus(){
    return status;
}

int SteamAPIAchievementsGlobal::GetAchievementsCount(){
    return count;
}

void SteamAPIAchievementsGlobal::Update(){
    Set(key,appid,language);
}

SteamAPIAchievementsGlobal::SteamAPIAchievementsGlobal( const SteamAPIAchievementsGlobal & achievementss){
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    language=achievementss.language;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    gameversion=achievementss.gameversion;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
}

SteamAPIAchievementsGlobal & SteamAPIAchievementsGlobal::operator=(const SteamAPIAchievementsGlobal & achievementss) {
    delete manager;
    achievements=achievementss.achievements;
    appid=achievementss.appid;
    language=achievementss.language;
    key=achievementss.key;
    count=achievementss.count;
    gamename=achievementss.gamename;
    gameversion=achievementss.gameversion;
    status=achievementss.status;
    manager = new QNetworkAccessManager;
    return *this;
}

void SteamAPIAchievementsGlobal::Clear(){
    achievements.clear();
    count=0;
}
