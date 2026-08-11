#ifndef ACTIONCATEGORY_H
#define ACTIONCATEGORY_H

#include <QAction>
#include <QObject>
#include "classes/files/category.h"

class ActionCategory : public QAction {
    Q_OBJECT
public:
    ActionCategory(const QString &text = QString(), QObject *object = nullptr);
    ActionCategory(const QIcon &icon, const QString &text = QString(), QObject *object = nullptr);
    ActionCategory(Category *category, const QIcon &icon, const QString &text = QString(), QObject *object = nullptr);

    Category *category() const;
    ActionCategory &setCategory(Category*);

private:
    Category *category_ = nullptr;
};

#endif // ACTIONCATEGORY_H
