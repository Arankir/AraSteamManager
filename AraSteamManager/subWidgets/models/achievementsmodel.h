#ifndef ACHIEVEMENTSMODEL_H
#define ACHIEVEMENTSMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/comments.h"
#include "classes/common/generalfunctions.h"
#include <QSortFilterProxyModel>
#include "classes/achievements/categoriesgame.h"

enum modelAchievementsColumns {
    AchievementAppid         = 0,
    AchievementIndex         = 1,
    AchievementIcon          = 2,
    AchievementTitle         = 3,
    AchievementDescription   = 4,
    AchievementComments      = 5,
    AchievementWorld         = 6,
    AchievementReachedMy     = 7,
    AchievementCount         = 7
};

class AchievementsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    AchievementsModel(QObject *parent = nullptr): QAbstractTableModel(parent) {};
    void setAchievements(const ProfileID &userId, const GameID &gameId);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QString achievementId(const QModelIndex &index) const;
    bool hasChildren(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertColumn(int column, int count, const QModelIndex &parent = QModelIndex());
    bool removeColumn(int column, int count, const QModelIndex &parent = QModelIndex());

    SAchievement getAchievement(const int &row) const;
    SAchievement getAchievement(const QModelIndex &index) const;
    SAchievements getAchievements() const;
    int getReachedFromProfile(const int &index = -1);
    int getAchievementsCount();

    int addProfile(const SProfile &profile);
    SProfile getProfile(const int &);
    void removeProfile(const SProfile &profile);
    void clearProfiles();

public slots:
    void updateComments();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, const int &progress, const int &max);

private:
    struct AchievementInModel {
        QPixmap icon;
        QStringList comment;
        SAchievementSchema schema;
        SAchievementPercentage percent;
        QList<SAchievementPlayer> profiles;

        friend QDebug operator<<(QDebug dbg, const AchievementInModel &a) {
            dbg.nospace() << "AchievementInModel" << "(" << a.schema.apiName() << a.percent.percent() << "profiles(";
            for (auto &profile: a.profiles) {
                dbg.nospace() << profile.apiName() << profile.achieved() << ",";
            }
            dbg.nospace() << "))\n";;
            return dbg.space();
        }
    };

    ProfileID _userId;
    GameID _gameId;

    SProfiles _profiles;
    QList<AchievementInModel> _achievementsInModel;
};

using CategoriesFilter = QList<QPair<QString, QList<Category>>>;

class ProxyModelAchievements : public QSortFilterProxyModel {
    Q_OBJECT
public:
    ProxyModelAchievements(QObject* parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    AchievementsModel *sourceModel() const;
    void setSourceModel(AchievementsModel *sourceModel);

public slots:
    void setName(const QString &newName);
    void setReached(int newReached);
    void setCategories(const CategoriesFilter &newCategories);
    CategoriesFilter getCategories() const {return _categories;}
    void setFavorites(const QStringList &newFavorites);
    void clear();

private:
    void setSourceModel(QAbstractItemModel *sourceModel) {Q_UNUSED(sourceModel);}

    QStringList _preCategories;

    QString _name;
    int _reached;
    CategoriesFilter _categories; //QList<QList<QList<QString>>> = (1&2&...)||(n&n2&...)||m||m2... QList<QList<QString>> = (1&2&...) QList<QString> = 1
    QStringList _favorite;
};

#endif // ACHIEVEMENTSMODEL_H
