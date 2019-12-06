#include "formfavorites.h"
#include "ui_formfavorites.h"

FormFavorites::FormFavorites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFavorites)
{
    ui->setupUi(this);
}

FormFavorites::~FormFavorites()
{
    delete ui;
}

void FormFavorites::on_pushButton_clicked()
{
    ui->label->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
    ui->label_2->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
}
