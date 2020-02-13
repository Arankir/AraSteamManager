#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>

namespace Ui {
class FormProfile;
}

class FormProfile : public QWidget
{
    Q_OBJECT

public:
    explicit FormProfile(QWidget *parent = nullptr);
    ~FormProfile();

private:
    Ui::FormProfile *ui;
};

#endif // FORMPROFILE_H
