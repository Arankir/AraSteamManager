#include "Sgames.h"

#define SGameStart {
SGame::SGame(QJsonObject a_game, QObject *parent) : QObject(parent),_game(a_game){}
SGame::SGame(QObject *parent) : QObject(parent){}
void SGame::Set(QJsonObject a_game){
    _game=a_game;
}
QString SGame::GetNumberPlayers(bool a_hardReload){
    if(_numberPlayers==""||a_hardReload){
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
SGame::SGame( const SGame & a_game){
    _game=a_game._game;
    _numberPlayers=a_game._numberPlayers;
}
SGame & SGame::operator=(const SGame & a_game) {
    _game=a_game._game;
    _numberPlayers=a_game._numberPlayers;
    return *this;
}
const bool &SGame::operator<(const SGame &a_game){
    static const bool b=_game.value("name").toString().toLower()<a_game._game.value("name").toString().toLower();
    return b;
}
#define SGameEnd }
#define SGamesStart {
SGames::SGames(QString a_id, bool a_free_games, bool a_game_info, bool a_parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _id=a_id;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+_setting.GetKey();
    if(a_free_games)
        request+="&include_played_free_games=1";
    if(a_game_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+a_id;
    if(a_parallel){
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
    }
}
SGames::SGames(QJsonDocument a_games, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    if(a_games.object().value("response").toObject().value("games").toArray().size()>0){
        //_games=a_games.object().value("response").toObject().value("games").toArray();
        _games.resize(a_games.object().value("response").toObject().value("games").toArray().size());
        for(int i=0;i<a_games.object().value("response").toObject().value("games").toArray().size();i++){
            _games[i]=SGame(a_games.object().value("response").toObject().value("games").toArray().at(i).toObject());
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SGames::SGames(QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
}
SGames::~SGames(){
    delete _manager;
}
void SGames::Set(QString a_id, bool a_free_games, bool a_game_info, bool a_parallel){
    _id=a_id;
    QString request="http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+_setting.GetKey();
    if(a_free_games)
        request+="&include_played_free_games=1";
    if(a_game_info)
        request+="&include_appinfo=1";
    request+="&format=json&steamid="+a_id;
    if(a_parallel){
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
void SGames::Set(QJsonDocument a_games){
    Clear();
    if(a_games.object().value("response").toObject().value("games").toArray().size()>0){
        _games.resize(a_games.object().value("response").toObject().value("games").toArray().size());
        for(int i=0;i<a_games.object().value("response").toObject().value("games").toArray().size();i++){
            _games[i]=SGame(a_games.object().value("response").toObject().value("games").toArray().at(i).toObject());
        }
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SGames::Load(QNetworkReply *a_reply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SGames::Load);
    QJsonDocument localGames = QJsonDocument::fromJson(a_reply->readAll());
    a_reply->deleteLater();
    Set(localGames);
    emit s_finished(this);
    emit s_finished();
}
void SGames::Update(bool parallel){
    Set(_id,_free_games,_game_info, parallel);
}
void SGames::Clear(){
    _games.clear();
}
void SGames::Sort(){
    //Переделать нормально
    std::list<SGame> list(_games.begin(),_games.end());
    list.sort([](const SGame &s1, const SGame &s2)-> const bool {
        if(QString::compare(s1.GetName().toLower(),s2.GetName().toLower())<0)
            return true;
        else
            return false;
    });
    _games=QVector<SGame>(list.begin(),list.end());
    //_games=QVector<SGame>::fromList(QList<SGame>::fromStdList(list));
}
SGames::SGames( const SGames & a_newGames){
    _games=a_newGames._games;
    _status=a_newGames._status;
    _error=a_newGames._error;
    _id=a_newGames._id;
    _free_games=a_newGames._free_games;
    _game_info=a_newGames._game_info;
    _manager = new QNetworkAccessManager;
}
SGames & SGames::operator=(const SGames & a_newGames){
    delete _manager;
    _games=a_newGames._games;
    _status=a_newGames._status;
    _error=a_newGames._error;
    _id=a_newGames._id;
    _free_games=a_newGames._free_games;
    _game_info=a_newGames._game_info;
    _manager = new QNetworkAccessManager;
    return *this;
}
SGame &SGames::operator[](const int &a_index){
    return _games[a_index];
}
#define SGamesEnd }
