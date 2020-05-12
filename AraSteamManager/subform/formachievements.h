#ifndef FORMACHIEVEMENTS_H
#define FORMACHIEVEMENTS_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
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
#include <subform/formcategoryvalue.h>
#include <subform/formcompareprofilefilter.h>
#include <subwidget/qbuttonwithdata.h>
#include <subwidget/qradiobuttonwithdata.h>
#include <subwidget/qcomboboxwithdata.h>
#include <subwidget/qcheckboxwithdata.h>
#include <subform/formtablesheaders.h>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

enum class FormMode{
    achievement,
    compare
};

enum class FriendType{
    haveGame,
    haventGame
};

enum class CategoryType{
    none,
    add,
    change
};

public:
    explicit FormAchievements(SAchievementsPlayer pl, QString id, SGame game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_return_to_games(int num);

public slots:
    void ProgressLoading(int p,int row);
    void OnFinish(int reached, int notReached);
    QString GetProfile() {return _id;}
    int GetGameAppID() {return _game._appID;}
    void ButtonUpdate_Clicked();

private slots:
    void changeEvent(QEvent *event);
    void InitComponents();
    void PullTableWidget();
    void Retranslate();

    void SwitchSimpleCompare(FormAchievements::FormMode sc);
    void LoadingCompare();
    void LoadFriendGames(SGames *Games);
    void FinishLoadFriends();
    void CompareProfileFilterClickMy(QString name,ReachedType type);
    void CompareProfileFilterClickFriends(QString name,ReachedType type);

    void ButtonCompareAllFriendsReach_Clicked();
    void TableWidgetCompareFriends_CellChanged(int row, int column);
    void CreateCompareProfileFilter(bool Aaccept, int Acolumn);
    void CheckBoxCompareAllFriends_StateChanged(int arg1);

    void closeEvent(QCloseEvent*);
    void ShowCategories();
    void UpdateHiddenRows();
    bool SetFriendAchievements(SAchievements achievement, int col);

    void LineEditNameAchievements_TextChanged(const QString &arg1);
    void ButtonFindAchievement_Clicked();
    void ButtonAddCategory_Clicked();
    void ButtonChangeCategory_Clicked();
    void FavoritesClicked();
    void ButtonCompare_Clicked();
    void CheckBoxShowFilter_StateChanged(int arg1);
    void ComboBoxCategory_IndexChange(int index);
    void CheckBoxCategory_StateChanged(int ind);
    void ButtonDeleteAllCategories_Clicked();

    void ButtonAddValueCategory_Clicked();
    void ButtonCancelCategory_Clicked();
    void ButtonAcceptCategory_Clicked();
    void ButtonDeleteCategory_Clicked();
    void CheckBoxCategoryOneValue_StateChanged(int arg1);
    void LineEditTitleCategory_TextChanged(const QString &arg1);
    void ComboBoxCategories_Activated(int index);
    void CheckBoxCategoryVisibleAll_Clicked();

    void UpdateValuesUpDown(int value=-1);
    void FormCategoryValue_Change(int pos, QString value);
    void FormCategoryVisible_Change(int pos, bool visible);
    void FormCategoryPosition_Change(int pos, int newpos);
    void FormCategorySelect_Change(int pos, bool select);
    void FormCategoryDelete(int pos);
    void FormCategoryReverse(int pos);

    void CheckBoxFavorites_StateChanged(int arg1);

    void CheckBoxCategoryUniqueValue_StateChanged(int arg1);
    void HideCheckedAchievement(QTableWidgetItem *item);
    FormCategoryValue *CreateValueCategory();

    void ButtonFavorite_Clicked();

    void TableAchievements_CellClicked(int row, int column);

private:
    Ui::FormAchievements *ui;
    Settings _setting;
    QString _theme="white";
    QString _currentAchievement;
    int _currentAchievementIndex=-1;

    //ключевые данные
    QString _id;
    SGame _game;
    int _unicNum;
    SAchievements _achievements;
    CategoriesGame _categoriesGame;
    Favorites _favorites;

    //используются на форме
    FormCompareProfileFilter *FilterMyProfile;
    QFormLayout *_categoryValuesLayout;
    FormTablesHeaders *_tableAchievements;

    //для загрузки картинок
    QVector<RequestData*> _request;
    int _numRequests=0;
    int _numNow=0;

    //сравнение с друзьями
    FormMode _simpleCompare=FormMode::compare;
    int _loadCompare=0;
    int _type1=0;
    int _type2=0;
    SProfiles _profilesFriends;
    QVector<QPair<SProfile,FriendType>> _friends;

    //для создания/редактирования категории
    CategoryType _typeCategory=CategoryType::none;
    QVector<FormCategoryValue*> _values;
    bool _isUnique=false;

    //для фильтрации
    Filter _fAchievements;
    Filter _fCompare;

};

#endif // FORMACHIEVEMENTS_H
