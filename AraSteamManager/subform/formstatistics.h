#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistics(QWidget *parent = nullptr);
    ~FormStatistics();

private:
    Ui::FormStatistics *ui;
};

#endif // FORMSTATISTICS_H
