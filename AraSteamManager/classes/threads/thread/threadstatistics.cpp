#include "threadstatistics.h"

int ThreadStatistics::fill() {
//    for (auto &game: _games) {
//        SAchievementPlayer::load(game.appId(), _id, std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
//    }
    for (auto &game: _statistics._games) {
        SAchievementPlayer::load(game.appId(), _statistics._profile.steamID(), std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
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
    emit s_progress(tr("Загрузка статистики"), nowProcessed, _statistics._games.count());
    if (aAchievements.count() > 0) {

        int countReached = countReachedAchievements(aAchievements);
        int countNotReached = aAchievements.count() - countReached;
        _statistics._achievementCount += aAchievements.count();

        GameWithPercent resultGame(std::move(aGame), (100.0 * countReached) / aAchievements.count(), aAchievements);
        if (countNotReached == 0) {
            _statistics._complete.append(resultGame);
        } else if (countReached == 0) {
            _statistics._notStarted.append(resultGame);
        } else {
            _statistics._started.append(resultGame);//26.6 //29.7//92.9
        }

    } else {
        GameWithPercent resultGame(std::move(aGame), -1.0, aAchievements);
        _statistics._noAchievements.append(resultGame);
    }
    if (++nowProcessed == _statistics._games.count()) {
        nowProcessed = 0;
        emit s_finished();
        this->deleteLater();
    }
}

int ThreadStatistics::countReachedAchievements(const SAchievementsPlayer &aAchievements) {
    int reached = 0;
    for (auto &achievement: aAchievements) {
        if (achievement.achieved() == 1) {
            updateTimes(achievement.unlockTime());
            ++reached;
        }
    }
    return reached;
}

void ThreadStatistics::updateTimes(const QDateTime &aUnlockedTime) {
    int hour = aUnlockedTime.time().hour();
    int month = aUnlockedTime.date().month();
    int year = aUnlockedTime.date().year();
    ++_statistics._times[hour];
    ++_statistics._months[month - 1];
    auto iterator = std::find_if(_statistics._years.begin(),
                                 _statistics._years.end(),
                                 [=](const YearCount &lYear) {
                                    return lYear.year.toInt() == year;
                                 });
    if (iterator != _statistics._years.end()) {
        ++(*iterator).count;
    } else {
        _statistics._years.append(YearCount(QString::number(year), 1));
    }
}
