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
    QPushButton *ButtonFavorites;
    QLabel *LabelProfileVisibility;
    QPushButton *ButtonStatistics;
    QLabel *LabelProfileUrl;
    QLabel *LabelLogo;
    QFrame *line;
    QPushButton *ButtonGames;
    QPushButton *ButtonGoToMyProfile;
    QPushButton *ButtonFriends;
    QLabel *LabelBans;
    QLabel *LabelPersonaState;
    QPushButton *ButtonExit;
    QPushButton *ButtonSetProfile;
    QLabel *Labellvl;
    QLineEdit *LineEditIdProfile;
    QScrollArea *ScrollAreaForm;
    QWidget *FormsWidget;
    QLabel *LabelTimeCreated;
    QLabel *LabelAvatar;
    QLabel *LabelLocCountryCode;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSettings;
    QPushButton *ButtonFindProfile;
    QLabel *LabelRealName;
    QSpacerItem *verticalSpacer;
    QLabel *LabelNick;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(587, 425);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ButtonFavorites = new QPushButton(centralWidget);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        gridLayout->addWidget(ButtonFavorites, 12, 5, 1, 1);

        LabelProfileVisibility = new QLabel(centralWidget);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));

        gridLayout->addWidget(LabelProfileVisibility, 10, 0, 1, 3);

        ButtonStatistics = new QPushButton(centralWidget);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        gridLayout->addWidget(ButtonStatistics, 12, 6, 1, 1);

        LabelProfileUrl = new QLabel(centralWidget);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        QFont font;
        font.setPointSize(10);
        LabelProfileUrl->setFont(font);
        LabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout->addWidget(LabelProfileUrl, 6, 1, 1, 9);

        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 8, 3, 3, 1);

        ButtonGames = new QPushButton(centralWidget);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);

        gridLayout->addWidget(ButtonGames, 12, 0, 1, 2);

        ButtonGoToMyProfile = new QPushButton(centralWidget);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        gridLayout->addWidget(ButtonGoToMyProfile, 12, 8, 1, 2);

        ButtonFriends = new QPushButton(centralWidget);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        gridLayout->addWidget(ButtonFriends, 12, 2, 1, 3);

        LabelBans = new QLabel(centralWidget);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font);
        LabelBans->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(LabelBans, 10, 4, 1, 6);

        LabelPersonaState = new QLabel(centralWidget);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setFont(font);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(LabelPersonaState, 5, 1, 1, 9);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        gridLayout->addWidget(ButtonExit, 0, 9, 1, 1);

        ButtonSetProfile = new QPushButton(centralWidget);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout->addWidget(ButtonSetProfile, 0, 6, 1, 1);

        Labellvl = new QLabel(centralWidget);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font);

        gridLayout->addWidget(Labellvl, 8, 0, 1, 3);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(LineEditIdProfile, 1, 0, 1, 9);

        ScrollAreaForm = new QScrollArea(centralWidget);
        ScrollAreaForm->setObjectName(QString::fromUtf8("ScrollAreaForm"));
        ScrollAreaForm->setWidgetResizable(true);
        FormsWidget = new QWidget();
        FormsWidget->setObjectName(QString::fromUtf8("FormsWidget"));
        FormsWidget->setGeometry(QRect(0, 0, 560, 115));
        ScrollAreaForm->setWidget(FormsWidget);

        gridLayout->addWidget(ScrollAreaForm, 23, 0, 1, 10);

        LabelTimeCreated = new QLabel(centralWidget);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font);

        gridLayout->addWidget(LabelTimeCreated, 9, 0, 1, 3);

        LabelAvatar = new QLabel(centralWidget);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));

        gridLayout->addWidget(LabelAvatar, 2, 0, 6, 1);

        LabelLocCountryCode = new QLabel(centralWidget);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font);

        gridLayout->addWidget(LabelLocCountryCode, 9, 4, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 7, 1, 1);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        gridLayout->addWidget(ButtonSettings, 4, 8, 1, 2);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        gridLayout->addWidget(ButtonFindProfile, 1, 9, 1, 1);

        LabelRealName = new QLabel(centralWidget);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font);

        gridLayout->addWidget(LabelRealName, 8, 4, 1, 2);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 23, 10, 1, 1);

        LabelNick = new QLabel(centralWidget);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font1.setPointSize(14);
        LabelNick->setFont(font1);
        LabelNick->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 0)"));

        gridLayout->addWidget(LabelNick, 3, 1, 2, 6);

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
        ButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        LabelProfileVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
        ButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "Go to my profile", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
        ButtonExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        ButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        LabelNick->setText(QApplication::translate("MainWindow", "NickName", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
