#ifndef SFRIENDS_H
#define SFRIENDS_H

#include "./sprofile.h"
#include "../sapi.h"

class SFriend : public Sapi {
    Q_OBJECT
public:
    SFriend(const QJsonObject &object = QJsonObject(), QObject *parent = nullptr);
    SFriend(const SFriend &steamFriend);

    QJsonObject toJson() const;
    static QList<SFriend> load(const ProfileID &profileId, std::function<void (QList<SFriend>)> callback = nullptr);
    SFriend &operator=(const SFriend&);
    bool operator<(const SFriend&) const;
    bool operator>(const SFriend&) const;
    bool operator==(const SFriend&) const;
    bool operator!=(const SFriend&) const;

    ProfileID steamId()     const;
    QString relationship()  const;
    QDateTime friendSince() const;

    static QStringList getFriendsSteamId(const ProfileID &profileId);

private:
    ProfileID steamId_;
    QString relationship_;
    QDateTime friend_since_;

};

using SFriends = QList<SFriend>;

struct SFriendProfile {
    SFriendProfile(const SFriend &steamFriend, const SProfile &profile);
    SFriendProfile(const SProfile &profile, const SFriend &steamFriend);
    SFriend steamFriend;
    SProfile steamProfile;
};

#endif // SFRIENDS_H
