#include "steamapigame.h"

SteamAPIGame::SteamAPIGame(QJsonObject ObjGame, QObject *parent) : QObject(parent){
    Set(ObjGame);
}
SteamAPIGame::SteamAPIGame(){

}

void SteamAPIGame::Set(QJsonObject ObjGame){
    appid=ObjGame.value("appid").toInt();
    name=ObjGame.value("name").toString();
    playtime_2weeks=ObjGame.value("playtime_2weeks").toInt();
    playtime_forever=ObjGame.value("playtime_forever").toInt();
    img_icon_url=ObjGame.value("img_icon_url").toString();
    img_logo_url=ObjGame.value("img_logo_url").toString();
    has_community_visible_stats=ObjGame.value("has_community_visible_stats").toBool();
}

QString SteamAPIGame::GetNumberPlayers(QString key, bool hardreload){
    if(numberplayers==""||hardreload){
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+QString::number(appid))));
        loop.exec();
        QJsonDocument NumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
        numberplayers=QString::number(NumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble());
    }
    return numberplayers;
    //{"player_count":9023,
    //"result":1}
}

SteamAPIGame::SteamAPIGame( const SteamAPIGame & a){
    appid=a.appid;
    name=a.name;
    playtime_2weeks=a.playtime_2weeks;
    playtime_forever=a.playtime_forever;
    img_icon_url=a.img_icon_url;
    img_logo_url=a.img_logo_url;
    has_community_visible_stats=a.has_community_visible_stats;
}
SteamAPIGame & SteamAPIGame::operator=(const SteamAPIGame & game) {
    appid=game.appid;
    name=game.name;
    playtime_2weeks=game.playtime_2weeks;
    playtime_forever=game.playtime_forever;
    img_icon_url=game.img_icon_url;
    img_logo_url=game.img_logo_url;
    has_community_visible_stats=game.has_community_visible_stats;
    return *this;
}
