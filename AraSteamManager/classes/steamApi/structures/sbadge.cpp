#include "sbadge.h"
#include <QJsonDocument>
#include <QJsonArray>

SBadge::SBadge(QObject *parent): Sapi{parent} {

}

SBadge::SBadge(const SBadge &aCopy): Sapi{aCopy.parent()}, badgeid_{aCopy.badgeid_}, appid_{aCopy.appid_}, level_{aCopy.level_},
    completion_time_{aCopy.completion_time_}, xp_{aCopy.xp_}, communityitemid_{aCopy.communityitemid_},
    border_color_{aCopy.border_color_}, scarcity_{aCopy.scarcity_} {

}

SBadge::SBadge(const QJsonObject &aObject, QObject *parent): Sapi{parent} {
    fromJson(aObject);
}

SBadge &SBadge::operator=(const SBadge &aBadge) {
    badgeid_ = aBadge.badgeid_;
    appid_ = aBadge.appid_;
    level_ = aBadge.level_;
    completion_time_ = aBadge.completion_time_;
    xp_ = aBadge.xp_;
    communityitemid_ = aBadge.communityitemid_;
    border_color_ = aBadge.border_color_;
    scarcity_ = aBadge.scarcity_;
    return *this;
}

bool SBadge::operator<(const SBadge &aBadge) const {
    return communityitemid_ < aBadge.communityitemid_;
}

bool SBadge::operator>(const SBadge &aBadge) const {
    return communityitemid_ > aBadge.communityitemid_;
}

bool SBadge::operator==(const SBadge &aBadge) const {
    return badgeid_ == aBadge.badgeid_ &&
            appid_ == aBadge.appid_ &&
            level_ == aBadge.level_ &&
            completion_time_ == aBadge.completion_time_ &&
            xp_ == aBadge.xp_ &&
            communityitemid_ == aBadge.communityitemid_ &&
            border_color_ == aBadge.border_color_ &&
            scarcity_ == aBadge.scarcity_;
}

bool SBadge::operator!=(const SBadge &aBadge) const {
    return badgeid_ != aBadge.badgeid_ ||
            appid_ != aBadge.appid_ ||
            level_ != aBadge.level_ ||
            completion_time_ != aBadge.completion_time_ ||
            xp_ != aBadge.xp_ ||
            communityitemid_ != aBadge.communityitemid_ ||
            border_color_ != aBadge.border_color_ ||
            scarcity_ != aBadge.scarcity_;
}

QJsonObject SBadge::toJson() const {
    QJsonObject object;
    object["badgeid"] = badgeid_;
    object["appid"] = appid_;
    object["level"] = level_;
    object["completion_time"] = completion_time_.toSecsSinceEpoch();
    object["xp"] = xp_;
    object["communityitemid"] = communityitemid_;
    object["border_color"] = border_color_;
    object["scarcity"] = scarcity_;
    return object;
}

void SBadge::fromJson(const QJsonObject &aObject) {
    badgeid_ = aObject.value("badgeid").toInt();
    appid_ = aObject.value("appid").toInt();
    level_ = aObject.value("level").toInt();
    completion_time_ = QDateTime::fromSecsSinceEpoch(aObject.value("completion_time").toInt(), Qt::LocalTime);
    xp_ = aObject.value("xp").toInt();
    communityitemid_ = aObject.value("communityitemid").toInt();
    border_color_ = aObject.value("border_color").toInt();
    scarcity_ = aObject.value("scarcity").toInt();
}

SBadges onLoadBadges(const QByteArray &byteArray) {
    SBadges list;
    for(const auto &badge: QJsonDocument::fromJson(byteArray).object().value("response").toObject().value("badges").toArray()) {
        list.append(SBadge(badge.toObject()));
    }
    return list;
}

QList<SBadge> SBadge::load(const ProfileID &aProfileId, std::function<void (QList<SBadge>)> aCallback) {
    return Sapi::load<SBadge>(badgesUrl(aProfileId), onLoadBadges, aCallback);
}

void SBadge::getXpInfo(const ProfileID &aProfileId, int &aPlayerXp, int &aPlayerLevel, int &aPlayerXpNeededToLevelUp, int &aPlayerXpNeededCurrentLevel) {
    aPlayerXp = 0;
    aPlayerLevel = 0;
    aPlayerXpNeededToLevelUp = 0;
    aPlayerXpNeededCurrentLevel = 0;
    RequestData request;
    request.get(badgesUrl(aProfileId), false);
    auto object = QJsonDocument::fromJson(request.reply()).object().value("response").toObject();
    aPlayerXp = object.value("player_xp").toInt();
    aPlayerLevel = object.value("player_level").toInt();
    aPlayerXpNeededToLevelUp = object.value("player_xp_needed_to_level_up").toInt();
    aPlayerXpNeededCurrentLevel = object.value("player_xp_needed_current_level").toInt();
}

int SBadge::badgeid() const {
    return badgeid_;
}

GameID SBadge::appid() const {
    return appid_;
}

int SBadge::level() const {
    return level_;
}

QDateTime SBadge::completion_time() const {
    return completion_time_;
}

int SBadge::xp() const {
    return xp_;
}

int SBadge::communityitemid() const {
    return communityitemid_;
}

int SBadge::border_color() const {
    return border_color_;
}

int SBadge::scarcity() const {
    return scarcity_;
}
