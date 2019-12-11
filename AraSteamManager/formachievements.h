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

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, QString ids, SGame game, int num, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void return_to_games(int num);

public slots:
    void ProgressLoading(int p,int row);
    void OnFinish();

private slots:
    void InitComponents();

    void OnResultImage(ImageRequest *imgr);
    void SwitchSimpleCompare(int sc);
    void LoadingCompare();
    void on_ComboBoxCategory_Change(int index);
    void on_CheckBoxCategory_Change(int ind);
    void closeEvent(QCloseEvent*);
    void on_ButtonReturn_clicked();
    void UpdateHiddenRows();
    void PullTableWidget();
    bool ProfileIsPublic(SAchievements achievement, int col);
    void on_ButtonAddCategory_clicked();

    void on_RadioButtonAll_clicked();
    void on_RadioButtonReached_clicked();
    void on_RadioButtonNotReached_clicked();
    void FavoritesClicked();

    void on_LineEditNameAchievements_textChanged(const QString &arg1);

    void on_ButtonChangeCategory_clicked();

    void on_ButtonFindAchievement_clicked();

    void on_ButtonUpdate_clicked();

    void ShowCategories();

    void on_ButtonCompare_clicked();

    void on_RadioButtonFriendAll_Click();
    void on_RadioButtonFriendReached_Click();
    void on_RadioButtonFriendNotReached_Click();

    void on_CheckBoxCompareIcon_stateChanged(int arg1);

    void on_CheckBoxCompareTitle_stateChanged(int arg1);

    void on_CheckBoxCompareDescription_stateChanged(int arg1);

    void on_CheckBoxCompareTotalPercent_stateChanged(int arg1);

    void on_CheckBoxShowFilter_stateChanged(int arg1);

    void on_RadioButtonCompareFriendsAll_clicked();
    void on_RadioButtonCompareFriendsReached_clicked();
    void on_RadioButtonCompareFriendsNotReached_clicked();

    void on_TableWidgetCompareFriendsCellChanged(int row, int column);

    void on_CheckBoxCompareAllFriends_stateChanged(int arg1);

    void LoadFriend(SGames *Games);
    void FinishLoadFriends();

    void on_ButtonAddValueCategory_clicked();

    void on_CheckBoxCategoryOneValue_stateChanged(int arg1);

    void on_ButtonCancelCategory_clicked();

    void on_ButtonDeleteCategory_clicked();

    void on_ButtonAcceptCategory_clicked();

    void on_ComboBoxCategoriesCategory_activated(int index);

    void on_FormCategoryValueChange(int pos, QString value);
    void on_FormCategoryVisibleChange(int pos, bool visible);
    void on_FormCategoryPositionChange(int pos, int newpos);
    void on_FormCategorySelectChange(int pos, bool select);
    void on_FormCategoryDeleting(int pos);

    void on_CheckBoxCategoryVisibleAll_clicked();

    void on_ButtonDeleteAllCategories_clicked();

    void on_LineEditTitleCategory_textChanged(const QString &arg1);

    void on_CheckBoxFavorites_stateChanged(int arg1);

private:
    Ui::FormAchievements *ui;
    QString key;
    QString id;
    SGame game;
    int unicnum;
    SAchievements achievements;
    CategoriesGame categoriesGame;
    Settings Setting;
    QString theme="white";
    Favorites favorites;

    QVector<ImageRequest*> request;
    int numrequests=0;
    int numnow=0;

    int simpleCompare=1;
    int loadCompare=0;
    int type1=0;
    int type2=0;
    int friendsCount=0;
    QVector<SProfile> Profiles;
    QVector<QPair<SProfile,int>> friends;

    QFormLayout *categoryvalueslayout;
    int typecategory=0;
    QVector<FormCategoryValue*> Values;
    Filter FAchievements;
    Filter FCompare;
};

#endif // FORMACHIEVEMENTS_H
