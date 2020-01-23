#ifndef FORMCATEGORYVALUE_H
#define FORMCATEGORYVALUE_H

#include <QWidget>
#include <class/settings.h>

enum class EnabledUpDown{
    none,
    up,
    down,
    both
};

namespace Ui {
class FormCategoryValue;
}

class FormCategoryValue : public QWidget
{
    Q_OBJECT

public:
    explicit FormCategoryValue(int position, QWidget *parent = nullptr);
    ~FormCategoryValue();
    void SetVisible(bool visible);
    void SetPosition(int pos);
    void SetTitle(QString);
    void SetEnabledUpDown(EnabledUpDown firstlast);
    int GetPosition() {return _position;}
    QString GetTitle();
    bool GetVisible();


private slots:

    void on_CheckBoxVisible_stateChanged(int arg1);
    void on_ButtonUp_clicked();
    void on_ButtonDown_clicked();
    void on_ButtonSelect_clicked();
    void on_ButtonUnSelect_clicked();
    void on_ButtonDelete_clicked();
    void on_LineEditTitle_textChanged(const QString &arg1);
    void on_ButtonReverse_clicked();

signals:
    void s_valuechange(int pos, QString value);
    void s_visiblechange(int pos, bool visible);
    void s_positionchange(int pos, int posnew);
    void s_selectchange(int pos, bool select);
    void s_deleting(int pos);
    void s_reverse(int pos);

private:
    Ui::FormCategoryValue *ui;
    Settings _setting;
    QString _theme="white";
    int _position=0;
    EnabledUpDown _isFirstLast=EnabledUpDown::none;
};


#endif // FORMCATEGORYVALUE_H
