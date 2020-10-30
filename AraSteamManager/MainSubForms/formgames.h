#ifndef FORMGAMES_H
#define FORMGAMES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QList>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QAction>
#include <QMenu>
#include "formgroupsgamesinteractions.h"
#include "formcommentsinteractions.h"
#include "class/favorites.h"
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sachievements.h"
#include "class/Threads/threading.h"
#include "class/Network/requestimage.h"
#include "class/filter.h"
#include "subwidget/qbuttonwithdata.h"

namespace Ui {
class FormGames;
}

class FormGames : public QWidget {
    Q_OBJECT

public slots:
    void updateSettings();

public:
    explicit FormGames(SProfile &profile, SGames &Games, QWidget *parent = nullptr);
    ~FormGames();

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int,int);
    void s_finish(int width);
    void s_showAchievements(SAchievementsPlayer &achievements, SGame &games);

private slots:
    void changeEvent(QEvent *event);
    void initComponents();
    void setIcons();
    void retranslate();
    void onResultAchievements(SAchievementsPlayer *ach);
    void closeEvent(QCloseEvent *event);

    void lineEditGame_TextChanged(const QString &aFindText);
    void buttonFind_Clicked();

    void buttonAchievements_Clicked();
    void buttonFavorite_Clicked();
    void buttonHide_Clicked();
    void createThread();

    QMenu *createMenu(SGame &game);
    void updateHiddenGames();
    void updateCurrentGame();
    void initTable();
    void setTableModel(QStandardItemModel *aModel);
    int getIndexGameFromRow(int aRow);
    int getRowFromIndexGame(int aIndex);
    int getIndexGameFromIdGame(QString aId);
    void updateHiddenRows();
    void updateHideFromFile(const QString &aFile);
    void initGroups();
    void updateGroupsFilter();
    void showGroupsInteractive();
    void showCommentsInteractive();
    int getRowFromIdGame(QString aId);
private:
    Ui::FormGames *ui;
    SProfile _profile;
    SGames _games;
    QVector<SAchievementsPlayer*> _achievements;

    SGame *_currentGame = nullptr;
    int _currentIndex;

    Favorites _favorites;
    Filter _filter;
    QStringList _hide;
    GroupsGames _groups;

    int _windowChildCount = 0;

};

#endif // FORMGAMES_H
