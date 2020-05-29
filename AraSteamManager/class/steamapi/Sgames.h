#ifndef SGAMES_H
#define SGAMES_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QEventLoop>
#include <QTextCodec>
#include <QObject>
#include <class/settings.h>
#include <class/statusvalue.h>

class SGame : public QObject{
    Q_OBJECT
public:
    explicit SGame(QJsonObject game, QObject *parent = nullptr): QObject(parent), _appID(game.value("appid").toInt()), _name(game.value("name").toString()),
        _playtime_2weeks(game.value("playtime_2weeks").toInt()), _playtime_forever(game.value("playtime_forever").toInt()), _img_icon_url(game.value("img_icon_url").toString()),
        _img_logo_url(game.value("img_logo_url").toString()), _has_community_visible_stats(game.value("has_community_visible_stats").toBool()){};
    void Set(QJsonObject ObjGame);
    const int _appID;
    const QString _name;
    const int _playtime_2weeks;
    const int _playtime_forever;
    const QString _img_icon_url;
    const QString _img_logo_url;
    const bool _has_community_visible_stats;
    const QString GetNumberPlayers(bool hardreload);
    SGame(const SGame &game): QObject(game.parent()), _appID(game._appID), _name(game._name), _playtime_2weeks(game._playtime_2weeks), _playtime_forever(game._playtime_forever),
        _img_icon_url(game._img_icon_url), _img_logo_url(game._img_logo_url), _has_community_visible_stats(game._has_community_visible_stats){};
    SGame & operator=(const SGame &a_game) { _numberPlayers=a_game._numberPlayers; return *this;}
    const bool &operator<(const SGame & game);

signals:

public slots:

private:
    QString _numberPlayers="";
    Settings _setting;
};

class SGames : public QObject
{
    Q_OBJECT
public:
    explicit SGames(QString id, bool free_games, bool game_info, bool parallel, QObject *parent = nullptr);
    SGames(QJsonDocument DocGames, QObject *parent = nullptr);
    SGames(QObject *parent): QObject(parent), _manager(new QNetworkAccessManager){};
    ~SGames();
    void Set(QString id, bool free_games, bool game_info, bool parallel);
    void Set(QJsonDocument DocGames);
    int GetAppid(int index) {return _games[index]._appID;}
    QString GetID() {return _id;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _games.size();}
    QList<SGame>::iterator begin() {return _games.begin();}
    QList<SGame>::iterator end() {return _games.end();}
    void Update(bool parallel);
    void Clear();
    void Sort();
    SGames(const SGames &games): QObject(games.parent()), _manager(new QNetworkAccessManager), _games(games._games), _status(games._status), _error(games._error), _id(games._id),
        _free_games(games._free_games), _game_info(games._game_info){};
    SGames & operator=(const SGames &games);
    SGame &operator[](const int &index) {return _games[index];}

    int _index=-1;

signals:
    void s_finished(SGames*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QList<SGame> _games;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id;
    bool _free_games=false;
    bool _game_info=false;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // SGAMES_H
