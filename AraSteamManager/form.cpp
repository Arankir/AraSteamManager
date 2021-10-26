#include "form.h"
#include <QStatusBar>

Form::Form(QWidget *parent) : QWidget(parent) {

}

void Form::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void Form::close() {
    emit s_closed();
//    QWidget::close();
}

void Form::setFramelessWindow(class FramelessWindow *window) {
    _framelessWindow = window;
    _isRoot = true;
}

FramelessWindow *Form::formParent() {
    QWidget *parent = parentWidget();
    while (parent->parentWidget()) {
        if (auto form = dynamic_cast<FramelessWindow*>(parent->parentWidget())) {
            return form;
        }
        parent = parent->parentWidget();
    }
    return nullptr;
}

bool Form::setStatus(const QString &aStatusName, int aProgress, int aMaxProgress) {
//    qDebug() << aStatusName << aProgress << aMaxProgress;
    if (window() == nullptr) {
        if (auto form = formParent()) {
            form->setStatus(aStatusName, aProgress, aMaxProgress);
            return true;
        }
        return false;
    }
    window()->setStatus(aStatusName, aProgress, aMaxProgress);
    return true;
}

bool Form::clearStatus() {
    if (window() == nullptr) {
        if (auto form = formParent()) {
            form->clearStatus();
            return true;
        }
        return false;
    }
    window()->clearStatus();
    return true;
}
