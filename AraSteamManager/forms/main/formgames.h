#ifndef FORMGAMES_H
#define FORMGAMES_H

#include "form.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "subWidgets/models/gamesmodel.h"

namespace Ui {
class FormGames;
}

class FormGames : public Form {
    Q_OBJECT

public slots:
    void updateSettings(QFlags<changedSettings> settings) override;
    void setGames(const ProfileID &profileId);
    void setGames(const ProfileID &profileId, const SGames &games);
    bool isInit();
    void clear();

    SGames currentGames();
public:
    FormGames(QWidget *parent = nullptr);
    ~FormGames();

signals:
//    void s_achievementsLoaded(const QString&, int , int);
    void s_finish(int width);
    void s_showAchievements(const SGame &games);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;

    void lineEditGame_TextChanged(const QString &findText);
    void buttonFind_Clicked();

    void buttonAchievements_Clicked();

    QMenu *createMenu(const SGame &game);
    SGame currentGame();
    QStringList currentComment();
    QList<SAchievementPlayer> currentAchievements();
    void updateGroups();

    void updateGroupsFilter();
    void showGroupsEdit();
    void showCommentsEdit();

    void checkBoxFavorites_StateChanged(int state);

    int currentIndex();
    void setEnable(bool isEnable);
private:
    Ui::FormGames *ui;
    ProfileID profileId_;
//    FilterModelGames filterGames_;

};

#endif // FORMGAMES_H
