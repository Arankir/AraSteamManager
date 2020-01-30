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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subwidget/qradiobuttonwithdata.h"

QT_BEGIN_NAMESPACE

class Ui_FormCompareProfileFilter
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButtonWithData *RadioButtonAll;
    QRadioButtonWithData *RadioButtonReached;
    QRadioButtonWithData *RadioButtonNotReached;

    void setupUi(QWidget *FormCompareProfileFilter)
    {
        if (FormCompareProfileFilter->objectName().isEmpty())
            FormCompareProfileFilter->setObjectName(QString::fromUtf8("FormCompareProfileFilter"));
        FormCompareProfileFilter->resize(129, 130);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormCompareProfileFilter->setFont(font);
        verticalLayout = new QVBoxLayout(FormCompareProfileFilter);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        RadioButtonAll = new QRadioButtonWithData(FormCompareProfileFilter);
        RadioButtonAll->setObjectName(QString::fromUtf8("RadioButtonAll"));
        RadioButtonAll->setChecked(true);

        verticalLayout->addWidget(RadioButtonAll);

        RadioButtonReached = new QRadioButtonWithData(FormCompareProfileFilter);
        RadioButtonReached->setObjectName(QString::fromUtf8("RadioButtonReached"));

        verticalLayout->addWidget(RadioButtonReached);

        RadioButtonNotReached = new QRadioButtonWithData(FormCompareProfileFilter);
        RadioButtonNotReached->setObjectName(QString::fromUtf8("RadioButtonNotReached"));

        verticalLayout->addWidget(RadioButtonNotReached);


        retranslateUi(FormCompareProfileFilter);

        QMetaObject::connectSlotsByName(FormCompareProfileFilter);
    } // setupUi

    void retranslateUi(QWidget *FormCompareProfileFilter)
    {
        FormCompareProfileFilter->setWindowTitle(QApplication::translate("FormCompareProfileFilter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompareProfileFilter: public Ui_FormCompareProfileFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPAREPROFILEFILTER_H
