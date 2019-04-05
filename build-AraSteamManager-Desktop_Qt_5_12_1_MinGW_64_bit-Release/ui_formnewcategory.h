/********************************************************************************
** Form generated from reading UI file 'formnewcategory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNEWCATEGORY_H
#define UI_FORMNEWCATEGORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNewCategory
{
public:
    QGridLayout *gridLayout;
    QLabel *FormAddCategoryLabelParameterValue;
    QLineEdit *FormAddCategoryLineEditNameCategory;
    QTableWidget *FormAddCategoryTableWidgetAchievements;
    QLabel *FormAddCategoryLabelNameCategory;
    QScrollArea *FormAddCategoryScrollAreaValuae;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *FormAddCategoryLineEditNameValue;
    QPushButton *FormAddCategoryButtonAddParameterValue;
    QLabel *FormAddCategoryLabelGame;
    QPushButton *FormAddCategoryButtonCancel;
    QPushButton *FormAddCategoryButtonAddCategory;

    void setupUi(QWidget *FormNewCategory)
    {
        if (FormNewCategory->objectName().isEmpty())
            FormNewCategory->setObjectName(QString::fromUtf8("FormNewCategory"));
        FormNewCategory->resize(941, 605);
        gridLayout = new QGridLayout(FormNewCategory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormAddCategoryLabelParameterValue = new QLabel(FormNewCategory);
        FormAddCategoryLabelParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryLabelParameterValue"));

        gridLayout->addWidget(FormAddCategoryLabelParameterValue, 1, 0, 1, 1);

        FormAddCategoryLineEditNameCategory = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameCategory"));

        gridLayout->addWidget(FormAddCategoryLineEditNameCategory, 0, 1, 1, 2);

        FormAddCategoryTableWidgetAchievements = new QTableWidget(FormNewCategory);
        FormAddCategoryTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAddCategoryTableWidgetAchievements"));

        gridLayout->addWidget(FormAddCategoryTableWidgetAchievements, 3, 0, 1, 5);

        FormAddCategoryLabelNameCategory = new QLabel(FormNewCategory);
        FormAddCategoryLabelNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLabelNameCategory"));

        gridLayout->addWidget(FormAddCategoryLabelNameCategory, 0, 0, 1, 1);

        FormAddCategoryScrollAreaValuae = new QScrollArea(FormNewCategory);
        FormAddCategoryScrollAreaValuae->setObjectName(QString::fromUtf8("FormAddCategoryScrollAreaValuae"));
        FormAddCategoryScrollAreaValuae->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 610, 75));
        FormAddCategoryScrollAreaValuae->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(FormAddCategoryScrollAreaValuae, 0, 4, 3, 1);

        FormAddCategoryLineEditNameValue = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameValue->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameValue"));

        gridLayout->addWidget(FormAddCategoryLineEditNameValue, 1, 1, 1, 2);

        FormAddCategoryButtonAddParameterValue = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddParameterValue"));

        gridLayout->addWidget(FormAddCategoryButtonAddParameterValue, 1, 3, 1, 1);

        FormAddCategoryLabelGame = new QLabel(FormNewCategory);
        FormAddCategoryLabelGame->setObjectName(QString::fromUtf8("FormAddCategoryLabelGame"));

        gridLayout->addWidget(FormAddCategoryLabelGame, 0, 3, 1, 1);

        FormAddCategoryButtonCancel = new QPushButton(FormNewCategory);
        FormAddCategoryButtonCancel->setObjectName(QString::fromUtf8("FormAddCategoryButtonCancel"));

        gridLayout->addWidget(FormAddCategoryButtonCancel, 2, 3, 1, 1);

        FormAddCategoryButtonAddCategory = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddCategory->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddCategory"));

        gridLayout->addWidget(FormAddCategoryButtonAddCategory, 2, 0, 1, 3);


        retranslateUi(FormNewCategory);

        QMetaObject::connectSlotsByName(FormNewCategory);
    } // setupUi

    void retranslateUi(QWidget *FormNewCategory)
    {
        FormNewCategory->setWindowTitle(QApplication::translate("FormNewCategory", "Form", nullptr));
        FormAddCategoryLabelParameterValue->setText(QApplication::translate("FormNewCategory", "ParameterValue", nullptr));
        FormAddCategoryLineEditNameCategory->setPlaceholderText(QApplication::translate("FormNewCategory", "None", nullptr));
        FormAddCategoryLabelNameCategory->setText(QApplication::translate("FormNewCategory", "Name Category", nullptr));
        FormAddCategoryButtonAddParameterValue->setText(QApplication::translate("FormNewCategory", "Add parameter value", nullptr));
        FormAddCategoryLabelGame->setText(QApplication::translate("FormNewCategory", "Game", nullptr));
        FormAddCategoryButtonCancel->setText(QApplication::translate("FormNewCategory", "Cancel", nullptr));
        FormAddCategoryButtonAddCategory->setText(QApplication::translate("FormNewCategory", "Add category", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormNewCategory: public Ui_FormNewCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWCATEGORY_H
