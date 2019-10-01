/********************************************************************************
** Form generated from reading UI file 'formcompare.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
    QPushButton *ButtonUpdate;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelLogo;
    QGroupBox *GroupBoxFilter;
    QGridLayout *gridLayout_3;
    QPushButton *ButtonFind;
    QCheckBox *CheckBoxFavorites;
    QLineEdit *LineEditFind;
    QCheckBox *CheckBoxAllFriends;
    QGroupBox *GroupBoxShowedColumns;
    QGridLayout *gridLayout_6;
    QCheckBox *CheckBoxSCIcons;
    QCheckBox *CheckBoxSCTitle;
    QCheckBox *CheckBoxSCDescription;
    QCheckBox *CheckBoxSCTotalPercent;
    QScrollArea *ScrollAreaCategoriesCheckBox;
    QWidget *scrollAreaWidgetContents_3;
    QScrollArea *ScrollAreaCategoriesComboBox;
    QWidget *scrollAreaWidgetContents_2;
    QTableWidget *TableWidgetFriends;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelPlayerCount;
    QCheckBox *CheckBoxShowFilter;
    QPushButton *ButtonReturn;
    QTableWidget *TableWidget;

    void setupUi(QWidget *FormCompare)
    {
        if (FormCompare->objectName().isEmpty())
            FormCompare->setObjectName(QString::fromUtf8("FormCompare"));
        FormCompare->resize(1031, 818);
        gridLayout_4 = new QGridLayout(FormCompare);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        ButtonUpdate = new QPushButton(FormCompare);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        gridLayout_4->addWidget(ButtonUpdate, 1, 4, 1, 1);

        groupBox = new QGroupBox(FormCompare);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        LabelLogo = new QLabel(groupBox);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout_5->addWidget(LabelLogo, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 3, 2);

        GroupBoxFilter = new QGroupBox(FormCompare);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        GroupBoxFilter->setMaximumSize(QSize(16777215, 380));
        gridLayout_3 = new QGridLayout(GroupBoxFilter);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ButtonFind = new QPushButton(GroupBoxFilter);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));

        gridLayout_3->addWidget(ButtonFind, 4, 5, 1, 1);

        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        gridLayout_3->addWidget(CheckBoxFavorites, 0, 5, 1, 1);

        LineEditFind = new QLineEdit(GroupBoxFilter);
        LineEditFind->setObjectName(QString::fromUtf8("LineEditFind"));

        gridLayout_3->addWidget(LineEditFind, 4, 0, 1, 5);

        CheckBoxAllFriends = new QCheckBox(GroupBoxFilter);
        CheckBoxAllFriends->setObjectName(QString::fromUtf8("CheckBoxAllFriends"));

        gridLayout_3->addWidget(CheckBoxAllFriends, 1, 5, 1, 1);

        GroupBoxShowedColumns = new QGroupBox(GroupBoxFilter);
        GroupBoxShowedColumns->setObjectName(QString::fromUtf8("GroupBoxShowedColumns"));
        gridLayout_6 = new QGridLayout(GroupBoxShowedColumns);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 1, -1, 1);
        CheckBoxSCIcons = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCIcons->setObjectName(QString::fromUtf8("CheckBoxSCIcons"));
        CheckBoxSCIcons->setChecked(true);

        gridLayout_6->addWidget(CheckBoxSCIcons, 0, 0, 1, 1);

        CheckBoxSCTitle = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCTitle->setObjectName(QString::fromUtf8("CheckBoxSCTitle"));
        CheckBoxSCTitle->setChecked(true);

        gridLayout_6->addWidget(CheckBoxSCTitle, 1, 0, 1, 1);

        CheckBoxSCDescription = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCDescription->setObjectName(QString::fromUtf8("CheckBoxSCDescription"));
        CheckBoxSCDescription->setChecked(true);

        gridLayout_6->addWidget(CheckBoxSCDescription, 2, 0, 1, 1);

        CheckBoxSCTotalPercent = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCTotalPercent->setObjectName(QString::fromUtf8("CheckBoxSCTotalPercent"));
        CheckBoxSCTotalPercent->setChecked(true);

        gridLayout_6->addWidget(CheckBoxSCTotalPercent, 3, 0, 1, 1);


        gridLayout_3->addWidget(GroupBoxShowedColumns, 0, 2, 3, 3);

        ScrollAreaCategoriesCheckBox = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategoriesCheckBox->setObjectName(QString::fromUtf8("ScrollAreaCategoriesCheckBox"));
        ScrollAreaCategoriesCheckBox->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 387, 117));
        ScrollAreaCategoriesCheckBox->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(ScrollAreaCategoriesCheckBox, 0, 1, 3, 1);

        ScrollAreaCategoriesComboBox = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategoriesComboBox->setObjectName(QString::fromUtf8("ScrollAreaCategoriesComboBox"));
        ScrollAreaCategoriesComboBox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 387, 117));
        ScrollAreaCategoriesComboBox->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(ScrollAreaCategoriesComboBox, 0, 0, 3, 1);

        TableWidgetFriends = new QTableWidget(GroupBoxFilter);
        TableWidgetFriends->setObjectName(QString::fromUtf8("TableWidgetFriends"));
        TableWidgetFriends->setMinimumSize(QSize(0, 180));
        TableWidgetFriends->setMaximumSize(QSize(16777215, 330));
        TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TableWidgetFriends->setShowGrid(true);

        gridLayout_3->addWidget(TableWidgetFriends, 3, 0, 1, 6);


        gridLayout_4->addWidget(GroupBoxFilter, 3, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        LabelPlayerCount = new QLabel(FormCompare);
        LabelPlayerCount->setObjectName(QString::fromUtf8("LabelPlayerCount"));
        QFont font;
        font.setPointSize(14);
        LabelPlayerCount->setFont(font);

        gridLayout_4->addWidget(LabelPlayerCount, 2, 2, 1, 1);

        CheckBoxShowFilter = new QCheckBox(FormCompare);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        gridLayout_4->addWidget(CheckBoxShowFilter, 2, 4, 1, 1);

        ButtonReturn = new QPushButton(FormCompare);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));

        gridLayout_4->addWidget(ButtonReturn, 0, 4, 1, 1);

        TableWidget = new QTableWidget(FormCompare);
        TableWidget->setObjectName(QString::fromUtf8("TableWidget"));
        TableWidget->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(TableWidget, 4, 0, 2, 5);


        retranslateUi(FormCompare);

        QMetaObject::connectSlotsByName(FormCompare);
    } // setupUi

    void retranslateUi(QWidget *FormCompare)
    {
        FormCompare->setWindowTitle(QApplication::translate("FormCompare", "Form", nullptr));
        ButtonUpdate->setText(QApplication::translate("FormCompare", "Update", nullptr));
        groupBox->setTitle(QString());
        LabelLogo->setText(QApplication::translate("FormCompare", "Logo", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        GroupBoxFilter->setAccessibleName(QApplication::translate("FormCompare", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        GroupBoxFilter->setTitle(QApplication::translate("FormCompare", "Filter", nullptr));
        ButtonFind->setText(QApplication::translate("FormCompare", "Find", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormCompare", "Favorites", nullptr));
        CheckBoxAllFriends->setText(QApplication::translate("FormCompare", "All friends", nullptr));
        GroupBoxShowedColumns->setTitle(QApplication::translate("FormCompare", "Showed columns", nullptr));
        CheckBoxSCIcons->setText(QApplication::translate("FormCompare", "Icon", nullptr));
        CheckBoxSCTitle->setText(QApplication::translate("FormCompare", "Title", nullptr));
        CheckBoxSCDescription->setText(QApplication::translate("FormCompare", "Description", nullptr));
        CheckBoxSCTotalPercent->setText(QApplication::translate("FormCompare", "Total percent", nullptr));
        LabelPlayerCount->setText(QApplication::translate("FormCompare", "PlayerCount", nullptr));
        CheckBoxShowFilter->setText(QApplication::translate("FormCompare", "Show Filter", nullptr));
        ButtonReturn->setText(QApplication::translate("FormCompare", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompare: public Ui_FormCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPARE_H
