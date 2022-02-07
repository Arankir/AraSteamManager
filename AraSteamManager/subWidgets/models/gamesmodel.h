#ifndef GAMESMODEL_H
#define GAMESMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "classes/steamApi/structures/sgames.h"
#include "classes/common/comments.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/generalfunctions.h"
#include <QSortFilterProxyModel>

enum modelGamesColumns {
    GamesAppid    = 0,
    GamesIndex    = 1,
    GamesIcon     = 2,
    GamesName     = 3,
    GamesComment  = 4,
    GamesProgress = 5,
    GamesCount    = 6
};

class GamesModel : public QAbstractTableModel {
    Q_OBJECT
public:
    GamesModel(QObject *parent = nullptr): QAbstractTableModel(parent) {};
    void setGames(const SGames &games, const QString &userId);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    GameID gameId(const QModelIndex &index) const;

    SGame getGame(const int &row) const;
    SGame getGame(const QModelIndex &index) const;
    QStringList getComment(const int &row) const;
    QList<SAchievementPlayer> getAchievements(const int &row) const;

public slots:
    void updateComments();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, const int &progress, const int &max);

protected:
    void loadImages(const SGames &lGames, QList<GameComment> &comments, int gameCount);
private slots:
    void onResultAchievements(QList<SAchievementPlayer> achievements, GameID appId);

private:
    struct GameInModel {
        SGame game;
        QStringList comment;
        QList<SAchievementPlayer> achievements;
        int achieved;
    };

    QString _userId;
    QList<GameInModel> _gamesInModel;

    int _loadedGames = 0;
};

class ProxyModelGames : public QSortFilterProxyModel {
    Q_OBJECT
public:
    ProxyModelGames(QObject* parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    GamesModel *sourceModel() const;
    void setSourceModel(GamesModel *sourceModel);

    SGame getGame(int aIndex);
    QStringList getGameComment(int aIndex);
    QList<SAchievementPlayer> getGameAchievements(int aIndex);

public slots:
    void setName(const QString &newName);
    void setHide(const QStringList &newHide);
    void setGroup(const QStringList &newGroup);
    void setFavorites(const QStringList &newFavorites);
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel) {Q_UNUSED(sourceModel)};

    QString _name;
    QStringList _hide;
    QStringList _group;
    QStringList _favorite;
};
#include "subWidgets/models/filters.h"
class FilterModelGames : public FilterModel {
    Q_OBJECT
public:
    FilterModelGames(int row = 0, QObject* parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    GamesModel *sourceModel() const;
    void setSourceModel(GamesModel *sourceModel);

    SGame getGame(int aIndex);
    QStringList getGameComment(int aIndex);
    QList<SAchievementPlayer> getGameAchievements(int aIndex);

public slots:
    void setName(const QString &newName);
    void setHide(const QStringList &newHide);
    void setGroup(const QStringList &newGroup);
    void setFavorites(const QStringList &newFavorites);
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel) {Q_UNUSED(sourceModel)};

    QString _name;
    QStringList _hide;
    QStringList _group;
    QStringList _favorite;
};

#endif // GAMESMODEL_H
