#include "Sgame.h"

SGame::SGame(QJsonObject AGame, QObject *parent) : QObject(parent){
    _game=AGame;
}
SGame::SGame(){

}

void SGame::Set(QJsonObject AGame){
    _game=AGame;
}

QString SGame::GetNumberPlayers(QString AKey, bool AHardReload){
    if(_numberPlayers==""||AHardReload){
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+AKey+"&appid="+QString::number(_game.value("appid").toInt()))));
        loop.exec();
        QJsonDocument NumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
        _numberPlayers=QString::number(NumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble());
    }
    return _numberPlayers;
}

SGame::SGame( const SGame & a){
    _game=a._game;
    _numberPlayers=a._numberPlayers;
}
SGame & SGame::operator=(const SGame & a) {
    _game=a._game;
    _numberPlayers=a._numberPlayers;
    return *this;
}
