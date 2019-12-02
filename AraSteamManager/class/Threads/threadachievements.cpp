#include "threadachievements.h"

ThreadAchievements::ThreadAchievements(QObject *parent) : QObject(parent){

}

void ThreadAchievements::Set(SAchievements achievements, QStringList Words, QLabel *LabelTotalPersent, QTableWidget *TableWidgetAchievements, QLabel *LabelTotalPersentCompare, QTableWidget *TableWidgetCompareAchievements){
    this->achievements=achievements;
    this->Words=Words;
    this->LabelTotalPersent=LabelTotalPersent;
    this->TableWidgetAchievements=TableWidgetAchievements;
    this->LabelTotalPersentCompare=LabelTotalPersentCompare;
    this->TableWidgetCompareAchievements=TableWidgetCompareAchievements;
}

int ThreadAchievements::Fill(){
    int totalr=0;
    int totalnr=0;
    int j=0;
    for(int i=0;i<achievements.GetAchievementsCount();i++){
        if(achievements.GetDisplayname(i)!=""){
            TableWidgetAchievements->setItem(j,0,new QTableWidgetItem(achievements.GetApiname(i)));
            TableWidgetAchievements->setItem(j,2,new QTableWidgetItem(achievements.GetDisplayname(i)));
            TableWidgetAchievements->setItem(j,3,new QTableWidgetItem(achievements.GetDescription(i)));
            TableWidgetAchievements->setItem(j,4,new QTableWidgetItem(achievements.GetPercent(i)<10?"0"+QString::number(achievements.GetPercent(i))+"%":QString::number(achievements.GetPercent(i))+"%"));
            if(achievements.GetAchieved(i)==1){
                TableWidgetAchievements->setItem(j,5,new QTableWidgetItem(Words[23].arg(achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm"))));
                totalr++;
                } else {
                TableWidgetAchievements->setItem(j,5,new QTableWidgetItem(Words[24]));
                totalnr++;
                }
            TableWidgetAchievements->item(j,2)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(j,3)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(j,4)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(j,5)->setTextAlignment(Qt::AlignCenter);
            TableWidgetCompareAchievements->setItem(j+2,0,new QTableWidgetItem(achievements.GetApiname(i)));
            TableWidgetCompareAchievements->setItem(j+2,2,new QTableWidgetItem(achievements.GetDisplayname(i)));
            TableWidgetCompareAchievements->setItem(j+2,3,new QTableWidgetItem(achievements.GetDescription(i)));
            TableWidgetCompareAchievements->setItem(j+2,4,new QTableWidgetItem(achievements.GetPercent(i)<10?"0"+QString::number(achievements.GetPercent(i))+"%":QString::number(achievements.GetPercent(i))+"%"));
            if(achievements.GetAchieved(i)==1){
                TableWidgetCompareAchievements->setItem(j+2,5,new QTableWidgetItem(Words[23].arg(achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm"))));
                } else {
                TableWidgetCompareAchievements->setItem(j+2,5,new QTableWidgetItem(Words[24]));
                }
            TableWidgetCompareAchievements->item(j+2,2)->setTextAlignment(Qt::AlignCenter);
            TableWidgetCompareAchievements->item(j+2,3)->setTextAlignment(Qt::AlignCenter);
            TableWidgetCompareAchievements->item(j+2,4)->setTextAlignment(Qt::AlignCenter);
            TableWidgetCompareAchievements->item(j+2,5)->setTextAlignment(Qt::AlignCenter);
            emit progress(i,j);
            j++;
        }
    }
    LabelTotalPersent->setText(QString("%1/%2 = %3%").arg(QString::number(totalr)).arg(QString::number(totalr+totalnr)).arg(QString::number(100.0*totalr/(totalr+totalnr))));
    LabelTotalPersentCompare->setText(QString("%1/%2\n%3%").arg(QString::number(totalr)).arg(QString::number(totalr+totalnr)).arg(QString::number(100.0*totalr/(totalr+totalnr))));
    emit finished();
    return 1;
}
