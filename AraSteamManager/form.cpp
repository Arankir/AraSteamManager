#include "form.h"

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
