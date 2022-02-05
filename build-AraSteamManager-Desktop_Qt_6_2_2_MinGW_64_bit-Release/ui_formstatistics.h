/********************************************************************************
** Form generated from reading UI file 'formstatistics.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTATISTICS_H
#define UI_FORMSTATISTICS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/comboBoxes/qcomboboxfriends.h"
#include "subWidgets/labels/labelvalue.h"

QT_BEGIN_NAMESPACE

class Ui_FormStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelProfile;
    QSpacerItem *horizontalSpacer_4;
    ComboBoxFriends *comboBoxCurrentProfile;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelSummColumn;
    LabelValue *labelSumAchievementsValue;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAveragePercentValue;
    LabelValue *labelAverageAllGamesValue;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    LabelValue *labelAverageStartedGamesValue;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    LabelValue *labelCompletedGamesValue;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    LabelValue *labelStartedGamesValue;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    LabelValue *labelNotStartedGamesValue;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    LabelValue *labelNoAchievementsGamesValue;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QTableView *tableViewLastAchievements;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutPie;
    QChartView *ChartViewPercentages;
    QTableView *TableViewGames;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_9;
    QSplitter *splitter;
    QStackedWidget *stackedWidgetGraphs;
    QWidget *page;
    QVBoxLayout *verticalLayout_8;
    QChartView *ChartsViewTimes;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QChartView *ChartsViewYears;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBoxGraph;
    ComboBoxFriends *comboBoxGraphsFriends;
    QListWidget *listWidgetFriendsGraph;

    void setupUi(QWidget *FormStatistics)
    {
        if (FormStatistics->objectName().isEmpty())
            FormStatistics->setObjectName(QString::fromUtf8("FormStatistics"));
        FormStatistics->resize(657, 550);
        verticalLayout = new QVBoxLayout(FormStatistics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelProfile = new QLabel(FormStatistics);
        labelProfile->setObjectName(QString::fromUtf8("labelProfile"));
        labelProfile->setText(QString::fromUtf8("Profile"));

        horizontalLayout->addWidget(labelProfile);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        comboBoxCurrentProfile = new ComboBoxFriends(FormStatistics);
        comboBoxCurrentProfile->setObjectName(QString::fromUtf8("comboBoxCurrentProfile"));

        horizontalLayout->addWidget(comboBoxCurrentProfile);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(FormStatistics);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelSummColumn = new QLabel(tab);
        labelSummColumn->setObjectName(QString::fromUtf8("labelSummColumn"));

        horizontalLayout_3->addWidget(labelSummColumn);

        labelSumAchievementsValue = new LabelValue(tab);
        labelSumAchievementsValue->setObjectName(QString::fromUtf8("labelSumAchievementsValue"));
        labelSumAchievementsValue->setText(QString::fromUtf8("0"));

        horizontalLayout_3->addWidget(labelSumAchievementsValue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        label->setFont(font);
        label->setText(QString::fromUtf8("?"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelAveragePercentValue = new QLabel(tab);
        labelAveragePercentValue->setObjectName(QString::fromUtf8("labelAveragePercentValue"));
        labelAveragePercentValue->setText(QString::fromUtf8("\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\277\321\200\320\276\321\206\320\265\320\275\321\202 \320\277\320\276 \320\262\321\201\320\265\320\274 \320\270\320\263\321\200\320\260\320\274"));

        horizontalLayout_4->addWidget(labelAveragePercentValue);

        labelAverageAllGamesValue = new LabelValue(tab);
        labelAverageAllGamesValue->setObjectName(QString::fromUtf8("labelAverageAllGamesValue"));

        horizontalLayout_4->addWidget(labelAverageAllGamesValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        labelAverageStartedGamesValue = new LabelValue(tab);
        labelAverageStartedGamesValue->setObjectName(QString::fromUtf8("labelAverageStartedGamesValue"));

        horizontalLayout_5->addWidget(labelAverageStartedGamesValue);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        labelCompletedGamesValue = new LabelValue(tab);
        labelCompletedGamesValue->setObjectName(QString::fromUtf8("labelCompletedGamesValue"));

        horizontalLayout_2->addWidget(labelCompletedGamesValue);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        labelStartedGamesValue = new LabelValue(tab);
        labelStartedGamesValue->setObjectName(QString::fromUtf8("labelStartedGamesValue"));

        horizontalLayout_6->addWidget(labelStartedGamesValue);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        labelNotStartedGamesValue = new LabelValue(tab);
        labelNotStartedGamesValue->setObjectName(QString::fromUtf8("labelNotStartedGamesValue"));

        horizontalLayout_7->addWidget(labelNotStartedGamesValue);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        labelNoAchievementsGamesValue = new LabelValue(tab);
        labelNoAchievementsGamesValue->setObjectName(QString::fromUtf8("labelNoAchievementsGamesValue"));

        horizontalLayout_8->addWidget(labelNoAchievementsGamesValue);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_10->addWidget(label_3);

        tableViewLastAchievements = new QTableView(tab);
        tableViewLastAchievements->setObjectName(QString::fromUtf8("tableViewLastAchievements"));

        verticalLayout_10->addWidget(tableViewLastAchievements);


        horizontalLayout_9->addLayout(verticalLayout_10);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayoutPie = new QHBoxLayout();
        horizontalLayoutPie->setObjectName(QString::fromUtf8("horizontalLayoutPie"));
        ChartViewPercentages = new QChartView(tab_2);
        ChartViewPercentages->setObjectName(QString::fromUtf8("ChartViewPercentages"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChartViewPercentages->sizePolicy().hasHeightForWidth());
        ChartViewPercentages->setSizePolicy(sizePolicy);
        ChartViewPercentages->setMinimumSize(QSize(0, 250));

        horizontalLayoutPie->addWidget(ChartViewPercentages);

        TableViewGames = new QTableView(tab_2);
        TableViewGames->setObjectName(QString::fromUtf8("TableViewGames"));
        TableViewGames->horizontalHeader()->setStretchLastSection(true);

        horizontalLayoutPie->addWidget(TableViewGames);


        verticalLayout_3->addLayout(horizontalLayoutPie);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_9 = new QVBoxLayout(tab_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        splitter = new QSplitter(tab_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        stackedWidgetGraphs = new QStackedWidget(splitter);
        stackedWidgetGraphs->setObjectName(QString::fromUtf8("stackedWidgetGraphs"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_8 = new QVBoxLayout(page);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        ChartsViewTimes = new QChartView(page);
        ChartsViewTimes->setObjectName(QString::fromUtf8("ChartsViewTimes"));

        verticalLayout_8->addWidget(ChartsViewTimes);

        stackedWidgetGraphs->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ChartsViewYears = new QChartView(page_2);
        ChartsViewYears->setObjectName(QString::fromUtf8("ChartsViewYears"));

        verticalLayout_4->addWidget(ChartsViewYears);

        stackedWidgetGraphs->addWidget(page_2);
        splitter->addWidget(stackedWidgetGraphs);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBoxGraph = new QComboBox(layoutWidget);
        comboBoxGraph->setObjectName(QString::fromUtf8("comboBoxGraph"));

        verticalLayout_5->addWidget(comboBoxGraph);

        comboBoxGraphsFriends = new ComboBoxFriends(layoutWidget);
        comboBoxGraphsFriends->setObjectName(QString::fromUtf8("comboBoxGraphsFriends"));

        verticalLayout_5->addWidget(comboBoxGraphsFriends);

        listWidgetFriendsGraph = new QListWidget(layoutWidget);
        listWidgetFriendsGraph->setObjectName(QString::fromUtf8("listWidgetFriendsGraph"));

        verticalLayout_5->addWidget(listWidgetFriendsGraph);

        splitter->addWidget(layoutWidget);

        verticalLayout_9->addWidget(splitter);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(FormStatistics);

        tabWidget->setCurrentIndex(0);
        stackedWidgetGraphs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormStatistics);
    } // setupUi

    void retranslateUi(QWidget *FormStatistics)
    {
        FormStatistics->setWindowTitle(QCoreApplication::translate("FormStatistics", "Form", nullptr));
        labelSummColumn->setText(QCoreApplication::translate("FormStatistics", "\320\222\321\201\320\265\320\263\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271:", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("FormStatistics", "<html><head/><body><p>\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\275\320\260 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\265 \321\203 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\265\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217.<br/>\320\225\321\201\320\273\320\270 \321\201\321\203\320\274\320\274\320\260\321\200\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \321\201 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\265\320\271 \321\201\321\202\320\270\320\274\320\260, \320\267\320\275\320\260\321"
                        "\207\320\270\321\202 \321\207\320\260\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\260 \321\201 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265\320\274 \321\201\320\265\320\274\320\265\320\271\320\275\320\276\320\263\320\276 \320\264\320\276\321\201\321\202\321\203\320\277\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelAverageAllGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_2->setText(QCoreApplication::translate("FormStatistics", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\277\321\200\320\276\321\206\320\265\320\275\321\202 \320\277\320\276 \320\275\320\260\321\207\320\260\321\202\321\213\320\274 \320\270\320\263\321\200\320\260\320\274", nullptr));
        labelAverageStartedGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_4->setText(QCoreApplication::translate("FormStatistics", "\320\227\320\260\320\272\321\200\321\213\321\202\321\213\321\205 \320\270\320\263\321\200", nullptr));
        labelCompletedGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_6->setText(QCoreApplication::translate("FormStatistics", "\320\235\320\260\321\207\320\260\321\202\321\213\321\205 \320\270\320\263\321\200", nullptr));
        labelStartedGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_8->setText(QCoreApplication::translate("FormStatistics", "\320\235\320\265 \320\275\320\260\321\207\320\260\321\202\321\213\321\205 \320\270\320\263\321\200", nullptr));
        labelNotStartedGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_10->setText(QCoreApplication::translate("FormStatistics", "\320\230\320\263\321\200 \320\261\320\265\320\267 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271", nullptr));
        labelNoAchievementsGamesValue->setText(QCoreApplication::translate("FormStatistics", "0", nullptr));
        label_3->setText(QCoreApplication::translate("FormStatistics", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\265 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormStatistics", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormStatistics", "\320\230\320\263\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FormStatistics", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistics: public Ui_FormStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTICS_H
