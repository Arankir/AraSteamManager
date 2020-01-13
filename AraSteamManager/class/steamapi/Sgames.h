#ifndef SGAMES_H
#define SGAMES_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QObject>
#include <class/steamapi/Sgame.h>
#include <class/settings.h>
#include <class/statusvalue.h>

class SGames : public QObject
{
    Q_OBJECT
public:
    explicit SGames(QString id, bool free_games, bool game_info, bool parallel, QObject *parent = nullptr);
    SGames(QJsonDocument DocGames);
    SGames();
    ~SGames();
    void Set(QString id, bool free_games, bool game_info, bool parallel);
    void Set(QJsonDocument DocGames);
    void SetIndex(int AIndex) {_index=AIndex;}
    SGame GetGame(int index) {return SGame(_games[index].toObject());}
    int GetAppid(int index) {return _games[index].toObject().value("appid").toInt();}
    QString GetName(int index) {return _games[index].toObject().value("name").toString();}
    int GetPlaytime_2weeks(int index) {return _games[index].toObject().value("playtime_2weeks").toInt();}
    int GetPlaytime_forever(int index) {return _games[index].toObject().value("playtime_forever").toInt();}
    QString GetImg_icon_url(int index) {return _games[index].toObject().value("img_icon_url").toString();}
    QString GetImg_logo_url(int index) {return _games[index].toObject().value("img_logo_url").toString();}
    bool GetHas_community_visible_stats(int index) {return _games[index].toObject().value("has_community_visible_stats").toBool();}
    QString GetID() {return _id;}
    int GetIndex() {return _index;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _games.size();}
    void Update(bool parallel);
    void Clear();
    SGames( const SGames & a);
    SGames & operator=(const SGames & profile);

signals:
    void s_finished(SGames*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QJsonArray _games;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id;
    int _index=-1;
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
