#include "qradiobuttonwithdata.h"

QRadioButtonWithData::QRadioButtonWithData(const QString &text, QWidget *parent): QRadioButton(text, parent) {

}

QRadioButtonWithData::QRadioButtonWithData(QWidget *parent): QRadioButton(parent) {

}

void QRadioButtonWithData::AddData(QString aTitle, QString aData) {
    _data.append(QPair<QString,QString>(aTitle, aData));
}

QString QRadioButtonWithData::GetData(QString aTitle) {
    for(int i = 0; i < _data.size(); i++) {
        if(_data[i].first == aTitle) {
            return _data[i].second;
        }
    }
    return "";
}

QString QRadioButtonWithData::GetData(int aIndex) {
    if(aIndex < _data.size()) {
        return _data[aIndex].second;
    }
    return "";
}

void QRadioButtonWithData::SetReachedType(ReachedType aSet) {
    _type = aSet;
}
