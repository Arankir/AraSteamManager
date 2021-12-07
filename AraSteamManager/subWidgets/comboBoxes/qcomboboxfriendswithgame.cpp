#include "qcomboboxfriendswithgame.h"
#include <QLineEdit>
#include <QEvent>

const int c_allFriendsIndex = 1;

ComboBoxFriendsWithGame::ComboBoxFriendsWithGame(QWidget *aParent):
                                ComboBoxFriends(aParent) {
    mCountFilterWidgets = 2;
    clear();
}

void ComboBoxFriendsWithGame::addFilterWidgets() {
    ComboBoxFriends::addFilterWidgets();

    QListWidgetItem* curItem2 = new QListWidgetItem(mListWidget);
    mListWidget->addItem(curItem2);

    mAllFriends = new QCheckBox(tr("Все друзья"));
    mListWidget->setItemWidget(curItem2, mAllFriends);
    connect(mAllFriends, &QCheckBox::stateChanged, this, &ComboBoxFriendsWithGame::onAllFriends);
}

void ComboBoxFriendsWithGame::addItem(const SProfile &steamFriend, FriendType type) {
    QListWidgetFriend *item = new  QListWidgetFriend(steamFriend, type);
    item->setText(steamFriend.personaName());
    item->setIcon(steamFriend.pixmapAvatar());
    mListWidget->addItem(item);
    onAllFriends(static_cast<int>(mAllFriends->isChecked()) * 2);
}

void ComboBoxFriendsWithGame::onAllFriends(int aState) {
    switch (aState) {
    case 0: {
        for(int i = mCountFilterWidgets; i < mListWidget->count(); ++i) {
            auto steamFriend = dynamic_cast<QListWidgetFriend*>(mListWidget->item(i));
            if (steamFriend) {
                mListWidget->item(i)->setHidden(steamFriend->_type != FriendType::haveGame);
            }
        }
        break;
    }
    case 2: {
        for (int i = mCountFilterWidgets; i < mListWidget->count(); ++i) {
            mListWidget->item(i)->setHidden(false);
        }
        break;
    }
    }
    hidePopup();
    showPopup();
}
