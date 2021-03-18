#include "threading.h"

int Threading::AddThreadGames(QList<SGame> aGames) {
    ThreadGames *games = new ThreadGames(aGames);
    QThread *thread = createThread();
    games->moveToThread(thread);
    connect(thread, &QThread::started,              games,          &ThreadGames::fill);
    connect(games,  &ThreadGames::s_finished,       thread,         &QThread::quit);
    connect(games,  &ThreadGames::s_finished,       games,          &ThreadGames::deleteLater);
    connect(games,  &ThreadGames::s_progress,       this->parent(), [=](int progress) {emit s_games_progress(progress);});
    connect(games,  &ThreadGames::s_finishedModel,  parent(),       [=](QStandardItemModel *model) {emit s_games_finished_model(model);});
    thread->start();
    return 1;
}

int Threading::AddThreadFriends(QList<QPair<SFriend, SProfile>> aFriends) {
    ThreadFriends *friends = new ThreadFriends(aFriends);
    QThread *thread = createThread();
    friends->moveToThread(thread);
    connect(thread,  &QThread::started,          friends,        &ThreadFriends::fill);
    connect(friends, &ThreadFriends::s_finished, thread,         &QThread::quit);
    connect(friends, &ThreadFriends::s_finished, friends,        &ThreadFriends::deleteLater);
    connect(friends, &ThreadFriends::s_finishedModel, parent(),  [=](QStandardItemModel *model) {emit s_friends_finished_model(model);});
    connect(friends, &ThreadFriends::s_progress, this->parent(), [=](int progress) {emit s_friends_progress(progress);});
    thread->start();
    return 1;
}

int Threading::AddThreadStatistics(QList<SGame> &aGames, const QString &aId, QList<SGame> &aNoAchievements, QList<SGame> &aComplete,
                                   QList<QPair<SGame, double>> &aStarted, QList<SGame> &aNotStarted, int &aAchievementsCount, QVector<int> &aTimes,
                                   QVector<int> &aMonths, QVector<QPair<QString,int>> &aYears) {
    ThreadStatistics *statistics = new ThreadStatistics(aGames, aId, aAchievementsCount, aNoAchievements, aComplete, aStarted, aNotStarted, aTimes, aMonths, aYears);
    QThread *thread = createThread();
    statistics->moveToThread(thread);
    connect(thread,     &QThread::started,              statistics,     &ThreadStatistics::fill);
    connect(statistics, &ThreadStatistics::s_finished,  thread,         &QThread::quit);
    connect(statistics, &ThreadStatistics::s_finished,  statistics,     &ThreadStatistics::deleteLater);
    connect(statistics, &ThreadStatistics::s_progress,  this->parent(), [=](int progress) {emit s_statistics_progress(progress);});
    connect(statistics, &ThreadStatistics::s_finished,  this->parent(), [=]() {emit s_statistics_finished();});
    thread->start();
    return 1;
}

int Threading::AddThreadAchievements(const QColor aAchievedColor, const QColor aNotAchievedColor,
                                     const QList<SAchievement> &aAchievements, int aGameAppId) {
    ThreadAchievements *achievements = new ThreadAchievements(aAchievements, aGameAppId,
                                                              aAchievedColor, aNotAchievedColor);
    QThread *thread = createThread();
    achievements->moveToThread(thread);
    connect(thread,       &QThread::started,               achievements,   &ThreadAchievements::fill);
    connect(achievements, &ThreadAchievements::s_finished, thread,         &QThread::quit);
    connect(achievements, &ThreadAchievements::s_finished, achievements,   &ThreadAchievements::deleteLater);
    connect(achievements, &ThreadAchievements::s_progress, this->parent(), [=](int progress, int max) {emit s_achievements_progress(progress, max);});
    connect(achievements, &ThreadAchievements::s_finishedModel, parent(),  [=](QStandardItemModel *model, int reached, int notReached) {emit s_achievements_finished_model(model, reached, notReached);});
    thread->start();
    return 1;
}

QThread *Threading::createThread() {
    QThread *thread = new QThread;
    connect(thread,       &QThread::finished,              thread,         &QThread::deleteLater);
    connect(thread,       &QThread::finished,              this,           &Threading::deleteLater);
    return thread;
}
