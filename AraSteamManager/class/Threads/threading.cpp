#include "threading.h"

Threading::Threading(QObject *parent): QObject(parent) {

}

int Threading::AddThreadGames(const int aColumnID, const int aColumnIndex, const int aColumnName, QTableWidget *aTableWidgetGames, SGames aGames) {
    ThreadGames *games = new ThreadGames(aColumnID, aColumnIndex, aColumnName, aTableWidgetGames, aGames);
    QThread *thread = new QThread;
    games->moveToThread(thread);
    connect(thread,SIGNAL(started()),games,SLOT(Fill()));
    connect(games,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(games,SIGNAL(s_finished()),games,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(games,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(games,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    //connect(Games,SIGNAL(s_finished()),this->parent()->parent(),SLOT(ShowGames()));
    connect(games,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(const int aColumnID, const int aColumnName, const int aColumnAdded, const int aColumnStatus, const int aColumnisPublic,
                                QTableWidget *aTableWidgetFriends, SProfiles aProfiles, SFriends aFriends) {
    ThreadFriends *friends = new ThreadFriends(aColumnID, aColumnName, aColumnAdded, aColumnStatus, aColumnisPublic, aTableWidgetFriends, aProfiles, aFriends);
    QThread *thread = new QThread;
    friends->moveToThread(thread);
    connect(thread,SIGNAL(started()),friends,SLOT(Fill()));
    connect(friends,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(friends,SIGNAL(s_finished()),friends,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(friends,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(friends,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(friends,SIGNAL(s_finished()),this->parent()->parent(),SLOT(ShowFriends()));
    connect(friends,SIGNAL(s_finished()),this->parent(),SLOT(OnFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadStatistics(SGames aGames, QString aId) {
    ThreadStatistics *statistics = new ThreadStatistics(aGames, aId);
    QThread *thread = new QThread;
    statistics->moveToThread(thread);
    connect(thread,SIGNAL(started()),statistics,SLOT(Fill()));
    connect(statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>)),thread,SLOT(quit()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(statistics,SIGNAL(s_progress(int,int)),this->parent()->parent(),SLOT(ProgressLoading(int,int)));
    connect(statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>))
            ,this->parent(),SLOT(OnFinish(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>)));
    connect(statistics,SIGNAL(s_finished(QVector<int>, QVector<QPair<QString,QString>>, QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> ,
                              QVector<double>, int, QVector<int>, QVector<int>, QVector<QPair<QString,int>>))
            ,this->parent()->parent(),SLOT(ShowStatistic()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriendAchievements(QTableWidget *aTableWidgetAchievements, SAchievements aAchievement, int aCol, int aColumnAppid) {
    ThreadAchievements *achievements = new ThreadAchievements;
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    achievements->setFriend(aTableWidgetAchievements, aAchievement, aCol, aColumnAppid);
    connect(thread,SIGNAL(started()),achievements,SLOT(AddFriend()));
    connect(achievements,SIGNAL(s_finished()),thread,SLOT(quit()));
    connect(achievements,SIGNAL(s_finished()),achievements,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    //connect(Achievements,SIGNAL(s_progress(int,int)),this->parent(),SLOT(ProgressLoading(int,int)));
    connect(achievements,SIGNAL(s_is_public(bool,int)),this->parent(),SLOT(CreateCompareProfileFilter(bool,int)));
    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(const int aTableColumnAppid, const int aTableColumnTitle, const int aTableColumnDescription, const int aTableColumnWorld, const int aTableColumnMy,
                                     SAchievements aAchievements, QTableWidget *aTableWidgetAchievements) {
    ThreadAchievements *achievements = new ThreadAchievements(aAchievements, aTableWidgetAchievements, aTableColumnAppid, aTableColumnTitle, aTableColumnDescription,
                                                              aTableColumnWorld, aTableColumnMy);
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

