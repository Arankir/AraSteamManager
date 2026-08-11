#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QRubberBand>
#include <QLabel>
#include <QProgressBar>
#include "classes/common/settings.h"

namespace Ui {
class FramelessWindow;
}

class FramelessWindow : public QMainWindow {
    Q_OBJECT

public slots:
    void updateSettings();

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

    static FramelessWindow *createWithWidget(QWidget *widget);

    FramelessWindow();
    FramelessWindow(QWidget *target);
    ~FramelessWindow();
    void setWidget(QWidget *target);
    void animateResize(int width, int height);
    void setStatus(const QString &statusName = "", int progress = 0, int maxProgress = 0);

    void clearStatus();
    void show();
protected:
    bool eventFilter(QObject *o, QEvent *e) override;
    void mouseHover(QHoverEvent*);
    void mouseLeave(QEvent*);
    void mousePress(QMouseEvent*);
    void mouseRealese(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void updateCursorShape(const QPointF &);
    void calculateCursorPosition(const QPointF &, const QRect &, Edges &);
    void buttonExit_Clicked();
    void buttonMaximize_Clicked();
    void buttonMinimize_Clicked();

private:
    void updateIcons();

    Ui::FramelessWindow *ui;
    QWidget *target_ = nullptr;
    QRubberBand *rubberband_ = nullptr;
    bool cursorchanged_;
    bool leftButtonPressed_;
    Edges mousePress_ = Edge::None;
    Edges mouseMove_ = Edge::None;

    QPoint dragPos_;
    bool dragStart_ = false;

    QLabel *statusLabel_;
    QProgressBar *statusProgressBar_;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FramelessWindow::Edges);
#endif // FRAMELESSWINDOW_H
