#include "freezerowstable.h"

#include <QScrollBar>
#include <QHeaderView>

FreezeRowsTable::FreezeRowsTable(QAbstractItemModel *aModel) {
    setModel(aModel);
    frozenTableView = new QTableView(this);

    init();

    //connect the headers and scrollbars of both tableviews together
    connect(horizontalHeader(), &QHeaderView::sectionResized, this, &FreezeRowsTable::updateSectionWidth);
    connect(verticalHeader(), &QHeaderView::sectionResized, this, &FreezeRowsTable::updateSectionHeight);

    connect(frozenTableView->horizontalScrollBar(), &QAbstractSlider::valueChanged, horizontalScrollBar(), &QAbstractSlider::setValue);
    connect(horizontalScrollBar(), &QAbstractSlider::valueChanged, frozenTableView->horizontalScrollBar(), &QAbstractSlider::setValue);
}

FreezeRowsTable::~FreezeRowsTable() {
    delete frozenTableView;
}

void FreezeRowsTable::init() {
    frozenTableView->setModel(model());
    frozenTableView->setFocusPolicy(Qt::NoFocus);
    frozenTableView->horizontalHeader()->hide();
    frozenTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    viewport()->stackUnder(frozenTableView);
    //  frozenTableView->setStyleSheet("QTableView { border: none;"
    //                                     "background-color: #8EDE21;"
    //                                     "selection-background-color: #999}"); //for demo purposes
    frozenTableView->setSelectionModel(selectionModel());
    for (int row = 1; row < model()->rowCount(); ++row) {
        frozenTableView->setRowHidden(row, true);
    }

    frozenTableView->setRowHeight(0, rowHeight(0));

    frozenTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frozenTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frozenTableView->show();

    updateFrozenTableGeometry();

    setHorizontalScrollMode(ScrollPerPixel);
    setVerticalScrollMode(ScrollPerPixel);
    frozenTableView->setHorizontalScrollMode(ScrollPerPixel);
}

void FreezeRowsTable::updateSectionWidth(int logicalIndex, int /* oldSize */, int newSize) {
    frozenTableView->setColumnWidth(logicalIndex, newSize);
}

void FreezeRowsTable::updateSectionHeight(int logicalIndex, int /* oldSize */, int newSize) {
    if (logicalIndex == 0) {
        frozenTableView->setRowHeight(0, newSize);
        updateFrozenTableGeometry();
    }
}

void FreezeRowsTable::resizeEvent(QResizeEvent *event) {
    QTableView::resizeEvent(event);
    updateFrozenTableGeometry();
}

QModelIndex FreezeRowsTable::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) {
    QModelIndex current = QTableView::moveCursor(cursorAction, modifiers);

    if (cursorAction == MoveLeft && current.row() > 0 && visualRect(current).topLeft().y() < frozenTableView->rowHeight(0) ){
        const int newValue = verticalScrollBar()->value() + visualRect(current).topLeft().y() - frozenTableView->rowHeight(0);
        verticalScrollBar()->setValue(newValue);
    }
    return current;
}

void FreezeRowsTable::scrollTo (const QModelIndex & index, ScrollHint hint) {
    if (index.row() > 0) {
        QTableView::scrollTo(index, hint);
    }
}

void FreezeRowsTable::updateFrozenTableGeometry() {
      frozenTableView->setGeometry(frameWidth(), frameWidth() + horizontalHeader()->height(), viewport()->width() + verticalHeader()->width(), rowHeight(0));
}
