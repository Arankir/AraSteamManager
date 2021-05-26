#ifndef SBANS_H
#define SBANS_H

#include "../sapi.h"

class SBan : public Sapi {
    Q_OBJECT
public:
    explicit SBan(const QJsonObject &achievement, QObject *parent = nullptr): Sapi(parent),
        _steamId(achievement.value("steamid").toString()),
        _communityBanned(achievement.value("CommunityBanned").toBool()),
        _vacBanned(achievement.value("VACBanned").toBool()),
        _numberOfVacBan(achievement.value("NumberOfVACBans").toInt()),
        _daysSinceLastBan(achievement.value("DaysSinceLastBan").toInt()),
        _numberOfGameBans(achievement.value("NumberOfGameBans").toInt()),
        _economyBan(achievement.value("EconomyBan").toString()) {

        }
    SBan(const SBan &ban): Sapi(ban.parent()), _steamId(ban._steamId), _communityBanned(ban._communityBanned),
        _vacBanned(ban._vacBanned), _numberOfVacBan(ban._numberOfVacBan), _daysSinceLastBan(ban._daysSinceLastBan),
        _numberOfGameBans(ban._numberOfGameBans), _economyBan(ban._economyBan) {

        }

    SBan &operator=(const SBan &ban);
    bool  operator<(const SBan &ban) const;
    bool  operator>(const SBan &ban) const;
    bool  operator==(const SBan &ban) const;
    bool  operator!=(const SBan &ban) const;

    QJsonObject toJson() const;
    virtual QString className() const {return "SBan";}
    static QList<SBan> load(const QString &aId, std::function<void (QList<SBan>)> aCallback = nullptr);

    QString steamId()       const {return _steamId;}
    bool communityBanned()  const {return _communityBanned;}
    bool vacBanned()        const {return _vacBanned;}
    int numberOfVacBan()    const {return _numberOfVacBan;}
    int daysSinceLastBan()  const {return _daysSinceLastBan;}
    int numberOfGameBans()  const {return _numberOfGameBans;}
    QString economyBan()    const {return _economyBan;}

private:
    QString _steamId;
    bool    _communityBanned;
    bool    _vacBanned;
    int     _numberOfVacBan;
    int     _daysSinceLastBan;
    int     _numberOfGameBans;
    QString _economyBan;

};
#endif // SBANS_H
