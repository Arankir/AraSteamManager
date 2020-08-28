#include "threading.h"

Threading::Threading(QObject *parent): QObject(parent) {

}

int Threading::AddThreadGames(const int aColumnID, const int aColumnIndex, const int aColumnName, QTableWidget *aTableWidgetGames, SGames aGames) {
    ThreadGames *games = new ThreadGames(aColumnID, aColumnIndex, aColumnName, aTableWidgetGames, aGames);
    QThread *thread = new QThread;
    games->moveToThread(thread);
    connect(thread, &QThread::started,        games,          &ThreadGames::fill);
    connect(games,  &ThreadGames::s_finished, thread,         &QThread::quit);
    connect(games,  &ThreadGames::s_finished, games,          &ThreadGames::deleteLater);
    connect(thread, &QThread::finished,       thread,         &QThread::deleteLater);
    connect(thread, &QThread::finished,       this,           &Threading::deleteLater);
    connect(games,  &ThreadGames::s_progress, this->parent(), [=](int progress, int row) {
        emit s_games_progress(progress, row);
    });
    connect(games,  &ThreadGames::s_finished, this->parent(), [=]() {
        emit s_games_finished();
    });
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(const int aColumnID, const int aColumnName, const int aColumnAdded, const int aColumnStatus, const int aColumnisPublic,
                                QTableWidget *aTableWidgetFriends, QList<QPair<SFriend, SProfile>> aFriends) {
    ThreadFriends *friends = new ThreadFriends(aColumnID, aColumnName, aColumnAdded, aColumnStatus, aColumnisPublic, aTableWidgetFriends, aFriends);
    QThread *thread = new QThread;
    friends->moveToThread(thread);
    connect(thread,  &QThread::started,          friends,        &ThreadFriends::fill);
    connect(friends, &ThreadFriends::s_finished, thread,         &QThread::quit);
    connect(friends, &ThreadFriends::s_finished, friends,        &ThreadFriends::deleteLater);
    connect(thread,  &QThread::finished,         thread,         &QThread::deleteLater);
    connect(thread,  &QThread::finished,         this,           &Threading::deleteLater);
    connect(friends, &ThreadFriends::s_progress, this->parent(), [=](int progress, int row) {
        emit s_friends_progress(progress, row);
    });
    connect(friends, &ThreadFriends::s_finished, this->parent(), [=]() {
        emit s_friends_finished();
    });
    thread->start();
    return 1;
}

int Threading::AddThreadStatistics(SGames aGames, QString aId, QVector<int> &aNumOf, QVector<QPair<QString,QString> > &aComplete,
                                   QVector<QPair<QString,QString>> &aStarted, QVector<QPair<QString,QString>> &aNotStarted,
                                   QVector<double> &aAveragePercent, int &aSummColumn, QVector<int> &aTimes,
                                   QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears) {
    ThreadStatistics *statistics = new ThreadStatistics(aGames, aId, aNumOf, aComplete, aStarted, aNotStarted, aAveragePercent, aSummColumn, aTimes, aMonths, aYears);
    QThread *thread = new QThread;
    statistics->moveToThread(thread);
    connect(thread,     &QThread::started,              statistics,     &ThreadStatistics::fill);
    connect(statistics, &ThreadStatistics::s_finished,  thread,         &QThread::quit);
    connect(statistics, &ThreadStatistics::s_finished,  statistics,     &ThreadStatistics::deleteLater);
    connect(thread,     &QThread::finished,             thread,         &QThread::deleteLater);
    connect(thread,     &QThread::finished,             this,           &Threading::deleteLater);
    connect(statistics, &ThreadStatistics::s_progress,  this->parent(), [=](int progress, int row) {
        emit s_statistics_progress(progress, row);
    });
    connect(statistics, &ThreadStatistics::s_finished,  this->parent(), [=]() {
        emit s_statistics_finished();
    });
    thread->start();
    return 1;
}

int Threading::AddThreadFriendAchievements(QTableWidget *aTableWidgetAchievements, SAchievements aAchievement, int aCol, int aColumnAppid) {
    Q_UNUSED(aTableWidgetAchievements);
    Q_UNUSED(aAchievement);
    Q_UNUSED(aCol);
    Q_UNUSED(aColumnAppid);
//    ThreadAchievements *achievements = new ThreadAchievements;
//    QThread *thread = new QThread;
//    achievements->moveToThread(thread);
//    achievements->setFriend(aTableWidgetAchievements, aAchievement, aCol, aColumnAppid);
//    connect(thread,       &QThread::started,                achievements,   &ThreadAchievements::addFriend);
//    connect(achievements, &ThreadAchievements::s_finished,  thread,         &QThread::quit);
//    connect(achievements, &ThreadAchievements::s_finished,  achievements,   &ThreadAchievements::deleteLater);
//    connect(thread,       &QThread::finished,               thread,         &QThread::deleteLater);
//    connect(thread,       &QThread::finished,               this,           &Threading::deleteLater);
//    connect(achievements, &ThreadAchievements::s_is_public, this->parent(), [=](bool isVisible, int column) {
//        emit s_achievements_friends_is_public(isVisible, column);
//    });
//    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(const int aTableColumnAppid, const int aTableColumnTitle, const int aTableColumnDescription, const int aTableColumnWorld, const int aTableColumnMy,
                                     SAchievements *aAchievements, QTableWidget *aTableWidgetAchievements) {
    ThreadAchievements *achievements = new ThreadAchievements(aAchievements, aTableWidgetAchievements, aTableColumnAppid, aTableColumnTitle, aTableColumnDescription,
                                                              aTableColumnWorld, aTableColumnMy);
    QThread *thread = new QThread;
    achievements->moveToThread(thread);
    connect(thread,       &QThread::started,               achievements,   &ThreadAchievements::fill);
    connect(achievements, &ThreadAchievements::s_finished, thread,         &QThread::quit);
    connect(achievements, &ThreadAchievements::s_finished, achievements,   &ThreadAchievements::deleteLater);
    connect(thread,       &QThread::finished,              thread,         &QThread::deleteLater);
    connect(thread,       &QThread::finished,              this,           &Threading::deleteLater);
    connect(achievements, &ThreadAchievements::s_progress, this->parent(), [=](int progress, int row) {
        emit s_achievements_progress(progress, row);
    });
    connect(achievements, &ThreadAchievements::s_finished, this->parent(), [=](int totalReached, int totalNotReached) {
        emit s_achievements_finished(totalReached, totalNotReached);
    });
    thread->start();
    return 1;
}

