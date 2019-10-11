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
    QPushButton *ButtonStatistics;
    QPushButton *ButtonExit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonGoToMyProfile;
    QPushButton *ButtonSettings;
    QScrollArea *ScrollAreaForm;
    QWidget *FormsWidget;
    QLineEdit *LineEditIdProfile;
    QPushButton *ButtonFriends;
    QPushButton *ButtonSetProfile;
    QPushButton *ButtonFindProfile;
    QPushButton *ButtonGames;
    QPushButton *ButtonFavorites;
    QLabel *LabelLogo;
    QSpacerItem *verticalSpacer;
    QScrollArea *ScrollAreaProfileInfo;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *LabelTimeCreated;
    QLabel *LabelBans;
    QLabel *LabelRealName;
    QLabel *LabelLocCountryCode;
    QLabel *Labellvl;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelProfileVisibility;
    QLabel *LabelAvatar;
    QLabel *LabelNick;
    QLabel *LabelProfileUrl;
    QLabel *LabelPersonaState;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(587, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ButtonStatistics = new QPushButton(centralWidget);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        gridLayout->addWidget(ButtonStatistics, 3, 3, 1, 1);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        gridLayout->addWidget(ButtonExit, 0, 8, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        ButtonGoToMyProfile = new QPushButton(centralWidget);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        gridLayout->addWidget(ButtonGoToMyProfile, 3, 7, 1, 3);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        gridLayout->addWidget(ButtonSettings, 0, 6, 1, 2);

        ScrollAreaForm = new QScrollArea(centralWidget);
        ScrollAreaForm->setObjectName(QString::fromUtf8("ScrollAreaForm"));
        ScrollAreaForm->setWidgetResizable(true);
        FormsWidget = new QWidget();
        FormsWidget->setObjectName(QString::fromUtf8("FormsWidget"));
        FormsWidget->setGeometry(QRect(0, 0, 560, 234));
        ScrollAreaForm->setWidget(FormsWidget);

        gridLayout->addWidget(ScrollAreaForm, 4, 0, 1, 10);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(LineEditIdProfile, 1, 0, 1, 8);

        ButtonFriends = new QPushButton(centralWidget);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        gridLayout->addWidget(ButtonFriends, 3, 1, 1, 1);

        ButtonSetProfile = new QPushButton(centralWidget);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout->addWidget(ButtonSetProfile, 0, 3, 1, 2);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(ButtonFindProfile, 1, 8, 1, 2);

        ButtonGames = new QPushButton(centralWidget);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);

        gridLayout->addWidget(ButtonGames, 3, 0, 1, 1);

        ButtonFavorites = new QPushButton(centralWidget);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        gridLayout->addWidget(ButtonFavorites, 3, 2, 1, 1);

        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 10, 1, 1);

        ScrollAreaProfileInfo = new QScrollArea(centralWidget);
        ScrollAreaProfileInfo->setObjectName(QString::fromUtf8("ScrollAreaProfileInfo"));
        ScrollAreaProfileInfo->setMinimumSize(QSize(0, 154));
        ScrollAreaProfileInfo->setMaximumSize(QSize(16777215, 154));
        ScrollAreaProfileInfo->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 560, 152));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        LabelTimeCreated = new QLabel(scrollAreaWidgetContents);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        QFont font;
        font.setPointSize(10);
        LabelTimeCreated->setFont(font);

        gridLayout_2->addWidget(LabelTimeCreated, 7, 0, 1, 3);

        LabelBans = new QLabel(scrollAreaWidgetContents);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font);
        LabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(LabelBans, 8, 4, 1, 1);

        LabelRealName = new QLabel(scrollAreaWidgetContents);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font);

        gridLayout_2->addWidget(LabelRealName, 6, 4, 1, 1);

        LabelLocCountryCode = new QLabel(scrollAreaWidgetContents);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font);

        gridLayout_2->addWidget(LabelLocCountryCode, 7, 4, 1, 1);

        Labellvl = new QLabel(scrollAreaWidgetContents);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font);

        gridLayout_2->addWidget(Labellvl, 6, 0, 1, 3);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 6, 3, 3, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        LabelProfileVisibility = new QLabel(scrollAreaWidgetContents);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        LabelProfileVisibility->setFont(font);

        gridLayout_2->addWidget(LabelProfileVisibility, 8, 0, 1, 3);

        LabelAvatar = new QLabel(scrollAreaWidgetContents);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setMaximumSize(QSize(64, 64));

        gridLayout_2->addWidget(LabelAvatar, 1, 0, 3, 1);

        LabelNick = new QLabel(scrollAreaWidgetContents);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font1.setPointSize(14);
        LabelNick->setFont(font1);
        LabelNick->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 0)"));

        gridLayout_2->addWidget(LabelNick, 1, 1, 1, 2);

        LabelProfileUrl = new QLabel(scrollAreaWidgetContents);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        LabelProfileUrl->setFont(font);
        LabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout_2->addWidget(LabelProfileUrl, 3, 1, 1, 4);

        LabelPersonaState = new QLabel(scrollAreaWidgetContents);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        LabelPersonaState->setFont(font);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(LabelPersonaState, 2, 1, 1, 4);

        ScrollAreaProfileInfo->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(ScrollAreaProfileInfo, 2, 0, 1, 10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 20));
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
        ButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        ButtonExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "Go to my profile", nullptr));
        ButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        ButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        LabelProfileVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        LabelNick->setText(QApplication::translate("MainWindow", "NickName", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
