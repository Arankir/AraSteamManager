#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include <QDebug>
#include "classes/common/settings.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"

enum class ReachedType {
    reached = 0,
    all = 1,
    notReached = 2,
    none
};

namespace Ui {
class FormReachedFilter;
}

class FormReachedFilter: public QWidget {
    Q_OBJECT

public:
    explicit FormReachedFilter(QWidget *parent = nullptr);
    ~FormReachedFilter();
    void setType(ReachedType);
    void update();

public slots:
    void updateSettings();
    void setIcons();
signals:
    void s_radioButtonChange(ReachedType type);

private slots:
    void changeEvent(QEvent *event);
    void slideValueChanged();

private:
    Ui::FormReachedFilter *ui;
};

#endif // FORMCOMPAREPROFILEFILTER_H
