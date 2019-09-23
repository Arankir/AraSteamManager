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
    QEventLoop loop;
    connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    this->key=key;
    this->steamid=id;
    QNetworkReply& Reply = *manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+key+"&steamid="+id));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit finished(this);
    emit finished();
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

void SteamAPILevels::Update(){
    Set(key, steamid);
}
