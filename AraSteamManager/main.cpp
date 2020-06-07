#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QTranslator>
#include <class/settings.h>
#include <frameless.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Arankir");
    QCoreApplication::setOrganizationDomain("Arankir");
    QCoreApplication::setApplicationName("SteamAchievementsStatistic");

    qApp->setStyle(QStyleFactory::create("Fusion"));
    qRegisterMetaType<QVector<int>>("QVector<int>");
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<QVector<QPair<QString,int> >>("QVector<QPair<QString,int> >");
    qRegisterMetaType<QVector<QPair<QString,QString> >>("QVector<QPair<QString,QString> >");
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    QTranslator lang;
    Settings Setting;
    switch(Setting.getLanguage()){
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
    MainWindow *w = new MainWindow;
    FrameLess f(w);
    w->show();
    return a.exec();
}
