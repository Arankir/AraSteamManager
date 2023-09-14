/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAIN_H
#define UI_FORMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <forms/main/formfavorites.h>
#include <forms/main/formfriends.h>
#include <forms/main/formgames.h>
#include <forms/main/formsettings.h>
#include "forms/main/formprofilesbrowser.h"
#include "forms/main/formstatistics.h"

QT_BEGIN_NAMESPACE

class Ui_FormMain
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidgetProfiles;
    FormProfilesBrowser *profilesBrowser;
    QStackedWidget *stackedWidgetForms;
    QWidget *none;
    QGridLayout *gridLayout;
    QScrollArea *scrollAreaNone;
    QWidget *scrollAreaWidgetContents;
    QWidget *games;
    QGridLayout *gridLayout_2;
    FormGames *stackedFormGames;
    QWidget *friends;
    QGridLayout *gridLayout_3;
    FormFriends *stackedFormFriends;
    QWidget *statistic;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollAreaStatistic;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    FormStatistics *stackedFormStatistics;
    QWidget *favorites;
    QGridLayout *gridLayout_5;
    FormFavorites *stackedFormFavorites;
    QWidget *settings;
    QGridLayout *gridLayout_6;
    FormSettings *stackedFormSettings;

    void setupUi(QWidget *FormMain)
    {
        if (FormMain->objectName().isEmpty())
            FormMain->setObjectName(QString::fromUtf8("FormMain"));
        FormMain->resize(427, 284);
        verticalLayout = new QVBoxLayout(FormMain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidgetProfiles = new QStackedWidget(FormMain);
        stackedWidgetProfiles->setObjectName(QString::fromUtf8("stackedWidgetProfiles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidgetProfiles->sizePolicy().hasHeightForWidth());
        stackedWidgetProfiles->setSizePolicy(sizePolicy);
        stackedWidgetProfiles->setLineWidth(0);

        verticalLayout->addWidget(stackedWidgetProfiles);

        profilesBrowser = new FormProfilesBrowser(FormMain);
        profilesBrowser->setObjectName(QString::fromUtf8("profilesBrowser"));

        verticalLayout->addWidget(profilesBrowser);

        stackedWidgetForms = new QStackedWidget(FormMain);
        stackedWidgetForms->setObjectName(QString::fromUtf8("stackedWidgetForms"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidgetForms->sizePolicy().hasHeightForWidth());
        stackedWidgetForms->setSizePolicy(sizePolicy1);
        none = new QWidget();
        none->setObjectName(QString::fromUtf8("none"));
        sizePolicy1.setHeightForWidth(none->sizePolicy().hasHeightForWidth());
        none->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(none);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollAreaNone = new QScrollArea(none);
        scrollAreaNone->setObjectName(QString::fromUtf8("scrollAreaNone"));
        scrollAreaNone->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        scrollAreaNone->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollAreaNone, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(none);
        games = new QWidget();
        games->setObjectName(QString::fromUtf8("games"));
        sizePolicy1.setHeightForWidth(games->sizePolicy().hasHeightForWidth());
        games->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(games);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedFormGames = new FormGames(games);
        stackedFormGames->setObjectName(QString::fromUtf8("stackedFormGames"));
        sizePolicy1.setHeightForWidth(stackedFormGames->sizePolicy().hasHeightForWidth());
        stackedFormGames->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(stackedFormGames, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(games);
        friends = new QWidget();
        friends->setObjectName(QString::fromUtf8("friends"));
        sizePolicy1.setHeightForWidth(friends->sizePolicy().hasHeightForWidth());
        friends->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(friends);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedFormFriends = new FormFriends(friends);
        stackedFormFriends->setObjectName(QString::fromUtf8("stackedFormFriends"));

        gridLayout_3->addWidget(stackedFormFriends, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(friends);
        statistic = new QWidget();
        statistic->setObjectName(QString::fromUtf8("statistic"));
        sizePolicy1.setHeightForWidth(statistic->sizePolicy().hasHeightForWidth());
        statistic->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(statistic);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollAreaStatistic = new QScrollArea(statistic);
        scrollAreaStatistic->setObjectName(QString::fromUtf8("scrollAreaStatistic"));
        scrollAreaStatistic->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 98, 28));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedFormStatistics = new FormStatistics(scrollAreaWidgetContents_3);
        stackedFormStatistics->setObjectName(QString::fromUtf8("stackedFormStatistics"));
        sizePolicy1.setHeightForWidth(stackedFormStatistics->sizePolicy().hasHeightForWidth());
        stackedFormStatistics->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(stackedFormStatistics);

        scrollAreaStatistic->setWidget(scrollAreaWidgetContents_3);

        gridLayout_4->addWidget(scrollAreaStatistic, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(statistic);
        favorites = new QWidget();
        favorites->setObjectName(QString::fromUtf8("favorites"));
        sizePolicy1.setHeightForWidth(favorites->sizePolicy().hasHeightForWidth());
        favorites->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(favorites);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedFormFavorites = new FormFavorites(favorites);
        stackedFormFavorites->setObjectName(QString::fromUtf8("stackedFormFavorites"));

        gridLayout_5->addWidget(stackedFormFavorites, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(favorites);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        sizePolicy1.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(settings);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        stackedFormSettings = new FormSettings(settings);
        stackedFormSettings->setObjectName(QString::fromUtf8("stackedFormSettings"));

        gridLayout_6->addWidget(stackedFormSettings, 0, 0, 1, 1);

        stackedWidgetForms->addWidget(settings);

        verticalLayout->addWidget(stackedWidgetForms);


        retranslateUi(FormMain);

        stackedWidgetForms->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(FormMain);
    } // setupUi

    void retranslateUi(QWidget *FormMain)
    {
        FormMain->setWindowTitle(QCoreApplication::translate("FormMain", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormMain: public Ui_FormMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
