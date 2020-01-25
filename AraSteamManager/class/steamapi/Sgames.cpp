#include "Sgames.h"

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
const bool &SGame::operator<(const SGame &Agame){
    static const bool b=_game.value("name").toString().toLower()<Agame._game.value("name").toString().toLower();
    return b;
}


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
        //_games=Agames.object().value("response").toObject().value("games").toArray();
        _games.resize(Agames.object().value("response").toObject().value("games").toArray().size());
        for(int i=0;i<Agames.object().value("response").toObject().value("games").toArray().size();i++){
            _games[i]=SGame(Agames.object().value("response").toObject().value("games").toArray().at(i).toObject());
        }
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
        //_games=Agames.object().value("response").toObject().value("games").toArray();
        _games.resize(Agames.object().value("response").toObject().value("games").toArray().size());
        for(int i=0;i<Agames.object().value("response").toObject().value("games").toArray().size();i++){
            _games[i]=SGame(Agames.object().value("response").toObject().value("games").toArray().at(i).toObject());
        }
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
    _games.clear();
}

void SGames::Sort(){
    //Переделать нормально
    std::list<SGame> list = _games.toList().toStdList();
    list.sort([](const SGame &s1, const SGame &s2)-> const bool {
        if(QString::compare(s1.GetName().toLower(),s2.GetName().toLower())<0)
            return true;
        else
            return false;
    });

    _games=QVector<SGame>::fromList(QList<SGame>::fromStdList(list));
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

SGame &SGames::operator[](const int &Aindex){
    return _games[Aindex];
}
