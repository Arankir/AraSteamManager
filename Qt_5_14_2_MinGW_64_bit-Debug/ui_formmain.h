/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAIN_H
#define UI_FORMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <forms/subForms/main/formfavorites.h>
#include <forms/subForms/main/formfriends.h>
#include <forms/subForms/main/formgames.h>
#include <forms/subForms/main/formsettings.h>
#include <subWidgets/progressBars/progressbargood.h>

QT_BEGIN_NAMESPACE

class Ui_FormMain
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonBack;
    QPushButton *ButtonNext;
    QPushButton *ButtonUpdate;
    QPushButton *ButtonGoToMyProfile;
    QPushButton *ButtonSettings;
    QLineEdit *LineEditIdProfile;
    QPushButton *ButtonFindProfile;
    QStackedWidget *StackedWidgetProfiles;
    ProgressBarGood *FormProgressBar;
    QStackedWidget *StackedWidgetForms;
    QWidget *None;
    QGridLayout *gridLayout;
    QScrollArea *ScrollAreaNone;
    QWidget *scrollAreaWidgetContents;
    QWidget *Games;
    QGridLayout *gridLayout_2;
    FormGames *StackedFormGames;
    QWidget *Friends;
    QGridLayout *gridLayout_3;
    FormFriends *StackedFormFriends;
    QWidget *Statistic;
    QGridLayout *gridLayout_4;
    QScrollArea *ScrollAreaStatistic;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *Favorites;
    QGridLayout *gridLayout_5;
    FormFavorites *StackedFormFavorites;
    QWidget *Settings;
    QGridLayout *gridLayout_6;
    FormSettings *StackedFormSettings;

    void setupUi(QWidget *FormMain)
    {
        if (FormMain->objectName().isEmpty())
            FormMain->setObjectName(QString::fromUtf8("FormMain"));
        FormMain->resize(564, 544);
        verticalLayout_2 = new QVBoxLayout(FormMain);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 6, 9, 6);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonBack = new QPushButton(FormMain);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));
        QFont font;
        font.setPointSize(10);
        ButtonBack->setFont(font);

        horizontalLayout_4->addWidget(ButtonBack);

        ButtonNext = new QPushButton(FormMain);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));
        ButtonNext->setFont(font);

        horizontalLayout_4->addWidget(ButtonNext);

        ButtonUpdate = new QPushButton(FormMain);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        ButtonUpdate->setFont(font);

        horizontalLayout_4->addWidget(ButtonUpdate);

        ButtonGoToMyProfile = new QPushButton(FormMain);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));
        ButtonGoToMyProfile->setFont(font);

        horizontalLayout_4->addWidget(ButtonGoToMyProfile);

        ButtonSettings = new QPushButton(FormMain);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));
        ButtonSettings->setFont(font);

        horizontalLayout_4->addWidget(ButtonSettings);

        LineEditIdProfile = new QLineEdit(FormMain);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setFont(font);

        horizontalLayout_4->addWidget(LineEditIdProfile);

        ButtonFindProfile = new QPushButton(FormMain);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);
        ButtonFindProfile->setFont(font);

        horizontalLayout_4->addWidget(ButtonFindProfile);


        verticalLayout->addLayout(horizontalLayout_4);

        StackedWidgetProfiles = new QStackedWidget(FormMain);
        StackedWidgetProfiles->setObjectName(QString::fromUtf8("StackedWidgetProfiles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StackedWidgetProfiles->sizePolicy().hasHeightForWidth());
        StackedWidgetProfiles->setSizePolicy(sizePolicy);
        StackedWidgetProfiles->setLineWidth(0);

        verticalLayout->addWidget(StackedWidgetProfiles);

        FormProgressBar = new ProgressBarGood(FormMain);
        FormProgressBar->setObjectName(QString::fromUtf8("FormProgressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(FormProgressBar->sizePolicy().hasHeightForWidth());
        FormProgressBar->setSizePolicy(sizePolicy1);
        FormProgressBar->setValue(0);

        verticalLayout->addWidget(FormProgressBar);

        StackedWidgetForms = new QStackedWidget(FormMain);
        StackedWidgetForms->setObjectName(QString::fromUtf8("StackedWidgetForms"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(StackedWidgetForms->sizePolicy().hasHeightForWidth());
        StackedWidgetForms->setSizePolicy(sizePolicy2);
        None = new QWidget();
        None->setObjectName(QString::fromUtf8("None"));
        sizePolicy2.setHeightForWidth(None->sizePolicy().hasHeightForWidth());
        None->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(None);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ScrollAreaNone = new QScrollArea(None);
        ScrollAreaNone->setObjectName(QString::fromUtf8("ScrollAreaNone"));
        ScrollAreaNone->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 544, 465));
        ScrollAreaNone->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(ScrollAreaNone, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(None);
        Games = new QWidget();
        Games->setObjectName(QString::fromUtf8("Games"));
        sizePolicy2.setHeightForWidth(Games->sizePolicy().hasHeightForWidth());
        Games->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(Games);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        StackedFormGames = new FormGames(Games);
        StackedFormGames->setObjectName(QString::fromUtf8("StackedFormGames"));

        gridLayout_2->addWidget(StackedFormGames, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Games);
        Friends = new QWidget();
        Friends->setObjectName(QString::fromUtf8("Friends"));
        sizePolicy2.setHeightForWidth(Friends->sizePolicy().hasHeightForWidth());
        Friends->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(Friends);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        StackedFormFriends = new FormFriends(Friends);
        StackedFormFriends->setObjectName(QString::fromUtf8("StackedFormFriends"));

        gridLayout_3->addWidget(StackedFormFriends, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Friends);
        Statistic = new QWidget();
        Statistic->setObjectName(QString::fromUtf8("Statistic"));
        sizePolicy2.setHeightForWidth(Statistic->sizePolicy().hasHeightForWidth());
        Statistic->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(Statistic);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        ScrollAreaStatistic = new QScrollArea(Statistic);
        ScrollAreaStatistic->setObjectName(QString::fromUtf8("ScrollAreaStatistic"));
        ScrollAreaStatistic->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 98, 28));
        ScrollAreaStatistic->setWidget(scrollAreaWidgetContents_3);

        gridLayout_4->addWidget(ScrollAreaStatistic, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Statistic);
        Favorites = new QWidget();
        Favorites->setObjectName(QString::fromUtf8("Favorites"));
        sizePolicy2.setHeightForWidth(Favorites->sizePolicy().hasHeightForWidth());
        Favorites->setSizePolicy(sizePolicy2);
        gridLayout_5 = new QGridLayout(Favorites);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        StackedFormFavorites = new FormFavorites(Favorites);
        StackedFormFavorites->setObjectName(QString::fromUtf8("StackedFormFavorites"));

        gridLayout_5->addWidget(StackedFormFavorites, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Favorites);
        Settings = new QWidget();
        Settings->setObjectName(QString::fromUtf8("Settings"));
        sizePolicy2.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy2);
        gridLayout_6 = new QGridLayout(Settings);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        StackedFormSettings = new FormSettings(Settings);
        StackedFormSettings->setObjectName(QString::fromUtf8("StackedFormSettings"));

        gridLayout_6->addWidget(StackedFormSettings, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Settings);

        verticalLayout->addWidget(StackedWidgetForms);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FormMain);

        StackedWidgetForms->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormMain);
    } // setupUi

    void retranslateUi(QWidget *FormMain)
    {
        FormMain->setWindowTitle(QCoreApplication::translate("FormMain", "Form", nullptr));
        ButtonBack->setText(QString());
        ButtonNext->setText(QString());
        ButtonUpdate->setText(QString());
        ButtonGoToMyProfile->setText(QString());
        ButtonSettings->setText(QString());
        LineEditIdProfile->setPlaceholderText(QCoreApplication::translate("FormMain", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 Steamid", nullptr));
        ButtonFindProfile->setText(QCoreApplication::translate("FormMain", " \320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormMain: public Ui_FormMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
