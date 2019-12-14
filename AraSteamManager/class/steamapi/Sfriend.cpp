#include "Sfriend.h"

SFriend::SFriend(QJsonObject AFriend, QObject *parent) : QObject(parent){
    _friend=AFriend;
}
SFriend::SFriend(){

}

void SFriend::Set(QJsonObject AFriend){
    _friend=AFriend;
}

SFriend::SFriend( const SFriend & ANewFriend){
    _friend=ANewFriend._friend;
}
SFriend & SFriend::operator=(const SFriend & ANewFriend) {
    _friend=ANewFriend._friend;
    return *this;
}
