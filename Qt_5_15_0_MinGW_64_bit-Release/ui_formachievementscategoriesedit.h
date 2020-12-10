/********************************************************************************
** Form generated from reading UI file 'formachievementscategoriesedit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTSCATEGORIESEDIT_H
#define UI_FORMACHIEVEMENTSCATEGORIESEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subwidget/qlistwidgetachievements.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievementsCategoriesEdit
{
public:
    QHBoxLayout *horizontalLayout_3;
    QListWidgetAchievements *ListWidgetAll;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonDeleteCategory;
    QPushButton *ButtonDeleteAllCategories;
    QPushButton *ButtonChangeParent;
    QLabel *LabelCategoryParent;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *ButtonAcceptCategory;
    QPushButton *ButtonCancelCategory;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *LineEditTitleCategory;
    QListWidgetAchievements *ListWidgetCategory;
    QFrame *FrameSubCategories;
    QVBoxLayout *verticalLayout_2;
    QLabel *LabelSubCategories;
    QListWidget *ListWidgetSubCategories;

    void setupUi(QWidget *FormAchievementsCategoriesEdit)
    {
        if (FormAchievementsCategoriesEdit->objectName().isEmpty())
            FormAchievementsCategoriesEdit->setObjectName(QString::fromUtf8("FormAchievementsCategoriesEdit"));
        FormAchievementsCategoriesEdit->resize(974, 547);
        horizontalLayout_3 = new QHBoxLayout(FormAchievementsCategoriesEdit);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ListWidgetAll = new QListWidgetAchievements(FormAchievementsCategoriesEdit);
        ListWidgetAll->setObjectName(QString::fromUtf8("ListWidgetAll"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListWidgetAll->sizePolicy().hasHeightForWidth());
        ListWidgetAll->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(ListWidgetAll);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonAddCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonAddCategory->sizePolicy().hasHeightForWidth());
        ButtonAddCategory->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(ButtonAddCategory);

        ButtonDeleteCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        horizontalLayout->addWidget(ButtonDeleteCategory);

        ButtonDeleteAllCategories = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonDeleteAllCategories->setObjectName(QString::fromUtf8("ButtonDeleteAllCategories"));
        sizePolicy1.setHeightForWidth(ButtonDeleteAllCategories->sizePolicy().hasHeightForWidth());
        ButtonDeleteAllCategories->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(ButtonDeleteAllCategories);

        ButtonChangeParent = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonChangeParent->setObjectName(QString::fromUtf8("ButtonChangeParent"));

        horizontalLayout->addWidget(ButtonChangeParent);

        LabelCategoryParent = new QLabel(FormAchievementsCategoriesEdit);
        LabelCategoryParent->setObjectName(QString::fromUtf8("LabelCategoryParent"));
        LabelCategoryParent->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(LabelCategoryParent);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        ButtonAcceptCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonAcceptCategory->setObjectName(QString::fromUtf8("ButtonAcceptCategory"));

        horizontalLayout->addWidget(ButtonAcceptCategory);

        ButtonCancelCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonCancelCategory->setObjectName(QString::fromUtf8("ButtonCancelCategory"));

        horizontalLayout->addWidget(ButtonCancelCategory);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LineEditTitleCategory = new QLineEdit(FormAchievementsCategoriesEdit);
        LineEditTitleCategory->setObjectName(QString::fromUtf8("LineEditTitleCategory"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LineEditTitleCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategory->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(LineEditTitleCategory);

        ListWidgetCategory = new QListWidgetAchievements(FormAchievementsCategoriesEdit);
        ListWidgetCategory->setObjectName(QString::fromUtf8("ListWidgetCategory"));

        verticalLayout->addWidget(ListWidgetCategory);


        horizontalLayout_2->addLayout(verticalLayout);

        FrameSubCategories = new QFrame(FormAchievementsCategoriesEdit);
        FrameSubCategories->setObjectName(QString::fromUtf8("FrameSubCategories"));
        FrameSubCategories->setFrameShape(QFrame::StyledPanel);
        FrameSubCategories->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FrameSubCategories);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LabelSubCategories = new QLabel(FrameSubCategories);
        LabelSubCategories->setObjectName(QString::fromUtf8("LabelSubCategories"));

        verticalLayout_2->addWidget(LabelSubCategories);

        ListWidgetSubCategories = new QListWidget(FrameSubCategories);
        ListWidgetSubCategories->setObjectName(QString::fromUtf8("ListWidgetSubCategories"));

        verticalLayout_2->addWidget(ListWidgetSubCategories);


        horizontalLayout_2->addWidget(FrameSubCategories);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(FormAchievementsCategoriesEdit);

        QMetaObject::connectSlotsByName(FormAchievementsCategoriesEdit);
    } // setupUi

    void retranslateUi(QWidget *FormAchievementsCategoriesEdit)
    {
        FormAchievementsCategoriesEdit->setWindowTitle(QCoreApplication::translate("FormAchievementsCategoriesEdit", "Form", nullptr));
#if QT_CONFIG(tooltip)
        ButtonAddCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAddCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setText(QString());
        ButtonChangeParent->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonAcceptCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAcceptCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonCancelCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonCancelCategory->setText(QString());
        LineEditTitleCategory->setPlaceholderText(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        LabelSubCategories->setText(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\237\320\276\320\264\320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievementsCategoriesEdit: public Ui_FormAchievementsCategoriesEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTSCATEGORIESEDIT_H
