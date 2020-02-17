/********************************************************************************
** Form generated from reading UI file 'formprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LabelAvatar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelNick;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSetProfile;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelPersonaState;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelProfileUrl;
    QSpacerItem *horizontalSpacer_3;
    QFrame *FrameInfo;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutInfo1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Labellvl;
    QLabel *LabellvlValue;
    QFrame *line;
    QHBoxLayout *horizontalLayout_12;
    QLabel *LabelTimeCreated;
    QLabel *LabelTimeCreatedValue;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *LabelLocCountryCode;
    QLabel *LabelLocCountryCodeValue;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *LabelRealName;
    QLabel *LabelRealNameValue;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelProfileStatus;
    QLabel *LabelProfileVisibility;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelFriendsStatus;
    QLabel *LabelFriendsVisibility;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LabelGamesStatus;
    QLabel *LabelGamesVisibility;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LabelBans;
    QLabel *LabelBansNone;
    QLabel *LabelBansNotNone;
    QLabel *LabelBansLast;
    QLabel *LabelBansDays;
    QLabel *LabelBansDaysAgo;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonGames;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QPushButton *ButtonFavorites;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormProfile)
    {
        if (FormProfile->objectName().isEmpty())
            FormProfile->setObjectName(QString::fromUtf8("FormProfile"));
        FormProfile->resize(802, 385);
        verticalLayout = new QVBoxLayout(FormProfile);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LabelAvatar = new QLabel(FormProfile);
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
        LabelNick = new QLabel(FormProfile);
        LabelNick->setObjectName(QString::fromUtf8("LabelNick"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        LabelNick->setFont(font);
        LabelNick->setText(QString::fromUtf8("NickName"));

        horizontalLayout_7->addWidget(LabelNick);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        ButtonSetProfile = new QPushButton(FormProfile);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        horizontalLayout_7->addWidget(ButtonSetProfile);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelPersonaState = new QLabel(FormProfile);
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
        LabelProfileUrl = new QLabel(FormProfile);
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

        FrameInfo = new QFrame(FormProfile);
        FrameInfo->setObjectName(QString::fromUtf8("FrameInfo"));
        FrameInfo->setFrameShape(QFrame::StyledPanel);
        FrameInfo->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameInfo);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutInfo1 = new QHBoxLayout();
        horizontalLayoutInfo1->setSpacing(2);
        horizontalLayoutInfo1->setObjectName(QString::fromUtf8("horizontalLayoutInfo1"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(1);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        Labellvl = new QLabel(FrameInfo);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Labellvl->sizePolicy().hasHeightForWidth());
        Labellvl->setSizePolicy(sizePolicy);
        Labellvl->setFont(font1);

        horizontalLayout_11->addWidget(Labellvl);

        LabellvlValue = new QLabel(FrameInfo);
        LabellvlValue->setObjectName(QString::fromUtf8("LabellvlValue"));
        QFont font2;
        font2.setPointSize(10);
        LabellvlValue->setFont(font2);
        LabellvlValue->setText(QString::fromUtf8("0"));

        horizontalLayout_11->addWidget(LabellvlValue);


        horizontalLayoutInfo1->addLayout(horizontalLayout_11);

        line = new QFrame(FrameInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(1);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        LabelTimeCreated = new QLabel(FrameInfo);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        sizePolicy.setHeightForWidth(LabelTimeCreated->sizePolicy().hasHeightForWidth());
        LabelTimeCreated->setSizePolicy(sizePolicy);
        LabelTimeCreated->setFont(font1);

        horizontalLayout_12->addWidget(LabelTimeCreated);

        LabelTimeCreatedValue = new QLabel(FrameInfo);
        LabelTimeCreatedValue->setObjectName(QString::fromUtf8("LabelTimeCreatedValue"));
        LabelTimeCreatedValue->setFont(font2);
        LabelTimeCreatedValue->setText(QString::fromUtf8("0"));

        horizontalLayout_12->addWidget(LabelTimeCreatedValue);


        horizontalLayoutInfo1->addLayout(horizontalLayout_12);

        line_2 = new QFrame(FrameInfo);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(1);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        LabelLocCountryCode = new QLabel(FrameInfo);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        sizePolicy.setHeightForWidth(LabelLocCountryCode->sizePolicy().hasHeightForWidth());
        LabelLocCountryCode->setSizePolicy(sizePolicy);
        LabelLocCountryCode->setFont(font1);

        horizontalLayout_13->addWidget(LabelLocCountryCode);

        LabelLocCountryCodeValue = new QLabel(FrameInfo);
        LabelLocCountryCodeValue->setObjectName(QString::fromUtf8("LabelLocCountryCodeValue"));
        LabelLocCountryCodeValue->setFont(font2);
        LabelLocCountryCodeValue->setText(QString::fromUtf8("EN"));

        horizontalLayout_13->addWidget(LabelLocCountryCodeValue);


        horizontalLayoutInfo1->addLayout(horizontalLayout_13);

        line_3 = new QFrame(FrameInfo);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(1);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        LabelRealName = new QLabel(FrameInfo);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        sizePolicy.setHeightForWidth(LabelRealName->sizePolicy().hasHeightForWidth());
        LabelRealName->setSizePolicy(sizePolicy);
        LabelRealName->setFont(font1);

        horizontalLayout_14->addWidget(LabelRealName);

        LabelRealNameValue = new QLabel(FrameInfo);
        LabelRealNameValue->setObjectName(QString::fromUtf8("LabelRealNameValue"));
        LabelRealNameValue->setFont(font2);
        LabelRealNameValue->setText(QString::fromUtf8("none"));

        horizontalLayout_14->addWidget(LabelRealNameValue);


        horizontalLayoutInfo1->addLayout(horizontalLayout_14);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutInfo1->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayoutInfo1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelProfileStatus = new QLabel(FrameInfo);
        LabelProfileStatus->setObjectName(QString::fromUtf8("LabelProfileStatus"));
        LabelProfileStatus->setText(QString::fromUtf8("S"));

        horizontalLayout_2->addWidget(LabelProfileStatus);

        LabelProfileVisibility = new QLabel(FrameInfo);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        sizePolicy.setHeightForWidth(LabelProfileVisibility->sizePolicy().hasHeightForWidth());
        LabelProfileVisibility->setSizePolicy(sizePolicy);
        LabelProfileVisibility->setFont(font2);

        horizontalLayout_2->addWidget(LabelProfileVisibility);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LabelFriendsStatus = new QLabel(FrameInfo);
        LabelFriendsStatus->setObjectName(QString::fromUtf8("LabelFriendsStatus"));
        LabelFriendsStatus->setText(QString::fromUtf8("S"));

        horizontalLayout_4->addWidget(LabelFriendsStatus);

        LabelFriendsVisibility = new QLabel(FrameInfo);
        LabelFriendsVisibility->setObjectName(QString::fromUtf8("LabelFriendsVisibility"));
        sizePolicy.setHeightForWidth(LabelFriendsVisibility->sizePolicy().hasHeightForWidth());
        LabelFriendsVisibility->setSizePolicy(sizePolicy);
        LabelFriendsVisibility->setFont(font2);

        horizontalLayout_4->addWidget(LabelFriendsVisibility);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(1);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LabelGamesStatus = new QLabel(FrameInfo);
        LabelGamesStatus->setObjectName(QString::fromUtf8("LabelGamesStatus"));
        LabelGamesStatus->setText(QString::fromUtf8("S"));

        horizontalLayout_9->addWidget(LabelGamesStatus);

        LabelGamesVisibility = new QLabel(FrameInfo);
        LabelGamesVisibility->setObjectName(QString::fromUtf8("LabelGamesVisibility"));
        sizePolicy.setHeightForWidth(LabelGamesVisibility->sizePolicy().hasHeightForWidth());
        LabelGamesVisibility->setSizePolicy(sizePolicy);
        LabelGamesVisibility->setFont(font2);

        horizontalLayout_9->addWidget(LabelGamesVisibility);


        horizontalLayout_3->addLayout(horizontalLayout_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LabelBans = new QLabel(FrameInfo);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        sizePolicy.setHeightForWidth(LabelBans->sizePolicy().hasHeightForWidth());
        LabelBans->setSizePolicy(sizePolicy);
        LabelBans->setFont(font2);
        LabelBans->setText(QString::fromUtf8("VAC Bans: "));

        horizontalLayout_10->addWidget(LabelBans);

        LabelBansNone = new QLabel(FrameInfo);
        LabelBansNone->setObjectName(QString::fromUtf8("LabelBansNone"));
        LabelBansNone->setFont(font2);

        horizontalLayout_10->addWidget(LabelBansNone);

        LabelBansNotNone = new QLabel(FrameInfo);
        LabelBansNotNone->setObjectName(QString::fromUtf8("LabelBansNotNone"));
        LabelBansNotNone->setFont(font2);
        LabelBansNotNone->setText(QString::fromUtf8("0"));

        horizontalLayout_10->addWidget(LabelBansNotNone);

        LabelBansLast = new QLabel(FrameInfo);
        LabelBansLast->setObjectName(QString::fromUtf8("LabelBansLast"));
        LabelBansLast->setFont(font2);

        horizontalLayout_10->addWidget(LabelBansLast);

        LabelBansDays = new QLabel(FrameInfo);
        LabelBansDays->setObjectName(QString::fromUtf8("LabelBansDays"));
        LabelBansDays->setFont(font2);
        LabelBansDays->setText(QString::fromUtf8("000-00-00"));

        horizontalLayout_10->addWidget(LabelBansDays);

        LabelBansDaysAgo = new QLabel(FrameInfo);
        LabelBansDaysAgo->setObjectName(QString::fromUtf8("LabelBansDaysAgo"));
        LabelBansDaysAgo->setFont(font2);

        horizontalLayout_10->addWidget(LabelBansDaysAgo);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout->addWidget(FrameInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 2);
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

        horizontalLayout->addWidget(ButtonStatistics);

        ButtonFavorites = new QPushButton(FormProfile);
        ButtonFavorites->setObjectName(QString::fromUtf8("ButtonFavorites"));

        horizontalLayout->addWidget(ButtonFavorites);

        horizontalSpacer_4 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FormProfile);

        QMetaObject::connectSlotsByName(FormProfile);
    } // setupUi

    void retranslateUi(QWidget *FormProfile)
    {
        FormProfile->setWindowTitle(QCoreApplication::translate("FormProfile", "Form", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        Labellvl->setText(QCoreApplication::translate("FormProfile", "lvl:", nullptr));
        LabelTimeCreated->setText(QCoreApplication::translate("FormProfile", "TimeCreated:", nullptr));
        LabelLocCountryCode->setText(QCoreApplication::translate("FormProfile", "CountryCode:", nullptr));
        LabelRealName->setText(QCoreApplication::translate("FormProfile", "RealName:", nullptr));
        LabelProfileVisibility->setText(QCoreApplication::translate("FormProfile", "Profile", nullptr));
        LabelFriendsVisibility->setText(QCoreApplication::translate("FormProfile", "Friends", nullptr));
        LabelGamesVisibility->setText(QCoreApplication::translate("FormProfile", "Games", nullptr));
        LabelBansNone->setText(QCoreApplication::translate("FormProfile", "None", nullptr));
        LabelBansLast->setText(QCoreApplication::translate("FormProfile", "Last", nullptr));
        LabelBansDaysAgo->setText(QCoreApplication::translate("FormProfile", "days ago.", nullptr));
        ButtonStatistics->setText(QCoreApplication::translate("FormProfile", " \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        ButtonFavorites->setText(QCoreApplication::translate("FormProfile", " \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
