#include "threadstatistics.h"

int ThreadStatistics::fill() {
    for (auto &game: _games) {
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(game._appID), _id);
        connect(pl, SIGNAL(s_finished(SAchievementsPlayer*)), this, SLOT(onResultAchievements(SAchievementsPlayer*)));
    }
    return 1;
}

void ThreadStatistics::onResultAchievements(SAchievementsPlayer *aAchievements) {
    disconnect(aAchievements, SIGNAL(s_finished(SAchievementsPlayer*)), this, SLOT(onResultAchievements(SAchievementsPlayer*)));
    emit s_progress(_nownum, 0);
    if (aAchievements->getCount() > 0) {
        static int gamesCount = 0;
        gamesCount++;
        int countReached = 0;
        int countNotReached = 0;
        _summcolumn += aAchievements->getCount();
        for (auto &achievement: *aAchievements) {
            if (achievement._achieved == 1) {
                QDateTime dateTime = achievement._unlockTime;
                QString yearTitle = QString::number(dateTime.date().year());
                _times[dateTime.time().hour()]++;
                _months[dateTime.date().month() - 1]++;
                int pos = -1;
                for (int i = 0; i < _years.size(); i++) {
                    if(_years[i].first.toInt() == dateTime.date().year()) {
                        pos = i;
                        break;
                    }
                }
                if (pos > -1) {
                    _years[pos].second++;
                } else {
                    _years.append(QPair<QString, int>(QString::number(dateTime.date().year()), 1));
                    for (int i = _years.size() - 1; i > 0; i--) {
                        if(_years[i].first < _years[i - 1].first) {
                            std::swap(_years[i], _years[i - 1]);
                        }
                    }
                    _years.resize(_years.size());
                }
                countReached++;
            } else {
                countNotReached++;
            }
        }
        _averagePercent.append(std::move(1.0 * (countReached * 100) / (countReached + countNotReached)));
        if (countNotReached == 0) {
            _numof[2]++;
            _complete.append(QPair<QString, QString>(aAchievements->getAppid(), aAchievements->getGameName()));
        } else if (countReached == 0) {
            _numof[0]++;
            _started.append(QPair<QString, QString>(aAchievements->getAppid(), aAchievements->getGameName()));
        } else {
            _numof[1]++;
            _notStarted.append(QPair<QString, QString>(aAchievements->getAppid(), aAchievements->getGameName()));
        }
    }
    _nownum++;
    if (_nownum == _games.getCount()) {
        emit s_finished();
        this->deleteLater();
    }
}
