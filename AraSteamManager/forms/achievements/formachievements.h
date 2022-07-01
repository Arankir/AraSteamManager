#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include "form.h"
#include "classes/files/favorites.h"
#include "classes/files/category.h"
#include "subWidgets/models/achievementsmodel.h"
#include "subWidgets/withData/buttonreachedtype.h"

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
    void updateSettings(QFlags<changedSettings> aSettings) override;
    void update();
    void openManual();
    bool isDataSetted() {return _achievementsModel->getAchievementsCount() > 0 && _profile.personaName() != "" && _game.appId() > 0;}
    void setAllFriendsValue(const ReachedType &aType);
    void addFriendToList(const SProfile &aSteamFriend);
public:
    explicit FormAchievements(QWidget *parent = nullptr);
    ~FormAchievements();
    void setData(const SProfile &profile, const SGame &game);

    QString getProfileId() const {return _profile.steamID();}
    int getGameAppId() const {return _game.appId();}
    int getAchievementsCount();

signals:
    void s_filtersUpdated(QAbstractItemModel *model);
    void s_filtersValueUpdated();
    void s_progress(const QString &status = "", const int &progress = 0, const int &max = 0);
    void s_finished();
    void s_finishedFriends();

private slots:
    void closeEvent(QCloseEvent*) override;
    void retranslate() override;
    void updateIcons() override;

    //init
    void init();

    //system
    void updateCategories();

    void checkBoxFavorites_StateChanged(const int &arg1);

    void loadEditCategory();
    void tabWidget_CurrentChanged(const int &index);
    void loadFriendGames(const SGames &aGames, const QString &aUserId);

    void buttonComment_Clicked();
    QMenu *createMenuAchievements(const SAchievement &aAchievement);
    QMenu *createMenuCategory(Category *aCategory);
    void updateFilterWithMyProfile(const ReachedType &aType);
    void updateFilterTextAchievement(const QString &aNewText);
    void updateFilterCategory(Category *aCategory, const bool &aIsChecked);
    void updateFilterFavorite(const QList<FavoriteAchievement> &aFavoritesAchievements);
    void updateFilterFriend(SProfile *aSteamId, const ReachedType &aType);
    void loading(const bool &aIsLoading);
    SAchievement currentAchievement();
    void updateFilters();
    void updateModel();
    void loadingCompare();
    int addFriendColumn(const SProfile &aSteamFriend);
    bool removeFriendColumn(const SProfile &aSteamFriend);
private:
    Ui::FormAchievements *ui;

    //ключевые данные
    SProfile _profile;
    SGame _game;
    Category *_categories;

    //загружены ли другие формы
    bool _isEditCategoryLoaded = false;
    bool _isCompareLoaded      = false;

    AchievementsModel *_achievementsModel = nullptr;
    FilterModelAchievements _filterAchievements;

    //сравнение с друзьями
    int _loadCompare = 0;
    QList<SProfile> _profilesFriends;

};

#endif // FORMACHIEVEMENTS_H
