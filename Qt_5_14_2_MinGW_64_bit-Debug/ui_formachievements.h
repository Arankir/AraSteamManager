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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
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
    QVBoxLayout *verticalLayout_4;
    QFrame *FrameGameInfo;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *LabelGameLogo;
    QCheckBox *CheckBoxShowFilter;
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
    QPushButton *ButtonUpdate;
    QSpacerItem *horizontalSpacer_2;
    QFrame *FrameFilter;
    QHBoxLayout *horizontalLayout_13;
    QFrame *FrameReachedFilter;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *CheckBoxFavorites;
    QPushButton *ButtonFavorite;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *ButtonCompare;
    QCheckBox *CheckBoxCompareAllFriends;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QProgressBar *ProgressBarFriendsLoad;
    QFrame *FrameContainer;
    QFrame *FrameEditCategory;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *ComboBoxCategories;
    QLineEdit *LineEditTitleCategory;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *ButtonAcceptCategory;
    QPushButton *ButtonDeleteCategory;
    QPushButton *ButtonCancelCategory;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *CheckBoxCategoryOneValue;
    QCheckBox *CheckBoxCategoryUniqueValue;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *ButtonAddValueCategory;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *CheckBoxCategoryVisibleAll;
    QListWidget *ListWidgetValuesCategory;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ButtonCategoryValueReverse;
    QPushButton *ButtonCategoryValueUp;
    QPushButton *ButtonCategoryValueDown;
    QPushButton *ButtonCategoryValueCheckVisible;
    QPushButton *ButtonCategoryValueUncheckVisible;
    QPushButton *ButtonCategoryValueDelete;
    QFrame *FrameCategories;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonAddCategory;
    QPushButton *ButtonChangeCategory;
    QPushButton *ButtonDeleteAllCategories;
    QSpacerItem *horizontalSpacer_6;
    QScrollArea *ScrollAreaCategories;
    QWidget *widget;
    QFormLayout *layoutComboBoxCategories;
    QScrollArea *ScrollAreaCheckCategories;
    QWidget *widget_2;
    QFormLayout *layoutCheckBoxCategories;
    QTableWidget *TableWidgetFriends;
    QFrame *FrameHideColumns;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *CheckBoxCompareIcon;
    QCheckBox *CheckBoxCompareTitle;
    QCheckBox *CheckBoxCompareDescription;
    QCheckBox *CheckBoxCompareTotalPercent;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(894, 752);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormAchievements->setFont(font);
        verticalLayout_4 = new QVBoxLayout(FormAchievements);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
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

        CheckBoxShowFilter = new QCheckBox(FrameGameInfo);
        CheckBoxShowFilter->setObjectName(QString::fromUtf8("CheckBoxShowFilter"));
        CheckBoxShowFilter->setChecked(true);

        verticalLayout_7->addWidget(CheckBoxShowFilter);


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

        ButtonUpdate = new QPushButton(FrameGameInfo);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        horizontalLayout_6->addWidget(ButtonUpdate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_8);

        FrameFilter = new QFrame(FrameGameInfo);
        FrameFilter->setObjectName(QString::fromUtf8("FrameFilter"));
        FrameFilter->setMinimumSize(QSize(0, 0));
        FrameFilter->setFrameShape(QFrame::StyledPanel);
        FrameFilter->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(FrameFilter);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
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

        ButtonFavorite = new QPushButton(FrameFilter);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));

        horizontalLayout_12->addWidget(ButtonFavorite);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        ButtonCompare = new QPushButton(FrameFilter);
        ButtonCompare->setObjectName(QString::fromUtf8("ButtonCompare"));

        horizontalLayout_10->addWidget(ButtonCompare);

        CheckBoxCompareAllFriends = new QCheckBox(FrameFilter);
        CheckBoxCompareAllFriends->setObjectName(QString::fromUtf8("CheckBoxCompareAllFriends"));

        horizontalLayout_10->addWidget(CheckBoxCompareAllFriends);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LineEditNameAchievements = new QLineEdit(FrameFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));

        horizontalLayout_3->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(FrameFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);

        horizontalLayout_3->addWidget(ButtonFindAchievement);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_13->addLayout(verticalLayout_3);


        horizontalLayout_7->addWidget(FrameFilter);


        verticalLayout_4->addWidget(FrameGameInfo);

        ProgressBarFriendsLoad = new QProgressBar(FormAchievements);
        ProgressBarFriendsLoad->setObjectName(QString::fromUtf8("ProgressBarFriendsLoad"));
        ProgressBarFriendsLoad->setValue(0);

        verticalLayout_4->addWidget(ProgressBarFriendsLoad);

        FrameContainer = new QFrame(FormAchievements);
        FrameContainer->setObjectName(QString::fromUtf8("FrameContainer"));
        FrameContainer->setFrameShape(QFrame::StyledPanel);
        FrameContainer->setFrameShadow(QFrame::Raised);
        FrameEditCategory = new QFrame(FrameContainer);
        FrameEditCategory->setObjectName(QString::fromUtf8("FrameEditCategory"));
        FrameEditCategory->setGeometry(QRect(480, 200, 401, 271));
        FrameEditCategory->setFrameShape(QFrame::StyledPanel);
        FrameEditCategory->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FrameEditCategory);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        ComboBoxCategories = new QComboBox(FrameEditCategory);
        ComboBoxCategories->addItem(QString());
        ComboBoxCategories->setObjectName(QString::fromUtf8("ComboBoxCategories"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ComboBoxCategories->sizePolicy().hasHeightForWidth());
        ComboBoxCategories->setSizePolicy(sizePolicy2);
        ComboBoxCategories->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_14->addWidget(ComboBoxCategories);

        LineEditTitleCategory = new QLineEdit(FrameEditCategory);
        LineEditTitleCategory->setObjectName(QString::fromUtf8("LineEditTitleCategory"));
        sizePolicy2.setHeightForWidth(LineEditTitleCategory->sizePolicy().hasHeightForWidth());
        LineEditTitleCategory->setSizePolicy(sizePolicy2);

        horizontalLayout_14->addWidget(LineEditTitleCategory);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        ButtonAcceptCategory = new QPushButton(FrameEditCategory);
        ButtonAcceptCategory->setObjectName(QString::fromUtf8("ButtonAcceptCategory"));

        horizontalLayout_14->addWidget(ButtonAcceptCategory);

        ButtonDeleteCategory = new QPushButton(FrameEditCategory);
        ButtonDeleteCategory->setObjectName(QString::fromUtf8("ButtonDeleteCategory"));

        horizontalLayout_14->addWidget(ButtonDeleteCategory);

        ButtonCancelCategory = new QPushButton(FrameEditCategory);
        ButtonCancelCategory->setObjectName(QString::fromUtf8("ButtonCancelCategory"));

        horizontalLayout_14->addWidget(ButtonCancelCategory);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        CheckBoxCategoryOneValue = new QCheckBox(FrameEditCategory);
        CheckBoxCategoryOneValue->setObjectName(QString::fromUtf8("CheckBoxCategoryOneValue"));
        sizePolicy2.setHeightForWidth(CheckBoxCategoryOneValue->sizePolicy().hasHeightForWidth());
        CheckBoxCategoryOneValue->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(CheckBoxCategoryOneValue);

        CheckBoxCategoryUniqueValue = new QCheckBox(FrameEditCategory);
        CheckBoxCategoryUniqueValue->setObjectName(QString::fromUtf8("CheckBoxCategoryUniqueValue"));

        horizontalLayout_15->addWidget(CheckBoxCategoryUniqueValue);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        ButtonAddValueCategory = new QPushButton(FrameEditCategory);
        ButtonAddValueCategory->setObjectName(QString::fromUtf8("ButtonAddValueCategory"));

        horizontalLayout_16->addWidget(ButtonAddValueCategory);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        CheckBoxCategoryVisibleAll = new QCheckBox(FrameEditCategory);
        CheckBoxCategoryVisibleAll->setObjectName(QString::fromUtf8("CheckBoxCategoryVisibleAll"));
        CheckBoxCategoryVisibleAll->setChecked(true);

        horizontalLayout_16->addWidget(CheckBoxCategoryVisibleAll);


        verticalLayout_2->addLayout(horizontalLayout_16);

        ListWidgetValuesCategory = new QListWidget(FrameEditCategory);
        ListWidgetValuesCategory->setObjectName(QString::fromUtf8("ListWidgetValuesCategory"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ListWidgetValuesCategory->sizePolicy().hasHeightForWidth());
        ListWidgetValuesCategory->setSizePolicy(sizePolicy3);
        ListWidgetValuesCategory->setMaximumSize(QSize(16777215, 135));
        ListWidgetValuesCategory->setDragEnabled(true);
        ListWidgetValuesCategory->setDragDropMode(QAbstractItemView::InternalMove);
        ListWidgetValuesCategory->setDefaultDropAction(Qt::MoveAction);

        verticalLayout_2->addWidget(ListWidgetValuesCategory);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(FrameEditCategory);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        ButtonCategoryValueReverse = new QPushButton(FrameEditCategory);
        ButtonCategoryValueReverse->setObjectName(QString::fromUtf8("ButtonCategoryValueReverse"));

        horizontalLayout_9->addWidget(ButtonCategoryValueReverse);

        ButtonCategoryValueUp = new QPushButton(FrameEditCategory);
        ButtonCategoryValueUp->setObjectName(QString::fromUtf8("ButtonCategoryValueUp"));

        horizontalLayout_9->addWidget(ButtonCategoryValueUp);

        ButtonCategoryValueDown = new QPushButton(FrameEditCategory);
        ButtonCategoryValueDown->setObjectName(QString::fromUtf8("ButtonCategoryValueDown"));

        horizontalLayout_9->addWidget(ButtonCategoryValueDown);

        ButtonCategoryValueCheckVisible = new QPushButton(FrameEditCategory);
        ButtonCategoryValueCheckVisible->setObjectName(QString::fromUtf8("ButtonCategoryValueCheckVisible"));

        horizontalLayout_9->addWidget(ButtonCategoryValueCheckVisible);

        ButtonCategoryValueUncheckVisible = new QPushButton(FrameEditCategory);
        ButtonCategoryValueUncheckVisible->setObjectName(QString::fromUtf8("ButtonCategoryValueUncheckVisible"));

        horizontalLayout_9->addWidget(ButtonCategoryValueUncheckVisible);

        ButtonCategoryValueDelete = new QPushButton(FrameEditCategory);
        ButtonCategoryValueDelete->setObjectName(QString::fromUtf8("ButtonCategoryValueDelete"));

        horizontalLayout_9->addWidget(ButtonCategoryValueDelete);


        verticalLayout_2->addLayout(horizontalLayout_9);

        FrameCategories = new QFrame(FrameContainer);
        FrameCategories->setObjectName(QString::fromUtf8("FrameCategories"));
        FrameCategories->setGeometry(QRect(20, 210, 261, 195));
        FrameCategories->setFrameShape(QFrame::StyledPanel);
        FrameCategories->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(FrameCategories);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonAddCategory = new QPushButton(FrameCategories);
        ButtonAddCategory->setObjectName(QString::fromUtf8("ButtonAddCategory"));

        horizontalLayout->addWidget(ButtonAddCategory);

        ButtonChangeCategory = new QPushButton(FrameCategories);
        ButtonChangeCategory->setObjectName(QString::fromUtf8("ButtonChangeCategory"));

        horizontalLayout->addWidget(ButtonChangeCategory);

        ButtonDeleteAllCategories = new QPushButton(FrameCategories);
        ButtonDeleteAllCategories->setObjectName(QString::fromUtf8("ButtonDeleteAllCategories"));

        horizontalLayout->addWidget(ButtonDeleteAllCategories);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout);

        ScrollAreaCategories = new QScrollArea(FrameCategories);
        ScrollAreaCategories->setObjectName(QString::fromUtf8("ScrollAreaCategories"));
        sizePolicy3.setHeightForWidth(ScrollAreaCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCategories->setWidgetResizable(true);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 239, 68));
        layoutComboBoxCategories = new QFormLayout(widget);
        layoutComboBoxCategories->setObjectName(QString::fromUtf8("layoutComboBoxCategories"));
        ScrollAreaCategories->setWidget(widget);

        verticalLayout_5->addWidget(ScrollAreaCategories);

        ScrollAreaCheckCategories = new QScrollArea(FrameCategories);
        ScrollAreaCheckCategories->setObjectName(QString::fromUtf8("ScrollAreaCheckCategories"));
        sizePolicy3.setHeightForWidth(ScrollAreaCheckCategories->sizePolicy().hasHeightForWidth());
        ScrollAreaCheckCategories->setSizePolicy(sizePolicy3);
        ScrollAreaCheckCategories->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollAreaCheckCategories->setWidgetResizable(true);
        widget_2 = new QWidget();
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 239, 68));
        layoutCheckBoxCategories = new QFormLayout(widget_2);
        layoutCheckBoxCategories->setObjectName(QString::fromUtf8("layoutCheckBoxCategories"));
        ScrollAreaCheckCategories->setWidget(widget_2);

        verticalLayout_5->addWidget(ScrollAreaCheckCategories);

        TableWidgetFriends = new QTableWidget(FrameContainer);
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
        TableWidgetFriends->setGeometry(QRect(10, 10, 801, 141));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TableWidgetFriends->sizePolicy().hasHeightForWidth());
        TableWidgetFriends->setSizePolicy(sizePolicy4);
        TableWidgetFriends->setSelectionBehavior(QAbstractItemView::SelectColumns);
        TableWidgetFriends->setRowCount(4);
        TableWidgetFriends->setColumnCount(2);
        TableWidgetFriends->verticalHeader()->setVisible(false);
        FrameHideColumns = new QFrame(FrameContainer);
        FrameHideColumns->setObjectName(QString::fromUtf8("FrameHideColumns"));
        FrameHideColumns->setGeometry(QRect(10, 160, 358, 40));
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

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(FrameContainer);


        retranslateUi(FormAchievements);

        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QCoreApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        CheckBoxShowFilter->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        LabelGameOnline->setText(QCoreApplication::translate("FormAchievements", "GameOnline:  ", nullptr));
        ButtonUpdate->setText(QCoreApplication::translate("FormAchievements", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        CheckBoxFavorites->setText(QCoreApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonFavorite->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonCompare->setText(QCoreApplication::translate("FormAchievements", " \320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270", nullptr));
        CheckBoxCompareAllFriends->setText(QCoreApplication::translate("FormAchievements", "\320\222\321\201\320\265 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
        LineEditNameAchievements->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        ButtonFindAchievement->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        ProgressBarFriendsLoad->setFormat(QCoreApplication::translate("FormAchievements", "%v/%m", nullptr));
        ComboBoxCategories->setItemText(0, QCoreApplication::translate("FormAchievements", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));

        LineEditTitleCategory->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#if QT_CONFIG(tooltip)
        ButtonAcceptCategory->setToolTip(QCoreApplication::translate("FormAchievements", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAcceptCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteCategory->setToolTip(QCoreApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonCancelCategory->setToolTip(QCoreApplication::translate("FormAchievements", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonCancelCategory->setText(QString());
        CheckBoxCategoryOneValue->setText(QCoreApplication::translate("FormAchievements", "\320\221\320\265\320\267 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        CheckBoxCategoryUniqueValue->setText(QCoreApplication::translate("FormAchievements", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        ButtonAddValueCategory->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        CheckBoxCategoryVisibleAll->setText(QCoreApplication::translate("FormAchievements", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\321\221", nullptr));
        label->setText(QCoreApplication::translate("FormAchievements", "Value", nullptr));
        ButtonCategoryValueReverse->setText(QString());
        ButtonCategoryValueUp->setText(QString());
        ButtonCategoryValueDown->setText(QString());
        ButtonCategoryValueCheckVisible->setText(QString());
        ButtonCategoryValueUncheckVisible->setText(QString());
        ButtonCategoryValueDelete->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonAddCategory->setToolTip(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonAddCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonChangeCategory->setToolTip(QCoreApplication::translate("FormAchievements", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonChangeCategory->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setToolTip(QCoreApplication::translate("FormAchievements", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonDeleteAllCategories->setText(QString());

        const bool __sortingEnabled = TableWidgetFriends->isSortingEnabled();
        TableWidgetFriends->setSortingEnabled(false);
        TableWidgetFriends->setSortingEnabled(__sortingEnabled);

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
