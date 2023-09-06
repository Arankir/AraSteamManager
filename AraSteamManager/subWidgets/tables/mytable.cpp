#include "mytable.h"
#include <QApplication>
#include <QHeaderView>

MyTable::MyTable(QWidget *aParent): QTableView{aParent} {
    init();
}

MyTable::~MyTable() {
//    if (filter_) {
//        delete filter_;
//    }
}

void MyTable::init() {
    setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    setSelectionBehavior(QAbstractItemView::SelectRows);
    setShowGrid(false);
    setSortingEnabled(true);
    horizontalHeader()->setStretchLastSection(true);
    verticalHeader()->setVisible(false);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setIconSize(QSize(32, 32));
}

int MyTable::widthColumns(bool aIncludeScrollBar) {
    int width = 0;
    for (int i = 0; i < model()->columnCount(); ++i) {
        width += columnWidth(i) + 1;
    }
    if (aIncludeScrollBar) {
        width += qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    }
    return width;
}

int MyTable::heightColumns(bool aIncludeScrollBar) {
    int height = 0;
    for (int i = 0; i < model()->rowCount(); ++i) {
        height += rowHeight(i) + 1;
    }
    if (aIncludeScrollBar) {
        height += qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    }
    return height;
}

void MyTable::setModel(QAbstractItemModel *aModel) {
    model_ = aModel;
    if (filter_) {
        filter_->setSourceModel(model_);
        QTableView::setModel(filter_);
    } else {
        QTableView::setModel(model_);
    }
}

void MyTable::setFilter(FilterModel *aModel) {
    filter_ = aModel;
    if (model_) {
        QTableView::setModel(filter_);
        filter_->setSourceModel(model_);
    }
}

QAbstractItemModel *MyTable::originalModel() {
    return model_;
}

FilterModel *MyTable::filter() {
    return filter_;
}
