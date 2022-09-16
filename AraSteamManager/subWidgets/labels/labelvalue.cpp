#include "labelvalue.h"

LabelValue::LabelValue(QWidget *aParent): QLabel(aParent) {

}

LabelValue::LabelValue(const QString &aText, QWidget *aParent): LabelValue(aParent) {
    setText(aText);
}
