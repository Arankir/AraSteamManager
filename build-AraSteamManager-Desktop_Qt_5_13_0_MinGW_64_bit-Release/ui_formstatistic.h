/********************************************************************************
** Form generated from reading UI file 'formstatistic.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTATISTIC_H
#define UI_FORMSTATISTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FormStatistic
{
public:
    QGridLayout *gridLayout;
    QPushButton *FormStatisticButtonReturn;
    QLabel *FormStatisticLabelName;
    QSpacerItem *horizontalSpacer;
    QLabel *FormStatisticLabelAveragePercentage;
    QLabel *FormStatisticLabelHundredPercentage;
    QCustomPlot *FormStatisticCustomPlotGames;
    QScrollArea *FormStatisticScrollAreaCustomPlots;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QCustomPlot *FormStatisticCustomPlotYears;
    QCustomPlot *FormStatisticCustomPlotDays;
    QCustomPlot *FormStatisticCustomPlotMonths;
    QCustomPlot *FormStatisticCustomPlotHours;
    QLabel *FormStatisticLabelLogo;

    void setupUi(QWidget *FormStatistic)
    {
        if (FormStatistic->objectName().isEmpty())
            FormStatistic->setObjectName(QString::fromUtf8("FormStatistic"));
        FormStatistic->resize(936, 810);
        gridLayout = new QGridLayout(FormStatistic);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormStatisticButtonReturn = new QPushButton(FormStatistic);
        FormStatisticButtonReturn->setObjectName(QString::fromUtf8("FormStatisticButtonReturn"));

        gridLayout->addWidget(FormStatisticButtonReturn, 0, 2, 1, 1);

        FormStatisticLabelName = new QLabel(FormStatistic);
        FormStatisticLabelName->setObjectName(QString::fromUtf8("FormStatisticLabelName"));

        gridLayout->addWidget(FormStatisticLabelName, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        FormStatisticLabelAveragePercentage = new QLabel(FormStatistic);
        FormStatisticLabelAveragePercentage->setObjectName(QString::fromUtf8("FormStatisticLabelAveragePercentage"));

        gridLayout->addWidget(FormStatisticLabelAveragePercentage, 2, 0, 1, 1);

        FormStatisticLabelHundredPercentage = new QLabel(FormStatistic);
        FormStatisticLabelHundredPercentage->setObjectName(QString::fromUtf8("FormStatisticLabelHundredPercentage"));

        gridLayout->addWidget(FormStatisticLabelHundredPercentage, 3, 0, 1, 1);

        FormStatisticCustomPlotGames = new QCustomPlot(FormStatistic);
        FormStatisticCustomPlotGames->setObjectName(QString::fromUtf8("FormStatisticCustomPlotGames"));
        FormStatisticCustomPlotGames->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(FormStatisticCustomPlotGames, 4, 0, 1, 3);

        FormStatisticScrollAreaCustomPlots = new QScrollArea(FormStatistic);
        FormStatisticScrollAreaCustomPlots->setObjectName(QString::fromUtf8("FormStatisticScrollAreaCustomPlots"));
        FormStatisticScrollAreaCustomPlots->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 902, 1236));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormStatisticCustomPlotYears = new QCustomPlot(scrollAreaWidgetContents);
        FormStatisticCustomPlotYears->setObjectName(QString::fromUtf8("FormStatisticCustomPlotYears"));
        FormStatisticCustomPlotYears->setMinimumSize(QSize(0, 300));

        gridLayout_2->addWidget(FormStatisticCustomPlotYears, 4, 0, 1, 1);

        FormStatisticCustomPlotDays = new QCustomPlot(scrollAreaWidgetContents);
        FormStatisticCustomPlotDays->setObjectName(QString::fromUtf8("FormStatisticCustomPlotDays"));
        FormStatisticCustomPlotDays->setMinimumSize(QSize(0, 300));

        gridLayout_2->addWidget(FormStatisticCustomPlotDays, 1, 0, 1, 1);

        FormStatisticCustomPlotMonths = new QCustomPlot(scrollAreaWidgetContents);
        FormStatisticCustomPlotMonths->setObjectName(QString::fromUtf8("FormStatisticCustomPlotMonths"));
        FormStatisticCustomPlotMonths->setMinimumSize(QSize(0, 300));

        gridLayout_2->addWidget(FormStatisticCustomPlotMonths, 3, 0, 1, 1);

        FormStatisticCustomPlotHours = new QCustomPlot(scrollAreaWidgetContents);
        FormStatisticCustomPlotHours->setObjectName(QString::fromUtf8("FormStatisticCustomPlotHours"));
        FormStatisticCustomPlotHours->setMinimumSize(QSize(0, 300));

        gridLayout_2->addWidget(FormStatisticCustomPlotHours, 0, 0, 1, 1);

        FormStatisticScrollAreaCustomPlots->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormStatisticScrollAreaCustomPlots, 5, 0, 1, 3);

        FormStatisticLabelLogo = new QLabel(FormStatistic);
        FormStatisticLabelLogo->setObjectName(QString::fromUtf8("FormStatisticLabelLogo"));

        gridLayout->addWidget(FormStatisticLabelLogo, 0, 0, 1, 2);


        retranslateUi(FormStatistic);

        QMetaObject::connectSlotsByName(FormStatistic);
    } // setupUi

    void retranslateUi(QWidget *FormStatistic)
    {
        FormStatistic->setWindowTitle(QCoreApplication::translate("FormStatistic", "Form", nullptr));
        FormStatisticButtonReturn->setText(QCoreApplication::translate("FormStatistic", "Return", nullptr));
        FormStatisticLabelName->setText(QCoreApplication::translate("FormStatistic", "Name", nullptr));
        FormStatisticLabelAveragePercentage->setText(QCoreApplication::translate("FormStatistic", "AveragePercentage", nullptr));
        FormStatisticLabelHundredPercentage->setText(QCoreApplication::translate("FormStatistic", "HundredPercentage", nullptr));
        FormStatisticLabelLogo->setText(QCoreApplication::translate("FormStatistic", "(WIP)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistic: public Ui_FormStatistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTIC_H
