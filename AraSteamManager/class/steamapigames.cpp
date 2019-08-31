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

SteamAPIGame SteamAPIGames::GetGameInfo(int index){
    return games[index];
}
int SteamAPIGames::GetAppid(int index){
    return games[index].GetAppid();
}
QString SteamAPIGames::GetName(int index){
    return games[index].GetName();
}
int SteamAPIGames::GetPlaytime_2weeks(int index){
    return games[index].GetPlaytime_2weeks();
}
int SteamAPIGames::GetPlaytime_forever(int index){
    return games[index].GetPlaytime_forever();
}
QString SteamAPIGames::GetImg_icon_url(int index){
    return games[index].GetImg_icon_url();
}
QString SteamAPIGames::GetImg_logo_url(int index){
    return games[index].GetImg_logo_url();
}
bool SteamAPIGames::GetHas_community_visible_stats(int index){
    return games[index].GetHas_community_visible_stats();
}
QString SteamAPIGames::GetStatus(){
    return status;
}

int SteamAPIGames::GetGamesCount(){
    return count;
}

void SteamAPIGames::Update(){
    Set(key,id,free_games,game_info);
}
