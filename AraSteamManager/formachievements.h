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
#include <QMessageBox>
#include <QFormLayout>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, int languages, QString ids, QString appids, QString GameName, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void return_to_games();

private slots:
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

    void on_FormAchievementsButtonAccessNewCategory_clicked();

private:
    Ui::FormAchievements *ui;
    QString key;
    QString id;
    int language;
    QString appid;
    QJsonDocument JsonDocNumberOfCurrentPlayers;
    QJsonDocument JsonDocGlobalAchievementPercentagesForApp;
    QJsonDocument JsonDocPlayerAchievements;
    QJsonDocument JsonDocSchemaForGame;
    bool **filter;
    int colfilter=3;
    QFormLayout *newcategoryvalueslayout;
};

#endif // FORMACHIEVEMENTS_H
