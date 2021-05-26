#include "threadstatistics.h"

int ThreadStatistics::fill() {
    for (auto &game: _games) {
        SAchievementPlayer::load(game.sAppId(), _id, std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(const QList<SAchievementPlayer> &aAchievements, const SGame &aGame) {
    static int nowProcessed = 0;
    emit s_progress(nowProcessed);
    if (aAchievements.count() > 0) {

        int countReached = countReachedAchievements(aAchievements);
        int countNotReached = aAchievements.count() - countReached;
        _achievementsCount += aAchievements.count();

        if (countNotReached == 0) {
            _complete.append(std::move(aGame));
        } else if (countReached == 0) {
            _notStarted.append(std::move(aGame));
        } else {
            _started.append(QPair<SGame, double>(std::move(aGame), (100.0 * countReached) / aAchievements.count()));
        }

    } else {
        _noAchievements.append(std::move(aGame));
    }
    if (++nowProcessed == _games.count()) {
        emit s_finished();
        this->deleteLater();
    }
}

int ThreadStatistics::countReachedAchievements(const QList<SAchievementPlayer> &aAchievements) {
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
#define yearType QPair<QString,int>
    int hour = aUnlockedTime.time().hour();
    int month = aUnlockedTime.date().month();
    int year = aUnlockedTime.date().year();
    ++_times[hour];
    ++_months[month - 1];
    auto iterator = std::find_if(_years.begin(),
                                 _years.end(),
                                 [=](const yearType &lYear) {
                                    return lYear.first.toInt() == year;
                                 });
    if (iterator != _years.end()) {
        ++(*iterator).second;
    } else {
        _years.append(yearType(QString::number(year), 1));
    }
}
