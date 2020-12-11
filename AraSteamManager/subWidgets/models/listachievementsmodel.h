#ifndef LISTACHIEVEMENTSMODEL_H
#define LISTACHIEVEMENTSMODEL_H

#include <QObject>
#include <QWidget>
#include <QAbstractListModel>
#include <QStringListModel>
#include <QMimeData>

class ListAchievementsModel : public QAbstractListModel {
    Q_OBJECT
public:
    ListAchievementsModel(QWidget *parent = nullptr) : QAbstractListModel(parent) {;}
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QStringList mimeTypes() const;
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
};

#endif // LISTACHIEVEMENTSMODEL_H
