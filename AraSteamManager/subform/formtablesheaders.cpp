#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

FormTablesHeaders::FormTablesHeaders(QWidget *parent): QWidget(parent), ui(new Ui::FormTablesHeaders){
    ui->setupUi(this);
}

FormTablesHeaders::~FormTablesHeaders(){
    delete ui;
}

void FormTablesHeaders::resizeEvent(QResizeEvent *event){
    ui->TableWidgetHollow->horizontalHeader()->setVisible(true);
    int hollowHorizontalHeader=ui->TableWidgetHollow->horizontalHeader()->isVisible()?ui->TableWidgetHollow->horizontalHeader()->height():0;
    int hollowVerticalHeader=ui->TableWidgetHollow->verticalHeader()->width();
    ui->TableWidgetHollow->setGeometry(0,0,ui->TableWidgetHollow->horizontalHeader()->isVisible()?_verticalHeaderWidth+ui->TableWidgetHollow->horizontalHeader()->width():_verticalHeaderWidth
                                        ,ui->TableWidgetHollow->verticalHeader()->isVisible()?_horizontalHeaderHeight+ui->TableWidgetHollow->verticalHeader()->height():_horizontalHeaderHeight);
    ui->TableWidgetVerticalHeader->setGeometry(0,ui->TableWidgetHollow->height(),_verticalHeaderWidth,this->height()-_horizontalHeaderHeight);
    ui->TableWidgetHorizontalHeader->setGeometry(ui->TableWidgetHollow->width(),0,this->width()-_verticalHeaderWidth,_horizontalHeaderHeight);
    ui->TableWidgetContent->setGeometry(_verticalHeaderWidth,_horizontalHeaderHeight,this->width()-_verticalHeaderWidth,this->height()-_horizontalHeaderHeight);
    qDebug()<<hollowHorizontalHeader<<hollowVerticalHeader<<ui->TableWidgetHollow->geometry();
}
