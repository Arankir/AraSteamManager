#include "profile.h"

Profile::Profile(QString steamids, QPixmap Avatars, int visibilitys, QString Names, int timecreateds, QString inGames, QString Gameids){
    steamid=steamids;
    Avatar=Avatars;
    visibility=visibilitys;
    Name=Names;
    timecreated=timecreateds;
    inGame=inGames;
    Gameid=Gameids;
}

Profile::Profile(QJsonObject info){
    steamid=info.value("steamid").toString();
    QNetworkAccessManager imagemanager;
    QEventLoop imageloop;  //Ждем ответ от сервера.
    QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(info.value("avatar").toString()));
    imageloop.exec();
    Avatar.loadFromData(imagereply.readAll());
    visibility=info.value("communityvisibilitystate").toInt();
    Name=info.value("personaname").toString();
    timecreated=info.value("timecreated").toInt();
    inGame=info.value("gameextrainfo").toString();
    Gameid=info.value("gameid").toString();
}

Profile::Profile(){

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
