/********************************************************************************
** Form generated from reading UI file 'formaddcategory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMADDCATEGORY_H
#define UI_FORMADDCATEGORY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAddCategory
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LineEditTitle;
    QCheckBox *CheckBoxNoValue;
    QPushButton *ButtonAddValue;
    QScrollArea *ScrollAreaValues;
    QWidget *ScrollAreaLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *ButtonCancel;
    QCheckBox *CheckBoxSelectAll;
    QPushButton *ButtonAccept;

    void setupUi(QWidget *FormAddCategory)
    {
        if (FormAddCategory->objectName().isEmpty())
            FormAddCategory->setObjectName(QString::fromUtf8("FormAddCategory"));
        FormAddCategory->resize(700, 103);
        horizontalLayout = new QHBoxLayout(FormAddCategory);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LineEditTitle = new QLineEdit(FormAddCategory);
        LineEditTitle->setObjectName(QString::fromUtf8("LineEditTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LineEditTitle->sizePolicy().hasHeightForWidth());
        LineEditTitle->setSizePolicy(sizePolicy);
        LineEditTitle->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(LineEditTitle);

        CheckBoxNoValue = new QCheckBox(FormAddCategory);
        CheckBoxNoValue->setObjectName(QString::fromUtf8("CheckBoxNoValue"));

        verticalLayout_2->addWidget(CheckBoxNoValue);

        ButtonAddValue = new QPushButton(FormAddCategory);
        ButtonAddValue->setObjectName(QString::fromUtf8("ButtonAddValue"));
        ButtonAddValue->setMaximumSize(QSize(150, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/program/program/create.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonAddValue->setIcon(icon);

        verticalLayout_2->addWidget(ButtonAddValue);


        horizontalLayout->addLayout(verticalLayout_2);

        ScrollAreaValues = new QScrollArea(FormAddCategory);
        ScrollAreaValues->setObjectName(QString::fromUtf8("ScrollAreaValues"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ScrollAreaValues->sizePolicy().hasHeightForWidth());
        ScrollAreaValues->setSizePolicy(sizePolicy1);
        ScrollAreaValues->setWidgetResizable(true);
        ScrollAreaLayout = new QWidget();
        ScrollAreaLayout->setObjectName(QString::fromUtf8("ScrollAreaLayout"));
        ScrollAreaLayout->setGeometry(QRect(0, 0, 498, 99));
        ScrollAreaValues->setWidget(ScrollAreaLayout);

        horizontalLayout->addWidget(ScrollAreaValues);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ButtonCancel = new QPushButton(FormAddCategory);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/program/program/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonCancel->setIcon(icon1);

        verticalLayout->addWidget(ButtonCancel);

        CheckBoxSelectAll = new QCheckBox(FormAddCategory);
        CheckBoxSelectAll->setObjectName(QString::fromUtf8("CheckBoxSelectAll"));
        CheckBoxSelectAll->setChecked(true);

        verticalLayout->addWidget(CheckBoxSelectAll);

        ButtonAccept = new QPushButton(FormAddCategory);
        ButtonAccept->setObjectName(QString::fromUtf8("ButtonAccept"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/program/program/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonAccept->setIcon(icon2);

        verticalLayout->addWidget(ButtonAccept);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FormAddCategory);

        QMetaObject::connectSlotsByName(FormAddCategory);
    } // setupUi

    void retranslateUi(QWidget *FormAddCategory)
    {
        FormAddCategory->setWindowTitle(QApplication::translate("FormAddCategory", "Form", nullptr));
        CheckBoxNoValue->setText(QApplication::translate("FormAddCategory", "CheckBox", nullptr));
        ButtonAddValue->setText(QApplication::translate("FormAddCategory", "AddValue", nullptr));
        ButtonCancel->setText(QApplication::translate("FormAddCategory", "Cancel", nullptr));
        CheckBoxSelectAll->setText(QApplication::translate("FormAddCategory", "SelectAll", nullptr));
        ButtonAccept->setText(QApplication::translate("FormAddCategory", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAddCategory: public Ui_FormAddCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMADDCATEGORY_H
