#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include <QWidgetAction>

#include "form.h"
#include "classes/files/favorites.h"
#include "subWidgets/models/achievementsmodel.h"
#include "subWidgets/models/categoriesmodel.h"
#include "subWidgets/withData/buttonreachedtype.h"
#include "subWidgets/items/friendlistitem.h"

namespace FormAchievementsData {
    enum tabs {
        TabStandart     = 0,
        TabCategories   = 1
    };
}

namespace Ui {
    class FormAchievements;
}

class FormAchievements: public Form {
    Q_OBJECT
public slots:
    void update();
    void openManual();
    bool isDataSetted();
    void setAllFriendsValue(const ReachedType &type);
    void addFriendToList(const SProfile &profile, FriendListItemData::ProfileType type);
    void addProfileToTable(const QModelIndex &index);
public:
    explicit FormAchievements(QWidget *parent = nullptr);
    ~FormAchievements();
    void setData(const SProfile &profile, const SGame &game);

    QString getProfileId() const;
    int getGameAppId() const;
    int getAchievementsCount();

signals:
    void s_filtersUpdated(QAbstractItemModel *model);
    void s_filtersValueUpdated();
    void s_progress(const QString &status = "", int progress = 0, int max = 0);
    void s_finishedAchievements();
    void s_finishedFriends();

protected slots:
    void createCategory(const QModelIndex &categoryIndex);
    void createSubCategory(const QModelIndex &categoryIndex);

    void onAchievementsLoaded();
    void findFriend();
    void checkBoxFriendsOnlyWithGame_Clicked(bool isChecked);
private slots:
    void closeEvent(QCloseEvent*) override;
    void retranslate() override;
    void updateIcons() override;

    //init
    void init();

    //system
    void updateCategories();

    void checkBoxFavorites_StateChanged(int arg1);

    void initEditCategory();
    void onLoadedFriendGames(const SGames &games, const ProfileID &profileId);

    void buttonComment_Clicked();
    QMenu *createMenuAchievements(const SAchievement &achievement);
    QMenu *createMenuCategory(const QModelIndex &category);
    QMenu *createMenuAchievementsHeader();
    QMenu *createMenuFrozenTable(const QModelIndex &index);
    void updateFilterWithMyProfile(const ReachedType &type);
    void updateFilterTextAchievement(const QString &newText);
    void updateFilterCategory(Category *aCategory, bool isChecked);
    void updateFilterFavorite(const QList<FavoriteAchievement> &favoritesAchievements);
    void updateFilterFriend(const ProfileID &profileId, const ReachedType &type);
    void loading(bool isLoading);
    SAchievement currentAchievement();
    void onUpdateFilters();
    void updateAchievements();
    void loadFriends();
    int addFriendColumn(const SProfile &profile, const FriendListItemData::ProfileType &);
    bool removeFriendColumn(const SProfile &profile);
    void initTreeCategories();
    void initAchievementsTable();
    void initFriends();
    QWidgetAction *createCheckBoxHeaderAction(QMenu *menu, const QString &text, const achievementsModel::Columns &column);
    void buttonAddProfile_Clicked();

private:
    Ui::FormAchievements *ui;

    //ключевые данные
    SProfile profile_;
    SGame game_;

//    AchievementsModel *achievementsModel_ = nullptr;
//    FilterModelAchievements filterAchievements_;

    CategoriesModel *categoriesModel_ = nullptr;

    //сравнение с друзьями
    QList<SProfile> friendsProfiles_;
    QList<QPair<SProfile, FriendListItemData::ProfileType>> profilesInTable_;

    bool loadedCategories_ = false;
    bool loadedAchievements_ = false;
    bool loadedFriends_ = false;

};

#endif // FORMACHIEVEMENTS_H
