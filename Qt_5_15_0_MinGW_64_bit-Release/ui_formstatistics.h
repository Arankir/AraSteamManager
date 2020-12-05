/********************************************************************************
** Form generated from reading UI file 'formstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTATISTICS_H
#define UI_FORMSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts/QtCharts"

QT_BEGIN_NAMESPACE

class Ui_FormStatistics
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QChartView *ChartViewPercentages;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *LabelAveragePercentValue;
    QVBoxLayout *verticalLayout_2;
    QLabel *LabelSummColumn;
    QLabel *LabelSummColumnValue;
    QChartView *ChartsViewTimes;
    QChartView *ChartsViewMonths;
    QChartView *ChartsViewYears;

    void setupUi(QWidget *FormStatistics)
    {
        if (FormStatistics->objectName().isEmpty())
            FormStatistics->setObjectName(QString::fromUtf8("FormStatistics"));
        FormStatistics->resize(828, 734);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormStatistics->setFont(font);
        verticalLayout_4 = new QVBoxLayout(FormStatistics);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ChartViewPercentages = new QChartView(FormStatistics);
        ChartViewPercentages->setObjectName(QString::fromUtf8("ChartViewPercentages"));
        ChartViewPercentages->setMinimumSize(QSize(0, 250));

        horizontalLayout->addWidget(ChartViewPercentages);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(FormStatistics);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setText(QString::fromUtf8("?"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelAveragePercentValue = new QLabel(FormStatistics);
        LabelAveragePercentValue->setObjectName(QString::fromUtf8("LabelAveragePercentValue"));
        LabelAveragePercentValue->setText(QString::fromUtf8("0"));

        verticalLayout->addWidget(LabelAveragePercentValue);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LabelSummColumn = new QLabel(FormStatistics);
        LabelSummColumn->setObjectName(QString::fromUtf8("LabelSummColumn"));

        verticalLayout_2->addWidget(LabelSummColumn);

        LabelSummColumnValue = new QLabel(FormStatistics);
        LabelSummColumnValue->setObjectName(QString::fromUtf8("LabelSummColumnValue"));
        LabelSummColumnValue->setText(QString::fromUtf8("0"));

        verticalLayout_2->addWidget(LabelSummColumnValue);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        ChartsViewTimes = new QChartView(FormStatistics);
        ChartsViewTimes->setObjectName(QString::fromUtf8("ChartsViewTimes"));

        verticalLayout_4->addWidget(ChartsViewTimes);

        ChartsViewMonths = new QChartView(FormStatistics);
        ChartsViewMonths->setObjectName(QString::fromUtf8("ChartsViewMonths"));

        verticalLayout_4->addWidget(ChartsViewMonths);

        ChartsViewYears = new QChartView(FormStatistics);
        ChartsViewYears->setObjectName(QString::fromUtf8("ChartsViewYears"));

        verticalLayout_4->addWidget(ChartsViewYears);


        retranslateUi(FormStatistics);

        QMetaObject::connectSlotsByName(FormStatistics);
    } // setupUi

    void retranslateUi(QWidget *FormStatistics)
    {
        FormStatistics->setWindowTitle(QCoreApplication::translate("FormStatistics", "Form", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("FormStatistics", "<html><head/><body><p><span style=\" font-family:'Open Sans','Arial','sans-serif'; font-size:12px; color:#000000;\">\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\275\320\260 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\265 \321\203 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\265\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217.</span></p><p><span style=\" font-family:'Open Sans','Arial','sans-serif'; font-size:12px; color:#000000;\">\320\225\321\201\320\273\320\270 \321\201\321\203\320\274\320\274\320\260\321\200\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320"
                        "\264\320\260\320\265\321\202 \321\201 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\265\320\271 \321\201\321\202\320\270\320\274\320\260, \320\267\320\275\320\260\321\207\320\270\321\202 \321\207\320\260\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\260 \321\201 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265\320\274 \321\201\320\265\320\274\320\265\320\271\320\275\320\276\320\263\320\276 \320\264\320\276\321\201\321\202\321\203\320\277\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelSummColumn->setText(QCoreApplication::translate("FormStatistics", "\320\222\321\201\320\265\320\263\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistics: public Ui_FormStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTICS_H
