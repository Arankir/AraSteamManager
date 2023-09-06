#ifndef ACHIEVEMENTSMODEL_H
#define ACHIEVEMENTSMODEL_H

#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/files/comments.h"
#include "classes/files/category.h"
#include "subWidgets/models/filters.h"

namespace achievementsModel {
    constexpr int c_reservedRows = 2;

    enum ReservedRows {
        Avatar = 0,
        Percent = 1
    };

    enum Columns {
        Appid       = 0,
        Index       = 1,
        Title       = 2,
        Description = 3,
        Comments    = 4,
        World       = 5,
        ReachedMy   = 6,
        Count       = 6
    };
}

class AchievementsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    AchievementsModel(QObject *parent = nullptr);
    void setAchievements(const ProfileID &profileId, const GameID &gameId);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    AchievementID achievementId(const QModelIndex &index) const;
    bool hasChildren(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertColumn(int column, int count, const QModelIndex &parent = QModelIndex());
    bool removeColumn(int column, int count, const QModelIndex &parent = QModelIndex());

    SAchievement getAchievement(int row) const;
    SAchievement getAchievement(const QModelIndex &index) const;
    SAchievements getAchievements() const;
    int getReachedFromProfile(int index = -1);
    int getAchievementsCount() const;

    int addProfile(const SProfile &profile);
    SProfile getProfile(int index);
    int getProfileNumber(const ProfileID &profileId);
    void removeProfile(const SProfile &profile);
    void clearProfiles();

public slots:
    void updateComments();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void s_finished();
    void s_progress(const QString &status, int progress, int max);

private:
    struct AchievementInModel {
        QIcon *icon = nullptr;
        QStringList comment;
        SAchievementSchema schema;
        SAchievementPercentage percent;
        QList<SAchievementPlayer> profiles;

        friend QDebug operator<<(QDebug dbg, const AchievementInModel &achievement) {
            QStringList profiles = std::accumulate(achievement.profiles.begin(),
                                               achievement.profiles.end(),
                                               QStringList(),
                                               [=](QStringList line, const SAchievementPlayer &lPlayer) {
                return std::move(line) << (lPlayer.apiName() + " " + QString::number(lPlayer.achieved()));
            });
            dbg.nospace() << "AchievementInModel" << "(" << achievement.schema.apiName() << " " << achievement.percent.percent() << " "
                          << "profiles(" << profiles.join(", ") << "))\n";;
            return dbg.space();
        }
    };

    ProfileID profileId_;
    GameID gameId_;

    QList<QPair<SProfile, int> > profiles_;
    QList<AchievementInModel> achievementsInModel_;
};

class CategoriesFilter {
public:
    CategoriesFilter();
    CategoriesFilter(const QMap<QString, QList<Category *>> &categories);
    bool addCategory(Category *category);
    bool removeCategory(Category *category);
    void clear();
    QMap<QString, QList<Category *>> getCategories() const;
    QSet<AchievementID> getAchievementIDs();

private:
    QMap<QString, QList<Category *>> categories_;
};

class FilterModelAchievements : public FilterModel {
    Q_OBJECT
public:
    FilterModelAchievements(QObject *parent = nullptr);
    FilterModelAchievements(int row, QObject *parent = nullptr);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    AchievementsModel *sourceModel() const;
    void setSourceModel(AchievementsModel *sourceModel);

//    SGame getGame(int index);
//    QStringList getGameComment(int index);
//    QList<SAchievementPlayer> getGameAchievements(int index);
    QMap<ProfileID, int> getProfiles();

    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
public slots:
    int addProfile(const SProfile &profile);
    SProfile getProfile(int index);
    void removeProfile(const SProfile &profile);

    void setName(const QString &newName);
    void setReached(int newReached);
    void setReachedFriend(int newReached, const ProfileID &profileId);
    void setCategories(const CategoriesFilter &newCategories);
    CategoriesFilter getCategories() const;
    void setFavorites(const QStringList &newFavorites);
    void clear() override;

    void addCategory(Category *aCategory);
    void removeCategory(Category *aCategory);
private slots:
    void updateCategoriesFilter();
private:
    void setSourceModel(QAbstractItemModel *sourceModel) override;

    QString name_;
    int reached_;
    QMap<ProfileID, int> profiles_;
    CategoriesFilter categories_;
    QStringList favorite_;
};

#endif // ACHIEVEMENTSMODEL_H
