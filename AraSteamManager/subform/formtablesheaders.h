#ifndef FORMTABLESHEADERS_H
#define FORMTABLESHEADERS_H

#include <QWidget>
#include <QtDebug>

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

private:
    Ui::FormTablesHeaders *ui;
    bool _visibleHorizontal=true;
    bool _visibleVertical=true;
    int _columnCount=0;
    int _rowCount=0;
    int _horizontalHeaderHeight=30;
    int _verticalHeaderWidth=30;
};

#endif // FORMTABLESHEADERS_H
