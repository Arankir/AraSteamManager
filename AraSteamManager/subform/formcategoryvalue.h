#ifndef FORMCATEGORYVALUE_H
#define FORMCATEGORYVALUE_H

#include <QWidget>
#include <class/settings.h>

namespace Ui {
class FormCategoryValue;
}

class FormCategoryValue : public QWidget
{
    Q_OBJECT

public:
    explicit FormCategoryValue(int position, QWidget *parent = nullptr);
    ~FormCategoryValue();
    void setVisibl(bool visible);
    void setPosition(int pos);
    void setTitle(QString);
    void setFirstLast(int firstlast);
    int getPosition() {return position;}
    QString getTitle();
    bool getVisible();


private slots:

    void on_CheckBoxVisible_stateChanged(int arg1);
    void on_ButtonUp_clicked();
    void on_ButtonDown_clicked();
    void on_ButtonSelect_clicked();
    void on_ButtonUnSelect_clicked();
    void on_ButtonDelete_clicked();
    void on_LineEditTitle_textChanged(const QString &arg1);

signals:
    void valuechange(int pos, QString value);
    void visiblechange(int pos, bool visible);
    void positionchange(int pos, int posnew);
    void selectchange(int pos, bool select);
    void deleting(int pos);

private:
    Ui::FormCategoryValue *ui;
    Settings Setting;
    QString theme="white";
    int position=0;
    int isfirstlast=0;
};

#endif // FORMCATEGORYVALUE_H
