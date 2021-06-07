#ifndef FORMCOMMENTSINTERACTIONS_H
#define FORMCOMMENTSINTERACTIONS_H

#include <QWidget>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/comments.h"

namespace Ui {
class FormComments;
}

class FormComments : public Form
{
    Q_OBJECT

public:
    explicit FormComments(QWidget *parent = nullptr);;
    explicit FormComments(const SProfile &profile, const SGame &game, const SAchievement &achievement = SAchievement(), QWidget *parent = nullptr);
    void setData(const SProfile &aProfile, const SGame &aGame, const SAchievement &aAchievement = SAchievement());
    ~FormComments();

signals:
    void s_updateComments();

private slots:
    void init();

    void on_ButtonCancel_clicked();

    void on_ButtonApply_clicked();

    void retranslate() override;
    void updateIcons() override;
    void updateSettings() override;

private:
    Ui::FormComments *ui;
    SGame _game;
    SAchievement _achievement;
    SProfile _profile;
};

#endif // FORMCOMMENTSINTERACTIONS_H
