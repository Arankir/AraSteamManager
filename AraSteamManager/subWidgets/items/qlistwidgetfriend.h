#ifndef QLISTWIDGETACHIEVEMENT_H
#define QLISTWIDGETACHIEVEMENT_H

#include <QListWidgetItem>
#include "classes/steamApi/structures/sfriends.h"

enum class FriendType {
    none,
    haventGame,
    haveGame
};

class QListWidgetFriend : public QListWidgetItem {
public:
    QListWidgetFriend(SProfile *steamFriend, FriendType type);
    QListWidgetFriend(): QListWidgetItem() {}
    ~QListWidgetFriend();

    QListWidgetFriend &operator=(const QListWidgetFriend&);
    bool operator==(const QListWidgetFriend&);

    SProfile *_steamFriend = nullptr;
    FriendType _type = FriendType::none;
};

#endif // QLISTWIDGETACHIEVEMENT_H
