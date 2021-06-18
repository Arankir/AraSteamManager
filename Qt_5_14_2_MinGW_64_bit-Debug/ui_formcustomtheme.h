/********************************************************************************
** Form generated from reading UI file 'formcustomtheme.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCUSTOMTHEME_H
#define UI_FORMCUSTOMTHEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCustomTheme
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QPushButton *buttonChangeColor;

    void setupUi(QWidget *FormCustomTheme)
    {
        if (FormCustomTheme->objectName().isEmpty())
            FormCustomTheme->setObjectName(QString::fromUtf8("FormCustomTheme"));
        FormCustomTheme->resize(669, 466);
        horizontalLayout = new QHBoxLayout(FormCustomTheme);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton = new QRadioButton(FormCustomTheme);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        buttonChangeColor = new QPushButton(FormCustomTheme);
        buttonChangeColor->setObjectName(QString::fromUtf8("buttonChangeColor"));

        horizontalLayout->addWidget(buttonChangeColor);


        retranslateUi(FormCustomTheme);

        QMetaObject::connectSlotsByName(FormCustomTheme);
    } // setupUi

    void retranslateUi(QWidget *FormCustomTheme)
    {
        FormCustomTheme->setWindowTitle(QCoreApplication::translate("FormCustomTheme", "Form", nullptr));
        radioButton->setText(QString());
        buttonChangeColor->setText(QCoreApplication::translate("FormCustomTheme", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCustomTheme: public Ui_FormCustomTheme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCUSTOMTHEME_H
