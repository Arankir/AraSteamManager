/********************************************************************************
** Form generated from reading UI file 'formreachedfilter.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMREACHEDFILTER_H
#define UI_FORMREACHEDFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormReachedFilter
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *FormReachedFilter)
    {
        if (FormReachedFilter->objectName().isEmpty())
            FormReachedFilter->setObjectName(QString::fromUtf8("FormReachedFilter"));
        FormReachedFilter->resize(180, 129);
        horizontalLayout = new QHBoxLayout(FormReachedFilter);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(FormReachedFilter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(FormReachedFilter);

        QMetaObject::connectSlotsByName(FormReachedFilter);
    } // setupUi

    void retranslateUi(QWidget *FormReachedFilter)
    {
        FormReachedFilter->setWindowTitle(QCoreApplication::translate("FormReachedFilter", "Form", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormReachedFilter: public Ui_FormReachedFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMREACHEDFILTER_H
