/********************************************************************************
** Form generated from reading UI file 'formcompare.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
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
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *FormCompareLabelLogo;
    QGroupBox *FormCompareGroupBoxFilter;
    QGridLayout *gridLayout_3;
    QPushButton *FormCompareButtonFind;
    QCheckBox *FormCompareCheckBoxFavorites;
    QLineEdit *FormCompareLineEditFind;
    QCheckBox *FormCompareCheckBoxAllFriends;
    QGroupBox *FormCompareGroupBoxShowedColumns;
    QGridLayout *gridLayout_6;
    QCheckBox *FormCompareCheckBoxSCIcons;
    QCheckBox *FormCompareCheckBoxSCTitle;
    QCheckBox *FormCompareCheckBoxSCDescription;
    QCheckBox *FormCompareCheckBoxSCTotalPercent;
    QScrollArea *FormCompareScrollAreaCategoriesCheckBox;
    QWidget *scrollAreaWidgetContents_3;
    QScrollArea *FormCompareScrollAreaCategoriesComboBox;
    QWidget *scrollAreaWidgetContents_2;
    QTableWidget *FormCompareTableWidgetFriends;
    QSpacerItem *horizontalSpacer;
    QLabel *FormCompareLabelPlayerCount;
    QCheckBox *FormComparCheckBoxShowFilter;
    QPushButton *FormCompareButtonReturn;
    QTableWidget *FormCompareTableWidget;

    void setupUi(QWidget *FormCompare)
    {
        if (FormCompare->objectName().isEmpty())
            FormCompare->setObjectName(QString::fromUtf8("FormCompare"));
        FormCompare->resize(1031, 818);
        gridLayout_4 = new QGridLayout(FormCompare);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        FormCompareButtonUpdate = new QPushButton(FormCompare);
        FormCompareButtonUpdate->setObjectName(QString::fromUtf8("FormCompareButtonUpdate"));

        gridLayout_4->addWidget(FormCompareButtonUpdate, 1, 4, 1, 1);

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

        FormCompareGroupBoxFilter = new QGroupBox(FormCompare);
        FormCompareGroupBoxFilter->setObjectName(QString::fromUtf8("FormCompareGroupBoxFilter"));
        FormCompareGroupBoxFilter->setMaximumSize(QSize(16777215, 380));
        gridLayout_3 = new QGridLayout(FormCompareGroupBoxFilter);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FormCompareButtonFind = new QPushButton(FormCompareGroupBoxFilter);
        FormCompareButtonFind->setObjectName(QString::fromUtf8("FormCompareButtonFind"));

        gridLayout_3->addWidget(FormCompareButtonFind, 4, 5, 1, 1);

        FormCompareCheckBoxFavorites = new QCheckBox(FormCompareGroupBoxFilter);
        FormCompareCheckBoxFavorites->setObjectName(QString::fromUtf8("FormCompareCheckBoxFavorites"));

        gridLayout_3->addWidget(FormCompareCheckBoxFavorites, 0, 5, 1, 1);

        FormCompareLineEditFind = new QLineEdit(FormCompareGroupBoxFilter);
        FormCompareLineEditFind->setObjectName(QString::fromUtf8("FormCompareLineEditFind"));

        gridLayout_3->addWidget(FormCompareLineEditFind, 4, 0, 1, 5);

        FormCompareCheckBoxAllFriends = new QCheckBox(FormCompareGroupBoxFilter);
        FormCompareCheckBoxAllFriends->setObjectName(QString::fromUtf8("FormCompareCheckBoxAllFriends"));

        gridLayout_3->addWidget(FormCompareCheckBoxAllFriends, 1, 5, 1, 1);

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


        gridLayout_3->addWidget(FormCompareGroupBoxShowedColumns, 0, 2, 3, 3);

        FormCompareScrollAreaCategoriesCheckBox = new QScrollArea(FormCompareGroupBoxFilter);
        FormCompareScrollAreaCategoriesCheckBox->setObjectName(QString::fromUtf8("FormCompareScrollAreaCategoriesCheckBox"));
        FormCompareScrollAreaCategoriesCheckBox->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 387, 117));
        FormCompareScrollAreaCategoriesCheckBox->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(FormCompareScrollAreaCategoriesCheckBox, 0, 1, 3, 1);

        FormCompareScrollAreaCategoriesComboBox = new QScrollArea(FormCompareGroupBoxFilter);
        FormCompareScrollAreaCategoriesComboBox->setObjectName(QString::fromUtf8("FormCompareScrollAreaCategoriesComboBox"));
        FormCompareScrollAreaCategoriesComboBox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 387, 117));
        FormCompareScrollAreaCategoriesComboBox->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(FormCompareScrollAreaCategoriesComboBox, 0, 0, 3, 1);

        FormCompareTableWidgetFriends = new QTableWidget(FormCompareGroupBoxFilter);
        FormCompareTableWidgetFriends->setObjectName(QString::fromUtf8("FormCompareTableWidgetFriends"));
        FormCompareTableWidgetFriends->setMinimumSize(QSize(0, 180));
        FormCompareTableWidgetFriends->setMaximumSize(QSize(16777215, 330));
        FormCompareTableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FormCompareTableWidgetFriends->setShowGrid(true);

        gridLayout_3->addWidget(FormCompareTableWidgetFriends, 3, 0, 1, 6);


        gridLayout_4->addWidget(FormCompareGroupBoxFilter, 3, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        FormCompareLabelPlayerCount = new QLabel(FormCompare);
        FormCompareLabelPlayerCount->setObjectName(QString::fromUtf8("FormCompareLabelPlayerCount"));
        QFont font;
        font.setPointSize(14);
        FormCompareLabelPlayerCount->setFont(font);

        gridLayout_4->addWidget(FormCompareLabelPlayerCount, 2, 2, 1, 1);

        FormComparCheckBoxShowFilter = new QCheckBox(FormCompare);
        FormComparCheckBoxShowFilter->setObjectName(QString::fromUtf8("FormComparCheckBoxShowFilter"));
        FormComparCheckBoxShowFilter->setChecked(true);

        gridLayout_4->addWidget(FormComparCheckBoxShowFilter, 2, 4, 1, 1);

        FormCompareButtonReturn = new QPushButton(FormCompare);
        FormCompareButtonReturn->setObjectName(QString::fromUtf8("FormCompareButtonReturn"));

        gridLayout_4->addWidget(FormCompareButtonReturn, 0, 4, 1, 1);

        FormCompareTableWidget = new QTableWidget(FormCompare);
        FormCompareTableWidget->setObjectName(QString::fromUtf8("FormCompareTableWidget"));
        FormCompareTableWidget->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(FormCompareTableWidget, 4, 0, 2, 5);


        retranslateUi(FormCompare);

        QMetaObject::connectSlotsByName(FormCompare);
    } // setupUi

    void retranslateUi(QWidget *FormCompare)
    {
        FormCompare->setWindowTitle(QCoreApplication::translate("FormCompare", "Form", nullptr));
        FormCompareButtonUpdate->setText(QCoreApplication::translate("FormCompare", "Update", nullptr));
        groupBox->setTitle(QString());
        FormCompareLabelLogo->setText(QCoreApplication::translate("FormCompare", "Logo", nullptr));
#if QT_CONFIG(accessibility)
        FormCompareGroupBoxFilter->setAccessibleName(QCoreApplication::translate("FormCompare", "Filter", nullptr));
#endif // QT_CONFIG(accessibility)
        FormCompareGroupBoxFilter->setTitle(QCoreApplication::translate("FormCompare", "Filter", nullptr));
        FormCompareButtonFind->setText(QCoreApplication::translate("FormCompare", "Find", nullptr));
        FormCompareCheckBoxFavorites->setText(QCoreApplication::translate("FormCompare", "Favorites", nullptr));
        FormCompareCheckBoxAllFriends->setText(QCoreApplication::translate("FormCompare", "All friends", nullptr));
        FormCompareGroupBoxShowedColumns->setTitle(QCoreApplication::translate("FormCompare", "Showed columns", nullptr));
        FormCompareCheckBoxSCIcons->setText(QCoreApplication::translate("FormCompare", "Icon", nullptr));
        FormCompareCheckBoxSCTitle->setText(QCoreApplication::translate("FormCompare", "Title", nullptr));
        FormCompareCheckBoxSCDescription->setText(QCoreApplication::translate("FormCompare", "Description", nullptr));
        FormCompareCheckBoxSCTotalPercent->setText(QCoreApplication::translate("FormCompare", "Total percent", nullptr));
        FormCompareLabelPlayerCount->setText(QCoreApplication::translate("FormCompare", "PlayerCount", nullptr));
        FormComparCheckBoxShowFilter->setText(QCoreApplication::translate("FormCompare", "Show Filter", nullptr));
        FormCompareButtonReturn->setText(QCoreApplication::translate("FormCompare", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompare: public Ui_FormCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPARE_H
