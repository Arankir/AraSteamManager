#include "threadstatistics.h"

int ThreadStatistics::fill() {
    for (auto &game: _games) {
        SAchievementsPlayer *pl = new SAchievementsPlayer(game.sAppId(), _id);
        connect(pl, SIGNAL(s_finished(SAchievementsPlayer*)), this, SLOT(onResultAchievements(SAchievementsPlayer*)));
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(SAchievementsPlayer *aAchievements) {
    disconnect(aAchievements, SIGNAL(s_finished(SAchievementsPlayer*)), this, SLOT(onResultAchievements(SAchievementsPlayer*)));
    static int nowProcessed = 0;
    emit s_progress(nowProcessed, 0);
    if (aAchievements->count() > 0) {
        ++_colgames;
        int countReached = 0;
        int countNotReached = 0;

        for (auto &achievement: *aAchievements) {
            if (achievement.achieved() == 1) {
                updateTimes(achievement.unlockTime());
                ++countReached;
            } else {
                ++countNotReached;
            }
        }

        _summcolumn += aAchievements->count();
        (*_averagePercent).append(std::move(1.0 * (countReached * 100) / (countReached + countNotReached)));

        QPair<QString, QString> dataNow(aAchievements->appid(), aAchievements->gameName());
        if (countNotReached == 0) {
            ++(*_numof)[2];
            (*_complete).append(std::move(dataNow));
        } else if (countReached == 0) {
            ++(*_numof)[0];
            (*_started).append(std::move(dataNow));
        } else {
            ++(*_numof)[1];
            (*_notStarted).append(std::move(dataNow));
        }
    }
    if (++nowProcessed == _games.count()) {
        emit s_finished();
        this->deleteLater();
    }
}

void ThreadStatistics::updateTimes(const QDateTime &achievementTime) {
    ++(*_times)[achievementTime.time().hour()];
    ++(*_months)[achievementTime.date().month() - 1];
    auto iterator = std::find_if((*_years).begin(), (*_years).end(), [=](const QPair<QString, int> &year) {
                                                                        return year.first.toInt() == achievementTime.date().year();
                                                                    });
    if (iterator != (*_years).end()) {
        ++(*iterator).second;
    } else {
        (*_years).append(QPair<QString, int>(QString::number(achievementTime.date().year()), 1));
        std::sort((*_years).begin(), (*_years).end(), [](const QPair<QString, int> &p1, const QPair<QString, int> &p2){
                                                            return p1.first < p2.first;
                                                        });
    }
}
