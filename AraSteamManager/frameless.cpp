#include "frameless.h"
#include <QDebug>

const int c_border = 7;
const int c_catchWidth = 33;

FrameLess::FrameLess(QWidget *target):
                    _target(target),
                    _cursorchanged(false),
                    _leftButtonPressed(false),
                    _dragPos(QPoint()) {
    _target->setMouseTracking(true);
    _target->setWindowFlags(Qt::FramelessWindowHint);
    _target->setAttribute(Qt::WA_Hover);
    _target->installEventFilter(this);
    _rubberband = new QRubberBand(QRubberBand::Rectangle);
}

bool FrameLess::eventFilter(QObject *o, QEvent*e) {
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
        return _target->eventFilter(o, e);
    }
    }
}

void FrameLess::mouseRealese(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        _leftButtonPressed = false;
        _dragStart = false;
    }
}

void FrameLess::mouseLeave(QEvent *e) {
    Q_UNUSED(e);
    if (!_leftButtonPressed) {
        _target->unsetCursor();
    }
}

void FrameLess::mousePress(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        _leftButtonPressed = true;
        calculateCursorPosition(e->globalPos(), _target->frameGeometry(), _mousePress);
        if (!_mousePress.testFlag(Edge::None)) {
            _rubberband->setGeometry(_target->frameGeometry());
        }
        //qDebug()<<(e->globalPos() - _target->pos()).y();
        if (_target->rect().marginsRemoved(QMargins(c_border, c_border, c_border, c_border)).contains(e->pos()) &&
           ((e->globalPos() - _target->pos()).y() < c_catchWidth)) {
            _dragStart = true;
            _dragPos = e->pos();
        }
    }
}

void FrameLess::mouseMove(QMouseEvent *e) {
    if (_leftButtonPressed) {
        if (_target->isMaximized()) {
            _target->showNormal();
        }
        if (_dragStart) { //Change Position
            if (_target->normalGeometry().x() + _target->normalGeometry().width() < e->globalPos().x()) {
                _dragPos.setX(e->globalPos().x() - (_target->width() / 2) - _target->x());
                _target->move(QPoint(e->globalPos().x() - (_target->width() / 2), _target->y()));
            }
            _target->move(_target->frameGeometry().topLeft() + (e->pos() - _dragPos));
        }

        if (!_mousePress.testFlag(Edge::None)) { //Change Rectangle
            QRect newRect = _rubberband->frameGeometry();
            if (_mousePress.testFlag(Edge::Left)) {
                newRect.setLeft(e->globalPos().x());
            }
            if (_mousePress.testFlag(Edge::Right)) {
                newRect.setRight(e->globalPos().x());
            }
            if (newRect.right() - newRect.left() < _target->minimumWidth()) {
                newRect.setLeft(_target->frameGeometry().x());
            }
            if (_mousePress.testFlag(Edge::Top)) {
                newRect.setTop(e->globalPos().y());
            }
            if (_mousePress.testFlag(Edge::Bottom)) {
                newRect.setBottom(e->globalPos().y());
            }
            if (newRect.bottom() - newRect.top() < _target->minimumHeight()) {
                newRect.setTop(_target->frameGeometry().y());
            }
            _target->setGeometry(newRect);
            _rubberband->setGeometry(newRect);
        }
    } else {
        updateCursorShape(e->globalPos());
    }
}

void FrameLess::mouseHover(QHoverEvent *e) {
    updateCursorShape(_target->mapToGlobal(e->pos()));
}

void FrameLess::updateCursorShape(const QPoint &pos) {
    if (_target->isFullScreen() || _target->isMaximized()) {
        if (_cursorchanged) {
            _target->unsetCursor();
        }
        return;
    }
    if (!_leftButtonPressed) {
        calculateCursorPosition(pos, _target->frameGeometry(), _mouseMove);
        _cursorchanged = true;
        if (_mouseMove.testFlag(Edge::TopLeft) || _mouseMove.testFlag(Edge::BottomRight)) {
            _target->setCursor(Qt::SizeFDiagCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::TopRight) || _mouseMove.testFlag(Edge::BottomLeft)) {
            _target->setCursor(Qt::SizeBDiagCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::Top) || _mouseMove.testFlag(Edge::Bottom)) {
            _target->setCursor(Qt::SizeVerCursor);
            return;
        }
        if (_mouseMove.testFlag(Edge::Left) || _mouseMove.testFlag(Edge::Right)) {
            _target->setCursor(Qt::SizeHorCursor);
            return;
        }
        _target->unsetCursor();
        _cursorchanged = false;
    }
}

void FrameLess::calculateCursorPosition(const QPoint &aPos, const QRect &aFrameRect, Edges &aEdge) {
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
