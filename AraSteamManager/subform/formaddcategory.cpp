#include "formaddcategory.h"
#include "ui_formaddcategory.h"

FormAddCategory::FormAddCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAddCategory)
{
    ui->setupUi(this);
    Words=Setting.GetWords("addcategory");
    ui->LineEditTitle->setPlaceholderText(Words[0]);
    ui->CheckBoxNoValue->setText(Words[1]);
    ui->ButtonAddValue->setText(Words[2]);
    ui->ButtonCancel->setText(Words[3]);
    ui->CheckBoxSelectAll->setText(Words[4]);
    ui->ButtonAccept->setText(Words[5]);
}

FormAddCategory::~FormAddCategory()
{
    delete ui;
}
