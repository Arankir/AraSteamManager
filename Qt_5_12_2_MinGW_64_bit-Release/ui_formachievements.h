/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTS_H
#define UI_FORMACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QGridLayout *gridLayout_4;
    QLabel *LabelGameOnline;
    QGroupBox *GroupBoxFilter;
    QGridLayout *gridLayout;
    QRadioButton *RadioButtonAll;
    QPushButton *ButtonFindAchievement;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonChangeCategory;
    QRadioButton *RadioButtonReached;
    QScrollArea *ScrollAreaCheckCategories;
    QWidget *scrollAreaWidgetContents_4;
    QScrollArea *ScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *GroupBoxAddCategory;
    QGridLayout *gridLayout_2;
    QLineEdit *LineEditTitleNewCategory;
    QScrollArea *ScrollAreaValues;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *ButtonCancelNewCategory;
    QPushButton *ButtonAcceptNewCategory;
    QPushButton *ButtonAddValueNewCategory;
    QCheckBox *CheckBoxNewCategoryOneValue;
    QGroupBox *GroupBoxChangeCategory;
    QGridLayout *gridLayout_3;
    QLineEdit *LineEditTitleCategoryChangeCategory;
    QComboBox *ComboBoxCategoriesChangeCategory;
    QPushButton *ButtonDeleteCategory;
    QPushButton *ButtonAddValueChangeCategory;
    QPushButton *ButtonAcceptChangeCategory;
    QPushButton *ButtonCancelChangeCategory;
    QScrollArea *ScrollAreaValuesChangeCategory;
    QWidget *scrollAreaWidgetContents_3;
    QCheckBox *CheckBoxChangeCategoryOneValue;
    QLineEdit *LineEditNameAchievements;
    QLabel *LabelTotalPersent;
    QRadioButton *RadioButtonNotReached;
    QPushButton *ButtonUpdate;
    QCheckBox *CheckBoxFavorites;
    QPushButton *ButtonReturn;
    QTableWidget *TableWidgetAchievements;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelGameLogo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonCompare;
    QGroupBox *GroupBoxCategories;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(837, 838);
        gridLayout_4 = new QGridLayout(FormAchievements);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        LabelGameOnline = new QLabel(FormAchievements);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        QFont font;
        font.setPointSize(14);
        LabelGameOnline->setFont(font);

        gridLayout_4->addWidget(LabelGameOnline, 2, 1, 1, 1);

        GroupBoxFilter = new QGroupBox(FormAchievements);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        gridLayout = new QGridLayout(GroupBoxFilter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RadioButtonAll = new QRadioButton(GroupBoxFilter);
        RadioButtonAll->setObjectName(QString::fromUtf8("RadioButtonAll"));
        RadioButtonAll->setChecked(true);

        gridLayout->addWidget(RadioButtonAll, 0, 3, 1, 1);

        ButtonFindAchievement = new QPushButton(GroupBoxFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);

        gridLayout->addWidget(ButtonFindAchievement, 8, 3, 1, 1);

        ButtonAddCategory = new QPushButton(GroupBoxFilter);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));

        gridLayout->addWidget(ButtonAddCategory, 0, 2, 1, 1);

        ButtonChangeCategory = new QPushButton(GroupBoxFilter);
        ButtonChangeCategory->setObjectName(QString::fromUtf8("ButtonChangeCategory"));

        gridLayout->addWidget(ButtonChangeCategory, 1, 2, 1, 1);

        RadioButtonReached = new QRadioButton(GroupBoxFilter);
        RadioButtonReached->setObjectName(QString::fromUtf8("RadioButtonReached"));

        gridLayout->addWidget(RadioButtonReached, 1, 3, 1, 1);

        ScrollAreaCheckCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        ScrollAreaCheckCategories->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 294, 98));
        ScrollAreaCheckCategories->setWidget(scrollAreaWidgetContents_4);

        gridLayout->addWidget(ScrollAreaCheckCategories, 0, 1, 6, 1);

        ScrollAreaCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        ScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 295, 98));
        ScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(ScrollAreaCategories, 0, 0, 6, 1);

        GroupBoxAddCategory = new QGroupBox(GroupBoxFilter);
        GroupBoxAddCategory->setObjectName(QString::fromUtf8("GroupBoxAddCategory"));
        gridLayout_2 = new QGridLayout(GroupBoxAddCategory);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        LineEditTitleNewCategory = new QLineEdit(GroupBoxAddCategory);
        LineEditTitleNewCategory->setObjectName(QString::fromUtf8("LineEditTitleNewCategory"));

        gridLayout_2->addWidget(LineEditTitleNewCategory, 0, 0, 1, 2);

        ScrollAreaValues = new QScrollArea(GroupBoxAddCategory);
        ScrollAreaValues->setObjectName(QString::fromUtf8("ScrollAreaValues"));
        ScrollAreaValues->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 569, 72));
        ScrollAreaValues->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(ScrollAreaValues, 0, 2, 3, 1);

        ButtonCancelNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonCancelNewCategory->setObjectName(QString::fromUtf8("ButtonCancelNewCategory"));

        gridLayout_2->addWidget(ButtonCancelNewCategory, 0, 3, 1, 1);

        ButtonAcceptNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonAcceptNewCategory->setObjectName(QString::fromUtf8("ButtonAcceptNewCategory"));

        gridLayout_2->addWidget(ButtonAcceptNewCategory, 2, 3, 1, 1);

        ButtonAddValueNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonAddValueNewCategory->setObjectName(QString::fromUtf8("ButtonAddValueNewCategory"));

        gridLayout_2->addWidget(ButtonAddValueNewCategory, 2, 0, 1, 2);

        CheckBoxNewCategoryOneValue = new QCheckBox(GroupBoxAddCategory);
        CheckBoxNewCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxNewCategoryOneValue"));

        gridLayout_2->addWidget(CheckBoxNewCategoryOneValue, 1, 0, 1, 2);


        gridLayout->addWidget(GroupBoxAddCategory, 6, 0, 1, 4);

        GroupBoxChangeCategory = new QGroupBox(GroupBoxFilter);
        GroupBoxChangeCategory->setObjectName(QString::fromUtf8("GroupBoxChangeCategory"));
        gridLayout_3 = new QGridLayout(GroupBoxChangeCategory);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LineEditTitleCategoryChangeCategory = new QLineEdit(GroupBoxChangeCategory);
        LineEditTitleCategoryChangeCategory->setObjectName(QString::fromUtf8("LineEditTitleCategoryChangeCategory"));

        gridLayout_3->addWidget(LineEditTitleCategoryChangeCategory, 1, 0, 1, 2);

        ComboBoxCategoriesChangeCategory = new QComboBox(GroupBoxChangeCategory);
        ComboBoxCategoriesChangeCategory->setObjectName(QString::fromUtf8("ComboBoxCategoriesChangeCategory"));
        ComboBoxCategoriesChangeCategory->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(ComboBoxCategoriesChangeCategory, 0, 0, 1, 2);

        ButtonDeleteCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        gridLayout_3->addWidget(ButtonDeleteCategory, 1, 5, 1, 1);

        ButtonAddValueChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonAddValueChangeCategory->setObjectName(QString::fromUtf8("ButtonAddValueChangeCategory"));

        gridLayout_3->addWidget(ButtonAddValueChangeCategory, 2, 0, 1, 1);

        ButtonAcceptChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonAcceptChangeCategory->setObjectName(QString::fromUtf8("ButtonAcceptChangeCategory"));

        gridLayout_3->addWidget(ButtonAcceptChangeCategory, 2, 5, 1, 1);

        ButtonCancelChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonCancelChangeCategory->setObjectName(QString::fromUtf8("ButtonCancelChangeCategory"));

        gridLayout_3->addWidget(ButtonCancelChangeCategory, 0, 5, 1, 1);

        ScrollAreaValuesChangeCategory = new QScrollArea(GroupBoxChangeCategory);
        ScrollAreaValuesChangeCategory->setObjectName(QString::fromUtf8("ScrollAreaValuesChangeCategory"));
        ScrollAreaValuesChangeCategory->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 375, 75));
        ScrollAreaValuesChangeCategory->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(ScrollAreaValuesChangeCategory, 0, 2, 3, 3);

        CheckBoxChangeCategoryOneValue = new QCheckBox(GroupBoxChangeCategory);
        CheckBoxChangeCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxChangeCategoryOneValue"));

        gridLayout_3->addWidget(CheckBoxChangeCategoryOneValue, 2, 1, 1, 1);


        gridLayout->addWidget(GroupBoxChangeCategory, 7, 0, 1, 4);

        LineEditNameAchievements = new QLineEdit(GroupBoxFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        gridLayout->addWidget(LineEditNameAchievements, 8, 0, 1, 3);

        LabelTotalPersent = new QLabel(GroupBoxFilter);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LabelTotalPersent, 2, 2, 1, 1);

        RadioButtonNotReached = new QRadioButton(GroupBoxFilter);
        RadioButtonNotReached->setObjectName(QString::fromUtf8("RadioButtonNotReached"));

        gridLayout->addWidget(RadioButtonNotReached, 2, 3, 1, 1);

        ButtonUpdate = new QPushButton(GroupBoxFilter);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        gridLayout->addWidget(ButtonUpdate, 3, 2, 1, 1);

        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        gridLayout->addWidget(CheckBoxFavorites, 3, 3, 1, 1);


        gridLayout_4->addWidget(GroupBoxFilter, 3, 0, 1, 3);

        ButtonReturn = new QPushButton(FormAchievements);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));

        gridLayout_4->addWidget(ButtonReturn, 0, 2, 1, 1);

        TableWidgetAchievements = new QTableWidget(FormAchievements);
        TableWidgetAchievements->setObjectName(QString::fromUtf8("TableWidgetAchievements"));
        TableWidgetAchievements->setSortingEnabled(true);

        gridLayout_4->addWidget(TableWidgetAchievements, 6, 0, 1, 3);

        groupBox = new QGroupBox(FormAchievements);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        LabelGameLogo = new QLabel(groupBox);
        LabelGameLogo->setObjectName(QString::fromUtf8("LabelGameLogo"));

        gridLayout_5->addWidget(LabelGameLogo, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 3, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        ButtonCompare = new QPushButton(FormAchievements);
        ButtonCompare->setObjectName(QString::fromUtf8("ButtonCompare"));

        gridLayout_4->addWidget(ButtonCompare, 1, 2, 1, 1);

        GroupBoxCategories = new QGroupBox(FormAchievements);
        GroupBoxCategories->setObjectName(QString::fromUtf8("GroupBoxCategories"));

        gridLayout_4->addWidget(GroupBoxCategories, 4, 0, 1, 3);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        LabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        GroupBoxFilter->setAccessibleName(QApplication::translate("FormAchievements", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        GroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "Filter", nullptr));
        RadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        ButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
        ButtonAddCategory->setText(QApplication::translate("FormAchievements", "Add category", nullptr));
        ButtonChangeCategory->setText(QApplication::translate("FormAchievements", "Change category", nullptr));
        RadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        GroupBoxAddCategory->setTitle(QApplication::translate("FormAchievements", "New category", nullptr));
        LineEditTitleNewCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of category", nullptr));
        ButtonCancelNewCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        ButtonAcceptNewCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        ButtonAddValueNewCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        CheckBoxNewCategoryOneValue->setText(QApplication::translate("FormAchievements", "OneValue", nullptr));
        GroupBoxChangeCategory->setTitle(QApplication::translate("FormAchievements", "Change category", nullptr));
        ButtonDeleteCategory->setText(QApplication::translate("FormAchievements", "Delete", nullptr));
        ButtonAddValueChangeCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        ButtonAcceptChangeCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        ButtonCancelChangeCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        CheckBoxChangeCategoryOneValue->setText(QApplication::translate("FormAchievements", "OneValue", nullptr));
        LabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        RadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        ButtonUpdate->setText(QApplication::translate("FormAchievements", "Update", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        ButtonReturn->setText(QApplication::translate("FormAchievements", "Return", nullptr));
        groupBox->setTitle(QString());
        LabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
        ButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        GroupBoxCategories->setTitle(QApplication::translate("FormAchievements", "Categories", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
