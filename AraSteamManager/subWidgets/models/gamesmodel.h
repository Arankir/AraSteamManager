#ifndef GAMESMODEL_H
#define GAMESMODEL_H

#include <QSet>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "subWidgets/models/filters.h"

namespace gamesModel {
    enum Columns {
        Appid    = 0,
        Index    = 1,
        Icon     = 2,
        Name     = 3,
        Comment  = 4,
        Progress = 5,
        Count    = 6
    };
}

class GamesModel : public QAbstractTableModel {
    Q_OBJECT
public:
    GamesModel(QObject *parent = nullptr);
    void setGames(const SGames &games, const ProfileID &profileId);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    GameID gameId(const QModelIndex &index) const;

    SGame getGame(const int &row) const;
    SGame getGame(const QModelIndex &index) const;
    QStringList getComment(const int &row) const;
    QList<SAchievementPlayer> getAchievements(const int &row) const;

    void clear();
public slots:
    void updateComments();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, const int &progress, const int &max);

private slots:
    void onResultAchievements(const SAchievementsPlayer &achievements, const GameID &gameId);

private:
    struct gameModelItem {
        SGame game;
        QStringList comment;
        QList<SAchievementPlayer> achievements;
        int achieved;
    };

    ProfileID profileId_;
    QList<gameModelItem> modelItems_;
};

class FilterModelGames : public FilterModel {
    Q_OBJECT
public:
    FilterModelGames(int row = 0, QObject *parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    GamesModel *sourceModel() const;
    void setSourceModel(GamesModel *sourceModel);

    SGame getGame(const int &index);
    QStringList getGameComment(const int &index);
    QList<SAchievementPlayer> getGameAchievements(const int &index);

signals:
    void s_modelFinished();

public slots:
    void setName(const QString &newName);
    void setHide(const QSet<GameID> &newHide);
    void setGroup(const QSet<GameID> &newGroup);
    void setFavorites(const QSet<GameID> &newFavorites);
    void clearName();
    void clearHide();
    void clearGroup();
    void clearFavorites();
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel);

    QString name_;
    QSet<GameID> hide_;
    QSet<GameID> group_;
    QSet<GameID> favorite_;
};

#endif // GAMESMODEL_H
