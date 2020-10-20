#include "filter.h"

Filter::Filter(int aRow, int aCol, QObject *aParent): QObject(aParent), _row(aRow > 0 ? aRow : 0), _col(aCol > 0 ? aCol : 0) {
    if (_row > 0 && _col > 0) {
        _filter.resize(_row);
        for (int i = 0; i < _row; ++i) {
            _filter[i] = QVector<bool>(_col, true);
        }
    }
}

Filter &Filter::setRow(int aRow) {
    _filter.resize(aRow);
    if (aRow > _row) {
        for (int i = _row; i < aRow; ++i) {
            _filter[i] = QVector<bool>(_col, true);
        }
    }
    _row = aRow;
    return *this;
}

Filter &Filter::setCol(int aCol) {
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

Filter &Filter::setData(int aRow, int aCol, bool aData) {
    if (aRow < _row && aCol < _col) {
        _filter[aRow][aCol] = std::move(aData);
    }
    return *this;
}

bool Filter::getData(int aRow, int aCol) const {
    if (aRow < _row && aCol < _col) {
        return _filter[aRow][aCol];
    }
    return false;
}

bool Filter::getData(int aRow) const {
    if (aRow < _row) {
        return _filter[aRow].indexOf(false) == -1;
    }
    return false;
}

Filter &Filter::addCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; ++i) {
            _filter[aColNum].append(true);
        }
        ++_col;
    }
    return *this;
}

Filter &Filter::removeCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; ++i) {
            _filter[i].remove(aColNum);
        }
        --_col;
    }
    return *this;
}
