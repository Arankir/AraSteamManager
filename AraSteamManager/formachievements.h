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

namespace Ui {
class FormAchievements;
}

class FormAchievements : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievements(QString, int, QString, QString, QWidget *parent = nullptr);
    ~FormAchievements();

signals:
    void return_to_games();

private slots:
    void closeEvent(QCloseEvent *);
    void on_FormAchievementsButtonReturn_clicked();
    void FavoritesClicked();

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
