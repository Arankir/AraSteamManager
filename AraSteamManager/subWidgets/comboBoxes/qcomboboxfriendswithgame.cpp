#include "qcomboboxfriendswithgame.h"
#include <QLineEdit>
#include <QEvent>

const int c_allFriendsIndex = 1;

ComboBoxFriendsWithGame::ComboBoxFriendsWithGame(QWidget *aParent):
                                ComboBoxFriends(aParent) {
    countStaticWidgets_ = 2;
    clear();
}

void ComboBoxFriendsWithGame::addFilterWidgets() {
    ComboBoxFriends::addFilterWidgets();

    QListWidgetItem* curItem2 = new QListWidgetItem(listWidgetItems_);
    listWidgetItems_->addItem(curItem2);

    checkBoxAllFriends_ = new QCheckBox(tr("Все друзья"));
    listWidgetItems_->setItemWidget(curItem2, checkBoxAllFriends_);
    connect(checkBoxAllFriends_, &QCheckBox::stateChanged, this, &ComboBoxFriendsWithGame::onAllFriends);
}

void ComboBoxFriendsWithGame::addItem(const SProfile &profile, const FriendType &type) {
    QListWidgetFriend *item = new  QListWidgetFriend(profile, type);
    item->setText(profile.personaName());
    item->setIcon(profile.pixmapAvatar());
    listWidgetItems_->addItem(item);
    if (!checkBoxAllFriends_->isChecked() && item->_type != FriendType::haveGame) {
        item->setHidden(true);
    }
}

void ComboBoxFriendsWithGame::onAllFriends(const int &aState) {
    switch (aState) {
    case 0: {
        for(int i = countStaticWidgets_; i < listWidgetItems_->count(); ++i) {
            auto steamFriend = dynamic_cast<QListWidgetFriend*>(listWidgetItems_->item(i));
            if (steamFriend) {
                listWidgetItems_->item(i)->setHidden(steamFriend->_type != FriendType::haveGame);
            }
        }
        break;
    }
    case 2: {
        for (int i = countStaticWidgets_; i < listWidgetItems_->count(); ++i) {
            listWidgetItems_->item(i)->setHidden(false);
        }
        break;
    }
    }
    hidePopup();
    showPopup();
}
