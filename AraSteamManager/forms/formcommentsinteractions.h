#ifndef FORMCOMMENTSINTERACTIONS_H
#define FORMCOMMENTSINTERACTIONS_H

#include <QWidget>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/comments.h"

namespace Ui {
class FormCommentsInteractions;
}

class FormCommentsInteractions : public QWidget
{
    Q_OBJECT

public:
    explicit FormCommentsInteractions(const SProfile &profile, const SGame &game, SAchievement *achievement = nullptr, QWidget *parent = nullptr);
    ~FormCommentsInteractions();

signals:
    void s_updateComments(bool);

private slots:
    void init();

    void on_ButtonCancel_clicked();

    void on_ButtonApply_clicked();

private:
    Ui::FormCommentsInteractions *ui;
    SGame _game;
    SAchievement *_achievement;
    SProfile _profile;

    Comments _comment;
};

#endif // FORMCOMMENTSINTERACTIONS_H
