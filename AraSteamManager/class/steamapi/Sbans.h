#ifndef SBANS_H
#define SBANS_H

#include "class/steamapi/Sapi.h"

class SBans : public Sapi
{
    Q_OBJECT
public:
    explicit SBans(const QString &id, bool parallel, QObject *parent = nullptr);
    SBans(QObject *parent = nullptr): Sapi(parent) {}
    ~SBans() {}

    SBans &load(const QString &id, bool parallel);
    SBans &update(bool parallel);

    QString getSteamid(int index = 0) const;
    bool getCommunityBanned(int index = 0) const;
    bool getVacBanned(int index = 0) const;
    int getNumberOfVacBans(int index = 0) const;
    int getDaysSinceLastBan(int index = 0) const;
    int getNumberOfGameBans(int index = 0) const;
    QString getEconomyBan(int index = 0) const;

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QJsonArray _bans;
    QString _id;
};
#endif // SBANS_H
