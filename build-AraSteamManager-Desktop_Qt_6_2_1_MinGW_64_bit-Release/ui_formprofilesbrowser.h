/********************************************************************************
** Form generated from reading UI file 'formprofilesbrowser.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROFILESBROWSER_H
#define UI_FORMPROFILESBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/lineEdit/mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_FormProfilesBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonBack;
    QPushButton *ButtonNext;
    QPushButton *ButtonUpdate;
    QPushButton *ButtonGoToMyProfile;
    QPushButton *ButtonFavorites;
    QPushButton *ButtonSettings;
    MyLineEdit *LineEditIdProfile;
    QPushButton *ButtonFindProfile;
    QStackedWidget *StackedWidgetProfiles;

    void setupUi(QWidget *FormProfilesBrowser)
    {
        if (FormProfilesBrowser->objectName().isEmpty())
            FormProfilesBrowser->setObjectName(QString::fromUtf8("FormProfilesBrowser"));
        FormProfilesBrowser->resize(498, 34);
        verticalLayout = new QVBoxLayout(FormProfilesBrowser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonBack = new QPushButton(FormProfilesBrowser);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));
        QFont font;
        font.setPointSize(10);
        ButtonBack->setFont(font);

        horizontalLayout_4->addWidget(ButtonBack);

        ButtonNext = new QPushButton(FormProfilesBrowser);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));
        ButtonNext->setFont(font);

        horizontalLayout_4->addWidget(ButtonNext);

        ButtonUpdate = new QPushButton(FormProfilesBrowser);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        ButtonUpdate->setFont(font);

        horizontalLayout_4->addWidget(ButtonUpdate);

        ButtonGoToMyProfile = new QPushButton(FormProfilesBrowser);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));
        ButtonGoToMyProfile->setFont(font);

        horizontalLayout_4->addWidget(ButtonGoToMyProfile);

        ButtonFavorites = new QPushButton(FormProfilesBrowser);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        horizontalLayout_4->addWidget(ButtonFavorites);

        ButtonSettings = new QPushButton(FormProfilesBrowser);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));
        ButtonSettings->setFont(font);

        horizontalLayout_4->addWidget(ButtonSettings);

        LineEditIdProfile = new MyLineEdit(FormProfilesBrowser);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setFont(font);

        horizontalLayout_4->addWidget(LineEditIdProfile);

        ButtonFindProfile = new QPushButton(FormProfilesBrowser);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);
        ButtonFindProfile->setFont(font);

        horizontalLayout_4->addWidget(ButtonFindProfile);


        verticalLayout->addLayout(horizontalLayout_4);

        StackedWidgetProfiles = new QStackedWidget(FormProfilesBrowser);
        StackedWidgetProfiles->setObjectName(QString::fromUtf8("StackedWidgetProfiles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StackedWidgetProfiles->sizePolicy().hasHeightForWidth());
        StackedWidgetProfiles->setSizePolicy(sizePolicy);
        StackedWidgetProfiles->setLineWidth(0);

        verticalLayout->addWidget(StackedWidgetProfiles);


        retranslateUi(FormProfilesBrowser);

        QMetaObject::connectSlotsByName(FormProfilesBrowser);
    } // setupUi

    void retranslateUi(QWidget *FormProfilesBrowser)
    {
        FormProfilesBrowser->setWindowTitle(QCoreApplication::translate("FormProfilesBrowser", "Form", nullptr));
        ButtonBack->setText(QString());
        ButtonNext->setText(QString());
        ButtonUpdate->setText(QString());
        ButtonGoToMyProfile->setText(QString());
        ButtonFavorites->setText(QString());
        ButtonSettings->setText(QString());
        LineEditIdProfile->setPlaceholderText(QCoreApplication::translate("FormProfilesBrowser", "https://steamcommunity.com/id/gabelogannewell", nullptr));
        ButtonFindProfile->setText(QCoreApplication::translate("FormProfilesBrowser", " \320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfilesBrowser: public Ui_FormProfilesBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILESBROWSER_H
