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

class SGame : public QObject
{
    Q_OBJECT
public:
    explicit SGame(QJsonObject ObjGame, QObject *parent = nullptr);
    SGame(QObject *parent = nullptr);
    void Set(QJsonObject ObjGame);
    int GetAppid() {return _game.value("appid").toInt();}
    QString GetName() const {return _game.value("name").toString();}
    int GetPlaytime_2weeks() {return _game.value("playtime_2weeks").toInt();}
    int GetPlaytime_forever() {return _game.value("playtime_forever").toInt();}
    QString GetImg_icon_url() {return _game.value("img_icon_url").toString();}
    QString GetImg_logo_url() {return _game.value("img_logo_url").toString();}
    bool GetHas_community_visible_stats() {return _game.value("has_community_visible_stats").toBool();}
    QString GetNumberPlayers(bool hardreload);
    SGame(const SGame &);
    SGame & operator=(const SGame & game);
    const bool &operator<(const SGame & game);

signals:

public slots:

private:
    QJsonObject _game;
    QString _numberPlayers="";
    Settings _setting;
};

class SGames : public QObject
{
    Q_OBJECT
public:
    explicit SGames(QString id, bool free_games, bool game_info, bool parallel, QObject *parent = nullptr);
    SGames(QJsonDocument DocGames, QObject *parent = nullptr);
    SGames(QObject *parent = nullptr);
    ~SGames();
    void Set(QString id, bool free_games, bool game_info, bool parallel);
    void Set(QJsonDocument DocGames);
    int GetAppid(int index) {return _games[index].GetAppid();}
    QString GetID() {return _id;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _games.size();}
    void Update(bool parallel);
    void Clear();
    void Sort();
    SGames( const SGames & a);
    SGames & operator=(const SGames &games);
    SGame &operator[](const int &index);

    int _index=-1;

signals:
    void s_finished(SGames*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SGame> _games;
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
