#include "Sachievementsglobal.h"

SAchievementsGlobal::SAchievementsGlobal(QString Aappid, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+Aappid+"&l="+tr("russian")));
}
SAchievementsGlobal::SAchievementsGlobal(QJsonDocument Aachievements){
    _manager = new QNetworkAccessManager();
    if(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=Aachievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=Aachievements.object().value("game").toObject().value("gameVersion").toString();
        _count=Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementGlobal(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i++).toObject())));
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

void SAchievementsGlobal::Set(QString Aappid){
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    _appid=Aappid;
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+_setting.GetKey()+"&appid="+Aappid+"&l="+tr("russian")));
}
void SAchievementsGlobal::Set(QJsonDocument Aachievements){
    Clear();
    if(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size()>0){
        _gameName=Aachievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion=Aachievements.object().value("game").toObject().value("gameVersion").toString();
        _count=Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().size();
        for (int i=0;i<_count;
             _achievements.push_back(SAchievementGlobal(Aachievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(i++).toObject())));
        _status="success";
    }
    else {
        _status="error: game is not exist";
    }
}

void SAchievementsGlobal::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::Load);
    QJsonDocument localAchievements = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localAchievements);
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

SAchievementsGlobal::SAchievementsGlobal(const SAchievementsGlobal & AnewAchievements){
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _count=AnewAchievements._count;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _status=AnewAchievements._status;
    _manager = new QNetworkAccessManager;
}
SAchievementsGlobal & SAchievementsGlobal::operator=(const SAchievementsGlobal & AnewAchievements){
    delete _manager;
    _achievements=AnewAchievements._achievements;
    _appid=AnewAchievements._appid;
    _count=AnewAchievements._count;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _status=AnewAchievements._status;
    _manager = new QNetworkAccessManager;
    return *this;
}
