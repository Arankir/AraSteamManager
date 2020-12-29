/********************************************************************************
** Form generated from reading UI file 'formfrienditemcompare.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDITEMCOMPARE_H
#define UI_FORMFRIENDITEMCOMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "forms/subForms/achievements/widgets/formreachedfilter.h"

QT_BEGIN_NAMESPACE

class Ui_FormFriendItemCompare
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelName;
    QSpacerItem *horizontalSpacer;
    FormReachedFilter *Filter;
    QLabel *LabelPercent;
    QPushButton *ButtonDelete;

    void setupUi(QWidget *FormFriendItemCompare)
    {
        if (FormFriendItemCompare->objectName().isEmpty())
            FormFriendItemCompare->setObjectName(QString::fromUtf8("FormFriendItemCompare"));
        FormFriendItemCompare->resize(223, 39);
        horizontalLayout = new QHBoxLayout(FormFriendItemCompare);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LabelName = new QLabel(FormFriendItemCompare);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));

        horizontalLayout->addWidget(LabelName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Filter = new FormReachedFilter(FormFriendItemCompare);
        Filter->setObjectName(QString::fromUtf8("Filter"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Filter->sizePolicy().hasHeightForWidth());
        Filter->setSizePolicy(sizePolicy);
        Filter->setMinimumSize(QSize(50, 0));
        Filter->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(Filter);

        LabelPercent = new QLabel(FormFriendItemCompare);
        LabelPercent->setObjectName(QString::fromUtf8("LabelPercent"));
        LabelPercent->setMinimumSize(QSize(50, 0));
        LabelPercent->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(LabelPercent);

        ButtonDelete = new QPushButton(FormFriendItemCompare);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));

        horizontalLayout->addWidget(ButtonDelete);


        retranslateUi(FormFriendItemCompare);

        QMetaObject::connectSlotsByName(FormFriendItemCompare);
    } // setupUi

    void retranslateUi(QWidget *FormFriendItemCompare)
    {
        FormFriendItemCompare->setWindowTitle(QCoreApplication::translate("FormFriendItemCompare", "Form", nullptr));
        LabelName->setText(QString());
        LabelPercent->setText(QString());
        ButtonDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormFriendItemCompare: public Ui_FormFriendItemCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDITEMCOMPARE_H
