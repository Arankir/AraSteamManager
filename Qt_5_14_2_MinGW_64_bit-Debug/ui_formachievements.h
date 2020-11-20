/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTS_H
#define UI_FORMACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AchievementsSubForms\formachievementscategoriesedit.h"
#include "class\NotMine\freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout_6;
    QFrame *FrameGameInfo;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *LabelGameLogo;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelGameTitle;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelGameOnline;
    QLabel *LabelGameOnlineValue;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelTotalPersent;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_9;
    QFrame *FrameFilter;
    QHBoxLayout *horizontalLayout_13;
    QScrollArea *ScrollAreaCategories;
    QWidget *widget;
    QFormLayout *layoutComboBoxCategories;
    QScrollArea *ScrollAreaCheckCategories;
    QWidget *widget_2;
    QFormLayout *layoutCheckBoxCategories;
    QSpacerItem *horizontalSpacer_11;
    QFrame *FrameReachedFilter;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *CheckBoxFavorites;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *ButtonUpdate;
    QPushButton *ButtonGuides;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QProgressBar *ProgressBarFriendsLoad;
    QTabWidget *tabWidget;
    QWidget *tabStandart;
    QVBoxLayout *verticalLayout_4;
    QTableView *TableViewMyAchievements;
    QWidget *tabEditCategory;
    QHBoxLayout *horizontalLayout;
    FormAchievementsCategoriesEdit *CategoriesEdit;
    QWidget *tabCompare;
    QVBoxLayout *verticalLayout_12;
    QTableWidget *TableWidgetFriends;
    QFrame *FrameHideColumns;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QCheckBox *CheckBoxCompareAllFriends;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_15;
    FreezeTableWidget *TableViewCompare;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListView *listView_2;
    QListView *listView;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(894, 768);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormAchievements->setFont(font);
        verticalLayout_6 = new QVBoxLayout(FormAchievements);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        FrameGameInfo = new QFrame(FormAchievements);
        FrameGameInfo->setObjectName(QString::fromUtf8("FrameGameInfo"));
        FrameGameInfo->setMaximumSize(QSize(16777215, 100));
        FrameGameInfo->setFrameShape(QFrame::StyledPanel);
        FrameGameInfo->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(FrameGameInfo);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        LabelGameLogo = new QLabel(FrameGameInfo);
        LabelGameLogo->setObjectName(QString::fromUtf8("LabelGameLogo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelGameLogo->sizePolicy().hasHeightForWidth());
        LabelGameLogo->setSizePolicy(sizePolicy);
        LabelGameLogo->setText(QString::fromUtf8("GameLogo"));

        verticalLayout_7->addWidget(LabelGameLogo);


        horizontalLayout_7->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LabelGameTitle = new QLabel(FrameGameInfo);
        LabelGameTitle->setObjectName(QString::fromUtf8("LabelGameTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelGameTitle->sizePolicy().hasHeightForWidth());
        LabelGameTitle->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        LabelGameTitle->setFont(font1);
        LabelGameTitle->setText(QString::fromUtf8("GameTitle"));

        horizontalLayout_4->addWidget(LabelGameTitle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelGameOnline = new QLabel(FrameGameInfo);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        sizePolicy.setHeightForWidth(LabelGameOnline->sizePolicy().hasHeightForWidth());
        LabelGameOnline->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(10);
        LabelGameOnline->setFont(font2);

        horizontalLayout_2->addWidget(LabelGameOnline);

        LabelGameOnlineValue = new QLabel(FrameGameInfo);
        LabelGameOnlineValue->setObjectName(QString::fromUtf8("LabelGameOnlineValue"));
        LabelGameOnlineValue->setText(QString::fromUtf8("0"));

        horizontalLayout_2->addWidget(LabelGameOnlineValue);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_8->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelTotalPersent = new QLabel(FrameGameInfo);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setText(QString::fromUtf8("TotalPersent"));
        LabelTotalPersent->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(LabelTotalPersent);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_8);


        verticalLayout_6->addWidget(FrameGameInfo);

        frame = new QFrame(FormAchievements);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        FrameFilter = new QFrame(frame);
        FrameFilter->setObjectName(QString::fromUtf8("FrameFilter"));
        FrameFilter->setMinimumSize(QSize(0, 0));
        FrameFilter->setFrameShape(QFrame::StyledPanel);
        FrameFilter->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(FrameFilter);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        ScrollAreaCategories = new QScrollArea(FrameFilter);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy2);
        ScrollAreaCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCategories->setWidgetResizable(true);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 203, 80));
        layoutComboBoxCategories = new QFormLayout(widget);
        layoutComboBoxCategories->setObjectName(QString::fromUtf8("layoutComboBoxCategories"));
        ScrollAreaCategories->setWidget(widget);

        horizontalLayout_13->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(FrameFilter);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy2.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy2);
        ScrollAreaCheckCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        widget_2 = new QWidget();
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 203, 80));
        layoutCheckBoxCategories = new QFormLayout(widget_2);
        layoutCheckBoxCategories->setObjectName(QString::fromUtf8("layoutCheckBoxCategories"));
        ScrollAreaCheckCategories->setWidget(widget_2);

        horizontalLayout_13->addWidget(ScrollAreaCheckCategories);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_11);

        FrameReachedFilter = new QFrame(FrameFilter);
        FrameReachedFilter->setObjectName(QString::fromUtf8("FrameReachedFilter"));

        horizontalLayout_13->addWidget(FrameReachedFilter);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        CheckBoxFavorites = new QCheckBox(FrameFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        horizontalLayout_12->addWidget(CheckBoxFavorites);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        ButtonUpdate = new QPushButton(FrameFilter);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ButtonUpdate->sizePolicy().hasHeightForWidth());
        ButtonUpdate->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(ButtonUpdate);

        ButtonGuides = new QPushButton(FrameFilter);
        ButtonGuides->setObjectName(QString::fromUtf8("ButtonGuides"));
        sizePolicy3.setHeightForWidth(ButtonGuides->sizePolicy().hasHeightForWidth());
        ButtonGuides->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(ButtonGuides);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LineEditNameAchievements = new QLineEdit(FrameFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        horizontalLayout_3->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(FrameFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ButtonFindAchievement->sizePolicy().hasHeightForWidth());
        ButtonFindAchievement->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(ButtonFindAchievement);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_13->addLayout(verticalLayout_3);


        verticalLayout_9->addWidget(FrameFilter);


        verticalLayout_6->addWidget(frame);

        ProgressBarFriendsLoad = new QProgressBar(FormAchievements);
        ProgressBarFriendsLoad->setObjectName(QString::fromUtf8("ProgressBarFriendsLoad"));
        ProgressBarFriendsLoad->setValue(0);

        verticalLayout_6->addWidget(ProgressBarFriendsLoad);

        tabWidget = new QTabWidget(FormAchievements);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabStandart = new QWidget();
        tabStandart->setObjectName(QString::fromUtf8("tabStandart"));
        verticalLayout_4 = new QVBoxLayout(tabStandart);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        TableViewMyAchievements = new QTableView(tabStandart);
        TableViewMyAchievements->setObjectName(QString::fromUtf8("TableViewMyAchievements"));

        verticalLayout_4->addWidget(TableViewMyAchievements);

        tabWidget->addTab(tabStandart, QString());
        tabEditCategory = new QWidget();
        tabEditCategory->setObjectName(QString::fromUtf8("tabEditCategory"));
        horizontalLayout = new QHBoxLayout(tabEditCategory);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CategoriesEdit = new FormAchievementsCategoriesEdit(tabEditCategory);
        CategoriesEdit->setObjectName(QString::fromUtf8("CategoriesEdit"));

        horizontalLayout->addWidget(CategoriesEdit);

        tabWidget->addTab(tabEditCategory, QString());
        tabCompare = new QWidget();
        tabCompare->setObjectName(QString::fromUtf8("tabCompare"));
        verticalLayout_12 = new QVBoxLayout(tabCompare);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        TableWidgetFriends = new QTableWidget(tabCompare);
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

        verticalLayout_12->addWidget(TableWidgetFriends);

        FrameHideColumns = new QFrame(tabCompare);
        FrameHideColumns->setObjectName(QString::fromUtf8("FrameHideColumns"));
        FrameHideColumns->setFrameShape(QFrame::StyledPanel);
        FrameHideColumns->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(FrameHideColumns);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        CheckBoxCompareIcon = new QCheckBox(FrameHideColumns);
        CheckBoxCompareIcon->setObjectName(QString::fromUtf8("CheckBoxCompareIcon"));
        CheckBoxCompareIcon->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareIcon);

        CheckBoxCompareTitle = new QCheckBox(FrameHideColumns);
        CheckBoxCompareTitle->setObjectName(QString::fromUtf8("CheckBoxCompareTitle"));
        CheckBoxCompareTitle->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTitle);

        CheckBoxCompareDescription = new QCheckBox(FrameHideColumns);
        CheckBoxCompareDescription->setObjectName(QString::fromUtf8("CheckBoxCompareDescription"));
        CheckBoxCompareDescription->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareDescription);

        CheckBoxCompareTotalPercent = new QCheckBox(FrameHideColumns);
        CheckBoxCompareTotalPercent->setObjectName(QString::fromUtf8("CheckBoxCompareTotalPercent"));
        CheckBoxCompareTotalPercent->setChecked(true);

        horizontalLayout_8->addWidget(CheckBoxCompareTotalPercent);

        CheckBoxCompareAllFriends = new QCheckBox(FrameHideColumns);
        CheckBoxCompareAllFriends->setObjectName(QString::fromUtf8("CheckBoxCompareAllFriends"));

        horizontalLayout_8->addWidget(CheckBoxCompareAllFriends);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_12->addWidget(FrameHideColumns);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        TableViewCompare = new FreezeTableWidget(tabCompare);
        TableViewCompare->setObjectName(QString::fromUtf8("TableViewCompare"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(TableViewCompare->sizePolicy().hasHeightForWidth());
        TableViewCompare->setSizePolicy(sizePolicy6);

        horizontalLayout_15->addWidget(TableViewCompare);

        frame_2 = new QFrame(tabCompare);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy7);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame_3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_14->addWidget(lineEdit);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_14->addWidget(pushButton);


        verticalLayout_5->addWidget(frame_3);

        listView_2 = new QListView(frame_2);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        verticalLayout_5->addWidget(listView_2);

        listView = new QListView(frame_2);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_5->addWidget(listView);


        horizontalLayout_15->addWidget(frame_2);


        verticalLayout_12->addLayout(horizontalLayout_15);

        tabWidget->addTab(tabCompare, QString());

        verticalLayout_6->addWidget(tabWidget);


        retranslateUi(FormAchievements);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QCoreApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        LabelGameOnline->setText(QCoreApplication::translate("FormAchievements", "GameOnline:  ", nullptr));
        CheckBoxFavorites->setText(QCoreApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
#if QT_CONFIG(tooltip)
        ButtonUpdate->setToolTip(QCoreApplication::translate("FormAchievements", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonUpdate->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonGuides->setToolTip(QCoreApplication::translate("FormAchievements", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonGuides->setText(QString());
        LineEditNameAchievements->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        ButtonFindAchievement->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        ProgressBarFriendsLoad->setFormat(QCoreApplication::translate("FormAchievements", "%v/%m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStandart), QCoreApplication::translate("FormAchievements", " \320\241\320\262\320\276\320\270 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEditCategory), QCoreApplication::translate("FormAchievements", "  \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217\320\274\320\270  ", nullptr));

        const bool __sortingEnabled = TableWidgetFriends->isSortingEnabled();
        TableWidgetFriends->setSortingEnabled(false);
        TableWidgetFriends->setSortingEnabled(__sortingEnabled);

        CheckBoxCompareIcon->setText(QCoreApplication::translate("FormAchievements", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        CheckBoxCompareTitle->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareDescription->setText(QCoreApplication::translate("FormAchievements", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CheckBoxCompareTotalPercent->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        CheckBoxCompareAllFriends->setText(QCoreApplication::translate("FormAchievements", "\320\222\321\201\320\265 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCompare), QCoreApplication::translate("FormAchievements", "  \320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
