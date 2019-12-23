#include "threadstatistics.h"

ThreadStatistics::ThreadStatistics(QObject *parent) : QObject(parent){
    _times.resize(24);
    _months.resize(12);

    for (int i=0;i<24;i++) {
        _times[i]=QPair<QString,int>(QString::number(i)+":00",0);
        }
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
}

int ThreadStatistics::Fill(){
    for(int i=0;i<_games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(_games.GetAppid(i)),_id);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        _averagePercent[i]=0.0;
    }
}

void ThreadStatistics::Set(SGames Agames, QString Aid){
    _games=Agames;
    _id=Aid;
    _averagePercent.resize(_games.GetCount());
}

void ThreadStatistics::OnResultAchievements(SAchievementsPlayer Aachievement){
    disconnect(&Aachievement,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    emit s_progress(_nownum,0);
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
                int pos=-1;
                for (int i=0;i<_years.size();i++) {
                    if(_years[i].first.toInt()==dateTime.date().year()){
                        pos=i;
                        break;
                    }
                }
                if(pos>-1){
                    _years[pos].second++;
                } else {
                    _years.append(QPair<QString,int>(QString::number(dateTime.date().year()),1));
                    for (int i=_years.size()-1;i>0;i--)
                        if(_years[i].first<_years[i-1].first)
                            std::swap(_years[i],_years[i-1]);
                    _years.resize(_years.size());
                }
                colr++;
            } else {
                colnr++;
            }
        }
        _averagePercent.append(1.0*(colr*100)/(colr+colnr));
        if(colnr==0){
            _numof[2]++;
            _complete.append(QPair<QString,QString>(Aachievement.GetAppid(),Aachievement.GetGamename()));
        } else if(colr==0){
            _numof[0]++;
            _started.append(QPair<QString,QString>(Aachievement.GetAppid(),Aachievement.GetGamename()));
        } else {
            _numof[1]++;
            _notStarted.append(QPair<QString,QString>(Aachievement.GetAppid(),Aachievement.GetGamename()));
        }
    }
    _nownum++;
    if(_nownum==_games.GetCount()){
        emit s_finished(_numof,_complete,_started,_notStarted,_averagePercent,_summcolumn,_times,_months,_years);
        this->deleteLater();
        }
}
