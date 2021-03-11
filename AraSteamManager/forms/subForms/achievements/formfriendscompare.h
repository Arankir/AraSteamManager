#ifndef FORMACHIEVEMENTSFRIENDSCOMPARE_H
#define FORMACHIEVEMENTSFRIENDSCOMPARE_H

#include <QWidget>
#include <QLabel>
#include <QStandardItemModel>
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/myfilter.h"
#include "forms/subForms/achievements/widgets/formreachedfilter.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/items/qlistwidgetfriend.h"

enum tableAchievementsFriendsCompareColumns {
    ColumnAppid         = 0,
    ColumnIndex         = 1,
    ColumnIcon          = 2,
    ColumnTitle         = 3,
    ColumnDescription   = 4,
    ColumnComment       = 5,
    ColumnWorld         = 6,
    ColumnReachedMy     = 7,
    ColumnCount         = 8
};

namespace Ui {
class FormFriendsCompare;
}

class FormFriendsCompare : public QWidget {
    Q_OBJECT

public slots:
    void setInitData(SProfile &profile, SGame &game, QList<SAchievement> &achievements, QStandardItemModel *model, MyFilter *fAchievements);
    void setAchievedColors(QColor aAchieved, QColor aNotAchieved);
    void addFriendToList(SProfile *steamFriend);
    void removeFriendFromCompare();
    void updateHiddenRows();

public:
    explicit FormFriendsCompare(QWidget *parent = nullptr);
    ~FormFriendsCompare();

signals:
    void s_updateSettings();
    void s_progressLoad(int, int);
    void s_finishLoad();
    void s_addedFriend();

private slots:
    void setIcons();
    void initTableCompare();
    void updateFilterFriend(SProfile *aFriendName, ReachedType aType);
    void loadingCompare();
    void loadFriendGames(QList<SGame> aGames, const QString &aUserId);
    int rowFromId(QString aId);
    float addFriendColumn(SProfile &aSteamFriend);
    bool removeFriendColumn(SProfile &aSteamFriend);
    void updateCurrentAchievement();
    void setFriendsAll();
    void setFriendsReached();
    void setFriendsNotReached();
    void changeEvent(QEvent *event);
    void retranslate();

private:
    Ui::FormFriendsCompare *ui;
    QList<SAchievement> _achievements;

    //ключевые данные
    SProfile _profile;
    SGame _game;

    //сравнение с друзьями
    int _loadCompare = 0;
    int _type1 = 0;
    int _type2 = 0;
    QList<SProfile> _profilesFriends;
    //QList<QPair<SProfile, FriendType>> _friends;

    QList<SProfile> _friendColumns;

    MyFilter _fCompare;
    MyFilter *_fAchievements = nullptr;

    //выбранное достижение
    SAchievement *_currentAchievement = nullptr;
    int _currentAchievementIndex;

    QColor _achievedColor;
    QColor _notAchievedColor;

};

#endif // FORMACHIEVEMENTSFRIENDSCOMPARE_H
