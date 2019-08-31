#include "steamapifriends.h"

SteamAPIFriends::SteamAPIFriends(QString key, QString id, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id);
}
SteamAPIFriends::SteamAPIFriends(QJsonDocument DocFriends){
    manager = new QNetworkAccessManager();
    Set(DocFriends);
}
SteamAPIFriends::SteamAPIFriends(){
    manager = new QNetworkAccessManager();
}
SteamAPIFriends::~SteamAPIFriends(){
    manager->deleteLater();
}

void SteamAPIFriends::Set(QString key, QString id){
connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIFriends::Load);
this->key=key;
this->id=id;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
}
void SteamAPIFriends::Set(QJsonDocument DocFriends){
    if(DocFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        count=DocFriends.object().value("friendslist").toObject().value("friends").toArray().size();
        for (int i=0;i<count;i++) {
            SteamAPIFriend frienda;
            frienda.Set(DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject());
            friends.push_back(frienda);
        }
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

SteamAPIFriend SteamAPIFriends::GetFriendInfo(int index){
    return friends[index];
}
QString SteamAPIFriends::GetSteamid(int index){
    return friends[index].GetSteamid();
}
QString SteamAPIFriends::GetRelationship(int index){
    return friends[index].GetRelationship();
}
QDateTime SteamAPIFriends::GetFriend_since(int index){
    return friends[index].GetFriend_since();
}
QString SteamAPIFriends::GetStatus(){
    return status;
}

int SteamAPIFriends::GetFriendsCount(){
    return count;
}

SteamAPIProfile SteamAPIFriends::GetProfileFriend(int index){
    QEventLoop loop;
    SteamAPIProfile Profile;
    connect(&Profile, SIGNAL(finished()), &loop, SLOT(quit()));
    Profile.Set(key,GetSteamid(index),"url");
    loop.exec();
    disconnect(&Profile, SIGNAL(finished()), &loop, SLOT(quit()));
    return Profile;
}
QVector<SteamAPIProfile> SteamAPIFriends::GetProfiles(){
    QVector<SteamAPIProfile> Profiles;
    QEventLoop loop;
    QNetworkAccessManager profmanager;
    connect(&profmanager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+friends[0].GetSteamid();
    for (int i=1;i<count;i++) {
        Querry+=","+friends[i].GetSteamid();
    }
    QNetworkReply &Reply = *profmanager.get(QNetworkRequest(Querry));
    loop.exec();
    QJsonDocument DocFriends = QJsonDocument::fromJson(Reply.readAll());
    for (int i=0;i<count;i++) {
        SteamAPIProfile Profile;
        Profile.Set(DocFriends,i);
        qDebug()<<Profile.GetPersonaname();
        Profiles.push_back(Profile);
    }
    return Profiles;
}

void SteamAPIFriends::Update(){
    Set(key,id);
}

SteamAPIFriends::SteamAPIFriends( const SteamAPIFriends & a){
    friends=a.friends;
    status=a.status;
    id=a.id;
    key=a.key;
    count=a.count;
    manager = new QNetworkAccessManager;
}

SteamAPIFriends & SteamAPIFriends::operator=(const SteamAPIFriends & friendss) {
    delete manager;
    friends=friendss.friends;
    status=friendss.status;
    id=friendss.id;
    key=friendss.key;
    count=friendss.count;
    manager = new QNetworkAccessManager;
    return *this;
}
