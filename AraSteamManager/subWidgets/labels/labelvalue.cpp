#include "labelvalue.h"

LabelValue::LabelValue(const QString &aText, QWidget *aParent): LabelValue(aParent) {
    setText(aText);
}
