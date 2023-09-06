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
        Name     = 2,
        Comment  = 3,
        Progress = 4,
        Count    = 5
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

    SGame getGame(int row) const;
    SGame getGame(const QModelIndex &index) const;
    QStringList getComment(int row) const;
    QList<SAchievementPlayer> getAchievements(int row) const;

    void clear();
public slots:
    void updateComments();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, int progress, int max);

private slots:
    void onResultAchievements(const SAchievementsPlayer &achievements, const GameID &gameId);

private:
    struct gameModelItem {
        QIcon *icon = nullptr;
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
    FilterModelGames(QObject *parent = nullptr);
    FilterModelGames(int row, QObject *parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
    GamesModel *sourceModel() const;
    void setSourceModel(GamesModel *sourceModel);

    SGame getGame(int index);
    QStringList getGameComment(int index);
    QList<SAchievementPlayer> getGameAchievements(int index);

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
    void clear() override;

private:
    void setSourceModel(QAbstractItemModel *sourceModel) override;

    QString name_;
    QSet<GameID> hide_;
    QSet<GameID> group_;
    QSet<GameID> favorite_;
};

#endif // GAMESMODEL_H
