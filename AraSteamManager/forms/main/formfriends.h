#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include "subWidgets/models/friendsmodel.h"

namespace Ui {
class FormFriends;
}

class FormFriends : public Form {
    Q_OBJECT

public slots:
//    void updateSettings(QFlags<changedSettings> settings) override;
    void setFriends(const ProfileID &profileId);
    void clear();
    bool isInit();

public:
    explicit FormFriends(QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void s_finish(int width);
    void s_goToProfile(const ProfileID &profileId);

private slots:
    //Инициализация
    void init();
    void initComboBoxStatus();
    //Часто использующиеся функции
    void retranslate() override;
    void updateIcons() override;
    SFriendProfile currentFriend();
    //Взаимодействие с таблицей
    QMenu *createMenu(const SFriendProfile &profile);
    void goToCurrentProfile();
    //Фильтр
    void lineEditName_TextChanged(const QString &arg1);
    void buttonFind_Clicked();
    void comboBoxStatus_Activated(int index);
    void checkBoxFavorites_StateChanged(int arg1);

private:
    Ui::FormFriends *ui;

    ProfileID id_;
    bool isLoading_ = false;

    FilterModelFriends filterFriends_;
};

#endif // FORMFRIENDS_H
