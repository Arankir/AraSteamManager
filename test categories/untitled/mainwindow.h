#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QTreeWidgetItem>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QPushButton *button(QString);
    ~MainWindow();

private slots:
    void on_treeWidget_itemExpanded(QTreeWidgetItem *item);

    void on_treeWidget_itemCollapsed(QTreeWidgetItem *item);

    void buttonClick();
    QMenu *createMenu();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
