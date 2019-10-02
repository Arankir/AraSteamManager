#ifndef CATEGORYVALUE_H
#define CATEGORYVALUE_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <class/settings.h>

class CategoryValue : public QHBoxLayout
{
    Q_OBJECT
public:
    CategoryValue(int position);
    CategoryValue() {}
    QString GetValueName() {return ValueName->text();}
    int GetPosition() {return position;}
    bool GetVisible() {return Visible->isChecked();}
    void SetPosition(int pos) {position=pos;}
    void SetSelect(bool select);
    ~CategoryValue();
    CategoryValue(const CategoryValue &);
    CategoryValue & operator=(const CategoryValue & achievement);

signals:
    void valuechange(int pos, QString value);
    void visiblechange(int pos, bool visible);
    void positionchange(int pos, int posnew);
    void selectchange(int pos, bool select);
    void deleting(int pos);

private slots:
    void OnChangeValue() {emit valuechange(position, ValueName->text());}
    void OnChangeVisibility() {emit visiblechange(position, Visible->isChecked());}
    void OnChangePosition();
    void OnChangeSelect();
    void OnDeleting() {emit deleting(position);}

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
