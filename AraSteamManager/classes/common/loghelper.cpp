#include "loghelper.h"
#include "classes/common/settings.h"

#include <QDebug>
#include <QObject>
#include <QApplication>
#include <QString>
#include <QTime>
#include <QMessageBox>
#include <iostream>
#include <QDir>
#include <Windows.h>

QString LogHelper::m_logFileName;

void LogHelper::createLogFile() {
    // Создание пустого файла лога
    FILE *pFile = fopen(qPrintable(m_logFileName), "a+");

    if(!pFile) {
        fclose(pFile);
    }
}

void LogHelper::printToLogFile(const QString &aText) {
    // Лог-файл открывается в режиме добавления данных
    FILE *pFile = fopen(qPrintable(m_logFileName), "a+");

    if(!pFile) {
        printf("Log %s file not writable\n", qPrintable(m_logFileName));
        return;
    }

    // Быстрый вывод текста в файл лога
    fprintf(pFile, "%s", qPrintable(aText));

    // Лог-файл закрывается
    fclose(pFile);
}

void LogHelper::smartPrintDebugMessage(QString aMsg) {
    // Подготовка текста для вывода
    QTime currTime = QTime::currentTime();
    QString timeText = currTime.toString("hh:mm:ss.zzz");
    aMsg = timeText + " " + aMsg;

    // Быстрый вывод в консоль
//    fprintf(stderr, "%s", qPrintable(aMsg));

    // Вывод в файл лога
    printToLogFile(aMsg);

    OutputDebugString(reinterpret_cast<const wchar_t *>(aMsg.utf16()));
}

// Обработчик (хендлер) вызовов qDebug()
// Внутри этого обработчика нельзя использовать вызовы qDebug(), т. к. получится рекурсия
void LogHelper::myMessageOutput(QtMsgType aType, const QMessageLogContext &aContext, const QString &aMsgText) {
    Q_UNUSED(aContext)
    const char *function = aContext.function ? aContext.function : "";
    switch (aType) {
     case QtDebugMsg:
         // Отладочный вывод возможен только при компиляции в режиме отладки
         #ifdef QT_DEBUG
         smartPrintDebugMessage("[DBG] " + QString(function) + " " + aMsgText + "\n");
         #endif
         break;
     case QtWarningMsg:
         smartPrintDebugMessage("[WRN] " + QString(function) + " " + aMsgText + "\n");
//         QMessageBox::warning(nullptr, "Application warning message",
//                              aMsgText,
//                              QMessageBox::Ok);
         break;
    case QtCriticalMsg:
         smartPrintDebugMessage("[CRERR] " + QString(function) + " " + aMsgText + "\n");
//         QMessageBox::warning(nullptr, "Application critical message",
//                              aMsgText,
//                              QMessageBox::Ok);
         break;
     case QtFatalMsg:
         smartPrintDebugMessage("[FTERR] " + QString(function) + " " + aMsgText + "\n");
         abort();
     case QtInfoMsg:
         smartPrintDebugMessage("[INF] " + QString(function) + " " + aMsgText + "\n");
         break;
    }
}

void LogHelper::setDebugMessageHandler() {
    QString pathLogs = Paths::temp() + "files/logs/";
    QDir dirLogs;
    dirLogs.mkpath(pathLogs);
    dirLogs.setPath(pathLogs);
    dirLogs.setFilter(QDir::Files | QDir::NoSymLinks);
    dirLogs.setSorting(QDir::Name);
    QFileInfoList list = dirLogs.entryInfoList();
    for(auto &file: list) {
        if (file.fileName().indexOf("log_") == 0) {
            QDateTime date;
            date = QDateTime::fromString(file.fileName().remove("log_").remove(".txt"), Settings::dateFormat());
            if (date < QDateTime::currentDateTime().addMonths(-1)) {
                QFile::remove(file.filePath());
            }
        }
    }

    // Задается статическое значение имени файла лога
    m_logFileName = pathLogs + QDateTime::currentDateTime().toString("log_" + Settings::dateFormat()) + ".txt";
    printf("\nSet log file to %s\n", qPrintable(m_logFileName));

    // Лог-файл открывается
    createLogFile();

    // Устанавливается Qt-обработчик консольного вывода
    qInstallMessageHandler(myMessageOutput);
}

