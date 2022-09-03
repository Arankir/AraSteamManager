#ifndef COLLAPSABLEWIDGET_H
#define COLLAPSABLEWIDGET_H

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>

class CollapsableWidget : public QFrame {
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    static const int DEFAULT_DURATION = 300;

    explicit CollapsableWidget(QWidget *parent = nullptr);
    void setContentLayout(QLayout &contentLayout);
    void setLayout(QLayout *layout);
    void setTitle(const QString &aTitle);
    QString title();
    void setDuration(const int animationDuration);
    void updateHeights();
public slots:
    void toggle(bool collapsed);

private:
    QGridLayout *mainLayout;
    QToolButton *toggleButton;
    QFrame *headerLine;
    QParallelAnimationGroup *toggleAnimation;
    QScrollArea *contentArea;
    int animationDuration;
    int collapsedHeight;
    bool isExpanded = false;

};

#endif // COLLAPSABLEWIDGET_H
