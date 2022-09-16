#include "collapsablewidget.h"
#include "classes/common/theme.h"
#include "classes/common/images.h"

#include <QPropertyAnimation>

CollapsableWidget::CollapsableWidget(QWidget *aParent)
: QFrame(aParent), animationDuration_(DEFAULT_DURATION) {
    toggleButton_ = new QToolButton(this);
    headerLine_ = new QFrame(this);
    toggleAnimation_ = new QParallelAnimationGroup(this);
    contentArea_ = new QScrollArea(this);
    mainLayout_ = new QGridLayout(this);

    toggleButton_->setStyleSheet("QToolButton {border: none;}");
    toggleButton_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toggleButton_->setIcon(QIcon(Images::scrollBarRight()));
    toggleButton_->setCheckable(true);
    toggleButton_->setChecked(false);

    headerLine_->setFrameShape(QFrame::HLine);
    headerLine_->setFrameShadow(QFrame::Sunken);
    headerLine_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    contentArea_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // start out collapsed
    contentArea_->setMaximumHeight(0);
    contentArea_->setMinimumHeight(0);

    // let the entire widget grow and shrink with its content
    toggleAnimation_->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
    toggleAnimation_->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
    toggleAnimation_->addAnimation(new QPropertyAnimation(contentArea_, "maximumHeight"));

    mainLayout_->setVerticalSpacing(0);
    mainLayout_->setContentsMargins(0, 0, 0, 0);

    int row = 0;
    mainLayout_->addWidget(toggleButton_, row, 0, 1, 1, Qt::AlignLeft);
    mainLayout_->addWidget(headerLine_, row++, 2, 1, 1);
    mainLayout_->addWidget(contentArea_, row, 0, 1, 3);
    QFrame::setLayout(mainLayout_);

    connect(toggleButton_, &QToolButton::toggled, this, &CollapsableWidget::toggle);
}

void CollapsableWidget::toggle(bool aExpanded) {
    toggleButton_->setIcon(aExpanded ? QIcon(Images::scrollBarDown()) : QIcon(Images::scrollBarRight()));
    toggleAnimation_->setDirection(aExpanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
    toggleAnimation_->start();

    this->isExpanded_ = aExpanded;
}

void CollapsableWidget::setContentLayout(QLayout &aContentLayout) {
    delete contentArea_->layout();
    contentArea_->setLayout(&aContentLayout);
    collapsedHeight_ = sizeHint().height() - contentArea_->maximumHeight();

    updateHeights();
}

void CollapsableWidget::setLayout(QLayout *aLayout) {
    setContentLayout(*aLayout);
}

void CollapsableWidget::setTitle(const QString &aTitle) {
    toggleButton_->setText(aTitle);
}

QString CollapsableWidget::title() {
    return toggleButton_->text();
}

void CollapsableWidget::setDuration(const int &aAnimationDuration) {
    animationDuration_ = aAnimationDuration;
}

void CollapsableWidget::updateHeights() {
    int contentHeight = contentArea_->layout()->sizeHint().height();

    for (int i = 0; i < toggleAnimation_->animationCount() - 1; ++i) {
        QPropertyAnimation* SectionAnimation = static_cast<QPropertyAnimation*>(toggleAnimation_->animationAt(i));
        SectionAnimation->setDuration(animationDuration_);
        SectionAnimation->setStartValue(collapsedHeight_);
        SectionAnimation->setEndValue(collapsedHeight_ + contentHeight);
    }

    QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation*>(toggleAnimation_->animationAt(toggleAnimation_->animationCount() - 1));
    contentAnimation->setDuration(animationDuration_);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentHeight);

    toggleAnimation_->setDirection(isExpanded_ ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
    toggleAnimation_->start();
}
