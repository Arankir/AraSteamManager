#include "myfilter.h"

MyFilter::MyFilter(int aRow, int aCol, QObject *aParent): QObject(aParent), _row(aRow > 0 ? aRow : 0), _col(aCol > 0 ? aCol : 0) {
    if (_row >= 0 && _col >= 0) {
        _filter.resize(_row);
        for (int i = 0; i < _row; ++i) {
            _filter[i] = QVector<bool>(_col, true);
        }
    } else {
        qWarning() << "Number of rows or columns is less than 0";
    }
}

MyFilter &MyFilter::setRow(int aRow) {
    _filter.resize(aRow);
    if (aRow > _row) {
        for (int i = _row; i < aRow; ++i) {
            _filter[i] = QVector<bool>(_col, true);
        }
    }
    _row = aRow;
    return *this;
}

MyFilter &MyFilter::setCol(int aCol) {
    for(int i = 0; i < _row; ++i) {
        _filter[i].resize(aCol);
    }
    if (aCol > _col) {
        for (int i = 0; i < _row; ++i) {
            for (int j = _col; j < aCol; ++j) {
                _filter[i][j] = true;
            }
        }
    }
    _col = aCol;
    return *this;
}

MyFilter &MyFilter::setData(int aRow, int aCol, bool aData) {
    if (aRow < _row && aCol < _col) {
        _filter[aRow][aCol] = std::move(aData);
    } else {
        qWarning() << "Data cannot be inserted. "
                      "Cell (" + QString::number(aRow) + ", " + QString::number(aCol) + ") does not exist. "
                      "Filter size is (" + QString::number(_row) + ", " + QString::number(_col) + ")";
    }
    return *this;
}

bool MyFilter::getData(int aRow, int aCol) const {
    if (aRow < _row && aCol < _col) {
        return _filter[aRow][aCol];
    } else {
        qWarning() << "Data cannot be read. "
                      "Cell (" + QString::number(aRow) + ", " + QString::number(aCol) + ") does not exist. "
                      "Filter size is (" + QString::number(_row) + ", " + QString::number(_col) + ")";
    }
    return false;
}

bool MyFilter::getData(int aRow) const {
    if (aRow < _row) {
        return _filter[aRow].indexOf(false) == -1;
    } else {
        qWarning() << "Data cannot be read. "
                      "Row (" + QString::number(aRow) + ") does not exist. "
                      "Filter's row count is (" + QString::number(_row) + ")";
    }
    return false;
}

MyFilter &MyFilter::addCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; ++i) {
            _filter[aColNum].append(true);
        }
        ++_col;
    }
    return *this;
}

MyFilter &MyFilter::removeCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; ++i) {
            _filter[i].remove(aColNum);
        }
        --_col;
    }
    return *this;
}
