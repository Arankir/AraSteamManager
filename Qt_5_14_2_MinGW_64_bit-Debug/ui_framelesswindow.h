/********************************************************************************
** Form generated from reading UI file 'framelesswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSWINDOW_H
#define UI_FRAMELESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FramelessWindow)
    {
        if (FramelessWindow->objectName().isEmpty())
            FramelessWindow->setObjectName(QString::fromUtf8("FramelessWindow"));
        FramelessWindow->resize(800, 600);
        centralwidget = new QWidget(FramelessWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 280, 80, 21));
        FramelessWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FramelessWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        FramelessWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FramelessWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FramelessWindow->setStatusBar(statusbar);

        retranslateUi(FramelessWindow);

        QMetaObject::connectSlotsByName(FramelessWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FramelessWindow)
    {
        FramelessWindow->setWindowTitle(QCoreApplication::translate("FramelessWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("FramelessWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramelessWindow: public Ui_FramelessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSWINDOW_H
