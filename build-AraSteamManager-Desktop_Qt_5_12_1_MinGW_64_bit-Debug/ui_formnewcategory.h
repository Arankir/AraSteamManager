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
    QGridLayout *gridLayout_2;
    QLineEdit *FormAddCategoryLineEditNameValue;
    QLabel *FormAddCategoryLabelNameCategory;
    QLineEdit *FormAddCategoryLineEditNameCategory;
    QPushButton *FormAddCategoryButtonCancel;
    QPushButton *FormAddCategoryButtonAddParameterValue;
    QLabel *FormAddCategoryLabelGame;
    QTableWidget *FormAddCategoryTableWidgetAchievements;
    QPushButton *FormAddCategoryButtonAddCategory;
    QLabel *FormAddCategoryLabelParameterValue;
    QLineEdit *FormAddCategoryLineEditFind;
    QPushButton *FormAddCategoryButtonFind;

    void setupUi(QWidget *FormNewCategory)
    {
        if (FormNewCategory->objectName().isEmpty())
            FormNewCategory->setObjectName(QString::fromUtf8("FormNewCategory"));
        FormNewCategory->resize(941, 730);
        gridLayout_2 = new QGridLayout(FormNewCategory);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormAddCategoryLineEditNameValue = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameValue->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameValue"));

        gridLayout_2->addWidget(FormAddCategoryLineEditNameValue, 1, 3, 1, 1);

        FormAddCategoryLabelNameCategory = new QLabel(FormNewCategory);
        FormAddCategoryLabelNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLabelNameCategory"));

        gridLayout_2->addWidget(FormAddCategoryLabelNameCategory, 1, 0, 1, 1);

        FormAddCategoryLineEditNameCategory = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditNameCategory->setObjectName(QString::fromUtf8("FormAddCategoryLineEditNameCategory"));

        gridLayout_2->addWidget(FormAddCategoryLineEditNameCategory, 1, 1, 1, 1);

        FormAddCategoryButtonCancel = new QPushButton(FormNewCategory);
        FormAddCategoryButtonCancel->setObjectName(QString::fromUtf8("FormAddCategoryButtonCancel"));

        gridLayout_2->addWidget(FormAddCategoryButtonCancel, 0, 5, 1, 1);

        FormAddCategoryButtonAddParameterValue = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddParameterValue"));

        gridLayout_2->addWidget(FormAddCategoryButtonAddParameterValue, 1, 4, 1, 1);

        FormAddCategoryLabelGame = new QLabel(FormNewCategory);
        FormAddCategoryLabelGame->setObjectName(QString::fromUtf8("FormAddCategoryLabelGame"));

        gridLayout_2->addWidget(FormAddCategoryLabelGame, 0, 0, 1, 1);

        FormAddCategoryTableWidgetAchievements = new QTableWidget(FormNewCategory);
        FormAddCategoryTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAddCategoryTableWidgetAchievements"));

        gridLayout_2->addWidget(FormAddCategoryTableWidgetAchievements, 3, 0, 1, 7);

        FormAddCategoryButtonAddCategory = new QPushButton(FormNewCategory);
        FormAddCategoryButtonAddCategory->setObjectName(QString::fromUtf8("FormAddCategoryButtonAddCategory"));

        gridLayout_2->addWidget(FormAddCategoryButtonAddCategory, 1, 5, 1, 1);

        FormAddCategoryLabelParameterValue = new QLabel(FormNewCategory);
        FormAddCategoryLabelParameterValue->setObjectName(QString::fromUtf8("FormAddCategoryLabelParameterValue"));

        gridLayout_2->addWidget(FormAddCategoryLabelParameterValue, 1, 2, 1, 1);

        FormAddCategoryLineEditFind = new QLineEdit(FormNewCategory);
        FormAddCategoryLineEditFind->setObjectName(QString::fromUtf8("FormAddCategoryLineEditFind"));

        gridLayout_2->addWidget(FormAddCategoryLineEditFind, 2, 0, 1, 2);

        FormAddCategoryButtonFind = new QPushButton(FormNewCategory);
        FormAddCategoryButtonFind->setObjectName(QString::fromUtf8("FormAddCategoryButtonFind"));

        gridLayout_2->addWidget(FormAddCategoryButtonFind, 2, 2, 1, 1);


        retranslateUi(FormNewCategory);

        QMetaObject::connectSlotsByName(FormNewCategory);
    } // setupUi

    void retranslateUi(QWidget *FormNewCategory)
    {
        FormNewCategory->setWindowTitle(QApplication::translate("FormNewCategory", "Form", nullptr));
        FormAddCategoryLabelNameCategory->setText(QApplication::translate("FormNewCategory", "NameCategory", nullptr));
        FormAddCategoryLineEditNameCategory->setPlaceholderText(QApplication::translate("FormNewCategory", "None", nullptr));
        FormAddCategoryButtonCancel->setText(QApplication::translate("FormNewCategory", "Cancel", nullptr));
        FormAddCategoryButtonAddParameterValue->setText(QApplication::translate("FormNewCategory", "Add parameter value", nullptr));
        FormAddCategoryLabelGame->setText(QApplication::translate("FormNewCategory", "Game", nullptr));
        FormAddCategoryButtonAddCategory->setText(QApplication::translate("FormNewCategory", "Add category", nullptr));
        FormAddCategoryLabelParameterValue->setText(QApplication::translate("FormNewCategory", "ParameterValue", nullptr));
        FormAddCategoryButtonFind->setText(QApplication::translate("FormNewCategory", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormNewCategory: public Ui_FormNewCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWCATEGORY_H
