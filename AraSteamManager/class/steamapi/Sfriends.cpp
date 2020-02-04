#include "Sfriends.h"

#define SFriendStart {
SFriend::SFriend(QJsonObject a_friend, QObject *parent) : QObject(parent){
    _friend=a_friend;
}
SFriend::SFriend(){

}
void SFriend::Set(QJsonObject a_friend){
    _friend=a_friend;
}
SFriend::SFriend( const SFriend & a_newFriend){
    _friend=a_newFriend._friend;
}
SFriend & SFriend::operator=(const SFriend & a_newFriend) {
    _friend=a_newFriend._friend;
    return *this;
}
const bool &SFriend::operator<(const SFriend &a_game){
    static const bool b=_friend.value("steamid").toString().toLower()<a_game._friend.value("steamid").toString().toLower();
    //qDebug()<<_game.value("name").toString().toLower()<<a_game._game.value("name").toString().toLower();
    return b;
}
#define SFriendEnd }
#define SFriendsStart {
SFriends::SFriends(QString a_id, bool a_parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=a_id;
    if(a_parallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+a_id+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+a_id+"&relationship=friend"));
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
SFriends::SFriends(QJsonDocument a_friends){
    _manager = new QNetworkAccessManager();
    if(a_friends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        _friends.resize(a_friends.object().value("friendslist").toObject().value("friends").toArray().size());
        for(int i=0;i<a_friends.object().value("friendslist").toObject().value("friends").toArray().size();i++){
            _friends[i]=SFriend(a_friends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject());
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
void SFriends::Set(QString a_id, bool a_parallel){
    _id=a_id;
    if(a_parallel){
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+a_id+"&relationship=friend"));
        connect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    } else {
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+_setting.GetKey()+"&steamid="+a_id+"&relationship=friend"));
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
void SFriends::Set(QJsonDocument a_friends){
    Clear();
    if(a_friends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        //_friends=a_friends.object().value("friendslist").toObject().value("friends").toArray();
        _friends.resize(a_friends.object().value("friendslist").toObject().value("friends").toArray().size());
        for(int i=0;i<a_friends.object().value("friendslist").toObject().value("friends").toArray().size();i++){
            _friends[i]=SFriend(a_friends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject());
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SFriends::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SFriends::Load);
    QJsonDocument localFriends = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
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
void SFriends::Update(bool a_parallel){
    Set(_id,a_parallel);
}
void SFriends::Clear(){
    _friends.clear();
}
void SFriends::Sort(){
    //Переделать нормально
    std::list<SFriend> list = _friends.toList().toStdList();
    list.sort(/*[](const SFriend &s1, const SFriend &s2)-> const bool {
        if(QString::compare(s1.GetName().toLower(),s2.GetName().toLower())<0)
            return true;
        else
            return false;
    }*/);
    _friends=QVector<SFriend>::fromList(QList<SFriend>::fromStdList(list));
}
SFriends::SFriends( const SFriends & a_newFriends){
    _friends=a_newFriends._friends;
    _status=a_newFriends._status;
    _error=a_newFriends._error;
    _id=a_newFriends._id;
    _manager = new QNetworkAccessManager;
}
SFriends & SFriends::operator=(const SFriends & a_newFriends){
    delete _manager;
    _friends=a_newFriends._friends;
    _status=a_newFriends._status;
    _error=a_newFriends._error;
    _id=a_newFriends._id;
    _manager = new QNetworkAccessManager;
    return *this;
}
SFriend &SFriends::operator[](const int &index){
    return _friends[index];
}
#define SFriendsEnd }
