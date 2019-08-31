#include "steamapilevels.h"

SteamAPILevels::SteamAPILevels(QString key, QString id, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id);
}

SteamAPILevels::SteamAPILevels(QJsonDocument DocBans){
    manager = new QNetworkAccessManager();
    Set(DocBans);
}

SteamAPILevels::SteamAPILevels(){
    manager = new QNetworkAccessManager();
    status="null";
}

SteamAPILevels::~SteamAPILevels(){
    delete manager;
}

void SteamAPILevels::Set(QString key, QString id){
    connect(manager,&QNetworkAccessManager::finished,this,&SteamAPILevels::Load);
    this->key=key;
    this->steamid=id;
    manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+key+"&steamid="+id));
}
void SteamAPILevels::Set(QJsonDocument DocLvls){
    if(DocLvls.object().value("response").toObject().value("player_level").toInt()>0){
        player_level=DocLvls.object().value("response").toObject().value("player_level").toInt();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPILevels::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPILevels::Load);
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocLvls);
    emit finished(this);
    emit finished();
}

int SteamAPILevels::GetPlayer_level(){
    return player_level;
}
QString SteamAPILevels::GetStatus(){
    return status;
}

void SteamAPILevels::Update(){
    Set(key, steamid);
}
