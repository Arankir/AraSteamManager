#include "Sfriend.h"

SFriend::SFriend(QJsonObject Afriend, QObject *parent) : QObject(parent){
    _friend=Afriend;
}
SFriend::SFriend(){

}

void SFriend::Set(QJsonObject Afriend){
    _friend=Afriend;
}

SFriend::SFriend( const SFriend & AnewFriend){
    _friend=AnewFriend._friend;
}
SFriend & SFriend::operator=(const SFriend & AnewFriend) {
    _friend=AnewFriend._friend;
    return *this;
}
