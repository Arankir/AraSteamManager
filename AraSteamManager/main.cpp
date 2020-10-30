#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QTranslator>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QLoggingCategory>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "class/settings.h"
#include "frameless.h"

QScopedPointer<QFile> logFile_;

void registerTypes();
void initSetting();
void initLanguage(QApplication &app);
void initFont();
void initLog();
void log(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qApp->setStyle(QStyleFactory::create("Fusion"));

    registerTypes();
    initSetting();
    initLanguage(a);
    initFont();
    initLog();

    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));

    MainWindow *w = new MainWindow;
    FrameLess f(w);
    w->show();

    return a.exec();
}

void log(QtMsgType aType, const QMessageLogContext &aContext, const QString &aMessage) {
    const char *function = aContext.function ? aContext.function : "";
    QTextStream out(logFile_.data());

    switch (aType) {
    case QtInfoMsg:     out << "INFO "; break;
    case QtDebugMsg:    out << "DEBG "; break;
    case QtWarningMsg:  out << "WRNG "; break;
    case QtCriticalMsg: out << "CRCL "; break;
    case QtFatalMsg:    out << "FATL "; break;
    }

    out << QTime::currentTime().toString("hh:mm:ss ");//"yyyy-MM-dd hh:mm:ss "
    out << /*aContext.category << ": " << */function << "  " << aMessage << endl;
    out.flush();

    QString output(function);
    output += "  " + aMessage;
    OutputDebugString(reinterpret_cast<const wchar_t *>(output.utf16()));
}

void initLog() {
    Settings::createDir("files/logs/");

    //Удаление старых файлов
    QDir dirLogs("files/logs/");
    dirLogs.setFilter(QDir::Files | QDir::NoSymLinks);
    dirLogs.setSorting(QDir::Name);
    QFileInfoList list = dirLogs.entryInfoList();
    for(auto &file: list) {
        if (file.fileName().indexOf("log_") == 0) {
            QDateTime date = QDateTime::fromString(file.fileName().remove("log_").remove(".txt"), "yyyy.MM.dd");
            if (date < QDateTime::currentDateTime().addMonths(-1)) {
                QFile::remove(file.filePath() + "/" + file.fileName());
            }
        }
    }

    logFile_.reset(new QFile("files/logs/" + QDateTime::currentDateTime().toString("log_yyyy.MM.dd") + ".txt"));
    logFile_.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(log);
}

void registerTypes() {
    qRegisterMetaType<QVector<int>>                     ("QVector<int>");
    qRegisterMetaType<QMetaTypeId<ReachedType>>         ("QMetaTypeId<ReachedType>");
    qRegisterMetaType<QVector<double>>                  ("QVector<double>");
    qRegisterMetaType<QVector<QPair<QString,int> >>     ("QVector<QPair<QString, int> >");
    qRegisterMetaType<QVector<QPair<QString,QString> >> ("QVector<QPair<QString, QString> >");
}

void initSetting() {
    QCoreApplication::setOrganizationName("Arankir");
    QCoreApplication::setOrganizationDomain("Arankir");
    QCoreApplication::setApplicationName("SteamAchievementsStatistic");
}

void initLanguage(QApplication &app) {
    QTranslator lang;
    Settings Setting;
    switch(Setting.getLanguage()) {
    case 5:
        lang.load(":/AraSteamManager_ru.qm");
        app.installTranslator(&lang);
        break;
    case 1:
    default:
        lang.load(":/AraSteamManager_en.qm");
        app.installTranslator(&lang);
    }
}

void initFont() {
    QFont font(Settings::getFontDefaultName(), 10);
    //font.setPointSize(12);
    //font.setPixelSize(12);
    qApp->setFont(font);
}
