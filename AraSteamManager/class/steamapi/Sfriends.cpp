#include "Sfriends.h"

SFriends::SFriends(QString key, QString id, bool parallel, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, parallel);
}
SFriends::SFriends(QJsonDocument DocFriends){
    manager = new QNetworkAccessManager();
    Set(DocFriends);
}
SFriends::SFriends(){
    manager = new QNetworkAccessManager();
}
SFriends::~SFriends(){
    delete manager;
}

void SFriends::Set(QString key, QString id, bool parallel){
    this->key=key;
    this->id=id;
    if(parallel){
        manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
        connect(manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
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
void SFriends::Set(QJsonDocument DocFriends){
    Clear();
    if(DocFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        friends=DocFriends.object().value("friendslist").toObject().value("friends").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SFriends::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    QJsonDocument DocFriends = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocFriends);
    emit finished(this);
    emit finished();
}

SProfile SFriends::GetProfiles(){
    QEventLoop loop;
    QNetworkAccessManager profmanager;
    connect(&profmanager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    int size=0;
    QJsonArray arr;
    SProfile Profile;
    while(size<friends.size()){
        QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+friends[size++].toObject().value("steamid").toString();
        if(size+99>friends.size()){
            for (;size<friends.size();) {
                Querry+=", "+friends[size++].toObject().value("steamid").toString();
            }
        } else {
            for (int i=0;i<99;i++) {
                Querry+=", "+friends[size++].toObject().value("steamid").toString();
            }
        }
        qDebug()<<"Запрос= "<<Querry;
        QNetworkReply &Reply = *profmanager.get(QNetworkRequest(Querry));
        loop.exec();
        QJsonDocument DocFriends = QJsonDocument::fromJson(Reply.readAll());
        for(int i=0;i<DocFriends.object().value("response").toObject().value("players").toArray().size();i++)
            arr.append(DocFriends.object().value("response").toObject().value("players").toArray().at(i).toObject());
    }
    Profile.Set(arr);
    qDebug()<<"Друзей"<<Profile.GetCount();
    return Profile;
}

void SFriends::Update(bool parallel){
    Set(key,id,parallel);
}

SFriends::SFriends( const SFriends & a){
    friends=a.friends;
    status=a.status;
    id=a.id;
    key=a.key;
    manager = new QNetworkAccessManager;
}

SFriends & SFriends::operator=(const SFriends & friendss) {
    delete manager;
    friends=friendss.friends;
    status=friendss.status;
    id=friendss.id;
    key=friendss.key;
    manager = new QNetworkAccessManager;
    return *this;
}

void SFriends::Clear(){
    friends=QJsonArray();
}
