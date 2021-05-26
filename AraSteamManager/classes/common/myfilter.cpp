#include "myfilter.h"

MyFilter::MyFilter(const int &aRow, const int &aCol): _row(std::max(aRow, 0)), _col(std::max(aCol, 0)) {
    if (_row >= 0 && _col >= 0) {
        _filter.resize(_row);
        for (auto iterator = _filter.begin(); iterator < _filter.end(); ++iterator) {
            *iterator = QVector<bool>(_col, true);
        }
    } else {
        qWarning() << "Number of rows or columns is less than 0";
    }
}

MyFilter &MyFilter::setRow(const int &aRow) {
    if (aRow == _row) {
        return *this;
    }
    _filter.resize(aRow);
    if (aRow > _row) {
        for (auto iterator = _filter.begin() + _row; iterator < _filter.end(); ++iterator) {
            *iterator = QVector<bool>(_col, true);
        }
    }
    _row = aRow;
    return *this;
}

MyFilter &MyFilter::setCol(const int &aCol) {
    if (aCol == _col) {
        return *this;
    }
    for(auto iterator = _filter.begin(); iterator < _filter.end(); ++iterator) {
        (*iterator).resize(aCol);
    }
    if (aCol > _col) {
        for(auto iteratorRow = _filter.begin(); iteratorRow < _filter.end(); ++iteratorRow) {
            for(auto iteratorCol = (*iteratorRow).begin() + _col; iteratorCol < (*iteratorRow).end(); ++iteratorCol) {
                (*iteratorCol) = true;
            }
        }
    }
    _col = aCol;
    return *this;
}

MyFilter &MyFilter::setData(const int &aRow, const int &aCol, const bool &aData) {
    if (aRow < _row && aCol < _col) {
        _filter[aRow][aCol] = aData;
    } else {
        qWarning() << "Cell (" + QString::number(aRow) + ", " + QString::number(aCol) + ") does not exist. "
                      "Size is (" + QString::number(_row) + ", " + QString::number(_col) + ")";
    }
    return *this;
}

bool MyFilter::getData(const int &aRow, const int &aCol) const {
    if (aRow < _row && aCol < _col) {
        return _filter[aRow][aCol];
    } else {
        qWarning() << "Cell (" + QString::number(aRow) + ", " + QString::number(aCol) + ") does not exist. "
                      "Size is (" + QString::number(_row) + ", " + QString::number(_col) + ")";
    }
    return false;
}

bool MyFilter::getData(const int &aRow) const {
    if (aRow < _row) {
        return _filter[aRow].indexOf(false) == -1;
    } else {
        qWarning() << "Row (" + QString::number(aRow) + ") does not exist. "
                      "Row count is (" + QString::number(_row) + ")";
    }
    return true;
}

MyFilter &MyFilter::addCol(const int &aCol) {
    if (aCol < _col + 1) {
        for(auto iterator = _filter.begin(); iterator < _filter.end(); ++iterator) {
            (*iterator).append(true);
        }
        ++_col;
    }
    return *this;
}

MyFilter &MyFilter::removeCol(const int &aCol) {
    if (aCol < _col + 1) {
        for(auto iterator = _filter.begin(); iterator < _filter.end(); ++iterator) {
            (*iterator).remove(aCol);
        }
        --_col;
    }
    return *this;
}

MyFilter &MyFilter::clearCol(const int &aCol) {
    for (auto b = _filter.begin(); b < _filter.end(); ++b) {
        (*b)[aCol] = true;
    }
    return *this;
}
