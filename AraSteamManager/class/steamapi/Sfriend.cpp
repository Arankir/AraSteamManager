#include "Sfriend.h"

SFriend::SFriend(QJsonObject ObjFriend, QObject *parent) : QObject(parent){
    Set(ObjFriend);
}
SFriend::SFriend(){

}

void SFriend::Set(QJsonObject ObjFriend){
    friendd=ObjFriend;
}

SFriend::SFriend( const SFriend & a){
    friendd=a.friendd;
}
SFriend & SFriend::operator=(const SFriend & friends) {
    friendd=friends.friendd;
    return *this;
}
