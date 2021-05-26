#ifndef SGAMES_H
#define SGAMES_H

#include "../sapi.h"
#include "classes/common/generalfunctions.h"

#define SGames QList<SGame>

class SGame : public Sapi {
    Q_OBJECT
public:
    explicit SGame(const QJsonObject &game = QJsonObject(), const QString &userId = "", QObject *parent = nullptr);
    SGame(const SGame &game): Sapi(game.parent()), _userId(game.userId()), _appID(game._appID), _name(game._name),
        _playtime_2weeks(game._playtime_2weeks), _playtime_forever(game._playtime_forever),
        _has_community_visible_stats(game._has_community_visible_stats), _img_icon_url(game._img_icon_url),
        _img_logo_url(game._img_logo_url) {}

    QJsonObject toJson() const;
    virtual QString className() const {return "SGame";}
    static SGames load(const QString &id, const int &free_games = 0, const int &game_info = 0, std::function< void(SGames) > callback = nullptr);
    static int playerCount(const int &appId);

    SGame & operator=(const SGame &game);
    bool    operator<(const SGame &game) const;
    bool    operator>(const SGame &game) const;
    bool    operator==(const SGame &game) const;
    bool    operator!=(const SGame &game) const;

    QPixmap cPixmapIcon() const;

    QPixmap pixmapIcon();
    QPixmap pixmapLogo();

    QString userId()                const {return _userId;}
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

    QString _userId;
    int _appID;
    QString _name;
    int _playtime_2weeks;
    int _playtime_forever;
    bool _has_community_visible_stats;
    QString _img_icon_url;
    QString _img_logo_url;

    QPixmap _pixmapIcon;
    QPixmap _pixmapLogo;
};

//{"appid":218620,
//"name":"PAYDAY 2",
//"playtime_2weeks":329,
//"playtime_forever":45501,
//"img_icon_url":"a6abc0d0c1e79c0b5b0f5c8ab81ce9076a542414",
//"img_logo_url":"4467a70648f49a6b309b41b81b4531f9a20ed99d",
//"has_community_visible_stats":true}
#endif // SGAMES_H
