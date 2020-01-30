#include "threadstatistics.h"

ThreadStatistics::ThreadStatistics(QObject *parent) : QObject(parent){

}

int ThreadStatistics::Fill(){
    for(int i=0;i<_games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(_games[i].GetAppid()),_id);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        _averagePercent[i]=0.0;
    }
}

void ThreadStatistics::Set(SGames a_games, QString a_id){
    _games=a_games;
    _id=a_id;
    _averagePercent.resize(_games.GetCount());
}

void ThreadStatistics::OnResultAchievements(SAchievementsPlayer a_achievement){
    disconnect(&a_achievement,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    emit s_progress(_nownum,0);
    if(a_achievement.GetCount()>0){
        _colgames++;
        int colr=0;
        int colnr=0;
        _summcolumn+=a_achievement.GetCount();
        for (int i=0;i<a_achievement.GetCount();i++) {
            //помещаем данные в массивы
            if(a_achievement[i].GetAchieved()==1){
                QDateTime dateTime = a_achievement[i].GetUnlocktime();
                _times[dateTime.time().hour()]++;
                _months[dateTime.date().month()-1]++;
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
            _complete.append(QPair<QString,QString>(a_achievement.GetAppid(),a_achievement.GetGamename()));
        } else if(colr==0){
            _numof[0]++;
            _started.append(QPair<QString,QString>(a_achievement.GetAppid(),a_achievement.GetGamename()));
        } else {
            _numof[1]++;
            _notStarted.append(QPair<QString,QString>(a_achievement.GetAppid(),a_achievement.GetGamename()));
        }
    }
    _nownum++;
    if(_nownum==_games.GetCount()){
        emit s_finished(_numof,_complete,_started,_notStarted,_averagePercent,_summcolumn,_times,_months,_years);
        this->deleteLater();
        }
}
