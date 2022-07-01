#include "categoryitem.h"

CategoryItem::CategoryItem(Category *aCategory): QStandardItem{}, category_{aCategory} {
    if (category_) {
        QStandardItem::setText(category_->title());
        if (!category_->isEmpty()) {
            QStandardItem::setFlags(flags() | Qt::ItemIsUserCheckable);
            QStandardItem::setCheckState(Qt::Unchecked);
        }
    }
}

Category *CategoryItem::category() {
    return category_;
}

QStandardItem *CategoryItem::parentItem() {
    return QStandardItem::parent();
}

//CategoryItem2::CategoryItem2(Category2 *data): category_(data) {

//}

//CategoryItem2::~CategoryItem2() {

//}

//CategoryItem2 *CategoryItem2::child(int number) {
//    if (number < 0 || number >= category_->categories().size())
//        return nullptr;
//    auto childs = category_->categories();
//    return childs[number];
//}
////! [2]

////! [3]
//int CategoryItem2::childCount() const
//{
//    return childItems.count();
//}
////! [3]

////! [4]
//int CategoryItem2::childNumber() const
//{
//    if (parentItem)
//        return parentItem->childItems.indexOf(const_cast<CategoryItem2*>(this));
//    return 0;
//}
////! [4]

////! [5]
//int CategoryItem2::columnCount() const
//{
//    return itemData.count();
//}
////! [5]

////! [6]
//QVariant CategoryItem2::data(int column) const
//{
//    if (column < 0 || column >= itemData.size())
//        return QVariant();
//    return itemData.at(column);
//}
////! [6]

////! [7]
//bool CategoryItem2::insertChildren(int position, int count, int columns)
//{
//    if (position < 0 || position > childItems.size())
//        return false;

//    for (int row = 0; row < count; ++row) {
//        QList<QVariant> data(columns);
//        CategoryItem2 *item = new CategoryItem2(data, this);
//        childItems.insert(position, item);
//    }

//    return true;
//}
////! [7]

////! [8]
//bool CategoryItem2::insertColumns(int position, int columns)
//{
//    if (position < 0 || position > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.insert(position, QVariant());

//    for (CategoryItem2 *child : qAsConst(childItems))
//        child->insertColumns(position, columns);

//    return true;
//}
////! [8]

////! [9]
//CategoryItem2 *CategoryItem2::parent()
//{
//    return parentItem;
//}
////! [9]

////! [10]
//bool CategoryItem2::removeChildren(int position, int count)
//{
//    if (position < 0 || position + count > childItems.size())
//        return false;

//    for (int row = 0; row < count; ++row)
//        delete childItems.takeAt(position);

//    return true;
//}
////! [10]

//bool CategoryItem2::removeColumns(int position, int columns)
//{
//    if (position < 0 || position + columns > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.remove(position);

//    for (CategoryItem2 *child : qAsConst(childItems))
//        child->removeColumns(position, columns);

//    return true;
//}

////! [11]
//bool CategoryItem2::setData(int column, const QVariant &value)
//{
//    if (column < 0 || column >= itemData.size())
//        return false;

//    itemData[column] = value;
//    return true;
//}
