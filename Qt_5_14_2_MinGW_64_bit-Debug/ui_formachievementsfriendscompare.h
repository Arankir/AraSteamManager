/********************************************************************************
** Form generated from reading UI file 'formachievementsfriendscompare.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTSFRIENDSCOMPARE_H
#define UI_FORMACHIEVEMENTSFRIENDSCOMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "class\NotMine\freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievementsFriendsCompare
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QSpacerItem *horizontalSpacer_4;
    FreezeTableWidget *TableViewCompare;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListView *listView_2;
    QListView *listView;

    void setupUi(QWidget *FormAchievementsFriendsCompare)
    {
        if (FormAchievementsFriendsCompare->objectName().isEmpty())
            FormAchievementsFriendsCompare->setObjectName(QString::fromUtf8("FormAchievementsFriendsCompare"));
        FormAchievementsFriendsCompare->resize(1131, 539);
        horizontalLayout_3 = new QHBoxLayout(FormAchievementsFriendsCompare);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CheckBoxCompareIcon = new QCheckBox(FormAchievementsFriendsCompare);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(FormAchievementsFriendsCompare);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(FormAchievementsFriendsCompare);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(FormAchievementsFriendsCompare);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareTotalPercent);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        TableViewCompare = new FreezeTableWidget(FormAchievementsFriendsCompare);
        TableViewCompare->setObjectName(QString::fromUtf8("TableViewCompare"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableViewCompare->sizePolicy().hasHeightForWidth());
        TableViewCompare->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(TableViewCompare);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(FormAchievementsFriendsCompare);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(FormAchievementsFriendsCompare);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listView_2 = new QListView(FormAchievementsFriendsCompare);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listView_2->sizePolicy().hasHeightForWidth());
        listView_2->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(listView_2);

        listView = new QListView(FormAchievementsFriendsCompare);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy3.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(listView);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(FormAchievementsFriendsCompare);

        QMetaObject::connectSlotsByName(FormAchievementsFriendsCompare);
    } // setupUi

    void retranslateUi(QWidget *FormAchievementsFriendsCompare)
    {
        FormAchievementsFriendsCompare->setWindowTitle(QCoreApplication::translate("FormAchievementsFriendsCompare", "Form", nullptr));
        CheckBoxCompareIcon->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievementsFriendsCompare: public Ui_FormAchievementsFriendsCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTSFRIENDSCOMPARE_H
