#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QString key, QString id, SGames games, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics){
    ui->setupUi(this);
    this->games=games;
    this->key=key;
    this->id=id;
    for(int i=0;i<games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(key,QString::number(games.GetAppid(i)),id);
        connect(pl,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
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
    ach.GetAchievementsCount();
    for (int i=0;i<ach.GetAchievementsCount();i++) {
        //помещаем данные в массивы
        if(ach.GetAchieved(i)==1){
            QDateTime dateTime = ach.GetUnlocktime(i);
            times[dateTime.time().hour()]++;
            months[dateTime.date().month()-1]++;
            //Года
        }
    }
    for (int i=0;i<24;i++) {
        ui->tableWidget->item(0,i)->setText(QString::number(times[i]));
        }
    for (int i=0;i<12;i++) {
        ui->tableWidget_2->item(0,i)->setText(QString::number(months[i]));
        }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
    //ach->deleteLater();
}

FormStatistics::~FormStatistics()
{
    delete ui;
}
