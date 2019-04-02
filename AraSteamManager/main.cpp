#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    a.addLibraryPath(a.applicationDirPath() + "/plugins/qq17-imageio/argbplugin.pro");
    a.addLibraryPath(a.applicationDirPath() + "/plugins/imageformats/qjpeg4.dll");
    MainWindow w;
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    w.show();
    return a.exec();
}
