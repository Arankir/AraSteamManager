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
    if (!filterRegularExpression().isValid()) {
        return true;
    }
    bool ret = false;
    for (auto &rowFilter: _rows) {
        QModelIndex index = sourceModel()->index(source_row, rowFilter, source_parent);
        ret = (filterRegularExpression().match(index.data().toString()).hasMatch());
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
    _categories.append(QPair<QString, QStringList>(name, apis));
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
    setFilterRegularExpression("(" + resultList.join(")|(") + ")|(^$)");
}

int inline countBites(int bits) {
    return (int)ceil(1.0 * bits / 8);
}

void inline setBit(char &aChar, int bit) {
    aChar |= (1 << (bit % 8));
}

void inline unsetBit(char &aChar, int bit) {
    aChar &= ~(1 << (bit % 8));
}

bool inline getBit(const char &aChar, int bit) {
    return aChar >> (bit % 8) & 1;
}

void inline setDataToBit(char &aChar, int aBit, bool aData) {
    if (aData) {
        setBit(aChar, aBit);
    } else {
        unsetBit(aChar, aBit);
    }
}

Filter::Filter(int aRows, int aCols):
    rows_(std::max(0, aRows)),
    cols_(std::max(0, aCols)),
    checkCols_(QList<char>(countBites(cols_), 0xFF)),
    filter_(rows_, QList<char>(countBites(cols_), 0xFF)) {

}

bool Filter::operator[](int aRow) const {
    if (aRow >= rows_) {
        qWarning() << "index" << aRow << "is missing" << "(" << rows_ << ")";
        return false;
    }
    for (int c = 0; c < 8; ++c) {
        if (!(!getBit(checkCols_[c / 8], c) || getBit(filter_[aRow][c / 8], c))) { //Импликация (выводит false только если первое = true, а второе = false)
            return false;
        }
    }
    return true;
}

void Filter::setData(int aRow, int aCol, bool aData) {
    setDataToBit(filter_[aRow][aCol / 8], aCol, aData);
}

void Filter::setRows(int aRows) {
    int oldRows = rows_;
    rows_ = std::max(0, aRows);
    filter_.resize(rows_);
    if (rows_ > oldRows) {
        for (int r = oldRows; r < rows_; ++r) {
            filter_[r] = QList<char>(countBites(cols_), 0xFF);
        }
    }
}

void Filter::setCols(int aCols) {
    int oldCols = cols_;
    cols_ = std::max(0, aCols);
    for (int r = 0; r < rows_; ++r) {
        filter_[r].resize(countBites(cols_));
        if (countBites(cols_) > countBites(oldCols)) {
            for (int c = oldCols; c < cols_; ++c) {
                setBit(filter_[r][c / 8], c);
            }
        }
    }
}

void Filter::insertRow(int aRow) {
    int row = std::min(rows_ - 1, aRow);
    filter_.insert(row, QList<char>(countBites(cols_), 0xFF));
}

void Filter::removeRow(int aRow) {
    int row = std::min(rows_ - 1, aRow);
    filter_.remove(row);
}

void Filter::insertCol(int aCol) {
    int col = std::min(cols_ - 1, aCol);
    bool isNewChar = (((cols_ + 1) / 8) == 0);
    for (int r = 0; r < rows_; ++r) {
        if (isNewChar) {
            filter_.append(QList<char>(countBites(cols_), 0xFF));
        }
        for (int c = col; c < cols_; ++c) { // Сместить все биты направо
            setDataToBit(filter_[r][(c + 1) / 8], (c + 1), getBit(filter_[r][c / 8], c));
        }
        setBit(filter_[r][col / 8], col);
    }
    if (isNewChar) {
        checkCols_.append(0xFF);
    }
    for (int c = col; c < cols_; ++c) { // Сместить все биты направо
        setDataToBit(checkCols_[(c + 1) / 8], (c + 1), getBit(checkCols_[c / 8], c));
    }
    setBit(checkCols_[col / 8], col);
}

void Filter::removeCol(int aCol) {
    int col = std::min(cols_ - 1, aCol);
    bool isDeleteChar = (((cols_ - 1) / 8) == 0);
    for (int r = 0; r < rows_; ++r) {
        for (int c = col + 1; c < cols_; ++c) { // Сместить все биты налево
            setDataToBit(filter_[r][(c - 1) / 8], (c - 1), getBit(filter_[r][c / 8], c));
        }
        if (isDeleteChar) {
            filter_.remove(cols_);
        }
    }
    for (int c = col + 1; c < cols_; ++c) { // Сместить все биты налево
        setDataToBit(checkCols_[(c - 1) / 8], (c - 1), getBit(checkCols_[c / 8], c));
    }
    if (isDeleteChar) {
        checkCols_.remove(cols_);
    }
}

void Filter::disableCol(int aCol) {
    checkCols_[aCol / 8] &= ~(1 << aCol % 8);
}

void Filter::enableCol(int aCol) {
    checkCols_[aCol / 8] |= (1 << aCol % 8);
}

void Filter::clearCol(int col) {
    for (int r = 0; r < rows_; ++r) {
        setBit(filter_[r][col / 8], col);
    }
}

void Filter::clear() {
    for (int r = 0; r < rows_; ++r) {
        for (int c = 0; c < cols_; c += 8) {
            filter_[r][c] = 0xFF;
        }
    }
}

QVariant FilterModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

void FilterModel::setSourceModel(QAbstractItemModel *sourceModel) {
    if (sourceModel) {
        filter_.setRows(sourceModel->rowCount());
    } else {
        filter_.setRows(0);
    }
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

void FilterModel::forceInvalidate() {
    QSortFilterProxyModel::beginResetModel();
    QSortFilterProxyModel::invalidate();
    QSortFilterProxyModel::endResetModel();
}
