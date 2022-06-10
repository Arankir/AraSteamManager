#ifndef SBANS_H
#define SBANS_H

#include "../sapi.h"

class SBan : public Sapi {
    Q_OBJECT
public:
    SBan(const QJsonObject &achievement, QObject *parent = nullptr);
    SBan(const SBan &ban);

    SBan &operator=(const SBan &ban);
    bool  operator<(const SBan &ban) const;
    bool  operator>(const SBan &ban) const;
    bool  operator==(const SBan &ban) const;
    bool  operator!=(const SBan &ban) const;

    QJsonObject toJson() const;
    virtual QString className() const {return "SBan";}
    static QList<SBan> load(const ProfileID &aId, std::function<void (QList<SBan>)> aCallback = nullptr);

    ProfileID steamId()     const;
    bool communityBanned()  const;
    bool vacBanned()        const;
    int numberOfVacBan()    const;
    int daysSinceLastBan()  const;
    int numberOfGameBans()  const;
    QString economyBan()    const;

private:
    ProfileID   steamId_;
    bool        communityBanned_;
    bool        vacBanned_;
    int         numberOfVacBan_;
    int         daysSinceLastBan_;
    int         numberOfGameBans_;
    QString     economyBan_;

};

using SBans = QList<SBan>;

#endif // SBANS_H
