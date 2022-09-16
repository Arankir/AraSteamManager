#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include "classes/common/settings.h"

class MyLineEdit : public QLineEdit {
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent = nullptr);

public slots:
    void updateSettings(QFlags<changedSettings> settings);
};

#endif // MYLINEEDIT_H
