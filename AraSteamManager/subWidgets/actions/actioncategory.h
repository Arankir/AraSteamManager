#ifndef ACTIONCATEGORY_H
#define ACTIONCATEGORY_H

#include <QAction>
#include <QObject>
#include "classes/files/achievementscategory.h"

class ActionCategory : public QAction {
    Q_OBJECT
public:
    ActionCategory(QString text = QString(), QObject *object = nullptr): QAction(text, object) {};
    ActionCategory(QIcon icon, QString text = QString(), QObject *object = nullptr): QAction(icon, text, object) {};
    ActionCategory(Category2 *category, QIcon icon, QString text = QString(), QObject *object = nullptr);

    Category2 *category() const {return _category;}
    ActionCategory &setCategory(Category2*);

private:
    Category2 *_category = nullptr;
};

#endif // ACTIONCATEGORY_H
