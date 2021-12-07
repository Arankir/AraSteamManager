#include "sfriends.h"

#define SFriendStart {
SFriend &SFriend::operator=(const SFriend &aFriend) {
    _steamID = aFriend._steamID;
    _relationship = aFriend._relationship;
    _friendSince = aFriend._friendSince;
    return *this;
}

bool SFriend::operator<(const SFriend &aFriend) const {
    return _steamID.toLower() < aFriend._steamID.toLower();
}

bool SFriend::operator>(const SFriend &aFriend) const {
    return _steamID.toLower() > aFriend._steamID.toLower();
}

bool SFriend::operator==(const SFriend &aFriend) const {
    return (_steamID == aFriend._steamID &&
            _relationship == aFriend._relationship &&
            _friendSince == aFriend._friendSince);
}

bool SFriend::operator!=(const SFriend &aFriend) const {
    return (_steamID != aFriend._steamID ||
            _relationship != aFriend._relationship ||
            _friendSince != aFriend._friendSince);
}

QList<SFriend> onLoadFriend(const QByteArray &byteArray) {
    QList<SFriend> list;
    for(auto &&ban: QJsonDocument::fromJson(byteArray).object().value("friendslist").toObject().value("friends").toArray()) {
        list.append(SFriend(ban.toObject()));
    }
    return list;
}

QJsonObject SFriend::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["steamid"] = _steamID;
    obj["relationship"] = _relationship;
    obj["friend_since"] = _friendSince.toSecsSinceEpoch();
    return obj;
}

SFriends SFriend::load(const ProfileID &aId, std::function<void (SFriends)> aCallback) {
    return Sapi::load<SFriend>(friendsUrl(aId), onLoadFriend, aCallback);
}
#define SFriendEnd }
