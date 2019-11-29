#include "Sgame.h"

SGame::SGame(QJsonObject ObjGame, QObject *parent) : QObject(parent){
    Set(ObjGame);
}
SGame::SGame(){

}

void SGame::Set(QJsonObject ObjGame){
    game=ObjGame;
}

QString SGame::GetNumberPlayers(QString key, bool hardreload){
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

SGame::SGame( const SGame & a){
    game=a.game;
    numberplayers=a.numberplayers;
}
SGame & SGame::operator=(const SGame & a) {
    game=a.game;
    numberplayers=a.numberplayers;
    return *this;
}
