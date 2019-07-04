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
    explicit FormGames(QString id, QString key, int language, int Theme, QJsonDocument Games, int SaveImages, QWidget *parent = nullptr);
    ~FormGames();
    FormAchievements *achievementsform;

signals:
    void return_to_profile(FormGames*);

private slots:
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void OnResultAchievements(int, QString, ImageRequest *);
    void closeEvent(QCloseEvent *event);

    void on_FormGamesButtonReturn_clicked();

    void AchievementsClicked();

    void FavoritesClicked();

    void on_return(FormAchievements*);

    void on_FormGamesLineEditGame_textChanged(const QString);

    void on_FormGamesButtonFind_clicked();

private:
    Ui::FormGames *ui;
    QString id;
    QString key;
    int language;
    int Theme;
    int windowchildcount=0;
    QJsonDocument JsonDocGames;
    QStringList SLLanguage;
    int SaveImages;
};

#endif // FORMGAMES_H
