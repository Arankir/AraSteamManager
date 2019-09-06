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
#include <class\imagerequest.h>
#include <formcompare.h>
#include <class/settings.h>
#include <class/steamapigame.h>
#include <class/steamapiachievements.h>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, QString ids, SteamAPIGame game, QWidget *parent = nullptr);
    ~FormAchievements();
    FormCompare *compareform;

signals:
    void return_to_games(FormAchievements*);

private slots:
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void on_ComboBoxCategory_Change(int index);
    void on_CheckBoxCategory_Change(int ind);
    void closeEvent(QCloseEvent *);
    void on_return(FormCompare*);
    void on_ButtonReturn_clicked();
    void UpdateHiddenRows();
    void PullTableWidget();
    void on_ButtonAddCategory_clicked();

    void on_RadioButtonAll_clicked();
    void on_RadioButtonReached_clicked();
    void on_RadioButtonNotReached_clicked();
    void FavoritesClicked();

    void on_LineEditNameAchievements_textChanged(const QString &arg1);

    void on_ButtonChangeCategory_clicked();

    void on_ButtonCancelNewCategory_clicked();

    void on_ButtonCancelChangeCategory_clicked();

    void on_ButtonAddValueNewCategory_clicked();
    void on_buttonNewCategoryDeleteValues_clicked();
    void on_buttonChangeCategoryDeleteValues_clicked();
    void on_buttonNewCategorySelectValues_clicked();
    void on_buttonNewCategoryUnSelectValues_clicked();

    void on_ButtonAcceptNewCategory_clicked();

    void on_ComboBoxCategoriesChangeCategory_activated(int index);

    void on_ButtonAddValueChangeCategory_clicked();

    void on_ButtonAcceptChangeCategory_clicked();

    void on_ButtonDeleteCategory_clicked();

    void on_ButtonFindAchievement_clicked();

    void on_ButtonUpdate_clicked();

    void EditLineEditChangeCategoryValue();
    void on_buttonChangeCategoryUpValues_clicked();
    void on_buttonChangeCategoryDownValues_clicked();
    void on_buttonChangeCategorySelectValues_clicked();
    void on_buttonChangeCategoryUnSelectValues_clicked();

    void EditLineEditNewCategoryValue();
    void on_buttonNewCategoryUpValues_clicked();
    void on_buttonNewCategoryDownValues_clicked();

    void on_CheckBoxNewCategoryOneValue_stateChanged(int arg1);
    void on_CheckBoxChangeCategoryOneValue_stateChanged(int arg1);

    void on_Change_Title_NewCategory_OneValue();
    void on_Change_Title_ChangeCategory_OneValue();

    void ShowCategories();

    void on_ButtonCompare_clicked();

    void AddValueCategory(QString Type, QFormLayout* layout);
    void UpValueCategory(QString Type, int i);
    void DownValueCategory(QString Type, int i, QFormLayout* layout);
    void DeleteValuesCategory(QString Type, int i, QFormLayout* layout);
    void SelectValueCategory(int j,Qt::CheckState);

private:
    Ui::FormAchievements *ui;
    QString key;
    QString id;
    int windowchildcount=0;
    SteamAPIGame game;
    SteamAPIAchievements achievements;
    bool **filter;
    int colfilter=3;
    QFormLayout *newcategoryvalueslayout;
    QFormLayout *changecategoryvalueslayout;
    QStringList Words;
    Settings Setting;
    QString theme="white";
};

#endif // FORMACHIEVEMENTS_H
