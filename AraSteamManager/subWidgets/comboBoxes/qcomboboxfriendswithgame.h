#pragma once

#include "./qcomboboxfriends.h"

class ComboBoxFriendsWithGame : public ComboBoxFriends {
    Q_OBJECT

public:
    ComboBoxFriendsWithGame(QWidget *parent = nullptr);
    void addItem(const SProfile &steamFriend, FriendType type);

protected:
    void addFilterWidgets() override;

private:
    void onAllFriends(int state);

    QCheckBox *mAllFriends;
};
