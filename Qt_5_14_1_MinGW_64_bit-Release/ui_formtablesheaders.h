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
#include <QtWidgets/QScrollBar>
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
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *FormTablesHeaders)
    {
        if (FormTablesHeaders->objectName().isEmpty())
            FormTablesHeaders->setObjectName(QString::fromUtf8("FormTablesHeaders"));
        FormTablesHeaders->resize(653, 601);
        TableWidgetHollow = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHollow->columnCount() < 1)
            TableWidgetHollow->setColumnCount(1);
        if (TableWidgetHollow->rowCount() < 1)
            TableWidgetHollow->setRowCount(1);
        TableWidgetHollow->setObjectName(QString::fromUtf8("TableWidgetHollow"));
        TableWidgetHollow->setGeometry(QRect(10, 10, 131, 91));
        TableWidgetHollow->setRowCount(1);
        TableWidgetHollow->setColumnCount(1);
        TableWidgetHorizontalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHorizontalHeader->columnCount() < 3)
            TableWidgetHorizontalHeader->setColumnCount(3);
        if (TableWidgetHorizontalHeader->rowCount() < 1)
            TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setObjectName(QString::fromUtf8("TableWidgetHorizontalHeader"));
        TableWidgetHorizontalHeader->setGeometry(QRect(150, 11, 251, 91));
        TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setColumnCount(3);
        TableWidgetVerticalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetVerticalHeader->columnCount() < 1)
            TableWidgetVerticalHeader->setColumnCount(1);
        if (TableWidgetVerticalHeader->rowCount() < 3)
            TableWidgetVerticalHeader->setRowCount(3);
        TableWidgetVerticalHeader->setObjectName(QString::fromUtf8("TableWidgetVerticalHeader"));
        TableWidgetVerticalHeader->setGeometry(QRect(10, 110, 131, 192));
        TableWidgetVerticalHeader->setRowCount(3);
        TableWidgetVerticalHeader->setColumnCount(1);
        TableWidgetContent = new QTableWidget(FormTablesHeaders);
        if (TableWidgetContent->columnCount() < 3)
            TableWidgetContent->setColumnCount(3);
        if (TableWidgetContent->rowCount() < 3)
            TableWidgetContent->setRowCount(3);
        TableWidgetContent->setObjectName(QString::fromUtf8("TableWidgetContent"));
        TableWidgetContent->setGeometry(QRect(150, 110, 251, 191));
        TableWidgetContent->setRowCount(3);
        TableWidgetContent->setColumnCount(3);
        horizontalScrollBar = new QScrollBar(FormTablesHeaders);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(150, 310, 251, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(FormTablesHeaders);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(410, 110, 16, 191));
        verticalScrollBar->setOrientation(Qt::Vertical);

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
