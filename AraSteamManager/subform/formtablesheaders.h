#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>
#include <QScrollBar>

namespace Ui {
class FormTablesHeaders;
}

class FormTablesHeaders : public QWidget
{
    Q_OBJECT

public:
    explicit FormTablesHeaders(QWidget *parent = nullptr);
    ~FormTablesHeaders();
    void resizeEvent(QResizeEvent *event);
    void SetColumnCount(int col);
    int GetColumnCount() {return _columnCount;}
    void SetRowCount(int row);
    int GetRowCount() {return _rowCount;}
    void SetHorizontalVisible(bool visible);
    bool GetHorizontalVisible() {return _visibleHorizontal;}
    void SetVerticalVisible(bool visible);
    bool GetVerticalVisible() {return _visibleVertical;}

private:
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal=true;
    bool _visibleVertical=true;
    int _columnCount=0;
    int _rowCount=0;
    int _horizontalHeaderHeight=50;
    int _verticalHeaderWidth=100;


};

#endif // FORMTABLESHEADERS_H
