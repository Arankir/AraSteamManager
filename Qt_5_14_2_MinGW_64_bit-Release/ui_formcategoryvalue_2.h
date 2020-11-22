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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonFirst;
    QPushButton *ButtonBack;
    QPushButton *ButtonNext;
    QPushButton *ButtonLast;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonReverse;
    QPushButton *ButtonAddVisible;
    QPushButton *ButtonRemoveVisible;
    QListView *ListViewValue;

    void setupUi(QWidget *FormCategoryValue_2)
    {
        if (FormCategoryValue_2->objectName().isEmpty())
            FormCategoryValue_2->setObjectName(QString::fromUtf8("FormCategoryValue_2"));
        FormCategoryValue_2->resize(286, 466);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonFirst = new QPushButton(FormCategoryValue_2);
        ButtonFirst->setObjectName(QString::fromUtf8("ButtonFirst"));

        horizontalLayout_2->addWidget(ButtonFirst);

        ButtonBack = new QPushButton(FormCategoryValue_2);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));

        horizontalLayout_2->addWidget(ButtonBack);

        ButtonNext = new QPushButton(FormCategoryValue_2);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));

        horizontalLayout_2->addWidget(ButtonNext);

        ButtonLast = new QPushButton(FormCategoryValue_2);
        ButtonLast->setObjectName(QString::fromUtf8("ButtonLast"));

        horizontalLayout_2->addWidget(ButtonLast);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ButtonReverse = new QPushButton(FormCategoryValue_2);
        ButtonReverse->setObjectName(QString::fromUtf8("ButtonReverse"));

        horizontalLayout_2->addWidget(ButtonReverse);

        ButtonAddVisible = new QPushButton(FormCategoryValue_2);
        ButtonAddVisible->setObjectName(QString::fromUtf8("ButtonAddVisible"));

        horizontalLayout_2->addWidget(ButtonAddVisible);

        ButtonRemoveVisible = new QPushButton(FormCategoryValue_2);
        ButtonRemoveVisible->setObjectName(QString::fromUtf8("ButtonRemoveVisible"));

        horizontalLayout_2->addWidget(ButtonRemoveVisible);


        verticalLayout->addLayout(horizontalLayout_2);

        ListViewValue = new QListView(FormCategoryValue_2);
        ListViewValue->setObjectName(QString::fromUtf8("ListViewValue"));

        verticalLayout->addWidget(ListViewValue);


        retranslateUi(FormCategoryValue_2);

        QMetaObject::connectSlotsByName(FormCategoryValue_2);
    } // setupUi

    void retranslateUi(QWidget *FormCategoryValue_2)
    {
        FormCategoryValue_2->setWindowTitle(QCoreApplication::translate("FormCategoryValue_2", "Form", nullptr));
        ButtonDelete->setText(QString());
        ButtonFirst->setText(QString());
        ButtonBack->setText(QString());
        ButtonNext->setText(QString());
        ButtonLast->setText(QString());
        ButtonReverse->setText(QString());
        ButtonAddVisible->setText(QString());
        ButtonRemoveVisible->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormCategoryValue_2: public Ui_FormCategoryValue_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCATEGORYVALUE_2_H
