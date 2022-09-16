#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QDebug>
//#include <QLoggingCategory>

//Q_DECLARE_LOGGING_CATEGORY(logDebug)
//Q_DECLARE_LOGGING_CATEGORY(logInfo)
//Q_DECLARE_LOGGING_CATEGORY(logFunc)
//Q_DECLARE_LOGGING_CATEGORY(logWarning)
//Q_DECLARE_LOGGING_CATEGORY(logCritical)

class LogHelper {
public:
    static void setDebugMessageHandler();
    static void myMessageOutput(QtMsgType type,
                                const QMessageLogContext &context,
                                const QString &msgText);

protected:
    static void smartPrintDebugMessage(QString msg);
    static void printToLogFile(const QString &text);
    static void createLogFile();

    static QString m_logFileName;
};

#endif // LOGHELPER_H
