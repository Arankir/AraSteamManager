#include "progressbardelegate.h"
#include <QDebug>
#include <QApplication>

ProgressBarDelegate::ProgressBarDelegate(QObject *parent) : QStyledItemDelegate( parent ) {

}

void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    int cur = 0, max = 0;
    QString progress = index.data().toString();
    QRegularExpression reg("(\\d+)\\/(\\d+)");
    if (reg.match(progress).hasMatch()) {
        cur = reg.match(progress).captured(1).toInt();
        max = reg.match(progress).captured(2).toInt();
    }


    // Set up a QStyleOptionProgressBar to precisely mimic the
    // environment of a progress bar.
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.state = QStyle::State_Enabled;
    progressBarOption.direction = QApplication::layoutDirection();
    QRect r = option.rect;
    r.setHeight(32);
    r.moveTop(option.rect.top() + (option.rect.height() - 32) / 2 + 5);
//    qDebug() << option.rect << option.rect.top() << option.rect.left() << option.rect.right() << option.rect.bottom() << option.rect.center() << r;
    progressBarOption.rect = r;
//    progressBarOption.fontMetrics = QApplication::fontMetrics();
    progressBarOption.minimum = 0;
    progressBarOption.maximum = max;
    progressBarOption.progress = cur;
    progressBarOption.text = progress;
    progressBarOption.textAlignment = Qt::AlignCenter;

    // Draw the progress bar onto the view.
    QStyledItemDelegate::paint( painter, option, QModelIndex() );
    if (max > 0) {
        progressBarOption.textVisible = true;
        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
    }

}
