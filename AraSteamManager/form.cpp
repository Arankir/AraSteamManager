#include "form.h"
#include <QEvent>
#include <QStatusBar>

Form::Form(QWidget *aParent) : QWidget(aParent) {
    if (Form *parent = dynamic_cast<Form*>(aParent)) {
        connect(parent, &Form::s_settingsUpdated, this, &Form::updateSettings);
    }
}

Form::~Form() {
    qDebug() << tr("%1 deleted").arg(this->objectName());
    if (Form *parent = dynamic_cast<Form*>(parentWidget())) {
        disconnect(parent, &Form::s_settingsUpdated, this, &Form::updateSettings);
    }
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
    if (Form *parent = dynamic_cast<Form*>(parentWidget())) {
        disconnect(parent, &Form::s_settingsUpdated, this, &Form::updateSettings);
    }
    QWidget::setParent(aParent);
    connect(aParent, &Form::s_settingsUpdated, this, &Form::updateSettings);
}

void Form::setFramelessWindow(class FramelessWindow *window) {
    framelessWindow_ = window;
    isRoot_ = true;
}

FramelessWindow *findWindow(QObject *aObject) {
    if (aObject->parent()) {
        if (FramelessWindow *window = dynamic_cast<FramelessWindow*>(aObject->parent())) {
            return window;
        } else {
            return findWindow(aObject->parent());
        }
    } else {
        return nullptr;
    }
}

FramelessWindow *Form::window() {
    if (framelessWindow_) {
        return framelessWindow_;
    } else if (parent()) {
        return findWindow(this);
    } else {
        return nullptr;
    }
}

FramelessWindow *Form::formParent() {
    QWidget *parent = parentWidget();
    while (parent->parentWidget()) {
        if (FramelessWindow *form = dynamic_cast<FramelessWindow*>(parent->parentWidget())) {
            return form;
        }
        parent = parent->parentWidget();
    }
    return nullptr;
}

bool Form::setStatus(const QString &aStatusName, int aProgress, int aMaxProgress) {
//    qDebug() << aStatusName << aProgress << aMaxProgress;
    if (window() == nullptr) {
        if (FramelessWindow *form = formParent()) {
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
        if (FramelessWindow *form = formParent()) {
            form->clearStatus();
            return true;
        }
        return false;
    }
    window()->clearStatus();
    return true;
}

bool centralize(const QWidget *aParent, QWidget *aChild) {
    if (!aParent) {
        return false;
    }
    QRect parentGeometry = aParent->geometry();
    QSize childSize = aChild->sizeHint();
    QRect result(((parentGeometry.width() / 2) - (childSize.width() / 2)),
                ((parentGeometry.height() / 2) - (childSize.height() / 2)),
                childSize.width(),
                childSize.height());
    aChild->setGeometry(result);
    return true;
}

constexpr int c_border = 7;
constexpr int c_titleHeight = 20;
constexpr int c_minHeight = 80;
constexpr int c_minWidth = 80;

SubForm::SubForm(QWidget *aSubForm, QWidget *aParent):
Form(aParent),
cursorchanged_(false),
leftButtonPressed_(false),
dragPos_(QPoint()),
originalForm_(aSubForm) {
    //        assert(aSubForm == nullptr);//TODO static_assert
    //        assert(aParent == nullptr);
    rubberband_ = new QRubberBand(QRubberBand::Rectangle);
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Hover);
    this->installEventFilter(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);
    QFrame *title = new QFrame(this);
    title->setAccessibleName("TitleWindow");
    title->setFixedHeight(c_titleHeight);
    layout->addWidget(title);
    QFrame *frame = new QFrame(this);
    //        frame->setStyleSheet("background-color: red; "
    //                             "border: 1px solid blue; ");
    layout->addWidget(frame);
    QVBoxLayout *layout2 = new QVBoxLayout(frame);
    layout2->addWidget(aSubForm);
    frame->setLayout(layout2);
    centralize(aParent, this);
}

SubForm::~SubForm() {
    originalForm_->deleteLater();
    for (auto widget: widgets_) {
        widget.first->deleteLater();
    }
}

void SubForm::updateIcons() {
    if (auto form = dynamic_cast<Form*>(originalForm_)) {
        form->updateIcons();
    }
    for (auto widget: widgets_) {
        if (auto form = dynamic_cast<Form*>(widget.first)) {
            form->updateIcons();
        }
    }
}

void SubForm::retranslate() {
    if (auto form = dynamic_cast<Form*>(originalForm_)) {
        form->retranslate();
    }
    for (auto widget: widgets_) {
        if (auto form = dynamic_cast<Form*>(widget.first)) {
            form->retranslate();
        }
    }
}

bool SubForm::addWidget(QWidget *widget, FramelessWindow::Edge edge) {
    if (!widget) {
        return false;
    }
    auto layOriginal = dynamic_cast<QVBoxLayout*>(layout());
    if (layOriginal == nullptr || layOriginal->itemAt(1) == nullptr || layOriginal->itemAt(1)->widget() == nullptr) {
        return false;
    }
    if (auto lay = dynamic_cast<QVBoxLayout*>(layOriginal->itemAt(1)->widget()->layout())) {
        switch(edge) {
        case FramelessWindow::Edge::Top: {
            lay->insertWidget(0, widget);
            break;
        }
        case FramelessWindow::Edge::TopLeft: {
            QHBoxLayout *lay2 = new QHBoxLayout(this);
            lay2->addWidget(widget);
            QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
            lay2->addItem(spacer);
            lay->insertLayout(0, lay2);
            break;
        }
        case FramelessWindow::Edge::TopRight: {
            QHBoxLayout *lay2 = new QHBoxLayout(this);
            QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
            lay2->addItem(spacer);
            lay2->addWidget(widget);
            lay->insertLayout(0, lay2);
            break;
        }
        case FramelessWindow::Edge::Bottom: {
            lay->addWidget(widget);
            break;
        }
        case FramelessWindow::Edge::BottomLeft: {
            QHBoxLayout *lay2 = new QHBoxLayout(this);
            lay2->addWidget(widget);
            QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
            lay2->addItem(spacer);
            lay->addLayout(lay2);
            break;
        }
        case FramelessWindow::Edge::BottomRight: {
            QHBoxLayout *lay2 = new QHBoxLayout(this);
            QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
            lay2->addItem(spacer);
            lay2->addWidget(widget);
            lay->addLayout(lay2);
            break;
        }
        default: {
            return false;
        }
        }
        widgets_.append(QPair<QWidget*, FramelessWindow::Edge>(widget, edge));
        return true;
    }
    return false;
}

void SubForm::resizeEvent(QResizeEvent *aEvent) {
    emit s_resized(aEvent->oldSize(), aEvent->size());
}

void SubForm::moveEvent(QMoveEvent *aEvent) {
    emit s_moved(aEvent->oldPos(), aEvent->pos());
}

bool SubForm::eventFilter(QObject *o, QEvent*e) {
    switch (e->type()) {
    case QEvent::MouseMove:
        mouseMove(static_cast<QMouseEvent*>(e));
        return true;
        break;
    case QEvent::HoverMove:
        mouseHover(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::Leave:
        mouseLeave(e);
        return true;
        break;
    case QEvent::MouseButtonPress:
        mousePress(static_cast<QMouseEvent*>(e));
        return true;
        break;
    case QEvent::MouseButtonRelease:
        mouseRealese(static_cast<QMouseEvent*>(e));
        return true;
        break;
    default: {
        return Form::eventFilter(o, e);
    }
    }
}

void SubForm::mouseRealese(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        leftButtonPressed_ = false;
        dragStart_ = false;
    }
    Form::mouseReleaseEvent(e);
}

void SubForm::mouseLeave(QEvent *e) {
    Q_UNUSED(e);
    if (!leftButtonPressed_) {
        this->unsetCursor();
    }
}

void SubForm::mousePress(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        leftButtonPressed_ = true;
        calculateCursorPosition(e->position(), this->geometry(), mousePress_);
        if (!mousePress_.testFlag(FramelessWindow::Edge::None)) {
            rubberband_->setGeometry(this->frameGeometry());
        }
        if (this->rect().marginsRemoved(QMargins(c_border, c_border, c_border, c_border)).contains(e->pos()) &&
                (e->position().y() < c_titleHeight)) {
            dragStart_ = true;
            dragPos_ = e->pos();
        }
    }
}

void SubForm::mouseMove(QMouseEvent *e) {
    if (leftButtonPressed_) {
        if (dragStart_) { //Change Position
            QPoint parentBottomRight = this->parentWidget()->geometry().bottomRight();
            QPoint newPos = (this->frameGeometry().topLeft() + (e->pos() - dragPos_));
            if (newPos.x() < 0) {
                newPos.setX(0);
            }
            if (newPos.x() + e->pos().x() > parentBottomRight.x()) {
                newPos.setX(parentBottomRight.x() - dragPos_.x());
            }
            if (newPos.y() < 0) {
                newPos.setY(0);
            }
            if (newPos.y() + e->pos().y() > parentBottomRight.y()) {
                newPos.setY(parentBottomRight.y() - dragPos_.y());
            }
            this->move(newPos);
        }

        if (!mousePress_.testFlag(FramelessWindow::Edge::None)) { //Change Rectangle
            QRect parentRect = this->parentWidget()->geometry();
            QRect newRect = rubberband_->frameGeometry();
            if (mousePress_.testFlag(FramelessWindow::Edge::Left)) {
                newRect.setLeft(newRect.left() + e->position().x());
            }
            if (mousePress_.testFlag(FramelessWindow::Edge::Right)) {
                newRect.setRight(newRect.left() + e->position().x());
            }
            if (mousePress_.testFlag(FramelessWindow::Edge::Top)) {
                newRect.setTop(newRect.top() + e->position().y());
            }
            if (mousePress_.testFlag(FramelessWindow::Edge::Bottom)) {
                newRect.setBottom(newRect.top() + e->position().y());
            }
            if (newRect.left() < 0) {
                newRect.setLeft(0);
            }
            if (newRect.right() > parentRect.right()) {
                newRect.setRight(parentRect.right());
            }
            if (newRect.width() < c_minWidth) {
                newRect.setLeft(rubberband_->frameGeometry().left());
                newRect.setRight(rubberband_->frameGeometry().right());
            }
            if (newRect.top() < 0) {
                newRect.setTop(0);
            }
            if (newRect.bottom() > parentRect.bottom()) {
                newRect.setBottom(parentRect.bottom());
            }
            if (newRect.height() < c_minHeight) {
                newRect.setTop(rubberband_->frameGeometry().top());
                newRect.setBottom(rubberband_->frameGeometry().bottom());
            }
            this->setGeometry(newRect);
            rubberband_->setGeometry(newRect);
        }
    } else {
        updateCursorShape(e->position());
    }
}

void SubForm::mouseHover(QHoverEvent *e) {
    updateCursorShape(e->position());
}

void SubForm::updateCursorShape(const QPointF &pos) {
    if (this->isFullScreen() || this->isMaximized()) {
        if (cursorchanged_) {
            this->unsetCursor();
        }
        return;
    }
    if (!leftButtonPressed_) {
        calculateCursorPosition(pos, this->geometry(), mouseMove_);
        cursorchanged_ = true;
        if (mouseMove_.testFlag(FramelessWindow::Edge::TopLeft) || mouseMove_.testFlag(FramelessWindow::Edge::BottomRight)) {
            this->setCursor(Qt::SizeFDiagCursor);
            return;
        }
        if (mouseMove_.testFlag(FramelessWindow::Edge::TopRight) || mouseMove_.testFlag(FramelessWindow::Edge::BottomLeft)) {
            this->setCursor(Qt::SizeBDiagCursor);
            return;
        }
        if (mouseMove_.testFlag(FramelessWindow::Edge::Left) || mouseMove_.testFlag(FramelessWindow::Edge::Right)) {
            this->setCursor(Qt::SizeHorCursor);
            return;
        }
        if (mouseMove_.testFlag(FramelessWindow::Edge::Top) || mouseMove_.testFlag(FramelessWindow::Edge::Bottom)) {
            this->setCursor(Qt::SizeVerCursor);
            return;
        }
        this->unsetCursor();
        cursorchanged_ = false;
    }
}

void SubForm::calculateCursorPosition(const QPointF &aPos, const QRect &aFrameRect, FramelessWindow::Edges &aEdge) {
    int x = aPos.x(), y = aPos.y(), edge = 0;
    if (x <= c_border) { //Left
        edge += FramelessWindow::Edge::Left;
    } else if (x <= aFrameRect.width() - c_border) { //Center

    } else if (x <= aFrameRect.width()) { //Right
        edge += FramelessWindow::Edge::Right;
    }

    if (y <= c_border) { //Top
        edge += FramelessWindow::Edge::Top;
    } else if (y <= aFrameRect.height() - c_border) { //Center

    } else if (y <= aFrameRect.height()) { //Bottom
        edge += FramelessWindow::Edge::Bottom;
    }
    aEdge = static_cast<FramelessWindow::Edge>(edge);
}
