#include "qbuttonwithdata.h"

void QButtonWithData::addData(QString aTitle, QString aData) {
    _data.append(QPair<QString, QString>(std::move(aTitle), std::move(aData)));
}

QString QButtonWithData::getData(QString aTitle) const {
    for(auto &data: _data) {
        if (data.first == aTitle) {
            return data.second;
        }
    }
    return "";
}

QString QButtonWithData::getData(int aIndex) const {
    if (aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}

