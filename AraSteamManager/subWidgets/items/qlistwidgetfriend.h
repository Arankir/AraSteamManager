#ifndef QLISTWIDGETFRIENDS_H
#define QLISTWIDGETFRIENDS_H

#include <QListWidgetItem>
#include "classes/steamApi/structures/sfriends.h"

enum class FriendType {
    none,
    haventGame,
    haveGame
};

class QListWidgetFriend : public QListWidgetItem {
public:
    QListWidgetFriend(const SProfile &steamFriend, FriendType type = FriendType::none);
    QListWidgetFriend(): QListWidgetItem() {}

    QListWidgetFriend &operator=(const QListWidgetFriend&);
    bool operator==(const QListWidgetFriend&);

    SProfile _steamFriend;
    FriendType _type = FriendType::none;
};

#endif // QLISTWIDGETFRIENDS_H
