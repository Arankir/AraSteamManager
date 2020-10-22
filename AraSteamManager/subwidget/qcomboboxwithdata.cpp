#include "qcomboboxwithdata.h"

void QComboBoxWithData::addData(QString aTitle, QString aData) {
    _data.append(QPair<QString, QString>(aTitle, aData));
}

QString QComboBoxWithData::getData(QString aTitle) {
    for(int i = 0; i < _data.size(); ++i) {
        if (_data[i].first == aTitle) {
            return _data[i].second;
        }
    }
    return "";
}

QString QComboBoxWithData::getData(int aIndex) {
    if (aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}
