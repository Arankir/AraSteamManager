#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);

    QTreeWidgetItem *item2 = new QTreeWidgetItem(ui->treeWidget);

    QTreeWidgetItem *item3 = new QTreeWidgetItem(ui->treeWidget);

    QTreeWidgetItem *item4 = new QTreeWidgetItem(item);

    QTreeWidgetItem *item5 = new QTreeWidgetItem(item);

    QTreeWidgetItem *item6 = new QTreeWidgetItem(item2);

    QTreeWidgetItem *item7 = new QTreeWidgetItem(item2);

    QTreeWidgetItem *item8 = new QTreeWidgetItem(item5);

    QTreeWidgetItem *item9 = new QTreeWidgetItem(item5);

    QTreeWidgetItem *item10 = new QTreeWidgetItem(item2);

    QTreeWidgetItem *item11 = new QTreeWidgetItem(item3);

    QTreeWidgetItem *item12 = new QTreeWidgetItem(ui->treeWidget);

//    QComboBox *cb = new QComboBox();
//    cb->addItems(QStringList() << "1" << "3" << "5");

    ui->treeWidget->setItemWidget(item, 0, new QLabel("Type"));
    ui->treeWidget->setItemWidget(item2, 0, new QLabel("Difficulty"));
    ui->treeWidget->setItemWidget(item3, 0, new QLabel("Mission"));
    ui->treeWidget->setItemWidget(item4, 0, new QCheckBox("Singleplayer"));
    ui->treeWidget->setItemWidget(item5, 0, new QCheckBox("Multiplayer"));
    ui->treeWidget->setItemWidget(item6, 0, new QCheckBox("Easy"));
    ui->treeWidget->setItemWidget(item7, 0, new QCheckBox("Normal"));
    ui->treeWidget->setItemWidget(item8, 0, new QCheckBox("Play with bots"));
    ui->treeWidget->setItemWidget(item9, 0, new QCheckBox("Play with humans"));
    ui->treeWidget->setItemWidget(item10, 0, new QCheckBox("Hell"));
    ui->treeWidget->setItemWidget(item11, 0, new QCheckBox("Any"));
    ui->treeWidget->setItemWidget(item12, 0, new QCheckBox("Need party"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

