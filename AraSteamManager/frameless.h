#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QRubberBand>
#include <QtCore/QObject>
#include <QtCore/QEvent>
#include <QtCore/QRect>
#include <QtCore/QPoint>
#include <QtCore/Qt>
#include <QtGui/QHoverEvent>
#include <QtGui/QMouseEvent>

class FrameLess : public QObject {
    Q_OBJECT

public:
    enum Edge {
        None        = 0x0, //00000000
        Left        = 0x1, //00000001
        Top         = 0x2, //00000010
        Right       = 0x4, //00000100
        Bottom      = 0x8, //00001000
        TopLeft     = 0x3, //00000011
        TopRight    = 0x6, //00000110
        BottomLeft  = 0x9, //00001001
        BottomRight = 0xC, //00001100
    };
    Q_ENUM(Edge);
    Q_DECLARE_FLAGS(Edges, Edge);

    FrameLess(QWidget *target);

protected:
    bool eventFilter(QObject *o, QEvent *e) override;
    void mouseHover(QHoverEvent*);
    void mouseLeave(QEvent*);
    void mousePress(QMouseEvent*);
    void mouseRealese(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void updateCursorShape(const QPoint &);
    void calculateCursorPosition(const QPoint &, const QRect &, Edges &);

private:
    QWidget *_target = nullptr;
    QRubberBand *_rubberband = nullptr;
    bool _cursorchanged;
    bool _leftButtonPressed;
    Edges _mousePress = Edge::None;
    Edges _mouseMove = Edge::None;

    QPoint _dragPos;
    bool _dragStart = false;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FrameLess::Edges);
