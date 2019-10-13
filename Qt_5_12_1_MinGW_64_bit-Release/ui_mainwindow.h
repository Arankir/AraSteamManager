/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *ScrollAreaForm;
    QWidget *FormsWidget;
    QPushButton *ButtonBack;
    QLabel *LabelLogo;
    QScrollArea *ScrollAreaProfileInfo;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *LabelBans;
    QPushButton *ButtonFriends;
    QLabel *LabelAvatar;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QPushButton *ButtonFavorites;
    QPushButton *ButtonGames;
    QLabel *LabelProfileVisibility;
    QLabel *LabelProfileUrl;
    QLabel *LabelTimeCreated;
    QLabel *Labellvl;
    QPushButton *ButtonStatistics;
    QLabel *LabelNick;
    QLabel *LabelLocCountryCode;
    QLabel *LabelPersonaState;
    QPushButton *ButtonGoToMyProfile;
    QLabel *LabelRealName;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonExit;
    QLineEdit *LineEditIdProfile;
    QPushButton *ButtonFindProfile;
    QSpacerItem *verticalSpacer;
    QPushButton *ButtonSettings;
    QPushButton *ButtonNext;
    QPushButton *ButtonSetProfile;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(659, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ScrollAreaForm = new QScrollArea(centralWidget);
        ScrollAreaForm->setObjectName(QString::fromUtf8("ScrollAreaForm"));
        ScrollAreaForm->setWidgetResizable(true);
        FormsWidget = new QWidget();
        FormsWidget->setObjectName(QString::fromUtf8("FormsWidget"));
        FormsWidget->setGeometry(QRect(0, 0, 632, 198));
        ScrollAreaForm->setWidget(FormsWidget);

        gridLayout->addWidget(ScrollAreaForm, 5, 0, 1, 10);

        ButtonBack = new QPushButton(centralWidget);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));

        gridLayout->addWidget(ButtonBack, 1, 0, 1, 1);

        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 3);

        ScrollAreaProfileInfo = new QScrollArea(centralWidget);
        ScrollAreaProfileInfo->setObjectName(QString::fromUtf8("ScrollAreaProfileInfo"));
        ScrollAreaProfileInfo->setMinimumSize(QSize(0, 190));
        ScrollAreaProfileInfo->setMaximumSize(QSize(16777215, 190));
        ScrollAreaProfileInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollAreaProfileInfo->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 632, 188));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        LabelBans = new QLabel(scrollAreaWidgetContents);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        QFont font;
        font.setPointSize(10);
        LabelBans->setFont(font);
        LabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(LabelBans, 8, 4, 1, 2);

        ButtonFriends = new QPushButton(scrollAreaWidgetContents);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        gridLayout_2->addWidget(ButtonFriends, 9, 2, 1, 3);

        LabelAvatar = new QLabel(scrollAreaWidgetContents);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setMaximumSize(QSize(64, 64));

        gridLayout_2->addWidget(LabelAvatar, 1, 0, 3, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 7, 1, 2);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 6, 3, 3, 1);

        ButtonFavorites = new QPushButton(scrollAreaWidgetContents);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        gridLayout_2->addWidget(ButtonFavorites, 9, 5, 1, 1);

        ButtonGames = new QPushButton(scrollAreaWidgetContents);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);

        gridLayout_2->addWidget(ButtonGames, 9, 0, 1, 2);

        LabelProfileVisibility = new QLabel(scrollAreaWidgetContents);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        LabelProfileVisibility->setFont(font);

        gridLayout_2->addWidget(LabelProfileVisibility, 8, 0, 1, 3);

        LabelProfileUrl = new QLabel(scrollAreaWidgetContents);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        LabelProfileUrl->setFont(font);
        LabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout_2->addWidget(LabelProfileUrl, 3, 1, 1, 5);

        LabelTimeCreated = new QLabel(scrollAreaWidgetContents);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font);

        gridLayout_2->addWidget(LabelTimeCreated, 7, 0, 1, 3);

        Labellvl = new QLabel(scrollAreaWidgetContents);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font);

        gridLayout_2->addWidget(Labellvl, 6, 0, 1, 3);

        ButtonStatistics = new QPushButton(scrollAreaWidgetContents);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        gridLayout_2->addWidget(ButtonStatistics, 9, 6, 1, 1);

        LabelNick = new QLabel(scrollAreaWidgetContents);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font1.setPointSize(14);
        LabelNick->setFont(font1);
        LabelNick->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 0)"));

        gridLayout_2->addWidget(LabelNick, 1, 1, 1, 2);

        LabelLocCountryCode = new QLabel(scrollAreaWidgetContents);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font);

        gridLayout_2->addWidget(LabelLocCountryCode, 7, 4, 1, 2);

        LabelPersonaState = new QLabel(scrollAreaWidgetContents);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        LabelPersonaState->setFont(font);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(LabelPersonaState, 2, 1, 1, 5);

        ButtonGoToMyProfile = new QPushButton(scrollAreaWidgetContents);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        gridLayout_2->addWidget(ButtonGoToMyProfile, 9, 8, 1, 1);

        LabelRealName = new QLabel(scrollAreaWidgetContents);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font);

        gridLayout_2->addWidget(LabelRealName, 6, 4, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 9, 7, 1, 1);

        ScrollAreaProfileInfo->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(ScrollAreaProfileInfo, 3, 0, 1, 10);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        gridLayout->addWidget(ButtonExit, 0, 8, 1, 2);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(LineEditIdProfile, 2, 0, 1, 8);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(ButtonFindProfile, 2, 8, 1, 2);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 10, 1, 1);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        gridLayout->addWidget(ButtonSettings, 1, 2, 1, 1);

        ButtonNext = new QPushButton(centralWidget);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));

        gridLayout->addWidget(ButtonNext, 1, 1, 1, 1);

        ButtonSetProfile = new QPushButton(centralWidget);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout->addWidget(ButtonSetProfile, 1, 7, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 6, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SteamAchievementsStatistic", nullptr));
        ButtonBack->setText(QApplication::translate("MainWindow", "Back", nullptr));
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        ButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        LabelProfileVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        ButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        LabelNick->setText(QApplication::translate("MainWindow", "NickName", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "Go to my profile", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        ButtonExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        ButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        ButtonNext->setText(QApplication::translate("MainWindow", "Next", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
