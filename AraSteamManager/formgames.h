#ifndef FORMGAMES_H
#define FORMGAMES_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLabel>
#include <QPushButton>
#include <formachievements.h>

namespace Ui {
class FormGames;
}

class FormGames : public QWidget
{
    Q_OBJECT

public:
    explicit FormGames(QString id, QString key, int language, QWidget *parent = nullptr);
    void on_FormCreate_language(QString LabelLogo, QString GamePlaceholder, QString ButtonFind, QString ButtonReturn, QString HH0, QString HH1, QString HH2, QString HH3, QJsonArray Games, QString buttonAchievements);
    ~FormGames();
    FormAchievements *achievementsform;

signals:
    void return_to_profile();

private slots:
    void closeEvent(QCloseEvent *event);

    void on_FormGamesButtonReturn_clicked();

    void AchievementsClicked();

    void FavoritesClicked();

    void on_return();

    void on_FormGamesLineEditGame_textChanged(const QString);

    void on_FormGamesButtonFind_clicked();

private:
    Ui::FormGames *ui;
    QString id;
    QString key;
    int language;
    QJsonDocument JsonDocGames;
};

#endif // FORMGAMES_H
