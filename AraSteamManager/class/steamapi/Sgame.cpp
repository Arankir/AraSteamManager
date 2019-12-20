#include "Sgame.h"

SGame::SGame(QJsonObject Agame, QObject *parent) : QObject(parent){
    _game=Agame;
}
SGame::SGame(){

}

void SGame::Set(QJsonObject Agame){
    _game=Agame;
}

QString SGame::GetNumberPlayers(bool AhardReload){
    if(_numberPlayers==""||AhardReload){
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+_setting.GetKey()+"&appid="+QString::number(_game.value("appid").toInt()))));
        loop.exec();
        QJsonDocument NumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
        _numberPlayers=QString::number(NumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble());
    }
    return _numberPlayers;
}

SGame::SGame( const SGame & Agame){
    _game=Agame._game;
    _numberPlayers=Agame._numberPlayers;
}
SGame & SGame::operator=(const SGame & Agame) {
    _game=Agame._game;
    _numberPlayers=Agame._numberPlayers;
    return *this;
}
