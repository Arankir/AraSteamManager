#include "filter.h"

Filter::Filter(int aRow, int aCol, QObject *aParent): QObject(aParent), _row(aRow > 0 ? aRow : 0), _col(aCol > 0 ? aCol : 0) {
    if (_row > 0 && _col > 0) {
        for (int i = 0; i < _row; i++) {
            QVector<bool> subFilter(_col);
            for (int j = 0; j < _col; j++) {
                subFilter[j] = std::move(true);
            }
            _filter.append(std::move(subFilter));
        }
    }
}

Filter::Filter(QObject *aParent): QObject(aParent) {

}

Filter::~Filter() {

}

void Filter::setRow(int aRow){
    if (aRow > _row) {
        for (int i = _row; i < aRow; i++) {
            QVector<bool> subFilter(_col);
            for (int j = 0; j < _col; j++) {
                subFilter[j] = std::move(true);
            }
            _filter.append(std::move(subFilter));
        }
        _row = aRow;
    } else if (aRow < _row) {
        for (int i = _row; i < aRow; i++) {
            while(_filter.size() > aRow) {
                _filter.takeAt(aRow);
            }
        }
        _row = aRow;
    }
}
void Filter::setCol(int aCol) {
    if (aCol > _col) {
        for (int i = _col; i < aCol; i++) {
            for (int j = 0; j < _row; j++) {
                _filter[j].append(std::move(true));
            }
        }
        _col = aCol;
    } else if (aCol < _col) {
        for(int i = _col; i < aCol; i++) {
            for(int j = 0; j < _row; j++) {
                _filter[j].takeAt(_col);
            }
        }
        _col = aCol;
    }
}
void Filter::setData(int aRow, int aCol, bool aData) {
    if (aRow < _row && aCol < _col) {
        _filter[aRow][aCol] = std::move(aData);
    }
}

bool Filter::getData(int aRow, int aCol) {
    if (aRow < _row && aCol < _col) {
        return _filter[aRow][aCol];
    }
    return false;
}

bool Filter::getData(int aRow) {
    if (aRow < _row) {
        return _filter[aRow].indexOf(false) == -1;
    }
    return false;
}

int Filter::getRow() {
    return _row;
}

int Filter::getCol() {
    return _col;
}

void Filter::addCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; i++) {
            _filter[aColNum].append(std::move(true));
        }
        _col++;
    }
}

void Filter::removeCol(int aColNum) {
    if (aColNum < _col + 1) {
        for (int i = 0; i < _row; i++) {
            _filter[i].remove(aColNum);
        }
        _col--;
    }
}
