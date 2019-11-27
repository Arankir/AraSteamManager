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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
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
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QPushButton *ButtonCompare;
    QCheckBox *CheckBoxShowFilter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelGameLogo;
    QLabel *LabelGameTitle;
    QSpacerItem *horizontalSpacer_3;
    QLabel *LabelGameOnline;
    QGroupBox *GroupBoxFilter;
    QVBoxLayout *verticalLayout_8;
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
    QGroupBox *GroupBoxCompareShowedColumns;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *RadioButtonAll;
    QRadioButton *RadioButtonReached;
    QRadioButton *RadioButtonNotReached;
    QCheckBox *CheckBoxFavorites;
    QCheckBox *CheckBoxCompareAllFriends;
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
    QTableWidget *TableWidgetCompareFriends;
    QProgressBar *ProgressBarFriendsLoad;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *TableWidgetAchievements;
    QTableWidget *TableWidgetCompareAchievements;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(837, 849);
        verticalLayout_6 = new QVBoxLayout(FormAchievements);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ButtonCompare = new QPushButton(FormAchievements);
        ButtonCompare->setObjectName(QString::fromUtf8("ButtonCompare"));

        gridLayout->addWidget(ButtonCompare, 0, 3, 1, 2);

        CheckBoxShowFilter = new QCheckBox(FormAchievements);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        gridLayout->addWidget(CheckBoxShowFilter, 1, 4, 1, 1);

        groupBox = new QGroupBox(FormAchievements);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        LabelGameLogo = new QLabel(groupBox);
        LabelGameLogo->setObjectName(QString::fromUtf8("LabelGameLogo"));
        sizePolicy.setHeightForWidth(LabelGameLogo->sizePolicy().hasHeightForWidth());
        LabelGameLogo->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(LabelGameLogo, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 3, 1);

        LabelGameTitle = new QLabel(FormAchievements);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelGameTitle->sizePolicy().hasHeightForWidth());
        LabelGameTitle->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Bright"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        LabelGameTitle->setFont(font);

        gridLayout->addWidget(LabelGameTitle, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 2);

        LabelGameOnline = new QLabel(FormAchievements);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        sizePolicy.setHeightForWidth(LabelGameOnline->sizePolicy().hasHeightForWidth());
        LabelGameOnline->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        LabelGameOnline->setFont(font1);

        gridLayout->addWidget(LabelGameOnline, 2, 1, 1, 4);


        verticalLayout_6->addLayout(gridLayout);

        GroupBoxFilter = new QGroupBox(FormAchievements);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(GroupBoxFilter->sizePolicy().hasHeightForWidth());
        GroupBoxFilter->setSizePolicy(sizePolicy2);
        verticalLayout_8 = new QVBoxLayout(GroupBoxFilter);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ScrollAreaCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 119));
        ScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy3.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 240, 119));
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

        GroupBoxCompareShowedColumns = new QGroupBox(GroupBoxFilter);
        GroupBoxCompareShowedColumns->setObjectName(QString::fromUtf8("GroupBoxCompareShowedColumns"));
        verticalLayout_9 = new QVBoxLayout(GroupBoxCompareShowedColumns);
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 1, 1, 1);
        CheckBoxCompareIcon = new QCheckBox(GroupBoxCompareShowedColumns);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        verticalLayout_9->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(GroupBoxCompareShowedColumns);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        verticalLayout_9->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(GroupBoxCompareShowedColumns);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        verticalLayout_9->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(GroupBoxCompareShowedColumns);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        verticalLayout_9->addWidget(CheckBoxCompareTotalPercent);


        horizontalLayout_4->addWidget(GroupBoxCompareShowedColumns);

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

        CheckBoxCompareAllFriends = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareAllFriends->setObjectName(QString::fromUtf8("CheckBoxCompareAllFriends"));

        verticalLayout_5->addWidget(CheckBoxCompareAllFriends);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_4);

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
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(LineEditTitleNewCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleNewCategory->setSizePolicy(sizePolicy4);

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
        sizePolicy3.setHeightForWidth(ScrollAreaValues->sizePolicy().hasHeightForWidth());
        ScrollAreaValues->setSizePolicy(sizePolicy3);
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


        verticalLayout_8->addWidget(GroupBoxAddCategory);

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
        sizePolicy4.setHeightForWidth(LineEditTitleCategoryChangeCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategoryChangeCategory->setSizePolicy(sizePolicy4);

        formLayout->setWidget(1, QFormLayout::SpanningRole, LineEditTitleCategoryChangeCategory);

        ComboBoxCategoriesChangeCategory = new QComboBox(GroupBoxChangeCategory);
        ComboBoxCategoriesChangeCategory->setObjectName(QString::fromUtf8("ComboBoxCategoriesChangeCategory"));
        ComboBoxCategoriesChangeCategory->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::SpanningRole, ComboBoxCategoriesChangeCategory);


        horizontalLayout_2->addLayout(formLayout);

        ScrollAreaValuesChangeCategory = new QScrollArea(GroupBoxChangeCategory);
        ScrollAreaValuesChangeCategory->setObjectName(QString::fromUtf8("ScrollAreaValuesChangeCategory"));
        sizePolicy3.setHeightForWidth(ScrollAreaValuesChangeCategory->sizePolicy().hasHeightForWidth());
        ScrollAreaValuesChangeCategory->setSizePolicy(sizePolicy3);
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


        verticalLayout_8->addWidget(GroupBoxChangeCategory);

        GroupBoxCategories = new QGroupBox(GroupBoxFilter);
        GroupBoxCategories->setObjectName(QString::fromUtf8("GroupBoxCategories"));

        verticalLayout_8->addWidget(GroupBoxCategories);

        TableWidgetCompareFriends = new QTableWidget(GroupBoxFilter);
        TableWidgetCompareFriends->setObjectName(QString::fromUtf8("TableWidgetCompareFriends"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(TableWidgetCompareFriends->sizePolicy().hasHeightForWidth());
        TableWidgetCompareFriends->setSizePolicy(sizePolicy5);

        verticalLayout_8->addWidget(TableWidgetCompareFriends);

        ProgressBarFriendsLoad = new QProgressBar(GroupBoxFilter);
        ProgressBarFriendsLoad->setObjectName(QString::fromUtf8("ProgressBarFriendsLoad"));
        ProgressBarFriendsLoad->setValue(0);

        verticalLayout_8->addWidget(ProgressBarFriendsLoad);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LineEditNameAchievements = new QLineEdit(GroupBoxFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        horizontalLayout_3->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(GroupBoxFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);

        horizontalLayout_3->addWidget(ButtonFindAchievement);


        verticalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(GroupBoxFilter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        TableWidgetAchievements = new QTableWidget(FormAchievements);
        TableWidgetAchievements->setObjectName(QString::fromUtf8("TableWidgetAchievements"));
        TableWidgetAchievements->setSortingEnabled(true);

        horizontalLayout_5->addWidget(TableWidgetAchievements);

        TableWidgetCompareAchievements = new QTableWidget(FormAchievements);
        TableWidgetCompareAchievements->setObjectName(QString::fromUtf8("TableWidgetCompareAchievements"));

        horizontalLayout_5->addWidget(TableWidgetCompareAchievements);


        verticalLayout_6->addLayout(horizontalLayout_5);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        ButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        CheckBoxShowFilter->setText(QApplication::translate("FormAchievements", "Show Filter", nullptr));
        groupBox->setTitle(QString());
        LabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
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
        GroupBoxCompareShowedColumns->setTitle(QApplication::translate("FormAchievements", "Showed columns", nullptr));
        CheckBoxCompareIcon->setText(QApplication::translate("FormAchievements", "Icon", nullptr));
        CheckBoxCompareTitle->setText(QApplication::translate("FormAchievements", "Title", nullptr));
        CheckBoxCompareDescription->setText(QApplication::translate("FormAchievements", "Description", nullptr));
        CheckBoxCompareTotalPercent->setText(QApplication::translate("FormAchievements", "Total percent", nullptr));
        RadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        RadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        RadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        CheckBoxCompareAllFriends->setText(QApplication::translate("FormAchievements", "All friends", nullptr));
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
        ProgressBarFriendsLoad->setFormat(QApplication::translate("FormAchievements", "%v/%m", nullptr));
        ButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
