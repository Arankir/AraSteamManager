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
    ~CollapsableWidget();
    void setContentLayout(QLayout &contentLayout);
    void setLayout(QLayout *layout);
    void setTitle(const QString &title);
    QString title();
    void setDuration(int animationDuration);
    void updateHeights();
public slots:
    void toggle(bool collapsed);

private:
    QGridLayout *mainLayout_;
    QToolButton *toggleButton_;
    QFrame *headerLine_;
    QParallelAnimationGroup *toggleAnimation_;
    QScrollArea *contentArea_;
    int animationDuration_;
    int collapsedHeight_;
    bool isExpanded_ = false;

};

#endif // COLLAPSABLEWIDGET_H
