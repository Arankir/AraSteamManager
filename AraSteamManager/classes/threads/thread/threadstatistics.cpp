#include "threadstatistics.h"

int ThreadStatistics::fill() {
//    for (auto &game: _games) {
//        SAchievementPlayer::load(game.appId(), _id, std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
//    }
    for (auto &game: _statistics.games) {
        SAchievementPlayer::load(game.appId(), _statistics.profile.steamID(), std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(const SAchievementsPlayer &aAchievements, const SGame &aGame) {
    //    static int nowProcessed = 0;
    //    emit s_progress(tr("Загрузка статистики"), nowProcessed, _games.count());
    //    if (aAchievements.count() > 0) {

    //        int countReached = countReachedAchievements(aAchievements);
    //        int countNotReached = aAchievements.count() - countReached;
    //        _achievementsCount += aAchievements.count();

    //        if (countNotReached == 0) {
    //            _complete.append(std::move(aGame));
    //        } else if (countReached == 0) {
    //            _notStarted.append(std::move(aGame));
    //        } else {
    //            _started.append(QPair<SGame, double>(std::move(aGame), (100.0 * countReached) / aAchievements.count()));
    //        }

    //    } else {
    //        _noAchievements.append(std::move(aGame));
    //    }
    //    if (++nowProcessed == _games.count()) {
    //        emit s_finished();
    //        this->deleteLater();
    //    }
    static int nowProcessed = 0;
    emit s_progress(tr("Загрузка статистики"), nowProcessed, _statistics.games.count());
    if (aAchievements.count() > 0) {

        int countReached = countReachedAchievements(aAchievements, aGame);
        int countNotReached = aAchievements.count() - countReached;
        _statistics.achievementCount += countReached;

        GameWithPercent resultGame(aGame, (100.0 * countReached) / aAchievements.count(), aAchievements);
        if (countNotReached == 0) {
            _statistics.complete.append(resultGame);
        } else if (countReached == 0) {
            _statistics.notStarted.append(resultGame);
        } else {
            _statistics.started.append(resultGame);
        }

    } else {
        GameWithPercent resultGame(aGame, -1.0, aAchievements);
        _statistics.noAchievements.append(resultGame);
    }
    if (++nowProcessed == _statistics.games.count()) {
        nowProcessed = 0;
        emit s_finish(_statistics);
        this->deleteLater();
    }
}

int ThreadStatistics::countReachedAchievements(const SAchievementsPlayer &aAchievements, const SGame &aGame) {
    int reached = 0;
    for (auto &achievement: aAchievements) {
        if (achievement.achieved() == 1) {
            updateTimes(achievement.unlockTime());

            _statistics.completedAchievements.append(CompletedAchievement(achievement, aGame));

            ++reached;
        }
    }
    return reached;
}

void ThreadStatistics::updateTimes(const QDateTime &aUnlockedTime) {
//    int hour = aUnlockedTime.time().hour();
//    int month = aUnlockedTime.date().month();
    int year = aUnlockedTime.date().year();
//    ++_statistics.times[hour];
//    ++_statistics.months[month - 1];
    auto iterator = std::find_if(_statistics.years.begin(),
                                 _statistics.years.end(),
                                 [=](const YearCount &lYear) {
                                    return lYear.year.toInt() == year;
                                 });
    if (iterator != _statistics.years.end()) {
        ++(*iterator).count;
    } else {
        _statistics.years.append(YearCount(QString::number(year), 1));
    }
}

void Statistics::changeProfile(const SProfile &aProfile, const SGames &aGames) {
    profile = aProfile;
    games = aGames;

    summAverages = 0.0;
    achievementCount = 0;
    complete.clear();
    started.clear();
    notStarted.clear();
    noAchievements.clear();
    completedAchievements.clear();
    years.clear();
}

void Statistics::sortAllLists() {
    mySort<GameWithPercent>(complete, [](GameWithPercent &game1, GameWithPercent &game2)
        {return game1.game < game2.game;});
    mySort<GameWithPercent>(started, [](GameWithPercent &game1, GameWithPercent &game2)
        {return game1.game < game2.game;});
    mySort<GameWithPercent>(notStarted, [](GameWithPercent &game1, GameWithPercent &game2)
        {return game1.game < game2.game;});
    mySort<GameWithPercent>(noAchievements, [](GameWithPercent &game1, GameWithPercent &game2)
        {return game1.game < game2.game;});
    mySort<CompletedAchievement>(completedAchievements, [](CompletedAchievement &game1, CompletedAchievement &game2)
        {return game1.achievement.unlockTime() < game2.achievement.unlockTime();});
    std::sort(years.begin(),
              years.end(),
              [](const YearCount &p1, const YearCount &p2) {
                    return p1.year < p2.year;
                });
}
