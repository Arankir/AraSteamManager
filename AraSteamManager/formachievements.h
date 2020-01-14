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
#include <class/imagerequest.h>
#include <class/settings.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/filter.h>
#include <class/favorites.h>
#include <class/categoriesgame.h>
#include <class/Threads/threading.h>
#include <subform/formcategoryvalue.h>
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
    explicit FormAchievements(SAchievementsPlayer pl, QString ids, SGame game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void s_return_to_games(int num);

public slots:
    void ProgressLoading(int p,int row);
    void OnFinish();

private slots:
    void InitComponents();
    void PullTableWidget();
    void OnResultImage(ImageRequest *imgr);

    void SwitchSimpleCompare(FormMode sc);
    void LoadingCompare();
    void LoadFriend(SGames *Games);
    void FinishLoadFriends();
    void on_RadioButtonAll_clicked();
    void on_RadioButtonReached_clicked();
    void on_RadioButtonNotReached_clicked();

    void on_RadioButtonCompareFriendsAll_clicked();
    void on_RadioButtonCompareFriendsReached_clicked();
    void on_RadioButtonCompareFriendsNotReached_clicked();
    void on_RadioButtonFriendAll_Click();
    void on_RadioButtonFriendReached_Click();
    void on_RadioButtonFriendNotReached_Click();
    void on_TableWidgetCompareFriendsCellChanged(int row, int column);
    void on_CheckBoxCompareAllFriends_stateChanged(int arg1);

    void closeEvent(QCloseEvent*);
    void ShowCategories();
    void UpdateHiddenRows();
    bool ProfileIsPublic(SAchievements achievement, int col);

    void on_LineEditNameAchievements_textChanged(const QString &arg1);
    void on_ButtonFindAchievement_clicked();
    void on_ButtonAddCategory_clicked();
    void on_ButtonChangeCategory_clicked();
    void on_ButtonUpdate_clicked();
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

    void on_CheckBoxFavorites_stateChanged(int arg1);

private:
    Ui::FormAchievements *ui;
    QString _id;
    SGame _game;
    int _unicNum;
    SAchievements _achievements;
    CategoriesGame _categoriesGame;
    Settings _setting;
    QString _theme="white";
    Favorites _favorites;

    QVector<ImageRequest*> _request;
    int _numRequests=0;
    int _numNow=0;

    FormMode _simpleCompare=FormMode::compare;
    int _loadCompare=0;
    int _type1=0;
    int _type2=0;
    int _friendsCount=0;
    QVector<SProfile> _profiles;
    QVector<QPair<SProfile,FriendType>> _friends;

    QFormLayout *_categoryValuesLayout;
    CategoryType _typeCategory=CategoryType::none;
    QVector<FormCategoryValue*> _values;

    Filter _fAchievements;
    Filter _fCompare;

};

#endif // FORMACHIEVEMENTS_H
