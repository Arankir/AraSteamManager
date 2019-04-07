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
#include <formnewcategory.h>
#include <QDir>

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString keys, int languages, QString ids, QString appids, QString GameName, QWidget *parent = nullptr);
    ~FormAchievements();
    FormNewCategory *newcategoryform;

signals:
    void return_to_games();

private slots:
    void closeEvent(QCloseEvent *);
    void on_FormAchievementsButtonReturn_clicked();
    void FavoritesClicked();

    void on_FormAchievementsButtonAddCategory_clicked();
    void on_return();

    void on_FormAchievementsRadioButtonAll_clicked();

    void on_FormAchievementsRadioButtonReached_clicked();

    void on_FormAchievementsRadioButtonNotReached_clicked();

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
};

#endif // FORMACHIEVEMENTS_H
