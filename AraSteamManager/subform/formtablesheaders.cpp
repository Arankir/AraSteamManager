#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

FormTablesHeaders::FormTablesHeaders(QWidget *parent): QWidget(parent), ui(new Ui::FormTablesHeaders){
    ui->setupUi(this);
    connect(ui->TableWidgetContent->verticalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetVerticalHeader->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->verticalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetVerticalHeader->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setColumnWidth(logicalIndex,newSize);});
    connect(ui->TableWidgetVerticalHeader->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setRowHeight(logicalIndex,newSize);});

    connect(ui->TableWidgetHollow->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetVerticalHeader->setColumnWidth(logicalIndex,newSize);});
    connect(ui->TableWidgetHollow->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetHorizontalHeader->setRowHeight(logicalIndex,newSize);});

    connect(ui->TableWidgetHorizontalHeader,&QTableWidget::hideColumn,[=](int column)
            {ui->TableWidgetContent->setColumnHidden(column,true);});
    connect(ui->TableWidgetHorizontalHeader,&QTableWidget::showColumn,[=](int column)
            {ui->TableWidgetContent->setColumnHidden(column,false);});
    connect(ui->TableWidgetVerticalHeader,&QTableWidget::hideRow,[=](int row)
            {ui->TableWidgetContent->setRowHidden(row,true);});
    connect(ui->TableWidgetVerticalHeader,&QTableWidget::showRow,[=](int row)
            {ui->TableWidgetContent->setRowHidden(row,false);});

    connect(ui->TableWidgetHollow->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int oldSize, int newSize)
    {if(logicalIndex==ui->TableWidgetHollow->columnCount()-1){
            _verticalHeaderWidth+=(newSize-oldSize);
            int height=_horizontalHeaderHeight+ui->TableWidgetHollow->horizontalHeader()->height();
            int width=_verticalHeaderWidth+ui->TableWidgetHollow->verticalHeader()->width();
            ui->TableWidgetHollow->setGeometry(0,0,width,height);
            ui->TableWidgetVerticalHeader->setGeometry(0,height,width,this->height()-height);
            ui->TableWidgetHorizontalHeader->setGeometry(width,0,this->width()-width,height);
            ui->TableWidgetContent->setGeometry(width,height,this->width()-width,this->height()-height);
        }});
    connect(ui->TableWidgetHollow->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int oldSize, int newSize)
    {if(logicalIndex==ui->TableWidgetHollow->rowCount()-1){
            _horizontalHeaderHeight+=(newSize-oldSize);
            int height=_horizontalHeaderHeight+ui->TableWidgetHollow->horizontalHeader()->height();
            int width=_verticalHeaderWidth+ui->TableWidgetHollow->verticalHeader()->width();
            ui->TableWidgetHollow->setGeometry(0,0,width,height);
            ui->TableWidgetVerticalHeader->setGeometry(0,height,width,this->height()-height);
            ui->TableWidgetHorizontalHeader->setGeometry(width,0,this->width()-width,height);
            ui->TableWidgetContent->setGeometry(width,height,this->width()-width,this->height()-height);
        }});

    _horizontalHeaderHeight=0;
    for (int i=0;i<ui->TableWidgetHollow->rowCount();i++) {
        _horizontalHeaderHeight+=ui->TableWidgetHollow->rowHeight(i);
        ui->TableWidgetHollow->setVerticalHeaderItem(i,new QTableWidgetItem("0"));
    }
    _horizontalHeaderHeight+=1;
    _verticalHeaderWidth=0;
    for (int i=0;i<ui->TableWidgetHollow->columnCount();i++) {
        _verticalHeaderWidth+=ui->TableWidgetHollow->columnWidth(i);
        ui->TableWidgetHollow->setHorizontalHeaderItem(i,new QTableWidgetItem("0"));
    }
    _verticalHeaderWidth+=1;
    ui->TableWidgetHorizontalHeader->setColumnHidden(2,true);
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
    ui->TableWidgetContent->setGeometry(width,height,this->width()-width,this->height()-height);
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
