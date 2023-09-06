/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "forms/main/settings/formimportexport.h"

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QComboBox *ComboBoxTheme;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QComboBox *ComboBoxLanguage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxProfileInfo;
    QSpacerItem *horizontalSpacer;
    QLabel *labelIcons8;
    QSpacerItem *verticalSpacer;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_16;
    FormImportExport *widget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *treeWidgetHiddenGames;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QLabel *labelVersion;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(583, 456);
        verticalLayout_5 = new QVBoxLayout(FormSettings);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FormSettings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        ComboBoxTheme = new QComboBox(tab_2);
        ComboBoxTheme->setObjectName(QString::fromUtf8("ComboBoxTheme"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ComboBoxTheme->sizePolicy().hasHeightForWidth());
        ComboBoxTheme->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ComboBoxTheme);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);

        ComboBoxLanguage = new QComboBox(tab_2);
        ComboBoxLanguage->setObjectName(QString::fromUtf8("ComboBoxLanguage"));
        sizePolicy.setHeightForWidth(ComboBoxLanguage->sizePolicy().hasHeightForWidth());
        ComboBoxLanguage->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(ComboBoxLanguage);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxProfileInfo = new QComboBox(tab_2);
        comboBoxProfileInfo->setObjectName(QString::fromUtf8("comboBoxProfileInfo"));

        horizontalLayout_2->addWidget(comboBoxProfileInfo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        labelIcons8 = new QLabel(tab_2);
        labelIcons8->setObjectName(QString::fromUtf8("labelIcons8"));
        QFont font;
        font.setPointSize(10);
        labelIcons8->setFont(font);
        labelIcons8->setWordWrap(true);
        labelIcons8->setOpenExternalLinks(true);
        labelIcons8->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout->addWidget(labelIcons8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayout_16 = new QVBoxLayout(tab_6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        widget = new FormImportExport(tab_6);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_16->addWidget(widget);

        tabWidget->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeWidgetHiddenGames = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetHiddenGames->setHeaderItem(__qtreewidgetitem);
        treeWidgetHiddenGames->setObjectName(QString::fromUtf8("treeWidgetHiddenGames"));
        treeWidgetHiddenGames->header()->setVisible(false);

        verticalLayout_3->addWidget(treeWidgetHiddenGames);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setWordWrap(false);

        horizontalLayout_16->addWidget(label_7);

        labelVersion = new QLabel(tab);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelVersion->sizePolicy().hasHeightForWidth());
        labelVersion->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(labelVersion);


        verticalLayout_2->addLayout(horizontalLayout_16);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setWordWrap(true);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setItalic(true);
        label_9->setFont(font1);

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setTextFormat(Qt::RichText);

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());

        verticalLayout_5->addWidget(tabWidget);


        retranslateUi(FormSettings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "Form", nullptr));
        label_12->setText(QCoreApplication::translate("FormSettings", "\320\242\320\265\320\274\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("FormSettings", "\320\257\320\267\321\213\320\272", nullptr));
        label->setText(QCoreApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\277\321\200\320\276\321\204\320\270\320\273\320\265", nullptr));
        labelIcons8->setText(QCoreApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\201\320\260\320\271\321\202\320\276\320\274 <a href=https://icons8.ru/icons>https://icons8.ru/icons</a></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormSettings", "  \320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("FormSettings", "\320\230\320\274\320\277\320\276\321\200\321\202/\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FormSettings", "  \320\241\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213  ", nullptr));
        label_7->setText(QCoreApplication::translate("FormSettings", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:", nullptr));
        labelVersion->setText(QCoreApplication::translate("FormSettings", "1.0", nullptr));
        label_8->setText(QCoreApplication::translate("FormSettings", "\320\242\320\260\320\272 \320\266\320\265 \321\201\320\277\320\260\321\201\320\270\320\261\320\276 \320\267\320\260 \320\277\320\276\320\274\320\276\321\211\321\214 \320\262 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265:", nullptr));
        label_9->setText(QCoreApplication::translate("FormSettings", "-\320\230\320\264\321\200\320\270\321\201\320\276\320\262 \320\242\320\260\320\263\320\270\321\200", nullptr));
        label_10->setText(QCoreApplication::translate("FormSettings", "<html><head/><body><p>-<a href=https://arturosipov.com>\320\236\321\201\320\270\320\277\320\276\320\262 \320\220\321\200\321\202\321\203\321\200</a></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("FormSettings", "-\320\235\320\270\320\272\320\270\321\202\320\270\320\275 \320\222\320\260\321\201\320\270\320\273\320\270\320\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormSettings", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
