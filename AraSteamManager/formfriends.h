#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QWidget *parent = nullptr);
    ~FormFriends();

private:
    Ui::FormFriends *ui;
};

#endif // FORMFRIENDS_H
