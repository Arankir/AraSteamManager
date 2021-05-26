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
#include "subWidgets/models/achievementsmodel.h"

namespace Ui {
class FormFriendsCompare;
}

class FormFriendsCompare : public QWidget {
    Q_OBJECT

public slots:
    void setInitData(SProfile &profile, SGame &game, AchievementsModel *achievementsModel);
    void addFriendToList(SProfile &steamFriend);
    void setModel(QAbstractItemModel *model);
    void filtersValueUpdated();

public:
    explicit FormFriendsCompare(QWidget *parent = nullptr);
    ~FormFriendsCompare();

signals:
    void s_updateSettings();
    void s_startLoad(int max);
    void s_progressLoad(int value, int max);
    void s_finishLoad();
    void s_addedFriend();

private slots:
    void setIcons();
    void updateFilterFriend(SProfile *aFriendName, const ReachedType &aType);
    void loadingCompare();
    void loadFriendGames(const SGames &aGames, const QString &aUserId);
    int addFriendColumn(const SProfile &aSteamFriend);
    bool removeFriendColumn(const SProfile &aSteamFriend);
    void setFriendsAll();
    void setFriendsReached();
    void setFriendsNotReached();
    void changeEvent(QEvent *event);
    void retranslate();
    void setAllFriendsValue(const ReachedType &aType);
    void updateFiltersFriends();

private:
    Ui::FormFriendsCompare *ui;

    //ключевые данные
    SProfile _profile;
    SGame _game;

    //сравнение с друзьями
    int _loadCompare = 0;
    QList<SProfile> _profilesFriends;

    AchievementsModel *_achievementsModel;
    QAbstractItemModel *_model;
    QList<QSortFilterProxyModel*> _filtersFriends;

};

#endif // FORMACHIEVEMENTSFRIENDSCOMPARE_H
