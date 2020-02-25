/********************************************************************************
** Form generated from reading UI file 'formtablesheaders.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTABLESHEADERS_H
#define UI_FORMTABLESHEADERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTablesHeaders
{
public:
    QTableWidget *TableWidgetHollow;
    QTableWidget *TableWidgetHorizontalHeader;
    QTableWidget *TableWidgetVerticalHeader;
    QTableWidget *TableWidgetContent;

    void setupUi(QWidget *FormTablesHeaders)
    {
        if (FormTablesHeaders->objectName().isEmpty())
            FormTablesHeaders->setObjectName(QString::fromUtf8("FormTablesHeaders"));
        FormTablesHeaders->resize(653, 601);
        TableWidgetHollow = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHollow->columnCount() < 3)
            TableWidgetHollow->setColumnCount(3);
        if (TableWidgetHollow->rowCount() < 3)
            TableWidgetHollow->setRowCount(3);
        TableWidgetHollow->setObjectName(QString::fromUtf8("TableWidgetHollow"));
        TableWidgetHollow->setGeometry(QRect(0, 0, 256, 192));
        TableWidgetHollow->setRowCount(3);
        TableWidgetHollow->setColumnCount(3);
        TableWidgetHorizontalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHorizontalHeader->columnCount() < 3)
            TableWidgetHorizontalHeader->setColumnCount(3);
        if (TableWidgetHorizontalHeader->rowCount() < 3)
            TableWidgetHorizontalHeader->setRowCount(3);
        TableWidgetHorizontalHeader->setObjectName(QString::fromUtf8("TableWidgetHorizontalHeader"));
        TableWidgetHorizontalHeader->setGeometry(QRect(256, 0, 256, 192));
        TableWidgetHorizontalHeader->setRowCount(3);
        TableWidgetHorizontalHeader->setColumnCount(3);
        TableWidgetVerticalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetVerticalHeader->columnCount() < 3)
            TableWidgetVerticalHeader->setColumnCount(3);
        if (TableWidgetVerticalHeader->rowCount() < 3)
            TableWidgetVerticalHeader->setRowCount(3);
        TableWidgetVerticalHeader->setObjectName(QString::fromUtf8("TableWidgetVerticalHeader"));
        TableWidgetVerticalHeader->setGeometry(QRect(0, 301, 256, 192));
        TableWidgetVerticalHeader->setRowCount(3);
        TableWidgetVerticalHeader->setColumnCount(3);
        TableWidgetContent = new QTableWidget(FormTablesHeaders);
        if (TableWidgetContent->columnCount() < 3)
            TableWidgetContent->setColumnCount(3);
        if (TableWidgetContent->rowCount() < 3)
            TableWidgetContent->setRowCount(3);
        TableWidgetContent->setObjectName(QString::fromUtf8("TableWidgetContent"));
        TableWidgetContent->setGeometry(QRect(300, 290, 256, 192));
        TableWidgetContent->setRowCount(3);
        TableWidgetContent->setColumnCount(3);

        retranslateUi(FormTablesHeaders);

        QMetaObject::connectSlotsByName(FormTablesHeaders);
    } // setupUi

    void retranslateUi(QWidget *FormTablesHeaders)
    {
        FormTablesHeaders->setWindowTitle(QCoreApplication::translate("FormTablesHeaders", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTablesHeaders: public Ui_FormTablesHeaders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTABLESHEADERS_H
