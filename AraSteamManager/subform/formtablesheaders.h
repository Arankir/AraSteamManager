#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>
#include <QScrollBar>
#include <QTableWidgetItem>

namespace Ui {
class FormTablesHeaders;
}

enum class TableType{
    standart,
    compare
};

class FormTablesHeaders : public QWidget
{
    Q_OBJECT

public:
    explicit FormTablesHeaders(int rowHeaders, int rowContent, int column, TableType type, QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);

    void SetColumnCount(int col);
    void SetRowCount(int row);
    void SetRowCountHeaders(int rows);
    void SetColumnWidth(int column, int width);
    void SetRowHeight(int row, int height);
    void SetRowHeightHeaders(int row, int height);
    int GetColumnCount();
    int GetRowCount();
    int GetRowCountHeaders();
    int GetColumnWidth(int column);
    int GetRowHeight(int row);
    int GetRowHeightHeaders(int row);

    void SetWidgetHorizontalHeader(int row, int column, QWidget *widget);
    void SetWidgetContent(int row, int column, QWidget *widget);

    void SetItemHorizontalHeader(int row, int column, QTableWidgetItem *item);
    void SetItemContent(int row, int column, QTableWidgetItem *item);

    QTableWidgetItem* ItemHorizontalHeader(int row, int column);
    QTableWidgetItem* ItemContent(int row, int column);

    void SetVisibleRowContent(int row, bool visible);
    void SetVisibleColumn(int column, bool visible);
    void SetVisibleRowHeaders(int row, bool visible);

    void SetHorizontalTitle(int column, QTableWidgetItem *item);
    void ChangeHorizontalTitle(int column, QString text);
    void SetVerticalTitle(int row, QTableWidgetItem *item);
    void SetVerticalHeaderTitle(int row, QTableWidgetItem *item);

    void ResizeRowsToContentsContents();
    //void ResizeColumnsToContents();
    void ResizeRowsToContentsHeaders();

    void ResizeRowToContentsContents(int row);
    //void ResizeColumnToContents(int column);
    void ResizeRowToContentsHeaders(int row);

    void ResizeRowContent(int row, int height);
    void ResizeColumn(int column, int width);
    void ResizeRowHeaders(int row, int height);
    void SetType(TableType newType);

    QTableWidget *GetTableHH();
    QTableWidget *GetTableContent();

public slots:
    void InsertColumn(int a_columns);
    void RemoveColumn(int a_columns);
    void InsertRow(int a_row);
    void RemoveRow(int a_row);
private:
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal=true;
    int _horizontalHeaderHeight=0;
    TableType _currentType;


};

#endif // FORMTABLESHEADERS_H
