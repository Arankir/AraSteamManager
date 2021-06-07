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
#include "classes/common/settings.h"
#include "forms/formmain.h"
#include "framelesswindow.h"

QScopedPointer<QFile> logFile_;

void registerTypes();
void initSetting();
void initLanguage(QApplication &app);
void initFont();
void initLog();
void onCrush();
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

    createFramelessForm<FormMain>()->window()->show();

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
    output += "  " + aMessage + "\n";
    OutputDebugString(reinterpret_cast<const wchar_t *>(output.utf16()));
}

void registerTypes() {
    qRegisterMetaType<QVector<int>>                     ("QVector<int>");
    qRegisterMetaType<QMetaTypeId<ReachedType>>         ("QMetaTypeId<ReachedType>");
    qRegisterMetaType<QVector<double>>                  ("QVector<double>");
    qRegisterMetaType<QVector<QPair<QString,int> >>     ("QVector<QPair<QString, int> >");
    qRegisterMetaType<QVector<QPair<QString,QString> >> ("QVector<QPair<QString, QString> >");
}

void initSetting() {
    QCoreApplication::setOrganizationName(Settings::c_organizationName);
    QCoreApplication::setOrganizationDomain(Settings::c_organizationDomain);
    QCoreApplication::setApplicationName(Settings::c_applicationName);
}

void initLanguage(QApplication &app) {
    QTranslator *lang = new QTranslator;
    Settings Setting;
    switch(Setting.language()) {
    case 5:
        lang->load(":/AraSteamManager_ru.qm");
        app.installTranslator(lang);
        break;
    case 1:
    default:
        lang->load(":/AraSteamManager_en.qm");
        app.installTranslator(lang);
    }
}

void initFont() {
    QFont font(Settings::defaultFont(), 10);
    font.setStyleHint(QFont::Monospace);
    //font.setPointSize(12);
    //font.setPixelSize(12);
    qApp->setFont(font);
}

void initLog() {
    QString logsPath = Paths::temp() + "files/logs/";
    createDir(logsPath);

    //Удаление старых файлов
    QDir dirLogs(logsPath);
    dirLogs.setFilter(QDir::Files | QDir::NoSymLinks);
    dirLogs.setSorting(QDir::Name);
    QFileInfoList list = dirLogs.entryInfoList();
    for(auto &file: list) {
        if (file.fileName().indexOf("log_") == 0) {
            QDateTime date {QDateTime::fromString(file.fileName().remove("log_").remove(".txt"), Settings::dateFormat())};
            if (date < QDateTime::currentDateTime().addMonths(-1)) {
                QFile::remove(file.filePath() + "/" + file.fileName());
            }
        }
    }

    logFile_.reset(new QFile(logsPath + QDateTime::currentDateTime().toString("log_" + Settings::dateFormat()) + ".txt"));
    logFile_.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(log);
}

void onCrush() {

}
