/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QLabel *Labellvl;
    QPushButton *ButtonFindProfile;
    QLabel *LabelProfileVisibility;
    QLabel *LabelPersonaState;
    QLabel *LabelNick;
    QLabel *LabelRealName;
    QLabel *LabelLocCountryCode;
    QPushButton *ButtonGames;
    QLabel *LabelTimeCreated;
    QPushButton *ButtonFriends;
    QLabel *LabelBans;
    QPushButton *ButtonStatistics;
    QLabel *LabelLogo;
    QSpacerItem *verticalSpacer;
    QLabel *LabelAvatar;
    QPushButton *ButtonFavorites;
    QPushButton *ButtonExit;
    QLabel *LabelProfileUrl;
    QScrollArea *ScrollAreaForm;
    QWidget *FormsWidget;
    QPushButton *ButtonSetProfile;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSettings;
    QPushButton *ButtonGoToMyProfile;
    QLineEdit *LineEditIdProfile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(545, 425);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Labellvl = new QLabel(centralWidget);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        QFont font;
        font.setPointSize(10);
        Labellvl->setFont(font);

        gridLayout->addWidget(Labellvl, 9, 0, 1, 3);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(ButtonFindProfile, 1, 8, 1, 1);

        LabelProfileVisibility = new QLabel(centralWidget);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));

        gridLayout->addWidget(LabelProfileVisibility, 11, 0, 1, 3);

        LabelPersonaState = new QLabel(centralWidget);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setFont(font);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(LabelPersonaState, 5, 1, 1, 8);

        LabelNick = new QLabel(centralWidget);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font1.setPointSize(14);
        LabelNick->setFont(font1);
        LabelNick->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 0)"));

        gridLayout->addWidget(LabelNick, 3, 1, 2, 5);

        LabelRealName = new QLabel(centralWidget);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font);

        gridLayout->addWidget(LabelRealName, 9, 3, 1, 2);

        LabelLocCountryCode = new QLabel(centralWidget);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font);

        gridLayout->addWidget(LabelLocCountryCode, 10, 3, 1, 2);

        ButtonGames = new QPushButton(centralWidget);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);

        gridLayout->addWidget(ButtonGames, 14, 0, 1, 2);

        LabelTimeCreated = new QLabel(centralWidget);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font);

        gridLayout->addWidget(LabelTimeCreated, 10, 0, 1, 3);

        ButtonFriends = new QPushButton(centralWidget);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        gridLayout->addWidget(ButtonFriends, 14, 2, 1, 2);

        LabelBans = new QLabel(centralWidget);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font);
        LabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(LabelBans, 11, 3, 1, 6);

        ButtonStatistics = new QPushButton(centralWidget);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        gridLayout->addWidget(ButtonStatistics, 14, 5, 1, 1);

        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 25, 9, 1, 1);

        LabelAvatar = new QLabel(centralWidget);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));

        gridLayout->addWidget(LabelAvatar, 2, 0, 7, 1);

        ButtonFavorites = new QPushButton(centralWidget);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        gridLayout->addWidget(ButtonFavorites, 14, 4, 1, 1);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        gridLayout->addWidget(ButtonExit, 0, 8, 1, 1);

        LabelProfileUrl = new QLabel(centralWidget);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setFont(font);
        LabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout->addWidget(LabelProfileUrl, 6, 1, 1, 8);

        ScrollAreaForm = new QScrollArea(centralWidget);
        ScrollAreaForm->setObjectName(QString::fromUtf8("ScrollAreaForm"));
        ScrollAreaForm->setWidgetResizable(true);
        FormsWidget = new QWidget();
        FormsWidget->setObjectName(QString::fromUtf8("FormsWidget"));
        FormsWidget->setGeometry(QRect(0, 0, 518, 115));
        ScrollAreaForm->setWidget(FormsWidget);

        gridLayout->addWidget(ScrollAreaForm, 25, 0, 1, 9);

        ButtonSetProfile = new QPushButton(centralWidget);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout->addWidget(ButtonSetProfile, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 6, 1, 1);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        gridLayout->addWidget(ButtonSettings, 4, 7, 1, 2);

        ButtonGoToMyProfile = new QPushButton(centralWidget);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        gridLayout->addWidget(ButtonGoToMyProfile, 14, 7, 1, 2);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(LineEditIdProfile, 1, 0, 1, 8);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 545, 20));
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
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        LabelProfileVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
        LabelNick->setText(QApplication::translate("MainWindow", "NickName", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        ButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        ButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        ButtonExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
        ButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "Go to my profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
