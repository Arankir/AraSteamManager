#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QMenu>

#include "classes/steamApi/structures/sfriends.h"
#include "classes/threads/thread/threadfriends.h"
#include "classes/common/favorites.h"
#include "classes/common/myfilter.h"
#include "subWidgets/models/friendsmodel.h"
#include <QSortFilterProxyModel>

namespace Ui {
class FormFriends;
}

class FormFriends : public Form {
    Q_OBJECT

public slots:
    void updateSettings() override;
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
    void initComboBoxStatus();
    //Эвенты
    void closeEvent(QCloseEvent *event) override;
    //Часто использующиеся функции
    void retranslate() override;
    void updateIcons() override;
    QPair<SFriend, SProfile> currentFriend();
    bool isProfileFavorite(const QPair<SFriend, SProfile> &aProfile);
    //Взаимодействие с таблицей
    QMenu *createMenu(const QPair<SFriend, SProfile> &profile);
    void goToCurrentProfile();
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

    bool _blockedLoad = false;
    bool _loaded = false;

    Favorites _favorites;

    FriendsModel *_friendsModel = nullptr;
    QSortFilterProxyModel _filterName;
    QSortFilterProxyModel _filterStatus;
    QSortFilterProxyModel _filterPublic;
    QSortFilterProxyModel _filterFavorite;

};

#endif // FORMFRIENDS_H
