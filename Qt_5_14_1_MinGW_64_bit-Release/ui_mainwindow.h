/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LabelAvatar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelNick;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelProfileVisibility;
    QPushButton *ButtonSetProfile;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelPersonaState;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ButtonUpdate;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelProfileUrl;
    QSpacerItem *horizontalSpacer_3;
    QLabel *LabelBans;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Labellvl;
    QFrame *line;
    QLabel *LabelTimeCreated;
    QFrame *line_2;
    QLabel *LabelLocCountryCode;
    QFrame *line_3;
    QLabel *LabelRealName;
    QSpacerItem *horizontalSpacer_5;
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
        MainWindow->resize(479, 345);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LabelLogo = new QLabel(centralWidget);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));
        LabelLogo->setText(QString::fromUtf8("Logo"));

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
        ScrollAreaProfileInfo->setMinimumSize(QSize(0, 130));
        ScrollAreaProfileInfo->setMaximumSize(QSize(16777215, 130));
        ScrollAreaProfileInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollAreaProfileInfo->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 471, 128));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LabelAvatar = new QLabel(scrollAreaWidgetContents);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setMaximumSize(QSize(64, 64));

        horizontalLayout_8->addWidget(LabelAvatar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelNick = new QLabel(scrollAreaWidgetContents);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(16);
        LabelNick->setFont(font1);

        horizontalLayout_7->addWidget(LabelNick);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        LabelProfileVisibility = new QLabel(scrollAreaWidgetContents);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(10);
        LabelProfileVisibility->setFont(font2);

        horizontalLayout_7->addWidget(LabelProfileVisibility);

        ButtonSetProfile = new QPushButton(scrollAreaWidgetContents);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        horizontalLayout_7->addWidget(ButtonSetProfile);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelPersonaState = new QLabel(scrollAreaWidgetContents);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        LabelPersonaState->setFont(font2);
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        horizontalLayout_6->addWidget(LabelPersonaState);

        horizontalSpacer_6 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        ButtonUpdate = new QPushButton(scrollAreaWidgetContents);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        horizontalLayout_6->addWidget(ButtonUpdate);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LabelProfileUrl = new QLabel(scrollAreaWidgetContents);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        LabelProfileUrl->setFont(font2);
        LabelProfileUrl->setOpenExternalLinks(true);
        LabelProfileUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

        horizontalLayout_5->addWidget(LabelProfileUrl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        LabelBans = new QLabel(scrollAreaWidgetContents);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font2);

        horizontalLayout_5->addWidget(LabelBans);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Labellvl = new QLabel(scrollAreaWidgetContents);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font2);

        horizontalLayout_2->addWidget(Labellvl);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        LabelTimeCreated = new QLabel(scrollAreaWidgetContents);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font2);

        horizontalLayout_2->addWidget(LabelTimeCreated);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        LabelLocCountryCode = new QLabel(scrollAreaWidgetContents);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font2);

        horizontalLayout_2->addWidget(LabelLocCountryCode);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        LabelRealName = new QLabel(scrollAreaWidgetContents);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font2);

        horizontalLayout_2->addWidget(LabelRealName);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 2);
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


        verticalLayout_3->addLayout(horizontalLayout);

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
        FormsWidget->setGeometry(QRect(0, 0, 471, 68));
        ScrollAreaForm->setWidget(FormsWidget);

        verticalLayout->addWidget(ScrollAreaForm);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 20));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SteamAchievementsStatistic", nullptr));
        ButtonSettings->setText(QString());
        ButtonExit->setText(QCoreApplication::translate("MainWindow", " \320\222\321\213\321\205\320\276\320\264", nullptr));
        ButtonBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        ButtonNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        LineEditIdProfile->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 Steamid", nullptr));
        ButtonFindProfile->setText(QCoreApplication::translate("MainWindow", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        LabelAvatar->setText(QCoreApplication::translate("MainWindow", "Avatar", nullptr));
        LabelNick->setText(QCoreApplication::translate("MainWindow", "NickName", nullptr));
        LabelProfileVisibility->setText(QCoreApplication::translate("MainWindow", "Visibility", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        LabelPersonaState->setText(QCoreApplication::translate("MainWindow", "PersonaState", nullptr));
        ButtonUpdate->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        LabelProfileUrl->setText(QCoreApplication::translate("MainWindow", "ProfileUrl", nullptr));
        LabelBans->setText(QCoreApplication::translate("MainWindow", "Bans", nullptr));
        Labellvl->setText(QCoreApplication::translate("MainWindow", "lvl", nullptr));
        LabelTimeCreated->setText(QCoreApplication::translate("MainWindow", "TimeCreated", nullptr));
        LabelLocCountryCode->setText(QCoreApplication::translate("MainWindow", "CountryCode", nullptr));
        LabelRealName->setText(QCoreApplication::translate("MainWindow", "RealName", nullptr));
        ButtonGames->setText(QCoreApplication::translate("MainWindow", "Games", nullptr));
        ButtonFriends->setText(QCoreApplication::translate("MainWindow", "Friends", nullptr));
        ButtonStatistics->setText(QCoreApplication::translate("MainWindow", " \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        ButtonFavorites->setText(QCoreApplication::translate("MainWindow", " \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonGoToMyProfile->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        FormProgressBar->setFormat(QCoreApplication::translate("MainWindow", "%v/%m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
