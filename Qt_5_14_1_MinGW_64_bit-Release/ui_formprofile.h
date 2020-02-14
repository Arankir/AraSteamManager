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
    QLabel *Labellvl;
    QFrame *line;
    QLabel *LabelTimeCreated;
    QFrame *line_2;
    QLabel *LabelLocCountryCode;
    QFrame *line_3;
    QLabel *LabelRealName;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LabelProfileVisibility;
    QLabel *LabelFriendsVisibility;
    QLabel *LabelGamesVisibility;
    QSpacerItem *horizontalSpacer_2;
    QLabel *LabelBans;
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
        FormProfile->resize(422, 190);
        verticalLayout = new QVBoxLayout(FormProfile);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LabelAvatar = new QLabel(FormProfile);
        LabelAvatar->setObjectName(QString::fromUtf8("LabelAvatar"));
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
        Labellvl = new QLabel(FrameInfo);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Labellvl->sizePolicy().hasHeightForWidth());
        Labellvl->setSizePolicy(sizePolicy);
        Labellvl->setFont(font1);
        Labellvl->setText(QString::fromUtf8("lvl"));

        horizontalLayoutInfo1->addWidget(Labellvl);

        line = new QFrame(FrameInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line);

        LabelTimeCreated = new QLabel(FrameInfo);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        sizePolicy.setHeightForWidth(LabelTimeCreated->sizePolicy().hasHeightForWidth());
        LabelTimeCreated->setSizePolicy(sizePolicy);
        LabelTimeCreated->setFont(font1);
        LabelTimeCreated->setText(QString::fromUtf8("TimeCreated"));

        horizontalLayoutInfo1->addWidget(LabelTimeCreated);

        line_2 = new QFrame(FrameInfo);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line_2);

        LabelLocCountryCode = new QLabel(FrameInfo);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        sizePolicy.setHeightForWidth(LabelLocCountryCode->sizePolicy().hasHeightForWidth());
        LabelLocCountryCode->setSizePolicy(sizePolicy);
        LabelLocCountryCode->setFont(font1);
        LabelLocCountryCode->setText(QString::fromUtf8("CountryCode"));

        horizontalLayoutInfo1->addWidget(LabelLocCountryCode);

        line_3 = new QFrame(FrameInfo);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayoutInfo1->addWidget(line_3);

        LabelRealName = new QLabel(FrameInfo);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        sizePolicy.setHeightForWidth(LabelRealName->sizePolicy().hasHeightForWidth());
        LabelRealName->setSizePolicy(sizePolicy);
        LabelRealName->setFont(font1);
        LabelRealName->setText(QString::fromUtf8("RealName"));

        horizontalLayoutInfo1->addWidget(LabelRealName);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutInfo1->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayoutInfo1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LabelProfileVisibility = new QLabel(FrameInfo);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        sizePolicy.setHeightForWidth(LabelProfileVisibility->sizePolicy().hasHeightForWidth());
        LabelProfileVisibility->setSizePolicy(sizePolicy);
        LabelProfileVisibility->setFont(font1);

        horizontalLayout_3->addWidget(LabelProfileVisibility);

        LabelFriendsVisibility = new QLabel(FrameInfo);
        LabelFriendsVisibility->setObjectName(QString::fromUtf8("LabelFriendsVisibility"));
        sizePolicy.setHeightForWidth(LabelFriendsVisibility->sizePolicy().hasHeightForWidth());
        LabelFriendsVisibility->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(LabelFriendsVisibility);

        LabelGamesVisibility = new QLabel(FrameInfo);
        LabelGamesVisibility->setObjectName(QString::fromUtf8("LabelGamesVisibility"));
        sizePolicy.setHeightForWidth(LabelGamesVisibility->sizePolicy().hasHeightForWidth());
        LabelGamesVisibility->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(LabelGamesVisibility);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        LabelBans = new QLabel(FrameInfo);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        sizePolicy.setHeightForWidth(LabelBans->sizePolicy().hasHeightForWidth());
        LabelBans->setSizePolicy(sizePolicy);
        LabelBans->setFont(font1);
        LabelBans->setText(QString::fromUtf8("Bans"));

        verticalLayout_3->addWidget(LabelBans);


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
        LabelProfileVisibility->setText(QCoreApplication::translate("FormProfile", "Profile", nullptr));
        LabelFriendsVisibility->setText(QCoreApplication::translate("FormProfile", "Friends", nullptr));
        LabelGamesVisibility->setText(QCoreApplication::translate("FormProfile", "Games", nullptr));
        ButtonStatistics->setText(QCoreApplication::translate("FormProfile", " \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        ButtonFavorites->setText(QCoreApplication::translate("FormProfile", " \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
