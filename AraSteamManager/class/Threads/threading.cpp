#include "threading.h"

Threading::Threading(QObject *parent) : QObject(parent)
{

}

int Threading::AddThreadGames(QTableWidget *a_tableWidgetGames, SGames a_games){
    ThreadGames *Games = new ThreadGames;
    QThread *thread = new QThread;
    Games->moveToThread(thread);
    Games->Set(a_tableWidgetGames,a_games);
    connect(thread,SIGNAL(started()),Games,SLOT(Fill()));
    connect(Games,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(Games,SIGNAL(s_finished()),Games,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Games,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Games,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    //connect(Games,SIGNAL(s_finished()),this->parent()->parent(),SLOT(ShowGames()));
    connect(Games,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(QTableWidget *a_tableWidgetFriends, SProfiles a_profiles,SFriends a_friends){
    ThreadFriends *Friends = new ThreadFriends;
    QThread *thread = new QThread;
    Friends->moveToThread(thread);
    Friends->Set(a_tableWidgetFriends,a_profiles,a_friends);
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

int Threading::AddThreadStatistics(SGames a_games, QString a_id){
    ThreadStatistics *Statistics = new ThreadStatistics;
    QThread *thread = new QThread;
    Statistics->moveToThread(thread);
    Statistics->Set(a_games, a_id);
    connect(thread,SIGNAL(started()),Statistics,SLOT(Fill()));
    connect(Statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>)),thread,SLOT(quit()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(Statistics,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(Statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>))
            ,this->parent(),SLOT(OnFinish(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>)));
    connect(Statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>))
            ,this->parent()->parent(),SLOT(ShowStatistic()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriendAchievements(QTableWidget *a_tableWidgetAchievements, SAchievements a_achievement, int a_col, int a_columnAppid){
    ThreadAchievements *Achievements = new ThreadAchievements;
    QThread *thread = new QThread;
    Achievements->moveToThread(thread);
    Achievements->SetFriend(a_tableWidgetAchievements, a_achievement, a_col, a_columnAppid);
    connect(thread,SIGNAL(started()),Achievements,SLOT(AddFriend()));
    connect(Achievements,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(Achievements,SIGNAL(s_finished()),Achievements,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    //connect(Achievements,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(Achievements,SIGNAL(s_is_public(bool,int)),this->parent(),SLOT(CreateCompareProfileFilter(bool,int)));
    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(SAchievements a_achievements, QLabel *a_LabelTotalPersent, QTableWidget *a_tableWidgetAchievements, QLabel *a_LabelTotalPersentCompare, QTableWidget *a_tableWidgetCompareAchievements){
    ThreadAchievements *achievements = new ThreadAchievements;
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    achievements->Set(a_achievements, a_LabelTotalPersent, a_tableWidgetAchievements, a_LabelTotalPersentCompare, a_tableWidgetCompareAchievements);
    connect(thread,SIGNAL(started()),achievements,SLOT(Fill()));
    connect(achievements,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(achievements,SIGNAL(s_finished()),achievements,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(achievements,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(achievements,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

