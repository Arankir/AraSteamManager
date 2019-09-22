#include "steamapifriends.h"

SteamAPIFriends::SteamAPIFriends(QString key, QString id, bool parallel, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, parallel);
}
SteamAPIFriends::SteamAPIFriends(QJsonDocument DocFriends){
    manager = new QNetworkAccessManager();
    Set(DocFriends);
}
SteamAPIFriends::SteamAPIFriends(){
    manager = new QNetworkAccessManager();
}
SteamAPIFriends::~SteamAPIFriends(){
    delete manager;
}

void SteamAPIFriends::Set(QString key, QString id, bool parallel){
    this->key=key;
    this->id=id;
    if(parallel){
        manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIFriends::Load);
    } else {
        QNetworkReply *reply = manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        QEventLoop loop;
        connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit finished(this);
        emit finished();
    }
}
void SteamAPIFriends::Set(QJsonDocument DocFriends){
    Clear();
    if(DocFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        friends=DocFriends.object().value("friendslist").toObject().value("friends").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIFriends::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIFriends::Load);
    QJsonDocument DocFriends = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocFriends);
    emit finished(this);
    emit finished();
}

SteamAPIProfile SteamAPIFriends::GetProfiles(){
    QEventLoop loop;
    QNetworkAccessManager profmanager;
    qDebug()<<friends.size();
    connect(&profmanager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+friends[0].toObject().value("steamid").toString();
    for (int i=1;i<friends.size();i++) {
        Querry+=","+friends[i].toObject().value("steamid").toString();
    }
    qDebug()<<Querry;
    QNetworkReply &Reply = *profmanager.get(QNetworkRequest(Querry));
    loop.exec();
    QJsonDocument DocFriends = QJsonDocument::fromJson(Reply.readAll());
    SteamAPIProfile Profile(DocFriends);
    return Profile;
}

void SteamAPIFriends::Update(bool parallel){
    Set(key,id,parallel);
}

SteamAPIFriends::SteamAPIFriends( const SteamAPIFriends & a){
    friends=a.friends;
    status=a.status;
    id=a.id;
    key=a.key;
    manager = new QNetworkAccessManager;
}

SteamAPIFriends & SteamAPIFriends::operator=(const SteamAPIFriends & friendss) {
    delete manager;
    friends=friendss.friends;
    status=friendss.status;
    id=friendss.id;
    key=friendss.key;
    manager = new QNetworkAccessManager;
    return *this;
}

void SteamAPIFriends::Clear(){
    friends=QJsonArray();
}
