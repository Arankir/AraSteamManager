/********************************************************************************
** Form generated from reading UI file 'formstatistic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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

QT_BEGIN_NAMESPACE

class Ui_FormStatistic
{
public:
    QGridLayout *gridLayout;
    QPushButton *FormStatisticButtonReturn;
    QLabel *FormStatisticLabelAveragePercentage;
    QScrollArea *FormStatisticScrollAreaCustomPlots;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *FormStatisticLabelLogo;
    QLabel *FormStatisticLabelName;
    QLabel *FormStatisticLabelHundredPercentage;

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

        FormStatisticLabelAveragePercentage = new QLabel(FormStatistic);
        FormStatisticLabelAveragePercentage->setObjectName(QString::fromUtf8("FormStatisticLabelAveragePercentage"));

        gridLayout->addWidget(FormStatisticLabelAveragePercentage, 2, 0, 1, 1);

        FormStatisticScrollAreaCustomPlots = new QScrollArea(FormStatistic);
        FormStatisticScrollAreaCustomPlots->setObjectName(QString::fromUtf8("FormStatisticScrollAreaCustomPlots"));
        FormStatisticScrollAreaCustomPlots->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 916, 699));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormStatisticScrollAreaCustomPlots->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormStatisticScrollAreaCustomPlots, 4, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        FormStatisticLabelLogo = new QLabel(FormStatistic);
        FormStatisticLabelLogo->setObjectName(QString::fromUtf8("FormStatisticLabelLogo"));

        gridLayout->addWidget(FormStatisticLabelLogo, 0, 0, 1, 2);

        FormStatisticLabelName = new QLabel(FormStatistic);
        FormStatisticLabelName->setObjectName(QString::fromUtf8("FormStatisticLabelName"));

        gridLayout->addWidget(FormStatisticLabelName, 1, 0, 1, 1);

        FormStatisticLabelHundredPercentage = new QLabel(FormStatistic);
        FormStatisticLabelHundredPercentage->setObjectName(QString::fromUtf8("FormStatisticLabelHundredPercentage"));

        gridLayout->addWidget(FormStatisticLabelHundredPercentage, 3, 0, 1, 1);


        retranslateUi(FormStatistic);

        QMetaObject::connectSlotsByName(FormStatistic);
    } // setupUi

    void retranslateUi(QWidget *FormStatistic)
    {
        FormStatistic->setWindowTitle(QApplication::translate("FormStatistic", "Form", nullptr));
        FormStatisticButtonReturn->setText(QApplication::translate("FormStatistic", "Return", nullptr));
        FormStatisticLabelAveragePercentage->setText(QApplication::translate("FormStatistic", "AveragePercentage", nullptr));
        FormStatisticLabelLogo->setText(QApplication::translate("FormStatistic", "(WIP)", nullptr));
        FormStatisticLabelName->setText(QApplication::translate("FormStatistic", "Name", nullptr));
        FormStatisticLabelHundredPercentage->setText(QApplication::translate("FormStatistic", "HundredPercentage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistic: public Ui_FormStatistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTIC_H
