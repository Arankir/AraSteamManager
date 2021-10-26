#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QMenu>

#include "classes/steamApi/structures/sfriends.h"
#include "classes/threads/thread/threadfriends.h"
#include "classes/common/favorites.h"
#include "classes/common/myfilter.h"
#include "subWidgets/models/friendsmodel.h"

namespace Ui {
class FormFriends;
}

class FormFriends : public Form {
    Q_OBJECT

public slots:
    void updateSettings(QFlags<changedSettings> aSettings) override;
    void setFriends(const QString &aId, const SFriends &aFriends);
    void clear();
    bool isInit();

public:
    explicit FormFriends(const QString &id, SFriends &Friends, QWidget *parent = nullptr);
    FormFriends(QWidget *aParent = nullptr);
    ~FormFriends();

signals:
    void s_friendsLoaded(const QString &aStatus, int aValue, int aMaxValue);
    void s_finish(int width);
    void s_returnToProfile(QWidget*);
    void s_goToProfile(const QString &id, SProfile::LoadType type);

private slots:
    //Инициализация
    void init();
    void initComboBoxStatus();
    //Эвенты
    void closeEvent(QCloseEvent *event) override;
    //Часто использующиеся функции
    void retranslate() override;
    void updateIcons() override;
    SFriendProfile currentFriend();
    //Взаимодействие с таблицей
    QMenu *createMenu(const SFriendProfile &profile);
    void goToCurrentProfile();
    void friendToFavorite();
    //Фильтр
    void lineEditName_TextChanged(const QString &arg1);
    void buttonFind_Clicked();
    void comboBoxStatus_Activated(int index);
    void checkBoxFavorites_StateChanged(int arg1);

private:
    Ui::FormFriends *ui;

    QString _id;

    bool _isLoading = false;

//    FriendsModel *_friendsModel = nullptr;
    ProxyModelFriends _filterFriends;
};

#endif // FORMFRIENDS_H
