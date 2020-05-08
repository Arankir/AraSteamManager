#include "threadstatistics.h"

int ThreadStatistics::Fill(){
    for(int i=0;i<_games.GetCount();i++){
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(_games[i].GetAppid()),_id);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        _averagePercent[i]=0.0;
    }
    return 1;
}

void ThreadStatistics::OnResultAchievements(SAchievementsPlayer a_achievements){
    disconnect(&a_achievements,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    emit s_progress(_nownum,0);
    if(a_achievements.GetCount()>0){
        _colgames++;
        int colr=0;
        int colnr=0;
        _summcolumn+=a_achievements.GetCount();
        for(auto &achievement: a_achievements){
            if(achievement.GetAchieved()==1){
                QDateTime dateTime = achievement.GetUnlocktime();
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
            _complete.append(QPair<QString,QString>(a_achievements.GetAppid(),a_achievements.GetGamename()));
        } else if(colr==0){
            _numof[0]++;
            _started.append(QPair<QString,QString>(a_achievements.GetAppid(),a_achievements.GetGamename()));
        } else {
            _numof[1]++;
            _notStarted.append(QPair<QString,QString>(a_achievements.GetAppid(),a_achievements.GetGamename()));
        }
    }
    _nownum++;
    if(_nownum==_games.GetCount()){
        emit s_finished(_numof,_complete,_started,_notStarted,_averagePercent,_summcolumn,_times,_months,_years);
        this->deleteLater();
        }
}
