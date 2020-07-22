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
    void onFinish();

    void showHideSlideWidget(bool f_flag);
    void mouseMoveEvent(QMouseEvent *ev);
    void enableMouseTracking(const QObjectList &aChildren);

    bool eventFilter(QObject *obj, QEvent *event);
    void updateSettings();
public:
    explicit FormGames(SProfile profile, SGames Games, QWidget *parent = nullptr);
    ~FormGames();

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int,int);
    void s_finish(int width);
    void s_showAchievements(SAchievementsPlayer achievements,SGame games);

private slots:
    void changeEvent(QEvent *event);
    void initComponents();
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
    void createThread();

private:
    Ui::FormGames *ui;
    SProfile _profile;
    int _windowChildCount = 0;
    SGames _games;
    SAchievementsPlayer *_achievements;
    Favorites _favorites;
    QStringList _hide;
    Settings _setting;
    int _load = 0;

    QPropertyAnimation *_animate;

    const int c_widthVisibleGroup = 20;
    const QPoint c_invisibleGroupPos = QPoint(-280, 0);
    const QPoint c_visibleGroupPos = QPoint(20, 0);
    const int c_widthGroup = 300;
    bool _isGroupShow = false;

    QString _selectedGame;
    QString _selectedIndex;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;

};

#endif // FORMGAMES_H