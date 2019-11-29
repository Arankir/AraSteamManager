#include "Sgames.h"

SGames::SGames(QString key, QString id, bool free_games, bool game_info, bool parallel, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, free_games, game_info, parallel);
}
SGames::SGames(QJsonDocument DocGames){
    manager = new QNetworkAccessManager();
    Set(DocGames);
}
SGames::SGames(){
    manager = new QNetworkAccessManager();
}
SGames::~SGames(){
    delete manager;
}

void SGames::Set(QString key, QString id, bool free_games, bool game_info, bool parallel){
    this->key=key;
    this->id=id;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key;
    if(free_games)
        request+="&include_played_free_games=1";
    if(game_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+id;
    if(parallel){
        connect(manager,&QNetworkAccessManager::finished,this,&SGames::Load);
        manager->get(QNetworkRequest(request));
    } else {
        QEventLoop loop;
        connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = manager->get(QNetworkRequest(request));
        loop.exec();
        disconnect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        Set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit finished(this);
        emit finished();
    }
}
void SGames::Set(QJsonDocument DocGames){
    Clear();
    if(DocGames.object().value("response").toObject().value("games").toArray().size()>0){
        games=DocGames.object().value("response").toObject().value("games").toArray();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SGames::Load(QNetworkReply *Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SGames::Load);
    QJsonDocument DocGames = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocGames);
    emit finished(this);
    emit finished();
}

void SGames::Update(bool parallel){
    Set(key,id,free_games,game_info, parallel);
}
void SGames::Clear(){
    games=QJsonArray();
}

SGames::SGames( const SGames & a){
    games=a.games;
    status=a.status;
    id=a.id;
    key=a.key;
    free_games=a.free_games;
    game_info=a.game_info;
    manager = new QNetworkAccessManager;
}
SGames & SGames::operator=(const SGames & profile){
    delete manager;
    games=profile.games;
    status=profile.status;
    id=profile.id;
    key=profile.key;
    free_games=profile.free_games;
    game_info=profile.game_info;
    manager = new QNetworkAccessManager;
    return *this;
}
