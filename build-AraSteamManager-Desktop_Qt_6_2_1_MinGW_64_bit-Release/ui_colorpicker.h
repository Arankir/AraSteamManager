/********************************************************************************
** Form generated from reading UI file 'colorpicker.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKER_H
#define UI_COLORPICKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorPicker
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QDialog *ColorPicker)
    {
        if (ColorPicker->objectName().isEmpty())
            ColorPicker->setObjectName(QString::fromUtf8("ColorPicker"));
        ColorPicker->resize(400, 300);
        menuBar = new QMenuBar(ColorPicker);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        mainToolBar = new QToolBar(ColorPicker);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        centralWidget = new QWidget(ColorPicker);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        statusBar = new QStatusBar(ColorPicker);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));

        retranslateUi(ColorPicker);

        QMetaObject::connectSlotsByName(ColorPicker);
    } // setupUi

    void retranslateUi(QDialog *ColorPicker)
    {
        ColorPicker->setWindowTitle(QCoreApplication::translate("ColorPicker", "ColorPicker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorPicker: public Ui_ColorPicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKER_H
