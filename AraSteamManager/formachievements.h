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
#include <class/imagerequest.h>
#include <formcompare.h>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, int languages, int Theme, QString ids, QString appids, QString GameName, QJsonDocument JsonDocGlobalAchievement,int SaveImages, QWidget *parent = nullptr);
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
    void on_FormAchievementsButtonReturn_clicked();
    void UpdateHiddenRows();
    void on_FormAchievementsButtonAddCategory_clicked();

    void on_FormAchievementsRadioButtonAll_clicked();
    void on_FormAchievementsRadioButtonReached_clicked();
    void on_FormAchievementsRadioButtonNotReached_clicked();
    void FavoritesClicked();

    void on_FormAchievementsLineEditNameAchievements_textChanged(const QString &arg1);

    void on_FormAchievementsButtonChangeCategory_clicked();

    void on_FormAchievementsButtonCancelNewCategory_clicked();

    void on_FormAchievementsButtonCancelChangeCategory_clicked();

    void on_FormAchievementsButtonAddValueNewCategory_clicked();
    void on_buttonNewCategoryDeleteValues_clicked();
    void on_buttonChangeCategoryDeleteValues_clicked();

    void on_FormAchievementsButtonAcceptNewCategory_clicked();

    void on_FormAchievementsComboBoxCategoriesChangeCategory_activated(int index);

    void on_FormAchievementsButtonAddValueChangeCategory_clicked();

    void on_FormAchievementsButtonAcceptChangeCategory_clicked();

    void on_FormAchievementsButtonDeleteCategory_clicked();

    void on_FormAchievementsButtonFindAchievement_clicked();

    void on_FormAchievementsButtonUpdate_clicked();

    void EditLineEditChangeCategoryValue();
    void on_buttonChangeCategoryUpValues_clicked();
    void on_buttonChangeCategoryDownValues_clicked();

    void EditLineEditNewCategoryValue();
    void on_buttonNewCategoryUpValues_clicked();
    void on_buttonNewCategoryDownValues_clicked();

    void on_FormAchievementsCheckBoxNewCategoryOneValue_stateChanged(int arg1);
    void on_FormAchievementsCheckBoxChangeCategoryOneValue_stateChanged(int arg1);

    void on_Change_Title_NewCategory_OneValue();
    void on_Change_Title_ChangeCategory_OneValue();

    void ShowCategories();

    void on_FormAchievementsButtonCompare_clicked();

private:
    Ui::FormAchievements *ui;
    QString key;
    QString id;
    int language;
    int Theme;
    int windowchildcount=0;
    QString appid;
    QJsonDocument JsonDocNumberOfCurrentPlayers;
    QJsonArray JsonArrayGlobalAchievements;
    QJsonDocument JsonDocPlayerAchievements;
    QJsonArray JsonArraySchemaForGame;
    bool **filter;
    int colfilter=3;
    QFormLayout *newcategoryvalueslayout;
    QFormLayout *changecategoryvalueslayout;
    QStringList SLLanguage;
    int SaveImages;
};

#endif // FORMACHIEVEMENTS_H
