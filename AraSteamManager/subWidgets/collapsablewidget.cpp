#include "collapsablewidget.h"
#include "classes/common/theme.h"
#include "classes/common/images.h"

#include <QPropertyAnimation>

CollapsableWidget::CollapsableWidget(QWidget *aParent)
: QFrame(aParent), animationDuration(DEFAULT_DURATION) {
    toggleButton = new QToolButton(this);
    headerLine = new QFrame(this);
    toggleAnimation = new QParallelAnimationGroup(this);
    contentArea = new QScrollArea(this);
    mainLayout = new QGridLayout(this);

    toggleButton->setStyleSheet("QToolButton {border: none;}");
    toggleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toggleButton->setIcon(QIcon(Images::scrollBarRight()));
    toggleButton->setCheckable(true);
    toggleButton->setChecked(false);

    headerLine->setFrameShape(QFrame::HLine);
    headerLine->setFrameShadow(QFrame::Sunken);
    headerLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    contentArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // start out collapsed
    contentArea->setMaximumHeight(0);
    contentArea->setMinimumHeight(0);

    // let the entire widget grow and shrink with its content
    toggleAnimation->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
    toggleAnimation->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
    toggleAnimation->addAnimation(new QPropertyAnimation(contentArea, "maximumHeight"));

    mainLayout->setVerticalSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    int row = 0;
    mainLayout->addWidget(toggleButton, row, 0, 1, 1, Qt::AlignLeft);
    mainLayout->addWidget(headerLine, row++, 2, 1, 1);
    mainLayout->addWidget(contentArea, row, 0, 1, 3);
    QFrame::setLayout(mainLayout);

    connect(toggleButton, &QToolButton::toggled, this, &CollapsableWidget::toggle);
}

void CollapsableWidget::toggle(bool aExpanded) {
    toggleButton->setIcon(aExpanded ? QIcon(Images::scrollBarDown()) : QIcon(Images::scrollBarRight()));
    toggleAnimation->setDirection(aExpanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
    toggleAnimation->start();

    this->isExpanded = aExpanded;
}

void CollapsableWidget::setContentLayout(QLayout &aContentLayout) {
    delete contentArea->layout();
    contentArea->setLayout(&aContentLayout);
    collapsedHeight = sizeHint().height() - contentArea->maximumHeight();

    updateHeights();
}

void CollapsableWidget::setLayout(QLayout *aLayout) {
    setContentLayout(*aLayout);
}

void CollapsableWidget::setTitle(const QString &aTitle) {
    toggleButton->setText(aTitle);
}

QString CollapsableWidget::title() {
    return toggleButton->text();
}

void CollapsableWidget::setDuration(const int aAnimationDuration) {
    animationDuration = aAnimationDuration;
}

void CollapsableWidget::updateHeights() {
    int contentHeight = contentArea->layout()->sizeHint().height();

    for (int i = 0; i < toggleAnimation->animationCount() - 1; ++i) {
        QPropertyAnimation* SectionAnimation = static_cast<QPropertyAnimation*>(toggleAnimation->animationAt(i));
        SectionAnimation->setDuration(animationDuration);
        SectionAnimation->setStartValue(collapsedHeight);
        SectionAnimation->setEndValue(collapsedHeight + contentHeight);
    }

    QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation*>(toggleAnimation->animationAt(toggleAnimation->animationCount() - 1));
    contentAnimation->setDuration(animationDuration);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentHeight);

    toggleAnimation->setDirection(isExpanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
    toggleAnimation->start();
}
