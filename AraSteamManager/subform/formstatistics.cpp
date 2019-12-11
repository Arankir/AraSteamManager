#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QString key, QString id, SGames games, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics){
    ui->setupUi(this);
    this->games=games;
    this->key=key;
    this->id=id;
    numof[0]=0;
    numof[1]=0;
    numof[2]=0;
    averagePercent = new double[games.GetCount()];
    nownum=0;
    summcolumn=0;
    colgames=0;
    for(int i=0;i<games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(key,QString::number(games.GetAppid(i)),id);
        connect(pl,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        averagePercent[i]=0.0;
        }
    for (int i=0;i<24;i++) {
        times[i]=0;
        ui->tableWidget->setItem(0,i,new QTableWidgetItem(0));
        }
    for (int i=0;i<12;i++) {
        months[i]=0;
        ui->tableWidget_2->setItem(0,i,new QTableWidgetItem(0));
        }
}

void FormStatistics::OnResultAchievements(SAchievementsPlayer ach){
    disconnect(&ach,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    if(ach.GetAchievementsCount()>0){
        colgames++;
        int colr=0;
        int colnr=0;
        summcolumn+=ach.GetAchievementsCount();
        for (int i=0;i<ach.GetAchievementsCount();i++) {
            //помещаем данные в массивы
            if(ach.GetAchieved(i)==1){
                QDateTime dateTime = ach.GetUnlocktime(i);
                times[dateTime.time().hour()]++;
                months[dateTime.date().month()-1]++;
                //Года
                colr++;
            } else {
                colnr++;
            }
        }
        for (int i=0;i<24;i++) {
            ui->tableWidget->item(0,i)->setText(QString::number(times[i]));
            }
        for (int i=0;i<12;i++) {
            ui->tableWidget_2->item(0,i)->setText(QString::number(months[i]));
            }
        averagePercent[nownum]=1.0*(colr*100)/(colr+colnr);
        QPair<QString,QString> pair;
        pair.first=ach.GetAppid();
        pair.second=ach.GetGamename();
        if(colnr==0){
            numof[2]++;
            complete.append(pair);
        } else if(colr==0){
            numof[0]++;
            started.append(pair);
        } else {
            numof[1]++;
            notStarted.append(pair);
        }
        if(nownum==games.GetCount()-1){
            double aver=0.0;
            for (int i=0;i<games.GetCount();i++) {
                aver+=averagePercent[i];
            }
            aver/=colgames;
            ui->LabelAveragePercent->setText(tr("Средний процент по играм: %1%").arg(QString::number(aver)));
            ui->LabelNumOf->setText(tr("Не начатых игр: %1 \nНачатых игр: %2 \nЗаконченных игр: %3").arg(numof[0]).arg(numof[1]).arg(numof[2]));
            ui->LabelSummColumn->setText(tr("Всего достижений: %1").arg(summcolumn));
        }
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
    nownum++;
    //ach->deleteLater();
}

FormStatistics::~FormStatistics()
{
    delete ui;
}
