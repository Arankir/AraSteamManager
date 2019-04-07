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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNewCategory
{
public:
    QGridLayout *gridLayout;
    QTableWidget *FormAddCategoryTableWidgetAchievements;
    QLineEdit *FormAddCategoryLineEditNameValue;
    QLabel *FormAddCategoryLabelNameCategory;
    QLabel *FormAddCategoryLabelParameterValue;
    QLineEdit *FormAddCategoryLineEditNameCategory;
    QPushButton *FormAddCategoryButtonAddParameterValue;
    QPushButton *FormAddCategoryButtonAddCategory;
    QPushButton *FormAddCategoryButtonCancel;
    QLabel *FormAddCategoryLabelGame;

    void setupUi(QWidget *FormNewCategory)
    {
        if (FormNewCategory->objectName().isEmpty())
            FormNewCategory->setObjectName(QString::fromUtf8("FormNewCategory"));
        FormNewCategory->resize(941, 605);
        gridLayout = new QGridLayout(FormNewCategory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormAddCategoryTableWidgetAchievements = new QTableWidget(FormNewCategory);
        FormAddCategoryTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAddCategoryTableWidgetAchievements"));

        gridLayout->addWidget(FormAddCategoryTableWidgetAchievements, 3, 0, 1, 52);

        FormAddCategoryLineEditNameValue = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameValue->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameValue"));

        gridLayout->addWidget(FormAddCategoryLineEditNameValue, 2, 1, 1, 1);

        FormAddCategoryLabelNameCategory = new QLabel(FormNewCategory);
        FormAddCategoryLabelNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLabelNameCategory"));

        gridLayout->addWidget(FormAddCategoryLabelNameCategory, 1, 0, 1, 1);

        FormAddCategoryLabelParameterValue = new QLabel(FormNewCategory);
        FormAddCategoryLabelParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryLabelParameterValue"));

        gridLayout->addWidget(FormAddCategoryLabelParameterValue, 2, 0, 1, 1);

        FormAddCategoryLineEditNameCategory = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameCategory"));

        gridLayout->addWidget(FormAddCategoryLineEditNameCategory, 1, 1, 1, 1);

        FormAddCategoryButtonAddParameterValue = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddParameterValue"));

        gridLayout->addWidget(FormAddCategoryButtonAddParameterValue, 2, 2, 1, 1);

        FormAddCategoryButtonAddCategory = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddCategory->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddCategory"));

        gridLayout->addWidget(FormAddCategoryButtonAddCategory, 0, 51, 1, 1);

        FormAddCategoryButtonCancel = new QPushButton(FormNewCategory);
        FormAddCategoryButtonCancel->setObjectName(QString::fromUtf8("FormAddCategoryButtonCancel"));

        gridLayout->addWidget(FormAddCategoryButtonCancel, 0, 50, 1, 1);

        FormAddCategoryLabelGame = new QLabel(FormNewCategory);
        FormAddCategoryLabelGame->setObjectName(QString::fromUtf8("FormAddCategoryLabelGame"));

        gridLayout->addWidget(FormAddCategoryLabelGame, 0, 0, 1, 2);


        retranslateUi(FormNewCategory);

        QMetaObject::connectSlotsByName(FormNewCategory);
    } // setupUi

    void retranslateUi(QWidget *FormNewCategory)
    {
        FormNewCategory->setWindowTitle(QApplication::translate("FormNewCategory", "Form", nullptr));
        FormAddCategoryLabelNameCategory->setText(QApplication::translate("FormNewCategory", "NameCategory", nullptr));
        FormAddCategoryLabelParameterValue->setText(QApplication::translate("FormNewCategory", "ParameterValue", nullptr));
        FormAddCategoryLineEditNameCategory->setPlaceholderText(QApplication::translate("FormNewCategory", "None", nullptr));
        FormAddCategoryButtonAddParameterValue->setText(QApplication::translate("FormNewCategory", "Add parameter value", nullptr));
        FormAddCategoryButtonAddCategory->setText(QApplication::translate("FormNewCategory", "Add category", nullptr));
        FormAddCategoryButtonCancel->setText(QApplication::translate("FormNewCategory", "Cancel", nullptr));
        FormAddCategoryLabelGame->setText(QApplication::translate("FormNewCategory", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormNewCategory: public Ui_FormNewCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWCATEGORY_H
