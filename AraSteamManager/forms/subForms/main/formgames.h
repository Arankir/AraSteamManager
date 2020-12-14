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
#include "framelesswindow.h"
#include "forms/formgroupsgamesinteractions.h"
#include "forms/formcommentsinteractions.h"
#include "classes/common/favorites.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/threads/threading.h"
#include "classes/network/requestimage.h"
#include "classes/common/myfilter.h"
#include "classes/games/hiddengames.h"
#include "subWidgets/withData/qbuttonwithdata.h"

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
    void initGroups();
    void initComments();
    void setTableModel(QStandardItemModel *aModel);

    int indexFromRow(int aRow);
    int rowFromIndex(int aIndex);
    int indexFromId(QString aId);
    int rowFromId(QString aId);

    void updateHiddenRows();
    void updateGroupsFilter();
    void showGroupsInteractive();
    void showCommentsInteractive();

    void checkBoxFavorites_StateChanged(int arg1);

    bool isInFavorites(const int &aAppId);
private:
    Ui::FormGames *ui;
    SProfile _profile;
    SGames _games;
    QVector<SAchievementsPlayer*> _achievements;

    SGame *_currentGame = nullptr;
    int _currentIndex;

    Favorites _favorites;
    MyFilter _filter;
    QList<gameData> _hide;
    GroupsGames _groups;
    Comments _comments;

    int _windowChildCount = 0;

};

#endif // FORMGAMES_H
