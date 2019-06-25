/********************************************************************************
** Form generated from reading UI file 'formcompare.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMPARE_H
#define UI_FORMCOMPARE_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCompare
{
public:
    QGridLayout *gridLayout_4;
    QPushButton *FormCompareButtonUpdate;
    QPushButton *FormCompareButtonReturn;
    QSpacerItem *horizontalSpacer;
    QGroupBox *FormCompareGroupBoxFilter;
    QGridLayout *gridLayout_3;
    QPushButton *FormCompareButtonFind;
    QTableWidget *FormCompareTableWidgetFriends;
    QGroupBox *FormCompareGroupBoxFriendsA;
    QGridLayout *gridLayout_2;
    QRadioButton *FormCompareRadioButtonFriendsAll;
    QRadioButton *FormCompareRadioButtonFriendsReached;
    QRadioButton *FormCompareRadioButtonFriendsNotReached;
    QCheckBox *FormCompareCheckBoxAllFriends;
    QScrollArea *FormCompareScrollAreaCategoriesComboBox;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *FormCompareGroupBoxShowedColumns;
    QGridLayout *gridLayout_6;
    QCheckBox *FormCompareCheckBoxSCIcons;
    QCheckBox *FormCompareCheckBoxSCTitle;
    QCheckBox *FormCompareCheckBoxSCDescription;
    QCheckBox *FormCompareCheckBoxSCTotalPercent;
    QScrollArea *FormCompareScrollAreaCategoriesCheckBox;
    QWidget *scrollAreaWidgetContents_3;
    QLineEdit *FormCompareLineEditFind;
    QGroupBox *FormCompareGroupBoxMyA;
    QGridLayout *gridLayout;
    QRadioButton *FormCompareRadioButtonMyAll;
    QRadioButton *FormCompareRadioButtonMyReached;
    QRadioButton *FormCompareRadioButtonMyNotReached;
    QCheckBox *FormCompareCheckBoxFavorites;
    QTableWidget *FormCompareTableWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *FormCompareLabelLogo;
    QLabel *FormCompareLabelPlayerCount;

    void setupUi(QWidget *FormCompare)
    {
        if (FormCompare->objectName().isEmpty())
            FormCompare->setObjectName(QString::fromUtf8("FormCompare"));
        FormCompare->resize(1031, 733);
        gridLayout_4 = new QGridLayout(FormCompare);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        FormCompareButtonUpdate = new QPushButton(FormCompare);
        FormCompareButtonUpdate->setObjectName(QString::fromUtf8("FormCompareButtonUpdate"));

        gridLayout_4->addWidget(FormCompareButtonUpdate, 1, 4, 1, 1);

        FormCompareButtonReturn = new QPushButton(FormCompare);
        FormCompareButtonReturn->setObjectName(QString::fromUtf8("FormCompareButtonReturn"));

        gridLayout_4->addWidget(FormCompareButtonReturn, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        FormCompareGroupBoxFilter = new QGroupBox(FormCompare);
        FormCompareGroupBoxFilter->setObjectName(QString::fromUtf8("FormCompareGroupBoxFilter"));
        FormCompareGroupBoxFilter->setMaximumSize(QSize(16777215, 270));
        gridLayout_3 = new QGridLayout(FormCompareGroupBoxFilter);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FormCompareButtonFind = new QPushButton(FormCompareGroupBoxFilter);
        FormCompareButtonFind->setObjectName(QString::fromUtf8("FormCompareButtonFind"));

        gridLayout_3->addWidget(FormCompareButtonFind, 3, 4, 1, 1);

        FormCompareTableWidgetFriends = new QTableWidget(FormCompareGroupBoxFilter);
        FormCompareTableWidgetFriends->setObjectName(QString::fromUtf8("FormCompareTableWidgetFriends"));
        FormCompareTableWidgetFriends->setMaximumSize(QSize(16777215, 100));
        FormCompareTableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(FormCompareTableWidgetFriends, 2, 0, 1, 3);

        FormCompareGroupBoxFriendsA = new QGroupBox(FormCompareGroupBoxFilter);
        FormCompareGroupBoxFriendsA->setObjectName(QString::fromUtf8("FormCompareGroupBoxFriendsA"));
        gridLayout_2 = new QGridLayout(FormCompareGroupBoxFriendsA);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 1, -1, 1);
        FormCompareRadioButtonFriendsAll = new QRadioButton(FormCompareGroupBoxFriendsA);
        FormCompareRadioButtonFriendsAll->setObjectName(QString::fromUtf8("FormCompareRadioButtonFriendsAll"));

        gridLayout_2->addWidget(FormCompareRadioButtonFriendsAll, 0, 0, 1, 1);

        FormCompareRadioButtonFriendsReached = new QRadioButton(FormCompareGroupBoxFriendsA);
        FormCompareRadioButtonFriendsReached->setObjectName(QString::fromUtf8("FormCompareRadioButtonFriendsReached"));

        gridLayout_2->addWidget(FormCompareRadioButtonFriendsReached, 1, 0, 1, 1);

        FormCompareRadioButtonFriendsNotReached = new QRadioButton(FormCompareGroupBoxFriendsA);
        FormCompareRadioButtonFriendsNotReached->setObjectName(QString::fromUtf8("FormCompareRadioButtonFriendsNotReached"));

        gridLayout_2->addWidget(FormCompareRadioButtonFriendsNotReached, 2, 0, 1, 1);

        FormCompareCheckBoxAllFriends = new QCheckBox(FormCompareGroupBoxFriendsA);
        FormCompareCheckBoxAllFriends->setObjectName(QString::fromUtf8("FormCompareCheckBoxAllFriends"));

        gridLayout_2->addWidget(FormCompareCheckBoxAllFriends, 3, 0, 1, 1);


        gridLayout_3->addWidget(FormCompareGroupBoxFriendsA, 0, 3, 1, 2);

        FormCompareScrollAreaCategoriesComboBox = new QScrollArea(FormCompareGroupBoxFilter);
        FormCompareScrollAreaCategoriesComboBox->setObjectName(QString::fromUtf8("FormCompareScrollAreaCategoriesComboBox"));
        FormCompareScrollAreaCategoriesComboBox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 360, 96));
        FormCompareScrollAreaCategoriesComboBox->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(FormCompareScrollAreaCategoriesComboBox, 0, 0, 1, 1);

        FormCompareGroupBoxShowedColumns = new QGroupBox(FormCompareGroupBoxFilter);
        FormCompareGroupBoxShowedColumns->setObjectName(QString::fromUtf8("FormCompareGroupBoxShowedColumns"));
        gridLayout_6 = new QGridLayout(FormCompareGroupBoxShowedColumns);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 1, -1, 1);
        FormCompareCheckBoxSCIcons = new QCheckBox(FormCompareGroupBoxShowedColumns);
        FormCompareCheckBoxSCIcons->setObjectName(QString::fromUtf8("FormCompareCheckBoxSCIcons"));
        FormCompareCheckBoxSCIcons->setChecked(true);

        gridLayout_6->addWidget(FormCompareCheckBoxSCIcons, 0, 0, 1, 1);

        FormCompareCheckBoxSCTitle = new QCheckBox(FormCompareGroupBoxShowedColumns);
        FormCompareCheckBoxSCTitle->setObjectName(QString::fromUtf8("FormCompareCheckBoxSCTitle"));
        FormCompareCheckBoxSCTitle->setChecked(true);

        gridLayout_6->addWidget(FormCompareCheckBoxSCTitle, 1, 0, 1, 1);

        FormCompareCheckBoxSCDescription = new QCheckBox(FormCompareGroupBoxShowedColumns);
        FormCompareCheckBoxSCDescription->setObjectName(QString::fromUtf8("FormCompareCheckBoxSCDescription"));
        FormCompareCheckBoxSCDescription->setChecked(true);

        gridLayout_6->addWidget(FormCompareCheckBoxSCDescription, 2, 0, 1, 1);

        FormCompareCheckBoxSCTotalPercent = new QCheckBox(FormCompareGroupBoxShowedColumns);
        FormCompareCheckBoxSCTotalPercent->setObjectName(QString::fromUtf8("FormCompareCheckBoxSCTotalPercent"));
        FormCompareCheckBoxSCTotalPercent->setChecked(true);

        gridLayout_6->addWidget(FormCompareCheckBoxSCTotalPercent, 3, 0, 1, 1);


        gridLayout_3->addWidget(FormCompareGroupBoxShowedColumns, 2, 3, 1, 2);

        FormCompareScrollAreaCategoriesCheckBox = new QScrollArea(FormCompareGroupBoxFilter);
        FormCompareScrollAreaCategoriesCheckBox->setObjectName(QString::fromUtf8("FormCompareScrollAreaCategoriesCheckBox"));
        FormCompareScrollAreaCategoriesCheckBox->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 360, 96));
        FormCompareScrollAreaCategoriesCheckBox->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(FormCompareScrollAreaCategoriesCheckBox, 0, 1, 1, 1);

        FormCompareLineEditFind = new QLineEdit(FormCompareGroupBoxFilter);
        FormCompareLineEditFind->setObjectName(QString::fromUtf8("FormCompareLineEditFind"));

        gridLayout_3->addWidget(FormCompareLineEditFind, 3, 0, 1, 4);

        FormCompareGroupBoxMyA = new QGroupBox(FormCompareGroupBoxFilter);
        FormCompareGroupBoxMyA->setObjectName(QString::fromUtf8("FormCompareGroupBoxMyA"));
        gridLayout = new QGridLayout(FormCompareGroupBoxMyA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 1, -1, 1);
        FormCompareRadioButtonMyAll = new QRadioButton(FormCompareGroupBoxMyA);
        FormCompareRadioButtonMyAll->setObjectName(QString::fromUtf8("FormCompareRadioButtonMyAll"));

        gridLayout->addWidget(FormCompareRadioButtonMyAll, 0, 0, 1, 1);

        FormCompareRadioButtonMyReached = new QRadioButton(FormCompareGroupBoxMyA);
        FormCompareRadioButtonMyReached->setObjectName(QString::fromUtf8("FormCompareRadioButtonMyReached"));

        gridLayout->addWidget(FormCompareRadioButtonMyReached, 1, 0, 1, 1);

        FormCompareRadioButtonMyNotReached = new QRadioButton(FormCompareGroupBoxMyA);
        FormCompareRadioButtonMyNotReached->setObjectName(QString::fromUtf8("FormCompareRadioButtonMyNotReached"));

        gridLayout->addWidget(FormCompareRadioButtonMyNotReached, 2, 0, 1, 1);

        FormCompareCheckBoxFavorites = new QCheckBox(FormCompareGroupBoxMyA);
        FormCompareCheckBoxFavorites->setObjectName(QString::fromUtf8("FormCompareCheckBoxFavorites"));

        gridLayout->addWidget(FormCompareCheckBoxFavorites, 3, 0, 1, 1);


        gridLayout_3->addWidget(FormCompareGroupBoxMyA, 0, 2, 1, 1);


        gridLayout_4->addWidget(FormCompareGroupBoxFilter, 3, 0, 1, 5);

        FormCompareTableWidget = new QTableWidget(FormCompare);
        FormCompareTableWidget->setObjectName(QString::fromUtf8("FormCompareTableWidget"));

        gridLayout_4->addWidget(FormCompareTableWidget, 4, 0, 1, 5);

        groupBox = new QGroupBox(FormCompare);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        FormCompareLabelLogo = new QLabel(groupBox);
        FormCompareLabelLogo->setObjectName(QString::fromUtf8("FormCompareLabelLogo"));

        gridLayout_5->addWidget(FormCompareLabelLogo, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 3, 2);

        FormCompareLabelPlayerCount = new QLabel(FormCompare);
        FormCompareLabelPlayerCount->setObjectName(QString::fromUtf8("FormCompareLabelPlayerCount"));
        QFont font;
        font.setPointSize(14);
        FormCompareLabelPlayerCount->setFont(font);

        gridLayout_4->addWidget(FormCompareLabelPlayerCount, 2, 2, 1, 1);


        retranslateUi(FormCompare);

        QMetaObject::connectSlotsByName(FormCompare);
    } // setupUi

    void retranslateUi(QWidget *FormCompare)
    {
        FormCompare->setWindowTitle(QApplication::translate("FormCompare", "Form", nullptr));
        FormCompareButtonUpdate->setText(QApplication::translate("FormCompare", "Update", nullptr));
        FormCompareButtonReturn->setText(QApplication::translate("FormCompare", "Return", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        FormCompareGroupBoxFilter->setAccessibleName(QApplication::translate("FormCompare", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        FormCompareGroupBoxFilter->setTitle(QApplication::translate("FormCompare", "Filter", nullptr));
        FormCompareButtonFind->setText(QApplication::translate("FormCompare", "Find", nullptr));
        FormCompareGroupBoxFriendsA->setTitle(QApplication::translate("FormCompare", "Friends Achievements", nullptr));
        FormCompareRadioButtonFriendsAll->setText(QApplication::translate("FormCompare", "All", nullptr));
        FormCompareRadioButtonFriendsReached->setText(QApplication::translate("FormCompare", "Reached", nullptr));
        FormCompareRadioButtonFriendsNotReached->setText(QApplication::translate("FormCompare", "Not reached", nullptr));
        FormCompareCheckBoxAllFriends->setText(QApplication::translate("FormCompare", "All friends", nullptr));
        FormCompareGroupBoxShowedColumns->setTitle(QApplication::translate("FormCompare", "Showed columns", nullptr));
        FormCompareCheckBoxSCIcons->setText(QApplication::translate("FormCompare", "Icon", nullptr));
        FormCompareCheckBoxSCTitle->setText(QApplication::translate("FormCompare", "Title", nullptr));
        FormCompareCheckBoxSCDescription->setText(QApplication::translate("FormCompare", "Description", nullptr));
        FormCompareCheckBoxSCTotalPercent->setText(QApplication::translate("FormCompare", "Total percent", nullptr));
        FormCompareGroupBoxMyA->setTitle(QApplication::translate("FormCompare", "My Achievements", nullptr));
        FormCompareRadioButtonMyAll->setText(QApplication::translate("FormCompare", "All", nullptr));
        FormCompareRadioButtonMyReached->setText(QApplication::translate("FormCompare", "Reached", nullptr));
        FormCompareRadioButtonMyNotReached->setText(QApplication::translate("FormCompare", "Not reached", nullptr));
        FormCompareCheckBoxFavorites->setText(QApplication::translate("FormCompare", "Favorites", nullptr));
        groupBox->setTitle(QString());
        FormCompareLabelLogo->setText(QApplication::translate("FormCompare", "Logo", nullptr));
        FormCompareLabelPlayerCount->setText(QApplication::translate("FormCompare", "PlayerCount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompare: public Ui_FormCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPARE_H
