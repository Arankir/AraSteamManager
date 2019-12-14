#include "Sfriends.h"

SFriends::SFriends(QString AKey, QString AID, bool AParallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _key=AKey;
    _id=AID;
    if(AParallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+AKey+"&steamid="+AID+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+AKey+"&steamid="+AID+"&relationship=friend"));
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SFriends::SFriends(QJsonDocument AFriends){
    _manager = new QNetworkAccessManager();
    if(AFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        _friends=AFriends.object().value("friendslist").toObject().value("friends").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SFriends::SFriends(){
    _manager = new QNetworkAccessManager();
}
SFriends::~SFriends(){
    delete _manager;
}

void SFriends::Set(QString AKey, QString AID, bool AParallel){
    _key=AKey;
    _id=AID;
    if(AParallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+AKey+"&steamid="+AID+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+AKey+"&steamid="+AID+"&relationship=friend"));
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SFriends::Set(QJsonDocument AFriends){
    Clear();
    if(AFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        _friends=AFriends.object().value("friendslist").toObject().value("friends").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SFriends::Load(QNetworkReply *AReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    QJsonDocument localFriends = QJsonDocument::fromJson(AReply->readAll());
    AReply->deleteLater();
    Set(localFriends);
    emit s_finished(this);
    emit s_finished();
}

SProfile SFriends::GetProfiles(){
    QEventLoop loop;
    QNetworkAccessManager localManager;
    connect(&localManager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    int size=0;
    QJsonArray arrProfiles;
    SProfile Profile;
    while(size<_friends.size()){
        QString querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_key+"&steamids="+_friends[size++].toObject().value("steamid").toString();
        if(size+99>_friends.size()){
            for (;size<_friends.size();querry+=", "+_friends[size++].toObject().value("steamid").toString());
        } else {
            for (int i=0;i<99;i++)
                querry+=", "+_friends[size++].toObject().value("steamid").toString();
        }
        qDebug()<<"Запрос="<<querry;
        QNetworkReply &localReply = *localManager.get(QNetworkRequest(querry));
        loop.exec();
        QJsonDocument DocFriends = QJsonDocument::fromJson(localReply.readAll());
        for(int i=0;i<DocFriends.object().value("response").toObject().value("players").toArray().size();
            arrProfiles.append(DocFriends.object().value("response").toObject().value("players").toArray().at(i++).toObject()));
    }
    Profile.Set(arrProfiles);
    qDebug()<<"Друзей"<<Profile.GetCount();
    return Profile;
}

void SFriends::Update(bool AParallel){
    Set(_key,_id,AParallel);
}
void SFriends::Clear(){
    _friends=QJsonArray();
}

SFriends::SFriends( const SFriends & ANewFriends){
    _friends=ANewFriends._friends;
    _status=ANewFriends._status;
    _id=ANewFriends._id;
    _key=ANewFriends._key;
    _manager = new QNetworkAccessManager;
}

SFriends & SFriends::operator=(const SFriends & ANewFriends){
    delete _manager;
    _friends=ANewFriends._friends;
    _status=ANewFriends._status;
    _id=ANewFriends._id;
    _key=ANewFriends._key;
    _manager = new QNetworkAccessManager;
    return *this;
}

