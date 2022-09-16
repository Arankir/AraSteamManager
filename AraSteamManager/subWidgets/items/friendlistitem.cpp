#include "friendlistitem.h"

using namespace FriendListItemData;

FriendListItem::FriendListItem(const SProfile &profile, const ProfileType &type):
    QStandardItem{profile.pixmapAvatar(), profile.personaName()},
    profile_{profile},
    profileType_{type} {

}

const SProfile &FriendListItem::profile() const {
    return profile_;
}

QVariant FriendListItem::data(int aRole) const {
    switch(aRole) {
    case Qt::ItemDataRole::ForegroundRole: {
        if (profileType_ == FriendWithoutGame) {
            return QColor(255, 0, 0, 255 * 0.5);
        } else {
            return QStandardItem::data(aRole);
        }
    }
    default: {
        return QStandardItem::data(aRole);
    }
    }
}

FriendListItemData::ProfileType FriendListItem::profileType() const {
    return profileType_;
}
