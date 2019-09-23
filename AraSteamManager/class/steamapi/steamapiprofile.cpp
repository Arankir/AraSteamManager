#include "steamapiprofile.h"

SteamAPIProfile::SteamAPIProfile(QString key, QString id, bool parallel, QString type, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, parallel, type);
}
SteamAPIProfile::SteamAPIProfile(QJsonDocument DocSummaries){
    manager = new QNetworkAccessManager();
    Set(DocSummaries);
}
SteamAPIProfile::SteamAPIProfile(QJsonObject ObjSummaries){
    manager = new QNetworkAccessManager();
    Set(ObjSummaries);
}
SteamAPIProfile::SteamAPIProfile(){
    manager = new QNetworkAccessManager();
}
SteamAPIProfile::~SteamAPIProfile(){
    delete manager;
}

void SteamAPIProfile::Set(QString key, QString id, bool parallel, QString type){
    this->key=key;
    this->id=id;
    if(type=="vanity"){
        if(parallel){
            connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadVanity);
            manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+key+"&vanityurl="+id+"&url_type=1"));
        } else {
            QNetworkReply *reply = manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+key+"&vanityurl="+id+"&url_type=1"));
            QEventLoop loop;
            connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
            loop.exec();
            QString id=QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject().value("steamid").toString();
            reply = manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
            loop.exec();
            disconnect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
            Set(QJsonDocument::fromJson(reply->readAll()));
            delete reply;
            emit finished(this);
            emit finished();
        }
    } else {
        if(type=="url"){
            if(parallel){
                connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
                manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
            } else {
                QEventLoop loop;
                connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
                QNetworkReply *reply = manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
                loop.exec();
                disconnect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
                Set(QJsonDocument::fromJson(reply->readAll()));
                delete reply;
                emit finished(this);
                emit finished();
            }
        } else {
            status="error: unknown type";
            emit finished(this);
            emit finished();
        }
    }
}
void SteamAPIProfile::Set(QJsonDocument DocSummaries){
    Clear();
    if(DocSummaries.object().value("response").toObject().value("players").toArray().size()>0){
        profile=DocSummaries.object().value("response").toObject().value("players").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}
void SteamAPIProfile::Set(QJsonObject ObjSummaries){
    Clear();
    profile.push_back(ObjSummaries);
    status="success";
}

void SteamAPIProfile::LoadVanity(QNetworkReply *Reply){
    QJsonDocument Doc = QJsonDocument::fromJson(Reply->readAll());
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadVanity);
    connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
    QString id=Doc.object().value("response").toObject().value("steamid").toString();
    manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+id));
}
void SteamAPIProfile::LoadURL(QNetworkReply *Reply){
    QJsonDocument DocSummaries = QJsonDocument::fromJson(Reply->readAll());
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIProfile::LoadURL);
    Reply->deleteLater();
    Set(DocSummaries);
    emit finished(this);
    emit finished();
}

void SteamAPIProfile::Update(bool parallel){
    Set(key, id, parallel, "url");
}
void SteamAPIProfile::Clear(){
    profile=QJsonArray();
    status="none";
}

SteamAPIProfile::SteamAPIProfile( const SteamAPIProfile & a){
    profile=a.profile;
    key=a.key;
    id=a.id;
    status=a.status;
    manager = new QNetworkAccessManager;
}
SteamAPIProfile & SteamAPIProfile::operator=(const SteamAPIProfile & profil){
    delete manager;
    profile=profil.profile;
    key=profil.key;
    id=profil.id;
    status=profil.status;
    manager = new QNetworkAccessManager;
    return *this;
}

