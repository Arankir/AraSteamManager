#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include "form.h"
#include "classes/files/favorites.h"
#include "classes/files/achievementscategory.h"
#include "subWidgets/models/achievementsmodel.h"
#include "forms/widgets/formreachedfilter.h"

namespace FormAchievementsData {
//    enum tableAchievements {
//        ColumnAppid         = 0,
//        ColumnIndex         = 1,
//        ColumnIcon          = 2,
//        ColumnTitle         = 3,
//        ColumnDescription   = 4,
//        ColumnComment       = 5,
//        ColumnWorld         = 6,
//        ColumnReachedMy     = 7,
//        ColumnCount         = 8
//    };

//    enum filterAchievements {
//        FilterName             = 0,
//        FilterReached          = 1,
//        FilterFavorite         = 2,
//        FilterColumnCount      = 3,
//        FilterEndConstValues   = 3
//    };

    enum tabs {
        TabStandart     = 0,
        TabCategories   = 1,
        TabCompare      = 2
    };
}

namespace Ui {
    class FormAchievements;
}

class FormAchievements: public Form {
    Q_OBJECT

enum FriendType {
    haventGame,
    haveGame
};

public slots:
    void updateSettings(QFlags<changedSettings> aSettings) override;
    void update();
    void openManual();
    bool isDataSetted() {return _achievementsModel->getAchievementsCount() > 0 && _profile.personaName() != "" && _game.appId() > 0;}
public:
    explicit FormAchievements(const SProfile &profile, const SGame &game, QWidget *parent = nullptr);
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

private slots:
    void closeEvent(QCloseEvent*) override;
    void retranslate() override;
    void updateIcons() override;

    //init
    void init();
//    void initComments();
//    void createThread();
//    void onModelFinished(QStandardItemModel *aModel, const int &reached, const int &notReached);

    //system
    void updateCategories();

    void checkBoxFavorites_StateChanged(const int &arg1);

    void buttonFavorite_Clicked();

    void loadEditCategory();
    void loadCompare();
    void tabWidget_CurrentChanged(const int &index);

//    void updateCurrentAchievement();
//    void updateHiddenRows();
    void buttonComment_Clicked();
    QMenu *createMenu(const SAchievement &aAchievement);
    void updateFilterWithMyProfile(const ReachedType &aType);
    void updateFilterTextAchievement(const QString &aNewText);
    void hideFriendsColumns();
    void updateFilterCategory(Category2 *aCategory, const bool &aIsChecked);
    void updateFilterFavorite(const QList<FavoriteAchievement> &aFavoritesAchievements);
//    int rowFromId(const QString &aId);
    void loading(const bool &aIsLoading);
    SAchievement currentAchievement();
    void updateFilters();
    void updateModel();
private:
    Ui::FormAchievements *ui;

    //Достижения
//    QList<SAchievementSchema> _global;
//    QList<SAchievementPercentage> _percent;
//    QList<SAchievementPlayer> _player;
//    SAchievements _achievements;

    //ключевые данные
    SProfile _profile;
    SGame _game;
//    Favorites _favorites;
//    QList<AchievementComment> _comments;

    //загружены ли другие формы
    bool _isEditCategoryLoaded = false;
    bool _isCompareLoaded      = false;

    //для фильтрации
//    MyFilter _fCategories;
//    MyFilter _fAchievements;

    //выбранное достижение
//    SAchievement *_currentAchievement = nullptr;
//    int _currentAchievementIndex;

    AchievementsModel *_achievementsModel = nullptr;
//    ProxyModelAchievements _filterAchievements;
    FilterModelAchievements _filterAchievements;
//    SortFilterProxyModelMiltiRow _filterName;
//    QSortFilterProxyModel _filterReached;
//    QSortFilterProxyModel _filterFavorite;
//    QList<SortFilterProxyModelCategory*> _filtersCategories;
};

#endif // FORMACHIEVEMENTS_H
