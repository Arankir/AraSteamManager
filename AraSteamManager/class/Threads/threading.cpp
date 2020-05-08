#include "threading.h"

Threading::Threading(QObject *parent) : QObject(parent)
{

}

int Threading::AddThreadGames(const int a_columnID, const int a_columnIndex, const int a_columnName, QTableWidget *a_tableWidgetGames, SGames a_games){
    ThreadGames *Games = new ThreadGames(a_columnID, a_columnIndex, a_columnName, a_tableWidgetGames, a_games);
    QThread *thread = new QThread;
    Games->moveToThread(thread);
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

int Threading::AddThreadFriends(const int a_columnID, const int a_columnName, const int a_columnAdded, const int a_columnStatus, const int a_columnisPublic,
                                QTableWidget *a_tableWidgetFriends, SProfiles a_profiles, SFriends a_friends){
    ThreadFriends *Friends = new ThreadFriends(a_columnID, a_columnName, a_columnAdded, a_columnStatus, a_columnisPublic, a_tableWidgetFriends, a_profiles, a_friends);
    QThread *thread = new QThread;
    Friends->moveToThread(thread);
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
    ThreadStatistics *Statistics = new ThreadStatistics(a_games, a_id);
    QThread *thread = new QThread;
    Statistics->moveToThread(thread);
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

int Threading::AddThreadAchievements(const int a_tableColumnAppid, const int a_tableColumnTitle, const int a_tableColumnDescription, const int a_tableColumnWorld, const int a_tableColumnMy,
                                     SAchievements a_achievements, QLabel *a_LabelTotalPersent, QTableWidget *a_tableWidgetAchievements, QLabel *a_LabelTotalPersentCompare){
    ThreadAchievements *achievements = new ThreadAchievements(a_achievements, a_LabelTotalPersent, a_tableWidgetAchievements, a_LabelTotalPersentCompare,a_tableColumnAppid,
                                                              a_tableColumnTitle, a_tableColumnDescription, a_tableColumnWorld, a_tableColumnMy);
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    connect(thread,SIGNAL(started()),achievements,SLOT(Fill()));
    connect(achievements,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(achievements,SIGNAL(s_finished()),achievements,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(achievements,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(achievements,SIGNAL(s_finished(int,int)),this->parent(),SLOT(OnFinish(int,int)));
    thread->start();
    return 1;
}

