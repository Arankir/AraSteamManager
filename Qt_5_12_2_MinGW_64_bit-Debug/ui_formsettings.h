/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButtonLanguageEnglish;
    QRadioButton *RadioButtonLanguageRussian;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(676, 496);
        label = new QLabel(FormSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 40, 181, 16));
        QFont font;
        font.setStrikeOut(true);
        label->setFont(font);
        label_2 = new QLabel(FormSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 140, 331, 16));
        label_3 = new QLabel(FormSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 180, 261, 16));
        label_4 = new QLabel(FormSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 160, 181, 16));
        label_5 = new QLabel(FormSettings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 20, 181, 16));
        label_6 = new QLabel(FormSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 60, 181, 16));
        label_7 = new QLabel(FormSettings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 80, 181, 16));
        label_8 = new QLabel(FormSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(280, 100, 181, 16));
        label_9 = new QLabel(FormSettings);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 120, 181, 16));
        label_11 = new QLabel(FormSettings);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(280, 200, 181, 16));
        groupBox = new QGroupBox(FormSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 108, 85));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RadioButtonLanguageEnglish = new QRadioButton(groupBox);
        RadioButtonLanguageEnglish->setObjectName(QString::fromUtf8("RadioButtonLanguageEnglish"));

        verticalLayout->addWidget(RadioButtonLanguageEnglish);

        RadioButtonLanguageRussian = new QRadioButton(groupBox);
        RadioButtonLanguageRussian->setObjectName(QString::fromUtf8("RadioButtonLanguageRussian"));

        verticalLayout->addWidget(RadioButtonLanguageRussian);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", nullptr));
        label->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        label_2->setText(QApplication::translate("FormSettings", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272, \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271, \320\277\321\200\320\276\321\207\320\265\320\263\320\276", nullptr));
        label_3->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\270\320\273\320\270 \320\275\320\265\321\202 \321\201\320\272\321\200\321\213\321\202\321\213\320\265 \320\270\320\263\321\200\321\213 \320\277\321\200\320\270 \320\277\320\276\320\270\321\201\320\272\320\265", nullptr));
        label_4->setText(QApplication::translate("FormSettings", "\320\241\320\261\321\200\320\276\321\201 \320\272 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\320\274 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274", nullptr));
        label_5->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        label_6->setText(QApplication::translate("FormSettings", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\204\320\276\320\275\320\276\320\262\321\203\321\216 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203 ?", nullptr));
        label_7->setText(QApplication::translate("FormSettings", "\320\241\321\201\321\213\320\273\320\272\320\260 \320\275\320\260 icons8", nullptr));
        label_8->setText(QApplication::translate("FormSettings", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\275\320\260\321\202\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("FormSettings", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202", nullptr));
        label_11->setText(QApplication::translate("FormSettings", "\320\224\320\276\321\201\321\202\320\260\321\202\321\214 \320\270\320\263\321\200\321\203 \320\270\320\267 \321\207\321\201", nullptr));
        groupBox->setTitle(QApplication::translate("FormSettings", "Language", nullptr));
        RadioButtonLanguageEnglish->setText(QApplication::translate("FormSettings", "English", nullptr));
        RadioButtonLanguageRussian->setText(QApplication::translate("FormSettings", "Russian", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
