/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *FrameTitleWindow;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelLogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonMinimize;
    QPushButton *ButtonMaximize;
    QPushButton *ButtonExit;
    QFrame *line;
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
    QProgressBar *FormProgressBar;
    QStackedWidget *StackedWidgetForms;
    QWidget *None;
    QGridLayout *gridLayout;
    QScrollArea *ScrollAreaNone;
    QWidget *scrollAreaWidgetContents;
    QWidget *Games;
    QGridLayout *gridLayout_2;
    QScrollArea *ScrollAreaGames;
    QWidget *widget;
    QWidget *Friends;
    QGridLayout *gridLayout_3;
    QScrollArea *ScrollAreaFriends;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *Statistic;
    QGridLayout *gridLayout_4;
    QScrollArea *ScrollAreaStatistic;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *Favorites;
    QGridLayout *gridLayout_5;
    QScrollArea *ScrollAreaFavorites;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *Settings;
    QGridLayout *gridLayout_6;
    QScrollArea *ScrollAreaSettings;
    QWidget *scrollAreaWidgetContents_5;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(479, 623);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, -1);
        FrameTitleWindow = new QFrame(centralWidget);
        FrameTitleWindow->setObjectName(QString::fromUtf8("FrameTitleWindow"));
#if QT_CONFIG(accessibility)
        FrameTitleWindow->setAccessibleName(QString::fromUtf8("TitleWindow"));
#endif // QT_CONFIG(accessibility)
        FrameTitleWindow->setFrameShape(QFrame::StyledPanel);
        FrameTitleWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(FrameTitleWindow);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 0, 3, 0);
        LabelLogo = new QLabel(FrameTitleWindow);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));
        LabelLogo->setText(QString::fromUtf8("Logo"));

        horizontalLayout->addWidget(LabelLogo);

        horizontalSpacer = new QSpacerItem(337, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ButtonMinimize = new QPushButton(FrameTitleWindow);
        ButtonMinimize->setObjectName(QString::fromUtf8("ButtonMinimize"));
        QFont font1;
        font1.setPointSize(10);
        ButtonMinimize->setFont(font1);
        ButtonMinimize->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(ButtonMinimize);

        ButtonMaximize = new QPushButton(FrameTitleWindow);
        ButtonMaximize->setObjectName(QString::fromUtf8("ButtonMaximize"));
        ButtonMaximize->setFont(font1);
        ButtonMaximize->setText(QString::fromUtf8(""));

        horizontalLayout->addWidget(ButtonMaximize);

        ButtonExit = new QPushButton(FrameTitleWindow);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        ButtonExit->setFont(font1);

        horizontalLayout->addWidget(ButtonExit);


        verticalLayout_2->addWidget(FrameTitleWindow);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, 9, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonBack = new QPushButton(centralWidget);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));
        ButtonBack->setFont(font1);

        horizontalLayout_4->addWidget(ButtonBack);

        ButtonNext = new QPushButton(centralWidget);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));
        ButtonNext->setFont(font1);

        horizontalLayout_4->addWidget(ButtonNext);

        ButtonUpdate = new QPushButton(centralWidget);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));
        ButtonUpdate->setFont(font1);

        horizontalLayout_4->addWidget(ButtonUpdate);

        ButtonGoToMyProfile = new QPushButton(centralWidget);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));
        ButtonGoToMyProfile->setFont(font1);

        horizontalLayout_4->addWidget(ButtonGoToMyProfile);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));
        ButtonSettings->setFont(font1);

        horizontalLayout_4->addWidget(ButtonSettings);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setFont(font1);

        horizontalLayout_4->addWidget(LineEditIdProfile);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);
        ButtonFindProfile->setFont(font1);

        horizontalLayout_4->addWidget(ButtonFindProfile);


        verticalLayout->addLayout(horizontalLayout_4);

        StackedWidgetProfiles = new QStackedWidget(centralWidget);
        StackedWidgetProfiles->setObjectName(QString::fromUtf8("StackedWidgetProfiles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StackedWidgetProfiles->sizePolicy().hasHeightForWidth());
        StackedWidgetProfiles->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(StackedWidgetProfiles);

        FormProgressBar = new QProgressBar(centralWidget);
        FormProgressBar->setObjectName(QString::fromUtf8("FormProgressBar"));
        FormProgressBar->setValue(0);

        verticalLayout->addWidget(FormProgressBar);

        StackedWidgetForms = new QStackedWidget(centralWidget);
        StackedWidgetForms->setObjectName(QString::fromUtf8("StackedWidgetForms"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(StackedWidgetForms->sizePolicy().hasHeightForWidth());
        StackedWidgetForms->setSizePolicy(sizePolicy1);
        None = new QWidget();
        None->setObjectName(QString::fromUtf8("None"));
        sizePolicy1.setHeightForWidth(None->sizePolicy().hasHeightForWidth());
        None->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(None);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ScrollAreaNone = new QScrollArea(None);
        ScrollAreaNone->setObjectName(QString::fromUtf8("ScrollAreaNone"));
        ScrollAreaNone->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 459, 229));
        ScrollAreaNone->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(ScrollAreaNone, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(None);
        Games = new QWidget();
        Games->setObjectName(QString::fromUtf8("Games"));
        sizePolicy1.setHeightForWidth(Games->sizePolicy().hasHeightForWidth());
        Games->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(Games);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ScrollAreaGames = new QScrollArea(Games);
        ScrollAreaGames->setObjectName(QString::fromUtf8("ScrollAreaGames"));
        ScrollAreaGames->setWidgetResizable(true);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 459, 229));
        ScrollAreaGames->setWidget(widget);

        gridLayout_2->addWidget(ScrollAreaGames, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Games);
        Friends = new QWidget();
        Friends->setObjectName(QString::fromUtf8("Friends"));
        sizePolicy1.setHeightForWidth(Friends->sizePolicy().hasHeightForWidth());
        Friends->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(Friends);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ScrollAreaFriends = new QScrollArea(Friends);
        ScrollAreaFriends->setObjectName(QString::fromUtf8("ScrollAreaFriends"));
        ScrollAreaFriends->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 98, 28));
        ScrollAreaFriends->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(ScrollAreaFriends, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Friends);
        Statistic = new QWidget();
        Statistic->setObjectName(QString::fromUtf8("Statistic"));
        sizePolicy1.setHeightForWidth(Statistic->sizePolicy().hasHeightForWidth());
        Statistic->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(Statistic);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
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
        sizePolicy1.setHeightForWidth(Favorites->sizePolicy().hasHeightForWidth());
        Favorites->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(Favorites);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        ScrollAreaFavorites = new QScrollArea(Favorites);
        ScrollAreaFavorites->setObjectName(QString::fromUtf8("ScrollAreaFavorites"));
        ScrollAreaFavorites->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 98, 28));
        ScrollAreaFavorites->setWidget(scrollAreaWidgetContents_4);

        gridLayout_5->addWidget(ScrollAreaFavorites, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Favorites);
        Settings = new QWidget();
        Settings->setObjectName(QString::fromUtf8("Settings"));
        sizePolicy1.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(Settings);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        ScrollAreaSettings = new QScrollArea(Settings);
        ScrollAreaSettings->setObjectName(QString::fromUtf8("ScrollAreaSettings"));
        ScrollAreaSettings->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 459, 229));
        ScrollAreaSettings->setWidget(scrollAreaWidgetContents_5);

        gridLayout_6->addWidget(ScrollAreaSettings, 0, 0, 1, 1);

        StackedWidgetForms->addWidget(Settings);

        verticalLayout->addWidget(StackedWidgetForms);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 20));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        StackedWidgetForms->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SteamAchievementsStatistic", nullptr));
        ButtonExit->setText(QString());
        ButtonBack->setText(QString());
        ButtonNext->setText(QString());
        ButtonUpdate->setText(QString());
        ButtonGoToMyProfile->setText(QString());
        ButtonSettings->setText(QString());
        LineEditIdProfile->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 Steamid", nullptr));
        ButtonFindProfile->setText(QCoreApplication::translate("MainWindow", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        FormProgressBar->setFormat(QCoreApplication::translate("MainWindow", "%v/%m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
