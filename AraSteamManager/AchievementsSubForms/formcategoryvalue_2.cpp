#include "formcategoryvalue_2.h"
#include "ui_formcategoryvalue_2.h"

FormCategoryValue_2::FormCategoryValue_2(QWidget *parent): QWidget(parent), ui(new Ui::FormCategoryValue_2) {
    ui->setupUi(this);
    ui->ListWidgetValue->viewport()->setAcceptDrops(true);
}

FormCategoryValue_2::~FormCategoryValue_2() {
    delete ui;
}

void FormCategoryValue_2::on_ButtonDelete_clicked()
{
    qDebug()<<ui->ListWidgetValue->itemWidget(ui->ListWidgetValue->item(0));
}
