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
#include <class/Network/requestimage.h>
#include <class/settings.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/filter.h>
#include <class/favorites.h>
#include <class/categoriesgame.h>
#include <class/Threads/threading.h>
#include <AchievementsSubForms/formcategoryvalue.h>
#include <AchievementsSubForms/formcompareprofilefilter.h>
#include <AchievementsSubForms/formtablesheaders.h>
#include <subwidget/qbuttonwithdata.h>
#include <subwidget/qradiobuttonwithdata.h>
#include <subwidget/qcomboboxwithdata.h>
#include <subwidget/qcheckboxwithdata.h>

namespace Ui {
    class FormAchievements;
}

class FormAchievements: public QWidget {
    Q_OBJECT

enum class FormMode {
    achievement,
    compare
};

enum class FriendType {
    haveGame,
    haventGame
};

enum class CategoryType {
    none,
    add,
    change
};

public slots:
    void progressLoading(int progress, int row);
    void onFinish(int reached, int notReached);
    QString getProfile();
    int getGameAppId();
    void buttonUpdate_Clicked();

public:
    explicit FormAchievements(SAchievementsPlayer pl, QString id, SGame game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_returnToGames(int num);


private slots:
    void changeEvent(QEvent *event);
    void initComponents();
    void pullTable();
    void retranslate();

    void switchMode(FormAchievements::FormMode mode);
    void loadingCompare();
    void loadFriendGames(SGames *games);
    void finishLoadFriends();
    void compareProfileFilterClickMy(QString name, ReachedType type);
    void compareProfileFilterClickFriends(QString name, ReachedType type);

    void buttonCompareAllFriendsReach_Clicked();
    void tableWidgetCompareFriends_CellChanged(int row, int column);
    void createCompareProfileFilter(bool accept, int column);
    void checkBoxCompareAllFriends_StateChanged(int arg1);

    void closeEvent(QCloseEvent*);
    void showCategories();
    void updateHiddenRows();
    bool setFriendAchievements(SAchievements achievement, int column);

    void lineEditNameAchievements_TextChanged(const QString &arg1);
    void buttonFindAchievement_Clicked();
    void buttonAddCategory_Clicked();
    void buttonChangeCategory_Clicked();
    void favoritesClicked();
    void buttonCompare_Clicked();
    void checkBoxShowFilter_StateChanged(int arg1);
    void comboBoxCategory_IndexChange(int index);
    void checkBoxCategory_StateChanged(int ind);
    void buttonDeleteAllCategories_Clicked();

    void buttonAddValueCategory_Clicked();
    void buttonCancelCategory_Clicked();
    void buttonAcceptCategory_Clicked();
    void buttonDeleteCategory_Clicked();
    void checkBoxCategoryOneValue_StateChanged(int arg1);
    void lineEditTitleCategory_TextChanged(const QString &arg1);
    void comboBoxCategories_Activated(int index);
    void checkBoxCategoryVisibleAll_Clicked();

    void updateValuesUpDown(int value = -1);
    void formCategoryValue_Change(int pos, QString value);
    void formCategoryVisible_Change(int pos, bool visible);
    void formCategoryPosition_Change(int pos, int newpos);
    void formCategorySelect_Change(int pos, bool select);
    void formCategoryDelete(int pos);
    void formCategoryReverse(int pos);

    void checkBoxFavorites_StateChanged(int arg1);

    void checkBoxCategoryUniqueValue_StateChanged(int arg1);
    void hideCheckedAchievement(QTableWidgetItem *item);
    FormCategoryValue* createValueCategory();

    void buttonFavorite_Clicked();

    void tableAchievements_CellClicked(int row, int column);

    void setTheme();
    void setIcons();

private:
    Ui::FormAchievements *ui;
    Settings _setting;
    QString _theme = "white";
    QString _currentAchievement;
    int _currentAchievementIndex = -1;

    //ключевые данные
    QString _id;
    SGame _game;
    int _unicNum;
    SAchievements _achievements;
    CategoriesGame _categoriesGame;
    Favorites _favorites;

    //используются на форме
    FormCompareProfileFilter *_filterMyProfile;
    QFormLayout *_categoryValuesLayout;
    FormTablesHeaders *_tableAchievements;

    //для загрузки картинок
    QList<RequestData*> _request;
    int _numRequests=0;
    int _numNow=0;

    //сравнение с друзьями
    FormMode _currentMode = FormMode::compare;
    int _loadCompare = 0;
    int _type1 = 0;
    int _type2 = 0;
    SProfiles _profilesFriends;
    QList<QPair<SProfile, FriendType>> _friends;

    //для создания/редактирования категории
    CategoryType _typeCategory = CategoryType::none;
    QList<FormCategoryValue*> _values;
    bool _isUnique = false;

    //для фильтрации
    Filter _fAchievements;
    Filter _fCompare;

};

#endif // FORMACHIEVEMENTS_H
