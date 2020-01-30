#include "qcomboboxwithdata.h"

void QComboBoxWithData::AddData(QString a_title, QString a_data){
    _data.append(QPair<QString,QString>(a_title,a_data));
}

QString QComboBoxWithData::GetData(QString a_title){
    for(int i=0;i<_data.size();i++){
        if(_data[i].first==a_title){
            return _data[i].second;
        }
    }
    return "";
}

QString QComboBoxWithData::GetData(int a_index){
    if(a_index<_data.size()){
        return _data[a_index].second;
    }
    return "";
}
