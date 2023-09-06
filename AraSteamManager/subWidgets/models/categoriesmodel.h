#ifndef CATEGORIESMODEL_H
#define CATEGORIESMODEL_H

#include <QAbstractItemModel>
#include "classes/files/category.h"

class CategoriesModel : public QAbstractItemModel {
    Q_OBJECT
public:
    CategoriesModel(Category *category = new Category(), QObject *parent = nullptr);
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
    bool insertRows(int position, const QModelIndex &parent, const QString &aTitle);
    bool removeRows(int position, int columns, const QModelIndex &parent = QModelIndex()) override;

    void update();
    Category *getItem(const QModelIndex &index) const;

    Qt::DropActions supportedDropActions() const override;
    QMimeData *mimeData(const QModelIndexList &indexes) const override;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) override;

public slots:
    bool removeAllCategories();
    bool saveCategories();
    void setGame(const SGame &aGame);
signals:
    void s_checkStateChanged(Category *category, bool isChecked);
    void s_error(const QString&);

protected slots:
    bool removeAllCategories(const QModelIndex &aParent);
private slots:
    bool insertRows(int position, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    Category *rootItem_;
    QSet<Category*> isChecked_;
};
#endif // CATEGORIESMODEL_H
