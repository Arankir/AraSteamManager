#include "steamapigame.h"

SteamAPIGame::SteamAPIGame(QJsonObject ObjGame, QObject *parent) : QObject(parent){
    Set(ObjGame);
}
SteamAPIGame::SteamAPIGame(){

}

void SteamAPIGame::Set(QJsonObject ObjGame){
    game=ObjGame;
}

QString SteamAPIGame::GetNumberPlayers(QString key, bool hardreload){
    if(numberplayers==""||hardreload){
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+QString::number(game.value("appid").toInt()))));
        loop.exec();
        QJsonDocument NumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
        numberplayers=QString::number(NumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble());
    }
    return numberplayers;
    //{"player_count":9023,
    //"result":1}
}

SteamAPIGame::SteamAPIGame( const SteamAPIGame & a){
    game=a.game;
    numberplayers=a.numberplayers;
}
SteamAPIGame & SteamAPIGame::operator=(const SteamAPIGame & a) {
    game=a.game;
    numberplayers=a.numberplayers;
    return *this;
}
