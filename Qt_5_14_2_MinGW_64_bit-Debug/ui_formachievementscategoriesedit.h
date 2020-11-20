/********************************************************************************
** Form generated from reading UI file 'formachievementscategoriesedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTSCATEGORIESEDIT_H
#define UI_FORMACHIEVEMENTSCATEGORIESEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievementsCategoriesEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *LayoutCategoriesSettings_2;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonChangeCategory;
    QPushButton *ButtonDeleteAllCategories;
    QSpacerItem *horizontalSpacer_10;
    QListView *ListViewAll;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_19;
    QComboBox *ComboBoxCategories;
    QLineEdit *LineEditTitleCategory;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *ButtonAcceptCategory;
    QPushButton *ButtonDeleteCategory;
    QPushButton *ButtonCancelCategory;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *ButtonAddValueCategory;
    QCheckBox *CheckBoxCategoryUniqueValue;
    QSpacerItem *horizontalSpacer_12;
    QScrollArea *ScrollAreaValues;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_11;

    void setupUi(QWidget *FormAchievementsCategoriesEdit)
    {
        if (FormAchievementsCategoriesEdit->objectName().isEmpty())
            FormAchievementsCategoriesEdit->setObjectName(QString::fromUtf8("FormAchievementsCategoriesEdit"));
        FormAchievementsCategoriesEdit->resize(974, 547);
        horizontalLayout = new QHBoxLayout(FormAchievementsCategoriesEdit);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setSizeConstraint(QLayout::SetMaximumSize);
        LayoutCategoriesSettings_2 = new QHBoxLayout();
        LayoutCategoriesSettings_2->setObjectName(QString::fromUtf8("LayoutCategoriesSettings_2"));
        ButtonAddCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonAddCategory->sizePolicy().hasHeightForWidth());
        ButtonAddCategory->setSizePolicy(sizePolicy);

        LayoutCategoriesSettings_2->addWidget(ButtonAddCategory);

        ButtonChangeCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonChangeCategory->setObjectName(QString::fromUtf8("ButtonChangeCategory"));
        sizePolicy.setHeightForWidth(ButtonChangeCategory->sizePolicy().hasHeightForWidth());
        ButtonChangeCategory->setSizePolicy(sizePolicy);

        LayoutCategoriesSettings_2->addWidget(ButtonChangeCategory);

        ButtonDeleteAllCategories = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonDeleteAllCategories->setObjectName(QString::fromUtf8("ButtonDeleteAllCategories"));
        sizePolicy.setHeightForWidth(ButtonDeleteAllCategories->sizePolicy().hasHeightForWidth());
        ButtonDeleteAllCategories->setSizePolicy(sizePolicy);

        LayoutCategoriesSettings_2->addWidget(ButtonDeleteAllCategories);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        LayoutCategoriesSettings_2->addItem(horizontalSpacer_10);


        verticalLayout_10->addLayout(LayoutCategoriesSettings_2);

        ListViewAll = new QListView(FormAchievementsCategoriesEdit);
        ListViewAll->setObjectName(QString::fromUtf8("ListViewAll"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ListViewAll->sizePolicy().hasHeightForWidth());
        ListViewAll->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(ListViewAll);


        horizontalLayout->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        ComboBoxCategories = new QComboBox(FormAchievementsCategoriesEdit);
        ComboBoxCategories->addItem(QString());
        ComboBoxCategories->setObjectName(QString::fromUtf8("ComboBoxCategories"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ComboBoxCategories->sizePolicy().hasHeightForWidth());
        ComboBoxCategories->setSizePolicy(sizePolicy2);
        ComboBoxCategories->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_19->addWidget(ComboBoxCategories);

        LineEditTitleCategory = new QLineEdit(FormAchievementsCategoriesEdit);
        LineEditTitleCategory->setObjectName(QString::fromUtf8("LineEditTitleCategory"));
        sizePolicy2.setHeightForWidth(LineEditTitleCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategory->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(LineEditTitleCategory);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_13);

        ButtonAcceptCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonAcceptCategory->setObjectName(QString::fromUtf8("ButtonAcceptCategory"));

        horizontalLayout_19->addWidget(ButtonAcceptCategory);

        ButtonDeleteCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        horizontalLayout_19->addWidget(ButtonDeleteCategory);

        ButtonCancelCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonCancelCategory->setObjectName(QString::fromUtf8("ButtonCancelCategory"));

        horizontalLayout_19->addWidget(ButtonCancelCategory);


        verticalLayout_11->addLayout(horizontalLayout_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        ButtonAddValueCategory = new QPushButton(FormAchievementsCategoriesEdit);
        ButtonAddValueCategory->setObjectName(QString::fromUtf8("ButtonAddValueCategory"));

        horizontalLayout_18->addWidget(ButtonAddValueCategory);

        CheckBoxCategoryUniqueValue = new QCheckBox(FormAchievementsCategoriesEdit);
        CheckBoxCategoryUniqueValue->setObjectName(QString::fromUtf8("CheckBoxCategoryUniqueValue"));

        horizontalLayout_18->addWidget(CheckBoxCategoryUniqueValue);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_12);


        verticalLayout_11->addLayout(horizontalLayout_18);

        ScrollAreaValues = new QScrollArea(FormAchievementsCategoriesEdit);
        ScrollAreaValues->setObjectName(QString::fromUtf8("ScrollAreaValues"));
        ScrollAreaValues->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 688, 466));
        horizontalLayout_11 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        ScrollAreaValues->setWidget(scrollAreaWidgetContents);

        verticalLayout_11->addWidget(ScrollAreaValues);


        horizontalLayout->addLayout(verticalLayout_11);


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
        ButtonChangeCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonChangeCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setText(QString());
        ComboBoxCategories->setItemText(0, QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));

        LineEditTitleCategory->setPlaceholderText(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#if QT_CONFIG(tooltip)
        ButtonAcceptCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAcceptCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonCancelCategory->setToolTip(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonCancelCategory->setText(QString());
        ButtonAddValueCategory->setText(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        CheckBoxCategoryUniqueValue->setText(QCoreApplication::translate("FormAchievementsCategoriesEdit", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievementsCategoriesEdit: public Ui_FormAchievementsCategoriesEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTSCATEGORIESEDIT_H
