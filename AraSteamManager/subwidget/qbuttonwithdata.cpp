#include "qbuttonwithdata.h"

void QButtonWithData::addData(QString aTitle, QString aData) {
    _data.append(QPair<QString, QString>(std::move(aTitle), std::move(aData)));
}

QString QButtonWithData::getData(QString aTitle) {
    for(auto &data: _data) {
        if (data.first == aTitle) {
            return data.second;
        }
    }
    return "";
}

QString QButtonWithData::getData(int aIndex) {
    if (aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}

