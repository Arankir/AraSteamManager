#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include <QDebug>
#include "classes/common/settings.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"
#include "form.h"

enum class ReachedType {
    reached = 0,
    all = 1,
    notReached = 2,
    none
};

namespace Ui {
class FormReachedFilter;
}

class FormReachedFilter: public Form {
    Q_OBJECT

public:
    explicit FormReachedFilter(QWidget *parent = nullptr);
    ~FormReachedFilter();
    void setType(const ReachedType&);
    void update();

public slots:
    void updateSettings() override;

signals:
    void s_radioButtonChange(const ReachedType &type);

private slots:
    void updateIcons() override;
    void retranslate() override;;
    void slideValueChanged();

private:
    Ui::FormReachedFilter *ui;
};

#endif // FORMCOMPAREPROFILEFILTER_H
