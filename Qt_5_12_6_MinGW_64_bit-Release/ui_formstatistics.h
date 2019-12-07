/********************************************************************************
** Form generated from reading UI file 'formstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTATISTICS_H
#define UI_FORMSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *FormStatistics)
    {
        if (FormStatistics->objectName().isEmpty())
            FormStatistics->setObjectName(QString::fromUtf8("FormStatistics"));
        FormStatistics->resize(828, 300);
        verticalLayout = new QVBoxLayout(FormStatistics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FormStatistics);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(FormStatistics);
        if (tableWidget->columnCount() < 24)
            tableWidget->setColumnCount(24);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(24);

        verticalLayout->addWidget(tableWidget);

        label_2 = new QLabel(FormStatistics);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        tableWidget_2 = new QTableWidget(FormStatistics);
        if (tableWidget_2->columnCount() < 12)
            tableWidget_2->setColumnCount(12);
        if (tableWidget_2->rowCount() < 1)
            tableWidget_2->setRowCount(1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setRowCount(1);
        tableWidget_2->setColumnCount(12);

        verticalLayout->addWidget(tableWidget_2);


        retranslateUi(FormStatistics);

        QMetaObject::connectSlotsByName(FormStatistics);
    } // setupUi

    void retranslateUi(QWidget *FormStatistics)
    {
        FormStatistics->setWindowTitle(QApplication::translate("FormStatistics", "Form", nullptr));
        label->setText(QApplication::translate("FormStatistics", "\320\247\320\260\321\201\321\213", nullptr));
        label_2->setText(QApplication::translate("FormStatistics", "\320\234\320\265\321\201\321\217\321\206\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistics: public Ui_FormStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTICS_H
