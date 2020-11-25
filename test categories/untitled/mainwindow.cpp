#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, [=](QPoint pos) {
        QMenu *menu = createMenu();
        menu->popup(ui->treeWidget->viewport()->mapToGlobal(pos));
    });

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

    QSize s;
    auto ch1 = new QLabel("Type");
    s = ch1->sizeHint();
    s.rwidth() += 10;
    item->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item, 0, ch1);
    auto ch2 = new QLabel("Difficulty");
    s = ch2->sizeHint();
    s.rwidth() += 10;
    item2->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item2, 0, ch2);
    auto ch3 = new QLabel("Mission");
    s = ch3->sizeHint();
    s.rwidth() += 10;
    item3->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item3, 0, ch3);
    auto ch4 = new QCheckBox("Singleplayer");
    s = ch4->sizeHint();
    s.rwidth() += 10;
    item4->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item4, 0, ch4);
    auto ch5 = new QCheckBox("Multiplayer");
    s = ch5->sizeHint();
    s.rwidth() += 10;
    item5->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item5, 0, ch5);
    auto ch6 = new QCheckBox("Easy");
    s = ch6->sizeHint();
    s.rwidth() += 10;
    item6->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item6, 0, ch6);
    auto ch7 = new QCheckBox("Normal");
    s = ch7->sizeHint();
    s.rwidth() += 10;
    item7->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item7, 0, ch7);
    auto ch8 = new QCheckBox("Play with bots");
    s = ch8->sizeHint();
    s.rwidth() += 10;
    item8->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item8, 0, ch8);
    auto ch9 = new QCheckBox("Play with humans");
    s = ch9->sizeHint();
    s.rwidth() += 10;
    item9->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item9, 0, ch9);
    auto ch10 = new QCheckBox("Hell");
    s = ch10->sizeHint();
    s.rwidth() += 10;
    item10->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item10, 0, ch10);
    auto ch11 = new QCheckBox("Any");
    s = ch11->sizeHint();
    s.rwidth() += 10;
    item11->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item11, 0, ch11);
    auto ch12 = new QCheckBox("Need party");
    s = ch12->sizeHint();
    s.rwidth() += 10;
    item12->setSizeHint(0, s);
    ui->treeWidget->setItemWidget(item12, 0, ch12);

    ui->treeWidget->setItemWidget(item, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item2, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item3, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item4, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item5, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item6, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item7, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item8, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item9, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item10, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item11, 1, button("://create.png"));
    ui->treeWidget->setItemWidget(item12, 1, button("://create.png"));

    ui->treeWidget->setItemWidget(item, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item2, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item3, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item4, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item5, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item6, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item7, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item8, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item9, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item10, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item11, 2, button("://change.png"));
    ui->treeWidget->setItemWidget(item12, 2, button("://change.png"));

    ui->treeWidget->setItemWidget(item, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item2, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item3, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item4, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item5, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item6, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item7, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item8, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item9, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item10, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item11, 3, button("://delete.png"));
    ui->treeWidget->setItemWidget(item12, 3, button("://delete.png"));

    ui->treeWidget->resizeColumnToContents(0);
    ui->treeWidget->setColumnWidth(1, 40);
    ui->treeWidget->setColumnWidth(2, 40);
    ui->treeWidget->setColumnWidth(3, 40);

    qDebug() << item->sizeHint(0);
    qDebug() << item2->sizeHint(0);
    qDebug() << item3->sizeHint(0);
    qDebug() << item4->sizeHint(0);
    qDebug() << item5->sizeHint(0);
    qDebug() << item6->sizeHint(0);
    qDebug() << item7->sizeHint(0);
    qDebug() << item8->sizeHint(0);
    qDebug() << item9->sizeHint(0);
    qDebug() << item10->sizeHint(0);
    qDebug() << item11->sizeHint(0);
    qDebug() << item12->sizeHint(0);
}

QPushButton *MainWindow::button(QString text) {
    auto b = new QPushButton();
    b->setFixedSize(40, 25);
    b->setIcon(QIcon(text));
    connect(b, &QPushButton::clicked, this, &MainWindow::buttonClick);
    return b;
}

void MainWindow::buttonClick() {
    QList<QString> list;
    auto item = ui->treeWidget->currentItem();
    while (item != nullptr) {
        auto widget = ui->treeWidget->itemWidget(item, 0);
        if (dynamic_cast<QLabel*>(widget)) {
            qDebug() << "QLabel " << dynamic_cast<QLabel*>(widget)->text();
        }
        if (dynamic_cast<QCheckBox*>(widget)) {
            qDebug() << "QCheckBox " << dynamic_cast<QCheckBox*>(widget)->text();
        }

        item = item->parent();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMenu *MainWindow::createMenu() {
    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(tr("Создать подкатегорию"), this);
    //Добавление кнопки руководств
    QAction *actionGuides = new QAction(tr("Изменить достижения"), this);
    //Добавление кнопки обновления
    QAction *actionUpdate = new QAction(tr("Удалить категорию"), this);
    QMenu *menu = new QMenu(this);
    menu->addAction (actionComment);
    menu->addAction (actionGuides);
    menu->addAction (actionUpdate);
    return menu;
}

void MainWindow::on_treeWidget_itemExpanded(QTreeWidgetItem *item) {
    ui->treeWidget->resetIndentation();
    ui->treeWidget->resizeColumnToContents(0);
}

void MainWindow::on_treeWidget_itemCollapsed(QTreeWidgetItem *item) {
    ui->treeWidget->resetIndentation();
    ui->treeWidget->resizeColumnToContents(0);
}
