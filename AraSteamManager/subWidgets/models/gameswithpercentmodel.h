#ifndef GAMESWITHPERCENTMODEL_H
#define GAMESWITHPERCENTMODEL_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include <QAbstractTableModel>

namespace gamesWithPercentModel {
    enum Columns {
        Appid    = 0,
        Index    = 1,
        Icon     = 2,
        Title    = 3,
        Percent  = 4,
        Count    = 5
    };
}

struct GameWithPercentModelItem {
    GameWithPercentModelItem(const SGame &game, const double &percent, const SAchievementsPlayer &achievements);
    SGame game;
    double percent;
    SAchievementsPlayer achievements;
};

class GamesWithPercentModel : public QAbstractTableModel {
    Q_OBJECT
public:
    GamesWithPercentModel(QObject *parent = nullptr);
    void setGames(const SGames &games, const ProfileID &profileId);
    void setGames(const QList<GameWithPercentModelItem> &games, const ProfileID &profileId);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    GameID gameId(const QModelIndex &index) const;

    SGame getGame(int row) const;
    SGame getGame(const QModelIndex &index) const;
    double getPercent(int row) const;
    SAchievementsPlayer getAchievements(int row) const;

    void clear();
public slots:
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, int progress, int max);

private slots:
    void onResultAchievements(const SAchievementsPlayer &achievements, const GameID &gameId);

private:
    ProfileID profileId_;
    QList<GameWithPercentModelItem> modelItems_;
};

#endif // GAMESWITHPERCENTMODEL_H
