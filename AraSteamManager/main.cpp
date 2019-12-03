#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QTranslator>
#include <class/settings.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    QTranslator lang;
    Settings Setting;
    switch(Setting.GetLanguage()){
    case 1:{
        lang.load(":/AraSteamManager_en.qm");
        a.installTranslator(&lang);
        break;
    }
    case 5:{
        lang.load(":/AraSteamManager_ru.qm");
        a.installTranslator(&lang);
        break;
    }
    default:{
        lang.load(":/AraSteamManager_en.qm");
        a.installTranslator(&lang);
    }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
