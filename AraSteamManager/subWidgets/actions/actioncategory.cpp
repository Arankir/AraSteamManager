#include "actioncategory.h"

ActionCategory::ActionCategory(Category *category, QIcon icon, QString text, QObject *object):
    QAction(icon, text, object), _category(category) {

}

ActionCategory &ActionCategory::setCategory(Category *aCategory) {
    _category = aCategory;
    return *this;
}
