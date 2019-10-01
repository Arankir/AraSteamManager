#ifndef CATEGORYVALUE_H
#define CATEGORYVALUE_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <class/settings.h>

class CategoryValue : public QGridLayout
{
    Q_OBJECT
public:
    CategoryValue(int position);
    QString GetValueName() {return ValueName->text();}
    int GetPosition() {return position;}
    ~CategoryValue();

signals:
    void valuechange(QString value);
    void visiblechange(bool visible);
    void positionchange(int pos);
    void selectchange(bool select);
    void deleting();

private slots:
    void OnChangeValue() {emit valuechange(ValueName->text());}
    void OnChangeVisibility() {emit visiblechange(Visible->isChecked());}
    void OnChangePosition();
    void OnChangeSelect();
    void OnDeleting() {emit deleting();}

private:
    QLineEdit *ValueName;
    QCheckBox *Visible;
    QPushButton *Up;
    QPushButton *Down;
    QPushButton *Select;
    QPushButton *UnSelect;
    QPushButton *Delete;
    int position=0;
    QStringList Words;
    Settings Setting;
    QString theme="white";
};

#endif // CATEGORYVALUE_H
