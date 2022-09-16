#include "framelesswindow.h"
#include "ui_framelesswindow.h"
#include "classes/common/images.h"

#include <QtGui/QMouseEvent>
#include <QPropertyAnimation>

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
                    target_(target),
                    cursorchanged_(false),
                    leftButtonPressed_(false),
                    dragPos_(QPoint()),
                    statusProgressBar_(new QProgressBar()) {
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Hover);
    this->installEventFilter(this);
    ui->statusbar->addPermanentWidget(statusProgressBar_, 0);
    setStatus();

    if (target_ != nullptr) {
        ui->centralwidget->layout()->addWidget(target_);
    }
    rubberband_ = new QRubberBand(QRubberBand::Rectangle);

    ui->ButtonMinimize  ->setFlat(true);
    ui->ButtonMaximize  ->setFlat(true);
    ui->ButtonExit      ->setFlat(true);

    connect(ui->ButtonMaximize, &QPushButton::clicked, this, &FramelessWindow::buttonMaximize_Clicked);
    connect(ui->ButtonMinimize, &QPushButton::clicked, this, &FramelessWindow::buttonMinimize_Clicked);
    connect(ui->ButtonExit,     &QPushButton::clicked, this, &FramelessWindow::buttonExit_Clicked);
    updateIcons();
}

void FramelessWindow::setWidget(QWidget *target) {
    target_ = target;
    ui->centralwidget->layout()->addWidget(target_);
}

void FramelessWindow::updateIcons() {
    ui->LabelLogo->setPixmap(QPixmap(Images::logo()).scaled(30, 30));
    ui->ButtonExit          ->setIcon(QIcon(Images::closeWindow()));
    ui->ButtonMinimize      ->setIcon(QIcon(Images::minimizeWindow()));
    if (this->isMaximized()) {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::maximizeWindow()));
    }
}

void FramelessWindow::updateSettings() {
    updateIcons();
}

void FramelessWindow::buttonExit_Clicked() {
    if (target_) {
        target_->close();
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
    if (target_) {
        delete target_;
    }
    delete ui;
}

void FramelessWindow::animateResize(const int &width, const int &height) {
//    qDebug() << QSize(this->width(), this->height()) << QSize(width, height);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "size");
    connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
    animation->setDuration(500);
    animation->setStartValue(QSize(this->width(), this->height()));
    animation->setEndValue(QSize(width, height));
    animation->start();
}

void FramelessWindow::setStatus(const QString &statusName, const int &progress, const int &maxProgress) {
    // showMessage(const QString & message, int timeout = 0)
    if (statusName == "") {
        clearStatus();
    } else {
        statusProgressBar_->setVisible(true);
        statusBar()->showMessage(statusName);
        statusProgressBar_->setValue(progress);
        statusProgressBar_->setMaximum(maxProgress);
    }
}

void FramelessWindow::clearStatus() {
    statusBar()->clearMessage();
    statusProgressBar_->setVisible(false);
}

void FramelessWindow::show() {
    if (this->isMaximized()) {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::maximizeWindow()));
    }
    QMainWindow::show();
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
        leftButtonPressed_ = false;
        dragStart_ = false;
    }
}

void FramelessWindow::mouseLeave(QEvent *e) {
    Q_UNUSED(e);
    if (!leftButtonPressed_) {
        this->unsetCursor();
    }
}

void FramelessWindow::mousePress(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        leftButtonPressed_ = true;
        calculateCursorPosition(e->globalPosition(), this->frameGeometry(), mousePress_);
        if (!mousePress_.testFlag(Edge::None)) {
            rubberband_->setGeometry(this->frameGeometry());
        }
        //qDebug()<<(e->globalPos() - _target->pos()).y();
        if (this->rect().marginsRemoved(QMargins(c_border, c_border, c_border, c_border)).contains(e->pos()) &&
           ((e->globalPosition() - this->pos()).y() < ui->FrameTitleWindow->height())) {
            dragStart_ = true;
            dragPos_ = e->pos();
        }
    }
}

void FramelessWindow::mouseMove(QMouseEvent *e) {
    if (leftButtonPressed_) {
        if (this->isMaximized()) {
            this->showNormal();
            ui->ButtonMaximize->setIcon(QIcon(Images::maximizeWindow()));
        }
        if (dragStart_) { //Change Position
            if (this->normalGeometry().x() + this->normalGeometry().width() < e->globalPosition().x()) {
                dragPos_.setX(e->globalPosition().x() - (this->width() / 2) - this->x());
                this->move(QPoint(e->globalPosition().x() - (this->width() / 2), this->y()));
            }
            this->move(this->frameGeometry().topLeft() + (e->pos() - dragPos_));
        }

        if (!mousePress_.testFlag(Edge::None)) { //Change Rectangle
            QRect newRect = rubberband_->frameGeometry();
            if (mousePress_.testFlag(Edge::Left)) {
                newRect.setLeft(e->globalPosition().x());
            }
            if (mousePress_.testFlag(Edge::Right)) {
                newRect.setRight(e->globalPosition().x());
            }
            if (newRect.right() - newRect.left() < this->minimumWidth()) {
                newRect.setLeft(this->frameGeometry().x());
            }
            if (mousePress_.testFlag(Edge::Top)) {
                newRect.setTop(e->globalPosition().y());
            }
            if (mousePress_.testFlag(Edge::Bottom)) {
                newRect.setBottom(e->globalPosition().y());
            }
            if (newRect.bottom() - newRect.top() < this->minimumHeight()) {
                newRect.setTop(this->frameGeometry().y());
            }
            this->setGeometry(newRect);
            rubberband_->setGeometry(newRect);
        }
    } else {
        updateCursorShape(e->globalPosition());
    }
}

void FramelessWindow::mouseHover(QHoverEvent *e) {
    updateCursorShape(this->mapToGlobal(e->position()));
}

void FramelessWindow::updateCursorShape(const QPointF &pos) {
    if (this->isFullScreen() || this->isMaximized()) {
        if (cursorchanged_) {
            this->unsetCursor();
        }
        return;
    }
    if (!leftButtonPressed_) {
        calculateCursorPosition(pos, this->frameGeometry(), mouseMove_);
        cursorchanged_ = true;
        if (mouseMove_.testFlag(Edge::TopLeft) || mouseMove_.testFlag(Edge::BottomRight)) {
            this->setCursor(Qt::SizeFDiagCursor);
            return;
        }
        if (mouseMove_.testFlag(Edge::TopRight) || mouseMove_.testFlag(Edge::BottomLeft)) {
            this->setCursor(Qt::SizeBDiagCursor);
            return;
        }
        if (mouseMove_.testFlag(Edge::Top) || mouseMove_.testFlag(Edge::Bottom)) {
            this->setCursor(Qt::SizeVerCursor);
            return;
        }
        if (mouseMove_.testFlag(Edge::Left) || mouseMove_.testFlag(Edge::Right)) {
            this->setCursor(Qt::SizeHorCursor);
            return;
        }
        this->unsetCursor();
        cursorchanged_ = false;
    }
}

void FramelessWindow::calculateCursorPosition(const QPointF &aPos, const QRect &aFrameRect, Edges &aEdge) {
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
