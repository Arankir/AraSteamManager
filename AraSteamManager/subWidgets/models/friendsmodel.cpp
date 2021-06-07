#include "friendsmodel.h"

int FriendsModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return FriendsCount;
}

int FriendsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _friends.count();
}

QVariant FriendsModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _friends.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case FriendsID: {
            return _friends[index.row()].first.steamId();
        }
        case FriendsIndex: {
            return index.row();
        }
        case FriendsName: {
            return _friends[index.row()].second.personaName();
        }
        case FriendsAdded: {
            return _friends[index.row()].first.friendSince().toString(Settings::dateTimeFormatShort());
        }
        case FriendsStatus: {
            return _friends[index.row()].second.stateText();
        }
        case FriendsIsPublic: {
            return _friends[index.row()].second.communityVisibilityState() == 3 ? isPublicTitle() : tr("Скрытый");
        }
        }
    }
    if (role == Qt::DecorationRole) {
        if (index.column() == FriendsIcon) {
            return _friends[index.row()].second.pixmapAvatar();
        }
    }
    if (role == Qt::ForegroundRole) {
        if (index.column() == FriendsStatus) {
            return _friends[index.row()].second.stateColor();
        }
        if (index.column() == FriendsIsPublic) {
            return _friends[index.row()].second.communityVisibilityState() == 3 ? QColor(105,155,44) : QColor(155,44,44);
        }
    }
    return QVariant();
}

QVariant FriendsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section) {
        case FriendsID: {
            return tr("ID");
        }
        case FriendsIndex: {
            return tr("Index");
        }
        case FriendsIcon: {
            return tr("");
        }
        case FriendsName: {
            return tr("Ник");
        }
        case FriendsAdded: {
            return tr("Добавлен");
        }
        case FriendsStatus: {
            return tr("Статус");
        }
        case FriendsIsPublic: {
            return tr("Профиль");
        }
        default: {
            return QVariant();
        }
        }
    else
        return QString("%1").arg(section);
}

QString FriendsModel::friendId(const QModelIndex &index) const {
    return _friends[index.row()].first.steamId();
}

QString FriendsModel::isPublicTitle() {
    return tr("Публичный");
}

void FriendsModel::sort(int column, Qt::SortOrder order) {
    qDebug() << 1 << column << order;
    switch (column) {
    case FriendsID: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.first.steamId() < f2.first.steamId();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.first.steamId() > f2.first.steamId();});
            break;
        }
        }
        break;
    }
    case FriendsIndex: {
        break;
    }
    case FriendsIcon: {
        break;
    }
    case FriendsName: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.personaName() < f2.second.personaName();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.personaName() > f2.second.personaName();});
            break;
        }
        }
        break;
    }
    case FriendsAdded: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.first.friendSince() < f2.first.friendSince();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.first.friendSince() > f2.first.friendSince();});
            break;
        }
        }
        break;
    }
    case FriendsStatus: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.stateText() < f2.second.stateText();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.stateText() > f2.second.stateText();});
            break;
        }
        }
        break;
    }
    case FriendsIsPublic: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.communityVisibilityState() < f2.second.communityVisibilityState();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<QPair<SFriend, SProfile>>(_friends, [](QPair<SFriend, SProfile> &f1, QPair<SFriend, SProfile> &f2) {return f1.second.communityVisibilityState() > f2.second.communityVisibilityState();});
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

QPair<SFriend, SProfile> FriendsModel::getFriend(const int &row) const {
    return _friends[row];
}

ProxyModelFriends::ProxyModelFriends(QObject *aParent): QSortFilterProxyModel(aParent),
    _name(""), _status(""), _public(), _favorite() {

}

bool ProxyModelFriends::filterAcceptsRow(int aSource_row, const QModelIndex &aSource_parent) const {
    QModelIndex indName = sourceModel()->index(aSource_row, FriendsName, aSource_parent);
    QModelIndex indStatus = sourceModel()->index(aSource_row, FriendsStatus, aSource_parent);
    QModelIndex indPublic = sourceModel()->index(aSource_row, FriendsIsPublic, aSource_parent);
    QModelIndex indId = sourceModel()->index(aSource_row, FriendsID, aSource_parent);
    if(sourceModel()->data(indName).toString().toLower().indexOf(_name.toLower()) == -1 ||
       (_status.isEmpty() ? false : sourceModel()->data(indStatus).toString().toLower() != _status.toLower()) ||
       sourceModel()->data(indPublic).toString().indexOf(_public > 0 ? FriendsModel::isPublicTitle() : "") == -1 ||
       (_favorite.isEmpty() ? false : _favorite.indexOf(sourceModel()->data(indId).toString()) == -1))
        return false;
    return true;
}

QVariant ProxyModelFriends::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

FriendsModel *ProxyModelFriends::sourceModel() const {
    return static_cast<FriendsModel*>(QSortFilterProxyModel::sourceModel());
}

void ProxyModelFriends::setSourceModel(FriendsModel *sourceModel) {
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

void ProxyModelFriends::setName(const QString &aNewName) {
    if(_name != aNewName)
        _name = aNewName;
    invalidateFilter();
}

void ProxyModelFriends::setStatus(const QString &aNewStatus) {
    if(_status != aNewStatus)
        _status = aNewStatus;
    invalidateFilter();

}

void ProxyModelFriends::setIsPublic(const int &aIsPublic) {
    if(_public != aIsPublic)
        _public = aIsPublic;
    invalidateFilter();
}

void ProxyModelFriends::setFavorites(const QStringList &aNewFavorites) {
    if(_favorite != aNewFavorites)
        _favorite = aNewFavorites;
    invalidateFilter();
}

void ProxyModelFriends::clear() {
    _name.clear();
    _status.clear();
    _public = 0;
    _favorite.clear();
}
