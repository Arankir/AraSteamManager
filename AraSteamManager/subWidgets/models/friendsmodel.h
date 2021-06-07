#ifndef FRIENDSMODEL_H
#define FRIENDSMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QSortFilterProxyModel>
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/generalfunctions.h"

enum modelFriendsColumns {
    FriendsID        = 0,
    FriendsIndex     = 1,
    FriendsIcon      = 2,
    FriendsName      = 3,
    FriendsAdded     = 4,
    FriendsStatus    = 5,
    FriendsIsPublic  = 6,
    FriendsCount     = 7
};

class FriendsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    FriendsModel(const QList<QPair<SFriend, SProfile>> &friends, QObject *parent = nullptr): QAbstractTableModel(parent), _friends(friends) {}
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QString friendId(const QModelIndex &index) const;
    static QString isPublicTitle();
    QPair<SFriend, SProfile> getFriend(const int &row) const;

public slots:
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
    QList<QPair<SFriend, SProfile>> _friends;

};

class ProxyModelFriends : public QSortFilterProxyModel {
    Q_OBJECT
public:
    ProxyModelFriends(QObject* parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    FriendsModel *sourceModel() const;
    void setSourceModel(FriendsModel *sourceModel);

public slots:
    void setName(const QString &newName);
    void setStatus(const QString &newStatus);
    void setIsPublic(const int &isPublic);
    void setFavorites(const QStringList &newFavorites);
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel) {Q_UNUSED(sourceModel);}

    QString _name;
    QString _status;
    int _public;
    QStringList _favorite;
};

#endif // FRIENDSMODEL_H
