#ifndef FORMSTATISTIC_H
#define FORMSTATISTIC_H

#include <QWidget>
//#include <qcustomplot.h>

namespace Ui {
class FormStatistic;
}

class FormStatistic : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistic(QWidget *parent = nullptr);
    ~FormStatistic();

private:
    Ui::FormStatistic *ui;
};

#endif // FORMSTATISTIC_H
