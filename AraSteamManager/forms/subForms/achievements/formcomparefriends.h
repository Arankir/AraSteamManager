#ifndef FORMCOMPAREFRIENDS_H
#define FORMCOMPAREFRIENDS_H

#include <QWidget>

namespace Ui {
class FormCompareFriends;
}

class FormCompareFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormCompareFriends(QWidget *parent = nullptr);
    ~FormCompareFriends();

private:
    Ui::FormCompareFriends *ui;
};

#endif // FORMCOMPAREFRIENDS_H
