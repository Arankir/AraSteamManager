/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMES_H
#define UI_FORMGAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/comboBoxes/multiselectcombobox.h"
#include "subWidgets/lineEdit/mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxFilter;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    MyLineEdit *lineEditGame;
    QPushButton *buttonFind;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    MultiSelectComboBox *comboBoxGroups;
    QCheckBox *checkBoxFavorites;
    QTableView *tableGames;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(325, 348);
        verticalLayout_2 = new QVBoxLayout(FormGames);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBoxFilter = new QGroupBox(FormGames);
        groupBoxFilter->setObjectName(QString::fromUtf8("groupBoxFilter"));
        verticalLayout_5 = new QVBoxLayout(groupBoxFilter);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditGame = new MyLineEdit(groupBoxFilter);
        lineEditGame->setObjectName(QString::fromUtf8("lineEditGame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditGame->sizePolicy().hasHeightForWidth());
        lineEditGame->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEditGame);

        buttonFind = new QPushButton(groupBoxFilter);
        buttonFind->setObjectName(QString::fromUtf8("buttonFind"));
        buttonFind->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonFind->sizePolicy().hasHeightForWidth());
        buttonFind->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(buttonFind);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBoxFilter);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label);

        comboBoxGroups = new MultiSelectComboBox(groupBoxFilter);
        comboBoxGroups->setObjectName(QString::fromUtf8("comboBoxGroups"));

        horizontalLayout_6->addWidget(comboBoxGroups);

        checkBoxFavorites = new QCheckBox(groupBoxFilter);
        checkBoxFavorites->setObjectName(QString::fromUtf8("checkBoxFavorites"));
        sizePolicy1.setHeightForWidth(checkBoxFavorites->sizePolicy().hasHeightForWidth());
        checkBoxFavorites->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(checkBoxFavorites);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBoxFilter);

        tableGames = new QTableView(FormGames);
        tableGames->setObjectName(QString::fromUtf8("tableGames"));

        verticalLayout_2->addWidget(tableGames);


        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QCoreApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        groupBoxFilter->setTitle(QCoreApplication::translate("FormGames", "     \320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        lineEditGame->setPlaceholderText(QCoreApplication::translate("FormGames", "Dota 2", nullptr));
        buttonFind->setText(QCoreApplication::translate("FormGames", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label->setText(QCoreApplication::translate("FormGames", "\320\223\321\200\321\203\320\277\320\277\321\213:", nullptr));
        checkBoxFavorites->setText(QCoreApplication::translate("FormGames", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
