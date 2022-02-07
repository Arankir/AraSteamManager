#include "gamesmodel.h"
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

const QString c_noAchievements = "-";

void GamesModel::loadImages(const SGames &aGames, QList<GameComment> &aComments, int aGameCount) {
    for(auto &game: aGames) {
        auto iterator = std::find_if(aComments.begin(),
                                     aComments.end(),
                                     [=](const GameComment &gameComment) {
                                        return gameComment.gameId() == game.appId();
                                     });

        if (iterator != aComments.end()) {
            _gamesInModel.append(GameInModel{game, (*iterator).comment(), QList<SAchievementPlayer>(), 0});
        } else {
            _gamesInModel.append(GameInModel{game, QStringList(), QList<SAchievementPlayer>(), 0});
        }
        emit s_progress(tr("Загрузка данных об игре"), ++_loadedGames, aGameCount);
//        qDebug() << 11 << _loadedGames << gameCount;
    }
}

void GamesModel::setGames(const SGames &games, const QString &userId) {
    _userId = userId;
    _gamesInModel.clear();
    auto comments = GameComment::load(_userId);
    _loadedGames = 0;

//    int step = games.count() / QThread::idealThreadCount();
//    int y = 0;

//    QVector<QList<SGame>> tasks;
//    for( ; y < games.count() - step; y += step ) {
////        qDebug() << y << y + step;
//        tasks << games.mid(y, y + step);
//    }
//    QFuture<void> future = QtConcurrent::map(tasks, std::bind(&GamesModel::loadImages, this,  std::placeholders::_1, comments, games.count()));
//    loadImages(games.mid(y), comments, games.count());
//    future.waitForFinished();


    int progress = 0;
    for(auto &game: games) {
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=](const GameComment &gameComment) {
                                        return gameComment.gameId() == game.appId();
                                     });

        if (iterator != comments.end()) {
            _gamesInModel.append(GameInModel{game, (*iterator).comment(), QList<SAchievementPlayer>(), 0});
        } else {
            _gamesInModel.append(GameInModel{game, QStringList(), QList<SAchievementPlayer>(), 0});
        }
        emit s_progress(tr("Загрузка данных об игре"), ++progress, games.count());
        qDebug() << 33 << progress << games.count();
    }
    for (const auto &game: qAsConst(_gamesInModel)) {
        //Загрузка достижений игрока
        SAchievementPlayer::load(game.game.appId(), _userId, std::bind(&GamesModel::onResultAchievements, this,  std::placeholders::_1, game.game.appId()));
    }
}

void GamesModel::onResultAchievements(QList<SAchievementPlayer> aAchievements, GameID aAppId) {
    auto iterator = std::find_if(_gamesInModel.begin(),
                                 _gamesInModel.end(),
                                 [=](const GameInModel &gim) {
                                    return gim.game.appId() == aAppId;
                                });
    if (iterator != _gamesInModel.end()) {
        (*iterator).achievements = aAchievements;
        (*iterator).achieved = SAchievementPlayer::countAchieved(aAchievements);
    } else {
        qWarning() << "game" << aAppId << "coudn't find";
    }

    static int loaded = 0;
    emit s_progress(tr("Загрузка достижений"), loaded, _gamesInModel.count());
//    qDebug() << 22 << loaded << _gamesInModel.count();
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
            return _gamesInModel[index.row()].game.appId();
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
                return c_noAchievements;
            } else {
                return QString("%1%\n(%2/%3)").arg(QString::number(1.0 * game.achieved / (1.0 * game.achievements.count() / 100)/*, 6*/, 'f', 2/*, '0'*/)).arg(
                                                 QString::number(game.achieved),
                                                 QString::number(game.achievements.count()));
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
            return _gamesInModel[index.row()].game.pixmapIcon();
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

GameID GamesModel::gameId(const QModelIndex &index) const {
    return _gamesInModel[index.row()].game.appId();
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
                                        return gameComment.gameId() == game.game.appId();
                                     });

        if (iterator != comments.end()) {
            game.comment = (*iterator).comment();
        } else {
            game.comment = QStringList();
        }
        emit s_progress(tr("Обновление комментариев"), ++progress, _gamesInModel.count());
    }
}

ProxyModelGames::ProxyModelGames(QObject *aParent): QSortFilterProxyModel(aParent),
    _name(""), _hide(), _group(), _favorite() {

}

bool ProxyModelGames::filterAcceptsRow(int aSource_row, const QModelIndex &aSource_parent) const {
    QModelIndex indName = sourceModel()->index(aSource_row, GamesName, aSource_parent);
    QModelIndex indId = sourceModel()->index(aSource_row, GamesAppid, aSource_parent);
    if(sourceModel()->data(indName).toString().toLower().indexOf(_name.toLower()) == -1 ||
       (_hide.isEmpty() ? false : _hide.indexOf(sourceModel()->data(indId).toString()) > -1) ||
       (_group.isEmpty() ? false : _group.indexOf(sourceModel()->data(indId).toString()) == -1) ||
       (_favorite.isEmpty() ? false : _favorite.indexOf(sourceModel()->data(indId).toString()) == -1))
        return false;
    return true;
}

bool ProxyModelGames::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    if (left.column() == GamesProgress && right.column() == GamesProgress) {
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);
        if (leftData == c_noAchievements) {
            return true;
        }
        if (rightData == c_noAchievements) {
            return false;
        }
        double iLeft = leftData.toString().left(leftData.toString().indexOf("%")).toDouble();
        double iRight = rightData.toString().left(rightData.toString().indexOf("%")).toDouble();
        return iLeft < iRight;
    }
    return QSortFilterProxyModel::lessThan(left, right);
}

QVariant ProxyModelGames::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

void ProxyModelGames::setSourceModel(GamesModel *sourceModel) {
    QAbstractProxyModel::setSourceModel(sourceModel);
}

SGame ProxyModelGames::getGame(int aIndex) {
    return sourceModel()->getGame(aIndex);
}

QStringList ProxyModelGames::getGameComment(int aIndex) {
    return sourceModel()->getComment(aIndex);
}

QList<SAchievementPlayer> ProxyModelGames::getGameAchievements(int aIndex) {
    return sourceModel()->getAchievements(aIndex);
}

GamesModel *ProxyModelGames::sourceModel() const {
    return static_cast<GamesModel*>(QAbstractProxyModel::sourceModel());
}

void ProxyModelGames::setName(const QString &aNewName) {
    if(_name != aNewName)
        _name = aNewName;
    invalidateFilter();
}

void ProxyModelGames::setHide(const QStringList &aNewHide) {
    if(_hide != aNewHide)
        _hide = aNewHide;
    invalidateFilter();
}

void ProxyModelGames::setGroup(const QStringList &aNewGroup) {
    if(_group != aNewGroup)
        _group = aNewGroup;
    invalidateFilter();
}

void ProxyModelGames::setFavorites(const QStringList &aNewFavorites) {
    if(_favorite != aNewFavorites)
        _favorite = aNewFavorites;
    invalidateFilter();
}

void ProxyModelGames::clear() {
    _name.clear();
    _hide.clear();
    _group.clear();
    _favorite.clear();
}

FilterModelGames::FilterModelGames(int aRow, QObject *parent): FilterModel(aRow, 4, parent) {
    columns_.insert("name", 0);
    columns_.insert("hide", 1);
    columns_.insert("group", 2);
    columns_.insert("favorite", 3);
}

bool FilterModelGames::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    Q_UNUSED(source_parent);
    return filter_[source_row];
}

bool FilterModelGames::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    if (left.column() == GamesProgress && right.column() == GamesProgress) {
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);
        if (leftData == c_noAchievements) {
            return true;
        }
        if (rightData == c_noAchievements) {
            return false;
        }
        double iLeft = leftData.toString().left(leftData.toString().indexOf("%")).toDouble();
        double iRight = rightData.toString().left(rightData.toString().indexOf("%")).toDouble();
        return iLeft < iRight;
    }
    return QSortFilterProxyModel::lessThan(left, right);
}

QVariant FilterModelGames::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

void FilterModelGames::setSourceModel(GamesModel *sourceModel) {
    QAbstractProxyModel::setSourceModel(sourceModel);
    filter_.setRows(sourceModel->rowCount());
}

SGame FilterModelGames::getGame(int aIndex) {
    return sourceModel()->getGame(aIndex);
}

QStringList FilterModelGames::getGameComment(int aIndex) {
    return sourceModel()->getComment(aIndex);
}

QList<SAchievementPlayer> FilterModelGames::getGameAchievements(int aIndex) {
    return sourceModel()->getAchievements(aIndex);
}

GamesModel *FilterModelGames::sourceModel() const {
    return static_cast<GamesModel*>(QAbstractProxyModel::sourceModel());
}

void FilterModelGames::setName(const QString &aNewName) {
    if(_name == aNewName)
        return;
    _name = aNewName;
    int filterColumnName = columns_.value("name");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex nameIndex = sourceModel()->index(r, GamesName);
        filter_.setData(r, filterColumnName, sourceModel()->data(nameIndex).toString().toLower().indexOf(_name.toLower()) >= 0);
    }
    invalidateFilter();
}

void FilterModelGames::setHide(const QStringList &aNewHide) {
    if(_hide == aNewHide)
        return;
    _hide = aNewHide;
    int filterColumn = columns_.value("hide");
    if (_hide.isEmpty()) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex hideIndex = sourceModel()->index(r, GamesAppid);
            filter_.setData(r, filterColumn, _hide.indexOf(sourceModel()->data(hideIndex).toString()) >= 0);
        }
    }
    invalidateFilter();
}

void FilterModelGames::setGroup(const QStringList &aNewGroup) {
    if(_group == aNewGroup)
        return;
    _group = aNewGroup;
    int filterColumn = columns_.value("group");
    if (_group.isEmpty()) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex hideIndex = sourceModel()->index(r, GamesAppid);
            filter_.setData(r, filterColumn, _group.indexOf(sourceModel()->data(hideIndex).toString()) >= 0);
        }
    }
    invalidateFilter();
}

void FilterModelGames::setFavorites(const QStringList &aNewFavorites) {
    if(_favorite == aNewFavorites)
        return;
    _favorite = aNewFavorites;
    int filterColumn = columns_.value("favorite");
    if (_favorite.isEmpty()) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex hideIndex = sourceModel()->index(r, GamesAppid);
            filter_.setData(r, filterColumn, _favorite.indexOf(sourceModel()->data(hideIndex).toString()) >= 0);
        }
    }
    invalidateFilter();
}

void FilterModelGames::clear() {
    _name.clear();
    _hide.clear();
    _group.clear();
    _favorite.clear();
    filter_.clear();
}
