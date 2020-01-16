#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>

namespace Ui {
class FormCompareProfileFilter;
}

class FormCompareProfileFilter : public QWidget
{
    Q_OBJECT

public:
    explicit FormCompareProfileFilter(QWidget *parent = nullptr);
    ~FormCompareProfileFilter();

private:
    Ui::FormCompareProfileFilter *ui;
};

#endif // FORMCOMPAREPROFILEFILTER_H
