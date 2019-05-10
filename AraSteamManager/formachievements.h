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
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <imagerequest.h>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, int languages, QString ids, QString appids, QString GameName, QJsonDocument JsonDocGlobalAchievement,int SaveImages, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void return_to_games();

private slots:
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void on_ComboBoxCategory_Change(int index);
    void closeEvent(QCloseEvent *);
    void on_FormAchievementsButtonReturn_clicked();
    void FavoritesClicked();
    void UpdateHiddenRows();
    void on_FormAchievementsButtonAddCategory_clicked();
    void on_return();

    void on_FormAchievementsRadioButtonAll_clicked();

    void on_FormAchievementsRadioButtonReached_clicked();

    void on_FormAchievementsRadioButtonNotReached_clicked();

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

private:
    Ui::FormAchievements *ui;
    QString key;
    QString id;
    int language;
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
