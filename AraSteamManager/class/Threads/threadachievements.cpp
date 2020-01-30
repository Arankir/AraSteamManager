#include "threadachievements.h"

ThreadAchievements::ThreadAchievements(QObject *parent) : QObject(parent){

}

void ThreadAchievements::Set(SAchievements a_achievements, QLabel *a_labelTotalPersent, QTableWidget *a_tableWidgetAchievements, QLabel *a_labelTotalPersentCompare, QTableWidget *a_tableWidgetCompareAchievements){
    _achievements=a_achievements;
    _LabelTotalPersent=a_labelTotalPersent;
    _TableWidgetAchievements=a_tableWidgetAchievements;
    _LabelTotalPersentCompare=a_labelTotalPersentCompare;
    _TableWidgetCompareAchievements=a_tableWidgetCompareAchievements;
}

void ThreadAchievements::SetFriend(QTableWidget *a_tableWidgetAchievements, SAchievements a_achievement, int a_col, int a_columnAppid){
    _achievement = a_achievement;
    _col = a_col;
    _columnAppid = a_columnAppid;
    _TableWidgetCompareAchievements=a_tableWidgetAchievements;
}

bool ThreadAchievements::AddFriend(){
    int totalReach=0;
    int totalNotReach=0;
    for(int i=2;i<_TableWidgetCompareAchievements->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<_achievement.GetCount();j++){
            if(_achievement[j].GetApiname()==_TableWidgetCompareAchievements->item(i,_columnAppid)->text()){
                accept=true;
                break;
                }
        }
        if(accept){
            QTableWidgetItem *item5;
            if(_achievement[j].GetAchieved()==1){
                item5 = new QTableWidgetItem(tr("Получено %1").arg(_achievement[j].GetUnlocktime().toString("yyyy.MM.dd hh:mm")));
                item5->setToolTip(_achievement[j].GetUnlocktime().toString("yyyy.MM.dd hh:mm"));
                totalReach++;
                } else {
                item5 = new QTableWidgetItem(tr("Не получено"));
                totalNotReach++;
                }
            item5->setTextAlignment(Qt::AlignCenter);
            _TableWidgetCompareAchievements->setItem(i,_col,item5);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        _TableWidgetCompareAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не")).arg(tr("публичный"))));
        emit s_is_public(false,_col);
        } else {
        _TableWidgetCompareAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach))
                                                                             .arg(QString::number(totalReach+totalNotReach))
                                                                             .arg(QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        emit s_is_public(true,_col);
    }
    emit s_finished();
    return true;
}

int ThreadAchievements::Fill(){
    int totalr=0;
    int totalnr=0;
    int j=0;
    for(int i=0;i<_achievements.GetCount();i++){
        if(_achievements[i].GetDisplayname()!=""){
            _TableWidgetAchievements->setItem(j,0,new QTableWidgetItem(_achievements[i].GetApiname()));
            _TableWidgetCompareAchievements->setItem(j+2,0,new QTableWidgetItem(_achievements[i].GetApiname()));
            _TableWidgetAchievements->setItem(j,2,new QTableWidgetItem(_achievements[i].GetDisplayname()));
            _TableWidgetCompareAchievements->setItem(j+2,2,new QTableWidgetItem(_achievements[i].GetDisplayname()));
            _TableWidgetAchievements->setItem(j,3,new QTableWidgetItem(_achievements[i].GetDescription()));
            _TableWidgetCompareAchievements->setItem(j+2,3,new QTableWidgetItem(_achievements[i].GetDescription()));
            _TableWidgetAchievements->setItem(j,4,new QTableWidgetItem(_achievements[i].GetPercent()<10?"0"+QString::number(_achievements[i].GetPercent())+"%":QString::number(_achievements[i].GetPercent())+"%"));
            _TableWidgetCompareAchievements->setItem(j+2,4,new QTableWidgetItem(_achievements[i].GetPercent()<10?"0"+QString::number(_achievements[i].GetPercent())+"%":QString::number(_achievements[i].GetPercent())+"%"));
            if(_achievements[i].GetAchieved()==1){
                _TableWidgetAchievements->setItem(j,5,new QTableWidgetItem(tr("Получено %1").arg(_achievements[i].GetUnlocktime().toString("yyyy.MM.dd hh:mm"))));
                _TableWidgetCompareAchievements->setItem(j+2,5,new QTableWidgetItem(tr("Получено %1").arg(_achievements[i].GetUnlocktime().toString("yyyy.MM.dd hh:mm"))));
                totalr++;
                } else {
                _TableWidgetAchievements->setItem(j,5,new QTableWidgetItem(tr("Не получено")));
                _TableWidgetCompareAchievements->setItem(j+2,5,new QTableWidgetItem(tr("Не получено")));
                totalnr++;
                }
            _TableWidgetAchievements->item(j,2)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(j,3)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(j,4)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(j,5)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetCompareAchievements->item(j+2,2)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetCompareAchievements->item(j+2,3)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetCompareAchievements->item(j+2,4)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetCompareAchievements->item(j+2,5)->setTextAlignment(Qt::AlignCenter);
            emit s_progress(i,j);
            j++;
        }
    }
    _LabelTotalPersent->setText(QString("%1/%2 = %3%").arg(QString::number(totalr)).arg(QString::number(totalr+totalnr)).arg(QString::number(100.0*totalr/(totalr+totalnr))));
    _LabelTotalPersentCompare->setText(QString("%1/%2\n%3%").arg(QString::number(totalr)).arg(QString::number(totalr+totalnr)).arg(QString::number(100.0*totalr/(totalr+totalnr))));
    emit s_finished();
    return 1;
}
