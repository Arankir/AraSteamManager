#ifndef FORMCOMMENTSINTERACTIONS_H
#define FORMCOMMENTSINTERACTIONS_H

#include <QWidget>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/files/comments.h"

namespace Ui {
class FormComments;
}

class FormComments : public Form
{
    Q_OBJECT

public:
    explicit FormComments(QWidget *parent = nullptr);;
    explicit FormComments(const ProfileID &aId, const SGame &game, const SAchievement &achievement = SAchievement(), QWidget *parent = nullptr);
    void setData(const ProfileID &aId, const SGame &aGame, const SAchievement &aAchievement = SAchievement());
    ~FormComments();

signals:
    void s_updateComments();

private slots:
    void init();

    void on_ButtonCancel_clicked();

    void on_ButtonApply_clicked();

    void retranslate() override;
    void updateIcons() override;
//    void updateSettings(QFlags<changedSettings> aSettings) override;

private:
    Ui::FormComments *ui;
    SGame _game;
    SAchievement _achievement;
    ProfileID _profile;
};

#endif // FORMCOMMENTSINTERACTIONS_H
