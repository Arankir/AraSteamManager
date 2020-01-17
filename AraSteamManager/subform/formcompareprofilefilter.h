#ifndef FORMCOMPAREPROFILEFILTER_H
#define FORMCOMPAREPROFILEFILTER_H

#include <QWidget>
#include <class/settings.h>
#include <subwidget/qradiobuttonwithdata.h>
#include <QDebug>

namespace Ui {
class FormCompareProfileFilter;
}

class FormCompareProfileFilter : public QWidget
{
    Q_OBJECT

signals:
    void s_radioButtonChange(QString name, ReachedType type);

public:
    explicit FormCompareProfileFilter(QWidget *parent = nullptr);
    ~FormCompareProfileFilter();
    void SetName(QString Aname) {_name=Aname;}
    void SetIndex(QString Aindex) {_index=Aindex;}
    void SetTitles(QString,QString,QString);
    QString GetName() {return _name;}
    QString GetIndex() {return _index;}
    void SetType(ReachedType);
    void Update();

private slots:
    void RadioButtonClick();

private:
    Ui::FormCompareProfileFilter *ui;
    Settings _setting;
    QString _name;
    QString _index;
};

#endif // FORMCOMPAREPROFILEFILTER_H
