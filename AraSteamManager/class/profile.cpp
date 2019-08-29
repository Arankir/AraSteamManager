#include "profile.h"

Profile::Profile(QJsonObject info, QObject *parent) : QObject(parent){
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager,&QNetworkAccessManager::finished,&loop, &QEventLoop::quit);
    QNetworkReply &reply = *manager.get(QNetworkRequest(info.value("avatar").toString()));
    loop.exec();
    Avatar.loadFromData(reply.readAll());
    steamid=info.value("steamid").toString();
    visibility=info.value("communityvisibilitystate").toInt();
    Name=info.value("personaname").toString();
    timecreated=info.value("timecreated").toInt();
    inGame=info.value("gameextrainfo").toString();
    Gameid=info.value("gameid").toString();
}

void Profile::PostData(QJsonObject info){
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager,&QNetworkAccessManager::finished,&loop, &QEventLoop::quit);
    QNetworkReply &reply = *manager.get(QNetworkRequest(info.value("avatar").toString()));
    loop.exec();
    Avatar.loadFromData(reply.readAll());
    steamid=info.value("steamid").toString();
    visibility=info.value("communityvisibilitystate").toInt();
    Name=info.value("personaname").toString();
    timecreated=info.value("timecreated").toInt();
    inGame=info.value("gameextrainfo").toString();
    Gameid=info.value("gameid").toString();
}

Profile::Profile(){

}

Profile::Profile(const Profile& pro){
    this->Avatar=pro.Avatar;
    this->steamid=pro.steamid;
    this->visibility=pro.visibility;
    this->Name=pro.Name;
    this->timecreated=pro.timecreated;
    this->inGame=pro.inGame;
    this->Gameid=pro.Gameid;
}

Profile& Profile::operator=(const Profile& pro){
    this->Avatar=pro.Avatar;
    this->steamid=pro.steamid;
    this->visibility=pro.visibility;
    this->Name=pro.Name;
    this->timecreated=pro.timecreated;
    this->inGame=pro.inGame;
    this->Gameid=pro.Gameid;
}

Profile::~Profile(){

}

QString Profile::GetSteamid(){
    return steamid;
}

QPixmap Profile::GetAvatar(){
    return Avatar;
}

int Profile::GetVisibility(){
    return visibility;
}

QString Profile::GetName(){
    return Name;
}

int Profile::GetTimeCreated(){
    return timecreated;
}

QString Profile::GetInGame(){
    return inGame;
}

QString Profile::GetGameId(){
    return Gameid;
}
