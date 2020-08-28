/********************************************************************************
** Form generated from reading UI file 'formcategoryvalue_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCATEGORYVALUE_2_H
#define UI_FORMCATEGORYVALUE_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCategoryValue_2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditTitle;
    QPushButton *ButtonDelete;
    QListWidget *ListWidgetValue;

    void setupUi(QWidget *FormCategoryValue_2)
    {
        if (FormCategoryValue_2->objectName().isEmpty())
            FormCategoryValue_2->setObjectName(QString::fromUtf8("FormCategoryValue_2"));
        FormCategoryValue_2->resize(495, 466);
        verticalLayout = new QVBoxLayout(FormCategoryValue_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditTitle = new QLineEdit(FormCategoryValue_2);
        LineEditTitle->setObjectName(QString::fromUtf8("LineEditTitle"));

        horizontalLayout->addWidget(LineEditTitle);

        ButtonDelete = new QPushButton(FormCategoryValue_2);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));

        horizontalLayout->addWidget(ButtonDelete);


        verticalLayout->addLayout(horizontalLayout);

        ListWidgetValue = new QListWidget(FormCategoryValue_2);
        ListWidgetValue->setObjectName(QString::fromUtf8("ListWidgetValue"));
        ListWidgetValue->setDragDropMode(QAbstractItemView::DropOnly);

        verticalLayout->addWidget(ListWidgetValue);


        retranslateUi(FormCategoryValue_2);

        QMetaObject::connectSlotsByName(FormCategoryValue_2);
    } // setupUi

    void retranslateUi(QWidget *FormCategoryValue_2)
    {
        FormCategoryValue_2->setWindowTitle(QCoreApplication::translate("FormCategoryValue_2", "Form", nullptr));
        ButtonDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormCategoryValue_2: public Ui_FormCategoryValue_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCATEGORYVALUE_2_H
