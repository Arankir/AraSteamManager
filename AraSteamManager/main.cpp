#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    w.show();
    return a.exec();
}
