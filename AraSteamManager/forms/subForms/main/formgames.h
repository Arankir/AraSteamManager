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
#include "forms/formgroups.h"
#include "forms/formcomments.h"
#include "classes/common/generalfunctions.h"
#include "classes/common/myfilter.h"
#include "classes/common/favorites.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/threads/threading.h"
#include "classes/network/requestimage.h"
#include "classes/games/hiddengames.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/progressBars/progressbarbad.h"
#include "subWidgets/progressBars/progressbargood.h"

enum tableGamesColumns {
    ColumnGamesAppid    = 0,
    ColumnGamesIndex    = 1,
    ColumnGamesIcon     = 2,
    ColumnGamesName     = 3,
    ColumnGamesComment  = 4,
    ColumnGamesProgress = 5,
    ColumnGamesCount    = 6
};

enum filterGamesColumns {
    FilterGamesName        = 0,
    FilterGamesHide        = 1,
    FilterGamesGroup       = 2,
    FilterGamesFavorites   = 3,
    FilterGamesCount       = 4
};

namespace Ui {
class FormGames;
}

class FormGames : public QWidget {
    Q_OBJECT

public slots:
    void updateSettings();
    void setGames(SProfile &aProfile, QList<SGame> &aGames);
    bool isInit() {return ((_games.count() > 0) && (_filter.getRow() > 0) && (_loaded));}
    bool isLoaded() {return _loaded;}
    void clear();

public:
    //explicit FormGames(SProfile &profile, SGames &Games, QWidget *parent = nullptr);
    FormGames(QWidget *aParent = nullptr);
    ~FormGames();

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int);
    void s_finish(int width);
    void s_showAchievements(QList<SAchievementPlayer> &achievements, SGame &games);

private slots:
    void init();
    void changeEvent(QEvent *event);
    void setIcons();
    void retranslate();
    void onResultAchievements(QList<SAchievementPlayer> aAchievements, QString aAppId);
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
    void updateGroups(SProfile profile);
    void initComments();
    void setTableModel(QStandardItemModel *aModel);

    int indexFromRow(int aRow);
    int rowFromIndex(int aIndex);
    int indexFromId(QString aId);
    int rowFromId(QString aId);

    void updateHiddenRows();
    void updateGroupsFilter();
    void showGroupsEdit();
    void showCommentsEdit();

    void checkBoxFavorites_StateChanged(int arg1);

    bool isInFavorites(const int &aAppId);
    void resizeTableColumns();
private:
    Ui::FormGames *ui;
    SProfile _profile;
    QList<SGame> _games;
    QVector<QList<SAchievementPlayer>> _achievements;

    SGame *_currentGame = nullptr;
    int _currentIndex;

    Favorites _favorites;
    MyFilter _filter;
    QList<gameData> _hide;
    GroupsGames _groups;
    Comments _comments;

    bool _loaded = false;

    int _windowChildCount = 0;

};

#endif // FORMGAMES_H
