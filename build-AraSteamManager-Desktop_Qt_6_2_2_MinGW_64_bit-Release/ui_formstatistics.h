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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/labels/labelvalue.h"

QT_BEGIN_NAMESPACE

class Ui_FormStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *labelSummColumn;
    QHBoxLayout *horizontalLayout_3;
    LabelValue *labelSumAchievementsValue;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *labelAveragePercentValue;
    QHBoxLayout *horizontalLayout_4;
    LabelValue *labelAverageAllGamesValue;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    LabelValue *labelAverageStartedGamesValue;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    LabelValue *labelCompletedGamesValue;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    LabelValue *labelStartedGamesValue;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    LabelValue *labelNotStartedGamesValue;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    LabelValue *labelNoAchievementsGamesValue;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QGraphicsView *graphicsViewLastAchievements;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QChartView *ChartViewPercentages;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_9;
    QSplitter *splitterGraph;
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
    QListView *listViewFriendsGraph;

    void setupUi(QWidget *FormStatistics)
    {
        if (FormStatistics->objectName().isEmpty())
            FormStatistics->setObjectName(QString::fromUtf8("FormStatistics"));
        FormStatistics->resize(657, 550);
        verticalLayout = new QVBoxLayout(FormStatistics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(FormStatistics);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelSummColumn = new QLabel(tab);
        labelSummColumn->setObjectName(QString::fromUtf8("labelSummColumn"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSummColumn->sizePolicy().hasHeightForWidth());
        labelSummColumn->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelSummColumn);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelSumAchievementsValue = new LabelValue(tab);
        labelSumAchievementsValue->setObjectName(QString::fromUtf8("labelSumAchievementsValue"));
        sizePolicy.setHeightForWidth(labelSumAchievementsValue->sizePolicy().hasHeightForWidth());
        labelSumAchievementsValue->setSizePolicy(sizePolicy);
        labelSumAchievementsValue->setText(QString::fromUtf8("0"));

        horizontalLayout_3->addWidget(labelSumAchievementsValue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        label->setFont(font);
        label->setText(QString::fromUtf8("?"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);

        labelAveragePercentValue = new QLabel(tab);
        labelAveragePercentValue->setObjectName(QString::fromUtf8("labelAveragePercentValue"));
        sizePolicy.setHeightForWidth(labelAveragePercentValue->sizePolicy().hasHeightForWidth());
        labelAveragePercentValue->setSizePolicy(sizePolicy);
        labelAveragePercentValue->setText(QString::fromUtf8("\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\277\321\200\320\276\321\206\320\265\320\275\321\202 \320\277\320\276 \320\262\321\201\320\265\320\274 \320\270\320\263\321\200\320\260\320\274"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelAveragePercentValue);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelAverageAllGamesValue = new LabelValue(tab);
        labelAverageAllGamesValue->setObjectName(QString::fromUtf8("labelAverageAllGamesValue"));
        sizePolicy.setHeightForWidth(labelAverageAllGamesValue->sizePolicy().hasHeightForWidth());
        labelAverageAllGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(labelAverageAllGamesValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelAverageStartedGamesValue = new LabelValue(tab);
        labelAverageStartedGamesValue->setObjectName(QString::fromUtf8("labelAverageStartedGamesValue"));
        sizePolicy.setHeightForWidth(labelAverageStartedGamesValue->sizePolicy().hasHeightForWidth());
        labelAverageStartedGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(labelAverageStartedGamesValue);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelCompletedGamesValue = new LabelValue(tab);
        labelCompletedGamesValue->setObjectName(QString::fromUtf8("labelCompletedGamesValue"));
        sizePolicy.setHeightForWidth(labelCompletedGamesValue->sizePolicy().hasHeightForWidth());
        labelCompletedGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(labelCompletedGamesValue);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelStartedGamesValue = new LabelValue(tab);
        labelStartedGamesValue->setObjectName(QString::fromUtf8("labelStartedGamesValue"));
        sizePolicy.setHeightForWidth(labelStartedGamesValue->sizePolicy().hasHeightForWidth());
        labelStartedGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(labelStartedGamesValue);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelNotStartedGamesValue = new LabelValue(tab);
        labelNotStartedGamesValue->setObjectName(QString::fromUtf8("labelNotStartedGamesValue"));
        sizePolicy.setHeightForWidth(labelNotStartedGamesValue->sizePolicy().hasHeightForWidth());
        labelNotStartedGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(labelNotStartedGamesValue);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_7);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelNoAchievementsGamesValue = new LabelValue(tab);
        labelNoAchievementsGamesValue->setObjectName(QString::fromUtf8("labelNoAchievementsGamesValue"));
        sizePolicy.setHeightForWidth(labelNoAchievementsGamesValue->sizePolicy().hasHeightForWidth());
        labelNoAchievementsGamesValue->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(labelNoAchievementsGamesValue);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 253, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::LabelRole, verticalSpacer);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        graphicsViewLastAchievements = new QGraphicsView(tab_4);
        graphicsViewLastAchievements->setObjectName(QString::fromUtf8("graphicsViewLastAchievements"));

        verticalLayout_6->addWidget(graphicsViewLastAchievements);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ChartViewPercentages = new QChartView(tab_2);
        ChartViewPercentages->setObjectName(QString::fromUtf8("ChartViewPercentages"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ChartViewPercentages->sizePolicy().hasHeightForWidth());
        ChartViewPercentages->setSizePolicy(sizePolicy1);
        ChartViewPercentages->setMinimumSize(QSize(0, 250));

        verticalLayout_2->addWidget(ChartViewPercentages);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_9 = new QVBoxLayout(tab_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        splitterGraph = new QSplitter(tab_3);
        splitterGraph->setObjectName(QString::fromUtf8("splitterGraph"));
        splitterGraph->setOrientation(Qt::Horizontal);
        stackedWidgetGraphs = new QStackedWidget(splitterGraph);
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
        splitterGraph->addWidget(stackedWidgetGraphs);
        layoutWidget = new QWidget(splitterGraph);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBoxGraph = new QComboBox(layoutWidget);
        comboBoxGraph->setObjectName(QString::fromUtf8("comboBoxGraph"));

        verticalLayout_5->addWidget(comboBoxGraph);

        listViewFriendsGraph = new QListView(layoutWidget);
        listViewFriendsGraph->setObjectName(QString::fromUtf8("listViewFriendsGraph"));

        verticalLayout_5->addWidget(listViewFriendsGraph);

        splitterGraph->addWidget(layoutWidget);

        verticalLayout_9->addWidget(splitterGraph);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(FormStatistics);

        tabWidget->setCurrentIndex(3);
        stackedWidgetGraphs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormStatistics);
    } // setupUi

    void retranslateUi(QWidget *FormStatistics)
    {
        FormStatistics->setWindowTitle(QCoreApplication::translate("FormStatistics", "Form", nullptr));
        labelSummColumn->setText(QCoreApplication::translate("FormStatistics", "\320\222\321\201\320\265\320\263\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271:", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("FormStatistics", "<html><head/><body><p>\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\277\320\276 \320\270\320\263\321\200\320\260\320\274 \320\275\320\260 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\265 \321\203 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\265\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217.<br/>\320\225\321\201\320\273\320\270 \321\201\321\203\320\274\320\274\320\260\321\200\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \321\201 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\265\320\271 \321\201\321\202\320\270\320\274\320\260, \320\267\320\275\320\260\321"
                        "\207\320\270\321\202 \321\207\320\260\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\320\271 \320\275\320\260\321\205\320\276\320\264\320\270\321\202\321\201\321\217 \320\262 \320\270\320\263\321\200\320\260\321\205 \320\275\320\265 \320\270\320\267 \320\262\320\260\321\210\320\265\320\271 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\270 (\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200 \320\277\320\276 \321\201\320\265\320\274\320\265\320\271\320\275\320\276\320\274\321\203 \320\264\320\276\321\201\321\202\321\203\320\277\321\203 \320\270\320\273\320\270 \320\267\320\260\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\320\265 \320\262 \320\261\320\265\321\201\320\277\320\273\320\260\321\202\320\275\321\213\320\265 \320\262\321\213\321\205\320\276\320\264\320\275\321\213\320\265)</span></p></body></html>", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormStatistics", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("FormStatistics", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\265 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormStatistics", "\320\230\320\263\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FormStatistics", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormStatistics: public Ui_FormStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTATISTICS_H
