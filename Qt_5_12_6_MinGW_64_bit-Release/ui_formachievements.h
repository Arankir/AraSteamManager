/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
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
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelGameOnline;
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
    QTableWidget *TableWidgetCompareFriends;
    QProgressBar *ProgressBarFriendsLoad;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *TableWidgetAchievements;
    QTableWidget *TableWidgetCompareAchievements;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(837, 885);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormAchievements->setFont(font);
        verticalLayout_7 = new QVBoxLayout(FormAchievements);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
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

        gridLayout_5->addWidget(LabelGameLogo, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox);

        verticalLayout_6 = new QVBoxLayout();
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

        horizontalLayout_7->addWidget(LabelGameTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        CheckBoxShowFilter = new QCheckBox(FormAchievements);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        horizontalLayout_7->addWidget(CheckBoxShowFilter);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        LabelTotalPersent = new QLabel(FormAchievements);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(LabelTotalPersent);

        ButtonUpdate = new QPushButton(FormAchievements);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        horizontalLayout_2->addWidget(ButtonUpdate);


        verticalLayout_6->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_4);

        GroupBoxFilter = new QGroupBox(FormAchievements);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(GroupBoxFilter->sizePolicy().hasHeightForWidth());
        GroupBoxFilter->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(GroupBoxFilter);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ScrollAreaCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCategories->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 262, 89));
        ScrollAreaCategories->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(GroupBoxFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy3.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 261, 89));
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


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
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
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
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

        TableWidgetCompareFriends = new QTableWidget(GroupBoxFilter);
        if (TableWidgetCompareFriends->columnCount() < 2)
            TableWidgetCompareFriends->setColumnCount(2);
        if (TableWidgetCompareFriends->rowCount() < 4)
            TableWidgetCompareFriends->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableWidgetCompareFriends->setItem(0, 1, __qtablewidgetitem);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::CrossPattern);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setForeground(brush);
        TableWidgetCompareFriends->setItem(1, 1, __qtablewidgetitem1);
        TableWidgetCompareFriends->setObjectName(QString::fromUtf8("TableWidgetCompareFriends"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(TableWidgetCompareFriends->sizePolicy().hasHeightForWidth());
        TableWidgetCompareFriends->setSizePolicy(sizePolicy5);
        TableWidgetCompareFriends->setSelectionBehavior(QAbstractItemView::SelectColumns);
        TableWidgetCompareFriends->setRowCount(4);
        TableWidgetCompareFriends->setColumnCount(2);
        TableWidgetCompareFriends->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(TableWidgetCompareFriends);

        ProgressBarFriendsLoad = new QProgressBar(GroupBoxFilter);
        ProgressBarFriendsLoad->setObjectName(QString::fromUtf8("ProgressBarFriendsLoad"));
        ProgressBarFriendsLoad->setValue(0);

        verticalLayout_2->addWidget(ProgressBarFriendsLoad);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        CheckBoxCompareIcon = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(GroupBoxFilter);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTotalPercent);


        verticalLayout_2->addLayout(horizontalLayout_8);

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


        verticalLayout_7->addWidget(GroupBoxFilter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        TableWidgetAchievements = new QTableWidget(FormAchievements);
        TableWidgetAchievements->setObjectName(QString::fromUtf8("TableWidgetAchievements"));
        TableWidgetAchievements->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetAchievements->setSortingEnabled(true);
        TableWidgetAchievements->horizontalHeader()->setHighlightSections(false);

        horizontalLayout_5->addWidget(TableWidgetAchievements);

        TableWidgetCompareAchievements = new QTableWidget(FormAchievements);
        TableWidgetCompareAchievements->setObjectName(QString::fromUtf8("TableWidgetCompareAchievements"));
        TableWidgetCompareAchievements->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_5->addWidget(TableWidgetCompareAchievements);


        verticalLayout_7->addLayout(horizontalLayout_5);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        groupBox->setTitle(QString());
        LabelGameLogo->setText(QApplication::translate("FormAchievements", "GameLogo", nullptr));
        ButtonCompare->setText(QApplication::translate("FormAchievements", " \320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270", nullptr));
        LabelGameTitle->setText(QApplication::translate("FormAchievements", "GameTitle", nullptr));
        CheckBoxShowFilter->setText(QApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        LabelGameOnline->setText(QApplication::translate("FormAchievements", "GameOnline", nullptr));
        LabelTotalPersent->setText(QApplication::translate("FormAchievements", "TotalPersent", nullptr));
        ButtonUpdate->setText(QApplication::translate("FormAchievements", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        GroupBoxFilter->setAccessibleName(QApplication::translate("FormAchievements", "Filter", nullptr));
#endif // QT_NO_ACCESSIBILITY
        GroupBoxFilter->setTitle(QApplication::translate("FormAchievements", "      \320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        GroupBoxReachedFilter->setTitle(QString());
        CheckBoxFavorites->setText(QApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        CheckBoxCompareAllFriends->setText(QApplication::translate("FormAchievements", "\320\222\321\201\320\265 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
        ButtonAddCategory->setText(QApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        ButtonChangeCategory->setText(QApplication::translate("FormAchievements", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        ButtonDeleteAllCategories->setText(QApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        GroupBoxCategories->setTitle(QApplication::translate("FormAchievements", "Categories", nullptr));
        ComboBoxCategoriesCategory->setItemText(0, QApplication::translate("FormAchievements", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));

        LineEditTitleCategory->setPlaceholderText(QApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        CheckBoxCategoryOneValue->setText(QApplication::translate("FormAchievements", "\320\221\320\265\320\267 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        CheckBoxCategoryUniqueValue->setText(QApplication::translate("FormAchievements", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        ButtonAddValueCategory->setText(QApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        ButtonCancelCategory->setText(QApplication::translate("FormAchievements", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        ButtonDeleteCategory->setText(QApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        CheckBoxCategoryVisibleAll->setText(QApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\321\221", nullptr));
        ButtonAcceptCategory->setText(QApplication::translate("FormAchievements", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));

        const bool __sortingEnabled = TableWidgetCompareFriends->isSortingEnabled();
        TableWidgetCompareFriends->setSortingEnabled(false);
        TableWidgetCompareFriends->setSortingEnabled(__sortingEnabled);

        ProgressBarFriendsLoad->setFormat(QApplication::translate("FormAchievements", "%v/%m", nullptr));
        CheckBoxCompareIcon->setText(QApplication::translate("FormAchievements", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QApplication::translate("FormAchievements", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QApplication::translate("FormAchievements", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        LineEditNameAchievements->setPlaceholderText(QApplication::translate("FormAchievements", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        ButtonFindAchievement->setText(QApplication::translate("FormAchievements", "\320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
