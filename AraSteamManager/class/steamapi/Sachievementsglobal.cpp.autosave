#include "Sachievementsglobal.h"

SAchievementsGlobal::SAchievementsGlobal(QString key, QString appid, QString language, QObject* parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, appid, language);
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument DocAchievements){
    manager = new QNetworkAccessManager();
    Set(DocAchievements);
}
SAchievementsGlobal::SAchievementsGlobal(){
    manager = new QNetworkAccessManager();
}
SAchievementsGlobal::~SAchievementsGlobal(){
    delete manager;
}

void SAchievementsGlobal::Set(QString key, QString appid, QString language){
connect(manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
this->key=key;
this->appid=appid;
this->language=language;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l="+language));
}
void SAchievementsGlobal::Set(QJsonDocument DocAchievements){
    Clear();
    if(DocAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        gamename=DocAchievements.object().value("game").toObject().value("gameName").toString();
        gameversion=DocAchievements.object().value("game").toObject().value("gameVersion").toString();
        count=DocAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<count;i++) {
            achievements.push_back(SAchievementGlobal(DocAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i).toObject()));
        }
        status="success";
    }
    else {
        status="error: game is not exist";
    }
}

void SAchievementsGlobal::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    QJsonDocument DocAchievements = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocAchievements);
    qDebug()<<"Global load";
    emit finished(*this);
    emit finished();
}

void SAchievementsGlobal::Update(){
    Set(key,appid,language);
}
void SAchievementsGlobal::Clear(){
    achievements.clear();
    count=0;
}

SAchievementsGlobal::SAchievementsGlobal( const SAchievementsGlobal & achievementss){
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
SAchievementsGlobal & SAchievementsGlobal::operator=(const SAchievementsGlobal & achievementss) {
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
    return* this;
}
