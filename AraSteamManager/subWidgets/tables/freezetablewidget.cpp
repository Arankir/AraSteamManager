/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "freezetablewidget.h"

#include <QScrollBar>
#include <QHeaderView>
#include <QDebug>

FreezeTableWidget::FreezeTableWidget(QWidget *aParent) : QTableView(aParent) {
    frozenTableView = new QTableView(this);
    frozenTableView->setObjectName("FreezeRow");

    //connect the headers and scrollbars of both tableviews together
    connect(horizontalHeader(), &QHeaderView::sectionResized, this, &FreezeTableWidget::updateSectionWidth);
    connect(verticalHeader(), &QHeaderView::sectionResized, this, &FreezeTableWidget::updateSectionHeight);

    connect(frozenTableView->horizontalScrollBar(), &QAbstractSlider::valueChanged, horizontalScrollBar(), &QAbstractSlider::setValue);
    connect(horizontalScrollBar(), &QAbstractSlider::valueChanged, frozenTableView->horizontalScrollBar(), &QAbstractSlider::setValue);
}

FreezeTableWidget::~FreezeTableWidget() {
    delete frozenTableView;
}

void FreezeTableWidget::initFreezeTable() {
    frozenTableView->setModel(model());
    frozenTableView->setSelectionModel(selectionModel());
    frozenTableView->setFocusPolicy(Qt::NoFocus);

    frozenTableView->horizontalHeader()->hide();
    frozenTableView->verticalHeader()->hide();
    frozenTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    frozenTableView->setRowHeight(0, rowHeight(0));
    for (int row = 1; row < model()->rowCount(); ++row) {
        frozenTableView->setRowHidden(row, true);
    }

    frozenTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frozenTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frozenTableView->show();

    updateFrozenTableGeometry();

    setHorizontalScrollMode(ScrollPerPixel);
    setVerticalScrollMode(ScrollPerPixel);
    frozenTableView->setHorizontalScrollMode(ScrollPerPixel);
}

void FreezeTableWidget::updateSectionWidth(int aLogicalIndex, int /* aOldSize */, int aNewSize) {
    frozenTableView->setColumnWidth(aLogicalIndex, aNewSize);
}

void FreezeTableWidget::updateSectionHeight(int aLogicalIndex, int /* aOldSize */, int aNewSize) {
    if (aLogicalIndex == 0) {
        frozenTableView->setRowHeight(0, aNewSize);
        updateFrozenTableGeometry();
    }
}

void FreezeTableWidget::resizeEvent(QResizeEvent *aEvent) {
    QTableView::resizeEvent(aEvent);
    updateFrozenTableGeometry();
}

QModelIndex FreezeTableWidget::moveCursor(CursorAction aCursorAction, Qt::KeyboardModifiers aModifiers) {
    QModelIndex current = QTableView::moveCursor(aCursorAction, aModifiers);

    if (aCursorAction == MoveLeft && current.row() > 0 && visualRect(current).topLeft().y() < frozenTableView->rowHeight(0) ) {
        const int newValue = verticalScrollBar()->value() + visualRect(current).topLeft().y() - frozenTableView->rowHeight(0);
        verticalScrollBar()->setValue(newValue);
    }
    return current;
}

void FreezeTableWidget::scrollTo (const QModelIndex &aIndex, ScrollHint aHint) {
    if (aIndex.row() > 0) {
        QTableView::scrollTo(aIndex, aHint);
    }
}

void FreezeTableWidget::setModel(QAbstractItemModel *aModel) {
    QTableView::setModel(aModel);
    initFreezeTable();
}

void FreezeTableWidget::updateFrozenTableGeometry() {
    if (model()) {
        int size = 0;
        for (int i = 0; i < model()->rowCount(); ++i) {
            if (model()->headerData(i, Qt::Vertical).toString().length() > size) {
                size = model()->headerData(i, Qt::Vertical).toString().length();
            }
        }
        model()->setHeaderData(0, Qt::Vertical, model()->headerData(0, Qt::Vertical).toString().rightJustified(size, ' '));
        int ax = frameWidth() + verticalHeader()->width();// - frozenTableView->verticalHeader()->width() - 1;
        int ay = frameWidth() + horizontalHeader()->height();
        int aw = viewport()->width() + verticalHeader()->width();
        int ah = rowHeight(0);
        frozenTableView->setGeometry(ax, ay, aw, ah);
    }
}


