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
<<<<<<< HEAD
    QTableWidget *TableWidgetHollow;
    QTableWidget *TableWidgetHorizontalHeader;
    QTableWidget *TableWidgetVerticalHeader;
=======
    QTableWidget *TableWidgetHorizontalHeader;
>>>>>>> работает
    QTableWidget *TableWidgetContent;

    void setupUi(QWidget *FormTablesHeaders)
    {
        if (FormTablesHeaders->objectName().isEmpty())
            FormTablesHeaders->setObjectName(QString::fromUtf8("FormTablesHeaders"));
        FormTablesHeaders->resize(653, 601);
<<<<<<< HEAD
        TableWidgetHollow = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHollow->columnCount() < 1)
            TableWidgetHollow->setColumnCount(1);
        if (TableWidgetHollow->rowCount() < 1)
            TableWidgetHollow->setRowCount(1);
        TableWidgetHollow->setObjectName(QString::fromUtf8("TableWidgetHollow"));
        TableWidgetHollow->setGeometry(QRect(10, 10, 131, 91));
        TableWidgetHollow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHollow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHollow->setRowCount(1);
        TableWidgetHollow->setColumnCount(1);
=======
>>>>>>> работает
        TableWidgetHorizontalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHorizontalHeader->columnCount() < 7)
            TableWidgetHorizontalHeader->setColumnCount(7);
        if (TableWidgetHorizontalHeader->rowCount() < 1)
            TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setObjectName(QString::fromUtf8("TableWidgetHorizontalHeader"));
<<<<<<< HEAD
        TableWidgetHorizontalHeader->setGeometry(QRect(150, 11, 251, 91));
        TableWidgetHorizontalHeader->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setColumnCount(7);
        TableWidgetHorizontalHeader->horizontalHeader()->setStretchLastSection(true);
        TableWidgetHorizontalHeader->verticalHeader()->setVisible(false);
        TableWidgetVerticalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetVerticalHeader->columnCount() < 1)
            TableWidgetVerticalHeader->setColumnCount(1);
        if (TableWidgetVerticalHeader->rowCount() < 7)
            TableWidgetVerticalHeader->setRowCount(7);
        TableWidgetVerticalHeader->setObjectName(QString::fromUtf8("TableWidgetVerticalHeader"));
        TableWidgetVerticalHeader->setGeometry(QRect(10, 110, 131, 192));
        TableWidgetVerticalHeader->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetVerticalHeader->setRowCount(7);
        TableWidgetVerticalHeader->setColumnCount(1);
        TableWidgetVerticalHeader->horizontalHeader()->setVisible(false);
        TableWidgetVerticalHeader->verticalHeader()->setStretchLastSection(true);
=======
        TableWidgetHorizontalHeader->setGeometry(QRect(160, 10, 481, 211));
        TableWidgetHorizontalHeader->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setColumnCount(7);
        TableWidgetHorizontalHeader->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        TableWidgetHorizontalHeader->horizontalHeader()->setStretchLastSection(true);
        TableWidgetHorizontalHeader->verticalHeader()->setVisible(false);
>>>>>>> работает
        TableWidgetContent = new QTableWidget(FormTablesHeaders);
        if (TableWidgetContent->columnCount() < 7)
            TableWidgetContent->setColumnCount(7);
        if (TableWidgetContent->rowCount() < 7)
            TableWidgetContent->setRowCount(7);
        TableWidgetContent->setObjectName(QString::fromUtf8("TableWidgetContent"));
<<<<<<< HEAD
        TableWidgetContent->setGeometry(QRect(150, 110, 251, 191));
=======
        TableWidgetContent->setGeometry(QRect(160, 230, 481, 361));
        TableWidgetContent->setSortingEnabled(true);
>>>>>>> работает
        TableWidgetContent->setRowCount(7);
        TableWidgetContent->setColumnCount(7);
        TableWidgetContent->horizontalHeader()->setVisible(false);
        TableWidgetContent->horizontalHeader()->setStretchLastSection(true);
        TableWidgetContent->verticalHeader()->setVisible(false);
        TableWidgetContent->verticalHeader()->setStretchLastSection(true);

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
