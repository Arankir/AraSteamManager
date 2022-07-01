#include "threadstatistics.h"

int ThreadStatistics::fill() {
//    for (auto &game: _games) {
//        SAchievementPlayer::load(game.appId(), _id, std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
//    }
    for (auto &game: statistics_.games) {
        SAchievementsPlayer::load(game.appId(), statistics_.profile.steamID(), std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
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
    emit s_progress(tr("Загрузка статистики"), nowProcessed, statistics_.games.count());
    if (aAchievements.count() > 0) {

        int countReached = countReachedAchievements(aAchievements, aGame);
        int countNotReached = aAchievements.count() - countReached;
        statistics_.achievementCount += countReached;

        GameWithPercentModelItem resultGame(aGame, (100.0 * countReached) / aAchievements.count(), aAchievements);
//        resultGame.game = aGame;
//        resultGame.percent = (100.0 * countReached) / aAchievements.count();
//        resultGame.achievements = aAchievements;
//        (aGame, (100.0 * countReached) / aAchievements.count(), aAchievements);
        if (countNotReached == 0) {
            statistics_.complete.append(resultGame);
        } else if (countReached == 0) {
            statistics_.notStarted.append(resultGame);
        } else {
            statistics_.started.append(resultGame);
        }

    } else {
        GameWithPercentModelItem resultGame(aGame, -1, aAchievements);
//        resultGame.game = aGame;
//        resultGame.percent = -1;
//        resultGame.achievements = aAchievements;

//        (aGame, -1.0, aAchievements);
        statistics_.noAchievements.append(resultGame);
    }
    if (++nowProcessed == statistics_.games.count()) {
        nowProcessed = 0;
        emit s_finish(statistics_);
        this->deleteLater();
    }
}

int ThreadStatistics::countReachedAchievements(const SAchievementsPlayer &aAchievements, const SGame &aGame) {
    int reached = 0;
    for (auto &achievement: aAchievements) {
        if (achievement.achieved() == 1) {
            updateTimes(achievement.unlockTime());

            statistics_.completedAchievements.append(CompletedAchievement(achievement, aGame));

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
    auto iterator = std::find_if(statistics_.years.begin(),
                                 statistics_.years.end(),
                                 [=](const YearCount &lYear) {
                                    return lYear.year.toInt() == year;
                                 });
    if (iterator != statistics_.years.end()) {
        ++(*iterator).count;
    } else {
        statistics_.years.append(YearCount(QString::number(year), 1));
    }
}

void Statistics::changeProfile(const SProfile &aProfile) {
    profile = aProfile;
    games = SGame::load(profile.steamID(), true, true);

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
    std::sort(complete.begin(),
              complete.end(),
              [](GameWithPercentModelItem &game1, GameWithPercentModelItem &game2) {
                return game1.game < game2.game;
              });
    std::sort(started.begin(),
              started.end(),
              [](GameWithPercentModelItem &game1, GameWithPercentModelItem &game2) {
                return game1.game < game2.game;
              });
    std::sort(notStarted.begin(),
              notStarted.end(),
              [](GameWithPercentModelItem &game1, GameWithPercentModelItem &game2) {
                return game1.game < game2.game;
              });
    std::sort(noAchievements.begin(),
              noAchievements.end(),
              [](GameWithPercentModelItem &game1, GameWithPercentModelItem &game2) {
                return game1.game < game2.game;
              });
    std::sort(completedAchievements.begin(),
              completedAchievements.end(),
              [](CompletedAchievement &game1, CompletedAchievement &game2) {
                return game1.achievement.unlockTime() < game2.achievement.unlockTime();
              });
    std::sort(years.begin(),
              years.end(),
              [](const YearCount &p1, const YearCount &p2) {
                return p1.year < p2.year;
              });
}
