#include "qradiobuttonwithdata.h"

void QRadioButtonWithData::addData(QString aTitle, QString aData) {
    _data.append(QPair<QString, QString>(aTitle, aData));
}

QString QRadioButtonWithData::getData(QString aTitle) const {
    for(int i = 0; i < _data.size(); ++i) {
        if(_data[i].first == aTitle) {
            return _data[i].second;
        }
    }
    return "";
}

QString QRadioButtonWithData::getData(int aIndex) const  {
    if(aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}


