#ifndef FORMGAMES_H
#define FORMGAMES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <formcontainerachievements.h>
#include <class/settings.h>
#include <class/favorites.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sachievements.h>
#include <class/Threads/threading.h>
#include <subwidget/qbuttonwithdata.h>
#include <QList>
#include <QPropertyAnimation>

namespace Ui {
class FormGames;
}

class FormGames : public QWidget
{
    Q_OBJECT

public:
    explicit FormGames(QString id, SGames Games, QWidget *parent = nullptr);
    ~FormGames();
    FormContainerAchievements *_containerAchievementsForm;
    QVector<FormAchievements*> _achievementsForms;

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int,int);
    void s_finish();

public slots:
    void ProgressLoading(int,int);
    void OnFinish();
    void ReturnFromAchievements(int num);

    void showHideSlideWidget(bool f_flag);
    void mouseMoveEvent(QMouseEvent *ev);
    void slotShowHideSlide();
private slots:
    void InitComponents();
    void OnImageLoad(RequestData *imgr);
    void OnResultAchievements(SAchievementsPlayer ach);
    void closeEvent(QCloseEvent *event);

    void AddAchievements(int index);
    void RemoveAchievements(int index);
    void ContainerAchievementsClose();

    void on_LineEditGame_textChanged(const QString);
    void on_ButtonFind_clicked();

    void on_TableWidgetGames_cellDoubleClicked(int row, int column);
    void on_TableWidgetGames_cellClicked(int row, int column);
    void on_ButtonAchievements_clicked();
    void on_ButtonFavorite_clicked();
    void on_ButtonHide_clicked();

private:
    Ui::FormGames *ui;
    QString _id;
    int _windowChildCount=0;
    SGames _games;
    SAchievementsPlayer *_achievements;
    Favorites _favorites;
    QStringList _hide;
    Settings _setting;
    QString _theme="white";
    int _achievementsCount=0;
    int _load=0;
//    QPropertyAnimation *_animate;
//    QRect _geometryGroup;
    QString _selectedGame;
    QString _selectedIndex;

    QVector<RequestData*> _request;
    int _numRequests=0;
    int _numNow=0;

};

#endif // FORMGAMES_H
