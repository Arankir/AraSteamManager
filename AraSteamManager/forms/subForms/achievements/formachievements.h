#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDir>
#include <QComboBox>
#include <QMessageBox>
#include <QFormLayout>
#include <QButtonGroup>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QMenu>
#include <QAction>
#include <QTreeWidgetItem>
#include "framelesswindow.h"
#include "classes/network/requestimage.h"
#include "classes/common/settings.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/myfilter.h"
#include "classes/common/favorites.h"
#include "classes/common/comments.h"
#include "classes/achievements/categoriesgame.h"
#include "classes/threads/thread/threadachievements.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"
#include "subWidgets/withData/qcomboboxwithdata.h"
#include "subWidgets/withData/qcheckboxwithdata.h"
#include "subWidgets/progressBars/progressbargood.h"
#include "forms/formcomments.h"
#include "forms/subForms/achievements/formcategoriesedit.h"
#include "forms/subForms/achievements/widgets/formreachedfilter.h"
#include "subWidgets/models/achievementsmodel.h"
#include "subWidgets/models/filters.h"

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
    void updateSettings() override;
    void update();
    void openManual();
    bool isDataSetted() {return _achievements.count() > 0 && _profile.personaName() != "" && _game.appId() > 0;}
public:
    explicit FormAchievements(SProfile &profile, SGame &game, QWidget *parent = nullptr);
    explicit FormAchievements(QWidget *parent = nullptr);
    ~FormAchievements();
    void setData(SProfile &profile, SGame &game);

    QString getProfileId() const {return _profile.steamID();}
    int getGameAppId() const {return _game.appId();}

signals:
    void s_updateSettings();
    void s_filtersUpdated(QAbstractItemModel *model);
    void s_filtersValueUpdated();
    void s_updatedHiddenRows();

private slots:
    void closeEvent(QCloseEvent*) override;
    void retranslate() override;
    void updateIcons() override;

    //init
    void init();
//    void initComments();
//    void createThread();
    void progressLoading(const int &value, const int &max);
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
    void updateFilterCategory(Category *aCategory, const bool &aIsChecked);
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
    SAchievements _achievements;

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
    SortFilterProxyModelMiltiRow _filterName;
    QSortFilterProxyModel _filterReached;
    QSortFilterProxyModel _filterFavorite;
    QList<SortFilterProxyModelCategory*> _filtersCategories;
};

#endif // FORMACHIEVEMENTS_H
