/********************************************************************************
** Form generated from reading UI file 'formgroupsgamesinteractions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGROUPSGAMESINTERACTIONS_H
#define UI_FORMGROUPSGAMESINTERACTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGroupsGamesInteractions
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LabelTitle;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditAddTitle;
    QPushButton *ButtonAdd;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *ComboBoxGroups;
    QLineEdit *LineEditChangeTitle;
    QPushButton *ButtonChangeTitle;
    QScrollArea *ScrollAreaGroups;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonCancel;
    QPushButton *ButtonApply;

    void setupUi(QWidget *FormGroupsGamesInteractions)
    {
        if (FormGroupsGamesInteractions->objectName().isEmpty())
            FormGroupsGamesInteractions->setObjectName(QString::fromUtf8("FormGroupsGamesInteractions"));
        FormGroupsGamesInteractions->resize(305, 384);
        verticalLayout = new QVBoxLayout(FormGroupsGamesInteractions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelTitle = new QLabel(FormGroupsGamesInteractions);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));

        verticalLayout->addWidget(LabelTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditAddTitle = new QLineEdit(FormGroupsGamesInteractions);
        LineEditAddTitle->setObjectName(QString::fromUtf8("LineEditAddTitle"));

        horizontalLayout->addWidget(LineEditAddTitle);

        ButtonAdd = new QPushButton(FormGroupsGamesInteractions);
        ButtonAdd->setObjectName(QString::fromUtf8("ButtonAdd"));

        horizontalLayout->addWidget(ButtonAdd);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ComboBoxGroups = new QComboBox(FormGroupsGamesInteractions);
        ComboBoxGroups->setObjectName(QString::fromUtf8("ComboBoxGroups"));

        horizontalLayout_3->addWidget(ComboBoxGroups);

        LineEditChangeTitle = new QLineEdit(FormGroupsGamesInteractions);
        LineEditChangeTitle->setObjectName(QString::fromUtf8("LineEditChangeTitle"));

        horizontalLayout_3->addWidget(LineEditChangeTitle);

        ButtonChangeTitle = new QPushButton(FormGroupsGamesInteractions);
        ButtonChangeTitle->setObjectName(QString::fromUtf8("ButtonChangeTitle"));

        horizontalLayout_3->addWidget(ButtonChangeTitle);


        verticalLayout->addLayout(horizontalLayout_3);

        ScrollAreaGroups = new QScrollArea(FormGroupsGamesInteractions);
        ScrollAreaGroups->setObjectName(QString::fromUtf8("ScrollAreaGroups"));
        ScrollAreaGroups->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 285, 256));
        ScrollAreaGroups->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(ScrollAreaGroups);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonCancel = new QPushButton(FormGroupsGamesInteractions);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));

        horizontalLayout_2->addWidget(ButtonCancel);

        ButtonApply = new QPushButton(FormGroupsGamesInteractions);
        ButtonApply->setObjectName(QString::fromUtf8("ButtonApply"));

        horizontalLayout_2->addWidget(ButtonApply);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormGroupsGamesInteractions);

        QMetaObject::connectSlotsByName(FormGroupsGamesInteractions);
    } // setupUi

    void retranslateUi(QWidget *FormGroupsGamesInteractions)
    {
        FormGroupsGamesInteractions->setWindowTitle(QCoreApplication::translate("FormGroupsGamesInteractions", "Form", nullptr));
        LabelTitle->setText(QString());
        ButtonAdd->setText(QCoreApplication::translate("FormGroupsGamesInteractions", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        ButtonChangeTitle->setText(QCoreApplication::translate("FormGroupsGamesInteractions", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        ButtonCancel->setText(QCoreApplication::translate("FormGroupsGamesInteractions", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        ButtonApply->setText(QCoreApplication::translate("FormGroupsGamesInteractions", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGroupsGamesInteractions: public Ui_FormGroupsGamesInteractions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGROUPSGAMESINTERACTIONS_H
