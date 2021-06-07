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

namespace Ui {
class FormGames;
}

class FormGames : public Form {
    Q_OBJECT

public slots:
    void updateSettings() override;
    void setGames(const SProfile &aProfile, SGames &aGames);
    bool isInit() {return ((_profile.steamID() != "") && (_filterGames.sourceModel()->rowCount() > 0));}
    void clear();

public:
    FormGames(QWidget *aParent = nullptr);
    ~FormGames();

signals:
    void s_achievementsLoaded(int);
    void s_finish(int width);
    void s_showAchievements(const SGame &games);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;

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

    int currentIndex();
    void setEnable(bool isEnable);
private:
    Ui::FormGames *ui;
    SProfile _profile;
    QList<HiddenGame> _hide;
    GroupsGames _groups;

    ProxyModelGames _filterGames;

};

#endif // FORMGAMES_H
