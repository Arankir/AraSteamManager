#include "Sprofile.h"

#define SProfileStart {
SProfile::SProfile(QString a_id, bool a_parallel, QueryType a_type, QObject *parent) : QObject(parent),_id(a_id){
    _manager = new QNetworkAccessManager();
    if(a_parallel){
        if(a_type==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
        } else if(a_type==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+a_id));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(a_type==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
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
            _error=reply->readAll();
        }
        delete reply;
    }
}
SProfile::SProfile(QJsonObject a_objSummaries, QObject *parent) : QObject(parent),_profile(a_objSummaries),_status(StatusValue::success){
    _manager = new QNetworkAccessManager();
}
SProfile::SProfile(QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
}
SProfile::~SProfile(){
    delete _manager;
}
void SProfile::Set(QString a_id, bool a_parallel, QueryType a_type){
    _id=a_id;
    if(a_parallel){
        if(a_type==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
        } else if(a_type==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+a_id));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(a_type==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
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
void SProfile::Set(QJsonObject a_objSummaries){
    Clear();
    _profile=a_objSummaries;
    _status=StatusValue::success;
}
void SProfile::LoadVanity(QNetworkReply *a_reply){
    QJsonDocument localDoc = QJsonDocument::fromJson(a_reply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadVanity);
    connect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
}
void SProfile::LoadURL(QNetworkReply *a_reply){
    QJsonDocument localSummaries = QJsonDocument::fromJson(a_reply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfile::LoadURL);
    a_reply->deleteLater();
    Set(localSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject());
    emit s_finished(this);
    emit s_finished();
}
void SProfile::Update(bool a_parallel){
    Set(_id, a_parallel, QueryType::url);
}
void SProfile::Clear(){
    _profile=QJsonObject();
    _status=StatusValue::none;
}
SProfile::SProfile( const SProfile & a_newProfile){
    _profile=a_newProfile._profile;
    _id=a_newProfile._id;
    _status=a_newProfile._status;
    _error=a_newProfile._error;
    _manager = new QNetworkAccessManager;
}
SProfile & SProfile::operator=(const SProfile & a_newProfile){
    delete _manager;
    _profile=a_newProfile._profile;
    _id=a_newProfile._id;
    _status=a_newProfile._status;
    _error=a_newProfile._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
const bool &SProfile::operator<(const SProfile &a_profile){
    static const bool b=_profile.value("personaname").toString().toLower()<a_profile._profile.value("personaname").toString().toLower();
    return b;
}
#define SProfileEnd }
#define SProfilesStart {
SProfiles::SProfiles(QString a_id, bool a_parallel, QueryType a_type, QObject *parent) : QObject(parent),_id(a_id){
    _manager = new QNetworkAccessManager();
    _id=a_id;
    if(a_parallel){
        if(a_type==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
        } else if(a_type==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+a_id));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(a_type==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
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
    }
}
SProfiles::SProfiles(QJsonDocument a_docSummaries, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    if(a_docSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        _profile.resize(a_docSummaries.object().value("response").toObject().value("players").toArray().size());
        for(int i=0;i<a_docSummaries.object().value("response").toObject().value("players").toArray().size();i++)
            _profile[i]=SProfile(a_docSummaries.object().value("response").toObject().value("players").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SProfiles::SProfiles(QJsonArray a_arrSummaries, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _profile.resize(a_arrSummaries.size());
    for(int i=0;i<_profile.size();i++)
        _profile[i]=SProfile(a_arrSummaries[i].toObject());
    _status=StatusValue::success;
}
SProfiles::SProfiles(QJsonObject a_objSummaries, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _profile.push_back(SProfile(a_objSummaries));
    _status=StatusValue::success;
}
SProfiles::SProfiles(QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
}
SProfiles::~SProfiles(){
    delete _manager;
}
void SProfiles::Set(QString a_id, bool a_parallel, QueryType a_type){
    _id=a_id;
    if(a_parallel){
        if(a_type==QueryType::vanity){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
            _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
        } else if(a_type==QueryType::url){
            connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
            _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+a_id));
        }
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        if(a_type==QueryType::vanity){
            QNetworkReply *reply = _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+a_id+"&url_type=1"));
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
void SProfiles::Set(QJsonDocument a_docSummaries){
    Clear();
    if(a_docSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        _profile.resize(a_docSummaries.object().value("response").toObject().value("players").toArray().size());
        for(int i=0;i<a_docSummaries.object().value("response").toObject().value("players").toArray().size();i++)
            _profile[i]=SProfile(a_docSummaries.object().value("response").toObject().value("players").toArray().at(i).toObject());
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SProfiles::Set(QJsonObject a_objSummaries){
    Clear();
    _profile.push_back(a_objSummaries);
    _status=StatusValue::success;
}
void SProfiles::Set(QJsonArray a_arrSummaries){
    Clear();
    _profile.resize(a_arrSummaries.size());
    for(int i=0;i<a_arrSummaries.size();i++)
        _profile[i]=SProfile(a_arrSummaries[i].toObject());
    _status=StatusValue::success;
}
void SProfiles::LoadVanity(QNetworkReply *a_reply){
    QJsonDocument localDoc = QJsonDocument::fromJson(a_reply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadVanity);
    connect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id));
}
void SProfiles::LoadURL(QNetworkReply *a_reply){
    QJsonDocument localSummaries = QJsonDocument::fromJson(a_reply->readAll());
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SProfiles::LoadURL);
    a_reply->deleteLater();
    Set(localSummaries);
    emit s_finished(this);
    emit s_finished();
}
void SProfiles::Update(bool a_parallel){
    Set(_id, a_parallel, QueryType::url);
}
void SProfiles::Sort(){
    //Переделать нормально
    //std::list<SProfile> list = _profile.toList().toStdList();
    std::list<SProfile> list(_profile.begin(),_profile.end());
    list.sort([](const SProfile &s1, const SProfile &s2)-> const bool {
        if(QString::compare(s1.GetPersonaname().toLower(),s2.GetPersonaname().toLower())<0)
            return true;
        else
            return false;
    });
    //_profile=QVector<SProfile>::fromList(QList<SProfile>::fromStdList(list));
    _profile=QVector<SProfile>(list.begin(),list.end());

}
void SProfiles::Clear(){
    _profile.clear();
    _status=StatusValue::none;
}
SProfiles::SProfiles( const SProfiles &a_newProfile){
    _profile=a_newProfile._profile;
    _id=a_newProfile._id;
    _status=a_newProfile._status;
    _error=a_newProfile._error;
    _manager = new QNetworkAccessManager;
}
SProfiles & SProfiles::operator=(const SProfiles &a_newProfile){
    delete _manager;
    _profile=a_newProfile._profile;
    _id=a_newProfile._id;
    _status=a_newProfile._status;
    _error=a_newProfile._error;
    _manager = new QNetworkAccessManager;
    return *this;
}
SProfile &SProfiles::operator[](const int &a_index){
    return _profile[a_index];
}
#define SProfilesEnd }
