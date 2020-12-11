#ifndef FORMACHIEVEMENTWIDGET_H
#define FORMACHIEVEMENTWIDGET_H

#include <QWidget>
#include "class/steamapi/Sachievements.h"

namespace Ui {
class FormAchievementWidget;
}

class FormAchievementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievementWidget(SAchievement *achievement, int gameId, QWidget *parent = nullptr);
    ~FormAchievementWidget();

private:
    Ui::FormAchievementWidget *ui;
    SAchievement *_achievement;
    int _gameId;
};

#endif // FORMACHIEVEMENTWIDGET_H
