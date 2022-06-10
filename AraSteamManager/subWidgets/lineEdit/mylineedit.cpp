#include "mylineedit.h"
#include <QStyle>
#include <classes/common/theme.h>

MyLineEdit::MyLineEdit(QWidget *aParent): QLineEdit(aParent) {
    this->setStyleSheet("QLineEdit[text=\"\"]{ color:" + Theme::getCurrentTheme().border.getString() + "; }");
    connect(this, &QLineEdit::textChanged, [=, this]{ style()->polish(this); });
}

void MyLineEdit::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        this->setStyleSheet("QLineEdit[text=\"\"]{ color:" + Theme::getCurrentTheme().border.getString() + "; }");
    }
}
