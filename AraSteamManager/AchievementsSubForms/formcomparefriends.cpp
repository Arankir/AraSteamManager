#include "formcomparefriends.h"
#include "ui_formcomparefriends.h"

#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>

FormCompareFriends::FormCompareFriends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompareFriends)
{
    ui->setupUi(this);

    QStandardItemModel *model=new QStandardItemModel();

    QFile file("C://grades.txt");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);

        QString line = stream.readLine();
        QStringList list = line.simplified().split(',');
        model->setHorizontalHeaderLabels(list);

        int row = 0;
        QStandardItem *newItem = nullptr;
        while (!stream.atEnd()) {
            line = stream.readLine();
            if (!line.startsWith('#') && line.contains(',')) {
                list = line.simplified().split(',');
                for (int col = 0; col < list.length(); ++col){
                    newItem = new QStandardItem(list.at(col));
                    model->setItem(row, col, newItem);
                }
                ++row;
            }
        }
    }
    file.close();

    ui->tableView->setModel(model);

}

FormCompareFriends::~FormCompareFriends()
{
    delete ui;
}
