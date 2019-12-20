#include "threading.h"

Threading::Threading(QObject *parent) : QObject(parent)
{

}

int Threading::AddThreadGames(QTableWidget *AtableWidgetGames, QVector<SGame> Agames){
    ThreadGames *Games = new ThreadGames;
    QThread *thread = new QThread;
    Games->moveToThread(thread);
    Games->Set(AtableWidgetGames,Agames);
    connect(thread,SIGNAL(started()),Games,SLOT(Fill()));
    connect(Games,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(Games,SIGNAL(s_finished()),Games,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Games,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Games,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Games,SIGNAL(s_finished()),this->parent()->parent(),SLOT(ShowGames()));
    connect(Games,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(QTableWidget *AtableWidgetFriends,QVector<SProfile> Aprofiles,SFriends Afriends){
    ThreadFriends *Friends = new ThreadFriends;
    QThread *thread = new QThread;
    Friends->moveToThread(thread);
    Friends->Set(AtableWidgetFriends,Aprofiles,Afriends);
    connect(thread,SIGNAL(started()),Friends,SLOT(Fill()));
    connect(Friends,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(Friends,SIGNAL(s_finished()),Friends,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Friends,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Friends,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Friends,SIGNAL(s_finished()),this->parent()->parent(),SLOT(ShowFriends()));
    connect(Friends,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(SAchievements AAchievements, QLabel *ALabelTotalPersent, QTableWidget *AtableWidgetAchievements, QLabel *ALabelTotalPersentCompare, QTableWidget *AtableWidgetCompareAchievements){
    ThreadAchievements *Achievements = new ThreadAchievements;
    QThread *thread = new QThread;
    Achievements->moveToThread(thread);
    Achievements->Set(AAchievements, ALabelTotalPersent, AtableWidgetAchievements, ALabelTotalPersentCompare, AtableWidgetCompareAchievements);
    connect(thread,SIGNAL(started()),Achievements,SLOT(Fill()));
    connect(Achievements,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(Achievements,SIGNAL(s_finished()),Achievements,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Achievements,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Achievements,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

