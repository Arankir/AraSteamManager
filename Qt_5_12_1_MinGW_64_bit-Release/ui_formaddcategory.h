/********************************************************************************
** Form generated from reading UI file 'formaddcategory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMADDCATEGORY_H
#define UI_FORMADDCATEGORY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAddCategory
{
public:
    QGridLayout *gridLayout;
    QScrollArea *ScrollAreaValues;
    QWidget *ScrollAreaLayout;
    QLineEdit *LineEditTitle;
    QPushButton *ButtonCancel;
    QPushButton *ButtonAddValue;
    QCheckBox *CheckBoxNoValue;
    QCheckBox *CheckBoxSelectAll;
    QPushButton *ButtonAccept;

    void setupUi(QWidget *FormAddCategory)
    {
        if (FormAddCategory->objectName().isEmpty())
            FormAddCategory->setObjectName(QString::fromUtf8("FormAddCategory"));
        FormAddCategory->resize(700, 108);
        gridLayout = new QGridLayout(FormAddCategory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ScrollAreaValues = new QScrollArea(FormAddCategory);
        ScrollAreaValues->setObjectName(QString::fromUtf8("ScrollAreaValues"));
        ScrollAreaValues->setWidgetResizable(true);
        ScrollAreaLayout = new QWidget();
        ScrollAreaLayout->setObjectName(QString::fromUtf8("ScrollAreaLayout"));
        ScrollAreaLayout->setGeometry(QRect(0, 0, 438, 81));
        ScrollAreaValues->setWidget(ScrollAreaLayout);

        gridLayout->addWidget(ScrollAreaValues, 0, 1, 3, 1);

        LineEditTitle = new QLineEdit(FormAddCategory);
        LineEditTitle->setObjectName(QString::fromUtf8("LineEditTitle"));
        LineEditTitle->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(LineEditTitle, 0, 0, 1, 1);

        ButtonCancel = new QPushButton(FormAddCategory);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/program/program/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonCancel->setIcon(icon);

        gridLayout->addWidget(ButtonCancel, 0, 2, 1, 1);

        ButtonAddValue = new QPushButton(FormAddCategory);
        ButtonAddValue->setObjectName(QString::fromUtf8("ButtonAddValue"));
        ButtonAddValue->setMaximumSize(QSize(150, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/program/program/create.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonAddValue->setIcon(icon1);

        gridLayout->addWidget(ButtonAddValue, 2, 0, 1, 1);

        CheckBoxNoValue = new QCheckBox(FormAddCategory);
        CheckBoxNoValue->setObjectName(QString::fromUtf8("CheckBoxNoValue"));

        gridLayout->addWidget(CheckBoxNoValue, 1, 0, 1, 1);

        CheckBoxSelectAll = new QCheckBox(FormAddCategory);
        CheckBoxSelectAll->setObjectName(QString::fromUtf8("CheckBoxSelectAll"));
        CheckBoxSelectAll->setChecked(true);

        gridLayout->addWidget(CheckBoxSelectAll, 1, 2, 1, 1);

        ButtonAccept = new QPushButton(FormAddCategory);
        ButtonAccept->setObjectName(QString::fromUtf8("ButtonAccept"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/program/program/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonAccept->setIcon(icon2);

        gridLayout->addWidget(ButtonAccept, 2, 2, 1, 1);


        retranslateUi(FormAddCategory);

        QMetaObject::connectSlotsByName(FormAddCategory);
    } // setupUi

    void retranslateUi(QWidget *FormAddCategory)
    {
        FormAddCategory->setWindowTitle(QApplication::translate("FormAddCategory", "Form", nullptr));
        ButtonCancel->setText(QApplication::translate("FormAddCategory", "Cancel", nullptr));
        ButtonAddValue->setText(QApplication::translate("FormAddCategory", "AddValue", nullptr));
        CheckBoxNoValue->setText(QApplication::translate("FormAddCategory", "CheckBox", nullptr));
        CheckBoxSelectAll->setText(QApplication::translate("FormAddCategory", "SelectAll", nullptr));
        ButtonAccept->setText(QApplication::translate("FormAddCategory", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAddCategory: public Ui_FormAddCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMADDCATEGORY_H
