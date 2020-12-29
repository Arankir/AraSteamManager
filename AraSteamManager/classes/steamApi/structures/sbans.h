#ifndef SBANS_H
#define SBANS_H

#include "../sapi.h"

class SBan : public QObject {
    Q_OBJECT
public:
    explicit SBan(const QJsonObject &achievement, QObject *parent = nullptr): QObject(parent),
        _steamId(achievement.value("steamid").toString()),
        _communityBanned(achievement.value("CommunityBanned").toBool()),
        _vacBanned(achievement.value("VACBanned").toBool()),
        _numberOfVacBan(achievement.value("NumberOfVACBans").toInt()),
        _daysSinceLastBan(achievement.value("DaysSinceLastBan").toInt()),
        _numberOfGameBans(achievement.value("NumberOfGameBans").toInt()),
        _economyBan(achievement.value("EconomyBan").toString()) {

        }
    SBan(const SBan &ban): QObject(ban.parent()), _steamId(ban._steamId), _communityBanned(ban._communityBanned),
        _vacBanned(ban._vacBanned), _numberOfVacBan(ban._numberOfVacBan), _daysSinceLastBan(ban._daysSinceLastBan),
        _numberOfGameBans(ban._numberOfGameBans), _economyBan(ban._economyBan) {

        }
    SBan &operator=(const SBan &ban);

    QString steamId()       {return _steamId;}
    bool communityBanned()  {return _communityBanned;}
    bool vacBanned()        {return _vacBanned;}
    int numberOfVacBan()    {return _numberOfVacBan;}
    int daysSinceLastBan()  {return _daysSinceLastBan;}
    int numberOfGameBans()  {return _numberOfGameBans;}
    QString economyBan()    {return _economyBan;}

private:
    QString _steamId;
    bool    _communityBanned;
    bool    _vacBanned;
    int     _numberOfVacBan;
    int     _daysSinceLastBan;
    int     _numberOfGameBans;
    QString _economyBan;

};

class SBans : public Sapi
{
    Q_OBJECT
public:
    explicit SBans(const QString &id, bool parallel, QObject *parent = nullptr);
    SBans(QObject *parent = nullptr): Sapi(parent) {}
    SBan &operator[](const int &index) {return _bans[index];}
    ~SBans() {}

    SBans &load(const QString &id, bool parallel);
    SBans &update(bool parallel);
    SBans &clear();

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SBan> _bans;
    QString _id;
};
#endif // SBANS_H
