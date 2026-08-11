#include <QApplication>
#include <QTranslator>
#include "classes/common/theme.h"
#include "forms/formmain.h"
#include "classes/common/loghelper.h"

//QScopedPointer<QFile> logFile_;

void registerTypes();
void initSetting();
void initLanguage(QApplication &app);
void initFont();
void onCrush();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    #if __cplusplus >= 202002L
        // C++20 (and later) code
        qDebug() << "C++20 (and later)" << __cplusplus;
    #endif

//    qApp->setStyle(QStyleFactory::create("Fusion"));

    registerTypes();
    initSetting();
    initLanguage(a);
    initFont();
    LogHelper::setDebugMessageHandler();

    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));

    FormMain *mainForm = createFramelessForm<FormMain>();
    QObject::connect(mainForm, &Form::s_settingsUpdated, mainForm, [=](QFlags<changedSettings> lSettings) {
        if (lSettings.testFlag(changedSettings::theme)) {
            mainForm->window()->updateSettings();
        }
    });
//    QObject::connect(mainForm, &FormMain::s_settingsUpdated, mainForm->window(), &FramelessWindow::updateSettings);
    QObject::connect(mainForm, &FormMain::s_destructed, [](){
        qInfo() << "Programm closed";
        qApp->closeAllWindows();
    });

    if (mainForm->window() != nullptr) {
        mainForm->window()->restoreGeometry(Settings::mainWindowGeometry());
        mainForm->window()->restoreState(Settings::mainWindowState());
    }
    mainForm->window()->show();

    return a.exec();
}

void registerTypes() {
    qRegisterMetaType<QVector<int> >                    ("QVector<int>");
    qRegisterMetaType<QMetaTypeId<ReachedType> >        ("QMetaTypeId<ReachedType>");
    qRegisterMetaType<QVector<double> >                 ("QVector<double>");
    qRegisterMetaType<QVector<QPair<QString,int> > >    ("QVector<QPair<QString, int> >");
    qRegisterMetaType<QVector<QPair<QString,QString> > >("QVector<QPair<QString, QString> >");
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
        if (lang->load(":/AraSteamManager_ru.qm")) {
            app.installTranslator(lang);
        }
        break;
    case 1:
    default:
        if (lang->load(":/AraSteamManager_en.qm")) {
            app.installTranslator(lang);
        }
        break;
    }
}

void initFont() {
    QFont font(Theme::defaultFont(), 10);
    font.setStyleHint(QFont::Monospace);
    //font.setPointSize(12);
    //font.setPixelSize(12);
    qApp->setFont(font);
}

void onCrush() {

}
