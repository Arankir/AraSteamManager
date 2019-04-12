/********************************************************************************
** Form generated from reading UI file 'formchangecategory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHANGECATEGORY_H
#define UI_FORMCHANGECATEGORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormChangeCategory
{
public:
    QGridLayout *gridLayout;
    QLabel *FormChangeCategoryLabelGame;
    QComboBox *FormChangeCategoryComboBoxCategories;
    QLineEdit *FormChangeCategoryLineEditFind;
    QLineEdit *FormChangeCategoryLineEditAddValue;
    QPushButton *FormChangeCategoryButtonFind;
    QTableWidget *FormChangeCategoryTableWidgetAchievements;
    QScrollArea *FormChangeCategoryScrollAreaValues;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *FormChangeCategorLineEditTitleCategory;
    QPushButton *FormChangeCategoryButtonAccept;
    QPushButton *FormChangeCategoryButtonAddValue;
    QPushButton *FormChangeCategoryButtonReturn;

    void setupUi(QWidget *FormChangeCategory)
    {
        if (FormChangeCategory->objectName().isEmpty())
            FormChangeCategory->setObjectName(QString::fromUtf8("FormChangeCategory"));
        FormChangeCategory->resize(866, 716);
        gridLayout = new QGridLayout(FormChangeCategory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormChangeCategoryLabelGame = new QLabel(FormChangeCategory);
        FormChangeCategoryLabelGame->setObjectName(QString::fromUtf8("FormChangeCategoryLabelGame"));
        QFont font;
        font.setPointSize(14);
        FormChangeCategoryLabelGame->setFont(font);

        gridLayout->addWidget(FormChangeCategoryLabelGame, 0, 0, 1, 1);

        FormChangeCategoryComboBoxCategories = new QComboBox(FormChangeCategory);
        FormChangeCategoryComboBoxCategories->setObjectName(QString::fromUtf8("FormChangeCategoryComboBoxCategories"));

        gridLayout->addWidget(FormChangeCategoryComboBoxCategories, 1, 0, 1, 1);

        FormChangeCategoryLineEditFind = new QLineEdit(FormChangeCategory);
        FormChangeCategoryLineEditFind->setObjectName(QString::fromUtf8("FormChangeCategoryLineEditFind"));

        gridLayout->addWidget(FormChangeCategoryLineEditFind, 4, 0, 1, 16);

        FormChangeCategoryLineEditAddValue = new QLineEdit(FormChangeCategory);
        FormChangeCategoryLineEditAddValue->setObjectName(QString::fromUtf8("FormChangeCategoryLineEditAddValue"));

        gridLayout->addWidget(FormChangeCategoryLineEditAddValue, 2, 2, 1, 1);

        FormChangeCategoryButtonFind = new QPushButton(FormChangeCategory);
        FormChangeCategoryButtonFind->setObjectName(QString::fromUtf8("FormChangeCategoryButtonFind"));

        gridLayout->addWidget(FormChangeCategoryButtonFind, 4, 16, 1, 1);

        FormChangeCategoryTableWidgetAchievements = new QTableWidget(FormChangeCategory);
        FormChangeCategoryTableWidgetAchievements->setObjectName(QString::fromUtf8("FormChangeCategoryTableWidgetAchievements"));

        gridLayout->addWidget(FormChangeCategoryTableWidgetAchievements, 5, 0, 1, 17);

        FormChangeCategoryScrollAreaValues = new QScrollArea(FormChangeCategory);
        FormChangeCategoryScrollAreaValues->setObjectName(QString::fromUtf8("FormChangeCategoryScrollAreaValues"));
        FormChangeCategoryScrollAreaValues->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 336, 68));
        FormChangeCategoryScrollAreaValues->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormChangeCategoryScrollAreaValues, 2, 0, 2, 2);

        FormChangeCategorLineEditTitleCategory = new QLineEdit(FormChangeCategory);
        FormChangeCategorLineEditTitleCategory->setObjectName(QString::fromUtf8("FormChangeCategorLineEditTitleCategory"));

        gridLayout->addWidget(FormChangeCategorLineEditTitleCategory, 1, 1, 1, 1);

        FormChangeCategoryButtonAccept = new QPushButton(FormChangeCategory);
        FormChangeCategoryButtonAccept->setObjectName(QString::fromUtf8("FormChangeCategoryButtonAccept"));

        gridLayout->addWidget(FormChangeCategoryButtonAccept, 3, 14, 1, 3);

        FormChangeCategoryButtonAddValue = new QPushButton(FormChangeCategory);
        FormChangeCategoryButtonAddValue->setObjectName(QString::fromUtf8("FormChangeCategoryButtonAddValue"));

        gridLayout->addWidget(FormChangeCategoryButtonAddValue, 2, 3, 1, 1);

        FormChangeCategoryButtonReturn = new QPushButton(FormChangeCategory);
        FormChangeCategoryButtonReturn->setObjectName(QString::fromUtf8("FormChangeCategoryButtonReturn"));

        gridLayout->addWidget(FormChangeCategoryButtonReturn, 0, 16, 1, 1);


        retranslateUi(FormChangeCategory);

        QMetaObject::connectSlotsByName(FormChangeCategory);
    } // setupUi

    void retranslateUi(QWidget *FormChangeCategory)
    {
        FormChangeCategory->setWindowTitle(QApplication::translate("FormChangeCategory", "Form", nullptr));
        FormChangeCategoryLabelGame->setText(QApplication::translate("FormChangeCategory", "Game", nullptr));
        FormChangeCategoryButtonFind->setText(QApplication::translate("FormChangeCategory", "Find", nullptr));
        FormChangeCategoryButtonAccept->setText(QApplication::translate("FormChangeCategory", "Accept", nullptr));
        FormChangeCategoryButtonAddValue->setText(QApplication::translate("FormChangeCategory", "Add Value", nullptr));
        FormChangeCategoryButtonReturn->setText(QApplication::translate("FormChangeCategory", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormChangeCategory: public Ui_FormChangeCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHANGECATEGORY_H
