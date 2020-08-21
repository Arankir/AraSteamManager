#ifndef FORMCATEGORYVALUE_2_H
#define FORMCATEGORYVALUE_2_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class FormCategoryValue_2;
}

class FormCategoryValue_2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormCategoryValue_2(QWidget *parent = nullptr);
    ~FormCategoryValue_2();

private slots:
    void on_ButtonDelete_clicked();

private:
    Ui::FormCategoryValue_2 *ui;
};

#endif // FORMCATEGORYVALUE_2_H
