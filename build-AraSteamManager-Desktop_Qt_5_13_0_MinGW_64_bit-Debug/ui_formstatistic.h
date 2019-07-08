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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormStatistic
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;

    void setupUi(QWidget *FormStatistic)
    {
        if (FormStatistic->objectName().isEmpty())
            FormStatistic->setObjectName(QString::fromUtf8("FormStatistic"));
        FormStatistic->resize(936, 1033);
        gridLayout = new QGridLayout(FormStatistic);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FormStatistic);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 4);

        pushButton = new QPushButton(FormStatistic);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 4, 1, 1);

        label_2 = new QLabel(FormStatistic);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(FormStatistic);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(FormStatistic);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        label_5 = new QLabel(FormStatistic);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_6 = new QLabel(FormStatistic);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 3, 1, 1);

        label_7 = new QLabel(FormStatistic);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(FormStatistic);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        widget = new QWidget(FormStatistic);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 300));

        gridLayout->addWidget(widget, 5, 0, 1, 4);

        widget_2 = new QWidget(FormStatistic);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 300));

        gridLayout->addWidget(widget_2, 6, 0, 1, 4);

        widget_3 = new QWidget(FormStatistic);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 300));

        gridLayout->addWidget(widget_3, 7, 0, 1, 4);


        retranslateUi(FormStatistic);

        QMetaObject::connectSlotsByName(FormStatistic);
    } // setupUi

    void retranslateUi(QWidget *FormStatistic)
    {
        FormStatistic->setWindowTitle(QCoreApplication::translate("FormStatistic", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("FormStatistic", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("FormStatistic", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistic: public Ui_FormStatistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTIC_H
