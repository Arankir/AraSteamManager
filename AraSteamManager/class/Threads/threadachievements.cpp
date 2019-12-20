#include "threadachievements.h"

ThreadAchievements::ThreadAchievements(QObject *parent) : QObject(parent){

}

void ThreadAchievements::Set(SAchievements Aachievements, QLabel *AlabelTotalPersent, QTableWidget *AtableWidgetAchievements, QLabel *AlabelTotalPersentCompare, QTableWidget *AtableWidgetCompareAchievements){
    _achievements=Aachievements;
    _LabelTotalPersent=AlabelTotalPersent;
    _TableWidgetAchievements=AtableWidgetAchievements;
    _LabelTotalPersentCompare=AlabelTotalPersentCompare;
    _TableWidgetCompareAchievements=AtableWidgetCompareAchievements;
}

int ThreadAchievements::Fill(){
    int totalr=0;
    int totalnr=0;
    int j=0;
    for(int i=0;i<_achievements.GetCount();i++){
        if(_achievements.GetDisplayname(i)!=""){
            _TableWidgetAchievements->setItem(j,0,new QTableWidgetItem(_achievements.GetApiname(i)));
            _TableWidgetCompareAchievements->setItem(j+2,0,new QTableWidgetItem(_achievements.GetApiname(i)));
            _TableWidgetAchievements->setItem(j,2,new QTableWidgetItem(_achievements.GetDisplayname(i)));
            _TableWidgetCompareAchievements->setItem(j+2,2,new QTableWidgetItem(_achievements.GetDisplayname(i)));
            _TableWidgetAchievements->setItem(j,3,new QTableWidgetItem(_achievements.GetDescription(i)));
            _TableWidgetCompareAchievements->setItem(j+2,3,new QTableWidgetItem(_achievements.GetDescription(i)));
            _TableWidgetAchievements->setItem(j,4,new QTableWidgetItem(_achievements.GetPercent(i)<10?"0"+QString::number(_achievements.GetPercent(i))+"%":QString::number(_achievements.GetPercent(i))+"%"));
            _TableWidgetCompareAchievements->setItem(j+2,4,new QTableWidgetItem(_achievements.GetPercent(i)<10?"0"+QString::number(_achievements.GetPercent(i))+"%":QString::number(_achievements.GetPercent(i))+"%"));
            if(_achievements.GetAchieved(i)==1){
                _TableWidgetAchievements->setItem(j,5,new QTableWidgetItem(tr("Получено %1").arg(_achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm"))));
                _TableWidgetCompareAchievements->setItem(j+2,5,new QTableWidgetItem(tr("Получено %1").arg(_achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm"))));
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
