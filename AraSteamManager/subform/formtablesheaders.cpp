#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

FormTablesHeaders::FormTablesHeaders(int a_rowHeaders, int a_columnHeaders, int a_rowContent, int a_columnContent, bool a_visibleHH, bool a_visibleVH, bool a_visibleH, bool a_visibleC, QWidget *parent): QWidget(parent), ui(new Ui::FormTablesHeaders){
    ui->setupUi(this);
#define ConnectSlots {
    connect(ui->TableWidgetContent->verticalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetVerticalHeader->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->verticalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetVerticalHeader->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionClicked,[=](int logicalIndex)
        {ui->TableWidgetContent->sortByColumn(logicalIndex,ui->TableWidgetHorizontalHeader->horizontalHeader()->sortIndicatorOrder());});
    connect(ui->TableWidgetHollow->horizontalHeader(),&QHeaderView::sectionClicked,[=](int logicalIndex)
        {ui->TableWidgetVerticalHeader->sortByColumn(logicalIndex,ui->TableWidgetHollow->horizontalHeader()->sortIndicatorOrder());});

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setColumnWidth(logicalIndex,newSize);});
    connect(ui->TableWidgetVerticalHeader->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setRowHeight(logicalIndex,newSize);});

    connect(ui->TableWidgetHollow->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetVerticalHeader->setColumnWidth(logicalIndex,newSize);});
    connect(ui->TableWidgetHollow->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetHorizontalHeader->setRowHeight(logicalIndex,newSize);});

    connect(ui->TableWidgetVerticalHeader->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int oldSize, int newSize){
        _verticalHeaderWidth+=(newSize-oldSize);
        this->resize(this->geometry().width(), this->geometry().height());
        });
    connect(ui->TableWidgetHorizontalHeader->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int oldSize, int newSize){
        _horizontalHeaderHeight+=(newSize-oldSize);
        this->resize(this->geometry().width(), this->geometry().height());
        });
#define ConnectSlotsEnd }
    ui->TableWidgetHollow->setRowCount(a_rowHeaders);
    ui->TableWidgetHorizontalHeader->setRowCount(a_rowHeaders);
    ui->TableWidgetHollow->setColumnCount(a_columnHeaders);
    ui->TableWidgetVerticalHeader->setColumnCount(a_columnHeaders);
    ui->TableWidgetContent->setRowCount(a_rowContent);
    ui->TableWidgetVerticalHeader->setRowCount(a_rowContent);
    ui->TableWidgetContent->setColumnCount(a_columnContent);
    ui->TableWidgetHorizontalHeader->setColumnCount(a_columnContent);

    SetHorizontalVisible(a_visibleHH);
    SetVerticalVisible(a_visibleVH);
    SetHollowVisible(a_visibleH);
    SetContentVisible(a_visibleC);

    ui->TableWidgetContent->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetContent->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetVerticalHeader->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetVerticalHeader->setSelectionMode(QAbstractItemView::NoSelection);

    _horizontalHeaderHeight=2;
    for (int i=0;i<ui->TableWidgetHollow->rowCount();i++) {
        _horizontalHeaderHeight+=ui->TableWidgetHollow->rowHeight(i);
        ui->TableWidgetHollow->setVerticalHeaderItem(i,new QTableWidgetItem("0"));
    }
    _verticalHeaderWidth=2;
    for (int i=0;i<ui->TableWidgetHollow->columnCount();i++) {
        _verticalHeaderWidth+=ui->TableWidgetHollow->columnWidth(i);
        ui->TableWidgetHollow->setHorizontalHeaderItem(i,new QTableWidgetItem("0"));
    }
}
FormTablesHeaders::~FormTablesHeaders(){
    delete ui;
}

void FormTablesHeaders::resizeEvent(QResizeEvent *event){
    int height=_visibleHorizontal||_visibleHollow?_visibleVertical||_visibleContent?_horizontalHeaderHeight+ui->TableWidgetHorizontalHeader->horizontalHeader()->height():this->height():0;
    int width=_visibleVertical||_visibleHollow?_visibleHorizontal||_visibleContent?_verticalHeaderWidth+ui->TableWidgetVerticalHeader->verticalHeader()->width():this->width():0;
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

void FormTablesHeaders::SetColumnCountHeaders(int a_columns){
    ui->TableWidgetHollow->setColumnCount(a_columns);
    ui->TableWidgetVerticalHeader->setColumnCount(a_columns);
    _verticalHeaderWidth=1;
    for (int i=0;i<ui->TableWidgetHollow->columnCount();i++) {
        _verticalHeaderWidth+=ui->TableWidgetHollow->columnWidth(i);
        ui->TableWidgetHollow->setHorizontalHeaderItem(i,new QTableWidgetItem("0"));
    }
}
int FormTablesHeaders::GetColumnCountHeaders(){
    return ui->TableWidgetHollow->columnCount();
}
void FormTablesHeaders::SetRowCountHeaders(int a_row){
    ui->TableWidgetHollow->setColumnCount(a_row);
    ui->TableWidgetVerticalHeader->setColumnCount(a_row);
    _horizontalHeaderHeight=1;
    for (int i=0;i<ui->TableWidgetHollow->rowCount();i++) {
        _horizontalHeaderHeight+=ui->TableWidgetHollow->rowHeight(i);
        ui->TableWidgetHollow->setVerticalHeaderItem(i,new QTableWidgetItem("0"));
    }
}
int FormTablesHeaders::GetRowCountHeaders(){
    return ui->TableWidgetHollow->rowCount();
}

void FormTablesHeaders::SetColumnWidthHeaders(int a_column, int a_width){
    ui->TableWidgetHollow->setColumnWidth(a_column,a_width);
}
int FormTablesHeaders::GetColumnWidthHeaders(int a_column){
    return ui->TableWidgetHollow->columnWidth(a_column);
}
void FormTablesHeaders::SetRowHeightHeaders(int a_row, int a_height){
    ui->TableWidgetHollow->setRowHeight(a_row,a_height);
}
int FormTablesHeaders::GetRowHeightHeaders(int a_row){
    return ui->TableWidgetHollow->rowHeight(a_row);
}

void FormTablesHeaders::SetColumnWidth(int a_column, int a_width){
    ui->TableWidgetContent->setColumnWidth(a_column,a_width);
}
int FormTablesHeaders::GetColumnWidth(int a_column){
    return ui->TableWidgetContent->columnWidth(a_column);
}
void FormTablesHeaders::SetRowHeight(int a_row, int a_height){
    ui->TableWidgetContent->setRowHeight(a_row,a_height);
}
int FormTablesHeaders::GetRowHeight(int a_row){
    return ui->TableWidgetContent->rowHeight(a_row);
}

void FormTablesHeaders::SetHorizontalVisible(bool a_visible){
    _visibleHorizontal=a_visible;
    ui->TableWidgetHorizontalHeader->setVisible(_visibleHorizontal);
    ui->TableWidgetContent->horizontalHeader()->setVisible(!_visibleHorizontal);
}
void FormTablesHeaders::SetVerticalVisible(bool a_visible){
    _visibleVertical=a_visible;
    ui->TableWidgetVerticalHeader->setVisible(_visibleVertical);
    ui->TableWidgetContent->verticalHeader()->setVisible(!_visibleVertical);
}
void FormTablesHeaders::SetHollowVisible(bool a_visible){
    _visibleHollow=a_visible;
    ui->TableWidgetHollow->setVisible(_visibleHollow);
    ui->TableWidgetVerticalHeader->horizontalHeader()->setVisible(!_visibleHollow);
    ui->TableWidgetHorizontalHeader->verticalHeader()->setVisible(!_visibleHollow);
}
void FormTablesHeaders::SetContentVisible(bool a_visible){
    _visibleContent=a_visible;
    ui->TableWidgetContent->setVisible(_visibleContent);
}

void FormTablesHeaders::SetWidgetHollow(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetHollow->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetWidgetHorizontalHeader(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetHorizontalHeader->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetWidgetVerticalHeader(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetVerticalHeader->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetWidgetContent(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetContent->setCellWidget(a_row, a_column, a_widget);
}

void FormTablesHeaders::SetItemHollow(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHollow->setItem(a_row, a_column, a_item);
}
void FormTablesHeaders::SetItemHorizontalHeader(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setItem(a_row, a_column, a_item);
}
void FormTablesHeaders::SetItemVerticalHeader(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetVerticalHeader->setItem(a_row, a_column, a_item);
}
void FormTablesHeaders::SetItemContent(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetContent->setItem(a_row, a_column, a_item);
}

QTableWidgetItem* FormTablesHeaders::ItemHollow(int a_row, int a_column){
    return ui->TableWidgetHollow->item(a_row, a_column);
}
QTableWidgetItem* FormTablesHeaders::ItemHorizontalHeader(int a_row, int a_column){
    return ui->TableWidgetHorizontalHeader->item(a_row, a_column);
}
QTableWidgetItem* FormTablesHeaders::ItemVerticalHeader(int a_row, int a_column){
    return ui->TableWidgetVerticalHeader->item(a_row, a_column);
}
QTableWidgetItem* FormTablesHeaders::ItemContent(int a_row, int a_column){
    return ui->TableWidgetContent->item(a_row, a_column);
}
/*
void FormTablesHeaders::SetSelectHollow(int a_row, int a_column, bool a_select){

}
void FormTablesHeaders::SetSelectHorizontalHeader(int a_row, int a_column, bool a_select){

}
void FormTablesHeaders::SetSelectVerticalHeader(int a_row, int a_column, bool a_select){

}
void FormTablesHeaders::SetSelectContent(int a_row, int a_column, bool a_select){

}

bool FormTablesHeaders::IsSelectedHollow(int a_row, int a_column){

}
bool FormTablesHeaders::IsSelectedHorizontalHeader(int a_row, int a_column){

}
bool FormTablesHeaders::IsSelectedVerticalHeader(int a_row, int a_column){

}
bool FormTablesHeaders::IsSelectedContent(int a_row, int a_column){

}
*/
void FormTablesHeaders::SetVisibleRowContent(int a_row, bool a_visible){
    ui->TableWidgetContent->setRowHidden(a_row, !a_visible);
    ui->TableWidgetVerticalHeader->setRowHidden(a_row, !a_visible);
}
void FormTablesHeaders::SetVisibleColumnContent(int a_column, bool a_visible){
    ui->TableWidgetContent->setColumnHidden(a_column, !a_visible);
    ui->TableWidgetHorizontalHeader->setColumnHidden(a_column, !a_visible);
}
void FormTablesHeaders::SetVisibleRowHeaders(int a_row, bool a_visible){
    ui->TableWidgetHollow->setRowHidden(a_row, !a_visible);
    ui->TableWidgetHorizontalHeader->setRowHidden(a_row, !a_visible);
}
void FormTablesHeaders::SetVisibleColumnHeaders(int a_column, bool a_visible){
    ui->TableWidgetHollow->setColumnHidden(a_column, !a_visible);
    ui->TableWidgetVerticalHeader->setColumnHidden(a_column, !a_visible);
}

void FormTablesHeaders::SetVisibleAll(bool a_visibleHollow, bool a_visibleHH, bool a_visibleVH, bool a_visibleContent){
    _visibleHollow=a_visibleHollow;
    _visibleContent=a_visibleContent;
    _visibleHorizontal=a_visibleHH;
    _visibleVertical=a_visibleVH;
    ui->TableWidgetHollow->setVisible(a_visibleHollow);
    ui->TableWidgetHorizontalHeader->setVisible(a_visibleHH);
    ui->TableWidgetVerticalHeader->setVisible(a_visibleVH);
    ui->TableWidgetContent->setVisible(a_visibleContent);
    ui->TableWidgetVerticalHeader->horizontalHeader()->setVisible(!a_visibleHollow);
    ui->TableWidgetHorizontalHeader->verticalHeader()->setVisible(!a_visibleHollow);
    ui->TableWidgetContent->horizontalHeader()->setVisible(!a_visibleHH);
    ui->TableWidgetContent->verticalHeader()->setVisible(!a_visibleVH);
    int height=_visibleHorizontal||_visibleHollow?_visibleVertical||_visibleContent?_horizontalHeaderHeight+ui->TableWidgetHorizontalHeader->horizontalHeader()->height():this->height():0;
    int width=_visibleVertical||_visibleHollow?_visibleHorizontal||_visibleContent?_verticalHeaderWidth+ui->TableWidgetVerticalHeader->verticalHeader()->width():this->width():0;
    ui->TableWidgetHollow->setGeometry(0,0,width,height);
    ui->TableWidgetVerticalHeader->setGeometry(0,height,width,this->height()-height);
    ui->TableWidgetHorizontalHeader->setGeometry(width,0,this->width()-width,height);
    ui->TableWidgetContent->setGeometry(width,height,this->width()-width,this->height()-height);
}
void FormTablesHeaders::SetHorizontalHeaderTitle(int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setHorizontalHeaderItem(a_column, a_item);
}
/*
void FormTablesHeaders::ResizeRowsToContentsContents(){

}
void FormTablesHeaders::ResizeColumnsToContentsContents(){

}

void FormTablesHeaders::ResizeRowsToContentsHeaders(){

}
void FormTablesHeaders::ResizeColumnsToContentsHeaders(){

}

void FormTablesHeaders::ResizeRowToContentsContents(int a_row){

}
void FormTablesHeaders::ResizeColumnToContentsContents(int a_column){

}

void FormTablesHeaders::ResizeRowToContentsHeaders(int a_row){

}
void FormTablesHeaders::ResizeColumnToContentsHeaders(int a_column){

}
*/
void FormTablesHeaders::ResizeRowContent(int a_row, int a_height){
    ui->TableWidgetVerticalHeader->setRowHeight(a_row, a_height);
}
void FormTablesHeaders::ResizeColumnContent(int a_column, int a_width){
    ui->TableWidgetHorizontalHeader->setColumnWidth(a_column, a_width);
}
void FormTablesHeaders::ResizeRowHeaders(int a_row, int a_height){
    ui->TableWidgetHollow->setRowHeight(a_row, a_height);
}
void FormTablesHeaders::ResizeColumnHeaders(int a_column, int a_width){
    ui->TableWidgetHollow->setColumnWidth(a_column, a_width);
}

QTableWidget *FormTablesHeaders::GetTableHollow(){
    return ui->TableWidgetHollow;
}

QTableWidget *FormTablesHeaders::GetTableHH(){
    return ui->TableWidgetHorizontalHeader;
}

QTableWidget *FormTablesHeaders::GetTableVH(){
    return ui->TableWidgetVerticalHeader;
}

QTableWidget *FormTablesHeaders::GetTableContent(){
    return ui->TableWidgetContent;
}

void FormTablesHeaders::InsertColumn(int a_columns){
    ui->TableWidgetHorizontalHeader->insertColumn(a_columns);
    ui->TableWidgetContent->insertColumn(a_columns);
}
void FormTablesHeaders::InsertColumnHeaders(int a_columns){
    ui->TableWidgetHollow->insertColumn(a_columns);
    ui->TableWidgetVerticalHeader->insertColumn(a_columns);
}
void FormTablesHeaders::RemoveColumn(int a_columns){
    ui->TableWidgetHorizontalHeader->removeColumn(a_columns);
    ui->TableWidgetContent->removeColumn(a_columns);
}
void FormTablesHeaders::RemoveColumnHeaders(int a_columns){
    ui->TableWidgetHollow->removeColumn(a_columns);
    ui->TableWidgetVerticalHeader->removeColumn(a_columns);
}
void FormTablesHeaders::SetHorizontalHeaderText(int a_index, QString a_text){
    ui->TableWidgetHorizontalHeader->setHorizontalHeaderItem(a_index,new QTableWidgetItem(a_text));
    ui->TableWidgetContent->setHorizontalHeaderItem(a_index,new QTableWidgetItem(a_text));
}

void FormTablesHeaders::InsertRow(int a_row){
    ui->TableWidgetVerticalHeader->insertRow(a_row);
    ui->TableWidgetContent->insertRow(a_row);
}
void FormTablesHeaders::RemoveRow(int a_row){
    ui->TableWidgetVerticalHeader->removeRow(a_row);
    ui->TableWidgetContent->removeRow(a_row);
}
