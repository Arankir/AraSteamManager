#include "threadstatistics.h"

int ThreadStatistics::fill() {
    for (auto &game: _games) {
        SAchievementPlayer::load(game.sAppId(), _id, std::bind(&ThreadStatistics::onResultAchievements, this, std::placeholders::_1, game));
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(QList<SAchievementPlayer> aAchievements, SGame aGame) {
    static int nowProcessed = 0;
    emit s_progress(nowProcessed);
    if (aAchievements.count() > 0) {
        ++_colgames;
        int countReached = 0;
        int countNotReached = 0;

        for (auto &achievement: aAchievements) {
            if (achievement.achieved() == 1) {
                updateTimes(achievement.unlockTime());
                ++countReached;
            } else {
                ++countNotReached;
            }
        }

        _summcolumn += aAchievements.count();

        if (countNotReached == 0) {
            _complete.append(aGame);
        } else if (countReached == 0) {
            _notStarted.append(aGame);
        } else {
            _started.append(QPair<SGame, double>(aGame, (100.0 * countReached) / (countReached + countNotReached)));
        }
    } else {
        _noAchievements.append(aGame);
    }
    if (++nowProcessed == _games.count()) {
        emit s_finished();
        this->deleteLater();
    }
}

void ThreadStatistics::updateTimes(const QDateTime &achievementTime) {
#define yearType QPair<QString,int>
    int hour = achievementTime.time().hour();
    int month = achievementTime.date().month();
    int year = achievementTime.date().year();
    ++_times[hour];
    ++_months[month - 1];
    auto iterator = std::find_if(_years.begin(),
                                 _years.end(),
                                 [=](const yearType &cYear) {
                                    return cYear.first.toInt() == year;
                                 });
    if (iterator != _years.end()) {
        ++(*iterator).second;
    } else {
        _years.append(yearType(QString::number(year), 1));
    }
}
