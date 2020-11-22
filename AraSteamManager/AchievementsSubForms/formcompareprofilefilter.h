#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include "class/settings.h"
#include "subwidget/qradiobuttonwithdata.h"
#include <QDebug>

enum class ReachedType {
    reached = 0,
    all = 1,
    notReached = 2,
    none
};

namespace Ui {
class FormCompareProfileFilter;
}

class FormCompareProfileFilter: public QWidget {
    Q_OBJECT

public:
    explicit FormCompareProfileFilter(QWidget *parent = nullptr);
    ~FormCompareProfileFilter();
    void setName(const QString &name) {_name = name;}
    void setIndex(const QString &index) {_index = index;}
    QString getName() {return _name;}
    QString getIndex() {return _index;}
    void setType(ReachedType);
    void update();

public slots:
    void updateSettings();
    void setIcons();
signals:
    void s_radioButtonChange(const QString &name, ReachedType type);

private slots:
    void changeEvent(QEvent *event);
    void slideValueChanged();

private:
    Ui::FormCompareProfileFilter *ui;
    QString _name;
    QString _index;
};

#endif // FORMCOMPAREPROFILEFILTER_H
