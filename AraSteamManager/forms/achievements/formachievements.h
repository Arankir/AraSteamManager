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
//    void updateSettings(QFlags<changedSettings> aSettings) override;
    void update();
    void openManual();
    bool isDataSetted() {return achievementsModel_->getAchievementsCount() > 0 && profile_.personaName() != "" && game_.appId() > 0;}
    void setAllFriendsValue(const ReachedType &aType);
    void addFriendToList(const SProfile &aSteamFriend, FriendListItemData::ProfileType type);
    void addProfileToTable(const QModelIndex &index);
public:
    explicit FormAchievements(QWidget *parent = nullptr);
    ~FormAchievements();
    void setData(const SProfile &profile, const SGame &game);

    QString getProfileId() const {return profile_.steamId();}
    int getGameAppId() const {return game_.appId();}
    int getAchievementsCount();

signals:
    void s_filtersUpdated(QAbstractItemModel *model);
    void s_filtersValueUpdated();
    void s_progress(const QString &status = "", const int &progress = 0, const int &max = 0);
    void s_finishedAchievements();
    void s_finishedFriends();

protected slots:
    void createCategory(const QModelIndex &aCategory);
    void createSubCategory(const QModelIndex &aCategory);

    void onAchievementsLoaded();
    void findFriend();
    void checkBoxFriendsOnlyWithGame_Clicked(bool aChecked);
private slots:
    void closeEvent(QCloseEvent*) override;
    void retranslate() override;
    void updateIcons() override;

    //init
    void init();

    //system
    void updateCategories();

    void checkBoxFavorites_StateChanged(const int &arg1);

    void initEditCategory();
    void onLoadedFriendGames(const SGames &games, const ProfileID &profileId);

    void buttonComment_Clicked();
    QMenu *createMenuAchievements(const SAchievement &aAchievement);
    QMenu *createMenuCategory(const QModelIndex &aCategory);
    QMenu *createMenuAchievementsHeader();
    QMenu *createMenuFrozenTable(const QModelIndex &aIndex);
    void updateFilterWithMyProfile(const ReachedType &aType);
    void updateFilterTextAchievement(const QString &aNewText);
    void updateFilterCategory(Category *aCategory, const bool &aIsChecked);
    void updateFilterFavorite(const QList<FavoriteAchievement> &aFavoritesAchievements);
    void updateFilterFriend(const ProfileID &aSteamId, const ReachedType &aType);
    void loading(const bool &aIsLoading);
    SAchievement currentAchievement();
    void onUpdateFilters();
    void updateAchievements();
    void loadFriends();
    int addFriendColumn(const SProfile &aSteamFriend, FriendListItemData::ProfileType);
    bool removeFriendColumn(const SProfile &aSteamFriend);
    void initTreeCategories();
    void initAchievementsTable();
    void initFriends();
    QWidgetAction *createCheckBoxHeaderAction(QMenu *aMenu, const QString &aText, achievementsModel::Columns aColumn);
    void buttonAddProfile_Clicked();

private:
    Ui::FormAchievements *ui;

    //ключевые данные
    SProfile profile_;
    SGame game_;
//    Category *_categories;

    //загружены ли другие формы
//    bool _isEditCategoryLoaded = false;
//    bool _isCompareLoaded      = false;

    AchievementsModel *achievementsModel_ = nullptr;
    FilterModelAchievements filterAchievements_;

    CategoriesModel *categoriesModel_ = nullptr;

    //сравнение с друзьями
    QList<SProfile> friendsProfiles_;
    QList<QPair<SProfile, FriendListItemData::ProfileType>> profilesInTable_;

    bool loadedCategories_ = false;
    bool loadedAchievements_ = false;
    bool loadedFriends_ = false;

};

#endif // FORMACHIEVEMENTS_H
