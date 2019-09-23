#include "steamapifriend.h"

SteamAPIFriend::SteamAPIFriend(QJsonObject ObjFriend, QObject *parent) : QObject(parent){
    Set(ObjFriend);
}
SteamAPIFriend::SteamAPIFriend(){

}

void SteamAPIFriend::Set(QJsonObject ObjFriend){
    friendd=ObjFriend;
}

SteamAPIFriend::SteamAPIFriend( const SteamAPIFriend & a){
    friendd=a.friendd;
}
SteamAPIFriend & SteamAPIFriend::operator=(const SteamAPIFriend & friends) {
    friendd=friends.friendd;
    return *this;
}
