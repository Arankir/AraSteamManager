#ifndef FORM_H
#define FORM_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QMoveEvent>
#include <QVBoxLayout>
#include <QSpacerItem>

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

protected:
    bool isLoading_ = false;

private:
    bool isRoot_ = false;
    class FramelessWindow *framelessWindow_ = nullptr;

    FramelessWindow *formParent();
};

bool centralize(const QWidget *parent, QWidget *child);

template <class T>
T *createFramelessForm() {
    FramelessWindow *f = new FramelessWindow;
    T *t = new T(f);
    f->setWidget(t);
    if (Form *form = dynamic_cast<Form*>(t)) {
        form->setFramelessWindow(f);

        QObject::connect(form, &Form::s_closed, f, [f](){
            f->close();
        });
    }
    return t;
}

class SubForm: public Form {
    Q_OBJECT
public:
    explicit SubForm(QWidget *aSubForm, QWidget *aParent);
    virtual ~SubForm();
    void updateIcons() override;
    void retranslate() override;
    bool addWidget(QWidget *widget, FramelessWindow::Edge edge = FramelessWindow::Edge::Bottom);
    
private:
    void resizeEvent(QResizeEvent *aEvent) override;
    void moveEvent(QMoveEvent *aEvent) override;
    bool eventFilter(QObject *o, QEvent *e) override;
    void mouseHover(QHoverEvent*);
    void mouseLeave(QEvent*);
    void mousePress(QMouseEvent*);
    void mouseRealese(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void updateCursorShape(const QPointF &);
    void calculateCursorPosition(const QPointF &, const QRect &, FramelessWindow::Edges &);

signals:
    void s_moved(QPoint oldPoint, QPoint newPoint);
    void s_resized(QSize oldSize, QSize newSize);
    
private:
    bool cursorchanged_;
    bool leftButtonPressed_;
    FramelessWindow::Edges mousePress_ = FramelessWindow::Edge::None;
    FramelessWindow::Edges mouseMove_ = FramelessWindow::Edge::None;
    QRubberBand *rubberband_ = nullptr;

    QPoint dragPos_;
    bool dragStart_ = false;

    QWidget *originalForm_;
    QList<QPair<QWidget*, FramelessWindow::Edge>> widgets_;
};

template <class T>//TODO Создать класс подформы с перемещением, закрытием, сигналами и редактированием виджетов
QFrame *createSubForm(T *aSubForm, QWidget *aParent, QPushButton *aButtonClose = nullptr) {
    QFrame *frame = new QFrame(aParent);
    frame->setObjectName("SubWindow");
    if (aButtonClose == nullptr) {
        QVBoxLayout *lay = new QVBoxLayout(frame);
        lay->addWidget(aSubForm);
    } else {
        QVBoxLayout *lay = new QVBoxLayout(frame);

        QWidget *closeWidget = new QWidget();
        QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Maximum);
        QHBoxLayout *hLayout = new QHBoxLayout(closeWidget);
        hLayout->addSpacerItem(spacer);
        hLayout->addWidget(aButtonClose);
        hLayout->setContentsMargins(0, 0, 0, 0);
        hLayout->setSpacing(0);

        lay->addWidget(closeWidget);
        lay->addWidget(aSubForm);
    }
    centralize(aParent, frame);
    frame->show();
    return frame;
}

#endif // FORM_H
