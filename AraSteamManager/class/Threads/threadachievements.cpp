#include "threadachievements.h"

void ThreadAchievements::Set(SAchievements a_achievements, QLabel *a_labelTotalPersent, QTableWidget *a_tableWidgetAchievements, QLabel *a_labelTotalPersentCompare){
    _achievements=a_achievements;
    _LabelTotalPersent=a_labelTotalPersent;
    _TableWidgetAchievements=a_tableWidgetAchievements;
    _LabelTotalPersentCompare=a_labelTotalPersentCompare;
}

void ThreadAchievements::SetFriend(QTableWidget *a_tableWidgetAchievements, SAchievements a_achievement, int a_col, int a_columnAppid){
    _achievement = a_achievement;
    _col = a_col;
    _columnAppid = a_columnAppid;
    _TableWidgetAchievements=a_tableWidgetAchievements;
}

bool ThreadAchievements::AddFriend(){
    int totalReach=0;
    int totalNotReach=0;
    for(int i=0;i<_TableWidgetAchievements->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<_achievement.GetCount();j++){
            if(_achievement[j].GetApiname()==_TableWidgetAchievements->item(i,_columnAppid)->text()){
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
            _TableWidgetAchievements->setItem(i,_col,item5);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        _TableWidgetAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"),tr("публичный"))));
        emit s_is_public(false,_col);
        } else {
        _TableWidgetAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),QString::number(totalReach+totalNotReach),
                                                                                                 QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        emit s_is_public(true,_col);
    }
    emit s_finished(totalReach,totalNotReach);
    return true;
}

int ThreadAchievements::Fill(){
    int totalr=0;
    int totalnr=0;
    int row=0;
    for(auto &achievement:_achievements){
        if(achievement.GetDisplayname()!=""){
            _TableWidgetAchievements->setItem(row,c_tableColumnAppid,new QTableWidgetItem(achievement.GetApiname()));
            _TableWidgetAchievements->setItem(row,c_tableColumnTitle,new QTableWidgetItem(achievement.GetDisplayname()));
            _TableWidgetAchievements->setItem(row,c_tableColumnDescription,new QTableWidgetItem(achievement.GetDescription()));
            _TableWidgetAchievements->setItem(row,c_tableColumnWorld,new QTableWidgetItem((achievement.GetPercent()<10?"0":"")+QString::number(achievement.GetPercent())+"%"));
            if(achievement.GetAchieved()==1){
                _TableWidgetAchievements->setItem(row,c_tableColumnMy,new QTableWidgetItem(tr("Получено %1").arg(achievement.GetUnlocktime().toString("yyyy.MM.dd hh:mm"))));
                totalr++;
            } else {
                _TableWidgetAchievements->setItem(row,c_tableColumnMy,new QTableWidgetItem(tr("Не получено")));
                totalnr++;
            }
            _TableWidgetAchievements->item(row,c_tableColumnTitle)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(row,c_tableColumnDescription)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(row,c_tableColumnWorld)->setTextAlignment(Qt::AlignCenter);
            _TableWidgetAchievements->item(row,c_tableColumnMy)->setTextAlignment(Qt::AlignCenter);
            emit s_progress(row,row);
            row++;
        }
    }
    emit s_finished(totalr,totalnr);
    return 1;
}
