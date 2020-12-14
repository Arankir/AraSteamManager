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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "classes\notMine\freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievementsFriendsCompare
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *TableWidgetFriends;
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
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;
    QCheckBox *CheckBoxCompareAllFriends;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QListView *listView_2;
    QListView *listView;

    void setupUi(QWidget *FormAchievementsFriendsCompare)
    {
        if (FormAchievementsFriendsCompare->objectName().isEmpty())
            FormAchievementsFriendsCompare->setObjectName(QString::fromUtf8("FormAchievementsFriendsCompare"));
        FormAchievementsFriendsCompare->resize(1131, 539);
        horizontalLayout_5 = new QHBoxLayout(FormAchievementsFriendsCompare);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        TableWidgetFriends = new QTableWidget(FormAchievementsFriendsCompare);
        if (TableWidgetFriends->columnCount() < 2)
            TableWidgetFriends->setColumnCount(2);
        if (TableWidgetFriends->rowCount() < 4)
            TableWidgetFriends->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableWidgetFriends->setItem(0, 1, __qtablewidgetitem);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::CrossPattern);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setForeground(brush);
        TableWidgetFriends->setItem(1, 1, __qtablewidgetitem1);
        TableWidgetFriends->setObjectName(QString::fromUtf8("TableWidgetFriends"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableWidgetFriends->sizePolicy().hasHeightForWidth());
        TableWidgetFriends->setSizePolicy(sizePolicy);
        TableWidgetFriends->setSelectionBehavior(QAbstractItemView::SelectColumns);
        TableWidgetFriends->setRowCount(4);
        TableWidgetFriends->setColumnCount(2);
        TableWidgetFriends->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(TableWidgetFriends);

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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TableViewCompare->sizePolicy().hasHeightForWidth());
        TableViewCompare->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(TableViewCompare);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(FormAchievementsFriendsCompare);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(FormAchievementsFriendsCompare);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_3 = new QPushButton(FormAchievementsFriendsCompare);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(FormAchievementsFriendsCompare);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(FormAchievementsFriendsCompare);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_4->addWidget(pushButton_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        CheckBoxCompareAllFriends = new QCheckBox(FormAchievementsFriendsCompare);
        CheckBoxCompareAllFriends->setObjectName(QString::fromUtf8("CheckBoxCompareAllFriends"));

        horizontalLayout_4->addWidget(CheckBoxCompareAllFriends);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_2 = new QLineEdit(FormAchievementsFriendsCompare);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lineEdit_2);

        pushButton_2 = new QPushButton(FormAchievementsFriendsCompare);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        listView_2 = new QListView(FormAchievementsFriendsCompare);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listView_2->sizePolicy().hasHeightForWidth());
        listView_2->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(listView_2);

        listView = new QListView(FormAchievementsFriendsCompare);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy4.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(listView);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(FormAchievementsFriendsCompare);

        QMetaObject::connectSlotsByName(FormAchievementsFriendsCompare);
    } // setupUi

    void retranslateUi(QWidget *FormAchievementsFriendsCompare)
    {
        FormAchievementsFriendsCompare->setWindowTitle(QCoreApplication::translate("FormAchievementsFriendsCompare", "Form", nullptr));

        const bool __sortingEnabled = TableWidgetFriends->isSortingEnabled();
        TableWidgetFriends->setSortingEnabled(false);
        TableWidgetFriends->setSortingEnabled(__sortingEnabled);

        CheckBoxCompareIcon->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        CheckBoxCompareAllFriends->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\222\321\201\320\265 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormAchievementsFriendsCompare", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievementsFriendsCompare: public Ui_FormAchievementsFriendsCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTSFRIENDSCOMPARE_H
