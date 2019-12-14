#include "Sbans.h"

SBans::SBans(QString AKey, QString AID, bool AParallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _key=AKey;
    _id=AID;
    if(AParallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+AKey+"&steamids="+AID));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+AKey+"&steamids="+AID));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SBans::SBans(QJsonDocument ABans){
    _manager = new QNetworkAccessManager();
    if(ABans.object().value("players").toArray().size()>0){
        _bans=ABans.object().value("players").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SBans::SBans(){
    _manager = new QNetworkAccessManager();
    _status="null";
}
SBans::~SBans(){
    delete _manager;
}

void SBans::Set(QString AKey, QString AID, bool AParallel){
    _key=AKey;
    _id=AID;
    if(AParallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+AKey+"&steamids="+AID));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+AKey+"&steamids="+AID));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SBans::Set(QJsonDocument ABans){
    if(ABans.object().value("players").toArray().size()>0){
        _bans=ABans.object().value("players").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SBans::Load(QNetworkReply *AReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
    QJsonDocument localBans = QJsonDocument::fromJson(AReply->readAll());
    AReply->deleteLater();
    Set(localBans);
    emit s_finished(this);
    emit s_finished();
}

void SBans::Update(bool AParallel){
    Set(_key, _id, AParallel);
}
