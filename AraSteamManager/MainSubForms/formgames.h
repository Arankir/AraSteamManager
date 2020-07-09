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
#include <class/Network/requestimage.h>
#include <subwidget/qbuttonwithdata.h>
#include <QList>
#include <QPropertyAnimation>
#include <QMouseEvent>

namespace Ui {
class FormGames;
}

class FormGames : public QWidget {
    Q_OBJECT

public slots:
    void progressLoading(int, int);
    void onFinish();

    void showHideSlideWidget(bool f_flag);
    void mouseMoveEvent(QMouseEvent *ev);
    void slotShowHideSlide();

public:
    explicit FormGames(QString id, SGames Games, QWidget *parent = nullptr);
    ~FormGames();

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int,int);
    void s_finish(int width);
    void s_showAchievements(SAchievementsPlayer achievements,SGame games);

private slots:
    void changeEvent(QEvent *event);
    void initComponents();
    void updateTheme();
    void setIcons();
    void retranslate();
    void onResultAchievements(SAchievementsPlayer ach);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);

    void lineEditGame_TextChanged(const QString);
    void buttonFind_Clicked();

    void tableWidgetGames_CellDoubleClicked(int row, int column);
    void tableWidgetGames_CellClicked(int row, int column);
    void buttonAchievements_Clicked();
    void buttonFavorite_Clicked();
    void buttonHide_Clicked();

private:
    Ui::FormGames *ui;
    QString _id;
    int _windowChildCount = 0;
    SGames _games;
    SAchievementsPlayer *_achievements;
    Favorites _favorites;
    QStringList _hide;
    Settings _setting;
    QString _theme = "white";
    int _load = 0;
    QPropertyAnimation *_animate;
    QRect _geometryGroup;
    QString _selectedGame;
    QString _selectedIndex;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;

};

#endif // FORMGAMES_H
