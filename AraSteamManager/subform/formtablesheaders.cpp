#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

FormTablesHeaders::FormTablesHeaders(int a_rowHeaders, int a_rowContent, int a_column, TableType a_type, QWidget *parent): QWidget(parent), ui(new Ui::FormTablesHeaders){
    ui->setupUi(this);
#define ConnectSlots {
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionClicked,[=](int logicalIndex)
            {ui->TableWidgetContent->sortByColumn(logicalIndex,ui->TableWidgetHorizontalHeader->horizontalHeader()->sortIndicatorOrder());});
    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setColumnWidth(logicalIndex,newSize);});

    connect(ui->TableWidgetHorizontalHeader->verticalHeader(),&QHeaderView::sectionResized,[=](int logicalIndex, int oldSize, int newSize){
        _horizontalHeaderHeight+=(newSize-oldSize);
        this->resize(this->geometry().width(), this->geometry().height());
        });
#define ConnectSlotsEnd }
    ui->TableWidgetHorizontalHeader->setRowCount(a_rowHeaders);
    ui->TableWidgetContent->setRowCount(a_rowContent);
    ui->TableWidgetContent->setColumnCount(a_column);
    ui->TableWidgetHorizontalHeader->setColumnCount(a_column);

    SetType(a_type);

    ui->TableWidgetContent->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetHorizontalHeader->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetContent->setSelectionMode(QAbstractItemView::NoSelection);

    _horizontalHeaderHeight=2;
    for (int i=0;i<ui->TableWidgetHorizontalHeader->rowCount();i++)
        _horizontalHeaderHeight+=ui->TableWidgetHorizontalHeader->rowHeight(i);
}
FormTablesHeaders::~FormTablesHeaders(){
    delete ui;
}

void FormTablesHeaders::resizeEvent(QResizeEvent*){
    int height= _visibleHorizontal?_horizontalHeaderHeight+ui->TableWidgetHorizontalHeader->horizontalHeader()->height():0;
    ui->TableWidgetHorizontalHeader->setGeometry(0,0,this->width(),height);
    ui->TableWidgetContent->setGeometry(0,height,this->width(),this->height()-height);
}

void FormTablesHeaders::SetColumnCount(int a_col){
    ui->TableWidgetHorizontalHeader->setColumnCount(a_col);
    ui->TableWidgetContent->setColumnCount(a_col);
}
int FormTablesHeaders::GetColumnCount(){
    return ui->TableWidgetHorizontalHeader->columnCount();
}
void FormTablesHeaders::SetRowCount(int a_row){
    ui->TableWidgetContent->setRowCount(a_row);
}
int FormTablesHeaders::GetRowCount(){
    return ui->TableWidgetContent->rowCount();
}
void FormTablesHeaders::SetRowCountHeaders(int a_row){
    ui->TableWidgetHorizontalHeader->setColumnCount(a_row);
    _horizontalHeaderHeight=1;
    for (int i=0;i<ui->TableWidgetHorizontalHeader->rowCount();i++) {
        _horizontalHeaderHeight+=ui->TableWidgetHorizontalHeader->rowHeight(i);
    }
}
int FormTablesHeaders::GetRowCountHeaders(){
    return ui->TableWidgetHorizontalHeader->rowCount();
}

void FormTablesHeaders::SetRowHeightHeaders(int a_row, int a_height){
    ui->TableWidgetHorizontalHeader->setRowHeight(a_row,a_height);
}
int FormTablesHeaders::GetRowHeightHeaders(int a_row){
    return ui->TableWidgetHorizontalHeader->rowHeight(a_row);
}

void FormTablesHeaders::SetColumnWidth(int a_column, int a_width){
    ui->TableWidgetHorizontalHeader->setColumnWidth(a_column,a_width);
    //ui->TableWidgetContent->setColumnWidth(a_column,a_width);
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

void FormTablesHeaders::SetWidgetHorizontalHeader(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetHorizontalHeader->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetWidgetContent(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetContent->setCellWidget(a_row, a_column, a_widget);
}

void FormTablesHeaders::SetItemHorizontalHeader(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setItem(a_row, a_column, a_item);
}
void FormTablesHeaders::SetItemContent(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetContent->setItem(a_row, a_column, a_item);
}

QTableWidgetItem* FormTablesHeaders::ItemHorizontalHeader(int a_row, int a_column){
    return ui->TableWidgetHorizontalHeader->item(a_row, a_column);
}
QTableWidgetItem* FormTablesHeaders::ItemContent(int a_row, int a_column){
    return ui->TableWidgetContent->item(a_row, a_column);
}

void FormTablesHeaders::SetVisibleRowContent(int a_row, bool a_visible){
    ui->TableWidgetContent->setRowHidden(a_row, !a_visible);
}
void FormTablesHeaders::SetVisibleColumn(int a_column, bool a_visible){
    ui->TableWidgetContent->setColumnHidden(a_column, !a_visible);
    ui->TableWidgetHorizontalHeader->setColumnHidden(a_column, !a_visible);
}
void FormTablesHeaders::SetVisibleRowHeaders(int a_row, bool a_visible){
    ui->TableWidgetHorizontalHeader->setRowHidden(a_row, !a_visible);
}

void FormTablesHeaders::SetHorizontalTitle(int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setHorizontalHeaderItem(a_column, a_item);
    ui->TableWidgetContent->setHorizontalHeaderItem(a_column, a_item);
}
void FormTablesHeaders::ChangeHorizontalTitle(int a_column, QString a_text){
    ui->TableWidgetHorizontalHeader->horizontalHeaderItem(a_column)->setText(a_text);
    ui->TableWidgetContent->horizontalHeaderItem(a_column)->setText(a_text);
}
void FormTablesHeaders::SetVerticalTitle(int a_row, QTableWidgetItem *a_item){
    ui->TableWidgetContent->setVerticalHeaderItem(a_row, a_item);
}
void FormTablesHeaders::SetVerticalHeaderTitle(int a_row, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setVerticalHeaderItem(a_row, a_item);
}
void FormTablesHeaders::ResizeRowsToContentsContents(){
    ui->TableWidgetContent->resizeRowsToContents();
}
//void FormTablesHeaders::ResizeColumnsToContents(){

//}
void FormTablesHeaders::ResizeRowsToContentsHeaders(){
    ui->TableWidgetHorizontalHeader->resizeRowsToContents();
}
void FormTablesHeaders::ResizeRowToContentsContents(int a_row){
    ui->TableWidgetContent->resizeRowToContents(a_row);
}
//void FormTablesHeaders::ResizeColumnToContents(int a_column){

//}
void FormTablesHeaders::ResizeRowToContentsHeaders(int a_row){
    ui->TableWidgetHorizontalHeader->resizeRowToContents(a_row);
}

void FormTablesHeaders::ResizeRowContent(int a_row, int a_height){
    ui->TableWidgetContent->setRowHeight(a_row, a_height);
}
void FormTablesHeaders::ResizeColumn(int a_column, int a_width){
    ui->TableWidgetHorizontalHeader->setColumnWidth(a_column, a_width);
}
void FormTablesHeaders::ResizeRowHeaders(int a_row, int a_height){
    ui->TableWidgetHorizontalHeader->setRowHeight(a_row, a_height);
}

void FormTablesHeaders::SetType(TableType a_newType){
    _currentType=a_newType;
    switch (_currentType) {
    case TableType::compare:{
        _visibleHorizontal=true;
        ui->TableWidgetHorizontalHeader->setVisible(true);
        ui->TableWidgetContent->horizontalHeader()->setVisible(false);
        //resize;
        break;
    }
    case TableType::standart:{
        _visibleHorizontal=false;
        ui->TableWidgetHorizontalHeader->setVisible(false);
        ui->TableWidgetContent->horizontalHeader()->setVisible(true);
        //resize;
        break;
    }
    }
    //!!!!!!!!!!!!!
}

QTableWidget *FormTablesHeaders::GetTableHH(){
    return ui->TableWidgetHorizontalHeader;
}
QTableWidget *FormTablesHeaders::GetTableContent(){
    return ui->TableWidgetContent;
}

void FormTablesHeaders::InsertColumn(int a_columns){
    ui->TableWidgetHorizontalHeader->insertColumn(a_columns);
    ui->TableWidgetContent->insertColumn(a_columns);
}
void FormTablesHeaders::RemoveColumn(int a_columns){
    ui->TableWidgetHorizontalHeader->removeColumn(a_columns);
    ui->TableWidgetContent->removeColumn(a_columns);
}
void FormTablesHeaders::InsertRow(int a_row){
    ui->TableWidgetContent->insertRow(a_row);
}
void FormTablesHeaders::RemoveRow(int a_row){
    ui->TableWidgetContent->removeRow(a_row);
}
