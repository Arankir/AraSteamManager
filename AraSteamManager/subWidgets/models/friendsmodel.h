#ifndef FRIENDSMODEL_H
#define FRIENDSMODEL_H

#include <QSet>
#include "classes/steamApi/structures/sfriends.h"
#include "subWidgets/models/filters.h"

namespace friendsModel {
    enum Columns {
        ID        = 0,
        Index     = 1,
        Icon      = 2,
        Name      = 3,
        Added     = 4,
        Status    = 5,
        IsPublic  = 6,
        Count     = 7
    };
}

class FriendsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    FriendsModel(QObject *parent = nullptr);
    void setFriends(const QList<SFriend> &friends);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QString friendId(const QModelIndex &index) const;
    static QString isPublicTitle();
    SFriendProfile getFriend(const int &row) const;
    void clear();

public slots:
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, const int &progress, const int &max);

private:
    QList<SFriendProfile> friends_;

};

class FilterModelFriends : public FilterModel {
    Q_OBJECT
public:
    FilterModelFriends(const int &row = 0, QObject *parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    FriendsModel *sourceModel() const;
    void setSourceModel(FriendsModel *sourceModel);

signals:
    void s_modelFinished();

public slots:
    void setName(const QString &newName);
    void setStatus(const QString &newStatus);
    void setIsPublic(const int &isPublic);
    void setFavorites(const QSet<ProfileID> &newFavorites);
    void clearFavorites();
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel) {Q_UNUSED(sourceModel);}

    QString name_;
    QString status_;
    int public_;
    QSet<ProfileID> favorite_;
};

#endif // FRIENDSMODEL_H
