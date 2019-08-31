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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *LabelLogo;
    QSpacerItem *verticalSpacer;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QPushButton *ButtonExit;
    QLabel *LabelRealName;
    QPushButton *ButtonFindProfile;
    QLabel *LabelAvatar;
    QPushButton *ButtonSetProfile;
    QPushButton *ButtonFavorites;
    QPushButton *ButtonSettings;
    QSpacerItem *horizontalSpacer;
    QLineEdit *LineEditIdProfile;
    QPushButton *ButtonGames;
    QPushButton *ButtonGoToMyProfile;
    QLabel *LabelBans;
    QLabel *Labellvl;
    QLabel *LabelLocCountryCode;
    QLabel *LabelTimeCreated;
    QLabel *LabelProfileUrl;
    QLabel *LabelPersonaState;
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
        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        ButtonFriends = new QPushButton(centralWidget);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        gridLayout->addWidget(ButtonFriends, 11, 0, 1, 2);

        ButtonStatistics = new QPushButton(centralWidget);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        gridLayout->addWidget(ButtonStatistics, 13, 0, 1, 2);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        gridLayout->addWidget(ButtonExit, 0, 5, 1, 1);

        LabelRealName = new QLabel(centralWidget);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        QFont font;
        font.setPointSize(10);
        LabelRealName->setFont(font);

        gridLayout->addWidget(LabelRealName, 5, 0, 1, 4);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(ButtonFindProfile, 1, 5, 1, 1);

        LabelAvatar = new QLabel(centralWidget);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));

        gridLayout->addWidget(LabelAvatar, 2, 0, 1, 3);

        ButtonSetProfile = new QPushButton(centralWidget);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout->addWidget(ButtonSetProfile, 14, 0, 1, 1);

        ButtonFavorites = new QPushButton(centralWidget);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        gridLayout->addWidget(ButtonFavorites, 12, 0, 1, 2);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        gridLayout->addWidget(ButtonSettings, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 2);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(LineEditIdProfile, 1, 0, 1, 5);

        ButtonGames = new QPushButton(centralWidget);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);

        gridLayout->addWidget(ButtonGames, 10, 0, 1, 2);

        ButtonGoToMyProfile = new QPushButton(centralWidget);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        gridLayout->addWidget(ButtonGoToMyProfile, 14, 1, 1, 1);

        LabelBans = new QLabel(centralWidget);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font);
        LabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(LabelBans, 6, 0, 1, 3);

        Labellvl = new QLabel(centralWidget);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font);

        gridLayout->addWidget(Labellvl, 4, 0, 1, 3);

        LabelLocCountryCode = new QLabel(centralWidget);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font);

        gridLayout->addWidget(LabelLocCountryCode, 8, 0, 1, 3);

        LabelTimeCreated = new QLabel(centralWidget);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font);

        gridLayout->addWidget(LabelTimeCreated, 7, 0, 1, 3);

        LabelProfileUrl = new QLabel(centralWidget);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setFont(font);
        LabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout->addWidget(LabelProfileUrl, 3, 0, 1, 5);

        LabelPersonaState = new QLabel(centralWidget);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(100, 16777215));
        LabelPersonaState->setFont(font);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(LabelPersonaState, 2, 5, 7, 1);

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
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        ButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        ButtonExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
        ButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        ButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "Go to my profile", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
