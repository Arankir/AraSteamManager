#include "Sachievementsglobal.h"

SAchievementsGlobal::SAchievementsGlobal(QString AAppid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=AAppid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+AAppid+"&l="+tr("russian")));
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument AAchievements){
    _manager = new QNetworkAccessManager();
    if(AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=AAchievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=AAchievements.object().value("game").toObject().value("gameVersion").toString();
        _count=AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementGlobal(AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: game is not exist";
    }
}
SAchievementsGlobal::SAchievementsGlobal(){
    _manager = new QNetworkAccessManager();
}
SAchievementsGlobal::~SAchievementsGlobal(){
    delete _manager;
}

void SAchievementsGlobal::Set(QString AAppid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=AAppid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+AAppid+"&l="+tr("russian")));
}
void SAchievementsGlobal::Set(QJsonDocument AAchievements){
    Clear();
    if(AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=AAchievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=AAchievements.object().value("game").toObject().value("gameVersion").toString();
        _count=AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementGlobal(AAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: game is not exist";
    }
}

void SAchievementsGlobal::Load(QNetworkReply *AReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(AReply->readAll());
    AReply->deleteLater();
    Set(localAchievements);
    qDebug()<<"Global load";
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsGlobal::Update(){
    Set(_appid);
}
void SAchievementsGlobal::Clear(){
    _achievements.clear();
    _count=0;
}

SAchievementsGlobal::SAchievementsGlobal( const SAchievementsGlobal & ANewAchievements){
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _count=ANewAchievements._count;
    _gameName=ANewAchievements._gameName;
    _gameVersion=ANewAchievements._gameVersion;
    _status=ANewAchievements._status;
    _manager = new QNetworkAccessManager;
}
SAchievementsGlobal & SAchievementsGlobal::operator=(const SAchievementsGlobal & ANewAchievements){
    delete _manager;
    _achievements=ANewAchievements._achievements;
    _appid=ANewAchievements._appid;
    _count=ANewAchievements._count;
    _gameName=ANewAchievements._gameName;
    _gameVersion=ANewAchievements._gameVersion;
    _status=ANewAchievements._status;
    _manager = new QNetworkAccessManager;
    return *this;
}
