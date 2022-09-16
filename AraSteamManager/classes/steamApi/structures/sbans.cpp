#include "sbans.h"

#include <QJsonDocument>
#include <QJsonArray>

QList<SBan> onLoadBan(const QByteArray &aByteArray) {
    QList<SBan> list;
    for(auto &&ban: QJsonDocument::fromJson(aByteArray).object().value("players").toArray()) {
        list.append(SBan(ban.toObject()));
    }
    return list;
}

QJsonObject SBan::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["steamid"] = steamId_;
    obj["CommunityBanned"] = communityBanned_;
    obj["VACBanned"] = vacBanned_;
    obj["NumberOfVACBans"] = numberOfVacBan_;
    obj["DaysSinceLastBan"] = daysSinceLastBan_;
    obj["NumberOfGameBans"] = numberOfGameBans_;
    obj["EconomyBan"] = economyBan_;
    return obj;
}

SBans SBan::load(const ProfileID &aProfileId, std::function<void (SBans)> aCallback) {
    return Sapi::load<SBan>(bansUrl(aProfileId), onLoadBan, aCallback);
}

ProfileID SBan::steamId() const {
    return steamId_;
}

bool SBan::communityBanned() const {
    return communityBanned_;
}

bool SBan::vacBanned() const {
    return vacBanned_;
}

int SBan::numberOfVacBan() const {
    return numberOfVacBan_;
}

int SBan::daysSinceLastBan() const {
    return daysSinceLastBan_;
}

int SBan::numberOfGameBans() const {
    return numberOfGameBans_;
}

QString SBan::economyBan() const {
    return economyBan_;
}

SBan::SBan(const QJsonObject &aAchievement, QObject *aParent): Sapi(aParent),
    steamId_(aAchievement.value("steamid").toString()),
    communityBanned_(aAchievement.value("CommunityBanned").toBool()),
    vacBanned_(aAchievement.value("VACBanned").toBool()),
    numberOfVacBan_(aAchievement.value("NumberOfVACBans").toInt()),
    daysSinceLastBan_(aAchievement.value("DaysSinceLastBan").toInt()),
    numberOfGameBans_(aAchievement.value("NumberOfGameBans").toInt()),
    economyBan_(aAchievement.value("EconomyBan").toString()) {

}

SBan::SBan(const SBan &aBan): Sapi(aBan.parent()), steamId_(aBan.steamId_), communityBanned_(aBan.communityBanned_),
    vacBanned_(aBan.vacBanned_), numberOfVacBan_(aBan.numberOfVacBan_), daysSinceLastBan_(aBan.daysSinceLastBan_),
    numberOfGameBans_(aBan.numberOfGameBans_), economyBan_(aBan.economyBan_) {

}

SBan &SBan::operator=(const SBan &aBan) {
    steamId_ = aBan.steamId_;
    communityBanned_ = aBan.communityBanned_;
    vacBanned_ = aBan.vacBanned_;
    numberOfVacBan_ = aBan.numberOfVacBan_;
    daysSinceLastBan_ = aBan.daysSinceLastBan_;
    numberOfGameBans_ = aBan.numberOfGameBans_;
    economyBan_ = aBan.economyBan_;
    return *this;
}

bool SBan::operator<(const SBan &aBan) const {
    return steamId_ < aBan.steamId_;
}

bool SBan::operator>(const SBan &aBan) const {
    return steamId_ > aBan.steamId_;
}

bool SBan::operator==(const SBan &aBan) const {
    return (steamId_ == aBan.steamId_ &&
            communityBanned_ == aBan.communityBanned_ &&
            vacBanned_ == aBan.vacBanned_ &&
            numberOfVacBan_ == aBan.numberOfVacBan_ &&
            daysSinceLastBan_ == aBan.daysSinceLastBan_ &&
            numberOfGameBans_ == aBan.numberOfGameBans_ &&
            economyBan_ == aBan.economyBan_);
}

bool SBan::operator!=(const SBan &aBan) const {
    return (steamId_ != aBan.steamId_ ||
            communityBanned_ != aBan.communityBanned_ ||
            vacBanned_ != aBan.vacBanned_ ||
            numberOfVacBan_ != aBan.numberOfVacBan_ ||
            daysSinceLastBan_ != aBan.daysSinceLastBan_ ||
            numberOfGameBans_ != aBan.numberOfGameBans_ ||
            economyBan_ != aBan.economyBan_);
}
