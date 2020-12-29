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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *FrameTitleWindow;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelLogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonMinimize;
    QPushButton *ButtonMaximize;
    QPushButton *ButtonExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FramelessWindow)
    {
        if (FramelessWindow->objectName().isEmpty())
            FramelessWindow->setObjectName(QString::fromUtf8("FramelessWindow"));
        FramelessWindow->resize(170, 68);
        centralwidget = new QWidget(FramelessWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FrameTitleWindow = new QFrame(centralwidget);
        FrameTitleWindow->setObjectName(QString::fromUtf8("FrameTitleWindow"));
        FrameTitleWindow->setMinimumSize(QSize(0, 0));
        FrameTitleWindow->setMaximumSize(QSize(16777215, 33));
#if QT_CONFIG(accessibility)
        FrameTitleWindow->setAccessibleName(QString::fromUtf8("TitleWindow"));
#endif // QT_CONFIG(accessibility)
        FrameTitleWindow->setFrameShape(QFrame::StyledPanel);
        FrameTitleWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(FrameTitleWindow);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(3, 0, 3, 0);
        LabelLogo = new QLabel(FrameTitleWindow);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));
        LabelLogo->setText(QString::fromUtf8("Logo"));

        horizontalLayout->addWidget(LabelLogo);

        horizontalSpacer = new QSpacerItem(337, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ButtonMinimize = new QPushButton(FrameTitleWindow);
        ButtonMinimize->setObjectName(QString::fromUtf8("ButtonMinimize"));
        QFont font;
        font.setPointSize(10);
        ButtonMinimize->setFont(font);
        ButtonMinimize->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(ButtonMinimize);

        ButtonMaximize = new QPushButton(FrameTitleWindow);
        ButtonMaximize->setObjectName(QString::fromUtf8("ButtonMaximize"));
        ButtonMaximize->setFont(font);
        ButtonMaximize->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(ButtonMaximize);

        ButtonExit = new QPushButton(FrameTitleWindow);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        ButtonExit->setFont(font);

        horizontalLayout->addWidget(ButtonExit);


        verticalLayout->addWidget(FrameTitleWindow);

        FramelessWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FramelessWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 170, 20));
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
        ButtonExit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FramelessWindow: public Ui_FramelessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSWINDOW_H
