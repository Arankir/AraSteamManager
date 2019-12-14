#include "Sgames.h"

SGames::SGames(QString AKey, QString AID, bool AFree_games, bool AGame_info, bool AParallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _key=AKey;
    _id=AID;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+AKey;
    if(AFree_games)
        request+="&include_played_free_games=1";
    if(AGame_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+AID;
    if(AParallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SGames::Load);
        _manager->get(QNetworkRequest(request));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest(request));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
SGames::SGames(QJsonDocument AGames){
    _manager = new QNetworkAccessManager();
    if(AGames.object().value("response").toObject().value("games").toArray().size()>0){
        _games=AGames.object().value("response").toObject().value("games").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SGames::SGames(){
    _manager = new QNetworkAccessManager();
}
SGames::~SGames(){
    delete _manager;
}

void SGames::Set(QString AKey, QString AID, bool AFree_games, bool AGame_info, bool AParallel){
    _key=AKey;
    _id=AID;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+AKey;
    if(AFree_games)
        request+="&include_played_free_games=1";
    if(AGame_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+AID;
    if(AParallel){
        connect(_manager,&QNetworkAccessManager::finished,this,&SGames::Load);
        _manager->get(QNetworkRequest(request));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest(request));
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}
void SGames::Set(QJsonDocument AGames){
    Clear();
    if(AGames.object().value("response").toObject().value("games").toArray().size()>0){
        _games=AGames.object().value("response").toObject().value("games").toArray();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SGames::Load(QNetworkReply *Reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SGames::Load);
    QJsonDocument localGames = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(localGames);
    emit s_finished(this);
    emit s_finished();
}

void SGames::Update(bool parallel){
    Set(_key,_id,_free_games,_game_info, parallel);
}
void SGames::Clear(){
    _games=QJsonArray();
}

SGames::SGames( const SGames & ANewGames){
    _games=ANewGames._games;
    _status=ANewGames._status;
    _id=ANewGames._id;
    _key=ANewGames._key;
    _free_games=ANewGames._free_games;
    _game_info=ANewGames._game_info;
    _manager = new QNetworkAccessManager;
}
SGames & SGames::operator=(const SGames & ANewGames){
    delete _manager;
    _games=ANewGames._games;
    _status=ANewGames._status;
    _id=ANewGames._id;
    _key=ANewGames._key;
    _free_games=ANewGames._free_games;
    _game_info=ANewGames._game_info;
    _manager = new QNetworkAccessManager;
    return *this;
}
