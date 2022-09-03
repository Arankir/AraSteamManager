#ifndef FORM_H
#define FORM_H

#include <QObject>
#include <QWidget>
#include "framelesswindow.h"

class Form : public QWidget {
    Q_OBJECT
public:
    explicit Form(QWidget *parent = nullptr);
    virtual ~Form();
    virtual void updateSettings(QFlags<changedSettings>);
    virtual void updateIcons() = 0;
    virtual void retranslate() = 0;
    virtual void changeEvent(QEvent *event);
    virtual void close();

    void setParent(Form *parent);

    void setFramelessWindow(FramelessWindow *window);
    FramelessWindow *window();

    bool setStatus(const QString &statusName = "", int progress = 0, int maxProgress = 0);
    bool clearStatus();

signals:
    void s_closed();
    void s_destructed();
    void s_settingsUpdated(QFlags<changedSettings>);

private:
    bool _isRoot = false;
    class FramelessWindow *_framelessWindow = nullptr;

    FramelessWindow *formParent();
};

#endif // FORM_H
