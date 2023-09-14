/********************************************************************************
** Form generated from reading UI file 'formcategoriesedit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCATEGORIESEDIT_H
#define UI_FORMCATEGORIESEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/lists/qlistwidgetachievements.h"

QT_BEGIN_NAMESPACE

class Ui_FormCategoriesEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *labelCategoryTitle;
    QHBoxLayout *horizontalLayout_2;
    QListWidgetAchievements *ListWidgetAll;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidgetAchievements *ListWidgetCategory;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonCancelCategory;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *ButtonAcceptCategory;

    void setupUi(QWidget *FormCategoriesEdit)
    {
        if (FormCategoriesEdit->objectName().isEmpty())
            FormCategoriesEdit->setObjectName(QString::fromUtf8("FormCategoriesEdit"));
        FormCategoriesEdit->resize(974, 547);
        verticalLayout_2 = new QVBoxLayout(FormCategoriesEdit);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelCategoryTitle = new QLabel(FormCategoriesEdit);
        labelCategoryTitle->setObjectName(QString::fromUtf8("labelCategoryTitle"));

        verticalLayout_2->addWidget(labelCategoryTitle);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ListWidgetAll = new QListWidgetAchievements(FormCategoriesEdit);
        ListWidgetAll->setObjectName(QString::fromUtf8("ListWidgetAll"));

        horizontalLayout_2->addWidget(ListWidgetAll);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FormCategoriesEdit);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        ListWidgetCategory = new QListWidgetAchievements(FormCategoriesEdit);
        ListWidgetCategory->setObjectName(QString::fromUtf8("ListWidgetCategory"));

        verticalLayout->addWidget(ListWidgetCategory);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonCancelCategory = new QPushButton(FormCategoriesEdit);
        ButtonCancelCategory->setObjectName(QString::fromUtf8("ButtonCancelCategory"));

        horizontalLayout->addWidget(ButtonCancelCategory);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        ButtonAcceptCategory = new QPushButton(FormCategoriesEdit);
        ButtonAcceptCategory->setObjectName(QString::fromUtf8("ButtonAcceptCategory"));

        horizontalLayout->addWidget(ButtonAcceptCategory);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FormCategoriesEdit);

        QMetaObject::connectSlotsByName(FormCategoriesEdit);
    } // setupUi

    void retranslateUi(QWidget *FormCategoriesEdit)
    {
        FormCategoriesEdit->setWindowTitle(QCoreApplication::translate("FormCategoriesEdit", "Form", nullptr));
        labelCategoryTitle->setText(QString());
        label->setText(QCoreApplication::translate("FormCategoriesEdit", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217 \320\262 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#if QT_CONFIG(tooltip)
        ButtonCancelCategory->setToolTip(QCoreApplication::translate("FormCategoriesEdit", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonCancelCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonAcceptCategory->setToolTip(QCoreApplication::translate("FormCategoriesEdit", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAcceptCategory->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormCategoriesEdit: public Ui_FormCategoriesEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCATEGORIESEDIT_H
