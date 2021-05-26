#ifndef FRIENDSMODEL_H
#define FRIENDSMODEL_H

#include <QAbstractTableModel>
#include <QObject>
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
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QString friendId(const QModelIndex &index) const;
    QPair<SFriend, SProfile> getFriend(const int &row) const;

public slots:
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
    QList<QPair<SFriend, SProfile>> _friends;

};

#endif // FRIENDSMODEL_H
