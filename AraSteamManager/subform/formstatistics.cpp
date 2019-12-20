#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QString Aid, SGames Agames, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics){
    ui->setupUi(this);
    _games=Agames;
    _id=Aid;
    averagePercent = new double[_games.GetCount()];
    _times.resize(24);
    _months.resize(12);

    _months[0]=QPair<QString,int>(tr("Январь"),0);
    _months[1]=QPair<QString,int>(tr("Февраль"),0);
    _months[2]=QPair<QString,int>(tr("Март"),0);
    _months[3]=QPair<QString,int>(tr("Апрель"),0);
    _months[4]=QPair<QString,int>(tr("Май"),0);
    _months[5]=QPair<QString,int>(tr("Июнь"),0);
    _months[6]=QPair<QString,int>(tr("Июль"),0);
    _months[7]=QPair<QString,int>(tr("Август"),0);
    _months[8]=QPair<QString,int>(tr("Сентябрь"),0);
    _months[9]=QPair<QString,int>(tr("Октябрь"),0);
    _months[10]=QPair<QString,int>(tr("Ноябрь"),0);
    _months[11]=QPair<QString,int>(tr("Декабрь"),0);

    for(int i=0;i<_games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(_games.GetAppid(i)),_id);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        averagePercent[i]=0.0;
        }
    for (int i=0;i<24;i++) {
        _times[i]=QPair<QString,int>(QString::number(i)+":00",0);
        ui->tableWidget->setItem(0,i,new QTableWidgetItem(0));
        }
    for (int i=0;i<12;i++) {
        ui->tableWidget_2->setItem(0,i,new QTableWidgetItem(0));
        }
}

void FormStatistics::OnResultAchievements(SAchievementsPlayer Aachievement){
    disconnect(&Aachievement,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    if(Aachievement.GetCount()>0){
        _colgames++;
        int colr=0;
        int colnr=0;
        _summcolumn+=Aachievement.GetCount();
        for (int i=0;i<Aachievement.GetCount();i++) {
            //помещаем данные в массивы
            if(Aachievement.GetAchieved(i)==1){
                QDateTime dateTime = Aachievement.GetUnlocktime(i);
                _times[dateTime.time().hour()].second++;
                _months[dateTime.date().month()-1].second++;
                //Года
                colr++;
            } else {
                colnr++;
            }
        }
        for (int i=0;i<24;i++) {
            ui->tableWidget->setHorizontalHeaderItem(i,new QTableWidgetItem(_times[i].first));
            ui->tableWidget->item(0,i)->setText(QString::number(_times[i].second));
            }
        for (int i=0;i<12;i++) {
            ui->tableWidget_2->setHorizontalHeaderItem(i,new QTableWidgetItem(_months[i].first));
            ui->tableWidget_2->item(0,i)->setText(QString::number(_months[i].second));
            }
        averagePercent[_nownum]=1.0*(colr*100)/(colr+colnr);
        QPair<QString,QString> pair;
        pair.first=Aachievement.GetAppid();
        pair.second=Aachievement.GetGamename();
        if(colnr==0){
            _numof[2]++;
            _complete.append(pair);
        } else if(colr==0){
            _numof[0]++;
            _started.append(pair);
        } else {
            _numof[1]++;
            _notStarted.append(pair);
        }
        if(_nownum==_games.GetCount()-1){
            double aver=0.0;
            for (int i=0;i<_games.GetCount();i++) {
                aver+=averagePercent[i];
            }
            aver/=_colgames;
            ui->LabelAveragePercent->setText(tr("Средний процент по играм: %1%").arg(QString::number(aver)));
            ui->LabelNumOf->setText(tr("Не начатых игр: %1 \nНачатых игр: %2 \nЗаконченных игр: %3").arg(_numof[0]).arg(_numof[1]).arg(_numof[2]));
            ui->LabelSummColumn->setText(tr("Всего достижений: %1").arg(_summcolumn));
        }
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
    _nownum++;
    //ach->deleteLater();
}

FormStatistics::~FormStatistics(){
    delete ui;
}
