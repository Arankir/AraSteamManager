#ifndef FORMADDCATEGORY_H
#define FORMADDCATEGORY_H

#include <QWidget>
#include <class/settings.h>
#include <class/categoryvalue.h>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>

namespace Ui {
class FormAddCategory;
}

class FormAddCategory : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddCategory(QString game, QWidget *parent = nullptr);
    ~FormAddCategory();
    int GetCount() {return count;}
    QString GetTitle();

signals:
    void valuechange(int pos, QString value);
    void visiblechange(int pos, bool visible);
    void positionchange(int pos, int posnew);
    void selectchange(int pos, bool select);
    void deleting(int pos);
    void accept();
    void cancel();
    void addvalue(int pos);
    void novalue(bool novalue);

private slots:
    void ChangePosition(int pos, int posnew);
    void ChangeValue(int pos, QString value);
    void ChangeVisibility(int pos, bool visible);
    void ChangeSelect(int pos, bool select);
    void DeleteValue(int pos);

    void on_ButtonAddValue_clicked();
    void on_ButtonAccept_clicked();
    void on_ButtonCancel_clicked();
    void on_CheckBoxSelectAll_clicked();
    void on_CheckBoxNoValue_stateChanged(int arg1);


private:
    Ui::FormAddCategory *ui;
    QString game;
    QStringList Words;
    Settings Setting;
    QString theme="white";
    QVector<CategoryValue*> Values;
    int count=0;
    QFormLayout *lay;
};

#endif // FORMADDCATEGORY_H
