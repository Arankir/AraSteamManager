#include "gameswithpercentmodel.h"

using namespace gamesWithPercentModel;

const QString c_noAchievements = "-";

GamesWithPercentModel::GamesWithPercentModel(QObject *aParent): QAbstractTableModel(aParent) {

}

void GamesWithPercentModel::setGames(const SGames &aGames, const ProfileID &aProfileId) {
    clear();
    profileId_ = aProfileId;

    int progress = 0;
    for(const SGame &game: aGames) {
        GameWithPercentModelItem item(game,
                                      0.0,
                                      SAchievementsPlayer());
        modelItems_.append(item);
        emit s_progress(tr("Загрузка данных об игре"), ++progress, aGames.count());
    }
    for (const GameWithPercentModelItem &gameModel: modelItems_) { //Загрузка достижений игрока
        SAchievementsPlayer::load(gameModel.game.appId(), profileId_, std::bind(&GamesWithPercentModel::onResultAchievements, this,  std::placeholders::_1, gameModel.game.appId()));
    }
}

void GamesWithPercentModel::setGames(const QList<GameWithPercentModelItem> &aGames, const ProfileID &aProfileId) {
//    int progress = 0;
    beginResetModel();
    clear();
    profileId_ = aProfileId;
    for(const GameWithPercentModelItem &game: aGames) {
        modelItems_.append(game);
//        emit s_progress(tr("Загрузка данных об игре"), ++progress, aGames.count());
    }
    endResetModel();
    emit s_finished();
}

void GamesWithPercentModel::onResultAchievements(const SAchievementsPlayer &aAchievements, const GameID &aGameId) {
    auto iterator = std::find_if(modelItems_.begin(),
                                 modelItems_.end(),
                                 [=](const GameWithPercentModelItem &lGame) {
                                    return lGame.game.appId() == aGameId;
                                });
    if (iterator != modelItems_.end()) {
        (*iterator).achievements = aAchievements;
        (*iterator).percent = (1.0 * SAchievementPlayer::countAchieved(aAchievements)) / (aAchievements.count() / 100);
    } else {
        qWarning() << "gameWithPercent" << aGameId << "coudn't find";
    }

    static int loaded = 0;
    emit s_progress(tr("Загрузка достижений"), loaded, modelItems_.count());
    if(++loaded == modelItems_.count()) { //Проверка всё ли загрузилось
        loaded = 0;
        emit s_finished();
    }
}

void GamesWithPercentModel::clear() {
    modelItems_.clear();
    profileId_ = "";
}

int GamesWithPercentModel::columnCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return Count;
}

int GamesWithPercentModel::rowCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return modelItems_.count();
}

QVariant GamesWithPercentModel::data(const QModelIndex &aIndex, int aRole) const {
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
        case Title: {
            return modelItems_[aIndex.row()].game.name();
        }
        case Percent: {
            return QString{"%1"}.arg(modelItems_[aIndex.row()].percent, 5, 'f', 2) + "%";
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::DecorationRole: {
        switch (aIndex.column()) {
        case Icon: {
            return modelItems_[aIndex.row()].game.pixmapIcon();
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

QVariant GamesWithPercentModel::headerData(int aSection, Qt::Orientation aOrientation, int aRole) const {
    if (aRole != Qt::DisplayRole) {
        return QVariant();
    }

    if (aOrientation == Qt::Horizontal) {
        switch (aSection) {
        case Appid: {
            return tr("ID");
        }
        case Title: {
            return tr("Название");
        }
        case Percent: {
            return tr("Завершён на");
        }
        }
    } else {
        return QString("%1").arg(aSection);
    }
    return QVariant();
}

GameID GamesWithPercentModel::gameId(const QModelIndex &aIndex) const {
    return modelItems_[aIndex.row()].game.appId();
}

void GamesWithPercentModel::sort(int aColumn, Qt::SortOrder aOrder) {
    switch (aColumn) {
    case Appid: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
                        return g1.game.appId() < g2.game.appId();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
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
    case Icon: {
        break;
    }
    case Title: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
                        return g1.game.name() < g2.game.name();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
                        return g1.game.name() > g2.game.name();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Percent: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
                        return g1.percent < g2.percent;
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(modelItems_.begin(),
                      modelItems_.end(),
                      [](GameWithPercentModelItem &g1, GameWithPercentModelItem &g2) {
                        return g1.percent > g2.percent;
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

SGame GamesWithPercentModel::getGame(int aRow) const {
    return modelItems_[aRow].game;
}

SGame GamesWithPercentModel::getGame(const QModelIndex &aIndex) const {
    return modelItems_[aIndex.row()].game;
}

double GamesWithPercentModel::getPercent(int aRow) const {
    return modelItems_[aRow].percent;
}

SAchievementsPlayer GamesWithPercentModel::getAchievements(int aRow) const {
    return modelItems_[aRow].achievements;
}

GameWithPercentModelItem::GameWithPercentModelItem(const SGame &aGame, const double &aPercent, const SAchievementsPlayer &aAchievements) :
game(aGame), percent(aPercent), achievements(aAchievements) {

}
