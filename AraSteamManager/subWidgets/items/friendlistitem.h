#ifndef FRIENDLISTITEM_H
#define FRIENDLISTITEM_H

#include <QStandardItem>

#include "classes/steamApi/structures/sprofile.h"

namespace FriendListItemData {
    enum ProfileType {
        Unknown = 0,
        FriendWithGame = 1,
        FriendWithoutGame = 2,
        NotFriend = 3
    };
}

class FriendListItem : public QStandardItem {
public:
    FriendListItem(const SProfile &profile, const FriendListItemData::ProfileType &type = FriendListItemData::ProfileType::Unknown);
    const SProfile &profile() const;
    virtual QVariant data(int role = Qt::UserRole + 1) const override;

    FriendListItemData::ProfileType profileType() const;

private:
    SProfile profile_;
    FriendListItemData::ProfileType profileType_ = FriendListItemData::ProfileType::Unknown;
};

#endif // FRIENDLISTITEM_H
