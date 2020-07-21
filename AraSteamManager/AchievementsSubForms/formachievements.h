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
    standart,
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
    void onTablePulled(int reached, int notReached);
    QString getProfileId();
    int getGameAppId();
    void buttonUpdate_Clicked();
    
    void updateSettings();
public:
    explicit FormAchievements(SAchievementsPlayer pl, SProfile profile, SGame game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_returnToGames(int num);
    void s_updateSettings();

private slots:
    void changeEvent(QEvent *event);
    void initComponents(SAchievementsPlayer player);
    void retranslate();
    void setIcons();

    QButtonWithData *createButtonWithData(QString aObjectName, QString aAppertain, QString aType, bool aChecked);
    void setFromMode(FormAchievements::FormMode mode);
    void loadingCompare();
    void loadFriendGames(SGames *games);
    void finishLoadFriends();
    void compareProfileFilterClickFriends(QString name, ReachedType type);

    void buttonCompareAllFriendsReach_Clicked();
    void tableWidgetCompareFriends_CellChanged(int row, int column);
    void createCompareProfileFilter(bool accept, int column);
    void checkBoxCompareAllFriends_StateChanged(int arg1);

    void closeEvent(QCloseEvent*);
    void showCategories();

    void buttonAddCategory_Clicked();
    void buttonChangeCategory_Clicked();
    void buttonCompare_Clicked();
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
    void formCategoryVisible_Change(int pos, bool visible);
    void formCategoryPosition_Change(int pos, int newpos);
    void formCategoryDelete(int pos);
    void formCategoryReverse(int pos);

    void checkBoxFavorites_StateChanged(int arg1);

    FormCategoryValue* createValueCategory();

    void buttonFavorite_Clicked();

    void tableAchievements_CellClicked(int row, int column);

private:
    Ui::FormAchievements *ui;
    Settings _setting;
    QString _currentAchievement;
    int _currentAchievementIndex = -1;

    //ключевые данные
    SProfile _profile;
    SGame _game;
    int _unicNum;
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

};

#endif // FORMACHIEVEMENTS_H
