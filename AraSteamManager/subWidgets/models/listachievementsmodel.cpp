#include "listachievementsmodel.h"

Qt::ItemFlags ListAchievementsModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags defaultFlags = QAbstractListModel::flags(index);

    if (index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
    else
        return Qt::ItemIsDropEnabled | defaultFlags;
}

QStringList ListAchievementsModel::mimeTypes() const {
    QStringList types;
    types << "application/x-item";
    return types;
}

QMimeData *ListAchievementsModel::mimeData(const QModelIndexList &indexes) const {
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    foreach (QModelIndex index, indexes) {
        if (index.isValid()) {
            QString text = data(index, Qt::DisplayRole).toString();
            stream << text;
        }
    }

    mimeData->setData("application/x-item", encodedData);
    return mimeData;
}

bool ListAchievementsModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) {
    if (action == Qt::IgnoreAction)
        return true;

    if (!data->hasFormat("application/x-item"))
        return false;

    if (column > 0)
        return false;

    int beginRow;
    if (row != -1)
        beginRow = row;
    else if (parent.isValid())
        beginRow = parent.row();
    else
        beginRow = rowCount(QModelIndex());

    QByteArray encodedData = data->data("application/x-item");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    QStringList newItems;
    int rows = 0;

    while (!stream.atEnd()) {
        QString text;
        stream >> text;
        newItems << text;
        ++rows;
    }
    insertRows(beginRow, rows, QModelIndex());
    foreach (QString text, newItems) {
        QModelIndex idx = index(beginRow, 0, QModelIndex());
        setData(idx, text);
        beginRow++;
    }

    return true;
}
