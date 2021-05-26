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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "forms/subForms/achievements/formcategoriesedit.h"
#include "forms/subForms/achievements/formcategoriestree.h"
#include "forms/subForms/achievements/formfriendscompare.h"
#include "forms/subForms/achievements/widgets/formreachedfilter.h"
#include "subWidgets/progressBars/progressbargood.h"

QT_BEGIN_NAMESPACE

class Ui_FormAchievements
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QFrame *FrameFilter;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelTotalPersent;
    QPushButton *ButtonUpdate;
    FormReachedFilter *FilterMyProfile;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *CheckBoxFavorites;
    QPushButton *ButtonGuides;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *LineEditNameAchievements;
    QPushButton *ButtonFindAchievement;
    FormCategoriesTree *TreeWidgetCategories;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelGameOnline;
    QLabel *LabelGameOnlineValue;
    QTabWidget *TabWidget;
    QWidget *tabStandart;
    QVBoxLayout *verticalLayout_4;
    QTableView *TableViewMyAchievements;
    QWidget *tabEditCategory;
    QHBoxLayout *horizontalLayout;
    FormCategoriesEdit *CategoriesEdit;
    QWidget *tabCompare;
    QHBoxLayout *horizontalLayout_4;
    FormFriendsCompare *FriendsCompare;
    ProgressBarGood *ProgressBarLoad;

    void setupUi(QWidget *FormAchievements)
    {
        if (FormAchievements->objectName().isEmpty())
            FormAchievements->setObjectName(QString::fromUtf8("FormAchievements"));
        FormAchievements->resize(894, 622);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormAchievements->setFont(font);
        verticalLayout = new QVBoxLayout(FormAchievements);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        FrameFilter = new QFrame(FormAchievements);
        FrameFilter->setObjectName(QString::fromUtf8("FrameFilter"));
        FrameFilter->setFrameShape(QFrame::StyledPanel);
        FrameFilter->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameFilter);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LabelTotalPersent = new QLabel(FrameFilter);
        LabelTotalPersent->setObjectName(QString::fromUtf8("LabelTotalPersent"));
        LabelTotalPersent->setText(QString::fromUtf8("none/none (0%)"));
        LabelTotalPersent->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(LabelTotalPersent);

        ButtonUpdate = new QPushButton(FrameFilter);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonUpdate->sizePolicy().hasHeightForWidth());
        ButtonUpdate->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(ButtonUpdate);


        verticalLayout_2->addLayout(horizontalLayout_5);

        FilterMyProfile = new FormReachedFilter(FrameFilter);
        FilterMyProfile->setObjectName(QString::fromUtf8("FilterMyProfile"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(FilterMyProfile->sizePolicy().hasHeightForWidth());
        FilterMyProfile->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(FilterMyProfile);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        CheckBoxFavorites = new QCheckBox(FrameFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        horizontalLayout_6->addWidget(CheckBoxFavorites);

        ButtonGuides = new QPushButton(FrameFilter);
        ButtonGuides->setObjectName(QString::fromUtf8("ButtonGuides"));
        sizePolicy.setHeightForWidth(ButtonGuides->sizePolicy().hasHeightForWidth());
        ButtonGuides->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(ButtonGuides);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LineEditNameAchievements = new QLineEdit(FrameFilter);
        LineEditNameAchievements->setObjectName(QString::fromUtf8("LineEditNameAchievements"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LineEditNameAchievements->sizePolicy().hasHeightForWidth());
        LineEditNameAchievements->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(LineEditNameAchievements);

        ButtonFindAchievement = new QPushButton(FrameFilter);
        ButtonFindAchievement->setObjectName(QString::fromUtf8("ButtonFindAchievement"));
        ButtonFindAchievement->setEnabled(true);
        sizePolicy.setHeightForWidth(ButtonFindAchievement->sizePolicy().hasHeightForWidth());
        ButtonFindAchievement->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(ButtonFindAchievement);


        verticalLayout_2->addLayout(horizontalLayout_7);

        TreeWidgetCategories = new FormCategoriesTree(FrameFilter);
        TreeWidgetCategories->setObjectName(QString::fromUtf8("TreeWidgetCategories"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TreeWidgetCategories->sizePolicy().hasHeightForWidth());
        TreeWidgetCategories->setSizePolicy(sizePolicy3);
        TreeWidgetCategories->setMaximumSize(QSize(200, 16777215));
        TreeWidgetCategories->setWordWrap(true);

        verticalLayout_2->addWidget(TreeWidgetCategories);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelGameOnline = new QLabel(FrameFilter);
        LabelGameOnline->setObjectName(QString::fromUtf8("LabelGameOnline"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(LabelGameOnline->sizePolicy().hasHeightForWidth());
        LabelGameOnline->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        LabelGameOnline->setFont(font1);

        horizontalLayout_2->addWidget(LabelGameOnline);

        LabelGameOnlineValue = new QLabel(FrameFilter);
        LabelGameOnlineValue->setObjectName(QString::fromUtf8("LabelGameOnlineValue"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        LabelGameOnlineValue->setFont(font2);
        LabelGameOnlineValue->setStyleSheet(QString::fromUtf8("color: #42a9c6;"));
        LabelGameOnlineValue->setText(QString::fromUtf8("0"));

        horizontalLayout_2->addWidget(LabelGameOnlineValue);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_8->addWidget(FrameFilter);

        TabWidget = new QTabWidget(FormAchievements);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        tabStandart = new QWidget();
        tabStandart->setObjectName(QString::fromUtf8("tabStandart"));
        verticalLayout_4 = new QVBoxLayout(tabStandart);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        TableViewMyAchievements = new QTableView(tabStandart);
        TableViewMyAchievements->setObjectName(QString::fromUtf8("TableViewMyAchievements"));

        verticalLayout_4->addWidget(TableViewMyAchievements);

        TabWidget->addTab(tabStandart, QString());
        tabEditCategory = new QWidget();
        tabEditCategory->setObjectName(QString::fromUtf8("tabEditCategory"));
        horizontalLayout = new QHBoxLayout(tabEditCategory);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CategoriesEdit = new FormCategoriesEdit(tabEditCategory);
        CategoriesEdit->setObjectName(QString::fromUtf8("CategoriesEdit"));

        horizontalLayout->addWidget(CategoriesEdit);

        TabWidget->addTab(tabEditCategory, QString());
        tabCompare = new QWidget();
        tabCompare->setObjectName(QString::fromUtf8("tabCompare"));
        horizontalLayout_4 = new QHBoxLayout(tabCompare);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        FriendsCompare = new FormFriendsCompare(tabCompare);
        FriendsCompare->setObjectName(QString::fromUtf8("FriendsCompare"));

        horizontalLayout_4->addWidget(FriendsCompare);

        TabWidget->addTab(tabCompare, QString());

        horizontalLayout_8->addWidget(TabWidget);


        verticalLayout->addLayout(horizontalLayout_8);

        ProgressBarLoad = new ProgressBarGood(FormAchievements);
        ProgressBarLoad->setObjectName(QString::fromUtf8("ProgressBarLoad"));
        ProgressBarLoad->setValue(0);

        verticalLayout->addWidget(ProgressBarLoad);


        retranslateUi(FormAchievements);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormAchievements)
    {
        FormAchievements->setWindowTitle(QCoreApplication::translate("FormAchievements", "SteamAchievementsStatistic", nullptr));
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
        QTreeWidgetItem *___qtreewidgetitem = TreeWidgetCategories->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("FormAchievements", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        LabelGameOnline->setText(QCoreApplication::translate("FormAchievements", "GameOnline:  ", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabStandart), QCoreApplication::translate("FormAchievements", " \320\241\320\262\320\276\320\270 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217  ", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabEditCategory), QCoreApplication::translate("FormAchievements", "  \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217\320\274\320\270  ", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabCompare), QCoreApplication::translate("FormAchievements", "  \320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \321\201 \320\264\321\200\321\203\320\267\321\214\321\217\320\274\320\270 ", nullptr));
        ProgressBarLoad->setFormat(QCoreApplication::translate("FormAchievements", "%v/%m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAchievements: public Ui_FormAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMACHIEVEMENTS_H
