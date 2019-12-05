/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *GroupBoxTheme;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *RadioButtonDarkTheme;
    QRadioButton *RadioButtonLightTheme;
    QRadioButton *RadioButtonCustomTheme;
    QLabel *label_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButtonLanguageEnglish;
    QRadioButton *RadioButtonLanguageRussian;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_3;
    QCheckBox *CheckBoxVisibleHiddenGames;
    QLabel *label_10;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(676, 496);
        formLayout = new QFormLayout(FormSettings);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        GroupBoxTheme = new QGroupBox(FormSettings);
        GroupBoxTheme->setObjectName(QString::fromUtf8("GroupBoxTheme"));
        verticalLayout_2 = new QVBoxLayout(GroupBoxTheme);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RadioButtonDarkTheme = new QRadioButton(GroupBoxTheme);
        RadioButtonDarkTheme->setObjectName(QString::fromUtf8("RadioButtonDarkTheme"));

        verticalLayout_2->addWidget(RadioButtonDarkTheme);

        RadioButtonLightTheme = new QRadioButton(GroupBoxTheme);
        RadioButtonLightTheme->setObjectName(QString::fromUtf8("RadioButtonLightTheme"));

        verticalLayout_2->addWidget(RadioButtonLightTheme);

        RadioButtonCustomTheme = new QRadioButton(GroupBoxTheme);
        RadioButtonCustomTheme->setObjectName(QString::fromUtf8("RadioButtonCustomTheme"));
        RadioButtonCustomTheme->setEnabled(false);

        verticalLayout_2->addWidget(RadioButtonCustomTheme);

        label_12 = new QLabel(GroupBoxTheme);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setWordWrap(true);

        verticalLayout_2->addWidget(label_12);


        verticalLayout_5->addWidget(GroupBoxTheme);

        groupBox = new QGroupBox(FormSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RadioButtonLanguageEnglish = new QRadioButton(groupBox);
        RadioButtonLanguageEnglish->setObjectName(QString::fromUtf8("RadioButtonLanguageEnglish"));

        verticalLayout->addWidget(RadioButtonLanguageEnglish);

        RadioButtonLanguageRussian = new QRadioButton(groupBox);
        RadioButtonLanguageRussian->setObjectName(QString::fromUtf8("RadioButtonLanguageRussian"));

        verticalLayout->addWidget(RadioButtonLanguageRussian);


        verticalLayout_5->addWidget(groupBox);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_11 = new QLabel(FormSettings);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_6 = new QLabel(FormSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_8 = new QLabel(FormSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(FormSettings);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_2 = new QLabel(FormSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        label_4 = new QLabel(FormSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(FormSettings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setStrikeOut(true);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        label = new QLabel(FormSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        label_7 = new QLabel(FormSettings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        label_3 = new QLabel(FormSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);


        verticalLayout_6->addLayout(verticalLayout_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_6);

        CheckBoxVisibleHiddenGames = new QCheckBox(FormSettings);
        CheckBoxVisibleHiddenGames->setObjectName(QString::fromUtf8("CheckBoxVisibleHiddenGames"));

        formLayout->setWidget(1, QFormLayout::LabelRole, CheckBoxVisibleHiddenGames);

        label_10 = new QLabel(FormSettings);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font1;
        font1.setPointSize(10);
        label_10->setFont(font1);
        label_10->setWordWrap(true);

        formLayout->setWidget(2, QFormLayout::SpanningRole, label_10);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", nullptr));
        GroupBoxTheme->setTitle(QApplication::translate("FormSettings", "\320\242\320\265\320\274\320\260", nullptr));
        RadioButtonDarkTheme->setText(QApplication::translate("FormSettings", "\320\242\321\221\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonLightTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        RadioButtonCustomTheme->setText(QApplication::translate("FormSettings", "\320\241\320\262\320\276\321\217 \321\202\320\265\320\274\320\260 (\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265)", nullptr));
        label_12->setText(QApplication::translate("FormSettings", "\320\237\320\276\321\202\320\276\320\274 \320\261\321\203\320\264\320\265\321\202 \320\262\320\270\320\267\321\203\320\260\320\273\321\214\320\275\320\276 \320\277\320\276\320\272\320\260\320\267\320\260\320\275\320\276 \320\272\320\260\320\272 \320\262\321\213\320\263\320\273\321\217\320\264\321\217\321\202 \321\202\320\265\320\274\321\213", nullptr));
        groupBox->setTitle(QApplication::translate("FormSettings", "Language", nullptr));
        RadioButtonLanguageEnglish->setText(QApplication::translate("FormSettings", "English", nullptr));
        RadioButtonLanguageRussian->setText(QApplication::translate("FormSettings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        label_11->setText(QApplication::translate("FormSettings", "\320\224\320\276\321\201\321\202\320\260\321\202\321\214 \320\270\320\263\321\200\321\203 \320\270\320\267 \321\207\321\201", nullptr));
        label_6->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\204\320\276\320\275\320\276\320\262\321\203\321\216 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203 ?", nullptr));
        label_8->setText(QApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\275\320\260\321\202\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("FormSettings", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202", nullptr));
        label_2->setText(QApplication::translate("FormSettings", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272, \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271, \320\277\321\200\320\276\321\207\320\265\320\263\320\276", nullptr));
        label_4->setText(QApplication::translate("FormSettings", "\320\241\320\261\321\200\320\276\321\201 \320\272 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\320\274 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274", nullptr));
        label_5->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        label->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        label_7->setText(QApplication::translate("FormSettings", "\320\241\321\201\321\213\320\273\320\272\320\260 \320\275\320\260 icons8", nullptr));
        label_3->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\270\320\273\320\270 \320\275\320\265\321\202 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213 \320\277\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265", nullptr));
        CheckBoxVisibleHiddenGames->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213 \320\277\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265", nullptr));
        label_10->setText(QApplication::translate("FormSettings", "<html><head/><body><p>\320\230\320\272\320\276\320\275\320\272\320\270 \320\264\320\273\321\217 \321\215\321\202\320\276\320\263\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\261\321\213\320\273\320\270 \320\262\320\267\321\217\321\202\321\213 \320\261\320\265\321\201\320\277\320\273\320\260\321\202\320\275\320\276 \321\201 \321\201\320\260\320\271\321\202\320\260 <span style=\" color:#55aa00;\">https://icons8.ru/icons</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
