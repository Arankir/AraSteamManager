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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QGridLayout *gridLayout_4;
    QLabel *FormAchievementsLabelGameOnline;
    QTableWidget *FormAchievementsTableWidgetAchievements;
    QPushButton *FormAchievementsButtonCompare;
    QPushButton *FormAchievementsButtonReturn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *FormAchievementsLabelGameLogo;
    QGroupBox *FormAchievementsGroupBoxFilter;
    QGridLayout *gridLayout;
    QLabel *FormAchievementsLabelTotalPersent;
    QGroupBox *FormAchievementsGroupBoxAddCategory;
    QGridLayout *gridLayout_2;
    QLineEdit *FormAchievementsLineEditTitleNewCategory;
    QScrollArea *FormAchievementsScrollAreaValues;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *FormAchievementsButtonCancelNewCategory;
    QPushButton *FormAchievementsButtonAcceptNewCategory;
    QPushButton *FormAchievementsButtonAddValueNewCategory;
    QPushButton *FormAchievementsButtonAddCategory;
    QRadioButton *FormAchievementsRadioButtonReached;
    QRadioButton *FormAchievementsRadioButtonAll;
    QCheckBox *FormAchievementsCheckBoxFavorites;
    QLineEdit *FormAchievementsLineEditNameAchievements;
    QPushButton *FormAchievementsButtonChangeCategory;
    QRadioButton *FormAchievementsRadioButtonNotReached;
    QScrollArea *FormAchievementsScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QPushButton *FormAchievementsButtonFindAchievement;
    QPushButton *FormAchievementsButtonUpdate;
    QGroupBox *FormAchievementsGroupBoxChangeCategory;
    QGridLayout *gridLayout_3;
    QLineEdit *FormAchievementsLineEditTitleCategoryChangeCategory;
    QComboBox *FormAchievementsComboBoxCategoriesChangeCategory;
    QPushButton *FormAchievementsButtonDeleteCategory;
    QPushButton *FormAchievementsButtonAddValueChangeCategory;
    QPushButton *FormAchievementsButtonAcceptChangeCategory;
    QPushButton *FormAchievementsButtonCancelChangeCategory;
    QScrollArea *FormAchievementsScrollAreaValuesChangeCategory;
    QWidget *scrollAreaWidgetContents_3;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(777, 838);
        gridLayout_4 = new QGridLayout(FormAchievements);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        FormAchievementsLabelGameOnline = new QLabel(FormAchievements);
        FormAchievementsLabelGameOnline->setObjectName(QString::fromUtf8("FormAchievementsLabelGameOnline"));
        QFont font;
        font.setPointSize(14);
        FormAchievementsLabelGameOnline->setFont(font);

        gridLayout_4->addWidget(FormAchievementsLabelGameOnline, 2, 1, 1, 1);

        FormAchievementsTableWidgetAchievements = new QTableWidget(FormAchievements);
        FormAchievementsTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAchievementsTableWidgetAchievements"));

        gridLayout_4->addWidget(FormAchievementsTableWidgetAchievements, 6, 0, 1, 6);

        FormAchievementsButtonCompare = new QPushButton(FormAchievements);
        FormAchievementsButtonCompare->setObjectName(QString::fromUtf8("FormAchievementsButtonCompare"));

        gridLayout_4->addWidget(FormAchievementsButtonCompare, 1, 5, 1, 1);

        FormAchievementsButtonReturn = new QPushButton(FormAchievements);
        FormAchievementsButtonReturn->setObjectName(QString::fromUtf8("FormAchievementsButtonReturn"));

        gridLayout_4->addWidget(FormAchievementsButtonReturn, 0, 5, 1, 1);

        groupBox = new QGroupBox(FormAchievements);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        FormAchievementsLabelGameLogo = new QLabel(groupBox);
        FormAchievementsLabelGameLogo->setObjectName(QString::fromUtf8("FormAchievementsLabelGameLogo"));

        gridLayout_5->addWidget(FormAchievementsLabelGameLogo, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 3, 1);

        FormAchievementsGroupBoxFilter = new QGroupBox(FormAchievements);
        FormAchievementsGroupBoxFilter->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxFilter"));
        gridLayout = new QGridLayout(FormAchievementsGroupBoxFilter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormAchievementsLabelTotalPersent = new QLabel(FormAchievementsGroupBoxFilter);
        FormAchievementsLabelTotalPersent->setObjectName(QString::fromUtf8("FormAchievementsLabelTotalPersent"));

        gridLayout->addWidget(FormAchievementsLabelTotalPersent, 1, 1, 1, 1);

        FormAchievementsGroupBoxAddCategory = new QGroupBox(FormAchievementsGroupBoxFilter);
        FormAchievementsGroupBoxAddCategory->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxAddCategory"));
        gridLayout_2 = new QGridLayout(FormAchievementsGroupBoxAddCategory);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormAchievementsLineEditTitleNewCategory = new QLineEdit(FormAchievementsGroupBoxAddCategory);
        FormAchievementsLineEditTitleNewCategory->setObjectName(QString::fromUtf8("FormAchievementsLineEditTitleNewCategory"));

        gridLayout_2->addWidget(FormAchievementsLineEditTitleNewCategory, 0, 0, 1, 2);

        FormAchievementsScrollAreaValues = new QScrollArea(FormAchievementsGroupBoxAddCategory);
        FormAchievementsScrollAreaValues->setObjectName(QString::fromUtf8("FormAchievementsScrollAreaValues"));
        FormAchievementsScrollAreaValues->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 509, 68));
        FormAchievementsScrollAreaValues->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(FormAchievementsScrollAreaValues, 0, 2, 3, 1);

        FormAchievementsButtonCancelNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonCancelNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonCancelNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonCancelNewCategory, 0, 3, 1, 1);

        FormAchievementsButtonAcceptNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonAcceptNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAcceptNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonAcceptNewCategory, 2, 3, 1, 1);

        FormAchievementsButtonAddValueNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonAddValueNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddValueNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonAddValueNewCategory, 2, 0, 1, 2);


        gridLayout->addWidget(FormAchievementsGroupBoxAddCategory, 6, 0, 1, 3);

        FormAchievementsButtonAddCategory = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonAddCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddCategory"));

        gridLayout->addWidget(FormAchievementsButtonAddCategory, 2, 1, 1, 1);

        FormAchievementsRadioButtonReached = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonReached->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonReached"));

        gridLayout->addWidget(FormAchievementsRadioButtonReached, 2, 2, 1, 1);

        FormAchievementsRadioButtonAll = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonAll->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonAll"));
        FormAchievementsRadioButtonAll->setChecked(true);

        gridLayout->addWidget(FormAchievementsRadioButtonAll, 1, 2, 1, 1);

        FormAchievementsCheckBoxFavorites = new QCheckBox(FormAchievementsGroupBoxFilter);
        FormAchievementsCheckBoxFavorites->setObjectName(QString::fromUtf8("FormAchievementsCheckBoxFavorites"));

        gridLayout->addWidget(FormAchievementsCheckBoxFavorites, 4, 2, 1, 1);

        FormAchievementsLineEditNameAchievements = new QLineEdit(FormAchievementsGroupBoxFilter);
        FormAchievementsLineEditNameAchievements->setObjectName(QString::fromUtf8("FormAchievementsLineEditNameAchievements"));

        gridLayout->addWidget(FormAchievementsLineEditNameAchievements, 8, 0, 1, 2);

        FormAchievementsButtonChangeCategory = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonChangeCategory"));

        gridLayout->addWidget(FormAchievementsButtonChangeCategory, 3, 1, 1, 1);

        FormAchievementsRadioButtonNotReached = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonNotReached->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonNotReached"));

        gridLayout->addWidget(FormAchievementsRadioButtonNotReached, 3, 2, 1, 1);

        FormAchievementsScrollAreaCategories = new QScrollArea(FormAchievementsGroupBoxFilter);
        FormAchievementsScrollAreaCategories->setObjectName(QString::fromUtf8("FormAchievementsScrollAreaCategories"));
        FormAchievementsScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 537, 98));
        FormAchievementsScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormAchievementsScrollAreaCategories, 1, 0, 5, 1);

        FormAchievementsButtonFindAchievement = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonFindAchievement->setObjectName(QString::fromUtf8("FormAchievementsButtonFindAchievement"));
        FormAchievementsButtonFindAchievement->setEnabled(true);

        gridLayout->addWidget(FormAchievementsButtonFindAchievement, 8, 2, 1, 1);

        FormAchievementsButtonUpdate = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonUpdate->setObjectName(QString::fromUtf8("FormAchievementsButtonUpdate"));

        gridLayout->addWidget(FormAchievementsButtonUpdate, 4, 1, 1, 1);

        FormAchievementsGroupBoxChangeCategory = new QGroupBox(FormAchievementsGroupBoxFilter);
        FormAchievementsGroupBoxChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxChangeCategory"));
        gridLayout_3 = new QGridLayout(FormAchievementsGroupBoxChangeCategory);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FormAchievementsLineEditTitleCategoryChangeCategory = new QLineEdit(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsLineEditTitleCategoryChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsLineEditTitleCategoryChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsLineEditTitleCategoryChangeCategory, 1, 0, 1, 2);

        FormAchievementsComboBoxCategoriesChangeCategory = new QComboBox(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsComboBoxCategoriesChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsComboBoxCategoriesChangeCategory"));
        FormAchievementsComboBoxCategoriesChangeCategory->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(FormAchievementsComboBoxCategoriesChangeCategory, 0, 0, 1, 2);

        FormAchievementsButtonDeleteCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonDeleteCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonDeleteCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonDeleteCategory, 1, 5, 1, 1);

        FormAchievementsButtonAddValueChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonAddValueChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddValueChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonAddValueChangeCategory, 2, 0, 1, 2);

        FormAchievementsButtonAcceptChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonAcceptChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAcceptChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonAcceptChangeCategory, 2, 5, 1, 1);

        FormAchievementsButtonCancelChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonCancelChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonCancelChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonCancelChangeCategory, 0, 5, 1, 1);

        FormAchievementsScrollAreaValuesChangeCategory = new QScrollArea(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsScrollAreaValuesChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsScrollAreaValuesChangeCategory"));
        FormAchievementsScrollAreaValuesChangeCategory->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 348, 75));
        FormAchievementsScrollAreaValuesChangeCategory->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(FormAchievementsScrollAreaValuesChangeCategory, 0, 2, 3, 3);


        gridLayout->addWidget(FormAchievementsGroupBoxChangeCategory, 7, 0, 1, 3);


        gridLayout_4->addWidget(FormAchievementsGroupBoxFilter, 3, 0, 1, 6);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        FormAchievementsLabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
        FormAchievementsButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        FormAchievementsButtonReturn->setText(QApplication::translate("FormAchievements", "Return", nullptr));
        groupBox->setTitle(QString());
        FormAchievementsLabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        FormAchievementsGroupBoxFilter->setAccessibleName(QApplication::translate("FormAchievements", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        FormAchievementsGroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "Filter", nullptr));
        FormAchievementsLabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        FormAchievementsGroupBoxAddCategory->setTitle(QApplication::translate("FormAchievements", "New category", nullptr));
        FormAchievementsLineEditTitleNewCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of category", nullptr));
        FormAchievementsButtonCancelNewCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        FormAchievementsButtonAcceptNewCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        FormAchievementsButtonAddValueNewCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        FormAchievementsButtonAddCategory->setText(QApplication::translate("FormAchievements", "Add category", nullptr));
        FormAchievementsRadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        FormAchievementsRadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        FormAchievementsCheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        FormAchievementsButtonChangeCategory->setText(QApplication::translate("FormAchievements", "Change category", nullptr));
        FormAchievementsRadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        FormAchievementsButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
        FormAchievementsButtonUpdate->setText(QApplication::translate("FormAchievements", "Update", nullptr));
        FormAchievementsGroupBoxChangeCategory->setTitle(QApplication::translate("FormAchievements", "Change category", nullptr));
        FormAchievementsButtonDeleteCategory->setText(QApplication::translate("FormAchievements", "Delete", nullptr));
        FormAchievementsButtonAddValueChangeCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        FormAchievementsButtonAcceptChangeCategory->setText(QApplication::translate("FormAchievements", "Accept", nullptr));
        FormAchievementsButtonCancelChangeCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
