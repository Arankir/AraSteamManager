#include "filters.h"

void SortFilterProxyModelMiltiRow::addRow(const int &row) {
    _rows.append(row);
}

void SortFilterProxyModelMiltiRow::removeRow(const int &row) {
    for (auto &rowFilter: _rows) {
        if (rowFilter == row) {
            _rows.removeOne(rowFilter);
            return;
        }
    }
}

bool SortFilterProxyModelMiltiRow::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (filterRegExp().isEmpty()) {
        return true;
    }
    bool ret = false;
    for (auto &rowFilter: _rows) {
        QModelIndex index = sourceModel()->index(source_row, rowFilter, source_parent);
        ret = (filterRegExp().indexIn(index.data().toString()) > 0);
        if(ret)
            return true;
    }
    return false;
};

const int SPECIFIC_DATA_INDEX = 0;
const QString SPECIFIC_DATA = "";

SortFilterProxyModelFreezeRow::SortFilterProxyModelFreezeRow(QObject *parent): QSortFilterProxyModel(parent) {

}

bool SortFilterProxyModelFreezeRow::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    // Get left and right row
    int leftRow = left.row();
    int rightRow = right.row();

    // Get specific data from left row
    QModelIndex leftIndex = sourceModel()->index(leftRow, SPECIFIC_DATA_INDEX);
    QString leftProperty = sourceModel()->data(leftIndex).toString();
    // Get specific data from right row
    QModelIndex  rightIndex = sourceModel()->index(rightRow, SPECIFIC_DATA_INDEX);
    QString rightProperty = sourceModel()->data(rightIndex).toString();

    if(leftProperty .compare(SPECIFIC_DATA) == 0) {// put left on top if it has a specific property
        return sortOrder() == Qt::AscendingOrder;
    } else if(rightProperty .compare(SPECIFIC_DATA) == 0) { // put right on top if it has a specific property
        return sortOrder() != Qt::AscendingOrder;
    }
    return QSortFilterProxyModel::lessThan(left, right);
}

void SortFilterProxyModelCategory::addCategory(const QString &name, const QStringList &apis) {
    _categories.append(std::move(QPair<QString, QStringList>(name, apis)));
    updateRegExp();
}

void SortFilterProxyModelCategory::removeCategory(const QString &name) {
    _categories.erase(std::remove_if(_categories.begin(),
                                     _categories.end(),
                                     [=](QPair<QString, QStringList> category){
                                          return category.first == name;
                                      }), _categories.end());
    updateRegExp();
}

void SortFilterProxyModelCategory::updateRegExp() {
    QStringList resultList;
    for (const auto &category: qAsConst(_categories)) {
        resultList << category.second;
    }
    setFilterRegExp("(" + resultList.join(")|(") + ")|(^$)");
}
