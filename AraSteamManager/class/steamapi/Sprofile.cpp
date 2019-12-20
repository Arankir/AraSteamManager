#include "Sprofile.h"

SProfile::SProfile(QString Aid, bool Aparallel, QString Atype, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    if(Aparallel){
        if(Atype=="vanity"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype=="url"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype=="vanity"){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
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
SProfile::SProfile(QJsonDocument AdocSummaries){
    _manager = new QNetworkAccessManager();
    if(AdocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        for(int i=0;i<AdocSummaries.object().value("response").toObject().value("players").toArray().size();
            _profile.push_back(AdocSummaries.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SProfile::SProfile(QJsonArray AarrSummaries){
    _manager = new QNetworkAccessManager();
    _profile=AarrSummaries;
    _status="success";
}
SProfile::SProfile(QJsonObject AobjSummaries){
    _manager = new QNetworkAccessManager();
    _profile.push_back(AobjSummaries);
    _status="success";
}
SProfile::SProfile(){
    _manager = new QNetworkAccessManager();
}
SProfile::~SProfile(){
    delete _manager;
}

void SProfile::Set(QString Aid, bool Aparallel, QString Atype){
    _id=Aid;
    if(Aparallel){
        if(Atype=="vanity"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype=="url"){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype=="vanity"){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SProfile::Set(QJsonDocument AdocSummaries){
    Clear();
    if(AdocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        for(int i=0;i<AdocSummaries.object().value("response").toObject().value("players").toArray().size();
            _profile.push_back(AdocSummaries.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
void SProfile::Set(QJsonObject AobjSummaries){
    Clear();
    _profile.push_back(AobjSummaries);
    _status="success";
}
void SProfile::Set(QJsonArray AarrSummaries){
    Clear();
    _profile=AarrSummaries;
    _status="success";
}

void SProfile::LoadVanity(QNetworkReply *Areply){
    QJsonDocument localDoc = QJsonDocument::fromJson(Areply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
    connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
}
void SProfile::LoadURL(QNetworkReply *Areply){
    QJsonDocument localSummaries = QJsonDocument::fromJson(Areply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    Areply->deleteLater();
    Set(localSummaries);
    emit s_finished(this);
    emit s_finished();
}

void SProfile::Update(bool Aparallel){
    Set(_id, Aparallel, "url");
}
void SProfile::Clear(){
    _profile=QJsonArray();
    _status="none";
}

SProfile::SProfile( const SProfile & AnewProfile){
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _manager = new QNetworkAccessManager;
}
SProfile & SProfile::operator=(const SProfile & AnewProfile){
    delete _manager;
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _manager = new QNetworkAccessManager;
    return *this;
}

