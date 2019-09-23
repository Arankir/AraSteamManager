#ifndef FORMGAMES_H
#define FORMGAMES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <formachievements.h>
#include <class/steamapi/steamapigames.h>
#include <class/settings.h>
#include <class/steamapi/steamapiachievements.h>

namespace Ui {
class FormGames;
}

class FormGames : public QWidget
{
    Q_OBJECT

public:
    explicit FormGames(QString id, QString key, SteamAPIGames Games, QWidget *parent = nullptr);
    ~FormGames();
    FormAchievements *achievementsform;

signals:
    void return_to_profile();

private slots:
    void OnResultImage(ImageRequest *imgr);
    void OnResultAchievements(ImageRequest *imgr);
    void closeEvent(QCloseEvent *event);

    void on_ButtonReturn_clicked();

    void AchievementsClicked();

    void FavoritesClicked();

    void returnfromachievements();

    void on_LineEditGame_textChanged(const QString);

    void on_ButtonFind_clicked();

private:
    Ui::FormGames *ui;
    QString id;
    QString key;
    int windowchildcount=0;
    QVector<SteamAPIGame> games;
    QStringList Words;
    Settings Setting;
    QString theme="white";
};

#endif // FORMGAMES_H
