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
    QLabel *FormProfileLabelLocCountryCode;
    QPushButton *FormProfileButtonGames;
    QLabel *FormProfileLabelPersonaState;
    QPushButton *FormProfileButtonStatistics;
    QPushButton *FormProfileButtonFindProfile;
    QSpacerItem *horizontalSpacer;
    QLabel *FormProfileLabelProfileUrl;
    QLabel *FormProfileAvatar;
    QPushButton *FormProfileButtonFriends;
    QPushButton *FormProfileButtonSettings;
    QLabel *FormProfileLabelLogo;
    QLabel *FormProfileLabelTimeCreated;
    QPushButton *FormProfileButtonFavorites;
    QSpacerItem *verticalSpacer;
    QLineEdit *FormProfileLineEditIdProfile;
    QLabel *FormProfileLabelPersonaName;
    QLabel *FormProfileLabelRealName;
    QPushButton *FormProfileButtonSetProfile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(560, 416);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 49, 49);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormProfileLabelLocCountryCode = new QLabel(centralWidget);
        FormProfileLabelLocCountryCode->setObjectName(QString::fromUtf8("FormProfileLabelLocCountryCode"));
        QFont font;
        font.setPointSize(10);
        FormProfileLabelLocCountryCode->setFont(font);

        gridLayout->addWidget(FormProfileLabelLocCountryCode, 6, 0, 1, 6);

        FormProfileButtonGames = new QPushButton(centralWidget);
        FormProfileButtonGames->setObjectName(QString::fromUtf8("FormProfileButtonGames"));

        gridLayout->addWidget(FormProfileButtonGames, 7, 0, 1, 2);

        FormProfileLabelPersonaState = new QLabel(centralWidget);
        FormProfileLabelPersonaState->setObjectName(QString::fromUtf8("FormProfileLabelPersonaState"));
        FormProfileLabelPersonaState->setFont(font);

        gridLayout->addWidget(FormProfileLabelPersonaState, 2, 8, 1, 3);

        FormProfileButtonStatistics = new QPushButton(centralWidget);
        FormProfileButtonStatistics->setObjectName(QString::fromUtf8("FormProfileButtonStatistics"));

        gridLayout->addWidget(FormProfileButtonStatistics, 11, 0, 1, 2);

        FormProfileButtonFindProfile = new QPushButton(centralWidget);
        FormProfileButtonFindProfile->setObjectName(QString::fromUtf8("FormProfileButtonFindProfile"));

        gridLayout->addWidget(FormProfileButtonFindProfile, 1, 9, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 7, 1, 1);

        FormProfileLabelProfileUrl = new QLabel(centralWidget);
        FormProfileLabelProfileUrl->setObjectName(QString::fromUtf8("FormProfileLabelProfileUrl"));
        FormProfileLabelProfileUrl->setFont(font);
        FormProfileLabelProfileUrl->setStyleSheet(QString::fromUtf8("color: rgb(0, 102, 255);"));

        gridLayout->addWidget(FormProfileLabelProfileUrl, 3, 0, 1, 7);

        FormProfileAvatar = new QLabel(centralWidget);
        FormProfileAvatar->setObjectName(QString::fromUtf8("FormProfileAvatar"));

        gridLayout->addWidget(FormProfileAvatar, 2, 0, 1, 1);

        FormProfileButtonFriends = new QPushButton(centralWidget);
        FormProfileButtonFriends->setObjectName(QString::fromUtf8("FormProfileButtonFriends"));

        gridLayout->addWidget(FormProfileButtonFriends, 8, 0, 1, 2);

        FormProfileButtonSettings = new QPushButton(centralWidget);
        FormProfileButtonSettings->setObjectName(QString::fromUtf8("FormProfileButtonSettings"));

        gridLayout->addWidget(FormProfileButtonSettings, 0, 9, 1, 2);

        FormProfileLabelLogo = new QLabel(centralWidget);
        FormProfileLabelLogo->setObjectName(QString::fromUtf8("FormProfileLabelLogo"));

        gridLayout->addWidget(FormProfileLabelLogo, 0, 0, 1, 8);

        FormProfileLabelTimeCreated = new QLabel(centralWidget);
        FormProfileLabelTimeCreated->setObjectName(QString::fromUtf8("FormProfileLabelTimeCreated"));
        FormProfileLabelTimeCreated->setFont(font);

        gridLayout->addWidget(FormProfileLabelTimeCreated, 5, 0, 1, 6);

        FormProfileButtonFavorites = new QPushButton(centralWidget);
        FormProfileButtonFavorites->setObjectName(QString::fromUtf8("FormProfileButtonFavorites"));

        gridLayout->addWidget(FormProfileButtonFavorites, 9, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        FormProfileLineEditIdProfile = new QLineEdit(centralWidget);
        FormProfileLineEditIdProfile->setObjectName(QString::fromUtf8("FormProfileLineEditIdProfile"));
        FormProfileLineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        gridLayout->addWidget(FormProfileLineEditIdProfile, 1, 0, 1, 9);

        FormProfileLabelPersonaName = new QLabel(centralWidget);
        FormProfileLabelPersonaName->setObjectName(QString::fromUtf8("FormProfileLabelPersonaName"));
        QFont font1;
        font1.setPointSize(14);
        FormProfileLabelPersonaName->setFont(font1);

        gridLayout->addWidget(FormProfileLabelPersonaName, 2, 1, 1, 2);

        FormProfileLabelRealName = new QLabel(centralWidget);
        FormProfileLabelRealName->setObjectName(QString::fromUtf8("FormProfileLabelRealName"));
        FormProfileLabelRealName->setFont(font);

        gridLayout->addWidget(FormProfileLabelRealName, 4, 0, 1, 6);

        FormProfileButtonSetProfile = new QPushButton(centralWidget);
        FormProfileButtonSetProfile->setObjectName(QString::fromUtf8("FormProfileButtonSetProfile"));

        gridLayout->addWidget(FormProfileButtonSetProfile, 12, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 560, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        FormProfileLabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        FormProfileButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        FormProfileLabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
        FormProfileButtonStatistics->setText(QApplication::translate("MainWindow", "Statistics", nullptr));
        FormProfileButtonFindProfile->setText(QApplication::translate("MainWindow", "Find", nullptr));
        FormProfileLabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        FormProfileAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        FormProfileButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        FormProfileButtonSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        FormProfileLabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        FormProfileLabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        FormProfileButtonFavorites->setText(QApplication::translate("MainWindow", "Favorites", nullptr));
        FormProfileLabelPersonaName->setText(QApplication::translate("MainWindow", "PersonaName", nullptr));
        FormProfileLabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        FormProfileButtonSetProfile->setText(QApplication::translate("MainWindow", "Set as my profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
