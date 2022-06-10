#ifndef SBADGE_H
#define SBADGE_H

#include "../sapi.h"
#include "./sgames.h"

class SBadge : public Sapi {
public:
    SBadge(QObject *parent = nullptr);
    SBadge(const SBadge &aCopy);
    SBadge(const QJsonObject &aObject, QObject *parent = nullptr);

    SBadge &operator=(const SBadge &aBadge);
    bool    operator<(const SBadge &aBadge) const;
    bool    operator>(const SBadge &aBadge) const;
    bool    operator==(const SBadge &aBadge) const;
    bool    operator!=(const SBadge &aBadge) const;


    QJsonObject toJson() const;
    void fromJson(const QJsonObject &aObject);
    virtual QString className() const {return "SBadge";}

    static QList<SBadge> load(const ProfileID &aId, std::function<void (QList<SBadge>)> aCallback = nullptr);
    static void getXpInfo(const ProfileID &aId, int &playerXp, int &playerLevel, int &playerXpNeededToLevelUp, int &playerXpNeededCurrentLevel);

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
