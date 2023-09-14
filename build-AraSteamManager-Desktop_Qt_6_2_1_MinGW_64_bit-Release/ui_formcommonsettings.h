/********************************************************************************
** Form generated from reading UI file 'formcommonsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOMMONSETTINGS_H
#define UI_FORMCOMMONSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCommonSettings
{
public:
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

    void setupUi(QWidget *FormCommonSettings)
    {
        if (FormCommonSettings->objectName().isEmpty())
            FormCommonSettings->setObjectName(QString::fromUtf8("FormCommonSettings"));
        FormCommonSettings->resize(250, 217);
        verticalLayout = new QVBoxLayout(FormCommonSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_12 = new QLabel(FormCommonSettings);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        ComboBoxTheme = new QComboBox(FormCommonSettings);
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
        label_13 = new QLabel(FormCommonSettings);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);

        ComboBoxLanguage = new QComboBox(FormCommonSettings);
        ComboBoxLanguage->setObjectName(QString::fromUtf8("ComboBoxLanguage"));
        sizePolicy.setHeightForWidth(ComboBoxLanguage->sizePolicy().hasHeightForWidth());
        ComboBoxLanguage->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(ComboBoxLanguage);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(FormCommonSettings);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxProfileInfo = new QComboBox(FormCommonSettings);
        comboBoxProfileInfo->setObjectName(QString::fromUtf8("comboBoxProfileInfo"));

        horizontalLayout_2->addWidget(comboBoxProfileInfo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        labelIcons8 = new QLabel(FormCommonSettings);
        labelIcons8->setObjectName(QString::fromUtf8("labelIcons8"));
        QFont font;
        font.setPointSize(10);
        labelIcons8->setFont(font);
        labelIcons8->setTextFormat(Qt::RichText);
        labelIcons8->setWordWrap(true);
        labelIcons8->setOpenExternalLinks(true);
        labelIcons8->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout->addWidget(labelIcons8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FormCommonSettings);

        QMetaObject::connectSlotsByName(FormCommonSettings);
    } // setupUi

    void retranslateUi(QWidget *FormCommonSettings)
    {
        FormCommonSettings->setWindowTitle(QCoreApplication::translate("FormCommonSettings", "Form", nullptr));
        label_12->setText(QCoreApplication::translate("FormCommonSettings", "\320\242\320\265\320\274\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("FormCommonSettings", "\320\257\320\267\321\213\320\272", nullptr));
        label->setText(QCoreApplication::translate("FormCommonSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\277\321\200\320\276\321\204\320\270\320\273\320\265", nullptr));
        labelIcons8->setText(QCoreApplication::translate("FormCommonSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\201\320\260\320\271\321\202\320\276\320\274 <a href=https://icons8.ru/icons>https://icons8.ru/icons</a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCommonSettings: public Ui_FormCommonSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOMMONSETTINGS_H
