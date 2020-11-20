#ifndef FORMACHIEVEMENTSFRIENDSCOMPARE_H
#define FORMACHIEVEMENTSFRIENDSCOMPARE_H

#include <QWidget>

namespace Ui {
class FormAchievementsFriendsCompare;
}

class FormAchievementsFriendsCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievementsFriendsCompare(QWidget *parent = nullptr);
    ~FormAchievementsFriendsCompare();

private:
    Ui::FormAchievementsFriendsCompare *ui;
};

#endif // FORMACHIEVEMENTSFRIENDSCOMPARE_H
