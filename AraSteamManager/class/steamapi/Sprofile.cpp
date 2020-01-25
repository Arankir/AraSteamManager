#include "Sprofile.h"

SProfile::SProfile(QString Aid, bool Aparallel, QueryType Atype, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    if(Aparallel){
        if(Atype==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype==QueryType::vanity){
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
            _profile=localSummapries.object().value("response").toObject().value("players").toArray().at(0).toObject();
            _status=StatusValue::success;
        }
        else {
            _status=StatusValue::error;
            _error="profile is not exist";
        }
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SProfile::SProfile(QJsonObject AobjSummaries){
    _manager = new QNetworkAccessManager();
    _profile=AobjSummaries;
    _status=StatusValue::success;
}
SProfile::SProfile(){
    _manager = new QNetworkAccessManager();
}
SProfile::~SProfile(){
    delete _manager;
}
void SProfile::Set(QString Aid, bool Aparallel, QueryType Atype){
    _id=Aid;
    if(Aparallel){
        if(Atype==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("players").toArray().at(0).toObject());
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SProfile::Set(QJsonObject AobjSummaries){
    Clear();
    _profile=AobjSummaries;
    _status=StatusValue::success;
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
    Set(localSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject());
    emit s_finished(this);
    emit s_finished();
}
void SProfile::Update(bool Aparallel){
    Set(_id, Aparallel, QueryType::url);
}
void SProfile::Clear(){
    _profile=QJsonObject();
    _status=StatusValue::none;
}
SProfile::SProfile( const SProfile & AnewProfile){
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _error=AnewProfile._error;
    _manager = new QNetworkAccessManager;
}
SProfile & SProfile::operator=(const SProfile & AnewProfile){
    delete _manager;
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _error=AnewProfile._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
const bool &SProfile::operator<(const SProfile &Aprofile){
    static const bool b=_profile.value("personaname").toString().toLower()<Aprofile._profile.value("personaname").toString().toLower();
    return b;
}

SProfiles::SProfiles(QString Aid, bool Aparallel, QueryType Atype, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    if(Aparallel){
        if(Atype==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
            loop.exec();
            _id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            delete reply;
        }
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QJsonDocument localSummaries = QJsonDocument::fromJson(reply->readAll());
        if(localSummaries.object().value("response").toObject().value("players").toArray().size()>0){
            _profile.resize(localSummaries.object().value("response").toObject().value("players").toArray().size());
            for(int i=0;i<localSummaries.object().value("response").toObject().value("players").toArray().size();i++)
                _profile[i]=SProfile(localSummaries.object().value("response").toObject().value("players").toArray().at(i).toObject());
            _status=StatusValue::success;
        }
        else {
            _status=StatusValue::error;
            _error="profile is not exist";
        }
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SProfiles::SProfiles(QJsonDocument AdocSummaries){
    _manager = new QNetworkAccessManager();
    if(AdocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        _profile.resize(AdocSummaries.object().value("response").toObject().value("players").toArray().size());
        for(int i=0;i<AdocSummaries.object().value("response").toObject().value("players").toArray().size();i++)
            _profile[i]=SProfile(AdocSummaries.object().value("response").toObject().value("players").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SProfiles::SProfiles(QJsonArray AarrSummaries){
    _manager = new QNetworkAccessManager();
    _profile.resize(AarrSummaries.size());
    for(int i=0;i<_profile.size();i++)
        _profile[i]=SProfile(AarrSummaries[i].toObject());
    _status=StatusValue::success;
}
SProfiles::SProfiles(QJsonObject AobjSummaries){
    _manager = new QNetworkAccessManager();
    _profile.push_back(SProfile(AobjSummaries));
    _status=StatusValue::success;
}
SProfiles::SProfiles(){
    _manager = new QNetworkAccessManager();
}
SProfiles::~SProfiles(){
    delete _manager;
}
void SProfiles::Set(QString Aid, bool Aparallel, QueryType Atype){
    _id=Aid;
    if(Aparallel){
        if(Atype==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+Aid+"&url_type=1"));
        } else if(Atype==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+Aid));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(Atype==QueryType::vanity){
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
void SProfiles::Set(QJsonDocument AdocSummaries){
    Clear();
    if(AdocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        _profile.resize(AdocSummaries.object().value("response").toObject().value("players").toArray().size());
        for(int i=0;i<AdocSummaries.object().value("response").toObject().value("players").toArray().size();i++)
            _profile[i]=SProfile(AdocSummaries.object().value("response").toObject().value("players").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SProfiles::Set(QJsonObject AobjSummaries){
    Clear();
    _profile.push_back(AobjSummaries);
    _status=StatusValue::success;
}
void SProfiles::Set(QJsonArray AarrSummaries){
    Clear();
    _profile.resize(AarrSummaries.size());
    for(int i=0;i<AarrSummaries.size();i++)
        _profile[i]=SProfile(AarrSummaries[i].toObject());
    _status=StatusValue::success;
}
void SProfiles::LoadVanity(QNetworkReply *Areply){
    QJsonDocument localDoc = QJsonDocument::fromJson(Areply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
    connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
}
void SProfiles::LoadURL(QNetworkReply *Areply){
    QJsonDocument localSummaries = QJsonDocument::fromJson(Areply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
    Areply->deleteLater();
    Set(localSummaries);
    emit s_finished(this);
    emit s_finished();
}
void SProfiles::Update(bool Aparallel){
    Set(_id, Aparallel, QueryType::url);
}
void SProfiles::Sort(){
    //Переделать нормально
    std::list<SProfile> list = _profile.toList().toStdList();
    list.sort();
    _profile=QVector<SProfile>::fromList(QList<SProfile>::fromStdList(list));
}
void SProfiles::Clear(){
    _profile.clear();
    _status=StatusValue::none;
}
SProfiles::SProfiles( const SProfiles & AnewProfile){
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _error=AnewProfile._error;
    _manager = new QNetworkAccessManager;
}
SProfiles & SProfiles::operator=(const SProfiles & AnewProfile){
    delete _manager;
    _profile=AnewProfile._profile;
    _id=AnewProfile._id;
    _status=AnewProfile._status;
    _error=AnewProfile._error;
    _manager = new QNetworkAccessManager;
    return *this;
}

