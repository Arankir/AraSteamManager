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

class SGame : public QObject {
    Q_OBJECT
public:
    explicit SGame(QJsonObject game, QObject *parent = nullptr);
    void Set(QJsonObject objGame);
    const int _appID;
    const QString _name;
    const int _playtime_2weeks;
    const int _playtime_forever;
    const QString _img_icon_url;
    const QString _img_logo_url;
    const bool _has_community_visible_stats;
    const QString getNumberPlayers(bool hardreload);
    SGame(const SGame &game);
    SGame &operator=(const SGame &game);
    const bool &operator<(const SGame &game);

signals:

private:
    QString _numberPlayers = "";
};

class SGames : public QObject {
    Q_OBJECT
public:
    explicit SGames(QString id, bool free_games, bool game_info, bool parallel, QObject *parent = nullptr);
    SGames(QJsonDocument docGames, QObject *parent = nullptr);
    SGames(QObject *parent);
    ~SGames();
    void set(QString id, bool free_games, bool game_info, bool parallel);
    void set(QJsonDocument docGames);
    int getAppid(int index);
    QString getID();
    StatusValue getStatus();
    QString getError();
    int getCount();
    void update(bool parallel);
    void clear();
    void sort();
    SGames(const SGames &games);
    SGames & operator=(const SGames &games);
    SGame &operator[](const int &index);
    QList<SGame>::iterator begin() {return _games.begin();}
    QList<SGame>::iterator end() {return _games.end();}

    int _index=-1;

signals:
    void s_finished(SGames*);
    void s_finished();

private slots:
    void onLoad(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    QList<SGame> _games;
    StatusValue _status = StatusValue::none;
    QString _error = "";
    QString _id;
    bool _free_games = false;
    bool _game_info = false;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // SGAMES_H
