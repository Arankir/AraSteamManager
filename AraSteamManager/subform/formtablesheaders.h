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
    explicit FormTablesHeaders(int rowHeaders, int columnHeaders, int rowContent, int columnContent, bool visibleHH, bool visibleVH, QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);

    void SetColumnCount(int col);
    int GetColumnCount() {return _columnCount;}
    void SetRowCount(int row);
    int GetRowCount() {return _rowCount;}

    void SetColumnCountHeaders(int columns);
    int GetColumnCountHeaders();
    void SetRowCountHeaders(int row);
    int GetRowCountHeaders();

    void SetHorizontalVisible(bool visible);
    bool GetHorizontalVisible() {return _visibleHorizontal;}

    void SetVerticalVisible(bool visible);
    bool GetVerticalVisible() {return _visibleVertical;}

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
