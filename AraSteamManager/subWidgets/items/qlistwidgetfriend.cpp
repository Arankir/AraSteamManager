#include "qlistwidgetfriend.h"

QListWidgetFriend::QListWidgetFriend(SProfile *steamFriend, FriendType type):
                    QListWidgetItem(),
                    _steamFriend(new SProfile(*steamFriend)),
                    _type(type) {
    //Посмотреть откуда он берет друзей, скорее всего они там удаляются и из-за этого все крашится
}

QListWidgetFriend::~QListWidgetFriend() {
    delete _steamFriend;
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
