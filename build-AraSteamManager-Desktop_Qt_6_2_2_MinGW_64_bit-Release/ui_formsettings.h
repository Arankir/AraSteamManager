/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "forms/main/settings/formcommonsettings.h"
#include "forms/main/settings/formimportexport.h"

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    FormCommonSettings *commonSettings;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_16;
    FormImportExport *importExport;
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
        commonSettings = new FormCommonSettings(tab_2);
        commonSettings->setObjectName(QString::fromUtf8("commonSettings"));

        verticalLayout->addWidget(commonSettings);

        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayout_16 = new QVBoxLayout(tab_6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        importExport = new FormImportExport(tab_6);
        importExport->setObjectName(QString::fromUtf8("importExport"));

        verticalLayout_16->addWidget(importExport);

        tabWidget->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setWordWrap(false);

        horizontalLayout_16->addWidget(label_7);

        labelVersion = new QLabel(tab);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelVersion->sizePolicy().hasHeightForWidth());
        labelVersion->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(labelVersion);


        verticalLayout_2->addLayout(horizontalLayout_16);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setWordWrap(true);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setItalic(true);
        label_9->setFont(font);

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormSettings", "  \320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("FormSettings", "\320\230\320\274\320\277\320\276\321\200\321\202/\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
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
