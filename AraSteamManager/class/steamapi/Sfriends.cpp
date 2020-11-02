#include "Sfriends.h"

#define SFriendStart {
SFriend &SFriend::operator=(const SFriend &) {
    return *this;
}

const bool &SFriend::operator<(const SFriend &aFriend) {
    static const bool b = _steamID.toLower() < aFriend._steamID.toLower();
    return b;
}
#define SFriendEnd }
#define SFriendsStart {
SFriends::SFriends(const QString &aId, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aParallel);
}

SFriends &SFriends::load(const QString &aId, bool aParallel) {
    _id = aId;
    _request.get(friendsUrl(_id), aParallel);
    return *this;
}

void SFriends::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("friendslist").toObject().value("friends"));
    emit s_finished();
}

void SFriends::fromJson(const QJsonValue &aValue) {
    clear();
    if (aValue.toArray().size() > 0) {
        for (const auto &friendP: aValue.toArray()) {
            _friends.append(std::move(SFriend(friendP.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("friends is not exist");
    }
}

SProfiles SFriends::getProfiles() const {
    QStringList ids;
    for (auto steamFriend: _friends) {
        ids << steamFriend._steamID;
    }
    return SProfiles(ids, false, ProfileUrlType::id);
}

SFriends &SFriends::update(bool aParallel) {
    load(_id, aParallel);
    return *this;
}

SFriends &SFriends::clear() {
    _friends.clear();
    _status = StatusValue::none;
    return *this;
}

SFriends &SFriends::sort() {
    std::sort(_friends.begin(), _friends.end());
    return *this;
}

SFriends::SFriends(const SFriends &aFriends) {
    _status     = aFriends._status;
    _error      = aFriends._error;

    _friends    = aFriends._friends;
    _id         = aFriends._id;
}

SFriends &SFriends::operator=(const SFriends &aFriends) {
    Sapi::operator=(aFriends);
    _friends    = aFriends._friends;
    _id         = aFriends._id;
    return *this;
}
#define SFriendsEnd }
