#include "gamesmodel.h"
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

void GamesModel::setGames(QList<SGame> &games, const QString &userId) {
    _userId = userId;
    _gamesInModel.clear();
    auto comments = GameComment::load(_userId);
    int progress = 0;

    for(auto &game: games) {
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=](const GameComment &gameComment) {
                                        return gameComment.gameId() == game.sAppId();
                                     });

        if (iterator != comments.end()) {
            _gamesInModel.append(std::move(GameInModel{game.pixmapIcon(), game, (*iterator).comment(), QList<SAchievementPlayer>(), 0}));
        } else {
            _gamesInModel.append(std::move(GameInModel{game.pixmapIcon(), game, QStringList(), QList<SAchievementPlayer>(), 0}));
        }
        emit s_progress(1, ++progress);
    }
    for (const auto &game: qAsConst(games)) {
        //Загрузка достижений игрока
        SAchievementPlayer::load(game.sAppId(), _userId, std::bind(&GamesModel::onResultAchievements, this,  std::placeholders::_1, game.sAppId()));
    }
}

void GamesModel::onResultAchievements(QList<SAchievementPlayer> aAchievements, QString aAppId) {
    auto iterator = std::find_if(_gamesInModel.begin(),
                                 _gamesInModel.end(),
                                 [=](const GameInModel &gim) {
                                    return gim.game.sAppId() == aAppId;
                                });
    if (iterator != _gamesInModel.end()) {
        (*iterator).achievements = aAchievements;
        (*iterator).achieved = SAchievementPlayer::countAchieved(aAchievements);
    } else {
        qWarning() << "game" << aAppId << "coudn't find";
    }

    static int loaded = 0;
    emit s_progress(2, loaded);
    //Проверка всё ли загрузилось
    if(++loaded == _gamesInModel.count()) {
        loaded = 0;
        emit s_finished();
    }
}

int GamesModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return GamesCount;
}

int GamesModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _gamesInModel.count();
}

QVariant GamesModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _gamesInModel.size())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole: {
        switch (index.column()) {
        case GamesAppid: {
            return _gamesInModel[index.row()].game.sAppId();
        }
        case GamesIndex: {
            return index.row();
        }
        case GamesName: {
            return _gamesInModel[index.row()].game.name();
        }
//        case GamesComment: {
//            if (_gamesInModel[index.row()].comment != QStringList() &&
//                _gamesInModel[index.row()].comment != QStringList() << "") {
//                return 1;
//            } else {
//                return 0;
//            }
//        }
        case GamesProgress: {
            auto game = _gamesInModel[index.row()];
            if (game.achievements.count() == 0) {
                return tr("Нет достижений");
            } else {
                return QString{"%1"}.arg(100.0 * game.achieved / game.achievements.count(), 5, 'f', 1, '0') + "%";
            }
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::DecorationRole: {
        switch (index.column()) {
        case GamesIcon: {
            return _gamesInModel[index.row()].icon;
        }
        case GamesComment: {
            if (_gamesInModel[index.row()].comment != QStringList() &&
                _gamesInModel[index.row()].comment != QStringList() << "") {
                return QPixmap(Images::isComment()).scaled(32, 32);
            } else {
                return QPixmap(Images::isNotComment()).scaled(32, 32);
            }
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ForegroundRole: {
        switch (index.column()) {
        case GamesProgress: {
            if (_gamesInModel[index.row()].achievements.count() == 0) {
                return QColor(255, 0, 0);
            } else {
                auto game = _gamesInModel[index.row()];
                double x = 1.0 * game.achieved / game.achievements.count();
                return QColor(254 * (1.0 - x), 254 * x, 0);
            }
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    default: {
        return QVariant();
    }
    }
}

QVariant GamesModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section) {
        case GamesAppid: {
            return tr("ID");
        }
        case GamesName: {
            return tr("Название");
        }
        case GamesProgress: {
            return tr("Прогресс");
        }
        }
    else
        return QString("%1").arg(section);
    return QVariant();
}

QString GamesModel::gameId(const QModelIndex &index) const {
    return _gamesInModel[index.row()].game.sAppId();
}

void GamesModel::sort(int column, Qt::SortOrder order) {
    switch (column) {
    case GamesAppid: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return g1.game.appId() < g2.game.appId();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return g1.game.appId() > g2.game.appId();});
            break;
        }
        }
        break;
    }
    case GamesIndex: {
        break;
    }
    case GamesIcon: {
        break;
    }
    case GamesName: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return g1.game.name() < g2.game.name();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return g1.game.name() > g2.game.name();});
            break;
        }
        }
        break;
    }
    case GamesComment: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return (g1.comment != QStringList() ? 1 : 0) < (g2.comment != QStringList() ? 1 : 0);});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {return (g1.comment != QStringList() ? 1 : 0) > (g2.comment != QStringList() ? 1 : 0);});
            break;
        }
        }
        break;
    }
    case GamesProgress: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {
                double g1Num, g2Num;
                if (g1.achievements.count() == 0) {
                    g1Num = -1.0;
                } else {
                    g1Num = 100.0 * g1.achieved / g1.achievements.count();
                }
                if (g2.achievements.count() == 0) {
                    g2Num = -1.0;
                } else {
                    g2Num = 100.0 * g2.achieved / g2.achievements.count();
                }
                qDebug() << 2 << g1Num << g2Num;
                return g1Num < g2Num;
            });
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<GameInModel>(_gamesInModel, [](GameInModel &g1, GameInModel &g2) {
                double g1Num, g2Num;
                if (g1.achievements.count() == 0) {
                    g1Num = -1.0;
                } else {
                    g1Num = 100.0 * g1.achieved / g1.achievements.count();
                }
                if (g2.achievements.count() == 0) {
                    g2Num = -1.0;
                } else {
                    g2Num = 100.0 * g2.achieved / g2.achievements.count();
                }
                qDebug() << 1 << g1Num << g2Num;
                return g1Num > g2Num;
            });
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

SGame GamesModel::getGame(const int &row) const {
    return _gamesInModel[row].game;
}

SGame GamesModel::getGame(const QModelIndex &index) const {
    return _gamesInModel[index.row()].game;
}

QStringList GamesModel::getComment(const int &row) const {
    return _gamesInModel[row].comment;
}

QList<SAchievementPlayer> GamesModel::getAchievements(const int &row) const {
    return _gamesInModel[row].achievements;
}

void GamesModel::updateComments() {
    auto comments = GameComment::load(_userId);
    int progress = 0;
    for(auto &game: _gamesInModel) {
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=](const GameComment &gameComment) {
                                        return gameComment.gameId() == game.game.sAppId();
                                     });

        if (iterator != comments.end()) {
            game.comment = (*iterator).comment();
        } else {
            game.comment = QStringList();
        }
        emit s_progress(1, ++progress);
    }
}
