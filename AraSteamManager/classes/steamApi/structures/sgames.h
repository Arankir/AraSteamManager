#ifndef SGAMES_H
#define SGAMES_H

#include "../sapi.h"
#include "classes/common/generalfunctions.h"

class SGame : public Sapi {
    Q_OBJECT
public:
    SGame(const QJsonObject &game = QJsonObject(), const ProfileID &userId = "", QObject *parent = nullptr);
    SGame(const SGame &game);

    QJsonObject toJson() const;
    virtual QString className() const {return "SGame";}
    static QList<SGame> load(const ProfileID &id, const int &free_games = 0, const int &game_info = 0, std::function< void(QList<SGame>) > callback = nullptr);
    static int playerCount(const GameID &appId);

    SGame & operator=(const SGame &game);
    bool    operator<(const SGame &game) const;
    bool    operator>(const SGame &game) const;
    bool    operator==(const SGame &game) const;
    bool    operator!=(const SGame &game) const;

    QPixmap pixmapIcon() const;
    QPixmap pixmapLogo() const;

    ProfileID userId()              const;
    GameID appId()                  const;
    QString name()                  const;
    int playtime2Weeks()            const;
    int playtimeForever()           const;
    int playtimeWindowsForever()    const;
    int playtimeMacForever()        const;
    int playtimeLinuxForever()      const;
    bool hasCommunityVisibleStats() const;

    QString imgIconUrl()            const;
    QString imgLogoUrl()            const;

    static QPixmap pixmapIcon(const GameID &aGameId, const QString &aIconPath);
signals:

private:
    void fromJson(const QJsonObject &value);

    ProfileID userId_;
    GameID appId_;
    QString name_;
    int playtime_2weeks_;
    int playtime_forever_;
    int playtime_windows_forever_;
    int playtime_mac_forever_;
    int playtime_linux_forever_;
    bool has_community_visible_stats_;
    QString img_icon_url_;
    QString img_logo_url_;

    mutable QImage pixmapIcon_;
    mutable QImage pixmapLogo_;
};

using SGames = QList<SGame>;

#endif // SGAMES_H
