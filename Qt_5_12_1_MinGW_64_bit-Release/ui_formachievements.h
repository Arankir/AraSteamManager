/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTS_H
#define UI_FORMACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelGameLogo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonReturn;
    QPushButton *ButtonCompare;
    QLabel *LabelGameTitle;
    QLabel *LabelGameOnline;
    QGroupBox *GroupBoxFilter;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *ScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *ScrollAreaCheckCategories;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonChangeCategory;
    QLabel *LabelTotalPersent;
    QPushButton *ButtonUpdate;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *RadioButtonAll;
    QRadioButton *RadioButtonReached;
    QRadioButton *RadioButtonNotReached;
    QCheckBox *CheckBoxFavorites;
    QGroupBox *GroupBoxAddCategory;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *LineEditTitleNewCategory;
    QCheckBox *CheckBoxNewCategoryOneValue;
    QPushButton *ButtonAddValueNewCategory;
    QScrollArea *ScrollAreaValues;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonCancelNewCategory;
    QPushButton *ButtonAcceptNewCategory;
    QGroupBox *GroupBoxChangeCategory;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QPushButton *ButtonAddValueChangeCategory;
    QCheckBox *CheckBoxChangeCategoryOneValue;
    QLineEdit *LineEditTitleCategoryChangeCategory;
    QComboBox *ComboBoxCategoriesChangeCategory;
    QScrollArea *ScrollAreaValuesChangeCategory;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ButtonCancelChangeCategory;
    QPushButton *ButtonDeleteCategory;
    QPushButton *ButtonAcceptChangeCategory;
    QGroupBox *GroupBoxCategories;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QTableWidget *TableWidgetAchievements;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(837, 838);
        verticalLayout_7 = new QVBoxLayout(FormAchievements);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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


        gridLayout->addWidget(groupBox, 0, 0, 3, 1);

        horizontalSpacer_2 = new QSpacerItem(636, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        ButtonReturn = new QPushButton(FormAchievements);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));

        gridLayout->addWidget(ButtonReturn, 0, 3, 1, 1);

        ButtonCompare = new QPushButton(FormAchievements);
        ButtonCompare->setObjectName(QString::fromUtf8("ButtonCompare"));

        gridLayout->addWidget(ButtonCompare, 1, 3, 1, 1);

        LabelGameTitle = new QLabel(FormAchievements);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));
        QFont font;
        font.setPointSize(14);
        LabelGameTitle->setFont(font);

        gridLayout->addWidget(LabelGameTitle, 1, 1, 1, 1);

        LabelGameOnline = new QLabel(FormAchievements);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        LabelGameOnline->setFont(font);

        gridLayout->addWidget(LabelGameOnline, 2, 1, 1, 2);


        verticalLayout_7->addLayout(gridLayout);

        GroupBoxFilter = new QGroupBox(FormAchievements);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupBoxFilter->sizePolicy().hasHeightForWidth());
        GroupBoxFilter->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(GroupBoxFilter);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ScrollAreaCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy1);
        ScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 292, 94));
        ScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy1.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy1);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 291, 94));
        ScrollAreaCheckCategories->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout_4->addWidget(ScrollAreaCheckCategories);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ButtonAddCategory = new QPushButton(GroupBoxFilter);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));

        verticalLayout_4->addWidget(ButtonAddCategory);

        ButtonChangeCategory = new QPushButton(GroupBoxFilter);
        ButtonChangeCategory->setObjectName(QString::fromUtf8("ButtonChangeCategory"));

        verticalLayout_4->addWidget(ButtonChangeCategory);

        LabelTotalPersent = new QLabel(GroupBoxFilter);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(LabelTotalPersent);

        ButtonUpdate = new QPushButton(GroupBoxFilter);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        verticalLayout_4->addWidget(ButtonUpdate);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        RadioButtonAll = new QRadioButton(GroupBoxFilter);
        RadioButtonAll->setObjectName(QString::fromUtf8("RadioButtonAll"));
        RadioButtonAll->setChecked(true);

        verticalLayout_5->addWidget(RadioButtonAll);

        RadioButtonReached = new QRadioButton(GroupBoxFilter);
        RadioButtonReached->setObjectName(QString::fromUtf8("RadioButtonReached"));

        verticalLayout_5->addWidget(RadioButtonReached);

        RadioButtonNotReached = new QRadioButton(GroupBoxFilter);
        RadioButtonNotReached->setObjectName(QString::fromUtf8("RadioButtonNotReached"));

        verticalLayout_5->addWidget(RadioButtonNotReached);

        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        verticalLayout_5->addWidget(CheckBoxFavorites);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_4);

        GroupBoxAddCategory = new QGroupBox(GroupBoxFilter);
        GroupBoxAddCategory->setObjectName(QString::fromUtf8("GroupBoxAddCategory"));
        horizontalLayout = new QHBoxLayout(GroupBoxAddCategory);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        LineEditTitleNewCategory = new QLineEdit(GroupBoxAddCategory);
        LineEditTitleNewCategory->setObjectName(QString::fromUtf8("LineEditTitleNewCategory"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LineEditTitleNewCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleNewCategory->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(LineEditTitleNewCategory);

        CheckBoxNewCategoryOneValue = new QCheckBox(GroupBoxAddCategory);
        CheckBoxNewCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxNewCategoryOneValue"));

        verticalLayout->addWidget(CheckBoxNewCategoryOneValue);

        ButtonAddValueNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonAddValueNewCategory->setObjectName(QString::fromUtf8("ButtonAddValueNewCategory"));

        verticalLayout->addWidget(ButtonAddValueNewCategory);


        horizontalLayout->addLayout(verticalLayout);

        ScrollAreaValues = new QScrollArea(GroupBoxAddCategory);
        ScrollAreaValues->setObjectName(QString::fromUtf8("ScrollAreaValues"));
        sizePolicy1.setHeightForWidth(ScrollAreaValues->sizePolicy().hasHeightForWidth());
        ScrollAreaValues->setSizePolicy(sizePolicy1);
        ScrollAreaValues->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 581, 74));
        ScrollAreaValues->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(ScrollAreaValues);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ButtonCancelNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonCancelNewCategory->setObjectName(QString::fromUtf8("ButtonCancelNewCategory"));

        verticalLayout_2->addWidget(ButtonCancelNewCategory);

        ButtonAcceptNewCategory = new QPushButton(GroupBoxAddCategory);
        ButtonAcceptNewCategory->setObjectName(QString::fromUtf8("ButtonAcceptNewCategory"));

        verticalLayout_2->addWidget(ButtonAcceptNewCategory);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(GroupBoxAddCategory);

        GroupBoxChangeCategory = new QGroupBox(GroupBoxFilter);
        GroupBoxChangeCategory->setObjectName(QString::fromUtf8("GroupBoxChangeCategory"));
        horizontalLayout_2 = new QHBoxLayout(GroupBoxChangeCategory);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        ButtonAddValueChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonAddValueChangeCategory->setObjectName(QString::fromUtf8("ButtonAddValueChangeCategory"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ButtonAddValueChangeCategory);

        CheckBoxChangeCategoryOneValue = new QCheckBox(GroupBoxChangeCategory);
        CheckBoxChangeCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxChangeCategoryOneValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, CheckBoxChangeCategoryOneValue);

        LineEditTitleCategoryChangeCategory = new QLineEdit(GroupBoxChangeCategory);
        LineEditTitleCategoryChangeCategory->setObjectName(QString::fromUtf8("LineEditTitleCategoryChangeCategory"));
        sizePolicy2.setHeightForWidth(LineEditTitleCategoryChangeCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategoryChangeCategory->setSizePolicy(sizePolicy2);

        formLayout->setWidget(1, QFormLayout::SpanningRole, LineEditTitleCategoryChangeCategory);

        ComboBoxCategoriesChangeCategory = new QComboBox(GroupBoxChangeCategory);
        ComboBoxCategoriesChangeCategory->setObjectName(QString::fromUtf8("ComboBoxCategoriesChangeCategory"));
        ComboBoxCategoriesChangeCategory->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::SpanningRole, ComboBoxCategoriesChangeCategory);


        horizontalLayout_2->addLayout(formLayout);

        ScrollAreaValuesChangeCategory = new QScrollArea(GroupBoxChangeCategory);
        ScrollAreaValuesChangeCategory->setObjectName(QString::fromUtf8("ScrollAreaValuesChangeCategory"));
        sizePolicy1.setHeightForWidth(ScrollAreaValuesChangeCategory->sizePolicy().hasHeightForWidth());
        ScrollAreaValuesChangeCategory->setSizePolicy(sizePolicy1);
        ScrollAreaValuesChangeCategory->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 532, 77));
        ScrollAreaValuesChangeCategory->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_2->addWidget(ScrollAreaValuesChangeCategory);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ButtonCancelChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonCancelChangeCategory->setObjectName(QString::fromUtf8("ButtonCancelChangeCategory"));

        verticalLayout_3->addWidget(ButtonCancelChangeCategory);

        ButtonDeleteCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        verticalLayout_3->addWidget(ButtonDeleteCategory);

        ButtonAcceptChangeCategory = new QPushButton(GroupBoxChangeCategory);
        ButtonAcceptChangeCategory->setObjectName(QString::fromUtf8("ButtonAcceptChangeCategory"));

        verticalLayout_3->addWidget(ButtonAcceptChangeCategory);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_6->addWidget(GroupBoxChangeCategory);

        GroupBoxCategories = new QGroupBox(GroupBoxFilter);
        GroupBoxCategories->setObjectName(QString::fromUtf8("GroupBoxCategories"));

        verticalLayout_6->addWidget(GroupBoxCategories);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LineEditNameAchievements = new QLineEdit(GroupBoxFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        horizontalLayout_3->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(GroupBoxFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);

        horizontalLayout_3->addWidget(ButtonFindAchievement);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_7->addWidget(GroupBoxFilter);

        TableWidgetAchievements = new QTableWidget(FormAchievements);
        TableWidgetAchievements->setObjectName(QString::fromUtf8("TableWidgetAchievements"));
        TableWidgetAchievements->setSortingEnabled(true);

        verticalLayout_7->addWidget(TableWidgetAchievements);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        groupBox->setTitle(QString());
        LabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
        ButtonReturn->setText(QApplication::translate("FormAchievements", "Return", nullptr));
        ButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        LabelGameTitle->setText(QApplication::translate("FormAchievements", "GameTitle", nullptr));
        LabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        GroupBoxFilter->setAccessibleName(QApplication::translate("FormAchievements", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        GroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "Filter", nullptr));
        ButtonAddCategory->setText(QApplication::translate("FormAchievements", "Add category", nullptr));
        ButtonChangeCategory->setText(QApplication::translate("FormAchievements", "Change category", nullptr));
        LabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        ButtonUpdate->setText(QApplication::translate("FormAchievements", "Update", nullptr));
        RadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        RadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        RadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        GroupBoxAddCategory->setTitle(QApplication::translate("FormAchievements", "New category", nullptr));
        LineEditTitleNewCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of category", nullptr));
        CheckBoxNewCategoryOneValue->setText(QApplication::translate("FormAchievements", "OneValue", nullptr));
        ButtonAddValueNewCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        ButtonCancelNewCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        ButtonAcceptNewCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        GroupBoxChangeCategory->setTitle(QApplication::translate("FormAchievements", "Change category", nullptr));
        ButtonAddValueChangeCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        CheckBoxChangeCategoryOneValue->setText(QApplication::translate("FormAchievements", "OneValue", nullptr));
        ButtonCancelChangeCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        ButtonDeleteCategory->setText(QApplication::translate("FormAchievements", "Delete", nullptr));
        ButtonAcceptChangeCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        GroupBoxCategories->setTitle(QApplication::translate("FormAchievements", "Categories", nullptr));
        ButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
