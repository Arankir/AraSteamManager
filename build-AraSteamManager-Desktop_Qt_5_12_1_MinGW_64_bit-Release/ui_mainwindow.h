/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
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
    QLabel *FormProfileLabelLogo;
    QSpacerItem *verticalSpacer;
    QPushButton *FormProfileButtonFriends;
    QPushButton *FormProfileButtonStatistics;
    QPushButton *FormProfileButtonExit;
    QLabel *FormProfileLabelRealName;
    QPushButton *FormProfileButtonFindProfile;
    QLabel *FormProfileAvatar;
    QPushButton *FormProfileButtonSetProfile;
    QPushButton *FormProfileButtonFavorites;
    QPushButton *FormProfileButtonSettings;
    QSpacerItem *horizontalSpacer;
    QLineEdit *FormProfileLineEditIdProfile;
    QPushButton *FormProfileButtonGames;
    QPushButton *FormProfileButtonGoToMyProfile;
    QLabel *FormProfileLabelBans;
    QLabel *FormProfileLabellvl;
    QLabel *FormProfileLabelLocCountryCode;
    QLabel *FormProfileLabelTimeCreated;
    QLabel *FormProfileLabelProfileUrl;
    QLabel *FormProfileLabelPersonaState;
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
        FormProfileLabelLogo = new QLabel(centralWidget);
        FormProfileLabelLogo->setObjectName(QString::fromUtf8("FormProfileLabelLogo"));

        gridLayout->addWidget(FormProfileLabelLogo, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        FormProfileButtonFriends = new QPushButton(centralWidget);
        FormProfileButtonFriends->setObjectName(QString::fromUtf8("FormProfileButtonFriends"));

        gridLayout->addWidget(FormProfileButtonFriends, 11, 0, 1, 2);

        FormProfileButtonStatistics = new QPushButton(centralWidget);
        FormProfileButtonStatistics->setObjectName(QString::fromUtf8("FormProfileButtonStatistics"));

        gridLayout->addWidget(FormProfileButtonStatistics, 13, 0, 1, 2);

        FormProfileButtonExit = new QPushButton(centralWidget);
        FormProfileButtonExit->setObjectName(QString::fromUtf8("FormProfileButtonExit"));

        gridLayout->addWidget(FormProfileButtonExit, 0, 5, 1, 1);

        FormProfileLabelRealName = new QLabel(centralWidget);
        FormProfileLabelRealName->setObjectName(QString::fromUtf8("FormProfileLabelRealName"));
        QFont font;
        font.setPointSize(10);
        FormProfileLabelRealName->setFont(font);

        gridLayout->addWidget(FormProfileLabelRealName, 5, 0, 1, 4);

        FormProfileButtonFindProfile = new QPushButton(centralWidget);
        FormProfileButtonFindProfile->setObjectName(QString::fromUtf8("FormProfileButtonFindProfile"));
        FormProfileButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(FormProfileButtonFindProfile, 1, 5, 1, 1);

        FormProfileAvatar = new QLabel(centralWidget);
        FormProfileAvatar->setObjectName(QString::fromUtf8("FormProfileAvatar"));

        gridLayout->addWidget(FormProfileAvatar, 2, 0, 1, 3);

        FormProfileButtonSetProfile = new QPushButton(centralWidget);
        FormProfileButtonSetProfile->setObjectName(QString::fromUtf8("FormProfileButtonSetProfile"));

        gridLayout->addWidget(FormProfileButtonSetProfile, 14, 0, 1, 1);

        FormProfileButtonFavorites = new QPushButton(centralWidget);
        FormProfileButtonFavorites->setObjectName(QString::fromUtf8("FormProfileButtonFavorites"));

        gridLayout->addWidget(FormProfileButtonFavorites, 12, 0, 1, 2);

        FormProfileButtonSettings = new QPushButton(centralWidget);
        FormProfileButtonSettings->setObjectName(QString::fromUtf8("FormProfileButtonSettings"));

        gridLayout->addWidget(FormProfileButtonSettings, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 2);

        FormProfileLineEditIdProfile = new QLineEdit(centralWidget);
        FormProfileLineEditIdProfile->setObjectName(QString::fromUtf8("FormProfileLineEditIdProfile"));
        FormProfileLineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(FormProfileLineEditIdProfile, 1, 0, 1, 5);

        FormProfileButtonGames = new QPushButton(centralWidget);
        FormProfileButtonGames->setObjectName(QString::fromUtf8("FormProfileButtonGames"));
        FormProfileButtonGames->setEnabled(true);

        gridLayout->addWidget(FormProfileButtonGames, 10, 0, 1, 2);

        FormProfileButtonGoToMyProfile = new QPushButton(centralWidget);
        FormProfileButtonGoToMyProfile->setObjectName(QString::fromUtf8("FormProfileButtonGoToMyProfile"));

        gridLayout->addWidget(FormProfileButtonGoToMyProfile, 14, 1, 1, 1);

        FormProfileLabelBans = new QLabel(centralWidget);
        FormProfileLabelBans->setObjectName(QString::fromUtf8("FormProfileLabelBans"));
        FormProfileLabelBans->setFont(font);
        FormProfileLabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(FormProfileLabelBans, 6, 0, 1, 3);

        FormProfileLabellvl = new QLabel(centralWidget);
        FormProfileLabellvl->setObjectName(QString::fromUtf8("FormProfileLabellvl"));
        FormProfileLabellvl->setFont(font);

        gridLayout->addWidget(FormProfileLabellvl, 4, 0, 1, 3);

        FormProfileLabelLocCountryCode = new QLabel(centralWidget);
        FormProfileLabelLocCountryCode->setObjectName(QString::fromUtf8("FormProfileLabelLocCountryCode"));
        FormProfileLabelLocCountryCode->setFont(font);

        gridLayout->addWidget(FormProfileLabelLocCountryCode, 8, 0, 1, 3);

        FormProfileLabelTimeCreated = new QLabel(centralWidget);
        FormProfileLabelTimeCreated->setObjectName(QString::fromUtf8("FormProfileLabelTimeCreated"));
        FormProfileLabelTimeCreated->setFont(font);

        gridLayout->addWidget(FormProfileLabelTimeCreated, 7, 0, 1, 3);

        FormProfileLabelProfileUrl = new QLabel(centralWidget);
        FormProfileLabelProfileUrl->setObjectName(QString::fromUtf8("FormProfileLabelProfileUrl"));
        FormProfileLabelProfileUrl->setFont(font);
        FormProfileLabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout->addWidget(FormProfileLabelProfileUrl, 3, 0, 1, 5);

        FormProfileLabelPersonaState = new QLabel(centralWidget);
        FormProfileLabelPersonaState->setObjectName(QString::fromUtf8("FormProfileLabelPersonaState"));
        FormProfileLabelPersonaState->setMaximumSize(QSize(100, 16777215));
        FormProfileLabelPersonaState->setFont(font);
        FormProfileLabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(FormProfileLabelPersonaState, 2, 5, 7, 1);

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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SteamAchievementsStatistic", nullptr));
        FormProfileLabelLogo->setText(QCoreApplication::translate("MainWindow", "Logo", nullptr));
        FormProfileButtonFriends->setText(QCoreApplication::translate("MainWindow", "Friends", nullptr));
        FormProfileButtonStatistics->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        FormProfileButtonExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        FormProfileLabelRealName->setText(QCoreApplication::translate("MainWindow", "RealName", nullptr));
        FormProfileButtonFindProfile->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        FormProfileAvatar->setText(QCoreApplication::translate("MainWindow", "Avatar", nullptr));
        FormProfileButtonSetProfile->setText(QCoreApplication::translate("MainWindow", "Set as my profile", nullptr));
        FormProfileButtonFavorites->setText(QCoreApplication::translate("MainWindow", "Favorites", nullptr));
        FormProfileButtonSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        FormProfileButtonGames->setText(QCoreApplication::translate("MainWindow", "Games", nullptr));
        FormProfileButtonGoToMyProfile->setText(QCoreApplication::translate("MainWindow", "Go to my profile", nullptr));
        FormProfileLabelBans->setText(QCoreApplication::translate("MainWindow", "Bans", nullptr));
        FormProfileLabellvl->setText(QCoreApplication::translate("MainWindow", "lvl", nullptr));
        FormProfileLabelLocCountryCode->setText(QCoreApplication::translate("MainWindow", "CountryCode", nullptr));
        FormProfileLabelTimeCreated->setText(QCoreApplication::translate("MainWindow", "TimeCreated", nullptr));
        FormProfileLabelProfileUrl->setText(QCoreApplication::translate("MainWindow", "ProfileUrl", nullptr));
        FormProfileLabelPersonaState->setText(QCoreApplication::translate("MainWindow", "PersonaState", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
