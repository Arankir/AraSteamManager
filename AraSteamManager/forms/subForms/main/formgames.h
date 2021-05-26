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
#include "classes/threads/thread/threadgames.h"
#include "classes/network/requestimage.h"
#include "classes/games/hiddengames.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/progressBars/progressbarbad.h"
#include "subWidgets/progressBars/progressbargood.h"
#include "subWidgets/models/gamesmodel.h"
#include "subWidgets/models/filters.h"

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

class FormGames : public Form {
    Q_OBJECT

public slots:
    void updateSettings() override;
    void setGames(SProfile &aProfile, SGames &aGames);
    bool isInit() {return ((_loaded) && (_gamesModel->rowCount() > 0));}
    bool isLoaded() {return _loaded;}
    void clear();

public:
    FormGames(QWidget *aParent = nullptr);
    ~FormGames();

signals:
    void s_return_to_profile(QWidget*);
    void s_achievementsLoaded(int);
    void s_finish(int width);
    void s_showAchievements(/*const QList<SAchievementPlayer> &achievements, */const SGame &games);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;
    void closeEvent(QCloseEvent *event) override;

    void lineEditGame_TextChanged(const QString &aFindText);
    void buttonFind_Clicked();

    void buttonAchievements_Clicked();
    void buttonFavorite_Clicked();
    void buttonHide_Clicked();

    QMenu *createMenu(const SGame &game);
    void updateHiddenGames();
    SGame currentGame();
    QStringList currentComment();
    QList<SAchievementPlayer> currentAchievements();
    void updateGroups(const SProfile &profile);

    void updateGroupsFilter();
    void showGroupsEdit();
    void showCommentsEdit();

    void checkBoxFavorites_StateChanged(int arg1);

    bool isInFavorites(const int &aAppId);
private:
    Ui::FormGames *ui;
    SProfile _profile;
    Favorites _favorites;
    QList<HiddenGame> _hide;
    GroupsGames _groups;

    bool _loaded = false;

    GamesModel *_gamesModel = nullptr;
    QSortFilterProxyModel _filterName;
    QSortFilterProxyInvertModel _filterHide;
    QSortFilterProxyModel _filterGroup;
    QSortFilterProxyModel _filterFavorite;

};

#endif // FORMGAMES_H
