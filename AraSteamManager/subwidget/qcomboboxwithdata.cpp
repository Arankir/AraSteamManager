#include "qcomboboxwithdata.h"

void QComboBoxWithData::AddData(QString Title, QString Data){
    _data.append(QPair<QString,QString>(Title,Data));
}

QString QComboBoxWithData::GetData(QString Title){
    for(int i=0;i<_data.size();i++){
        if(_data[i].first==Title){
            return _data[i].second;
        }
    }
    return "";
}

QString QComboBoxWithData::GetData(int index){
    if(index<_data.size()){
        return _data[index].second;
    }
    return "";
}
