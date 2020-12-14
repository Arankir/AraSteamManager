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
#include "classes/threads/threading.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"
#include "subWidgets/withData/qcomboboxwithdata.h"
#include "subWidgets/withData/qcheckboxwithdata.h"
#include "forms/formcommentsinteractions.h"
#include "forms/subForms/achievements/formcomparefriends.h"
#include "forms/subForms/achievements/formcategoriesedit.h"
#include "forms/subForms/achievements/formcompareprofilefilter.h"
#include "forms/subForms/achievements/formtablesheaders.h"

namespace Ui {
    class FormAchievements;
}

class FormAchievements: public QWidget {
    Q_OBJECT

enum class FormMode {
    standart,
    compare
};

enum FriendType {
    haventGame,
    haveGame
};

public slots:
    void progressLoading(int progress, int row);
    void onTablePulled(int reached, int notReached);
    QString getProfileId() const {return _profile._steamID;}
    int getGameAppId() const {return _game.appId();}
    void buttonUpdate_Clicked();
    
    void updateSettings();
    void buttonManual_Clicked();
public:
    explicit FormAchievements(SAchievementsPlayer &pl, SProfile &profile, SGame &game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_returnToGames(int num);
    void s_updateSettings();

private slots:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent*);
    void initComponents();
    void retranslate();
    void setIcons();

    QButtonWithData *createButtonWithData(const QString &aObjectName, const QString &aAppertain, const QString &aType, bool aChecked);
    void setFormMode(FormMode mode);
    void loadingCompare();
    void loadFriendGames(SGames *games);
    void finishLoadFriends();
    void compareProfileFilterClickFriends(const QString &name, ReachedType type);

    void buttonCompareAllFriendsReach_Clicked();
    void tableWidgetCompareFriends_CellChanged(int row, int column);
    void createCompareProfileFilter(bool accept, int column);
    void checkBoxCompareAllFriends_StateChanged(int arg1);

    void showCategories();

    void comboBoxCategory_IndexChange(int index);
    void checkBoxCategory_StateChanged(int ind);

    void checkBoxFavorites_StateChanged(int arg1);

    void buttonFavorite_Clicked();

    void loadEditCategory();
    void loadCompare();
    void tabWidget_CurrentChanged(int index);

    void createThread();
    void setTableModels(QStandardItemModel *aModel);
    void initTableStandart();
    void updateCurrentAchievement();
    void initComments();
    void updateHiddenRows(bool standart, bool compare);
    void buttonComment_Clicked();
    QMenu *createMenu(const SAchievement &aAchievement);
    void initTableCompare();
    void updateFilterWithMyProfile(ReachedType aType, bool aStandart, bool aCompare);
    void updateFilterTextAchievement(const QString &aNewText, bool aStandart, bool aCompare);
    void updateHiddenColumnsStandart();
    void updateFilterCategory(int categoryIndex, bool clear, QList<QString> achievementNames = QList<QString>());
    void updateFilterFavorite(const QList<FavoriteAchievement> &aFavoritesAchievements);
    int rowFromId(QString aId);
    int recursAddCategoryToTree(Category &category, int count, QTreeWidgetItem *root = nullptr);
    void updateCurrentCategory();
    QMenu *createMenuCategory(const Category &aCategory);
    void categoryChangeAchievements();
    void categoryAddSubCategory();
    void categoryDelete();
private:
    Ui::FormAchievements *ui;
    SAchievements _achievements;

    //ключевые данные
    SProfile _profile;
    SGame _game;
    int _unicNum;
    Categories _categoriesGame;
    Favorites _favorites;
    Comments _comments;

    //используются на форме
    //QFormLayout *_categoryValuesLayout;
    //FormTablesHeaders *_tableAchievements;

    //загружены ли другие формы
    bool _isEditCategoryLoaded = false;
    bool _isCompareLoaded      = false;

    //сравнение с друзьями
    FormMode _currentMode = FormMode::compare;
    int _loadCompare = 0;
    int _type1 = 0;
    int _type2 = 0;
    SProfiles _profilesFriends;
    QList<QPair<SProfile, FriendType>> _friends;

    //для фильтрации
    MyFilter _fCategories;
    MyFilter _fAchievements;
    MyFilter _fCompare;

    //выбранное достижение
    SAchievement *_currentAchievement = nullptr;
    int _currentAchievementIndex;

    //выбранная категория
    Category *_currentCategory = nullptr;
    int _currentCategoryIndex;

};

#endif // FORMACHIEVEMENTS_H
