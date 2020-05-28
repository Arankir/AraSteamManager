#include "qbuttonwithdata.h"

void QButtonWithData::AddData(QString a_title, QString a_data){
    _data.append(QPair<QString,QString>(std::move(a_title),std::move(a_data)));
}

QString QButtonWithData::GetData(QString a_title){
    for(auto &data: _data){
        if(data.first==a_title){
            return data.second;
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

