/********************************************************************************
** Form generated from reading UI file 'formgroups.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGROUPS_H
#define UI_FORMGROUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGroups
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelIcon;
    QLabel *LabelTitle;
    QListWidget *listWidgetGroups;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonCancel;
    QPushButton *ButtonApply;

    void setupUi(QWidget *FormGroups)
    {
        if (FormGroups->objectName().isEmpty())
            FormGroups->setObjectName(QString::fromUtf8("FormGroups"));
        FormGroups->resize(300, 327);
        verticalLayout = new QVBoxLayout(FormGroups);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelIcon = new QLabel(FormGroups);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));

        horizontalLayout_4->addWidget(labelIcon);

        LabelTitle = new QLabel(FormGroups);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelTitle->sizePolicy().hasHeightForWidth());
        LabelTitle->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(LabelTitle);


        verticalLayout->addLayout(horizontalLayout_4);

        listWidgetGroups = new QListWidget(FormGroups);
        listWidgetGroups->setObjectName(QString::fromUtf8("listWidgetGroups"));

        verticalLayout->addWidget(listWidgetGroups);

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
        labelIcon->setText(QString());
        LabelTitle->setText(QString());
        ButtonCancel->setText(QCoreApplication::translate("FormGroups", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        ButtonApply->setText(QCoreApplication::translate("FormGroups", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGroups: public Ui_FormGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGROUPS_H
