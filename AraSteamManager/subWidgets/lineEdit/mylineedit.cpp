#include "mylineedit.h"
#include "classes/common/theme.h"
#include "form.h"

#include <QStyle>

MyLineEdit::MyLineEdit(QWidget *aParent): QLineEdit(aParent) {
    this->setStyleSheet("QLineEdit[text=\"\"]{ color:" + Theme::getCurrentTheme().border.getString() + "; }");
    connect(this, &QLineEdit::textChanged, [=, this]{ style()->polish(this); });
    if (auto parent = dynamic_cast<Form*>(aParent)) {
        connect(parent, &Form::s_settingsUpdated, this, &MyLineEdit::updateSettings);
    }
}

void MyLineEdit::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        this->setStyleSheet("QLineEdit[text=\"\"]{ color:" + Theme::getCurrentTheme().border.getString() + "; }");
    }
}
