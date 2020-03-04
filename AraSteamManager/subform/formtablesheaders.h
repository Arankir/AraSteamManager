#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>
#include <QScrollBar>
#include <QTableWidgetItem>

namespace Ui {
class FormTablesHeaders;
}

class FormTablesHeaders : public QWidget
{
    Q_OBJECT

public:
    explicit FormTablesHeaders(int rowHeaders, int columnHeaders, int rowContent, int columnContent, bool visibleHH, bool visibleVH, bool visibleH, bool visibleC, QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);

    void SetColumnCount(int col);
    int GetColumnCount() {return _columnCount;}
    void SetRowCount(int row);
    int GetRowCount() {return _rowCount;}

    void SetColumnCountHeaders(int columns);
    int GetColumnCountHeaders();
    void SetRowCountHeaders(int rows);
    int GetRowCountHeaders();

    void SetColumnWidthHeaders(int column, int width);
    int GetColumnWidthHeaders(int column);
    void SetRowHeightHeaders(int row, int height);
    int GetRowHeightHeaders(int row);

    void SetColumnWidth(int column, int width);
    int GetColumnWidth(int column);
    void SetRowHeight(int row, int height);
    int GetRowHeight(int row);

    void SetHorizontalVisible(bool visible);
    bool GetHorizontalVisible() {return _visibleHorizontal;}

    void SetVerticalVisible(bool visible);
    bool GetVerticalVisible() {return _visibleVertical;}

    void SetHollowVisible(bool visible);
    bool GetHollowVisible() {return _visibleHollow;}

    void SetContentVisible(bool visible);
    bool GetContentVisible() {return _visibleContent;}

    void SetWidgetHollow(int row, int column, QWidget *widget);
    void SetWidgetHorizontalHeader(int row, int column, QWidget *widget);
    void SetWidgetVerticalHeader(int row, int column, QWidget *widget);
    void SetWidgetContent(int row, int column, QWidget *widget);

    void SetItemHollow(int row, int column, QTableWidgetItem *item);
    void SetItemHorizontalHeader(int row, int column, QTableWidgetItem *item);
    void SetItemVerticalHeader(int row, int column, QTableWidgetItem *item);
    void SetItemContent(int row, int column, QTableWidgetItem *item);

    QTableWidgetItem* ItemHollow(int row, int column);
    QTableWidgetItem* ItemHorizontalHeader(int row, int column);
    QTableWidgetItem* ItemVerticalHeader(int row, int column);
    QTableWidgetItem* ItemContent(int row, int column);
    /*
    void SetSelectHollow(int row, int column, bool select);
    void SetSelectHorizontalHeader(int row, int column, bool select);
    void SetSelectVerticalHeader(int row, int column, bool select);
    void SetSelectContent(int row, int column, bool select);

    bool IsSelectedHollow(int row, int column);
    bool IsSelectedHorizontalHeader(int row, int column);
    bool IsSelectedVerticalHeader(int row, int column);
    bool IsSelectedContent(int row, int column);
    */
    void SetVisibleRowContent(int row, bool visible);
    void SetVisibleColumnContent(int column, bool visible);
    void SetVisibleRowHeaders(int row, bool visible);
    void SetVisibleColumnHeaders(int column, bool visible);

    void SetVisibleAll(bool visibleHollow, bool visibleHH, bool visibleVH, bool visibleContent);

    void SetHorizontalHeaderTitle(int column, QTableWidgetItem *item);
    //void SetVerticalHeaderTitle(int row, QTableWidgetItem item);
    /*
    void ResizeRowsToContentsContents();
    void ResizeColumnsToContentsContents();
    void ResizeRowsToContentsHeaders();
    void ResizeColumnsToContentsHeaders();

    void ResizeRowToContentsContents(int row);
    void ResizeColumnToContentsContents(int column);
    void ResizeRowToContentsHeaders(int row);
    void ResizeColumnToContentsHeaders(int column);
    */
    void ResizeRowContent(int row, int height);
    void ResizeColumnContent(int column, int width);
    void ResizeRowHeaders(int row, int height);
    void ResizeColumnHeaders(int column, int width);

    QTableWidget *GetTableHollow();
    QTableWidget *GetTableHH();
    QTableWidget *GetTableVH();
    QTableWidget *GetTableContent();

public slots:
    void InsertColumn(int a_columns);
    void InsertColumnHeaders(int a_columns);
    void RemoveColumn(int a_columns);
    void RemoveColumnHeaders(int a_columns);
    void SetHorizontalHeaderText(int a_index, QString a_text);
    void InsertRow(int a_row);
    void RemoveRow(int a_row);
private:
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal=true;
    bool _visibleVertical=true;
    bool _visibleHollow=true;//!!!!
    bool _visibleContent=true;//!!!!
    int _columnCount=0;
    int _rowCount=0;
    int _horizontalHeaderHeight=0;
    int _verticalHeaderWidth=0;


};

#endif // FORMTABLESHEADERS_H
