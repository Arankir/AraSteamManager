#include "steamapigames.h"

SteamAPIGames::SteamAPIGames(QString key, QString id, bool free_games, bool game_info, QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id, free_games, game_info);
}
SteamAPIGames::SteamAPIGames(QJsonDocument DocGames){
    manager = new QNetworkAccessManager();
    Set(DocGames);
}
SteamAPIGames::SteamAPIGames(){
    manager = new QNetworkAccessManager();
}
SteamAPIGames::~SteamAPIGames(){
    delete manager;
}

void SteamAPIGames::Set(QString key, QString id, bool free_games, bool game_info){
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key;
    if(free_games)
        request+="&include_played_free_games=1";
    if(game_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+id;
    connect(manager,&QNetworkAccessManager::finished,this,&SteamAPIGames::Load);
    this->key=key;
    this->id=id;
    manager->get(QNetworkRequest(request));
}
void SteamAPIGames::Set(QJsonDocument DocGames){
    Clear();
    if(DocGames.object().value("response").toObject().value("games").toArray().size()>0){
        count=DocGames.object().value("response").toObject().value("game_count").toInt();
        for (int i=0;i<count;i++) {
            SteamAPIGame game;
            game.Set(DocGames.object().value("response").toObject().value("games").toArray().at(i).toObject());
            games.push_back(game);
        }
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SteamAPIGames::Load(QNetworkReply* Reply){
    disconnect(manager,&QNetworkAccessManager::finished,this,&SteamAPIGames::Load);
    QJsonDocument DocGames = QJsonDocument::fromJson(Reply->readAll());
    Reply->deleteLater();
    Set(DocGames);
    emit finished(this);
    emit finished();
}

void SteamAPIGames::Update(){
    Set(key,id,free_games,game_info);
}
void SteamAPIGames::Clear(){
    games.clear();
    count=0;
}
void SteamAPIGames::Sort(){
    for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (games[j].GetName() > games[j+1].GetName()) {
                SteamAPIGame temp = games[j];
                games[j] = games[j+1];
                games[j+1] = temp;
            }
        }
    }
}

SteamAPIGames::SteamAPIGames( const SteamAPIGames & a){
    games=a.games;
    status=a.status;
    id=a.id;
    key=a.key;
    free_games=a.free_games;
    game_info=a.game_info;
    count=a.count;
    manager = new QNetworkAccessManager;
}
SteamAPIGames & SteamAPIGames::operator=(const SteamAPIGames & profile){
    delete manager;
    games=profile.games;
    status=profile.status;
    id=profile.id;
    key=profile.key;
    free_games=profile.free_games;
    game_info=profile.game_info;
    count=profile.count;
    manager = new QNetworkAccessManager;
    return *this;
}
