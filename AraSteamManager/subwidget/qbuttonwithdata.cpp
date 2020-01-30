#include "qbuttonwithdata.h"

void QButtonWithData::AddData(QString a_title, QString a_data){
    _data.append(QPair<QString,QString>(a_title,a_data));
}

QString QButtonWithData::GetData(QString a_title){
    for(int i=0;i<_data.size();i++){
        if(_data[i].first==a_title){
            return _data[i].second;
        }
    }
    return "";
}

QString QButtonWithData::GetData(int a_index){
    if(a_index<_data.size()){
        return _data[a_index].second;
    }
    return "";
}

