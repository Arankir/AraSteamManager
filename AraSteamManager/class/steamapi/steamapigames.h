#ifndef STEAMAPIGAMES_H
#define STEAMAPIGAMES_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QObject>
#include <class/steamapi/steamapigame.h>

class SteamAPIGames : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIGames(QString key, QString id, bool free_games, bool game_info, bool parallel, QObject *parent = nullptr);
    SteamAPIGames(QJsonDocument DocGames);
    SteamAPIGames();
    ~SteamAPIGames();
    void Set(QString key, QString id, bool free_games, bool game_info, bool parallel);
    void Set(QJsonDocument DocGames);
    SteamAPIGame GetGame(int index) {return SteamAPIGame(games[index].toObject());}
    int GetAppid(int index) {return games[index].toObject().value("appid").toInt();}
    QString GetName(int index) {return games[index].toObject().value("name").toString();}
    int GetPlaytime_2weeks(int index) {return games[index].toObject().value("playtime_2weeks").toInt();}
    int GetPlaytime_forever(int index) {return games[index].toObject().value("playtime_forever").toInt();}
    QString GetImg_icon_url(int index) {return games[index].toObject().value("img_icon_url").toString();}
    QString GetImg_logo_url(int index) {return games[index].toObject().value("img_logo_url").toString();}
    bool GetHas_community_visible_stats(int index) {return games[index].toObject().value("has_community_visible_stats").toBool();}
    QString GetStatus() {return status;}
    int GetCount() {return games.size();}
    void Update(bool parallel);
    void Clear();
    SteamAPIGames( const SteamAPIGames & a);
    SteamAPIGames & operator=(const SteamAPIGames & profile);

signals:
    void finished(SteamAPIGames*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QJsonArray games;
    QString status="none";
    QString id;
    QString key;
    bool free_games=false;
    bool game_info=false;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // STEAMAPIGAMES_H
