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
#include "classes/files/favorites.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/threads/thread/threadgames.h"
#include "classes/network/requestimage.h"
#include "classes/files/hiddengames.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/progressBars/progressbarbad.h"
#include "subWidgets/progressBars/progressbargood.h"
#include "subWidgets/models/gamesmodel.h"
#include "subWidgets/delegates/progressbardelegate.h"

namespace Ui {
class FormGames;
}

class FormGames : public Form {
    Q_OBJECT

public slots:
    void updateSettings(QFlags<changedSettings> aSettings) override;
    void setGames(const ProfileID &profileId);
    void setGames(const ProfileID &aProfileId, const SGames &aGames);
    bool isInit();
    void clear();

    SGames currentGames();
public:
    FormGames(QWidget *aParent = nullptr);
    ~FormGames();

signals:
    void s_achievementsLoaded(const QString&, int, int);
    void s_finish(int width);
    void s_showAchievements(const SGame &games);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;

    void lineEditGame_TextChanged(const QString &aFindText);
    void buttonFind_Clicked();

    void buttonAchievements_Clicked();
    void buttonHide_Clicked();

    QMenu *createMenu(const SGame &game);
    void updateHiddenGames();
    SGame currentGame();
    QStringList currentComment();
    QList<SAchievementPlayer> currentAchievements();
    void updateGroups();

    void updateGroupsFilter();
    void showGroupsEdit();
    void showCommentsEdit();

    void checkBoxFavorites_StateChanged(int arg1);

    int currentIndex();
    void setEnable(bool isEnable);
private:
    Ui::FormGames *ui;
    ProfileID _steamId;
    FilterModelGames _filterGames;

};

#endif // FORMGAMES_H
