#include "Sgames.h"

SGames::SGames(QString Aid, bool Afree_games, bool Agame_info, bool Aparallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=Aid;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+_setting.GetKey();
    if(Afree_games)
        request+="&include_played_free_games=1";
    if(Agame_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+Aid;
    if(Aparallel){
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
SGames::SGames(QJsonDocument Agames){
    _manager = new QNetworkAccessManager();
    if(Agames.object().value("response").toObject().value("games").toArray().size()>0){
        _games=Agames.object().value("response").toObject().value("games").toArray();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SGames::SGames(){
    _manager = new QNetworkAccessManager();
}
SGames::~SGames(){
    delete _manager;
}

void SGames::Set(QString Aid, bool Afree_games, bool Agame_info, bool Aparallel){
    _id=Aid;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+_setting.GetKey();
    if(Afree_games)
        request+="&include_played_free_games=1";
    if(Agame_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+Aid;
    if(Aparallel){
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
void SGames::Set(QJsonDocument Agames){
    Clear();
    if(Agames.object().value("response").toObject().value("games").toArray().size()>0){
        _games=Agames.object().value("response").toObject().value("games").toArray();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}

void SGames::Load(QNetworkReply *Areply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SGames::Load);
    QJsonDocument localGames = QJsonDocument::fromJson(Areply->readAll());
    Areply->deleteLater();
    Set(localGames);
    emit s_finished(this);
    emit s_finished();
}

void SGames::Update(bool parallel){
    Set(_id,_free_games,_game_info, parallel);
}
void SGames::Clear(){
    _games=QJsonArray();
}

SGames::SGames( const SGames & AnewGames){
    _games=AnewGames._games;
    _status=AnewGames._status;
    _error=AnewGames._error;
    _id=AnewGames._id;
    _free_games=AnewGames._free_games;
    _game_info=AnewGames._game_info;
    _manager = new QNetworkAccessManager;
}
SGames & SGames::operator=(const SGames & AnewGames){
    delete _manager;
    _games=AnewGames._games;
    _status=AnewGames._status;
    _error=AnewGames._error;
    _id=AnewGames._id;
    _free_games=AnewGames._free_games;
    _game_info=AnewGames._game_info;
    _manager = new QNetworkAccessManager;
    return *this;
}
