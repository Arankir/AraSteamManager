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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCompare
{
public:
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonUpdate;
    QPushButton *ButtonReturn;
    QCheckBox *CheckBoxShowFilter;
    QLabel *LabelPlayerCount;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelLogo;
    QGroupBox *GroupBoxFilter;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QScrollArea *ScrollAreaCategoriesComboBox;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *ScrollAreaCategoriesCheckBox;
    QWidget *scrollAreaWidgetContents_3;
    QGroupBox *GroupBoxShowedColumns;
    QVBoxLayout *verticalLayout;
    QCheckBox *CheckBoxSCIcons;
    QCheckBox *CheckBoxSCTitle;
    QCheckBox *CheckBoxSCDescription;
    QCheckBox *CheckBoxSCTotalPercent;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *CheckBoxFavorites;
    QCheckBox *CheckBoxAllFriends;
    QTableWidget *TableWidgetFriends;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LineEditFind;
    QPushButton *ButtonFind;
    QTableWidget *TableWidget;

    void setupUi(QWidget *FormCompare)
    {
        if (FormCompare->objectName().isEmpty())
            FormCompare->setObjectName(QString::fromUtf8("FormCompare"));
        FormCompare->resize(1031, 818);
        verticalLayout_4 = new QVBoxLayout(FormCompare);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(881, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        ButtonUpdate = new QPushButton(FormCompare);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        gridLayout->addWidget(ButtonUpdate, 1, 3, 1, 1);

        ButtonReturn = new QPushButton(FormCompare);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));

        gridLayout->addWidget(ButtonReturn, 0, 3, 1, 1);

        CheckBoxShowFilter = new QCheckBox(FormCompare);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        gridLayout->addWidget(CheckBoxShowFilter, 2, 3, 1, 1);

        LabelPlayerCount = new QLabel(FormCompare);
        LabelPlayerCount->setObjectName(QString::fromUtf8("LabelPlayerCount"));
        QFont font;
        font.setPointSize(14);
        LabelPlayerCount->setFont(font);

        gridLayout->addWidget(LabelPlayerCount, 2, 1, 1, 1);

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


        gridLayout->addWidget(groupBox, 0, 0, 3, 1);


        verticalLayout_4->addLayout(gridLayout);

        GroupBoxFilter = new QGroupBox(FormCompare);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        GroupBoxFilter->setMaximumSize(QSize(16777215, 380));
        verticalLayout_3 = new QVBoxLayout(GroupBoxFilter);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ScrollAreaCategoriesComboBox = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategoriesComboBox->setObjectName(QString::fromUtf8("ScrollAreaCategoriesComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrollAreaCategoriesComboBox->sizePolicy().hasHeightForWidth());
        ScrollAreaCategoriesComboBox->setSizePolicy(sizePolicy);
        ScrollAreaCategoriesComboBox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 389, 117));
        ScrollAreaCategoriesComboBox->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(ScrollAreaCategoriesComboBox);

        ScrollAreaCategoriesCheckBox = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategoriesCheckBox->setObjectName(QString::fromUtf8("ScrollAreaCategoriesCheckBox"));
        sizePolicy.setHeightForWidth(ScrollAreaCategoriesCheckBox->sizePolicy().hasHeightForWidth());
        ScrollAreaCategoriesCheckBox->setSizePolicy(sizePolicy);
        ScrollAreaCategoriesCheckBox->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 389, 117));
        ScrollAreaCategoriesCheckBox->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(ScrollAreaCategoriesCheckBox);

        GroupBoxShowedColumns = new QGroupBox(GroupBoxFilter);
        GroupBoxShowedColumns->setObjectName(QString::fromUtf8("GroupBoxShowedColumns"));
        verticalLayout = new QVBoxLayout(GroupBoxShowedColumns);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 1, -1, 1);
        CheckBoxSCIcons = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCIcons->setObjectName(QString::fromUtf8("CheckBoxSCIcons"));
        CheckBoxSCIcons->setChecked(true);

        verticalLayout->addWidget(CheckBoxSCIcons);

        CheckBoxSCTitle = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCTitle->setObjectName(QString::fromUtf8("CheckBoxSCTitle"));
        CheckBoxSCTitle->setChecked(true);

        verticalLayout->addWidget(CheckBoxSCTitle);

        CheckBoxSCDescription = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCDescription->setObjectName(QString::fromUtf8("CheckBoxSCDescription"));
        CheckBoxSCDescription->setChecked(true);

        verticalLayout->addWidget(CheckBoxSCDescription);

        CheckBoxSCTotalPercent = new QCheckBox(GroupBoxShowedColumns);
        CheckBoxSCTotalPercent->setObjectName(QString::fromUtf8("CheckBoxSCTotalPercent"));
        CheckBoxSCTotalPercent->setChecked(true);

        verticalLayout->addWidget(CheckBoxSCTotalPercent);


        horizontalLayout->addWidget(GroupBoxShowedColumns);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        verticalLayout_2->addWidget(CheckBoxFavorites);

        CheckBoxAllFriends = new QCheckBox(GroupBoxFilter);
        CheckBoxAllFriends->setObjectName(QString::fromUtf8("CheckBoxAllFriends"));

        verticalLayout_2->addWidget(CheckBoxAllFriends);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        TableWidgetFriends = new QTableWidget(GroupBoxFilter);
        TableWidgetFriends->setObjectName(QString::fromUtf8("TableWidgetFriends"));
        sizePolicy.setHeightForWidth(TableWidgetFriends->sizePolicy().hasHeightForWidth());
        TableWidgetFriends->setSizePolicy(sizePolicy);
        TableWidgetFriends->setMinimumSize(QSize(0, 180));
        TableWidgetFriends->setMaximumSize(QSize(16777215, 330));
        TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TableWidgetFriends->setShowGrid(true);

        verticalLayout_3->addWidget(TableWidgetFriends);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LineEditFind = new QLineEdit(GroupBoxFilter);
        LineEditFind->setObjectName(QString::fromUtf8("LineEditFind"));

        horizontalLayout_2->addWidget(LineEditFind);

        ButtonFind = new QPushButton(GroupBoxFilter);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));

        horizontalLayout_2->addWidget(ButtonFind);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(GroupBoxFilter);

        TableWidget = new QTableWidget(FormCompare);
        TableWidget->setObjectName(QString::fromUtf8("TableWidget"));
        TableWidget->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(TableWidget);


        retranslateUi(FormCompare);

        QMetaObject::connectSlotsByName(FormCompare);
    } // setupUi

    void retranslateUi(QWidget *FormCompare)
    {
        FormCompare->setWindowTitle(QApplication::translate("FormCompare", "Form", nullptr));
        ButtonUpdate->setText(QApplication::translate("FormCompare", "Update", nullptr));
        ButtonReturn->setText(QApplication::translate("FormCompare", "Return", nullptr));
        CheckBoxShowFilter->setText(QApplication::translate("FormCompare", "Show Filter", nullptr));
        LabelPlayerCount->setText(QApplication::translate("FormCompare", "PlayerCount", nullptr));
        groupBox->setTitle(QString());
        LabelLogo->setText(QApplication::translate("FormCompare", "Logo", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        GroupBoxFilter->setAccessibleName(QApplication::translate("FormCompare", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        GroupBoxFilter->setTitle(QApplication::translate("FormCompare", "Filter", nullptr));
        GroupBoxShowedColumns->setTitle(QApplication::translate("FormCompare", "Showed columns", nullptr));
        CheckBoxSCIcons->setText(QApplication::translate("FormCompare", "Icon", nullptr));
        CheckBoxSCTitle->setText(QApplication::translate("FormCompare", "Title", nullptr));
        CheckBoxSCDescription->setText(QApplication::translate("FormCompare", "Description", nullptr));
        CheckBoxSCTotalPercent->setText(QApplication::translate("FormCompare", "Total percent", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormCompare", "Favorites", nullptr));
        CheckBoxAllFriends->setText(QApplication::translate("FormCompare", "All friends", nullptr));
        ButtonFind->setText(QApplication::translate("FormCompare", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCompare: public Ui_FormCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMPARE_H
