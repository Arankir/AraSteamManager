#ifndef CATEGORIESMODEL_H
#define CATEGORIESMODEL_H

#include <QStandardItemModel>
#include "classes/files/category.h"

class CategoriesModel : public QAbstractItemModel {
    Q_OBJECT
public:
    CategoriesModel(Category *category, QObject *parent = nullptr);
    ~CategoriesModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    bool insertColumns(int position, int columns, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int position, int columns, const QModelIndex &parent = QModelIndex()) override;
    bool insertRows(int position, int columns, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int columns, const QModelIndex &parent = QModelIndex()) override;

    void updateData(Category *parent);
    Category *getItem(const QModelIndex &index) const;

    Qt::DropActions supportedDropActions() const override;
    QMimeData *mimeData(const QModelIndexList &indexes) const override;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) override;

public slots:
    bool removeCategory(Category *aCategory);
    bool insertCategory(Category *aCategory, const QStringList &aList);
    bool removeAllCategories();
    bool saveCategories();
signals:
    void s_checkStateChanged(Category *category, const bool &isChecked);
    void s_error(const QString&);

    private:
    Category *rootItem_;
    QSet<Category*> isChecked_;
};
#endif // CATEGORIESMODEL_H
