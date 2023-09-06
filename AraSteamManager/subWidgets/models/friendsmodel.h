#ifndef FRIENDSMODEL_H
#define FRIENDSMODEL_H

#include <QSet>
#include "classes/steamApi/structures/sfriends.h"
#include "subWidgets/models/filters.h"

namespace friendsModel {
    enum Columns {
        ID        = 0,
        Index     = 1,
        Name      = 2,
        Added     = 3,
        Status    = 4,
        IsPublic  = 5,
        Count     = 6
    };
}

class FriendsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    struct item {
        QIcon *icon = nullptr;
        SFriend steamFriend;
        SProfile profile;
    };

    FriendsModel(QObject *parent = nullptr);
    void setFriends(const QList<SFriend> &friends);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QString friendId(const QModelIndex &index) const;
    static QString isPublicTitle();
    item getFriend(int row) const;
    void clear();

public slots:
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, int progress, int max);

private:
    QList<item> friends_;

};

class FilterModelFriends : public FilterModel {
    Q_OBJECT
public:
    FilterModelFriends(int row = 0, QObject *parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    FriendsModel *sourceModel() const;
    void setSourceModel(FriendsModel *sourceModel);

signals:
    void s_modelFinished();

public slots:
    void setName(const QString &newName);
    void setStatus(const QString &newStatus);
    void setIsPublic(int isPublic);
    void setFavorites(const QSet<ProfileID> &newFavorites);
    void clearFavorites();
    void clear() override;

private:
    void setSourceModel(QAbstractItemModel *sourceModel) override;

    QString name_;
    QString status_;
    int public_;
    QSet<ProfileID> favorite_;
};

#endif // FRIENDSMODEL_H
