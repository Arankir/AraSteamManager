/********************************************************************************
** Form generated from reading UI file 'formtablesheaders.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
    QTableWidget *TableWidgetHorizontalHeader;
    QTableWidget *TableWidgetContent;

    void setupUi(QWidget *FormTablesHeaders)
    {
        if (FormTablesHeaders->objectName().isEmpty())
            FormTablesHeaders->setObjectName(QString::fromUtf8("FormTablesHeaders"));
        FormTablesHeaders->resize(650, 601);
        TableWidgetHorizontalHeader = new QTableWidget(FormTablesHeaders);
        if (TableWidgetHorizontalHeader->columnCount() < 7)
            TableWidgetHorizontalHeader->setColumnCount(7);
        if (TableWidgetHorizontalHeader->rowCount() < 1)
            TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setObjectName(QString::fromUtf8("TableWidgetHorizontalHeader"));
        TableWidgetHorizontalHeader->setGeometry(QRect(10, 10, 631, 111));
        TableWidgetHorizontalHeader->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHorizontalHeader->setShowGrid(false);
        TableWidgetHorizontalHeader->setRowCount(1);
        TableWidgetHorizontalHeader->setColumnCount(7);
        TableWidgetHorizontalHeader->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        TableWidgetHorizontalHeader->horizontalHeader()->setStretchLastSection(true);
        TableWidgetHorizontalHeader->verticalHeader()->setVisible(false);
        TableWidgetContent = new QTableWidget(FormTablesHeaders);
        if (TableWidgetContent->columnCount() < 7)
            TableWidgetContent->setColumnCount(7);
        if (TableWidgetContent->rowCount() < 7)
            TableWidgetContent->setRowCount(7);
        TableWidgetContent->setObjectName(QString::fromUtf8("TableWidgetContent"));
        TableWidgetContent->setGeometry(QRect(10, 130, 631, 461));
        TableWidgetContent->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetContent->setShowGrid(false);
        TableWidgetContent->setSortingEnabled(true);
        TableWidgetContent->setRowCount(7);
        TableWidgetContent->setColumnCount(7);
        TableWidgetContent->horizontalHeader()->setVisible(false);
        TableWidgetContent->horizontalHeader()->setStretchLastSection(true);
        TableWidgetContent->verticalHeader()->setVisible(false);

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
