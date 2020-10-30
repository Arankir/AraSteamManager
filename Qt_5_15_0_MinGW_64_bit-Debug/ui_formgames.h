/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "class\NotMine\MultiSelectComboBox.h"

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;
    QHBoxLayout *horizontalLayout_6;
    MultiSelectComboBox *ComboBoxGroups;
    QCheckBox *CheckBoxFavorites;
    QTableView *TableGames;
    QProgressBar *ProgressBarLoading;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(564, 493);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout_2 = new QVBoxLayout(FormGames);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(FormGames);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(groupBox);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LineEditGame->sizePolicy().hasHeightForWidth());
        LineEditGame->setSizePolicy(sizePolicy);
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(groupBox);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonFind->sizePolicy().hasHeightForWidth());
        ButtonFind->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(8);
        ButtonFind->setFont(font1);

        horizontalLayout->addWidget(ButtonFind);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ComboBoxGroups = new MultiSelectComboBox(groupBox);
        ComboBoxGroups->setObjectName(QString::fromUtf8("ComboBoxGroups"));

        horizontalLayout_6->addWidget(ComboBoxGroups);

        CheckBoxFavorites = new QCheckBox(groupBox);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CheckBoxFavorites->sizePolicy().hasHeightForWidth());
        CheckBoxFavorites->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(CheckBoxFavorites);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBox);

        TableGames = new QTableView(FormGames);
        TableGames->setObjectName(QString::fromUtf8("TableGames"));

        verticalLayout_2->addWidget(TableGames);

        ProgressBarLoading = new QProgressBar(FormGames);
        ProgressBarLoading->setObjectName(QString::fromUtf8("ProgressBarLoading"));
        ProgressBarLoading->setValue(0);
        ProgressBarLoading->setFormat(QString::fromUtf8("%v/%m"));

        verticalLayout_2->addWidget(ProgressBarLoading);


        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QCoreApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FormGames", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        LineEditGame->setPlaceholderText(QCoreApplication::translate("FormGames", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\203", nullptr));
        ButtonFind->setText(QCoreApplication::translate("FormGames", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        CheckBoxFavorites->setText(QCoreApplication::translate("FormGames", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
