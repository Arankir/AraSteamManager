#ifndef SGAMES_H
#define SGAMES_H

#include "../sapi.h"

class SGame : public QObject {
    Q_OBJECT
public:
    explicit SGame(const QJsonObject &game = QJsonObject(), QObject *parent = nullptr);
    SGame(const SGame &game): QObject(game.parent()), _appID(game._appID), _name(game._name), _playtime_2weeks(game._playtime_2weeks),
        _playtime_forever(game._playtime_forever), _has_community_visible_stats(game._has_community_visible_stats), _img_icon_url(game._img_icon_url),
        _img_logo_url(game._img_logo_url) {}

    SGame & operator=(const SGame &game);
    bool    operator<(const SGame &game);

    QPixmap pixmapIcon();
    QPixmap pixmapLogo();

    //Пока сломано
    const QString getNumberPlayers(bool hardReload);

    int appId()                     const {return _appID;}
    QString sAppId()                const {return QString::number(_appID);}
    QString name()                  const {return _name;}
    int playtime2Weeks()            const {return _playtime_2weeks;}
    int playtimeForever()           const {return _playtime_forever;}
    bool hasCommunityVisibleStats() const {return _has_community_visible_stats;}

    QString imgIconUrl()            const {return _img_icon_url;}
    QString imgLogoUrl()            const {return _img_logo_url;}

signals:

private:
    void fromJson(const QJsonValue &value);

    int _appID;
    QString _name;
    int _playtime_2weeks;
    int _playtime_forever;
    bool _has_community_visible_stats;
    QString _img_icon_url;
    QString _img_logo_url;

    QPixmap _pixmapIcon;
    QPixmap _pixmapLogo;

    QString _numberPlayers = "";
};

class SGames : public Sapi {
    Q_OBJECT
public:
    explicit SGames(const QString &id, int free_games = 0, int game_info = 0, bool parallel = false, QObject *parent = nullptr);
    SGames(const SGames &games): Sapi(games.parent()), _games(games._games), _id(games._id), _free_games(games._free_games), _game_info(games._game_info) {}
    SGames(QObject *parent = nullptr): Sapi(parent) {}
    ~SGames() {;}

    SGames &operator=(const SGames &games);
    SGame &operator[](const int &index) {return _games[index];}

    SGames &load(const QString &id, int free_games = 0, int game_info = 0, bool parallel = false);
    SGames &update(bool parallel);
    SGames &clear();
    SGames &sort();

    QList<SGame>::iterator begin() {return _games.begin();}
    QList<SGame>::iterator end() {return _games.end();}
    QString getID() const {return _id;}
    int getCount() const {return _games.size();}

    int _index = -1;

signals:
    void s_finished(SGames*);
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SGame> _games;
    QString _id;
    int _free_games = 0;
    int _game_info = 0;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // SGAMES_H
