#include "Sfriends.h"

SFriend::SFriend(QJsonObject Afriend, QObject *parent) : QObject(parent){
    _friend=Afriend;
}
SFriend::SFriend(){

}

void SFriend::Set(QJsonObject Afriend){
    _friend=Afriend;
}

SFriend::SFriend( const SFriend & AnewFriend){
    _friend=AnewFriend._friend;
}
SFriend & SFriend::operator=(const SFriend & AnewFriend) {
    _friend=AnewFriend._friend;
    return *this;
}

const bool &SFriend::operator<(const SFriend &Agame){
    static const bool b=_friend.value("steamid").toString().toLower()<Agame._friend.value("steamid").toString().toLower();
    //qDebug()<<_game.value("name").toString().toLower()<<Agame._game.value("name").toString().toLower();
    return b;
}


SFriends::SFriends(QString Aid, bool Aparallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    if(Aparallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+Aid+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+Aid+"&relationship=friend"));
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
SFriends::SFriends(QJsonDocument Afriends){
    _manager = new QNetworkAccessManager();
    if(Afriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        _friends.resize(Afriends.object().value("friendslist").toObject().value("friends").toArray().size());
        for(int i=0;i<Afriends.object().value("friendslist").toObject().value("friends").toArray().size();i++){
            _friends[i]=SFriend(Afriends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject());
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SFriends::SFriends(){
    _manager = new QNetworkAccessManager();
}
SFriends::~SFriends(){
    delete _manager;
}

void SFriends::Set(QString Aid, bool Aparallel){
    _id=Aid;
    if(Aparallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+Aid+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+Aid+"&relationship=friend"));
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
void SFriends::Set(QJsonDocument Afriends){
    Clear();
    if(Afriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        //_friends=Afriends.object().value("friendslist").toObject().value("friends").toArray();
        _friends.resize(Afriends.object().value("friendslist").toObject().value("friends").toArray().size());
        for(int i=0;i<Afriends.object().value("friendslist").toObject().value("friends").toArray().size();i++){
            _friends[i]=SFriend(Afriends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject());
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}

void SFriends::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    QJsonDocument localFriends = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localFriends);
    emit s_finished(this);
    emit s_finished();
}

SProfiles SFriends::GetProfiles(){
    QEventLoop loop;
    QNetworkAccessManager localManager;
    connect(&localManager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    int size=0;
    QJsonArray arrProfiles;
    SProfiles Profile;
    while(size<_friends.size()){
        QString querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_friends[size++].GetSteamid();
        if(size+99>_friends.size()){
            for (;size<_friends.size();querry+=", "+_friends[size++].GetSteamid());
        } else {
            for (int i=0;i<99;i++)
                querry+=", "+_friends[size++].GetSteamid();
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

void SFriends::Update(bool Aparallel){
    Set(_id,Aparallel);
}
void SFriends::Clear(){
    _friends.clear();
}

void SFriends::Sort(){
    //Переделать нормально
    std::list<SFriend> list = _friends.toList().toStdList();
    list.sort();
    _friends=QVector<SFriend>::fromList(QList<SFriend>::fromStdList(list));
}

SFriends::SFriends( const SFriends & AnewFriends){
    _friends=AnewFriends._friends;
    _status=AnewFriends._status;
    _error=AnewFriends._error;
    _id=AnewFriends._id;
    _manager = new QNetworkAccessManager;
}

SFriends & SFriends::operator=(const SFriends & AnewFriends){
    delete _manager;
    _friends=AnewFriends._friends;
    _status=AnewFriends._status;
    _error=AnewFriends._error;
    _id=AnewFriends._id;
    _manager = new QNetworkAccessManager;
    return *this;
}

SFriend &SFriends::operator[](const int &index){
    return _friends[index];
}

