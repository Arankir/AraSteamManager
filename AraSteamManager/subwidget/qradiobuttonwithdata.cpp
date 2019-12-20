#include "qradiobuttonwithdata.h"

void QRadioButtonWithData::AddData(QString Atitle, QString Adata){
    _data.append(QPair<QString,QString>(Atitle,Adata));
}

QString QRadioButtonWithData::GetData(QString Atitle){
    for(int i=0;i<_data.size();i++){
        if(_data[i].first==Atitle){
            return _data[i].second;
        }
    }
    return "";
}

QString QRadioButtonWithData::GetData(int Aindex){
    if(Aindex<_data.size()){
        return _data[Aindex].second;
    }
    return "";
}
