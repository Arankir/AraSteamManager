/********************************************************************************
** Form generated from reading UI file 'formimportitem.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMPORTITEM_H
#define UI_FORMIMPORTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/lineEdit/mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_FormImportItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QLabel *labelIcon;
    QLabel *labelTitle;
    QFrame *frameProfile;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelProfileIcon;
    QLabel *labelProfileName;
    QHBoxLayout *horizontalLayout_2;
    MyLineEdit *lineEditProfile;
    QPushButton *pushButtonFindProfile;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelType;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FormImportItem)
    {
        if (FormImportItem->objectName().isEmpty())
            FormImportItem->setObjectName(QString::fromUtf8("FormImportItem"));
        FormImportItem->resize(278, 126);
        verticalLayout_2 = new QVBoxLayout(FormImportItem);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox = new QCheckBox(FormImportItem);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(checkBox);

        labelIcon = new QLabel(FormImportItem);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy1);
        labelIcon->setMinimumSize(QSize(32, 32));

        horizontalLayout_3->addWidget(labelIcon);

        labelTitle = new QLabel(FormImportItem);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy2);
        labelTitle->setWordWrap(true);

        horizontalLayout_3->addWidget(labelTitle);

        frameProfile = new QFrame(FormImportItem);
        frameProfile->setObjectName(QString::fromUtf8("frameProfile"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frameProfile->sizePolicy().hasHeightForWidth());
        frameProfile->setSizePolicy(sizePolicy3);
        frameProfile->setFrameShape(QFrame::StyledPanel);
        frameProfile->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameProfile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelProfileIcon = new QLabel(frameProfile);
        labelProfileIcon->setObjectName(QString::fromUtf8("labelProfileIcon"));
        sizePolicy3.setHeightForWidth(labelProfileIcon->sizePolicy().hasHeightForWidth());
        labelProfileIcon->setSizePolicy(sizePolicy3);
        labelProfileIcon->setMinimumSize(QSize(32, 32));

        horizontalLayout->addWidget(labelProfileIcon);

        labelProfileName = new QLabel(frameProfile);
        labelProfileName->setObjectName(QString::fromUtf8("labelProfileName"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelProfileName->sizePolicy().hasHeightForWidth());
        labelProfileName->setSizePolicy(sizePolicy4);
        labelProfileName->setWordWrap(true);

        horizontalLayout->addWidget(labelProfileName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditProfile = new MyLineEdit(frameProfile);
        lineEditProfile->setObjectName(QString::fromUtf8("lineEditProfile"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEditProfile->sizePolicy().hasHeightForWidth());
        lineEditProfile->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(lineEditProfile);

        pushButtonFindProfile = new QPushButton(frameProfile);
        pushButtonFindProfile->setObjectName(QString::fromUtf8("pushButtonFindProfile"));
        sizePolicy.setHeightForWidth(pushButtonFindProfile->sizePolicy().hasHeightForWidth());
        pushButtonFindProfile->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButtonFindProfile);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(frameProfile);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelType = new QLabel(FormImportItem);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        QFont font;
        font.setPointSize(7);
        labelType->setFont(font);
        labelType->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(labelType);

        horizontalSpacer_2 = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(FormImportItem);

        QMetaObject::connectSlotsByName(FormImportItem);
    } // setupUi

    void retranslateUi(QWidget *FormImportItem)
    {
        FormImportItem->setWindowTitle(QCoreApplication::translate("FormImportItem", "Form", nullptr));
        checkBox->setText(QString());
        labelIcon->setText(QString());
        labelTitle->setText(QCoreApplication::translate("FormImportItem", "Title", nullptr));
        labelProfileIcon->setText(QString());
        labelProfileName->setText(QCoreApplication::translate("FormImportItem", "Name", nullptr));
        pushButtonFindProfile->setText(QString());
        labelType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormImportItem: public Ui_FormImportItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMPORTITEM_H
