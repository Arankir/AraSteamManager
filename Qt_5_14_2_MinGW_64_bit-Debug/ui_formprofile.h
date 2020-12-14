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
    QVBoxLayout *verticalLayout_3;
    QFrame *FrameProfileBaseInfo;
    QHBoxLayout *horizontalLayout_15;
    QLabel *LabelAvatar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LabelRealName;
    QLabel *LabelRealNameValue;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelPersonaState;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *LabelProfileStatus;
    QLabel *LabelFriendsStatus;
    QLabel *LabelGamesStatus;
    QVBoxLayout *verticalLayout_8;
    QLabel *LabelProfileVisibility;
    QLabel *LabelFriendsVisibility;
    QLabel *LabelGamesVisibility;
    QFrame *FrameProfileMaximumInfo;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Labellvl;
    QLabel *LabellvlValue;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LabelBans;
    QLabel *LabelBansValue;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelTimeCreated;
    QLabel *LabelTimeCreatedValue;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelProfileUrl;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *LabelLocCountryCode;
    QLabel *LabelLocCountryCodeValue;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_12;
    QLabel *LabelProfileState;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LabelCommentPermission;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_5;
    QFrame *FrameProfileButtons;
    QHBoxLayout *horizontalLayout_16;
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
        FormProfile->resize(638, 334);
        verticalLayout_3 = new QVBoxLayout(FormProfile);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        FrameProfileBaseInfo = new QFrame(FormProfile);
        FrameProfileBaseInfo->setObjectName(QString::fromUtf8("FrameProfileBaseInfo"));
        FrameProfileBaseInfo->setFrameShape(QFrame::StyledPanel);
        FrameProfileBaseInfo->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(FrameProfileBaseInfo);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(-1, -1, 20, -1);
        LabelAvatar = new QLabel(FrameProfileBaseInfo);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
        LabelAvatar->setText(QString::fromUtf8("Avatar"));

        horizontalLayout_15->addWidget(LabelAvatar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelName = new QLabel(FrameProfileBaseInfo);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        LabelName->setFont(font);
        LabelName->setText(QString::fromUtf8("NickName"));

        horizontalLayout_7->addWidget(LabelName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LabelRealName = new QLabel(FrameProfileBaseInfo);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelRealName->sizePolicy().hasHeightForWidth());
        LabelRealName->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(10);
        LabelRealName->setFont(font1);

        horizontalLayout_9->addWidget(LabelRealName);

        LabelRealNameValue = new QLabel(FrameProfileBaseInfo);
        LabelRealNameValue->setObjectName(QString::fromUtf8("LabelRealNameValue"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        LabelRealNameValue->setFont(font2);
        LabelRealNameValue->setText(QString::fromUtf8("none"));

        horizontalLayout_9->addWidget(LabelRealNameValue);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelPersonaState = new QLabel(FrameProfileBaseInfo);
        LabelPersonaState->setObjectName(QString::fromUtf8("LabelPersonaState"));
        LabelPersonaState->setMaximumSize(QSize(16777215, 16));
        LabelPersonaState->setFont(font1);
        LabelPersonaState->setText(QString::fromUtf8("PersonaState"));
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        horizontalLayout_6->addWidget(LabelPersonaState);

        horizontalSpacer_6 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        LabelProfileStatus = new QLabel(FrameProfileBaseInfo);
        LabelProfileStatus->setObjectName(QString::fromUtf8("LabelProfileStatus"));
        LabelProfileStatus->setText(QString::fromUtf8("SP"));

        verticalLayout_7->addWidget(LabelProfileStatus);

        LabelFriendsStatus = new QLabel(FrameProfileBaseInfo);
        LabelFriendsStatus->setObjectName(QString::fromUtf8("LabelFriendsStatus"));
        LabelFriendsStatus->setText(QString::fromUtf8("SF"));

        verticalLayout_7->addWidget(LabelFriendsStatus);

        LabelGamesStatus = new QLabel(FrameProfileBaseInfo);
        LabelGamesStatus->setObjectName(QString::fromUtf8("LabelGamesStatus"));
        LabelGamesStatus->setText(QString::fromUtf8("SG"));

        verticalLayout_7->addWidget(LabelGamesStatus);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        LabelProfileVisibility = new QLabel(FrameProfileBaseInfo);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        sizePolicy.setHeightForWidth(LabelProfileVisibility->sizePolicy().hasHeightForWidth());
        LabelProfileVisibility->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(10);
        LabelProfileVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelProfileVisibility);

        LabelFriendsVisibility = new QLabel(FrameProfileBaseInfo);
        LabelFriendsVisibility->setObjectName(QString::fromUtf8("LabelFriendsVisibility"));
        sizePolicy.setHeightForWidth(LabelFriendsVisibility->sizePolicy().hasHeightForWidth());
        LabelFriendsVisibility->setSizePolicy(sizePolicy);
        LabelFriendsVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelFriendsVisibility);

        LabelGamesVisibility = new QLabel(FrameProfileBaseInfo);
        LabelGamesVisibility->setObjectName(QString::fromUtf8("LabelGamesVisibility"));
        sizePolicy.setHeightForWidth(LabelGamesVisibility->sizePolicy().hasHeightForWidth());
        LabelGamesVisibility->setSizePolicy(sizePolicy);
        LabelGamesVisibility->setFont(font3);

        verticalLayout_8->addWidget(LabelGamesVisibility);


        horizontalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout_15->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(FrameProfileBaseInfo);

        FrameProfileMaximumInfo = new QFrame(FormProfile);
        FrameProfileMaximumInfo->setObjectName(QString::fromUtf8("FrameProfileMaximumInfo"));
        FrameProfileMaximumInfo->setFrameShape(QFrame::StyledPanel);
        FrameProfileMaximumInfo->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(FrameProfileMaximumInfo);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Labellvl = new QLabel(FrameProfileMaximumInfo);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        sizePolicy.setHeightForWidth(Labellvl->sizePolicy().hasHeightForWidth());
        Labellvl->setSizePolicy(sizePolicy);
        Labellvl->setFont(font1);

        horizontalLayout_3->addWidget(Labellvl);

        LabellvlValue = new QLabel(FrameProfileMaximumInfo);
        LabellvlValue->setObjectName(QString::fromUtf8("LabellvlValue"));
        LabellvlValue->setMinimumSize(QSize(32, 32));
        LabellvlValue->setMaximumSize(QSize(16777215, 16777215));
        LabellvlValue->setFont(font2);
        LabellvlValue->setText(QString::fromUtf8("0"));
        LabellvlValue->setAlignment(Qt::AlignCenter);
        LabellvlValue->setMargin(5);

        horizontalLayout_3->addWidget(LabellvlValue);


        horizontalLayout_13->addLayout(horizontalLayout_3);

        line = new QFrame(FrameProfileMaximumInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LabelBans = new QLabel(FrameProfileMaximumInfo);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        sizePolicy.setHeightForWidth(LabelBans->sizePolicy().hasHeightForWidth());
        LabelBans->setSizePolicy(sizePolicy);
        LabelBans->setFont(font3);
        LabelBans->setText(QString::fromUtf8("VAC Bans: "));

        horizontalLayout_10->addWidget(LabelBans);

        LabelBansValue = new QLabel(FrameProfileMaximumInfo);
        LabelBansValue->setObjectName(QString::fromUtf8("LabelBansValue"));
        LabelBansValue->setFont(font3);
        LabelBansValue->setText(QString::fromUtf8("BansValue"));

        horizontalLayout_10->addWidget(LabelBansValue);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        horizontalLayout_13->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LabelTimeCreated = new QLabel(FrameProfileMaximumInfo);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        sizePolicy.setHeightForWidth(LabelTimeCreated->sizePolicy().hasHeightForWidth());
        LabelTimeCreated->setSizePolicy(sizePolicy);
        LabelTimeCreated->setFont(font1);

        horizontalLayout_4->addWidget(LabelTimeCreated);

        LabelTimeCreatedValue = new QLabel(FrameProfileMaximumInfo);
        LabelTimeCreatedValue->setObjectName(QString::fromUtf8("LabelTimeCreatedValue"));
        LabelTimeCreatedValue->setFont(font2);
        LabelTimeCreatedValue->setText(QString::fromUtf8("0"));

        horizontalLayout_4->addWidget(LabelTimeCreatedValue);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LabelProfileUrl = new QLabel(FrameProfileMaximumInfo);
        LabelProfileUrl->setObjectName(QString::fromUtf8("LabelProfileUrl"));
        LabelProfileUrl->setMaximumSize(QSize(16777215, 16));
        LabelProfileUrl->setFont(font1);
        LabelProfileUrl->setText(QString::fromUtf8("ProfileUrl"));
        LabelProfileUrl->setOpenExternalLinks(true);
        LabelProfileUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

        horizontalLayout_5->addWidget(LabelProfileUrl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LabelLocCountryCode = new QLabel(FrameProfileMaximumInfo);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        sizePolicy.setHeightForWidth(LabelLocCountryCode->sizePolicy().hasHeightForWidth());
        LabelLocCountryCode->setSizePolicy(sizePolicy);
        LabelLocCountryCode->setFont(font1);

        horizontalLayout_11->addWidget(LabelLocCountryCode);

        LabelLocCountryCodeValue = new QLabel(FrameProfileMaximumInfo);
        LabelLocCountryCodeValue->setObjectName(QString::fromUtf8("LabelLocCountryCodeValue"));
        LabelLocCountryCodeValue->setFont(font2);
        LabelLocCountryCodeValue->setText(QString::fromUtf8("EN"));

        horizontalLayout_11->addWidget(LabelLocCountryCodeValue);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        LabelProfileState = new QLabel(FrameProfileMaximumInfo);
        LabelProfileState->setObjectName(QString::fromUtf8("LabelProfileState"));
        LabelProfileState->setFont(font3);
        LabelProfileState->setText(QString::fromUtf8("ProfileState"));

        horizontalLayout_12->addWidget(LabelProfileState);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LabelCommentPermission = new QLabel(FrameProfileMaximumInfo);
        LabelCommentPermission->setObjectName(QString::fromUtf8("LabelCommentPermission"));
        LabelCommentPermission->setFont(font3);
        LabelCommentPermission->setText(QString::fromUtf8("CommentPermission"));

        horizontalLayout_8->addWidget(LabelCommentPermission);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_14->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(FrameProfileMaximumInfo);

        FrameProfileButtons = new QFrame(FormProfile);
        FrameProfileButtons->setObjectName(QString::fromUtf8("FrameProfileButtons"));
        FrameProfileButtons->setMinimumSize(QSize(0, 41));
        FrameProfileButtons->setFrameShape(QFrame::StyledPanel);
        FrameProfileButtons->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(FrameProfileButtons);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        LabelAvatarMinimize = new QLabel(FrameProfileButtons);
        LabelAvatarMinimize->setObjectName(QString::fromUtf8("LabelAvatarMinimize"));
        LabelAvatarMinimize->setText(QString::fromUtf8("Ava"));

        horizontalLayout_16->addWidget(LabelAvatarMinimize);

        LabelNameMinimize = new QLabel(FrameProfileButtons);
        LabelNameMinimize->setObjectName(QString::fromUtf8("LabelNameMinimize"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        LabelNameMinimize->setFont(font4);
        LabelNameMinimize->setText(QString::fromUtf8("Name"));

        horizontalLayout_16->addWidget(LabelNameMinimize);

        ButtonGames = new QPushButton(FrameProfileButtons);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);
        ButtonGames->setStyleSheet(QString::fromUtf8(""));
        ButtonGames->setText(QString::fromUtf8("Games"));

        horizontalLayout_16->addWidget(ButtonGames);

        ButtonFriends = new QPushButton(FrameProfileButtons);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));
        ButtonFriends->setText(QString::fromUtf8("Friends"));

        horizontalLayout_16->addWidget(ButtonFriends);

        ButtonStatistics = new QPushButton(FrameProfileButtons);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));
        ButtonStatistics->setText(QString::fromUtf8(" \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260"));

        horizontalLayout_16->addWidget(ButtonStatistics);

        ButtonFavorites = new QPushButton(FrameProfileButtons);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));
        ButtonFavorites->setText(QString::fromUtf8(" \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265"));

        horizontalLayout_16->addWidget(ButtonFavorites);

        horizontalSpacer_4 = new QSpacerItem(98, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_4);

        ButtonSetProfile = new QPushButton(FrameProfileButtons);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        horizontalLayout_16->addWidget(ButtonSetProfile);


        verticalLayout_3->addWidget(FrameProfileButtons);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(FormProfile);

        QMetaObject::connectSlotsByName(FormProfile);
    } // setupUi

    void retranslateUi(QWidget *FormProfile)
    {
        FormProfile->setWindowTitle(QCoreApplication::translate("FormProfile", "Form", nullptr));
        LabelRealName->setText(QCoreApplication::translate("FormProfile", "RealName: ", nullptr));
        LabelProfileVisibility->setText(QCoreApplication::translate("FormProfile", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        LabelFriendsVisibility->setText(QCoreApplication::translate("FormProfile", "\320\224\321\200\321\203\320\267\321\214\321\217", nullptr));
        LabelGamesVisibility->setText(QCoreApplication::translate("FormProfile", "\320\230\320\263\321\200\321\213", nullptr));
        Labellvl->setText(QCoreApplication::translate("FormProfile", "lvl:", nullptr));
        LabelTimeCreated->setText(QCoreApplication::translate("FormProfile", "TimeCreated:", nullptr));
        LabelLocCountryCode->setText(QCoreApplication::translate("FormProfile", "CountryCode:", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
