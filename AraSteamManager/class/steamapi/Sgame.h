#ifndef SGAME_H
#define SGAME_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QEventLoop>
#include <QTextCodec>
#include <QObject>

class SGame : public QObject
{
    Q_OBJECT
public:
    explicit SGame(QJsonObject ObjGame, QObject *parent = nullptr);
    SGame();
    void Set(QJsonObject ObjGame);
    int GetAppid() {return game.value("appid").toInt();}
    QString GetName() {return game.value("name").toString();}
    int GetPlaytime_2weeks() {return game.value("playtime_2weeks").toInt();}
    int GetPlaytime_forever() {return game.value("playtime_forever").toInt();}
    QString GetImg_icon_url() {return game.value("img_icon_url").toString();}
    QString GetImg_logo_url() {return game.value("img_logo_url").toString();}
    bool GetHas_community_visible_stats() {return game.value("has_community_visible_stats").toBool();}
    QString GetNumberPlayers(QString key, bool hardreload);
    SGame(const SGame &);
    SGame & operator=(const SGame & game);

signals:

public slots:

private:
    QJsonObject game;
    QString numberplayers="";
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // SGAME_H