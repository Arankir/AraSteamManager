#include "Sprofile.h"

SProfile::SProfile(QString AKey, QString AID, bool AParallel, QString AType, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _key=AKey;
    _id=AID;
    if(AParallel){
        if(AType=="vanity"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+AKey+"&vanityurl="+AID+"&url_type=1"));
        } else if(AType=="url"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+AKey+"&steamids="+AID));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(AType=="vanity"){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+AKey+"&vanityurl="+AID+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+AKey+"&steamids="+_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QJsonDocument localSummapries = QJsonDocument::fromJson(reply->readAll());
        if(localSummapries.object().value("response").toObject().value("players").toArray().size()>0){
            for(int i=0;i<localSummapries.object().value("response").toObject().value("players").toArray().size();
                _profile.push_back(localSummapries.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
            _status="success";
        }
        else {
            _status="error: profile is not exist";
        }
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SProfile::SProfile(QJsonDocument ADocSummaries){
    _manager = new QNetworkAccessManager();
    if(ADocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        for(int i=0;i<ADocSummaries.object().value("response").toObject().value("players").toArray().size();
            _profile.push_back(ADocSummaries.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SProfile::SProfile(QJsonArray AArrSummaries){
    _manager = new QNetworkAccessManager();
    _profile=AArrSummaries;
    _status="success";
}
SProfile::SProfile(QJsonObject AObjSummaries){
    _manager = new QNetworkAccessManager();
    _profile.push_back(AObjSummaries);
    _status="success";
}
SProfile::SProfile(){
    _manager = new QNetworkAccessManager();
}
SProfile::~SProfile(){
    delete _manager;
}

void SProfile::Set(QString AKey, QString AID, bool AParallel, QString AType){
    _key=AKey;
    _id=AID;
    if(AParallel){
        if(AType=="vanity"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+AKey+"&vanityurl="+AID+"&url_type=1"));
        } else if(AType=="url"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+AKey+"&steamids="+AID));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(AType=="vanity"){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+AKey+"&vanityurl="+AID+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+AKey+"&steamids="+_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SProfile::Set(QJsonDocument ADocSummaries){
    Clear();
    if(ADocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        for(int i=0;i<ADocSummaries.object().value("response").toObject().value("players").toArray().size();
            _profile.push_back(ADocSummaries.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
void SProfile::Set(QJsonObject AObjSummaries){
    Clear();
    _profile.push_back(AObjSummaries);
    _status="success";
}
void SProfile::Set(QJsonArray AArrSummaries){
    Clear();
    _profile=AArrSummaries;
    _status="success";
}

void SProfile::LoadVanity(QNetworkReply *AReply){
    QJsonDocument localDoc = QJsonDocument::fromJson(AReply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
    connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_key+"&steamids="+_id));
}
void SProfile::LoadURL(QNetworkReply *AReply){
    QJsonDocument localSummaries = QJsonDocument::fromJson(AReply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    AReply->deleteLater();
    Set(localSummaries);
    emit s_finished(this);
    emit s_finished();
}

void SProfile::Update(bool AParallel){
    Set(_key, _id, AParallel, "url");
}
void SProfile::Clear(){
    _profile=QJsonArray();
    _status="none";
}

SProfile::SProfile( const SProfile & ANewProfile){
    _profile=ANewProfile._profile;
    _key=ANewProfile._key;
    _id=ANewProfile._id;
    _status=ANewProfile._status;
    _manager = new QNetworkAccessManager;
}
SProfile & SProfile::operator=(const SProfile & ANewProfile){
    delete _manager;
    _profile=ANewProfile._profile;
    _key=ANewProfile._key;
    _id=ANewProfile._id;
    _status=ANewProfile._status;
    _manager = new QNetworkAccessManager;
    return *this;
}

