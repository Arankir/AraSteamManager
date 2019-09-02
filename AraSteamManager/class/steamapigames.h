#ifndef STEAMAPIGAMES_H
#define STEAMAPIGAMES_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <class/steamapigame.h>

class SteamAPIGames : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIGames(QString key, QString id, bool free_games, bool game_info, QObject *parent = nullptr);
    SteamAPIGames(QJsonDocument DocGames);
    SteamAPIGames();
    ~SteamAPIGames();
    void Set(QString key, QString id, bool free_games, bool game_info);
    void Set(QJsonDocument DocGames);
    SteamAPIGame GetGameInfo(int index);
    int GetAppid(int index);
    QString GetName(int index);
    int GetPlaytime_2weeks(int index);
    int GetPlaytime_forever(int index);
    QString GetImg_icon_url(int index);
    QString GetImg_logo_url(int index);
    bool GetHas_community_visible_stats(int index);
    QString GetStatus();
    int GetGamesCount();
    void Update();
    void Sort();
    SteamAPIGames( const SteamAPIGames & a);
    SteamAPIGames & operator=(const SteamAPIGames & profile);
    void Clear();

signals:
    void finished(SteamAPIGames*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SteamAPIGame> games;
    QString status="none";
    QString id;
    QString key;
    bool free_games=false;
    bool game_info=false;
    int count;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // STEAMAPIGAMES_H
