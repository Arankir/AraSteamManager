#ifndef MYTABLE_H
#define MYTABLE_H

#include <QTableView>
#include <QObject>
#include <QStandardItemModel>

#include "subWidgets/models/filters.h"

class MyTable : public QTableView {
    Q_OBJECT
public:
    MyTable(QWidget *parent = nullptr);
    ~MyTable();

    void init();
    int widthColumns(bool includeScrollBar = true);
    int heightColumns(bool includeScrollBar = true);

    void setModel(QAbstractItemModel*) override;
    virtual void setFilter(FilterModel *model);
    QAbstractItemModel *originalModel();
    FilterModel *filter();

private:
    QAbstractItemModel *model_ = nullptr;
    FilterModel *filter_ = nullptr;
};

#endif // MYTABLE_H
