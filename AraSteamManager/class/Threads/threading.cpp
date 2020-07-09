#include "threading.h"

Threading::Threading(QObject *parent): QObject(parent) {

}

int Threading::AddThreadGames(const int aColumnID, const int aColumnIndex, const int aColumnName, QTableWidget *aTableWidgetGames, SGames aGames) {
    ThreadGames *games = new ThreadGames(aColumnID, aColumnIndex, aColumnName, aTableWidgetGames, aGames);
    QThread *thread = new QThread;
    games->moveToThread(thread);
    connect(thread, SIGNAL(started()), games, SLOT(fill()));
    connect(games, SIGNAL(s_finished()), thread, SLOT(quit()));
    connect(games, SIGNAL(s_finished()), games, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(games, SIGNAL(s_progress(int, int)), this->parent()->parent(), SLOT(progressLoading(int, int)));
    connect(games, SIGNAL(s_progress(int, int)), this->parent(), SLOT(progressLoading(int, int)));
    //connect(Games, SIGNAL(s_finished()), this->parent()->parent(), SLOT(showGames()));
    connect(games, SIGNAL(s_finished()), this->parent(), SLOT(onFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(const int aColumnID, const int aColumnName, const int aColumnAdded, const int aColumnStatus, const int aColumnisPublic,
                                QTableWidget *aTableWidgetFriends, SProfiles aProfiles, SFriends aFriends) {
    ThreadFriends *friends = new ThreadFriends(aColumnID, aColumnName, aColumnAdded, aColumnStatus, aColumnisPublic, aTableWidgetFriends, aProfiles, aFriends);
    QThread *thread = new QThread;
    friends->moveToThread(thread);
    connect(thread, SIGNAL(started()), friends, SLOT(fill()));
    connect(friends, SIGNAL(s_finished()), thread, SLOT(quit()));
    connect(friends, SIGNAL(s_finished()), friends, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(friends, SIGNAL(s_progress(int, int)), this->parent()->parent(), SLOT(progressLoading(int, int)));
    connect(friends, SIGNAL(s_progress(int, int)), this->parent(), SLOT(progressLoading(int, int)));
    connect(friends, SIGNAL(s_finished()), this->parent()->parent(), SLOT(showFriends()));
    connect(friends, SIGNAL(s_finished()), this->parent(), SLOT(onFinish()));
    thread->start();
    return 1;
}

int Threading::AddThreadStatistics(SGames aGames, QString aId) {
    ThreadStatistics *statistics = new ThreadStatistics(aGames, aId);
    QThread *thread = new QThread;
    statistics->moveToThread(thread);
    connect(thread, SIGNAL(started()), statistics, SLOT(fill()));
    connect(statistics, SIGNAL(s_finished(
                               QVector<int>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<double>,
                               int,
                               QVector<int>,
                               QVector<int>,
                               QVector<QPair<QString, int>>
                               )), thread, SLOT(quit()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(statistics, SIGNAL(s_progress(int, int)), this->parent()->parent(), SLOT(progressLoading(int, int)));
    connect(statistics, SIGNAL(s_finished(
                               QVector<int>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<double>,
                               int,
                               QVector<int>,
                               QVector<int>,
                               QVector<QPair<QString, int>>
                               )), this->parent(), SLOT(onFinish(
                               QVector<int>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<double>,
                               int,
                               QVector<int>,
                               QVector<int>,
                               QVector<QPair<QString, int>>
                               )));
    connect(statistics,SIGNAL(s_finished(
                               QVector<int>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<QPair<QString, QString>>,
                               QVector<double>,
                               int,
                               QVector<int>,
                               QVector<int>,
                               QVector<QPair<QString, int>>
                               )), this->parent()->parent(), SLOT(showStatistic()));
    thread->start();
    return 1;
}

int Threading::AddThreadFriendAchievements(QTableWidget *aTableWidgetAchievements, SAchievements aAchievement, int aCol, int aColumnAppid) {
    ThreadAchievements *achievements = new ThreadAchievements;
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    achievements->setFriend(aTableWidgetAchievements, aAchievement, aCol, aColumnAppid);
    connect(thread, SIGNAL(started()), achievements, SLOT(addFriend()));
    connect(achievements, SIGNAL(s_finished()), thread, SLOT(quit()));
    connect(achievements, SIGNAL(s_finished()), achievements, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //connect(Achievements, SIGNAL(s_progress(int, int)), this->parent(), SLOT(progressLoading(int, int)));
    connect(achievements, SIGNAL(s_is_public(bool, int)), this->parent(), SLOT(createCompareProfileFilter(bool, int)));
    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(const int aTableColumnAppid, const int aTableColumnTitle, const int aTableColumnDescription, const int aTableColumnWorld, const int aTableColumnMy,
                                     SAchievements aAchievements, QTableWidget *aTableWidgetAchievements) {
    ThreadAchievements *achievements = new ThreadAchievements(aAchievements, aTableWidgetAchievements, aTableColumnAppid, aTableColumnTitle, aTableColumnDescription,
                                                              aTableColumnWorld, aTableColumnMy);
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    connect(thread, SIGNAL(started()), achievements, SLOT(fill()));
    connect(achievements, SIGNAL(s_finished()), thread, SLOT(quit()));
    connect(achievements, SIGNAL(s_finished()), achievements, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(achievements, SIGNAL(s_progress(int, int)), this->parent(), SLOT(progressLoading(int, int)));
    connect(achievements, SIGNAL(s_finished(int, int)), this->parent(), SLOT(onTablePulled(int, int)));
    thread->start();
    return 1;
}

