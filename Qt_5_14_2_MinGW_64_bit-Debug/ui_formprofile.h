/********************************************************************************
** Form generated from reading UI file 'formprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROFILE_H
#define UI_FORMPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormProfile
{
public:
    QVBoxLayout *verticalLayout_6;
    QFrame *FrameNormalInfo;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LabelAvatar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelPersonaState;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelProfileUrl;
    QSpacerItem *horizontalSpacer_3;
    QFrame *FrameMaximumInfo;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Labellvl;
    QLabel *LabellvlValue;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelTimeCreated;
    QLabel *LabelTimeCreatedValue;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LabelRealName;
    QLabel *LabelRealNameValue;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *LabelLocCountryCode;
    QLabel *LabelLocCountryCodeValue;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *LabelProfileStatus;
    QLabel *LabelFriendsStatus;
    QLabel *LabelGamesStatus;
    QVBoxLayout *verticalLayout_8;
    QLabel *LabelProfileVisibility;
    QLabel *LabelFriendsVisibility;
    QLabel *LabelGamesVisibility;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LabelBans;
    QLabel *LabelBansNone;
    QLabel *LabelBansNotNone;
    QLabel *LabelBansLast;
    QLabel *LabelBansDays;
    QLabel *LabelBansDaysAgo;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelAvatarMinimize;
    QLabel *LabelNameMinimize;
    QPushButton *ButtonGames;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QPushButton *ButtonFavorites;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonSetProfile;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormProfile)
    {
        if (FormProfile->objectName().isEmpty())
            FormProfile->setObjectName(QString::fromUtf8("FormProfile"));
        FormProfile->resize(519, 253);
        verticalLayout_6 = new QVBoxLayout(FormProfile);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        FrameNormalInfo = new QFrame(FormProfile);
        FrameNormalInfo->setObjectName(QString::fromUtf8("FrameNormalInfo"));
        FrameNormalInfo->setFrameShape(QFrame::StyledPanel);
        FrameNormalInfo->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(FrameNormalInfo);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LabelAvatar = new QLabel(FrameNormalInfo);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setMinimumSize(QSize(64, 64));
        LabelAvatar->setMaximumSize(QSize(64, 64));
        LabelAvatar->setText(QString::fromUtf8("Avatar"));

        horizontalLayout_8->addWidget(LabelAvatar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelName = new QLabel(FrameNormalInfo);
        LabelName->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        LabelName->setFont(font);
        LabelName->setText(QString::fromUtf8("NickName"));

        horizontalLayout_7->addWidget(LabelName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelPersonaState = new QLabel(FrameNormalInfo);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        LabelPersonaState->setFont(font1);
        LabelPersonaState->setText(QString::fromUtf8("PersonaState"));
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        horizontalLayout_6->addWidget(LabelPersonaState);

        horizontalSpacer_6 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LabelProfileUrl = new QLabel(FrameNormalInfo);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        LabelProfileUrl->setFont(font1);
        LabelProfileUrl->setText(QString::fromUtf8("ProfileUrl"));
        LabelProfileUrl->setOpenExternalLinks(true);
        LabelProfileUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

        horizontalLayout_5->addWidget(LabelProfileUrl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_8);

        FrameMaximumInfo = new QFrame(FrameNormalInfo);
        FrameMaximumInfo->setObjectName(QString::fromUtf8("FrameMaximumInfo"));
        FrameMaximumInfo->setFrameShape(QFrame::StyledPanel);
        FrameMaximumInfo->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameMaximumInfo);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Labellvl = new QLabel(FrameMaximumInfo);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Labellvl->sizePolicy().hasHeightForWidth());
        Labellvl->setSizePolicy(sizePolicy);
        Labellvl->setFont(font1);

        horizontalLayout_3->addWidget(Labellvl);

        LabellvlValue = new QLabel(FrameMaximumInfo);
        LabellvlValue->setObjectName(QString::fromUtf8("LabellvlValue"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        LabellvlValue->setFont(font2);
        LabellvlValue->setText(QString::fromUtf8("0"));

        horizontalLayout_3->addWidget(LabellvlValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LabelTimeCreated = new QLabel(FrameMaximumInfo);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        sizePolicy.setHeightForWidth(LabelTimeCreated->sizePolicy().hasHeightForWidth());
        LabelTimeCreated->setSizePolicy(sizePolicy);
        LabelTimeCreated->setFont(font1);

        horizontalLayout_4->addWidget(LabelTimeCreated);

        LabelTimeCreatedValue = new QLabel(FrameMaximumInfo);
        LabelTimeCreatedValue->setObjectName(QString::fromUtf8("LabelTimeCreatedValue"));
        LabelTimeCreatedValue->setFont(font2);
        LabelTimeCreatedValue->setText(QString::fromUtf8("0"));

        horizontalLayout_4->addWidget(LabelTimeCreatedValue);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LabelRealName = new QLabel(FrameMaximumInfo);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        sizePolicy.setHeightForWidth(LabelRealName->sizePolicy().hasHeightForWidth());
        LabelRealName->setSizePolicy(sizePolicy);
        LabelRealName->setFont(font1);

        horizontalLayout_9->addWidget(LabelRealName);

        LabelRealNameValue = new QLabel(FrameMaximumInfo);
        LabelRealNameValue->setObjectName(QString::fromUtf8("LabelRealNameValue"));
        LabelRealNameValue->setFont(font2);
        LabelRealNameValue->setText(QString::fromUtf8("none"));

        horizontalLayout_9->addWidget(LabelRealNameValue);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LabelLocCountryCode = new QLabel(FrameMaximumInfo);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        sizePolicy.setHeightForWidth(LabelLocCountryCode->sizePolicy().hasHeightForWidth());
        LabelLocCountryCode->setSizePolicy(sizePolicy);
        LabelLocCountryCode->setFont(font1);

        horizontalLayout_11->addWidget(LabelLocCountryCode);

        LabelLocCountryCodeValue = new QLabel(FrameMaximumInfo);
        LabelLocCountryCodeValue->setObjectName(QString::fromUtf8("LabelLocCountryCodeValue"));
        LabelLocCountryCodeValue->setFont(font2);
        LabelLocCountryCodeValue->setText(QString::fromUtf8("EN"));

        horizontalLayout_11->addWidget(LabelLocCountryCodeValue);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        verticalLayout_5->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        LabelProfileStatus = new QLabel(FrameMaximumInfo);
        LabelProfileStatus->setObjectName(QString::fromUtf8("LabelProfileStatus"));
        LabelProfileStatus->setText(QString::fromUtf8("SP"));

        verticalLayout_7->addWidget(LabelProfileStatus);

        LabelFriendsStatus = new QLabel(FrameMaximumInfo);
        LabelFriendsStatus->setObjectName(QString::fromUtf8("LabelFriendsStatus"));
        LabelFriendsStatus->setText(QString::fromUtf8("SF"));

        verticalLayout_7->addWidget(LabelFriendsStatus);

        LabelGamesStatus = new QLabel(FrameMaximumInfo);
        LabelGamesStatus->setObjectName(QString::fromUtf8("LabelGamesStatus"));
        LabelGamesStatus->setText(QString::fromUtf8("SG"));

        verticalLayout_7->addWidget(LabelGamesStatus);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        LabelProfileVisibility = new QLabel(FrameMaximumInfo);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        sizePolicy.setHeightForWidth(LabelProfileVisibility->sizePolicy().hasHeightForWidth());
        LabelProfileVisibility->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(10);
        LabelProfileVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelProfileVisibility);

        LabelFriendsVisibility = new QLabel(FrameMaximumInfo);
        LabelFriendsVisibility->setObjectName(QString::fromUtf8("LabelFriendsVisibility"));
        sizePolicy.setHeightForWidth(LabelFriendsVisibility->sizePolicy().hasHeightForWidth());
        LabelFriendsVisibility->setSizePolicy(sizePolicy);
        LabelFriendsVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelFriendsVisibility);

        LabelGamesVisibility = new QLabel(FrameMaximumInfo);
        LabelGamesVisibility->setObjectName(QString::fromUtf8("LabelGamesVisibility"));
        sizePolicy.setHeightForWidth(LabelGamesVisibility->sizePolicy().hasHeightForWidth());
        LabelGamesVisibility->setSizePolicy(sizePolicy);
        LabelGamesVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelGamesVisibility);


        horizontalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout_12->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LabelBans = new QLabel(FrameMaximumInfo);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        sizePolicy.setHeightForWidth(LabelBans->sizePolicy().hasHeightForWidth());
        LabelBans->setSizePolicy(sizePolicy);
        LabelBans->setFont(font3);
        LabelBans->setText(QString::fromUtf8("VAC Bans: "));

        horizontalLayout_10->addWidget(LabelBans);

        LabelBansNone = new QLabel(FrameMaximumInfo);
        LabelBansNone->setObjectName(QString::fromUtf8("LabelBansNone"));
        LabelBansNone->setFont(font3);

        horizontalLayout_10->addWidget(LabelBansNone);

        LabelBansNotNone = new QLabel(FrameMaximumInfo);
        LabelBansNotNone->setObjectName(QString::fromUtf8("LabelBansNotNone"));
        LabelBansNotNone->setFont(font3);
        LabelBansNotNone->setText(QString::fromUtf8("0"));

        horizontalLayout_10->addWidget(LabelBansNotNone);

        LabelBansLast = new QLabel(FrameMaximumInfo);
        LabelBansLast->setObjectName(QString::fromUtf8("LabelBansLast"));
        LabelBansLast->setFont(font3);

        horizontalLayout_10->addWidget(LabelBansLast);

        LabelBansDays = new QLabel(FrameMaximumInfo);
        LabelBansDays->setObjectName(QString::fromUtf8("LabelBansDays"));
        LabelBansDays->setFont(font3);
        LabelBansDays->setText(QString::fromUtf8("000-00-00"));

        horizontalLayout_10->addWidget(LabelBansDays);

        LabelBansDaysAgo = new QLabel(FrameMaximumInfo);
        LabelBansDaysAgo->setObjectName(QString::fromUtf8("LabelBansDaysAgo"));
        LabelBansDaysAgo->setFont(font3);

        horizontalLayout_10->addWidget(LabelBansDaysAgo);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout->addWidget(FrameMaximumInfo);


        verticalLayout_6->addWidget(FrameNormalInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 2);
        LabelAvatarMinimize = new QLabel(FormProfile);
        LabelAvatarMinimize->setObjectName(QString::fromUtf8("LabelAvatarMinimize"));
        LabelAvatarMinimize->setText(QString::fromUtf8("Ava"));

        horizontalLayout->addWidget(LabelAvatarMinimize);

        LabelNameMinimize = new QLabel(FormProfile);
        LabelNameMinimize->setObjectName(QString::fromUtf8("LabelNameMinimize"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        LabelNameMinimize->setFont(font4);
        LabelNameMinimize->setText(QString::fromUtf8("Name"));

        horizontalLayout->addWidget(LabelNameMinimize);

        ButtonGames = new QPushButton(FormProfile);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);
        ButtonGames->setStyleSheet(QString::fromUtf8(""));
        ButtonGames->setText(QString::fromUtf8("Games"));

        horizontalLayout->addWidget(ButtonGames);

        ButtonFriends = new QPushButton(FormProfile);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));
        ButtonFriends->setText(QString::fromUtf8("Friends"));

        horizontalLayout->addWidget(ButtonFriends);

        ButtonStatistics = new QPushButton(FormProfile);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));
        ButtonStatistics->setText(QString::fromUtf8(" \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260"));

        horizontalLayout->addWidget(ButtonStatistics);

        ButtonFavorites = new QPushButton(FormProfile);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));
        ButtonFavorites->setText(QString::fromUtf8(" \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265"));

        horizontalLayout->addWidget(ButtonFavorites);

        horizontalSpacer_4 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ButtonSetProfile = new QPushButton(FormProfile);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        horizontalLayout->addWidget(ButtonSetProfile);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        retranslateUi(FormProfile);

        QMetaObject::connectSlotsByName(FormProfile);
    } // setupUi

    void retranslateUi(QWidget *FormProfile)
    {
        FormProfile->setWindowTitle(QCoreApplication::translate("FormProfile", "Form", nullptr));
        Labellvl->setText(QCoreApplication::translate("FormProfile", "lvl:", nullptr));
        LabelTimeCreated->setText(QCoreApplication::translate("FormProfile", "TimeCreated:", nullptr));
        LabelRealName->setText(QCoreApplication::translate("FormProfile", "RealName:", nullptr));
        LabelLocCountryCode->setText(QCoreApplication::translate("FormProfile", "CountryCode:", nullptr));
        LabelProfileVisibility->setText(QCoreApplication::translate("FormProfile", "Profile", nullptr));
        LabelFriendsVisibility->setText(QCoreApplication::translate("FormProfile", "Friends", nullptr));
        LabelGamesVisibility->setText(QCoreApplication::translate("FormProfile", "Games", nullptr));
        LabelBansNone->setText(QCoreApplication::translate("FormProfile", "None", nullptr));
        LabelBansLast->setText(QCoreApplication::translate("FormProfile", "Last", nullptr));
        LabelBansDaysAgo->setText(QCoreApplication::translate("FormProfile", "days ago.", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
