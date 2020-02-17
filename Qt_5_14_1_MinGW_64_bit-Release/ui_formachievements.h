/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTS_H
#define UI_FORMACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *LabelGameLogo;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ButtonCompare;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelGameTitle;
    QSpacerItem *horizontalSpacer;
    QCheckBox *CheckBoxShowFilter;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelGameOnline;
    QLabel *LabelGameOnlineValue;
    QSpacerItem *horizontalSpacer_2;
    QLabel *LabelTotalPersent;
    QPushButton *ButtonUpdate;
    QGroupBox *GroupBoxFilter;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *ScrollAreaCategories;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *ScrollAreaCheckCategories;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *GroupBoxReachedFilter;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *CheckBoxFavorites;
    QCheckBox *CheckBoxCompareAllFriends;
    QPushButton *ButtonFavorite;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonChangeCategory;
    QPushButton *ButtonDeleteAllCategories;
    QGroupBox *GroupBoxCategories;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QComboBox *ComboBoxCategoriesCategory;
    QLineEdit *LineEditTitleCategory;
    QCheckBox *CheckBoxCategoryOneValue;
    QCheckBox *CheckBoxCategoryUniqueValue;
    QPushButton *ButtonAddValueCategory;
    QListWidget *ListWidgetValuesCategory;
    QVBoxLayout *verticalLayout_10;
    QPushButton *ButtonCancelCategory;
    QPushButton *ButtonDeleteCategory;
    QCheckBox *CheckBoxCategoryVisibleAll;
    QPushButton *ButtonAcceptCategory;
    QTableWidget *TableWidgetFriends;
    QProgressBar *ProgressBarFriendsLoad;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *TableWidgetHorizontalHeaderAchievements;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *TableWidgetAchievements;
    QTableWidget *TableWidgetCategory;
    QScrollBar *VerticalScrollBarTableAchievements;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(837, 1170);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormAchievements->setFont(font);
        verticalLayout_8 = new QVBoxLayout(FormAchievements);
        verticalLayout_8->setSpacing(3);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        groupBox = new QGroupBox(FormAchievements);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        LabelGameLogo = new QLabel(groupBox);
        LabelGameLogo->setObjectName(QString::fromUtf8("LabelGameLogo"));
        sizePolicy.setHeightForWidth(LabelGameLogo->sizePolicy().hasHeightForWidth());
        LabelGameLogo->setSizePolicy(sizePolicy);
        LabelGameLogo->setText(QString::fromUtf8("GameLogo"));

        gridLayout_5->addWidget(LabelGameLogo, 0, 0, 1, 1);


        horizontalLayout_11->addWidget(groupBox);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        ButtonCompare = new QPushButton(FormAchievements);
        ButtonCompare->setObjectName(QString::fromUtf8("ButtonCompare"));

        horizontalLayout_6->addWidget(ButtonCompare);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelGameTitle = new QLabel(FormAchievements);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelGameTitle->sizePolicy().hasHeightForWidth());
        LabelGameTitle->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Bright"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        LabelGameTitle->setFont(font1);
        LabelGameTitle->setText(QString::fromUtf8("GameTitle"));

        horizontalLayout_7->addWidget(LabelGameTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        CheckBoxShowFilter = new QCheckBox(FormAchievements);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        horizontalLayout_7->addWidget(CheckBoxShowFilter);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelGameOnline = new QLabel(FormAchievements);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        sizePolicy.setHeightForWidth(LabelGameOnline->sizePolicy().hasHeightForWidth());
        LabelGameOnline->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(10);
        LabelGameOnline->setFont(font2);

        horizontalLayout_2->addWidget(LabelGameOnline);

        LabelGameOnlineValue = new QLabel(FormAchievements);
        LabelGameOnlineValue->setObjectName(QString::fromUtf8("LabelGameOnlineValue"));
        LabelGameOnlineValue->setText(QString::fromUtf8("0"));

        horizontalLayout_2->addWidget(LabelGameOnlineValue);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        LabelTotalPersent = new QLabel(FormAchievements);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setText(QString::fromUtf8("TotalPersent"));
        LabelTotalPersent->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(LabelTotalPersent);

        ButtonUpdate = new QPushButton(FormAchievements);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        horizontalLayout_4->addWidget(ButtonUpdate);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_11->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_11);

        GroupBoxFilter = new QGroupBox(FormAchievements);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(GroupBoxFilter->sizePolicy().hasHeightForWidth());
        GroupBoxFilter->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(GroupBoxFilter);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ScrollAreaCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 109));
        ScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy3.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCheckCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 238, 109));
        ScrollAreaCheckCategories->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout->addWidget(ScrollAreaCheckCategories);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        GroupBoxReachedFilter = new QGroupBox(GroupBoxFilter);
        GroupBoxReachedFilter->setObjectName(QString::fromUtf8("GroupBoxReachedFilter"));

        verticalLayout_4->addWidget(GroupBoxReachedFilter);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        verticalLayout_3->addWidget(CheckBoxFavorites);

        CheckBoxCompareAllFriends = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareAllFriends->setObjectName(QString::fromUtf8("CheckBoxCompareAllFriends"));

        verticalLayout_3->addWidget(CheckBoxCompareAllFriends);

        ButtonFavorite = new QPushButton(GroupBoxFilter);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));

        verticalLayout_3->addWidget(ButtonFavorite);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ButtonAddCategory = new QPushButton(GroupBoxFilter);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));

        verticalLayout_5->addWidget(ButtonAddCategory);

        ButtonChangeCategory = new QPushButton(GroupBoxFilter);
        ButtonChangeCategory->setObjectName(QString::fromUtf8("ButtonChangeCategory"));

        verticalLayout_5->addWidget(ButtonChangeCategory);

        ButtonDeleteAllCategories = new QPushButton(GroupBoxFilter);
        ButtonDeleteAllCategories->setObjectName(QString::fromUtf8("ButtonDeleteAllCategories"));

        verticalLayout_5->addWidget(ButtonDeleteAllCategories);


        verticalLayout->addLayout(verticalLayout_5);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        GroupBoxCategories = new QGroupBox(GroupBoxFilter);
        GroupBoxCategories->setObjectName(QString::fromUtf8("GroupBoxCategories"));
        sizePolicy2.setHeightForWidth(GroupBoxCategories->sizePolicy().hasHeightForWidth());
        GroupBoxCategories->setSizePolicy(sizePolicy2);
        horizontalLayout_9 = new QHBoxLayout(GroupBoxCategories);
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        ComboBoxCategoriesCategory = new QComboBox(GroupBoxCategories);
        ComboBoxCategoriesCategory->addItem(QString());
        ComboBoxCategoriesCategory->setObjectName(QString::fromUtf8("ComboBoxCategoriesCategory"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ComboBoxCategoriesCategory->sizePolicy().hasHeightForWidth());
        ComboBoxCategoriesCategory->setSizePolicy(sizePolicy4);
        ComboBoxCategoriesCategory->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_11->addWidget(ComboBoxCategoriesCategory);

        LineEditTitleCategory = new QLineEdit(GroupBoxCategories);
        LineEditTitleCategory->setObjectName(QString::fromUtf8("LineEditTitleCategory"));
        sizePolicy4.setHeightForWidth(LineEditTitleCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategory->setSizePolicy(sizePolicy4);

        verticalLayout_11->addWidget(LineEditTitleCategory);

        CheckBoxCategoryOneValue = new QCheckBox(GroupBoxCategories);
        CheckBoxCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxCategoryOneValue"));
        sizePolicy4.setHeightForWidth(CheckBoxCategoryOneValue->sizePolicy().hasHeightForWidth());
        CheckBoxCategoryOneValue->setSizePolicy(sizePolicy4);

        verticalLayout_11->addWidget(CheckBoxCategoryOneValue);

        CheckBoxCategoryUniqueValue = new QCheckBox(GroupBoxCategories);
        CheckBoxCategoryUniqueValue->setObjectName(QString::fromUtf8("CheckBoxCategoryUniqueValue"));

        verticalLayout_11->addWidget(CheckBoxCategoryUniqueValue);

        ButtonAddValueCategory = new QPushButton(GroupBoxCategories);
        ButtonAddValueCategory->setObjectName(QString::fromUtf8("ButtonAddValueCategory"));

        verticalLayout_11->addWidget(ButtonAddValueCategory);


        horizontalLayout_9->addLayout(verticalLayout_11);

        ListWidgetValuesCategory = new QListWidget(GroupBoxCategories);
        ListWidgetValuesCategory->setObjectName(QString::fromUtf8("ListWidgetValuesCategory"));
        sizePolicy3.setHeightForWidth(ListWidgetValuesCategory->sizePolicy().hasHeightForWidth());
        ListWidgetValuesCategory->setSizePolicy(sizePolicy3);
        ListWidgetValuesCategory->setMaximumSize(QSize(16777215, 135));
        ListWidgetValuesCategory->setDragEnabled(true);
        ListWidgetValuesCategory->setDragDropMode(QAbstractItemView::InternalMove);
        ListWidgetValuesCategory->setDefaultDropAction(Qt::MoveAction);

        horizontalLayout_9->addWidget(ListWidgetValuesCategory);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        ButtonCancelCategory = new QPushButton(GroupBoxCategories);
        ButtonCancelCategory->setObjectName(QString::fromUtf8("ButtonCancelCategory"));

        verticalLayout_10->addWidget(ButtonCancelCategory);

        ButtonDeleteCategory = new QPushButton(GroupBoxCategories);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        verticalLayout_10->addWidget(ButtonDeleteCategory);

        CheckBoxCategoryVisibleAll = new QCheckBox(GroupBoxCategories);
        CheckBoxCategoryVisibleAll->setObjectName(QString::fromUtf8("CheckBoxCategoryVisibleAll"));
        CheckBoxCategoryVisibleAll->setChecked(true);

        verticalLayout_10->addWidget(CheckBoxCategoryVisibleAll);

        ButtonAcceptCategory = new QPushButton(GroupBoxCategories);
        ButtonAcceptCategory->setObjectName(QString::fromUtf8("ButtonAcceptCategory"));

        verticalLayout_10->addWidget(ButtonAcceptCategory);


        horizontalLayout_9->addLayout(verticalLayout_10);


        verticalLayout_2->addWidget(GroupBoxCategories);

        TableWidgetFriends = new QTableWidget(GroupBoxFilter);
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
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(TableWidgetFriends->sizePolicy().hasHeightForWidth());
        TableWidgetFriends->setSizePolicy(sizePolicy5);
        TableWidgetFriends->setSelectionBehavior(QAbstractItemView::SelectColumns);
        TableWidgetFriends->setRowCount(4);
        TableWidgetFriends->setColumnCount(2);
        TableWidgetFriends->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(TableWidgetFriends);

        ProgressBarFriendsLoad = new QProgressBar(GroupBoxFilter);
        ProgressBarFriendsLoad->setObjectName(QString::fromUtf8("ProgressBarFriendsLoad"));
        ProgressBarFriendsLoad->setValue(0);

        verticalLayout_2->addWidget(ProgressBarFriendsLoad);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LineEditNameAchievements = new QLineEdit(GroupBoxFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        horizontalLayout_3->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(GroupBoxFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);

        horizontalLayout_3->addWidget(ButtonFindAchievement);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_8->addWidget(GroupBoxFilter);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        CheckBoxCompareIcon = new QCheckBox(FormAchievements);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(FormAchievements);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(FormAchievements);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(FormAchievements);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTotalPercent);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_8);

        TableWidgetHorizontalHeaderAchievements = new QTableWidget(FormAchievements);
        TableWidgetHorizontalHeaderAchievements->setObjectName(QString::fromUtf8("TableWidgetHorizontalHeaderAchievements"));
        TableWidgetHorizontalHeaderAchievements->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetHorizontalHeaderAchievements->horizontalHeader()->setStretchLastSection(true);
        TableWidgetHorizontalHeaderAchievements->verticalHeader()->setVisible(false);
        TableWidgetHorizontalHeaderAchievements->verticalHeader()->setStretchLastSection(true);

        verticalLayout_7->addWidget(TableWidgetHorizontalHeaderAchievements);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        TableWidgetAchievements = new QTableWidget(FormAchievements);
        TableWidgetAchievements->setObjectName(QString::fromUtf8("TableWidgetAchievements"));
        TableWidgetAchievements->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableWidgetAchievements->setEditTriggers(QAbstractItemView::SelectedClicked);
        TableWidgetAchievements->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetAchievements->horizontalHeader()->setVisible(false);
        TableWidgetAchievements->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_5->addWidget(TableWidgetAchievements);

        TableWidgetCategory = new QTableWidget(FormAchievements);
        TableWidgetCategory->setObjectName(QString::fromUtf8("TableWidgetCategory"));
        TableWidgetCategory->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetCategory->setSortingEnabled(true);
        TableWidgetCategory->horizontalHeader()->setHighlightSections(false);
        TableWidgetCategory->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(TableWidgetCategory);


        verticalLayout_7->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_7);

        VerticalScrollBarTableAchievements = new QScrollBar(FormAchievements);
        VerticalScrollBarTableAchievements->setObjectName(QString::fromUtf8("VerticalScrollBarTableAchievements"));
        VerticalScrollBarTableAchievements->setOrientation(Qt::Vertical);

        horizontalLayout_10->addWidget(VerticalScrollBarTableAchievements);


        verticalLayout_8->addLayout(horizontalLayout_10);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QCoreApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        groupBox->setTitle(QString());
        ButtonCompare->setText(QCoreApplication::translate("FormAchievements", " \320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270", nullptr));
        CheckBoxShowFilter->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        LabelGameOnline->setText(QCoreApplication::translate("FormAchievements", "GameOnline:", nullptr));
        ButtonUpdate->setText(QCoreApplication::translate("FormAchievements", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(accessibility)
        GroupBoxFilter->setAccessibleName(QCoreApplication::translate("FormAchievements", "Filter", nullptr));
#endif // QT_CONFIG(accessibility)
        GroupBoxFilter->setTitle(QCoreApplication::translate("FormAchievements", "      \320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        GroupBoxReachedFilter->setTitle(QString());
        CheckBoxFavorites->setText(QCoreApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        CheckBoxCompareAllFriends->setText(QCoreApplication::translate("FormAchievements", "\320\222\321\201\320\265 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
        ButtonFavorite->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265 \320\262 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonAddCategory->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        ButtonChangeCategory->setText(QCoreApplication::translate("FormAchievements", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        ButtonDeleteAllCategories->setText(QCoreApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        GroupBoxCategories->setTitle(QCoreApplication::translate("FormAchievements", "Categories", nullptr));
        ComboBoxCategoriesCategory->setItemText(0, QCoreApplication::translate("FormAchievements", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));

        LineEditTitleCategory->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        CheckBoxCategoryOneValue->setText(QCoreApplication::translate("FormAchievements", "\320\221\320\265\320\267 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        CheckBoxCategoryUniqueValue->setText(QCoreApplication::translate("FormAchievements", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        ButtonAddValueCategory->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        ButtonCancelCategory->setText(QCoreApplication::translate("FormAchievements", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        ButtonDeleteCategory->setText(QCoreApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        CheckBoxCategoryVisibleAll->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\321\221", nullptr));
        ButtonAcceptCategory->setText(QCoreApplication::translate("FormAchievements", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));

        const bool __sortingEnabled = TableWidgetFriends->isSortingEnabled();
        TableWidgetFriends->setSortingEnabled(false);
        TableWidgetFriends->setSortingEnabled(__sortingEnabled);

        ProgressBarFriendsLoad->setFormat(QCoreApplication::translate("FormAchievements", "%v/%m", nullptr));
        LineEditNameAchievements->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        ButtonFindAchievement->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        CheckBoxCompareIcon->setText(QCoreApplication::translate("FormAchievements", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QCoreApplication::translate("FormAchievements", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
