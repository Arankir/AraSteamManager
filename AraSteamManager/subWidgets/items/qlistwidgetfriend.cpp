#include "qlistwidgetfriend.h"

QListWidgetFriend::QListWidgetFriend(SProfile *steamFriend, FriendType type):
                    QListWidgetItem(),
                    _steamFriend(steamFriend),
                    _type(type) {

}

QListWidgetFriend::~QListWidgetFriend() {

}

QListWidgetFriend &QListWidgetFriend::operator=(const QListWidgetFriend &aItem) {
    QListWidgetItem::operator=(aItem);
    _steamFriend = aItem._steamFriend;
    _type = aItem._type;
    return *this;
}

bool QListWidgetFriend::operator==(const QListWidgetFriend &aItem) {
    return ((_steamFriend == aItem._steamFriend) && (_type == aItem._type));
}
