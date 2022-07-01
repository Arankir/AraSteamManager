#ifndef CATEGORYITEM_H
#define CATEGORYITEM_H

#include <QStandardItem>

#include "classes/files/category.h"

class CategoryItem : public QObject, public QStandardItem {
    Q_OBJECT
public:
    explicit CategoryItem(Category *category);
    Category *category();
    QStandardItem *parentItem();
//    friend QDataStream &operator<<(QDataStream &stream, const CategoryItem &aItem) {
//        QStringList list;
//        aItem.category_->getPathFromRoot(list);
//        stream << list;
//        stream << aItem.category_->root();
//        stream << aItem.category_->toJson();
//        stream << aItem;
//        qDebug() << 11111;
//        return stream;
//    }
//    friend QDataStream &operator>>(QDataStream &stream, CategoryItem &aItem) {
//        QStringList list;
//        Category2 *root;
//        QJsonObject object;
//        stream >> aItem >> object >> root >> list;
//        aItem.category_ = root->find(list);
//        qDebug() << 22222;
//        return stream;

//    }

private:
    Category *category_ = nullptr;
};

//class CategoryItem2 {
//public:
//    explicit CategoryItem2(Category2 *data);
//    ~CategoryItem2();

//    CategoryItem2 *child(int number);
//    int childCount() const;
//    int columnCount() const;
//    QVariant data(int column) const;
//    bool insertChildren(int position, int count, int columns);
//    bool insertColumns(int position, int columns);
//    CategoryItem2 *parent();
//    bool removeChildren(int position, int count);
//    bool removeColumns(int position, int columns);
//    int childNumber() const;
//    bool setData(int column, const QVariant &value);

//private:
//    Category2 *category_ = nullptr;
//};
#endif // CATEGORYITEM_H
