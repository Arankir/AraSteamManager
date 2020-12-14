#ifndef FORMACHIEVEMENTSFRIENDSCOMPARE_H
#define FORMACHIEVEMENTSFRIENDSCOMPARE_H

#include <QWidget>
#include <QLabel>
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/myfilter.h"
#include "forms/subForms/achievements/formcompareprofilefilter.h"
#include "subWidgets/withData/qbuttonwithdata.h"

enum FriendType {
    haventGame,
    haveGame
};

namespace Ui {
class FormAchievementsFriendsCompare;
}

class FormFriendsCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriendsCompare(QWidget *parent = nullptr);
    ~FormFriendsCompare();

signals:
    void s_updateSettings();

private slots:
    void setIcons();
    QButtonWithData *createButtonWithData(const QString &aObjectName, const QString &aAppertain, const QString &aType, bool aChecked);
    void initTableCompare();
    void updateFilterWithFriend(const QString &aFriendName, ReachedType aType);
    void loadingCompare();
    void loadFriendGames(SGames *aGames);
    void finishLoadFriends();
    void compareProfileFilterClickFriends(const QString &aName, ReachedType aType);
    void buttonCompareAllFriendsReach_Clicked();
    void tableWidgetCompareFriends_CellChanged(int aRow, int aColumn);
    void createCompareProfileFilter(bool aAccept, int aColumn);
    void checkBoxCompareAllFriends_StateChanged(int arg1);
private:
    Ui::FormAchievementsFriendsCompare *ui;
    SAchievements _achievements;

    //ключевые данные
    SProfile _profile;
    SGame _game;

    //сравнение с друзьями
    int _loadCompare = 0;
    int _type1 = 0;
    int _type2 = 0;
    SProfiles _profilesFriends;
    QList<QPair<SProfile, FriendType>> _friends;

    MyFilter _fCompare;

};

#endif // FORMACHIEVEMENTSFRIENDSCOMPARE_H
