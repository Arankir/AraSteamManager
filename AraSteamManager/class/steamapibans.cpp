#include "steamapibans.h"

SteamAPIBans::SteamAPIBans(QString key, QString id, bool parallel, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, parallel);
}
SteamAPIBans::SteamAPIBans(QJsonDocument DocBans){
    manager = new QNetworkAccessManager();
    Set(DocBans);
}
SteamAPIBans::SteamAPIBans(){
    manager = new QNetworkAccessManager();
    status="null";
}
SteamAPIBans::~SteamAPIBans(){
    delete manager;
}

void SteamAPIBans::Set(QString key, QString id, bool parallel){
    this->key=key;
    this->id=id;
    if(parallel){
        connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIBans::Load);
        manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+key+"&steamids="+id));
    } else {
        QEventLoop loop;
        connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+key+"&steamids="+id));
        loop.exec();
        disconnect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit finished(this);
        emit finished();
    }
}
void SteamAPIBans::Set(QJsonDocument DocBans){
    if(DocBans.object().value("response").toObject().value("players").toArray().size()>0){
        bans=DocBans.object().value("response").toObject().value("players").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIBans::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIBans::Load);
    QJsonDocument DocBans = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocBans);
    emit finished(this);
    emit finished();
}

void SteamAPIBans::Update(bool parallel){
    Set(key, id, parallel);
}
