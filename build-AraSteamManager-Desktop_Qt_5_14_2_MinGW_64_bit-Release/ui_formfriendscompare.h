/********************************************************************************
** Form generated from reading UI file 'formfriendscompare.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDSCOMPARE_H
#define UI_FORMFRIENDSCOMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/comboBoxes/qcomboboxfriends.h"
#include "subWidgets/tables/freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormFriendsCompare
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
    ComboBoxFriends *ComboBoxFriend;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonFriendsReached;
    QPushButton *ButtonFriendsAll;
    QPushButton *ButtonFriendsNotReached;
    QSpacerItem *horizontalSpacer;
    QListWidget *ListWidgetFriends;

    void setupUi(QWidget *FormFriendsCompare)
    {
        if (FormFriendsCompare->objectName().isEmpty())
            FormFriendsCompare->setObjectName(QString::fromUtf8("FormFriendsCompare"));
        FormFriendsCompare->resize(1131, 539);
        horizontalLayout_3 = new QHBoxLayout(FormFriendsCompare);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CheckBoxCompareIcon = new QCheckBox(FormFriendsCompare);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(FormFriendsCompare);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(FormFriendsCompare);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(FormFriendsCompare);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        horizontalLayout->addWidget(CheckBoxCompareTotalPercent);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        TableViewCompare = new FreezeTableWidget(FormFriendsCompare);
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
        lineEdit = new QLineEdit(FormFriendsCompare);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(FormFriendsCompare);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ComboBoxFriend = new ComboBoxFriends(FormFriendsCompare);
        ComboBoxFriend->setObjectName(QString::fromUtf8("ComboBoxFriend"));
        sizePolicy1.setHeightForWidth(ComboBoxFriend->sizePolicy().hasHeightForWidth());
        ComboBoxFriend->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(ComboBoxFriend);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        ButtonFriendsReached = new QPushButton(FormFriendsCompare);
        ButtonFriendsReached->setObjectName(QString::fromUtf8("ButtonFriendsReached"));
        sizePolicy2.setHeightForWidth(ButtonFriendsReached->sizePolicy().hasHeightForWidth());
        ButtonFriendsReached->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(ButtonFriendsReached);

        ButtonFriendsAll = new QPushButton(FormFriendsCompare);
        ButtonFriendsAll->setObjectName(QString::fromUtf8("ButtonFriendsAll"));
        sizePolicy2.setHeightForWidth(ButtonFriendsAll->sizePolicy().hasHeightForWidth());
        ButtonFriendsAll->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(ButtonFriendsAll);

        ButtonFriendsNotReached = new QPushButton(FormFriendsCompare);
        ButtonFriendsNotReached->setObjectName(QString::fromUtf8("ButtonFriendsNotReached"));
        sizePolicy2.setHeightForWidth(ButtonFriendsNotReached->sizePolicy().hasHeightForWidth());
        ButtonFriendsNotReached->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(ButtonFriendsNotReached);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        ListWidgetFriends = new QListWidget(FormFriendsCompare);
        ListWidgetFriends->setObjectName(QString::fromUtf8("ListWidgetFriends"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ListWidgetFriends->sizePolicy().hasHeightForWidth());
        ListWidgetFriends->setSizePolicy(sizePolicy3);
        ListWidgetFriends->setResizeMode(QListView::Adjust);

        verticalLayout_2->addWidget(ListWidgetFriends);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(FormFriendsCompare);

        QMetaObject::connectSlotsByName(FormFriendsCompare);
    } // setupUi

    void retranslateUi(QWidget *FormFriendsCompare)
    {
        FormFriendsCompare->setWindowTitle(QCoreApplication::translate("FormFriendsCompare", "Form", nullptr));
        CheckBoxCompareIcon->setText(QCoreApplication::translate("FormFriendsCompare", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QCoreApplication::translate("FormFriendsCompare", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QCoreApplication::translate("FormFriendsCompare", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QCoreApplication::translate("FormFriendsCompare", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("FormFriendsCompare", "https://steamcommunity.com/id/gabelogannewell", nullptr));
        pushButton->setText(QCoreApplication::translate("FormFriendsCompare", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        ButtonFriendsReached->setText(QString());
        ButtonFriendsAll->setText(QString());
        ButtonFriendsNotReached->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormFriendsCompare: public Ui_FormFriendsCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDSCOMPARE_H
