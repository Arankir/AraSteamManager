#ifndef FORMCATEGORYVALUE_H
#define FORMCATEGORYVALUE_H

#include <QWidget>
#include "class/settings.h"

enum class EnabledUpDown {
    none,
    up,
    down,
    both
};

namespace Ui {
class FormCategoryValue;
}

class FormCategoryValue: public QWidget {
    Q_OBJECT

public:
    explicit FormCategoryValue(int position, QWidget *parent = nullptr);
    ~FormCategoryValue();
    void setColumnVisible(bool visible);
    void setPosition(int pos);
    void setTitle(QString);
    void setEnabledUpDown(EnabledUpDown firstlast);
    int getPosition();
    QString getTitle();
    bool getVisible();

public slots:
    void updateSettings();
    void setIcons();

signals:
    void s_valuechange(int pos, QString value);
    void s_visiblechange(int pos, bool visible);
    void s_positionchange(int pos, int posnew);
    void s_selectchange(int pos, bool select);
    void s_deleting(int pos);
    void s_reverse(int pos);

private slots:
    void changeEvent(QEvent *event);
    void checkBoxVisible_StateChanged(int arg1);
    void buttonUp_Clicked();
    void buttonDown_Clicked();
    void buttonSelect_Clicked();
    void buttonUnSelect_Clicked();
    void buttonDelete_Clicked();
    void lineEditTitle_TextChanged(const QString &arg1);
    void buttonReverse_Clicked();

private:
    Ui::FormCategoryValue *ui;
    int _position = 0;
    EnabledUpDown _isFirstLast = EnabledUpDown::none;
};


#endif // FORMCATEGORYVALUE_H
