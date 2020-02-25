#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

FormTablesHeaders::FormTablesHeaders(QWidget *parent): QWidget(parent), ui(new Ui::FormTablesHeaders){
    ui->setupUi(this);
}

FormTablesHeaders::~FormTablesHeaders(){
    delete ui;
}

void FormTablesHeaders::resizeEvent(QResizeEvent *event){
    int height=_horizontalHeaderHeight+ui->TableWidgetHollow->horizontalHeader()->height();
    int width=_verticalHeaderWidth+ui->TableWidgetHollow->verticalHeader()->width();
    ui->TableWidgetHollow->setGeometry(0,0,width,height);
    ui->TableWidgetVerticalHeader->setGeometry(0,height,width,this->height()-height);
    ui->TableWidgetHorizontalHeader->setGeometry(width,0,this->width()-width,height);
    ui->TableWidgetContent->setGeometry(width,height,this->width()-_verticalHeaderWidth,this->height()-_horizontalHeaderHeight);
}

void FormTablesHeaders::SetColumnCount(int a_col){
    _columnCount=a_col;
    ui->TableWidgetHorizontalHeader->setColumnCount(_columnCount);
    ui->TableWidgetContent->setColumnCount(_columnCount);
}

void FormTablesHeaders::SetRowCount(int a_row){
    _rowCount=a_row;
    ui->TableWidgetVerticalHeader->setRowCount(_rowCount);
    ui->TableWidgetContent->setRowCount(_rowCount);
}

void FormTablesHeaders::SetHorizontalVisible(bool a_visible){
    ui->TableWidgetHollow->setVisible(_visibleVertical&&a_visible);
    ui->TableWidgetVerticalHeader->horizontalHeader()->setVisible(!a_visible);
    ui->TableWidgetHorizontalHeader->setVisible(a_visible);
    ui->TableWidgetContent->horizontalHeader()->setVisible(!a_visible);
}

void FormTablesHeaders::SetVerticalVisible(bool a_visible){
    ui->TableWidgetHollow->setVisible(_visibleHorizontal&&a_visible);
    ui->TableWidgetVerticalHeader->setVisible(a_visible);
    ui->TableWidgetHorizontalHeader->verticalHeader()->setVisible(!a_visible);
    ui->TableWidgetContent->verticalHeader()->setVisible(!a_visible);
}
