#ifndef COMBOBOXFRIENDSWITHGAME_H
#define COMBOBOXFRIENDSWITHGAME_H
#pragma once

#include <QCheckBox>
#include "./qcomboboxfriends.h"
#include "subWidgets/items/qlistwidgetfriend.h"

class ComboBoxFriendsWithGame : public ComboBoxFriends {
    Q_OBJECT

public:
    ComboBoxFriendsWithGame(QWidget *parent = nullptr);
    void addItem(const SProfile &profile, const FriendType &type);

protected:
    void addFilterWidgets() override;

private:
    void onAllFriends(const int &state);

    QCheckBox *checkBoxAllFriends_;
};

#endif // COMBOBOXFRIENDSWITHGAME_H
