#ifndef ACTIONCATEGORY_H
#define ACTIONCATEGORY_H

#include <QAction>
#include <QObject>
#include "classes/achievements/categoriesgame.h"

class ActionCategory : public QAction
{
    Q_OBJECT
public:
    ActionCategory(QString text = QString(), QObject *object = nullptr): QAction(text, object) {};
    ActionCategory(QIcon icon, QString text = QString(), QObject *object = nullptr): QAction(icon, text, object) {};
    ActionCategory(Category *category, QIcon icon, QString text = QString(), QObject *object = nullptr);

    Category *category() const {return _category;}
    ActionCategory &setCategory(Category*);

private:
    Category *_category = nullptr;
};

#endif // ACTIONCATEGORY_H
