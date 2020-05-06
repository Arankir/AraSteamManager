#include "Sbans.h"

SBans::SBans(QString a_id, bool a_parallel, QObject *parent) : QObject(parent),_id(a_id){
    _manager = new QNetworkAccessManager();
    if(a_parallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+a_id));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+a_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
    }
}
SBans::SBans(QJsonDocument a_bans, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    if(a_bans.object().value("players").toArray().size()>0){
        _bans=a_bans.object().value("players").toArray();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SBans::SBans(QObject *parent) : QObject(parent),_status(StatusValue::none){
    _manager = new QNetworkAccessManager();
}
SBans::~SBans(){
    delete _manager;
}

void SBans::Set(QString a_id, bool a_parallel){
    _id=a_id;
    if(a_parallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+a_id));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key="+_setting.GetKey()+"&steamids="+a_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SBans::Set(QJsonDocument a_bans){
    if(a_bans.object().value("players").toArray().size()>0){
        _bans=a_bans.object().value("players").toArray();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}

void SBans::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SBans::Load);
    QJsonDocument localBans = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
    Set(localBans);
    emit s_finished(this);
    emit s_finished();
}

void SBans::Update(bool a_parallel){
    Set(_id, a_parallel);
}
