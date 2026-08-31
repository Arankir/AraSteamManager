#include "threadstatistics.h"

int ThreadStatistics::fill() {
    for (const SGame &game: statistics_.games) {
        SAchievementsPlayer::load(game.appId(), statistics_.profile.steamId(), std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
    }
    if (statistics_.games.isEmpty()) {
        emit s_finish(statistics_);
        this->deleteLater();
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(const SAchievementsPlayer &aAchievements, const SGame &aGame) {
    static int nowProcessed = 0;
    emit s_progress(tr("Загрузка статистики"), nowProcessed, statistics_.games.count());
    if (aAchievements.count() > 0) {

        int countReached = countReachedAchievements(aAchievements, aGame);
        int countNotReached = aAchievements.count() - countReached;
        statistics_.achievementCount += countReached;

        GameWithPercentModelItem resultGame(aGame, (100.0 * countReached) / aAchievements.count(), aAchievements);
        if (countNotReached == 0) {
            statistics_.complete.append(resultGame);
        } else if (countReached == 0) {
            statistics_.notStarted.append(resultGame);
        } else {
            statistics_.started.append(resultGame);
        }

    } else {
        GameWithPercentModelItem resultGame(aGame, -1, aAchievements);
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
    for (const SAchievementPlayer &achievement: aAchievements) {
        if (achievement.achieved() == 1) {
            updateTimes(achievement.unlockTime());

            statistics_.completedAchievements.append(CompletedAchievement(achievement, aGame));

            ++reached;
        }
    }
    return reached;
}

void ThreadStatistics::updateTimes(const QDateTime &aUnlockedTime) {
    int year = aUnlockedTime.date().year();
    if (statistics_.years.find(year) == statistics_.years.end()) {
        statistics_.years.insert(year, 0);
    }
    statistics_.years.find(year).value()++;
}

ThreadStatistics::ThreadStatistics(Statistics &statistic): statistics_(statistic) {

}

ThreadStatistics::~ThreadStatistics() {
    qInfo() << "Thread statistic deleted";
}

Statistics::Statistics(const SProfile &aProfile): profile(aProfile), games(SGame::load(aProfile.steamId(), true, true)) {

}

Statistics::Statistics() {

}

void Statistics::changeProfile(const SProfile &aProfile) {
    profile = aProfile;
    games = SGame::load(profile.steamId(), true, true);

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
}

CompletedAchievement::CompletedAchievement(SAchievementPlayer aAchievement, SGame aGame): achievement(aAchievement), game(aGame) {

}
