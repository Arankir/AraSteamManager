#ifndef SBADGE_H
#define SBADGE_H

#include "../sapi.h"
#include "./sgames.h"

class SBadge : public Sapi {
public:
    SBadge(QObject *parent = nullptr);
    SBadge(const SBadge &badge);
    SBadge(const QJsonObject &object, QObject *parent = nullptr);

    SBadge &operator=(const SBadge &badge);
    bool    operator<(const SBadge &badge) const;
    bool    operator>(const SBadge &badge) const;
    bool    operator==(const SBadge &badge) const;
    bool    operator!=(const SBadge &badge) const;


    QJsonObject toJson() const;
    void fromJson(const QJsonObject &object);

    static QList<SBadge> load(const ProfileID &profileId, std::function<void (QList<SBadge>)> aCallback = nullptr);
    static void getXpInfo(const ProfileID &profileId, int &playerXp, int &playerLevel, int &playerXpNeededToLevelUp, int &playerXpNeededCurrentLevel);

    int badgeid()               const;
    GameID appid()              const;
    int level()                 const;
    QDateTime completion_time() const;
    int xp()                    const;
    int communityitemid()       const;
    int border_color()          const;
    int scarcity()              const;

private:
    int badgeid_ = 0;
    GameID appid_ = 0;
    int level_ = 0;
    QDateTime completion_time_;
    int xp_ = 0;
    int communityitemid_ = 0;
    int border_color_ = 0;
    int scarcity_ = 0;
};

using SBadges = QList<SBadge>;

#endif // SBADGE_H
