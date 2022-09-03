#include "form.h"
#include <QStatusBar>

Form::Form(QWidget *aParent) : QWidget(aParent) {
    if (auto parent = dynamic_cast<Form*>(aParent)) {
        connect(parent, &Form::s_settingsUpdated, this, &Form::updateSettings);
    }
}

Form::~Form() {
    qDebug() << tr("%1 deleted").arg(this->objectName());
    emit s_destructed();
}

void Form::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
    emit s_settingsUpdated(aSettings);
}

void Form::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void Form::close() {
    qDebug() << "close";
    emit s_closed();
    //    QWidget::close();
}

void Form::setParent(Form *aParent) {
    QWidget::setParent(aParent);
    connect(aParent, &Form::s_settingsUpdated, this, &Form::updateSettings);
}

void Form::setFramelessWindow(class FramelessWindow *window) {
    _framelessWindow = window;
    _isRoot = true;
}

FramelessWindow *findWindow(QObject *aObject) {
    if (aObject->parent()) {
        if (auto window = dynamic_cast<FramelessWindow*>(aObject->parent())) {
            return window;
        } else {
            return findWindow(aObject->parent());
        }
    } else {
        return nullptr;
    }
}

FramelessWindow *Form::window() {
    if (_framelessWindow) {
        return _framelessWindow;
    } else {
        return findWindow(this);
    }
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
