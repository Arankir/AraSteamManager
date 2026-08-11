#include "actioncategory.h"

ActionCategory::ActionCategory(const QString &text, QObject *object): QAction(text, object) {

}

ActionCategory::ActionCategory(const QIcon &icon, const QString &text, QObject *object): QAction(icon, text, object) {

}

ActionCategory::ActionCategory(Category *category, const QIcon &icon, const QString &text, QObject *object):
    QAction(icon, text, object), category_(category) {

}

Category *ActionCategory::category() const {
    return category_;
}

ActionCategory &ActionCategory::setCategory(Category *aCategory) {
    category_ = aCategory;
    return *this;
}
