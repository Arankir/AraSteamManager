#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QMenu>

#include "classes/steamApi/structures/sfriends.h"
#include "classes/threads/threading.h"
#include "classes/common/favorites.h"
#include "classes/common/myfilter.h"

enum tableFriendsColumns {
    ColumnFriendsID        = 0,
    ColumnFriendsIndex     = 1,
    ColumnFriendsIcon      = 2,
    ColumnFriendsName      = 3,
    ColumnFriendsAdded     = 4,
    ColumnFriendsStatus    = 5,
    ColumnFriendsIsPublic  = 6,
    ColumnFriendsCount     = 7
};

enum filterFriendsColumns {
    FilterFriendsName      = 0,
    FilterFriendsStatus    = 1,
    FilterFriendsPublic    = 2,
    FilterFriendsFavorites = 3,
    FilterFriendsCount     = 4
};

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget {
    Q_OBJECT

public slots:
    void updateSettings();
    void setFriends(const QString &aId, QList<SFriend> &aFriends);
    void clear();
    bool isInit();
    bool isLoaded();

public:
    explicit FormFriends(const QString &id, QList<SFriend> &Friends, QWidget *parent = nullptr);
    FormFriends(QWidget *aParent = nullptr);
    ~FormFriends();

signals:
    void s_friendsLoaded(int progress);
    void s_finish();
    void s_returnToProfile(QWidget*);
    void s_goToProfile(const QString &id, SProfileRequestType type);

private slots:
    //Инициализация
    void init();
    void initFriends(QList<SFriend> &aFriends);
    void initTable();
    void initComboBoxStatus();
    //Доподгрузка данных
    void createThread();
    void setTableModel(QStandardItemModel *aModel);
    //Эвенты
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);
    //Часто использующиеся функции
    void retranslate();
    void setIcons();
    void updateHiddenRows();
    void updateCurrentFriend();
    QPair<SFriend, SProfile> *getFriendFromRow(int aRow);
    int getCurrentFriendIndex();
    int getIndexFriendFromRow(int aRow);
    int getRowFromIndexFriend(int aIndex);
    bool isProfileFavorite(const QPair<SFriend, SProfile> &aProfile);
    //Взаимодействие с таблицей
    QMenu *createMenu(const QPair<SFriend, SProfile> &profile);
    void updateActionFavoriteData(QAction *aAction, bool aIsFavorite);
    void goToProfile();
    void friendToFavorite();
    //Фильтр
    void checkBoxOpenProfile_StateChanged(int arg1);
    void lineEditName_TextChanged(const QString &arg1);
    void buttonFind_Clicked();
    void comboBoxStatus_Activated(int index);
    void checkBoxFavorites_StateChanged(int arg1);

private:
    Ui::FormFriends *ui;

    QString _id;
    QList<QPair<SFriend, SProfile>> _friends;
    QPair<SFriend, SProfile> *_currentFriend = nullptr;

    bool _blockedLoad = false;
    bool _loaded = false;

    Favorites _favorites;
    MyFilter _filter;

};

#endif // FORMFRIENDS_H
