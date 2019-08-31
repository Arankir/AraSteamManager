#ifndef STEAMAPIGAME_H
#define STEAMAPIGAME_H

#include <QMainWindow>
#include <QJsonObject>
#include <QTextCodec>
#include <QObject>

class SteamAPIGame : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIGame(QJsonObject ObjGame, QObject *parent = nullptr);
    SteamAPIGame();
    void Set(QJsonObject ObjGame);
    int GetAppid();
    QString GetName();
    int GetPlaytime_2weeks();
    int GetPlaytime_forever();
    QString GetImg_icon_url();
    QString GetImg_logo_url();
    bool GetHas_community_visible_stats();
    SteamAPIGame(const SteamAPIGame &);
    SteamAPIGame & operator=(const SteamAPIGame & game);

signals:

public slots:

private:
    int appid=0;
    QString name="";
    int playtime_2weeks=0;
    int playtime_forever=0;
    QString img_icon_url="";
    QString img_logo_url="";
    bool has_community_visible_stats=false;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // STEAMAPIGAME_H
