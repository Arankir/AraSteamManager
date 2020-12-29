/********************************************************************************
** Form generated from reading UI file 'formgroups.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGROUPS_H
#define UI_FORMGROUPS_H

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

class Ui_FormGroups
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

    void setupUi(QWidget *FormGroups)
    {
        if (FormGroups->objectName().isEmpty())
            FormGroups->setObjectName(QString::fromUtf8("FormGroups"));
        FormGroups->resize(305, 384);
        verticalLayout = new QVBoxLayout(FormGroups);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelTitle = new QLabel(FormGroups);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));

        verticalLayout->addWidget(LabelTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditAddTitle = new QLineEdit(FormGroups);
        LineEditAddTitle->setObjectName(QString::fromUtf8("LineEditAddTitle"));

        horizontalLayout->addWidget(LineEditAddTitle);

        ButtonAdd = new QPushButton(FormGroups);
        ButtonAdd->setObjectName(QString::fromUtf8("ButtonAdd"));

        horizontalLayout->addWidget(ButtonAdd);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ComboBoxGroups = new QComboBox(FormGroups);
        ComboBoxGroups->setObjectName(QString::fromUtf8("ComboBoxGroups"));

        horizontalLayout_3->addWidget(ComboBoxGroups);

        LineEditChangeTitle = new QLineEdit(FormGroups);
        LineEditChangeTitle->setObjectName(QString::fromUtf8("LineEditChangeTitle"));

        horizontalLayout_3->addWidget(LineEditChangeTitle);

        ButtonChangeTitle = new QPushButton(FormGroups);
        ButtonChangeTitle->setObjectName(QString::fromUtf8("ButtonChangeTitle"));

        horizontalLayout_3->addWidget(ButtonChangeTitle);


        verticalLayout->addLayout(horizontalLayout_3);

        ScrollAreaGroups = new QScrollArea(FormGroups);
        ScrollAreaGroups->setObjectName(QString::fromUtf8("ScrollAreaGroups"));
        ScrollAreaGroups->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 285, 256));
        ScrollAreaGroups->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(ScrollAreaGroups);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonCancel = new QPushButton(FormGroups);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));

        horizontalLayout_2->addWidget(ButtonCancel);

        ButtonApply = new QPushButton(FormGroups);
        ButtonApply->setObjectName(QString::fromUtf8("ButtonApply"));

        horizontalLayout_2->addWidget(ButtonApply);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormGroups);

        QMetaObject::connectSlotsByName(FormGroups);
    } // setupUi

    void retranslateUi(QWidget *FormGroups)
    {
        FormGroups->setWindowTitle(QCoreApplication::translate("FormGroups", "Form", nullptr));
        LabelTitle->setText(QString());
        ButtonAdd->setText(QCoreApplication::translate("FormGroups", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        ButtonChangeTitle->setText(QCoreApplication::translate("FormGroups", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        ButtonCancel->setText(QCoreApplication::translate("FormGroups", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        ButtonApply->setText(QCoreApplication::translate("FormGroups", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGroups: public Ui_FormGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGROUPS_H
