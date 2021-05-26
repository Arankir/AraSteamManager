#include "framelesswindow.h"
#include "ui_framelesswindow.h"

const int c_border = 7;

FramelessWindow *FramelessWindow::createWithWidget(QWidget *widget) {
    FramelessWindow *f = new FramelessWindow;
    widget->setParent(f);
    f->setWidget(widget);
    return f;
}

FramelessWindow::FramelessWindow(): FramelessWindow(nullptr) {

}

FramelessWindow::FramelessWindow(QWidget *target):
                    ui(new Ui::FramelessWindow),
                    _target(target),
                    _cursorchanged(false),
                    _leftButtonPressed(false),
                    _dragPos(QPoint()) {
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Hover);
    this->installEventFilter(this);
    if (_target != nullptr) {
        ui->centralwidget->layout()->addWidget(_target);
    }
    _rubberband = new QRubberBand(QRubberBand::Rectangle);

    ui->ButtonMinimize  ->setFlat(true);
    ui->ButtonMaximize  ->setFlat(true);
    ui->ButtonExit      ->setFlat(true);

    connect(ui->ButtonMaximize, &QPushButton::clicked, this, &FramelessWindow::buttonMaximize_Clicked);
    connect(ui->ButtonMinimize, &QPushButton::clicked, this, &FramelessWindow::buttonMinimize_Clicked);
    connect(ui->ButtonExit,     &QPushButton::clicked, this, &FramelessWindow::buttonExit_Clicked);
    setIcons();
}

void FramelessWindow::setWidget(QWidget *target) {
    _target = target;
    ui->centralwidget->layout()->addWidget(_target);
}

void FramelessWindow::setIcons() {
    ui->LabelLogo->setPixmap(QPixmap(Images::logo()).scaled(30, 30));

//    ui->LabelLogo->setTextFormat(Qt::RichText);
//    ui->LabelLogo->setText("<img height=30 style=\"vertical-align: top\" src=\"" + Images::logo() + "\"> "
//                                "<span style=\"vertical-align: bottom\">НАЯ ПРОГА</span>");
    ui->ButtonExit          ->setIcon(QIcon(Images::closeWindow()));
    ui->ButtonMinimize      ->setIcon(QIcon(Images::minimizeWindow()));
    if (this->isMaximized()) {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::maximizeWindow()));
    }
}

void FramelessWindow::buttonExit_Clicked() {
    if (_target) {
        _target->close();
    }
    this->close();
}

void FramelessWindow::buttonMaximize_Clicked() {
    if(!this->isMaximized()) {
        this->showMaximized();
        ui->ButtonMaximize->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        this->showNormal();
        ui->ButtonMaximize->setIcon(QIcon(Images::maximizeWindow()));
    }
}

void FramelessWindow::buttonMinimize_Clicked() {
    if(!this->isMinimized()) {
        this->showMinimized();
    } else {
        this->showNormal();
    }
}
FramelessWindow::~FramelessWindow() {
    if (_target) {
        delete _target;
    }
    delete ui;
}

void FramelessWindow::animateResize(int width, int height) {
    qDebug() << QSize(this->width(), this->height()) << QSize(width, height);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "size");
    connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
    animation->setDuration(500);
    animation->setStartValue(QSize(this->width(), this->height()));
    animation->setEndValue(QSize(width, height));
    animation->start();
}

bool FramelessWindow::eventFilter(QObject *o, QEvent*e) {
    Q_UNUSED(o);
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
        return false;
    }
    }
}

void FramelessWindow::mouseRealese(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        _leftButtonPressed = false;
        _dragStart = false;
    }
}

void FramelessWindow::mouseLeave(QEvent *e) {
    Q_UNUSED(e);
    if (!_leftButtonPressed) {
        this->unsetCursor();
    }
}

void FramelessWindow::mousePress(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        _leftButtonPressed = true;
        calculateCursorPosition(e->globalPos(), this->frameGeometry(), _mousePress);
        if (!_mousePress.testFlag(Edge::None)) {
            _rubberband->setGeometry(this->frameGeometry());
        }
        //qDebug()<<(e->globalPos() - _target->pos()).y();
        if (this->rect().marginsRemoved(QMargins(c_border, c_border, c_border, c_border)).contains(e->pos()) &&
           ((e->globalPos() - this->pos()).y() < ui->FrameTitleWindow->height())) {
            _dragStart = true;
            _dragPos = e->pos();
        }
    }
}

void FramelessWindow::mouseMove(QMouseEvent *e) {
    if (_leftButtonPressed) {
        if (this->isMaximized()) {
            this->showNormal();
            ui->ButtonMaximize->setIcon(QIcon(Images::maximizeWindow()));
        }
        if (_dragStart) { //Change Position
            if (this->normalGeometry().x() + this->normalGeometry().width() < e->globalPos().x()) {
                _dragPos.setX(e->globalPos().x() - (this->width() / 2) - this->x());
                this->move(QPoint(e->globalPos().x() - (this->width() / 2), this->y()));
            }
            this->move(this->frameGeometry().topLeft() + (e->pos() - _dragPos));
        }

        if (!_mousePress.testFlag(Edge::None)) { //Change Rectangle
            QRect newRect = _rubberband->frameGeometry();
            if (_mousePress.testFlag(Edge::Left)) {
                newRect.setLeft(e->globalPos().x());
            }
            if (_mousePress.testFlag(Edge::Right)) {
                newRect.setRight(e->globalPos().x());
            }
            if (newRect.right() - newRect.left() < this->minimumWidth()) {
                newRect.setLeft(this->frameGeometry().x());
            }
            if (_mousePress.testFlag(Edge::Top)) {
                newRect.setTop(e->globalPos().y());
            }
            if (_mousePress.testFlag(Edge::Bottom)) {
                newRect.setBottom(e->globalPos().y());
            }
            if (newRect.bottom() - newRect.top() < this->minimumHeight()) {
                newRect.setTop(this->frameGeometry().y());
            }
            this->setGeometry(newRect);
            _rubberband->setGeometry(newRect);
        }
    } else {
        updateCursorShape(e->globalPos());
    }
}

void FramelessWindow::mouseHover(QHoverEvent *e) {
    updateCursorShape(this->mapToGlobal(e->pos()));
}

void FramelessWindow::updateCursorShape(const QPoint &pos) {
    if (this->isFullScreen() || this->isMaximized()) {
        if (_cursorchanged) {
            this->unsetCursor();
        }
        return;
    }
    if (!_leftButtonPressed) {
        calculateCursorPosition(pos, this->frameGeometry(), _mouseMove);
        _cursorchanged = true;
        if (_mouseMove.testFlag(Edge::TopLeft) || _mouseMove.testFlag(Edge::BottomRight)) {
            this->setCursor(Qt::SizeFDiagCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::TopRight) || _mouseMove.testFlag(Edge::BottomLeft)) {
            this->setCursor(Qt::SizeBDiagCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::Top) || _mouseMove.testFlag(Edge::Bottom)) {
            this->setCursor(Qt::SizeVerCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::Left) || _mouseMove.testFlag(Edge::Right)) {
            this->setCursor(Qt::SizeHorCursor);
            return;
        }
        this->unsetCursor();
        _cursorchanged = false;
    }
}

void FramelessWindow::calculateCursorPosition(const QPoint &aPos, const QRect &aFrameRect, Edges &aEdge) {
    int x = aPos.x(), y = aPos.y();
    if (x >= aFrameRect.x() && y >= aFrameRect.y()) {
        x -= aFrameRect.x();
        y -= aFrameRect.y();

        int edge = 0;
        if (x <= c_border) { //Left
            edge += Edge::Left;
        } else if (x <= aFrameRect.width() - c_border) { //Center

        } else if (x <= aFrameRect.width()) { //Right
            edge += Edge::Right;
        }

        if (y <= c_border) { //Top
            edge += Edge::Top;
        } else if (y <= aFrameRect.height() - c_border) { //Center

        } else if (y <= aFrameRect.height()) { //Bottom
            edge += Edge::Bottom;
        }

        aEdge = static_cast<Edge>(edge);
    }
}
