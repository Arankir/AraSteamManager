#include "actioncategory.h"

ActionCategory::ActionCategory(Category2 *category, QIcon icon, QString text, QObject *object):
    QAction(icon, text, object), _category(category) {

}

ActionCategory &ActionCategory::setCategory(Category2 *aCategory) {
    _category = aCategory;
    return *this;
}
