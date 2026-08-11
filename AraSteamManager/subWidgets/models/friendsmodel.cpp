#include "friendsmodel.h"
#include "classes/common/settings.h"
#include "classes/common/images.h"
#include <QIcon>

using namespace friendsModel;

FriendsModel::FriendsModel(QObject *parent): QAbstractTableModel(parent) {

}

void FriendsModel::setFriends(const QList<SFriend> &aFriends) {
    clear();
    QStringList listIds;
    for (const SFriend &sFriend: aFriends) {
        listIds.append(sFriend.steamId());
    }
    QList<SProfile> profiles = SProfile::load(listIds);
    std::sort(profiles.begin(),
              profiles.end());
    int progress = 0;
    for(SProfile &profile: profiles) {
        for (const SFriend &currentFriend: aFriends) {
            if (currentFriend.steamId() == profile.steamId()) {
                QIcon *icon = new QIcon(profile.pixmapAvatar());
                icon->addPixmap(profile.pixmapAvatar(), QIcon::Selected);

                friends_.append(item{icon, currentFriend, profile});
                break;
            }
        }
        emit s_progress(tr("Загрузка друзей"), ++progress, profiles.count());
    }
    emit s_finished();
}

int FriendsModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return Count;
}

int FriendsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return friends_.count();
}

QVariant FriendsModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= friends_.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case ID: {
            return friends_[index.row()].steamFriend.steamId();
        }
        case Index: {
            return index.row();
        }
        case Name: {
            return friends_[index.row()].profile.personaName();
        }
        case Added: {
            return friends_[index.row()].steamFriend.friendSince().toString(Settings::dateTimeFormatShort());
        }
        case Status: {
            return friends_[index.row()].profile.stateText();
        }
        case IsPublic: {
            return friends_[index.row()].profile.communityVisibilityState() == 3 ? isPublicTitle() : tr("Скрытый");
        }
        }
    }
    if (role == Qt::DecorationRole) {
        if (index.column() == Name) {
            if (friends_[index.row()].icon == nullptr) {
                return QIcon(Images::missingImage());
            }
            return *(friends_[index.row()].icon);
        }
    }
    if (role == Qt::ForegroundRole) {
        if (index.column() == Status) {
            return friends_[index.row()].profile.stateColor();
        }
        if (index.column() == IsPublic) {
            return friends_[index.row()].profile.communityVisibilityState() == 3 ? QColor(105,155,44) : QColor(155,44,44);
        }
    }
    return QVariant();
}

QVariant FriendsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section) {
        case ID: {
            return tr("ID");
        }
        case Index: {
            return tr("Index");
        }
        case Name: {
            return tr("Ник");
        }
        case Added: {
            return tr("Добавлен");
        }
        case Status: {
            return tr("Статус");
        }
        case IsPublic: {
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
    return friends_[index.row()].steamFriend.steamId();
}

QString FriendsModel::isPublicTitle() {
    return tr("Публичный");
}

void FriendsModel::sort(int column, Qt::SortOrder order) {
    switch (column) {
    case ID: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.steamFriend.steamId() < f2.steamFriend.steamId();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.steamFriend.steamId() > f2.steamFriend.steamId();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Index: {
        break;
    }
    case Name: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.personaName() < f2.profile.personaName();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.personaName() > f2.profile.personaName();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Added: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.steamFriend.friendSince() < f2.steamFriend.friendSince();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.steamFriend.friendSince() > f2.steamFriend.friendSince();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Status: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.stateText() < f2.profile.stateText();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.stateText() > f2.profile.stateText();
                      }
                    );
            break;
        }
        }
        break;
    }
    case IsPublic: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.communityVisibilityState() < f2.profile.communityVisibilityState();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(friends_.begin(),
                      friends_.end(),
                      [](item &f1, item &f2) {
                        return f1.profile.communityVisibilityState() > f2.profile.communityVisibilityState();
                      }
                    );
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

FriendsModel::item FriendsModel::getFriend(int row) const {
    return friends_[row];
}

void FriendsModel::clear() {
    friends_.clear();
}

FilterModelFriends::FilterModelFriends(int aRow, QObject *aParent): FilterModel(aRow, 4, aParent),
    name_(""), status_(""), public_(), favorite_() {
    columns_.insert("name", 0);
    columns_.insert("status", 1);
    columns_.insert("public", 2);
    columns_.insert("favorite", 3);
}

bool FilterModelFriends::filterAcceptsRow(int aSource_row, const QModelIndex &aSource_parent) const {
    Q_UNUSED(aSource_parent);
    return filter_[aSource_row];
}

FriendsModel *FilterModelFriends::sourceModel() const {
    return static_cast<FriendsModel*>(FilterModel::sourceModel());
}

void FilterModelFriends::setSourceModel(FriendsModel *aSourceModel) {
    connect(aSourceModel, &FriendsModel::s_finished, this, [=, this]() {
        if (sourceModel() != nullptr) {
            filter_.setRows(sourceModel()->rowCount());
            forceInvalidate();
            emit s_modelFinished();
            emit s_rowsUpdated();
        } else {
            qWarning() << "in FilterModelFriends missing sourceModel, but emit 'finished'";
        }
    });
    FilterModel::setSourceModel(aSourceModel);
}

void FilterModelFriends::setName(const QString &aNewName) {
    if(name_ == aNewName)
        return;
    name_ = aNewName;
    int filterColumn = columns_.value("name");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex index = sourceModel()->index(r, Name);
        filter_.setData(r, filterColumn, sourceModel()->data(index).toString().toLower().indexOf(name_.toLower()) >= 0);
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelFriends::setStatus(const QString &aNewStatus) {
    if(status_ == aNewStatus)
        return;
    status_ = aNewStatus;
    int filterColumn = columns_.value("status");
    if (status_.isEmpty()) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex index = sourceModel()->index(r, Status);
            filter_.setData(r, filterColumn, sourceModel()->data(index).toString().toLower() == status_.toLower());
        }
    }
    invalidateFilter();
    emit s_rowsUpdated();

}

void FilterModelFriends::setIsPublic(int aIsPublic) {
    if(public_ == aIsPublic)
        return;
    public_ = aIsPublic;
    int filterColumn = columns_.value("public");
    if (public_ == 0) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex index = sourceModel()->index(r, IsPublic);
            filter_.setData(r, filterColumn, sourceModel()->data(index).toString().indexOf(public_ > 0 ? FriendsModel::isPublicTitle() : "") >= 0);
        }
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelFriends::setFavorites(const QSet<ProfileID> &aNewFavorites) {
    if(favorite_ == aNewFavorites)
        return;
    favorite_ = aNewFavorites;
    int filterColumn = columns_.value("favorite");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex index = sourceModel()->index(r, ID);
        filter_.setData(r, filterColumn, favorite_.find(sourceModel()->data(index).toString()) != favorite_.end());
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelFriends::clearFavorites() {
    favorite_.clear();
    int filterColumn = columns_.value("favorite");
    filter_.clearCol(filterColumn);
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelFriends::clear() {
    name_.clear();
    status_.clear();
    public_ = 0;
    favorite_.clear();
    FilterModel::clear();
    if (sourceModel() != nullptr) {
        sourceModel()->clear();
    }
}

void FilterModelFriends::setSourceModel(QAbstractItemModel *aSourceModel) {
    if (auto model = dynamic_cast<FriendsModel*>(aSourceModel)) {
        setSourceModel(model);
    }
}
