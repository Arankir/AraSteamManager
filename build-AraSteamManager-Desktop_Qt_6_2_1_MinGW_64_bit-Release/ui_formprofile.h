/********************************************************************************
** Form generated from reading UI file 'formprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROFILE_H
#define UI_FORMPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/collapsablewidget.h"
#include "subWidgets/labels/labellight.h"
#include "subWidgets/labels/labelvalue.h"

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
    LabelLight *LabelName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LabelRealName;
    LabelValue *LabelRealNameValue;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelPersonaState;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *LabelProfileStatus;
    QLabel *LabelFriendsStatus;
    QLabel *LabelGamesStatus;
    QVBoxLayout *verticalLayout_8;
    LabelLight *LabelProfileVisibility;
    LabelLight *LabelFriendsVisibility;
    LabelLight *LabelGamesVisibility;
    QFrame *FrameProfileMaximumInfo;
    QVBoxLayout *verticalLayout_14;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_18;
    LabelValue *LabellvlValue;
    QProgressBar *progressBarXp;
    CollapsableWidget *collapsableWidgetCommon;
    CollapsableWidget *collapsableWidgetBans;
    CollapsableWidget *collapsableWidgetBadges;
    CollapsableWidget *collapsableWidgetPlayTime;
    QFormLayout *formLayout;
    QLabel *label;
    LabelValue *labelWindowsPlayTimeValue;
    QLabel *label_3;
    LabelValue *labelLinuxPlayTimeValue;
    QLabel *label_5;
    LabelValue *labelMacOsPlayTimeValue;
    QLabel *label_7;
    LabelValue *labelTotalPlayTimeValue;
    CollapsableWidget *collapsableWidgetGamesPlayTime;
    CollapsableWidget *collapsableWidgetCustomizations;
    LabelLight *LabelProfileState;
    LabelLight *LabelCommentPermission;
    QFrame *FrameProfileButtons;
    QHBoxLayout *horizontalLayout_16;
    QLabel *LabelAvatarMinimize;
    LabelLight *LabelNameMinimize;
    QPushButton *ButtonGames;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonSetProfile;

    void setupUi(QWidget *FormProfile)
    {
        if (FormProfile->objectName().isEmpty())
            FormProfile->setObjectName(QString::fromUtf8("FormProfile"));
        FormProfile->resize(735, 893);
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
        LabelAvatar->setText(QString::fromUtf8(""));

        horizontalLayout_15->addWidget(LabelAvatar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelName = new LabelLight(FrameProfileBaseInfo);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));
        QFont font;
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
        font1.setPointSize(10);
        LabelRealName->setFont(font1);

        horizontalLayout_9->addWidget(LabelRealName);

        LabelRealNameValue = new LabelValue(FrameProfileBaseInfo);
        LabelRealNameValue->setObjectName(QString::fromUtf8("LabelRealNameValue"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelPersonaState->sizePolicy().hasHeightForWidth());
        LabelPersonaState->setSizePolicy(sizePolicy1);
        LabelPersonaState->setFont(font1);
        LabelPersonaState->setText(QString::fromUtf8("PersonaState"));
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        horizontalLayout_6->addWidget(LabelPersonaState);


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
        LabelProfileVisibility = new LabelLight(FrameProfileBaseInfo);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        sizePolicy.setHeightForWidth(LabelProfileVisibility->sizePolicy().hasHeightForWidth());
        LabelProfileVisibility->setSizePolicy(sizePolicy);
        LabelProfileVisibility->setFont(font1);

        verticalLayout_8->addWidget(LabelProfileVisibility);

        LabelFriendsVisibility = new LabelLight(FrameProfileBaseInfo);
        LabelFriendsVisibility->setObjectName(QString::fromUtf8("LabelFriendsVisibility"));
        sizePolicy.setHeightForWidth(LabelFriendsVisibility->sizePolicy().hasHeightForWidth());
        LabelFriendsVisibility->setSizePolicy(sizePolicy);
        LabelFriendsVisibility->setFont(font1);

        verticalLayout_8->addWidget(LabelFriendsVisibility);

        LabelGamesVisibility = new LabelLight(FrameProfileBaseInfo);
        LabelGamesVisibility->setObjectName(QString::fromUtf8("LabelGamesVisibility"));
        sizePolicy.setHeightForWidth(LabelGamesVisibility->sizePolicy().hasHeightForWidth());
        LabelGamesVisibility->setSizePolicy(sizePolicy);
        LabelGamesVisibility->setFont(font1);

        verticalLayout_8->addWidget(LabelGamesVisibility);


        horizontalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout_15->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(FrameProfileBaseInfo);

        FrameProfileMaximumInfo = new QFrame(FormProfile);
        FrameProfileMaximumInfo->setObjectName(QString::fromUtf8("FrameProfileMaximumInfo"));
        FrameProfileMaximumInfo->setFrameShape(QFrame::StyledPanel);
        FrameProfileMaximumInfo->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(FrameProfileMaximumInfo);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        scrollArea = new QScrollArea(FrameProfileMaximumInfo);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 713, 731));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        LabellvlValue = new LabelValue(scrollAreaWidgetContents);
        LabellvlValue->setObjectName(QString::fromUtf8("LabellvlValue"));
        LabellvlValue->setMinimumSize(QSize(32, 32));
        LabellvlValue->setMaximumSize(QSize(32, 32));
        LabellvlValue->setFont(font2);
        LabellvlValue->setText(QString::fromUtf8("0"));
        LabellvlValue->setAlignment(Qt::AlignCenter);
        LabellvlValue->setMargin(5);

        horizontalLayout_18->addWidget(LabellvlValue);

        progressBarXp = new QProgressBar(scrollAreaWidgetContents);
        progressBarXp->setObjectName(QString::fromUtf8("progressBarXp"));
        progressBarXp->setMaximum(101);
        progressBarXp->setValue(3);
        progressBarXp->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout_18->addWidget(progressBarXp);


        verticalLayout->addLayout(horizontalLayout_18);

        collapsableWidgetCommon = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetCommon->setObjectName(QString::fromUtf8("collapsableWidgetCommon"));
        collapsableWidgetCommon->setFrameShape(QFrame::StyledPanel);
        collapsableWidgetCommon->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(collapsableWidgetCommon);

        collapsableWidgetBans = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetBans->setObjectName(QString::fromUtf8("collapsableWidgetBans"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(collapsableWidgetBans->sizePolicy().hasHeightForWidth());
        collapsableWidgetBans->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(collapsableWidgetBans);

        collapsableWidgetBadges = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetBadges->setObjectName(QString::fromUtf8("collapsableWidgetBadges"));

        verticalLayout->addWidget(collapsableWidgetBadges);

        collapsableWidgetPlayTime = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetPlayTime->setObjectName(QString::fromUtf8("collapsableWidgetPlayTime"));
        formLayout = new QFormLayout(collapsableWidgetPlayTime);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(collapsableWidgetPlayTime);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        labelWindowsPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelWindowsPlayTimeValue->setObjectName(QString::fromUtf8("labelWindowsPlayTimeValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelWindowsPlayTimeValue);

        label_3 = new QLabel(collapsableWidgetPlayTime);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        labelLinuxPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelLinuxPlayTimeValue->setObjectName(QString::fromUtf8("labelLinuxPlayTimeValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelLinuxPlayTimeValue);

        label_5 = new QLabel(collapsableWidgetPlayTime);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        labelMacOsPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelMacOsPlayTimeValue->setObjectName(QString::fromUtf8("labelMacOsPlayTimeValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, labelMacOsPlayTimeValue);

        label_7 = new QLabel(collapsableWidgetPlayTime);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        labelTotalPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelTotalPlayTimeValue->setObjectName(QString::fromUtf8("labelTotalPlayTimeValue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, labelTotalPlayTimeValue);


        verticalLayout->addWidget(collapsableWidgetPlayTime);

        collapsableWidgetGamesPlayTime = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetGamesPlayTime->setObjectName(QString::fromUtf8("collapsableWidgetGamesPlayTime"));

        verticalLayout->addWidget(collapsableWidgetGamesPlayTime);

        collapsableWidgetCustomizations = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetCustomizations->setObjectName(QString::fromUtf8("collapsableWidgetCustomizations"));

        verticalLayout->addWidget(collapsableWidgetCustomizations);

        LabelProfileState = new LabelLight(scrollAreaWidgetContents);
        LabelProfileState->setObjectName(QString::fromUtf8("LabelProfileState"));
        LabelProfileState->setFont(font1);
        LabelProfileState->setText(QString::fromUtf8("ProfileState"));

        verticalLayout->addWidget(LabelProfileState);

        LabelCommentPermission = new LabelLight(scrollAreaWidgetContents);
        LabelCommentPermission->setObjectName(QString::fromUtf8("LabelCommentPermission"));
        LabelCommentPermission->setFont(font1);
        LabelCommentPermission->setText(QString::fromUtf8("CommentPermission"));

        verticalLayout->addWidget(LabelCommentPermission);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_14->addWidget(scrollArea);


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
        LabelAvatarMinimize->setText(QString::fromUtf8(""));

        horizontalLayout_16->addWidget(LabelAvatarMinimize);

        LabelNameMinimize = new LabelLight(FrameProfileButtons);
        LabelNameMinimize->setObjectName(QString::fromUtf8("LabelNameMinimize"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        LabelNameMinimize->setFont(font3);
        LabelNameMinimize->setText(QString::fromUtf8("Name"));

        horizontalLayout_16->addWidget(LabelNameMinimize);

        ButtonGames = new QPushButton(FrameProfileButtons);
        ButtonGames->setObjectName(QString::fromUtf8("ButtonGames"));
        ButtonGames->setEnabled(true);
        ButtonGames->setStyleSheet(QString::fromUtf8(""));
        ButtonGames->setText(QString::fromUtf8("Games"));
        ButtonGames->setChecked(false);

        horizontalLayout_16->addWidget(ButtonGames);

        ButtonFriends = new QPushButton(FrameProfileButtons);
        ButtonFriends->setObjectName(QString::fromUtf8("ButtonFriends"));
        ButtonFriends->setText(QString::fromUtf8("Friends"));

        horizontalLayout_16->addWidget(ButtonFriends);

        ButtonStatistics = new QPushButton(FrameProfileButtons);
        ButtonStatistics->setObjectName(QString::fromUtf8("ButtonStatistics"));
        ButtonStatistics->setText(QString::fromUtf8(" \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260"));

        horizontalLayout_16->addWidget(ButtonStatistics);

        horizontalSpacer_4 = new QSpacerItem(98, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_4);

        ButtonSetProfile = new QPushButton(FrameProfileButtons);
        ButtonSetProfile->setObjectName(QString::fromUtf8("ButtonSetProfile"));

        horizontalLayout_16->addWidget(ButtonSetProfile);


        verticalLayout_3->addWidget(FrameProfileButtons);


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
        progressBarXp->setFormat(QCoreApplication::translate("FormProfile", "%v/%m", nullptr));
        label->setText(QCoreApplication::translate("FormProfile", "Windows", nullptr));
        labelWindowsPlayTimeValue->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("FormProfile", "Linux", nullptr));
        labelLinuxPlayTimeValue->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("FormProfile", "MacOS", nullptr));
        labelMacOsPlayTimeValue->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("FormProfile", "Total", nullptr));
        labelTotalPlayTimeValue->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
