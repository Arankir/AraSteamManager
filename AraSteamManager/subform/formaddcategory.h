#ifndef FORMADDCATEGORY_H
#define FORMADDCATEGORY_H

#include <QWidget>
#include <class/settings.h>

namespace Ui {
class FormAddCategory;
}

class FormAddCategory : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddCategory(QWidget *parent = nullptr);
    ~FormAddCategory();

private:
    Ui::FormAddCategory *ui;
    QStringList Words;
    Settings Setting;
    QString theme="white";
};

#endif // FORMADDCATEGORY_H
