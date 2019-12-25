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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts/QtCharts"

QT_BEGIN_NAMESPACE

class Ui_FormStatistics
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QChartView *ChartViewPercentages;
    QVBoxLayout *verticalLayout;
    QLabel *LabelAveragePercent;
    QLabel *LabelSummColumn;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;
    QChartView *ChartsViewTimes;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_2;
    QChartView *ChartsViewMonths;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_3;
    QChartView *ChartsViewYears;

    void setupUi(QWidget *FormStatistics)
    {
        if (FormStatistics->objectName().isEmpty())
            FormStatistics->setObjectName(QString::fromUtf8("FormStatistics"));
        FormStatistics->resize(828, 734);
        verticalLayout_2 = new QVBoxLayout(FormStatistics);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ChartViewPercentages = new QChartView(FormStatistics);
        ChartViewPercentages->setObjectName(QString::fromUtf8("ChartViewPercentages"));
        ChartViewPercentages->setMinimumSize(QSize(0, 250));

        horizontalLayout_4->addWidget(ChartViewPercentages);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelAveragePercent = new QLabel(FormStatistics);
        LabelAveragePercent->setObjectName(QString::fromUtf8("LabelAveragePercent"));

        verticalLayout->addWidget(LabelAveragePercent);

        LabelSummColumn = new QLabel(FormStatistics);
        LabelSummColumn->setObjectName(QString::fromUtf8("LabelSummColumn"));

        verticalLayout->addWidget(LabelSummColumn);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableWidget = new QTableWidget(FormStatistics);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 24)
            tableWidget->setRowCount(24);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 70));
        tableWidget->setRowCount(24);
        tableWidget->setColumnCount(1);

        horizontalLayout_3->addWidget(tableWidget);

        ChartsViewTimes = new QChartView(FormStatistics);
        ChartsViewTimes->setObjectName(QString::fromUtf8("ChartsViewTimes"));

        horizontalLayout_3->addWidget(ChartsViewTimes);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget_2 = new QTableWidget(FormStatistics);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        if (tableWidget_2->rowCount() < 12)
            tableWidget_2->setRowCount(12);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMaximumSize(QSize(16777215, 70));
        tableWidget_2->setRowCount(12);
        tableWidget_2->setColumnCount(1);

        horizontalLayout_2->addWidget(tableWidget_2);

        ChartsViewMonths = new QChartView(FormStatistics);
        ChartsViewMonths->setObjectName(QString::fromUtf8("ChartsViewMonths"));

        horizontalLayout_2->addWidget(ChartsViewMonths);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget_3 = new QTableWidget(FormStatistics);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        if (tableWidget_3->rowCount() < 1)
            tableWidget_3->setRowCount(1);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setMaximumSize(QSize(16777215, 70));
        tableWidget_3->setRowCount(1);
        tableWidget_3->setColumnCount(1);

        horizontalLayout->addWidget(tableWidget_3);

        ChartsViewYears = new QChartView(FormStatistics);
        ChartsViewYears->setObjectName(QString::fromUtf8("ChartsViewYears"));

        horizontalLayout->addWidget(ChartsViewYears);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FormStatistics);

        QMetaObject::connectSlotsByName(FormStatistics);
    } // setupUi

    void retranslateUi(QWidget *FormStatistics)
    {
        FormStatistics->setWindowTitle(QApplication::translate("FormStatistics", "Form", nullptr));
        LabelAveragePercent->setText(QApplication::translate("FormStatistics", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\277\321\200\320\276\321\206\320\265\320\275\321\202: ", nullptr));
        LabelSummColumn->setText(QApplication::translate("FormStatistics", "\320\222\321\201\320\265\320\263\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistics: public Ui_FormStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTICS_H
