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
    QGroupBox *FormAchievementsGroupBoxChangeCategory;
    QGridLayout *gridLayout_3;
    QScrollArea *FormAchievementsScrollAreaValuesChangeCategory;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *FormAchievementsButtonAccessChangeCategory;
    QComboBox *FormAchievementsComboBoxCategoriesChangeCategory;
    QPushButton *FormAchievementsButtonAddValueChangeCategory;
    QPushButton *FormAchievementsButtonCancelChangeCategory;
    QLineEdit *FormAchievementsLineEditTitleValueChangeCategory;
    QPushButton *FormAchievementsButtonDeleteCategory;
    QLineEdit *FormAchievementsLineEditTitleCategoryChangeCategory;
    QGroupBox *FormAchievementsGroupBoxFilter;
    QGridLayout *gridLayout;
    QLineEdit *FormAchievementsLineEditNameAchievements;
    QRadioButton *FormAchievementsRadioButtonNotReached;
    QPushButton *FormAchievementsButtonAddCategory;
    QRadioButton *FormAchievementsRadioButtonAll;
    QPushButton *FormAchievementsButtonFindAchievement;
    QScrollArea *FormAchievementsScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QRadioButton *FormAchievementsRadioButtonReached;
    QLabel *FormAchievementsLabelTotalPersent;
    QPushButton *FormAchievementsButtonChangeCategory;
    QCheckBox *FormAchievementsCheckBoxFavorites;
    QGroupBox *FormAchievementsGroupBoxAddCategory;
    QGridLayout *gridLayout_2;
    QLineEdit *FormAchievementsLineEditTitleNewCategory;
    QScrollArea *FormAchievementsScrollAreaValues;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *FormAchievementsButtonCancelNewCategory;
    QPushButton *FormAchievementsButtonAccessNewCategory;
    QLineEdit *FormAchievementsLineEditTitleValueNewCategory;
    QPushButton *FormAchievementsButtonAddValueNewCategory;
    QLabel *FormAchievementsLabelGameOnline;
    QTableWidget *FormAchievementsTableWidgetAchievements;
    QPushButton *FormAchievementsButtonReturn;
    QPushButton *FormAchievementsButtonCompare;
    QLabel *FormAchievementsLabelGameLogo;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(777, 772);
        gridLayout_4 = new QGridLayout(FormAchievements);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        FormAchievementsGroupBoxChangeCategory = new QGroupBox(FormAchievements);
        FormAchievementsGroupBoxChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxChangeCategory"));
        gridLayout_3 = new QGridLayout(FormAchievementsGroupBoxChangeCategory);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FormAchievementsScrollAreaValuesChangeCategory = new QScrollArea(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsScrollAreaValuesChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsScrollAreaValuesChangeCategory"));
        FormAchievementsScrollAreaValuesChangeCategory->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 233, 68));
        FormAchievementsScrollAreaValuesChangeCategory->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(FormAchievementsScrollAreaValuesChangeCategory, 0, 3, 3, 1);

        FormAchievementsButtonAccessChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonAccessChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAccessChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonAccessChangeCategory, 2, 4, 1, 1);

        FormAchievementsComboBoxCategoriesChangeCategory = new QComboBox(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsComboBoxCategoriesChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsComboBoxCategoriesChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsComboBoxCategoriesChangeCategory, 0, 0, 1, 1);

        FormAchievementsButtonAddValueChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonAddValueChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddValueChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonAddValueChangeCategory, 2, 1, 1, 1);

        FormAchievementsButtonCancelChangeCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonCancelChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonCancelChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonCancelChangeCategory, 0, 4, 1, 1);

        FormAchievementsLineEditTitleValueChangeCategory = new QLineEdit(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsLineEditTitleValueChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsLineEditTitleValueChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsLineEditTitleValueChangeCategory, 2, 0, 1, 1);

        FormAchievementsButtonDeleteCategory = new QPushButton(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsButtonDeleteCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonDeleteCategory"));

        gridLayout_3->addWidget(FormAchievementsButtonDeleteCategory, 2, 2, 1, 1);

        FormAchievementsLineEditTitleCategoryChangeCategory = new QLineEdit(FormAchievementsGroupBoxChangeCategory);
        FormAchievementsLineEditTitleCategoryChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsLineEditTitleCategoryChangeCategory"));

        gridLayout_3->addWidget(FormAchievementsLineEditTitleCategoryChangeCategory, 0, 1, 1, 2);


        gridLayout_4->addWidget(FormAchievementsGroupBoxChangeCategory, 4, 0, 1, 5);

        FormAchievementsGroupBoxFilter = new QGroupBox(FormAchievements);
        FormAchievementsGroupBoxFilter->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxFilter"));
        gridLayout = new QGridLayout(FormAchievementsGroupBoxFilter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormAchievementsLineEditNameAchievements = new QLineEdit(FormAchievementsGroupBoxFilter);
        FormAchievementsLineEditNameAchievements->setObjectName(QString::fromUtf8("FormAchievementsLineEditNameAchievements"));

        gridLayout->addWidget(FormAchievementsLineEditNameAchievements, 0, 0, 1, 1);

        FormAchievementsRadioButtonNotReached = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonNotReached->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonNotReached"));

        gridLayout->addWidget(FormAchievementsRadioButtonNotReached, 2, 2, 1, 1);

        FormAchievementsButtonAddCategory = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonAddCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddCategory"));

        gridLayout->addWidget(FormAchievementsButtonAddCategory, 2, 1, 1, 1);

        FormAchievementsRadioButtonAll = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonAll->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonAll"));
        FormAchievementsRadioButtonAll->setChecked(true);

        gridLayout->addWidget(FormAchievementsRadioButtonAll, 0, 2, 1, 1);

        FormAchievementsButtonFindAchievement = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonFindAchievement->setObjectName(QString::fromUtf8("FormAchievementsButtonFindAchievement"));

        gridLayout->addWidget(FormAchievementsButtonFindAchievement, 0, 1, 1, 1);

        FormAchievementsScrollAreaCategories = new QScrollArea(FormAchievementsGroupBoxFilter);
        FormAchievementsScrollAreaCategories->setObjectName(QString::fromUtf8("FormAchievementsScrollAreaCategories"));
        FormAchievementsScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 537, 71));
        FormAchievementsScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormAchievementsScrollAreaCategories, 1, 0, 4, 1);

        FormAchievementsRadioButtonReached = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonReached->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonReached"));

        gridLayout->addWidget(FormAchievementsRadioButtonReached, 1, 2, 1, 1);

        FormAchievementsLabelTotalPersent = new QLabel(FormAchievementsGroupBoxFilter);
        FormAchievementsLabelTotalPersent->setObjectName(QString::fromUtf8("FormAchievementsLabelTotalPersent"));

        gridLayout->addWidget(FormAchievementsLabelTotalPersent, 1, 1, 1, 1);

        FormAchievementsButtonChangeCategory = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonChangeCategory"));

        gridLayout->addWidget(FormAchievementsButtonChangeCategory, 3, 1, 1, 1);

        FormAchievementsCheckBoxFavorites = new QCheckBox(FormAchievementsGroupBoxFilter);
        FormAchievementsCheckBoxFavorites->setObjectName(QString::fromUtf8("FormAchievementsCheckBoxFavorites"));

        gridLayout->addWidget(FormAchievementsCheckBoxFavorites, 3, 2, 1, 1);


        gridLayout_4->addWidget(FormAchievementsGroupBoxFilter, 2, 0, 1, 5);

        FormAchievementsGroupBoxAddCategory = new QGroupBox(FormAchievements);
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
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 276, 68));
        FormAchievementsScrollAreaValues->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(FormAchievementsScrollAreaValues, 0, 2, 3, 1);

        FormAchievementsButtonCancelNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonCancelNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonCancelNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonCancelNewCategory, 0, 3, 1, 1);

        FormAchievementsButtonAccessNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonAccessNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAccessNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonAccessNewCategory, 2, 3, 1, 1);

        FormAchievementsLineEditTitleValueNewCategory = new QLineEdit(FormAchievementsGroupBoxAddCategory);
        FormAchievementsLineEditTitleValueNewCategory->setObjectName(QString::fromUtf8("FormAchievementsLineEditTitleValueNewCategory"));

        gridLayout_2->addWidget(FormAchievementsLineEditTitleValueNewCategory, 2, 0, 1, 1);

        FormAchievementsButtonAddValueNewCategory = new QPushButton(FormAchievementsGroupBoxAddCategory);
        FormAchievementsButtonAddValueNewCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonAddValueNewCategory"));

        gridLayout_2->addWidget(FormAchievementsButtonAddValueNewCategory, 2, 1, 1, 1);


        gridLayout_4->addWidget(FormAchievementsGroupBoxAddCategory, 3, 0, 1, 5);

        FormAchievementsLabelGameOnline = new QLabel(FormAchievements);
        FormAchievementsLabelGameOnline->setObjectName(QString::fromUtf8("FormAchievementsLabelGameOnline"));
        QFont font;
        font.setPointSize(14);
        FormAchievementsLabelGameOnline->setFont(font);

        gridLayout_4->addWidget(FormAchievementsLabelGameOnline, 1, 1, 1, 1);

        FormAchievementsTableWidgetAchievements = new QTableWidget(FormAchievements);
        FormAchievementsTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAchievementsTableWidgetAchievements"));

        gridLayout_4->addWidget(FormAchievementsTableWidgetAchievements, 5, 0, 1, 5);

        FormAchievementsButtonReturn = new QPushButton(FormAchievements);
        FormAchievementsButtonReturn->setObjectName(QString::fromUtf8("FormAchievementsButtonReturn"));

        gridLayout_4->addWidget(FormAchievementsButtonReturn, 0, 4, 1, 1);

        FormAchievementsButtonCompare = new QPushButton(FormAchievements);
        FormAchievementsButtonCompare->setObjectName(QString::fromUtf8("FormAchievementsButtonCompare"));

        gridLayout_4->addWidget(FormAchievementsButtonCompare, 1, 4, 1, 1);

        FormAchievementsLabelGameLogo = new QLabel(FormAchievements);
        FormAchievementsLabelGameLogo->setObjectName(QString::fromUtf8("FormAchievementsLabelGameLogo"));

        gridLayout_4->addWidget(FormAchievementsLabelGameLogo, 0, 0, 2, 1);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "Form", nullptr));
        FormAchievementsGroupBoxChangeCategory->setTitle(QApplication::translate("FormAchievements", "Change category", nullptr));
        FormAchievementsButtonAccessChangeCategory->setText(QApplication::translate("FormAchievements", "Access", nullptr));
        FormAchievementsButtonAddValueChangeCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        FormAchievementsButtonCancelChangeCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        FormAchievementsLineEditTitleValueChangeCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of value", nullptr));
        FormAchievementsButtonDeleteCategory->setText(QApplication::translate("FormAchievements", "Delete", nullptr));
        FormAchievementsGroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "Filter", nullptr));
        FormAchievementsRadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        FormAchievementsButtonAddCategory->setText(QApplication::translate("FormAchievements", "Add category", nullptr));
        FormAchievementsRadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        FormAchievementsButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
        FormAchievementsRadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        FormAchievementsLabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        FormAchievementsButtonChangeCategory->setText(QApplication::translate("FormAchievements", "Change category", nullptr));
        FormAchievementsCheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        FormAchievementsGroupBoxAddCategory->setTitle(QApplication::translate("FormAchievements", "New category", nullptr));
        FormAchievementsLineEditTitleNewCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of category", nullptr));
        FormAchievementsButtonCancelNewCategory->setText(QApplication::translate("FormAchievements", "Cancel", nullptr));
        FormAchievementsButtonAccessNewCategory->setText(QApplication::translate("FormAchievements", "Access", nullptr));
        FormAchievementsLineEditTitleValueNewCategory->setPlaceholderText(QApplication::translate("FormAchievements", "Title of value", nullptr));
        FormAchievementsButtonAddValueNewCategory->setText(QApplication::translate("FormAchievements", "Add Value", nullptr));
        FormAchievementsLabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
        FormAchievementsButtonReturn->setText(QApplication::translate("FormAchievements", "Return", nullptr));
        FormAchievementsButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        FormAchievementsLabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
