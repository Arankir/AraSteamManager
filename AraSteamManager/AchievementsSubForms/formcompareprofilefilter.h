#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include "class/settings.h"
#include "subwidget/qradiobuttonwithdata.h"
#include <QDebug>

namespace Ui {
class FormCompareProfileFilter;
}

class FormCompareProfileFilter: public QWidget {
    Q_OBJECT

public:
    explicit FormCompareProfileFilter(QWidget *parent = nullptr);
    explicit FormCompareProfileFilter(const QString &all, const QString &reached, const QString &notReached, QWidget *parent = nullptr);
    ~FormCompareProfileFilter();
    void setName(const QString &name);
    void setIndex(const QString &index);
    void setTitles(const QString &titleAll, const QString &titleReached, const QString &titleNotReached);
    QString getName();
    QString getIndex();
    void setType(ReachedType);
    void update();

public slots:
    void updateSettings();
    void setIcons();
signals:
    void s_radioButtonChange(const QString &name, ReachedType type);

private slots:
    void changeEvent(QEvent *event);
    void radioButtonClick();

private:
    Ui::FormCompareProfileFilter *ui;
    Settings _setting;
    QString _name;
    QString _index;
};

#endif // FORMCOMPAREPROFILEFILTER_H
