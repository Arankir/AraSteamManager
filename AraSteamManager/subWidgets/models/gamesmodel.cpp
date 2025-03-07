#include "gamesmodel.h"
#include <QtConcurrent>
#include "classes/common/images.h"
#include "classes/files/comments.h"

using namespace gamesModel;

const QString c_noAchievements = "-";

GamesModel::GamesModel(QObject *aParent): QAbstractTableModel(aParent) {

}

void GamesModel::setGames(const SGames &aGames, const ProfileID &aProfileId) {
    clear();
    profileId_ = aProfileId;
    GameComments comments(profileId_);

    int progress = 0;
    QVector<QPair<const SGame *, QIcon *> > tasks;
    for (const SGame &game : aGames) {
        QStringList comment;
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=](const GameComment &gameComment) {
                                         return gameComment.gameId() == game.appId();
                                     });

        if (iterator != comments.end()) {
            comment = (*iterator).comment();
        }

        QIcon *icon = new QIcon();
        // QIcon *icon = new QIcon(game.pixmapIcon());
        // icon->addPixmap(game.pixmapIcon(), QIcon::Selected);

        tasks << QPair<const SGame *, QIcon *>(&game, icon);

        modelItems_.append(gameModelItem{icon, game, comment, SAchievementsPlayer(), 0});
        emit s_progress(tr("Загрузка данных об игре"), ++progress, aGames.count());
    }
    std::atomic<int> progress2 = 0;
    QFuture<void> future = QtConcurrent::map(
        tasks, [&aGames, &progress2, this](const QPair<const SGame *, QIcon *> &l_pair) {
            l_pair.second->addPixmap(l_pair.first->pixmapIcon());
            l_pair.second->addPixmap(l_pair.first->pixmapIcon(), QIcon::Selected);
            emit s_progress(tr("Загрузка иконок"), ++progress2, aGames.count());
        });
    future.waitForFinished();

    for (const gameModelItem &gameModel: modelItems_) { //Загрузка достижений игрока
        SAchievementsPlayer::load(gameModel.game.appId(),
                                  profileId_,
                                  std::bind(&GamesModel::onResultAchievements,
                                            this,
                                            std::placeholders::_1,
                                            gameModel.game.appId()));
    }
}

void GamesModel::onResultAchievements(const SAchievementsPlayer &aAchievements,
                                      const GameID &aGameId)
{
    auto iterator = std::find_if(modelItems_.begin(),
                                 modelItems_.end(),
                                 [=](const gameModelItem &lGame) {
                                     return lGame.game.appId() == aGameId;
                                 });
    if (iterator != modelItems_.end()) {
        (*iterator).achievements = aAchievements;
        (*iterator).achieved = SAchievementPlayer::countAchieved(aAchievements);
    } else {
        qWarning() << "game" << aGameId << "coudn't find";
    }

    static int loaded = 0;
    emit s_progress(tr("Загрузка достижений"), loaded, modelItems_.count());
    qDebug() << loaded << modelItems_.count();
    if(++loaded == modelItems_.count()) { //Проверка всё ли загрузилось
        qDebug() << loaded << modelItems_.count();
        loaded = 0;
        emit s_finished();
    }
}

void GamesModel::clear() {
    modelItems_.clear();
    profileId_ = "";
}

int GamesModel::columnCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return Count;
}

int GamesModel::rowCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return modelItems_.count();
}

QVariant GamesModel::data(const QModelIndex &aIndex, int aRole) const {
    if (!aIndex.isValid())
        return QVariant();

    if (aIndex.row() >= modelItems_.size())
        return QVariant();

    switch (aRole) {
    case Qt::DisplayRole: {
        switch (aIndex.column()) {
        case Appid: {
            return modelItems_[aIndex.row()].game.appId();
        }
        case Index: {
            return aIndex.row();
        }
        case Name: {
            return modelItems_[aIndex.row()].game.name();
        }
        case gamesModel::Comment: {
            if (!modelItems_[aIndex.row()].comment.isEmpty() &&
                modelItems_[aIndex.row()].comment != QStringList{""}) {
                if (modelItems_.count() > 1) {
                    return modelItems_[aIndex.row()].comment[0] + tr("\n...");
                } else {
                    return modelItems_[aIndex.row()].comment[0];
                }
            } else {
                return tr("-");
            }
        }
        case Progress: {
            gameModelItem game = modelItems_[aIndex.row()];
            if (game.achievements.count() == 0) {
                return c_noAchievements;
            } else {
                return QString("%1%\n(%2/%3)").arg(QString::number(1.0 * game.achieved / (1.0 * game.achievements.count() / 100), 'f', 2)).arg(
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
        switch (aIndex.column()) {
        case Name: {
            if (modelItems_[aIndex.row()].icon == nullptr) {
                return QIcon(Images::missingImage());
            }
            return *(modelItems_[aIndex.row()].icon);
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ForegroundRole: {
        switch (aIndex.column()) {
        case Progress: {
            if (modelItems_[aIndex.row()].achievements.count() == 0) {
                return QColor(255, 0, 0);
            } else {
                gameModelItem game = modelItems_[aIndex.row()];
                double x = 1.0 * game.achieved / game.achievements.count();
                return QColor(254 * (1.0 - x), 254 * x, 0);
            }
        }
        case gamesModel::Comment: {
            if (modelItems_[aIndex.row()].comment == QStringList() ||
                modelItems_[aIndex.row()].comment == QStringList() << "") {
                return QColor(55, 55, 150);
            }
            return QVariant();
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

QVariant GamesModel::headerData(int aSection, Qt::Orientation aOrientation, int aRole) const {
    if (aRole != Qt::DisplayRole) {
        return QVariant();
    }

    if (aOrientation == Qt::Horizontal) {
        switch (aSection) {
        case Appid: {
            return tr("ID");
        }
        case Name: {
            return tr("Название");
        }
        case Progress: {
            return tr("Прогресс");
        }
        }
    } else {
        return QString("%1").arg(aSection);
    }
    return QVariant();
}

GameID GamesModel::gameId(const QModelIndex &aIndex) const {
    return modelItems_[aIndex.row()].game.appId();
}

void GamesModel::sort(int aColumn, Qt::SortOrder aOrder) {
    switch (aColumn) {
    case Appid: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return g1.game.appId() < g2.game.appId();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return g1.game.appId() > g2.game.appId();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Index: {
        break;
    }
    case Name: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return g1.game.name() < g2.game.name();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return g1.game.name() > g2.game.name();
                      }
                    );
            break;
        }
        }
        break;
    }
    case gamesModel::Comment: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return (g1.comment != QStringList() ? 1 : 0) < (g2.comment != QStringList() ? 1 : 0);
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
                        return (g1.comment != QStringList() ? 1 : 0) > (g2.comment != QStringList() ? 1 : 0);
                      }
                    );
            break;
        }
        }
        break;
    }
    case Progress: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
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
                        return g1Num < g2Num;
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](gameModelItem &g1, gameModelItem &g2) {
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
                        return g1Num > g2Num;
                      }
                    );
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

SGame GamesModel::getGame(int aRow) const {
    return modelItems_[aRow].game;
}

SGame GamesModel::getGame(const QModelIndex &aIndex) const {
    return modelItems_[aIndex.row()].game;
}

QStringList GamesModel::getComment(int aRow) const {
    return modelItems_[aRow].comment;
}

QList<SAchievementPlayer> GamesModel::getAchievements(int aRow) const {
    return modelItems_[aRow].achievements;
}

void GamesModel::updateComments() {
    GameComments comments(profileId_);
    int progress = 0;
    for(gameModelItem &game: modelItems_) {
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
        emit s_progress(tr("Обновление комментариев"), ++progress, modelItems_.count());
    }
    emit s_finished();
}

FilterModelGames::FilterModelGames(QObject *aParent): FilterModelGames(0, aParent) {

}

FilterModelGames::FilterModelGames(int aRow, QObject *aParent): FilterModel(aRow, 4, aParent) {
    columns_.insert("name", 0);
    columns_.insert("hide", 1);
    columns_.insert("group", 2);
    columns_.insert("favorite", 3);
}

bool FilterModelGames::filterAcceptsRow(int aSourceRow, const QModelIndex &aSourceParent) const {
    Q_UNUSED(aSourceParent);
    return filter_[aSourceRow];
}

bool FilterModelGames::lessThan(const QModelIndex &aLeft, const QModelIndex &aRight) const {
    if (aLeft.column() == Progress && aRight.column() == Progress) {
        QVariant leftData = sourceModel()->data(aLeft);
        QVariant rightData = sourceModel()->data(aRight);
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
    return QSortFilterProxyModel::lessThan(aLeft, aRight);
}

void FilterModelGames::setSourceModel(GamesModel *aSourceModel) {
    connect(aSourceModel, &GamesModel::s_finished, this, [=, this]() {
        if (sourceModel() != nullptr) {
            filter_.setRows(sourceModel()->rowCount());
            forceInvalidate();
            emit s_modelFinished();
            emit s_rowsUpdated();
        } else {
            qWarning() << "in FilterModelGames missing sourceModel, but emit 'finished'";
        }
    });
    FilterModel::setSourceModel(aSourceModel);
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
    return static_cast<GamesModel*>(FilterModel::sourceModel());
}

void FilterModelGames::setName(const QString &aNewName) {
    if(name_ == aNewName)
        return;
    name_ = aNewName;
    int filterColumnName = columns_.value("name");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex nameIndex = sourceModel()->index(r, Name);
        filter_.setData(r, filterColumnName, sourceModel()->data(nameIndex).toString().toLower().indexOf(name_.toLower()) >= 0);
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::setHide(const QSet<GameID> &aNewHide) {
    if(hide_ == aNewHide)
        return;
    hide_ = aNewHide;
    int filterColumn = columns_.value("hide");
    if (hide_.isEmpty()) {
        filter_.clearCol(filterColumn);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex hideIndex = sourceModel()->index(r, Appid);
            filter_.setData(r, filterColumn, hide_.find(sourceModel()->data(hideIndex).toString().toInt()) == hide_.end());
        }
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::setGroup(const QSet<GameID> &aNewGroup) {
    if(group_ == aNewGroup)
        return;
    group_ = aNewGroup;
    int filterColumn = columns_.value("group");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex hideIndex = sourceModel()->index(r, Appid);
        filter_.setData(r, filterColumn, group_.find(sourceModel()->data(hideIndex).toString().toInt()) != group_.end());
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::setFavorites(const QSet<GameID> &aNewFavorites) {
    if(favorite_ == aNewFavorites)
        return;
    favorite_ = aNewFavorites;
    int filterColumn = columns_.value("favorite");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex hideIndex = sourceModel()->index(r, Appid);
        filter_.setData(r, filterColumn, favorite_.find(sourceModel()->data(hideIndex).toString().toInt()) != favorite_.end());
    }
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::clearName() {
    name_.clear();
    int nameColumn = columns_.value("name");
    filter_.clearCol(nameColumn);
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::clearHide() {
    hide_.clear();
    int hideColumn = columns_.value("hide");
    filter_.clearCol(hideColumn);
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::clearGroup() {
    group_.clear();
    int groupColumn = columns_.value("group");
    filter_.clearCol(groupColumn);
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::clearFavorites() {
    favorite_.clear();
    int filterColumn = columns_.value("favorite");
    filter_.clearCol(filterColumn);
    invalidateFilter();
    emit s_rowsUpdated();
}

void FilterModelGames::clear() {
    name_.clear();
    hide_.clear();
    group_.clear();
    favorite_.clear();
    FilterModel::clear();
    sourceModel()->clear();
}

void FilterModelGames::setSourceModel(QAbstractItemModel *aSourceModel) {
    if (auto model = dynamic_cast<GamesModel*>(aSourceModel)) {
        setSourceModel(model);
    }
}
