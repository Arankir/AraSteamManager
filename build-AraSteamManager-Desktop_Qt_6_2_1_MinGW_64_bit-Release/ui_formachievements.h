/********************************************************************************
** Form generated from reading UI file 'formachievements.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMACHIEVEMENTS_H
#define UI_FORMACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "forms/achievements/formcategoriesedit.h"
#include "subWidgets/lineEdit/mylineedit.h"
#include "subWidgets/tables/freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitterFilterAchievements;
    QFrame *FrameFilter;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelProfileAvatar;
    QLabel *LabelTotalPersent;
    QPushButton *ButtonUpdate;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *CheckBoxFavorites;
    QPushButton *ButtonGuides;
    QHBoxLayout *horizontalLayout_7;
    MyLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    QTreeView *TreeWidgetCategories;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelGameOnline;
    QLabel *LabelGameOnlineValue;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitterAchievementsFriends;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    FreezeTableWidget *TableViewAchievements;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    MyLineEdit *lineEditFindProfile;
    QPushButton *ButtonAddProfile;
    QHBoxLayout *horizontalLayout;
    MyLineEdit *lineEditFindFriend;
    QPushButton *ButtonFindFriend;
    QCheckBox *checkBoxOnlyWithGame;
    QListView *ListViewFriends;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    FormCategoriesEdit *CategoriesEdit;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(894, 622);
        verticalLayout = new QVBoxLayout(FormAchievements);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitterFilterAchievements = new QSplitter(FormAchievements);
        splitterFilterAchievements->setObjectName(QString::fromUtf8("splitterFilterAchievements"));
        splitterFilterAchievements->setOrientation(Qt::Horizontal);
        FrameFilter = new QFrame(splitterFilterAchievements);
        FrameFilter->setObjectName(QString::fromUtf8("FrameFilter"));
        FrameFilter->setFrameShape(QFrame::StyledPanel);
        FrameFilter->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameFilter);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelProfileAvatar = new QLabel(FrameFilter);
        labelProfileAvatar->setObjectName(QString::fromUtf8("labelProfileAvatar"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelProfileAvatar->sizePolicy().hasHeightForWidth());
        labelProfileAvatar->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(labelProfileAvatar);

        LabelTotalPersent = new QLabel(FrameFilter);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setText(QString::fromUtf8("none/none (0%)"));
        LabelTotalPersent->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(LabelTotalPersent);

        ButtonUpdate = new QPushButton(FrameFilter);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonUpdate->sizePolicy().hasHeightForWidth());
        ButtonUpdate->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(ButtonUpdate);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        CheckBoxFavorites = new QCheckBox(FrameFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CheckBoxFavorites->sizePolicy().hasHeightForWidth());
        CheckBoxFavorites->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(CheckBoxFavorites);

        ButtonGuides = new QPushButton(FrameFilter);
        ButtonGuides->setObjectName(QString::fromUtf8("ButtonGuides"));
        sizePolicy1.setHeightForWidth(ButtonGuides->sizePolicy().hasHeightForWidth());
        ButtonGuides->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(ButtonGuides);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LineEditNameAchievements = new MyLineEdit(FrameFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));
        sizePolicy2.setHeightForWidth(LineEditNameAchievements->sizePolicy().hasHeightForWidth());
        LineEditNameAchievements->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(FrameFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);
        sizePolicy1.setHeightForWidth(ButtonFindAchievement->sizePolicy().hasHeightForWidth());
        ButtonFindAchievement->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(ButtonFindAchievement);


        verticalLayout_3->addLayout(horizontalLayout_7);

        TreeWidgetCategories = new QTreeView(FrameFilter);
        TreeWidgetCategories->setObjectName(QString::fromUtf8("TreeWidgetCategories"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TreeWidgetCategories->sizePolicy().hasHeightForWidth());
        TreeWidgetCategories->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(TreeWidgetCategories);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelGameOnline = new QLabel(FrameFilter);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        sizePolicy.setHeightForWidth(LabelGameOnline->sizePolicy().hasHeightForWidth());
        LabelGameOnline->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        LabelGameOnline->setFont(font);

        horizontalLayout_2->addWidget(LabelGameOnline);

        LabelGameOnlineValue = new QLabel(FrameFilter);
        LabelGameOnlineValue->setObjectName(QString::fromUtf8("LabelGameOnlineValue"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        LabelGameOnlineValue->setFont(font1);
        LabelGameOnlineValue->setStyleSheet(QString::fromUtf8("color: #42a9c6;"));
        LabelGameOnlineValue->setText(QString::fromUtf8("0"));

        horizontalLayout_2->addWidget(LabelGameOnlineValue);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitterFilterAchievements->addWidget(FrameFilter);
        stackedWidget = new QStackedWidget(splitterFilterAchievements);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy4);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        splitterAchievementsFriends = new QSplitter(page);
        splitterAchievementsFriends->setObjectName(QString::fromUtf8("splitterAchievementsFriends"));
        splitterAchievementsFriends->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitterAchievementsFriends);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TableViewAchievements = new FreezeTableWidget(layoutWidget);
        TableViewAchievements->setObjectName(QString::fromUtf8("TableViewAchievements"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(TableViewAchievements->sizePolicy().hasHeightForWidth());
        TableViewAchievements->setSizePolicy(sizePolicy5);

        verticalLayout_2->addWidget(TableViewAchievements);

        splitterAchievementsFriends->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitterAchievementsFriends);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEditFindProfile = new MyLineEdit(layoutWidget1);
        lineEditFindProfile->setObjectName(QString::fromUtf8("lineEditFindProfile"));
        sizePolicy2.setHeightForWidth(lineEditFindProfile->sizePolicy().hasHeightForWidth());
        lineEditFindProfile->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(lineEditFindProfile);

        ButtonAddProfile = new QPushButton(layoutWidget1);
        ButtonAddProfile->setObjectName(QString::fromUtf8("ButtonAddProfile"));
        sizePolicy1.setHeightForWidth(ButtonAddProfile->sizePolicy().hasHeightForWidth());
        ButtonAddProfile->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(ButtonAddProfile);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditFindFriend = new MyLineEdit(layoutWidget1);
        lineEditFindFriend->setObjectName(QString::fromUtf8("lineEditFindFriend"));

        horizontalLayout->addWidget(lineEditFindFriend);

        ButtonFindFriend = new QPushButton(layoutWidget1);
        ButtonFindFriend->setObjectName(QString::fromUtf8("ButtonFindFriend"));

        horizontalLayout->addWidget(ButtonFindFriend);


        verticalLayout_4->addLayout(horizontalLayout);

        checkBoxOnlyWithGame = new QCheckBox(layoutWidget1);
        checkBoxOnlyWithGame->setObjectName(QString::fromUtf8("checkBoxOnlyWithGame"));

        verticalLayout_4->addWidget(checkBoxOnlyWithGame);

        ListViewFriends = new QListView(layoutWidget1);
        ListViewFriends->setObjectName(QString::fromUtf8("ListViewFriends"));
        sizePolicy3.setHeightForWidth(ListViewFriends->sizePolicy().hasHeightForWidth());
        ListViewFriends->setSizePolicy(sizePolicy3);
        ListViewFriends->setResizeMode(QListView::Adjust);

        verticalLayout_4->addWidget(ListViewFriends);

        splitterAchievementsFriends->addWidget(layoutWidget1);

        verticalLayout_5->addWidget(splitterAchievementsFriends);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        CategoriesEdit = new FormCategoriesEdit(page_2);
        CategoriesEdit->setObjectName(QString::fromUtf8("CategoriesEdit"));

        verticalLayout_6->addWidget(CategoriesEdit);

        stackedWidget->addWidget(page_2);
        splitterFilterAchievements->addWidget(stackedWidget);

        verticalLayout->addWidget(splitterFilterAchievements);


        retranslateUi(FormAchievements);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QCoreApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
        labelProfileAvatar->setText(QString());
#if QT_CONFIG(tooltip)
        ButtonUpdate->setToolTip(QCoreApplication::translate("FormAchievements", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonUpdate->setText(QString());
        CheckBoxFavorites->setText(QCoreApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
#if QT_CONFIG(tooltip)
        ButtonGuides->setToolTip(QCoreApplication::translate("FormAchievements", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        ButtonGuides->setText(QString());
        LineEditNameAchievements->setPlaceholderText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        ButtonFindAchievement->setText(QString());
        LabelGameOnline->setText(QCoreApplication::translate("FormAchievements", "GameOnline:  ", nullptr));
        lineEditFindProfile->setPlaceholderText(QCoreApplication::translate("FormAchievements", "https://steamcommunity.com/id/gabelogannewell", nullptr));
        ButtonAddProfile->setText(QCoreApplication::translate("FormAchievements", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lineEditFindFriend->setPlaceholderText(QCoreApplication::translate("FormAchievements", "LuckyGuy1337", nullptr));
        ButtonFindFriend->setText(QCoreApplication::translate("FormAchievements", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        checkBoxOnlyWithGame->setText(QCoreApplication::translate("FormAchievements", "\320\242\320\276\320\273\321\214\320\272\320\276 \321\201 \320\270\320\263\321\200\320\276\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
