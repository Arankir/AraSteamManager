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
#include <class/requestdata.h>
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
    void OnFinish();
    QString GetProfile() {return _id;}
    SGame GetGame() {return _game;}
    void on_ButtonUpdate_clicked();

private slots:
    void changeEvent(QEvent *event);
    void InitComponents();
    void PullTableWidget();
    void Retranslate();
    void OnImageLoaded(RequestData *imgr);

    void SwitchSimpleCompare(FormMode sc);
    void LoadingCompare();
    void LoadFriendGames(SGames *Games);
    void FinishLoadFriends();
    void CompareProfileFilterClickMy(QString name,ReachedType type);
    void CompareProfileFilterClickFriends(QString name,ReachedType type);

    void on_ButtonCompareAllFriendsReach_clicked();
    void on_TableWidgetCompareFriendsCellChanged(int row, int column);
    void CreateCompareProfileFilter(bool Aaccept, int Acolumn);
    void on_CheckBoxCompareAllFriends_stateChanged(int arg1);

    void closeEvent(QCloseEvent*);
    void ShowCategories(bool saveDate);
    void UpdateHiddenRows();
    bool SetFriendAchievements(SAchievements achievement, int col);

    void TableSetColumnCount(int columns);
    void TableInsertColumn(int columns);
    void TableRemoveColumn(int columns);
    void TableSetColumnVisible(int column, bool visible);
    void TableSetHorizontalHeaderText(int index, QString text);
    void TableSetRowCount(int row);
    void TableInsertRow(int row);
    void TableRemoveRow(int row);
    void TableSetRowVisible(int row, bool visible);

    void on_LineEditNameAchievements_textChanged(const QString &arg1);
    void on_ButtonFindAchievement_clicked();
    void on_ButtonAddCategory_clicked();
    void on_ButtonChangeCategory_clicked();
    void FavoritesClicked();
    void on_ButtonCompare_clicked();
    void on_CheckBoxShowFilter_stateChanged(int arg1);
    void on_ComboBoxCategory_Change(int index);
    void on_CheckBoxCategory_Change(int ind);
    void on_ButtonDeleteAllCategories_clicked();

    void on_CheckBoxCompareIcon_stateChanged(int arg1);
    void on_CheckBoxCompareTitle_stateChanged(int arg1);
    void on_CheckBoxCompareDescription_stateChanged(int arg1);
    void on_CheckBoxCompareTotalPercent_stateChanged(int arg1);

    void on_ButtonAddValueCategory_clicked();
    void on_ButtonCancelCategory_clicked();
    void on_ButtonAcceptCategory_clicked();
    void on_ButtonDeleteCategory_clicked();
    void on_CheckBoxCategoryOneValue_stateChanged(int arg1);
    void on_LineEditTitleCategory_textChanged(const QString &arg1);
    void on_ComboBoxCategoriesCategory_activated(int index);
    void on_CheckBoxCategoryVisibleAll_clicked();

    void on_FormCategoryValueChange(int pos, QString value);
    void on_FormCategoryVisibleChange(int pos, bool visible);
    void on_FormCategoryPositionChange(int pos, int newpos);
    void on_FormCategorySelectChange(int pos, bool select);
    void on_FormCategoryDeleting(int pos);
    void on_FormCategoryReverse(int pos);

    void on_CheckBoxFavorites_stateChanged(int arg1);

    void on_CheckBoxCategoryUniqueValue_stateChanged(int arg1);
    void HideCheckedAchievement(QTableWidgetItem *item);
    FormCategoryValue *CreateValueCategory();

    void on_horizontalScrollBar_sliderMoved(int position);

    void on_ButtonFavorite_clicked();

    void on_TableWidgetAchievements_cellClicked(int row, int column);

private:
    Ui::FormAchievements *ui;
    Settings _setting;
    QString _theme="white";
    bool _isFirstLoad=true;
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
