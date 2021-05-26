#ifndef FORM_H
#define FORM_H

#include <QObject>
#include <QWidget>
#include "framelesswindow.h"

class Form : public QWidget {
    Q_OBJECT
public:
    explicit Form(QWidget *parent = nullptr);
    virtual void updateSettings() = 0;
    virtual void updateIcons() = 0;
    virtual void changeEvent(QEvent *event);
    virtual void retranslate() = 0;

    void setFramelessWindow(FramelessWindow *window);
    FramelessWindow *window() {return _framelessWindow;}

signals:

private:
    bool _isRoot = false;
    class FramelessWindow *_framelessWindow = nullptr;

};

#endif // FORM_H
