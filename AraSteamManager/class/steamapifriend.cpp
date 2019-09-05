#include "steamapifriend.h"

SteamAPIFriend::SteamAPIFriend(QJsonObject ObjFriend, QObject *parent) : QObject(parent){
    Set(ObjFriend);
}
SteamAPIFriend::SteamAPIFriend(){

}

void SteamAPIFriend::Set(QJsonObject ObjFriend){
    steamid=ObjFriend.value("steamid").toString();
    relationship=ObjFriend.value("relationship").toString();
    friend_since=QDateTime::fromSecsSinceEpoch(ObjFriend.value("friend_since").toInt(),Qt::LocalTime);
}

SteamAPIFriend::SteamAPIFriend( const SteamAPIFriend & a){
    steamid=a.steamid;
    relationship=a.relationship;
    friend_since=a.friend_since;
}
SteamAPIFriend & SteamAPIFriend::operator=(const SteamAPIFriend & friends) {
    steamid=friends.steamid;
    relationship=friends.relationship;
    friend_since=friends.friend_since;
    return *this;
}
