#include "qcheckboxwithdata.h"

void QCheckBoxWithData::addData(QString aTitle, QString aData) {
    _data.append(QPair<QString, QString>(aTitle, aData));
}

void QCheckBoxWithData::clearData() {
    _data.clear();
}

QString QCheckBoxWithData::getData(QString aTitle) const {
    for(int i = 0; i < _data.size(); ++i) {
        if(_data[i].first == aTitle) {
            return _data[i].second;
        }
    }
    return "";
}

QString QCheckBoxWithData::getData(int aIndex) const {
    if(aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}
