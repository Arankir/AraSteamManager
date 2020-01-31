/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LabelLogo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonSettings;
    QPushButton *ButtonExit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonBack;
    QPushButton *ButtonNext;
    QLineEdit *LineEditIdProfile;
    QPushButton *ButtonFindProfile;
    QScrollArea *ScrollAreaProfileInfo;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *LabelProfileUrl;
    QLabel *LabelNick;
    QLabel *LabelAvatar;
    QLabel *LabelPersonaState;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSetProfile;
    QPushButton *ButtonUpdate;
    QGridLayout *gridLayout_3;
    QLabel *LabelTimeCreated;
    QLabel *LabelLocCountryCode;
    QLabel *LabelRealName;
    QLabel *Labellvl;
    QSpacerItem *horizontalSpacer_5;
    QLabel *LabelProfileVisibility;
    QLabel *LabelBans;
    QFrame *line;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonGames;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QPushButton *ButtonFavorites;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonGoToMyProfile;
    QProgressBar *FormProgressBar;
    QScrollArea *ScrollAreaForm;
    QWidget *FormsWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(479, 365);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        horizontalLayout_3->addWidget(LabelLogo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ButtonSettings = new QPushButton(centralWidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        horizontalLayout_3->addWidget(ButtonSettings);

        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));

        horizontalLayout_3->addWidget(ButtonExit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonBack = new QPushButton(centralWidget);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));

        horizontalLayout_4->addWidget(ButtonBack);

        ButtonNext = new QPushButton(centralWidget);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));

        horizontalLayout_4->addWidget(ButtonNext);

        LineEditIdProfile = new QLineEdit(centralWidget);
        LineEditIdProfile->setObjectName(QString::fromUtf8("LineEditIdProfile"));
        LineEditIdProfile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(26, 26, 26);"));

        horizontalLayout_4->addWidget(LineEditIdProfile);

        ButtonFindProfile = new QPushButton(centralWidget);
        ButtonFindProfile->setObjectName(QString::fromUtf8("ButtonFindProfile"));
        ButtonFindProfile->setEnabled(true);

        horizontalLayout_4->addWidget(ButtonFindProfile);


        verticalLayout->addLayout(horizontalLayout_4);

        ScrollAreaProfileInfo = new QScrollArea(centralWidget);
        ScrollAreaProfileInfo->setObjectName(QString::fromUtf8("ScrollAreaProfileInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrollAreaProfileInfo->sizePolicy().hasHeightForWidth());
        ScrollAreaProfileInfo->setSizePolicy(sizePolicy);
        ScrollAreaProfileInfo->setMaximumSize(QSize(16777215, 150));
        ScrollAreaProfileInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollAreaProfileInfo->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 465, 148));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(3);
        LabelProfileUrl = new QLabel(scrollAreaWidgetContents);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        LabelProfileUrl->setFont(font1);
        LabelProfileUrl->setWordWrap(true);
        LabelProfileUrl->setOpenExternalLinks(true);
        LabelProfileUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

        gridLayout_2->addWidget(LabelProfileUrl, 2, 1, 1, 2);

        LabelNick = new QLabel(scrollAreaWidgetContents);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(16);
        LabelNick->setFont(font2);

        gridLayout_2->addWidget(LabelNick, 0, 1, 1, 1);

        LabelAvatar = new QLabel(scrollAreaWidgetContents);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setMaximumSize(QSize(64, 64));

        gridLayout_2->addWidget(LabelAvatar, 0, 0, 3, 1);

        LabelPersonaState = new QLabel(scrollAreaWidgetContents);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        LabelPersonaState->setFont(font1);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        gridLayout_2->addWidget(LabelPersonaState, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        ButtonSetProfile = new QPushButton(scrollAreaWidgetContents);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        gridLayout_2->addWidget(ButtonSetProfile, 0, 3, 1, 2);

        ButtonUpdate = new QPushButton(scrollAreaWidgetContents);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        gridLayout_2->addWidget(ButtonUpdate, 1, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LabelTimeCreated = new QLabel(scrollAreaWidgetContents);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font1);

        gridLayout_3->addWidget(LabelTimeCreated, 1, 0, 1, 1);

        LabelLocCountryCode = new QLabel(scrollAreaWidgetContents);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font1);

        gridLayout_3->addWidget(LabelLocCountryCode, 1, 2, 1, 1);

        LabelRealName = new QLabel(scrollAreaWidgetContents);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font1);

        gridLayout_3->addWidget(LabelRealName, 0, 2, 1, 1);

        Labellvl = new QLabel(scrollAreaWidgetContents);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font1);

        gridLayout_3->addWidget(Labellvl, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 5, 2, 1);

        LabelProfileVisibility = new QLabel(scrollAreaWidgetContents);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        LabelProfileVisibility->setFont(font1);

        gridLayout_3->addWidget(LabelProfileVisibility, 0, 4, 1, 1);

        LabelBans = new QLabel(scrollAreaWidgetContents);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font1);

        gridLayout_3->addWidget(LabelBans, 1, 4, 1, 1);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 2, 1);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 0, 3, 2, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonGames = new QPushButton(scrollAreaWidgetContents);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);
        ButtonGames->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(ButtonGames);

        ButtonFriends = new QPushButton(scrollAreaWidgetContents);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));

        horizontalLayout->addWidget(ButtonFriends);

        ButtonStatistics = new QPushButton(scrollAreaWidgetContents);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));

        horizontalLayout->addWidget(ButtonStatistics);

        ButtonFavorites = new QPushButton(scrollAreaWidgetContents);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        horizontalLayout->addWidget(ButtonFavorites);

        horizontalSpacer_4 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ButtonGoToMyProfile = new QPushButton(scrollAreaWidgetContents);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        horizontalLayout->addWidget(ButtonGoToMyProfile);


        verticalLayout_2->addLayout(horizontalLayout);

        ScrollAreaProfileInfo->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(ScrollAreaProfileInfo);

        FormProgressBar = new QProgressBar(centralWidget);
        FormProgressBar->setObjectName(QString::fromUtf8("FormProgressBar"));
        FormProgressBar->setValue(0);

        verticalLayout->addWidget(FormProgressBar);

        ScrollAreaForm = new QScrollArea(centralWidget);
        ScrollAreaForm->setObjectName(QString::fromUtf8("ScrollAreaForm"));
        ScrollAreaForm->setWidgetResizable(true);
        FormsWidget = new QWidget();
        FormsWidget->setObjectName(QString::fromUtf8("FormsWidget"));
        FormsWidget->setGeometry(QRect(0, 0, 465, 68));
        ScrollAreaForm->setWidget(FormsWidget);

        verticalLayout->addWidget(ScrollAreaForm);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SteamAchievementsStatistic", nullptr));
        LabelLogo->setText(QApplication::translate("MainWindow", "Logo", nullptr));
        ButtonSettings->setText(QString());
        ButtonExit->setText(QApplication::translate("MainWindow", " \320\222\321\213\321\205\320\276\320\264", nullptr));
        ButtonBack->setText(QApplication::translate("MainWindow", "Back", nullptr));
        ButtonNext->setText(QApplication::translate("MainWindow", "Next", nullptr));
        LineEditIdProfile->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 Steamid", nullptr));
        ButtonFindProfile->setText(QApplication::translate("MainWindow", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        LabelProfileUrl->setText(QApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelNick->setText(QApplication::translate("MainWindow", "NickName", nullptr));
        LabelAvatar->setText(QApplication::translate("MainWindow", "Avatar", nullptr));
        LabelPersonaState->setText(QApplication::translate("MainWindow", "PersonaState", nullptr));
        ButtonSetProfile->setText(QApplication::translate("MainWindow", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        ButtonUpdate->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        LabelTimeCreated->setText(QApplication::translate("MainWindow", "TimeCreated", nullptr));
        LabelLocCountryCode->setText(QApplication::translate("MainWindow", "CountryCode", nullptr));
        LabelRealName->setText(QApplication::translate("MainWindow", "RealName", nullptr));
        Labellvl->setText(QApplication::translate("MainWindow", "lvl", nullptr));
        LabelProfileVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
        LabelBans->setText(QApplication::translate("MainWindow", "Bans", nullptr));
        ButtonGames->setText(QApplication::translate("MainWindow", "Games", nullptr));
        ButtonFriends->setText(QApplication::translate("MainWindow", "Friends", nullptr));
        ButtonStatistics->setText(QApplication::translate("MainWindow", " \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        ButtonFavorites->setText(QApplication::translate("MainWindow", " \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonGoToMyProfile->setText(QApplication::translate("MainWindow", "\320\235\320\260 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        FormProgressBar->setFormat(QApplication::translate("MainWindow", "%v/%m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
