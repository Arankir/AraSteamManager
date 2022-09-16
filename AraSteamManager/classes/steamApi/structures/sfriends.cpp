#include "sfriends.h"

#include <QJsonDocument>
#include <QJsonArray>

#define SFriendStart {
SFriend &SFriend::operator=(const SFriend &aFriend) {
    steamId_ = aFriend.steamId_;
    relationship_ = aFriend.relationship_;
    friend_since_ = aFriend.friend_since_;
    return *this;
}

bool SFriend::operator<(const SFriend &aFriend) const {
    return steamId_.toLower() < aFriend.steamId_.toLower();
}

bool SFriend::operator>(const SFriend &aFriend) const {
    return steamId_.toLower() > aFriend.steamId_.toLower();
}

bool SFriend::operator==(const SFriend &aFriend) const {
    return (steamId_ == aFriend.steamId_ &&
            relationship_ == aFriend.relationship_ &&
            friend_since_ == aFriend.friend_since_);
}

bool SFriend::operator!=(const SFriend &aFriend) const {
    return (steamId_ != aFriend.steamId_ ||
            relationship_ != aFriend.relationship_ ||
            friend_since_ != aFriend.friend_since_);
}

ProfileID SFriend::steamId() const {
    return steamId_;
}

QString SFriend::relationship() const {
    return relationship_;
}

QDateTime SFriend::friendSince() const {
    return friend_since_;
}

QStringList SFriend::getFriendsSteamId(const ProfileID &aProfileId) {
    QStringList list;
    for(const SFriend &sFriend: SFriend::load(aProfileId)) {
        list.append(sFriend.steamId());
    }
    return list;
}

QList<SFriend> onLoadFriend(const QByteArray &aByteArray) {
    QList<SFriend> list;
    for(auto &&ban: QJsonDocument::fromJson(aByteArray).object().value("friendslist").toObject().value("friends").toArray()) {
        list.append(SFriend(ban.toObject()));
    }
    return list;
}

SFriend::SFriend(const QJsonObject &aFriend, QObject *aParent): Sapi(aParent), steamId_(aFriend.value("steamid").toString()),
    relationship_(aFriend.value("relationship").toString()),
    friend_since_(QDateTime::fromSecsSinceEpoch(aFriend.value("friend_since").toInt(), Qt::LocalTime)) {

}

SFriend::SFriend(const SFriend &aFriend): Sapi(aFriend.parent()), steamId_(aFriend.steamId_),
    relationship_(aFriend.relationship_), friend_since_(aFriend.friend_since_) {

}

QJsonObject SFriend::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["steamid"] = steamId_;
    obj["relationship"] = relationship_;
    obj["friend_since"] = friend_since_.toSecsSinceEpoch();
    return obj;
}

SFriends SFriend::load(const ProfileID &aProfileId, std::function<void (SFriends)> aCallback) {
    return Sapi::load<SFriend>(friendsUrl(aProfileId), onLoadFriend, aCallback);
}
#define SFriendEnd }

SFriendProfile::SFriendProfile(const SFriend &aFriend, const SProfile &aProfile): steamFriend(aFriend), steamProfile(aProfile) {

}

SFriendProfile::SFriendProfile(const SProfile &aProfile, const SFriend &aFriend): steamFriend(aFriend), steamProfile(aProfile) {

}
