#include "Sbans.h"

SBans::SBans(QString Aid, bool Aparallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    if(Aparallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+Aid));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+Aid));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SBans::SBans(QJsonDocument Abans){
    _manager = new QNetworkAccessManager();
    if(Abans.object().value("players").toArray().size()>0){
        _bans=Abans.object().value("players").toArray();
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

void SBans::Set(QString Aid, bool Aparallel){
    _id=Aid;
    if(Aparallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+Aid));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+Aid));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SBans::Set(QJsonDocument Abans){
    if(Abans.object().value("players").toArray().size()>0){
        _bans=Abans.object().value("players").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SBans::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
    QJsonDocument localBans = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localBans);
    emit s_finished(this);
    emit s_finished();
}

void SBans::Update(bool Aparallel){
    Set(_id, Aparallel);
}
