#include "sfriends.h"

#define SFriendStart {
SFriend &SFriend::operator=(const SFriend &) {
//TODO почему здесь пусто? посмотреть почему оставил пустым
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
        list.append(std::move(SFriend(ban.toObject())));
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

QList<SFriend> SFriend::load(const QString &aId, std::function<void (QList<SFriend>)> aCallback) {
    return Sapi::load<SFriend>(friendsUrl(aId), onLoadFriend, aCallback);
}
#define SFriendEnd }
