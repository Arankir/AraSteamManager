#include "Sbans.h"

SBans::SBans(QString key, QString id, bool parallel, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, parallel);
}
SBans::SBans(QJsonDocument DocBans){
    manager = new QNetworkAccessManager();
    Set(DocBans);
}
SBans::SBans(){
    manager = new QNetworkAccessManager();
    status="null";
}
SBans::~SBans(){
    delete manager;
}

void SBans::Set(QString key, QString id, bool parallel){
    this->key=key;
    this->id=id;
    if(parallel){
        connect(manager,&QNetworkAccessManager::finished,this,&SBans::Load);
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
void SBans::Set(QJsonDocument DocBans){
    if(DocBans.object().value("players").toArray().size()>0){
        bans=DocBans.object().value("players").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SBans::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SBans::Load);
    QJsonDocument DocBans = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocBans);
    emit finished(this);
    emit finished();
}

void SBans::Update(bool parallel){
    Set(key, id, parallel);
}
