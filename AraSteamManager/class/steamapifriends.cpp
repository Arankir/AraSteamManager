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
    delete manager;
}

void SteamAPIFriends::Set(QString key, QString id){
connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIFriends::Load);
this->key=key;
this->id=id;
manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
}
void SteamAPIFriends::Set(QJsonDocument DocFriends){
    Clear();
    if(DocFriends.object().value("friendslist").toObject().value("friends").toArray().size()>0){
        count=DocFriends.object().value("friendslist").toObject().value("friends").toArray().size();
        for (int i=0;i<count;i++) {
            friends.push_back(SteamAPIFriend(DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject()));
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

SteamAPIProfile SteamAPIFriends::GetProfileFriend(int index){
    SteamAPIProfile Profile(key,GetSteamid(index),"url");
    return Profile;
}
QVector<SteamAPIProfile> SteamAPIFriends::GetProfiles(){
    QVector<SteamAPIProfile> Profiles;
    int countnow=0;
    QEventLoop loop;
    QNetworkAccessManager profmanager;
    qDebug()<<friends.size();
    connect(&profmanager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    while(countnow!=count){
        QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+friends[countnow++].GetSteamid();
        if(count-countnow>99){
            for (int i=countnow;i<countnow+99;i++) {
                Querry+=","+friends[i].GetSteamid();
            }
            countnow+=99;
            }
        else {
            for (int i=countnow;i<count;i++) {
                Querry+=","+friends[i].GetSteamid();
            }
            countnow=count;
            }
        qDebug()<<Querry;
        QNetworkReply &Reply = *profmanager.get(QNetworkRequest(Querry));
        loop.exec();
        QJsonDocument DocFriends = QJsonDocument::fromJson(Reply.readAll());
        for (int i=0;i<DocFriends.object().value("response").toObject().value("players").toArray().size();i++) {
            SteamAPIProfile Profile(DocFriends,i);
            qDebug()<<Profile.GetPersonaname();
            Profiles.push_back(Profile);
        }
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

void SteamAPIFriends::Clear(){
    friends.clear();
    count=0;
}
