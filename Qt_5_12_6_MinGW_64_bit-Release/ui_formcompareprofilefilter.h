/********************************************************************************
** Form generated from reading UI file 'formcompareprofilefilter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMPAREPROFILEFILTER_H
#define UI_FORMCOMPAREPROFILEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCompareProfileFilter
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *FormCompareProfileFilter)
    {
        if (FormCompareProfileFilter->objectName().isEmpty())
            FormCompareProfileFilter->setObjectName(QString::fromUtf8("FormCompareProfileFilter"));
        FormCompareProfileFilter->resize(400, 300);
        radioButton = new QRadioButton(FormCompareProfileFilter);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 20, 85, 20));
        radioButton_2 = new QRadioButton(FormCompareProfileFilter);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 40, 85, 20));
        radioButton_3 = new QRadioButton(FormCompareProfileFilter);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 70, 85, 20));

        retranslateUi(FormCompareProfileFilter);

        QMetaObject::connectSlotsByName(FormCompareProfileFilter);
    } // setupUi

    void retranslateUi(QWidget *FormCompareProfileFilter)
    {
        FormCompareProfileFilter->setWindowTitle(QApplication::translate("FormCompareProfileFilter", "Form", nullptr));
        radioButton->setText(QApplication::translate("FormCompareProfileFilter", "All", nullptr));
        radioButton_2->setText(QApplication::translate("FormCompareProfileFilter", "Reached", nullptr));
        radioButton_3->setText(QApplication::translate("FormCompareProfileFilter", "Not reached", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompareProfileFilter: public Ui_FormCompareProfileFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPAREPROFILEFILTER_H
