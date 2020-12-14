/********************************************************************************
** Form generated from reading UI file 'framelesswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSWINDOW_H
#define UI_FRAMELESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FramelessWindow)
    {
        if (FramelessWindow->objectName().isEmpty())
            FramelessWindow->setObjectName(QString::fromUtf8("FramelessWindow"));
        FramelessWindow->resize(800, 600);
        menubar = new QMenuBar(FramelessWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        FramelessWindow->setMenuBar(menubar);
        centralwidget = new QWidget(FramelessWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FramelessWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FramelessWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FramelessWindow->setStatusBar(statusbar);

        retranslateUi(FramelessWindow);

        QMetaObject::connectSlotsByName(FramelessWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FramelessWindow)
    {
        FramelessWindow->setWindowTitle(QCoreApplication::translate("FramelessWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramelessWindow: public Ui_FramelessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSWINDOW_H
