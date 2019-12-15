#ifndef FORMGAMES_H
#define FORMGAMES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <formachievements.h>
#include <class/settings.h>
#include <class/favorites.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/Threads/threading.h>

namespace Ui {
class FormGames;
}

class FormGames : public QWidget
{
    Q_OBJECT

public:
    explicit FormGames(QString id, SGames Games, QWidget *parent = nullptr);
    ~FormGames();
    QVector<FormAchievements*> achievementsforms;

signals:
    void s_return_to_profile();

public slots:
    void ProgressLoading(int,int);
    void OnFinish();
    void ReturnFromAchievements(int num);

private slots:
    void InitComponents();
    void OnResultImage(ImageRequest *imgr);
    void OnResultAchievements(SAchievementsPlayer ach);
    void closeEvent(QCloseEvent *event);

    void AchievementsClicked();
    void FavoritesClicked();
    void HideClicked();

    void on_LineEditGame_textChanged(const QString);

    void on_ButtonFind_clicked();

private:
    Ui::FormGames *ui;
    QString _id;
    int _windowChildCount=0;
    QVector<SGame> _games;
    SAchievementsPlayer *_achievements;
    Favorites _favorites;
    QStringList _hide;
    Settings _setting;
    QString _theme="white";

    QVector<ImageRequest*> _request;
    int _numRequests=0;
    int _numNow=0;
};

#endif // FORMGAMES_H
