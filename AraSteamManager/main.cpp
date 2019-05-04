#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
//    a.addLibraryPath(a.applicationDirPath() + "/plugins/qq17-imageio/argbplugin.pro");
//    a.addLibraryPath(a.applicationDirPath() + "/plugins/imageformats/qjpeg4.dll");
//    qApp->addLibraryPath("C:/Users/Arankir/Desktop/123/AraSteamManager/build-AraSteamManager-Desktop_Qt_5_12_1_MinGW_64_bit-Release/release/plugins");
    MainWindow w;
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    w.show();
    return a.exec();
}
