#ifndef FORMACHIEVEMENTSFRIENDSCOMPARE_H
#define FORMACHIEVEMENTSFRIENDSCOMPARE_H

#include <QWidget>
#include <QLabel>
#include "class/steamapi/Sachievements.h"
#include "class/steamapi/Sprofile.h"
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sfriends.h"
#include "AchievementsSubForms/formcompareprofilefilter.h"
#include "subwidget/qbuttonwithdata.h"

enum FriendType {
    haventGame,
    haveGame
};

namespace Ui {
class FormAchievementsFriendsCompare;
}

class FormAchievementsFriendsCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievementsFriendsCompare(QWidget *parent = nullptr);
    ~FormAchievementsFriendsCompare();

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

};

#endif // FORMACHIEVEMENTSFRIENDSCOMPARE_H
