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
    QGridLayout *gridLayout_2;
    QTableWidget *FormAchievementsTableWidgetAchievements;
    QPushButton *FormAchievementsButtonReturn;
    QGroupBox *FormAchievementsGroupBoxFilter;
    QGridLayout *gridLayout;
    QLineEdit *FormAchievementsLineEditNameAchievements;
    QPushButton *FormAchievementsButtonChangeCategory;
    QRadioButton *FormAchievementsRadioButtonNotReached;
    QPushButton *FormAchievementsButtonAddCategory;
    QRadioButton *FormAchievementsRadioButtonAll;
    QPushButton *FormAchievementsButtonFindAchievement;
    QScrollArea *FormAchievementsScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QCheckBox *FormAchievementsCheckBoxFavorites;
    QRadioButton *FormAchievementsRadioButtonReached;
    QLabel *FormAchievementsLabelTotalPersent;
    QPushButton *FormAchievementsButtonCompare;
    QLabel *FormAchievementsLabelGameOnline;
    QLabel *FormAchievementsLabelGameLogo;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(777, 772);
        gridLayout_2 = new QGridLayout(FormAchievements);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormAchievementsTableWidgetAchievements = new QTableWidget(FormAchievements);
        FormAchievementsTableWidgetAchievements->setObjectName(QString::fromUtf8("FormAchievementsTableWidgetAchievements"));

        gridLayout_2->addWidget(FormAchievementsTableWidgetAchievements, 6, 0, 1, 9);

        FormAchievementsButtonReturn = new QPushButton(FormAchievements);
        FormAchievementsButtonReturn->setObjectName(QString::fromUtf8("FormAchievementsButtonReturn"));

        gridLayout_2->addWidget(FormAchievementsButtonReturn, 0, 8, 1, 1);

        FormAchievementsGroupBoxFilter = new QGroupBox(FormAchievements);
        FormAchievementsGroupBoxFilter->setObjectName(QString::fromUtf8("FormAchievementsGroupBoxFilter"));
        gridLayout = new QGridLayout(FormAchievementsGroupBoxFilter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormAchievementsLineEditNameAchievements = new QLineEdit(FormAchievementsGroupBoxFilter);
        FormAchievementsLineEditNameAchievements->setObjectName(QString::fromUtf8("FormAchievementsLineEditNameAchievements"));

        gridLayout->addWidget(FormAchievementsLineEditNameAchievements, 0, 0, 1, 1);

        FormAchievementsButtonChangeCategory = new QPushButton(FormAchievementsGroupBoxFilter);
        FormAchievementsButtonChangeCategory->setObjectName(QString::fromUtf8("FormAchievementsButtonChangeCategory"));

        gridLayout->addWidget(FormAchievementsButtonChangeCategory, 4, 1, 1, 1);

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

        FormAchievementsCheckBoxFavorites = new QCheckBox(FormAchievementsGroupBoxFilter);
        FormAchievementsCheckBoxFavorites->setObjectName(QString::fromUtf8("FormAchievementsCheckBoxFavorites"));

        gridLayout->addWidget(FormAchievementsCheckBoxFavorites, 4, 2, 1, 1);

        FormAchievementsRadioButtonReached = new QRadioButton(FormAchievementsGroupBoxFilter);
        FormAchievementsRadioButtonReached->setObjectName(QString::fromUtf8("FormAchievementsRadioButtonReached"));

        gridLayout->addWidget(FormAchievementsRadioButtonReached, 1, 2, 1, 1);

        FormAchievementsLabelTotalPersent = new QLabel(FormAchievementsGroupBoxFilter);
        FormAchievementsLabelTotalPersent->setObjectName(QString::fromUtf8("FormAchievementsLabelTotalPersent"));

        gridLayout->addWidget(FormAchievementsLabelTotalPersent, 1, 1, 1, 1);


        gridLayout_2->addWidget(FormAchievementsGroupBoxFilter, 2, 0, 2, 9);

        FormAchievementsButtonCompare = new QPushButton(FormAchievements);
        FormAchievementsButtonCompare->setObjectName(QString::fromUtf8("FormAchievementsButtonCompare"));

        gridLayout_2->addWidget(FormAchievementsButtonCompare, 1, 8, 1, 1);

        FormAchievementsLabelGameOnline = new QLabel(FormAchievements);
        FormAchievementsLabelGameOnline->setObjectName(QString::fromUtf8("FormAchievementsLabelGameOnline"));
        QFont font;
        font.setPointSize(14);
        FormAchievementsLabelGameOnline->setFont(font);

        gridLayout_2->addWidget(FormAchievementsLabelGameOnline, 1, 1, 1, 1);

        FormAchievementsLabelGameLogo = new QLabel(FormAchievements);
        FormAchievementsLabelGameLogo->setObjectName(QString::fromUtf8("FormAchievementsLabelGameLogo"));

        gridLayout_2->addWidget(FormAchievementsLabelGameLogo, 0, 0, 2, 1);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "Form", nullptr));
        FormAchievementsButtonReturn->setText(QApplication::translate("FormAchievements", "Return", nullptr));
        FormAchievementsGroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "Filter", nullptr));
        FormAchievementsButtonChangeCategory->setText(QApplication::translate("FormAchievements", "Change category", nullptr));
        FormAchievementsRadioButtonNotReached->setText(QApplication::translate("FormAchievements", "Not reached", nullptr));
        FormAchievementsButtonAddCategory->setText(QApplication::translate("FormAchievements", "Add category", nullptr));
        FormAchievementsRadioButtonAll->setText(QApplication::translate("FormAchievements", "All", nullptr));
        FormAchievementsButtonFindAchievement->setText(QApplication::translate("FormAchievements", "Find", nullptr));
        FormAchievementsCheckBoxFavorites->setText(QApplication::translate("FormAchievements", "Only favorites", nullptr));
        FormAchievementsRadioButtonReached->setText(QApplication::translate("FormAchievements", "Reached", nullptr));
        FormAchievementsLabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        FormAchievementsButtonCompare->setText(QApplication::translate("FormAchievements", "Compare with friends", nullptr));
        FormAchievementsLabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
        FormAchievementsLabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
