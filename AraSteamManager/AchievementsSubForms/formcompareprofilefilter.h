#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include <class/settings.h>
#include <subwidget/qradiobuttonwithdata.h>
#include <QDebug>

namespace Ui {
class FormCompareProfileFilter;
}

class FormCompareProfileFilter: public QWidget {
    Q_OBJECT

public:
    explicit FormCompareProfileFilter(QWidget *parent = nullptr);
    explicit FormCompareProfileFilter(QString, QString, QString, QWidget *parent = nullptr);
    ~FormCompareProfileFilter();
    void setName(QString Aname);
    void setIndex(QString Aindex);
    void setTitles(QString titleAll, QString titleReached, QString titleNotReached);
    QString getName();
    QString getIndex();
    void setType(ReachedType);
    void update();

signals:
    void s_radioButtonChange(QString name, ReachedType type);

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
