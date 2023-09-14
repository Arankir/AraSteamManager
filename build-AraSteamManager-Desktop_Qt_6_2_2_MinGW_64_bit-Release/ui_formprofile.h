/********************************************************************************
** Form generated from reading UI file 'formprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
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
    QHBoxLayout *horizontalLayout_17;
    QLabel *LabelProfileStatus;
    QLabel *LabelFriendsStatus;
    QLabel *LabelGamesStatus;
    QFrame *FrameProfileMaximumInfo;
    QVBoxLayout *verticalLayout_14;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_18;
    LabelValue *LabellvlValue;
    QProgressBar *progressBarXp;
    CollapsableWidget *collapsableWidgetCommon;
    QFormLayout *layoutCommon;
    QLabel *labelVanityUrl;
    LabelValue *labelVanityUrlValue;
    QLabel *label_6;
    LabelValue *labelAccountIdValue;
    QLabel *labelLinkValue;
    QLabel *labelAccountCreated;
    LabelValue *labelAccountCreatedValue;
    QLabel *labelLanguage;
    LabelValue *labelLanguageValue;
    LabelLight *LabelProfileState;
    LabelLight *LabelCommentPermission;
    CollapsableWidget *collapsableWidgetBans;
    QFormLayout *layoutBans;
    QLabel *label_14;
    LabelLight *labelGameBansValue;
    QLabel *label_16;
    LabelLight *labelVacBansValue;
    QLabel *label_19;
    LabelLight *labelCommunityBanValue;
    QLabel *label_21;
    LabelLight *labelTradeBanValue;
    CollapsableWidget *collapsableWidgetBadges;
    QFormLayout *layoutBadges;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSpecialBadges;
    LabelValue *labelSpecialBadgesValue;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelNormalBadges;
    LabelValue *labelNormalBadgesValue;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelNormalLvl1;
    LabelValue *labelNormalLvl1Value;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelNormalLvl2;
    LabelValue *labelNormalLvl2Value;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelNormalLvl3;
    LabelValue *labelNormalLvl3Value;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelNormalLvl4;
    LabelValue *labelNormalLvl4Value;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelNormalLvl5;
    LabelValue *labelNormalLvl5Value;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelNormalLvl5plus;
    LabelValue *labelNormalLvl5plusValue;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelFoilBadges;
    LabelValue *labelFoilBadgesValue;
    QSpacerItem *horizontalSpacer_3;
    CollapsableWidget *collapsableWidgetPlayTime;
    QFormLayout *layoutPlayTime;
    QLabel *labelWindowsPlayTime;
    LabelValue *labelWindowsPlayTimeValue;
    QLabel *labelLinuxPlayTime;
    LabelValue *labelLinuxPlayTimeValue;
    QLabel *labelMacOsPlayTime;
    LabelValue *labelMacOsPlayTimeValue;
    QLabel *labelTotalPlayTime;
    LabelValue *labelTotalPlayTimeValue;
    CollapsableWidget *collapsableWidgetGamesPlayTime;
    QFormLayout *layoutGamesPlayTime;
    QLabel *label_46;
    LabelValue *labelPlayTime0Value;
    QLabel *label_50;
    LabelValue *labelPlayTime0_1Value;
    QLabel *label_48;
    LabelValue *labelPlayTime1_10Value;
    QLabel *label_44;
    LabelValue *labelPlayTime10_24Value;
    QLabel *label_47;
    LabelValue *labelPlayTime24_240Value;
    QLabel *label_41;
    LabelValue *labelPlayTime240_500Value;
    QLabel *label_45;
    LabelValue *labelPlayTime500_1000Value;
    QLabel *label_43;
    LabelValue *labelPlayTime1000plusValue;
    CollapsableWidget *collapsableWidgetCustomizations;
    QFormLayout *layoutCustomizations;
    QLabel *label_55;
    LabelValue *labelCustomizationBackgroundValue;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    LabelValue *labelCustomizationMiniProfileValue;
    LabelValue *labelCustomizationAvatarFrameValue;
    LabelValue *labelCustomizationAnimatedAvatarValue;
    LabelValue *labelCustomizationPointsPurchasesValue;
    LabelValue *labelCustomizationPointsUpgradesValue;
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
        FormProfile->resize(723, 409);
        verticalLayout_3 = new QVBoxLayout(FormProfile);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        FrameProfileBaseInfo = new QFrame(FormProfile);
        FrameProfileBaseInfo->setObjectName(QString::fromUtf8("FrameProfileBaseInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrameProfileBaseInfo->sizePolicy().hasHeightForWidth());
        FrameProfileBaseInfo->setSizePolicy(sizePolicy);
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelRealName->sizePolicy().hasHeightForWidth());
        LabelRealName->setSizePolicy(sizePolicy1);
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
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LabelPersonaState->sizePolicy().hasHeightForWidth());
        LabelPersonaState->setSizePolicy(sizePolicy2);
        LabelPersonaState->setFont(font1);
        LabelPersonaState->setText(QString::fromUtf8("PersonaState"));
        LabelPersonaState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LabelPersonaState->setWordWrap(true);

        horizontalLayout_6->addWidget(LabelPersonaState);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        LabelProfileStatus = new QLabel(FrameProfileBaseInfo);
        LabelProfileStatus->setObjectName(QString::fromUtf8("LabelProfileStatus"));
        LabelProfileStatus->setText(QString::fromUtf8("SP"));

        horizontalLayout_17->addWidget(LabelProfileStatus);

        LabelFriendsStatus = new QLabel(FrameProfileBaseInfo);
        LabelFriendsStatus->setObjectName(QString::fromUtf8("LabelFriendsStatus"));
        LabelFriendsStatus->setText(QString::fromUtf8("SF"));

        horizontalLayout_17->addWidget(LabelFriendsStatus);

        LabelGamesStatus = new QLabel(FrameProfileBaseInfo);
        LabelGamesStatus->setObjectName(QString::fromUtf8("LabelGamesStatus"));
        LabelGamesStatus->setText(QString::fromUtf8("SG"));

        horizontalLayout_17->addWidget(LabelGamesStatus);


        horizontalLayout_2->addLayout(horizontalLayout_17);


        horizontalLayout_15->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(FrameProfileBaseInfo);

        FrameProfileMaximumInfo = new QFrame(FormProfile);
        FrameProfileMaximumInfo->setObjectName(QString::fromUtf8("FrameProfileMaximumInfo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FrameProfileMaximumInfo->sizePolicy().hasHeightForWidth());
        FrameProfileMaximumInfo->setSizePolicy(sizePolicy3);
        FrameProfileMaximumInfo->setMaximumSize(QSize(16777215, 250));
        FrameProfileMaximumInfo->setFrameShape(QFrame::StyledPanel);
        FrameProfileMaximumInfo->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(FrameProfileMaximumInfo);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        scrollArea = new QScrollArea(FrameProfileMaximumInfo);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 687, 1004));
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
        layoutCommon = new QFormLayout(collapsableWidgetCommon);
        layoutCommon->setObjectName(QString::fromUtf8("layoutCommon"));
        labelVanityUrl = new QLabel(collapsableWidgetCommon);
        labelVanityUrl->setObjectName(QString::fromUtf8("labelVanityUrl"));

        layoutCommon->setWidget(0, QFormLayout::LabelRole, labelVanityUrl);

        labelVanityUrlValue = new LabelValue(collapsableWidgetCommon);
        labelVanityUrlValue->setObjectName(QString::fromUtf8("labelVanityUrlValue"));
        labelVanityUrlValue->setText(QString::fromUtf8("Unknown"));

        layoutCommon->setWidget(0, QFormLayout::FieldRole, labelVanityUrlValue);

        label_6 = new QLabel(collapsableWidgetCommon);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        layoutCommon->setWidget(1, QFormLayout::LabelRole, label_6);

        labelAccountIdValue = new LabelValue(collapsableWidgetCommon);
        labelAccountIdValue->setObjectName(QString::fromUtf8("labelAccountIdValue"));
        labelAccountIdValue->setText(QString::fromUtf8("Unknown"));

        layoutCommon->setWidget(1, QFormLayout::FieldRole, labelAccountIdValue);

        labelLinkValue = new QLabel(collapsableWidgetCommon);
        labelLinkValue->setObjectName(QString::fromUtf8("labelLinkValue"));
        labelLinkValue->setText(QString::fromUtf8(""));

        layoutCommon->setWidget(2, QFormLayout::SpanningRole, labelLinkValue);

        labelAccountCreated = new QLabel(collapsableWidgetCommon);
        labelAccountCreated->setObjectName(QString::fromUtf8("labelAccountCreated"));

        layoutCommon->setWidget(3, QFormLayout::LabelRole, labelAccountCreated);

        labelAccountCreatedValue = new LabelValue(collapsableWidgetCommon);
        labelAccountCreatedValue->setObjectName(QString::fromUtf8("labelAccountCreatedValue"));
        labelAccountCreatedValue->setText(QString::fromUtf8("Unknown"));

        layoutCommon->setWidget(3, QFormLayout::FieldRole, labelAccountCreatedValue);

        labelLanguage = new QLabel(collapsableWidgetCommon);
        labelLanguage->setObjectName(QString::fromUtf8("labelLanguage"));

        layoutCommon->setWidget(4, QFormLayout::LabelRole, labelLanguage);

        labelLanguageValue = new LabelValue(collapsableWidgetCommon);
        labelLanguageValue->setObjectName(QString::fromUtf8("labelLanguageValue"));
        labelLanguageValue->setText(QString::fromUtf8("Unknown"));

        layoutCommon->setWidget(4, QFormLayout::FieldRole, labelLanguageValue);

        LabelProfileState = new LabelLight(collapsableWidgetCommon);
        LabelProfileState->setObjectName(QString::fromUtf8("LabelProfileState"));
        LabelProfileState->setFont(font1);
        LabelProfileState->setText(QString::fromUtf8("ProfileState"));

        layoutCommon->setWidget(5, QFormLayout::SpanningRole, LabelProfileState);

        LabelCommentPermission = new LabelLight(collapsableWidgetCommon);
        LabelCommentPermission->setObjectName(QString::fromUtf8("LabelCommentPermission"));
        LabelCommentPermission->setFont(font1);
        LabelCommentPermission->setText(QString::fromUtf8("CommentPermission"));

        layoutCommon->setWidget(6, QFormLayout::SpanningRole, LabelCommentPermission);


        verticalLayout->addWidget(collapsableWidgetCommon);

        collapsableWidgetBans = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetBans->setObjectName(QString::fromUtf8("collapsableWidgetBans"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(collapsableWidgetBans->sizePolicy().hasHeightForWidth());
        collapsableWidgetBans->setSizePolicy(sizePolicy4);
        layoutBans = new QFormLayout(collapsableWidgetBans);
        layoutBans->setObjectName(QString::fromUtf8("layoutBans"));
        label_14 = new QLabel(collapsableWidgetBans);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        layoutBans->setWidget(0, QFormLayout::LabelRole, label_14);

        labelGameBansValue = new LabelLight(collapsableWidgetBans);
        labelGameBansValue->setObjectName(QString::fromUtf8("labelGameBansValue"));
        labelGameBansValue->setText(QString::fromUtf8("Unknown"));

        layoutBans->setWidget(0, QFormLayout::FieldRole, labelGameBansValue);

        label_16 = new QLabel(collapsableWidgetBans);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        layoutBans->setWidget(1, QFormLayout::LabelRole, label_16);

        labelVacBansValue = new LabelLight(collapsableWidgetBans);
        labelVacBansValue->setObjectName(QString::fromUtf8("labelVacBansValue"));
        labelVacBansValue->setText(QString::fromUtf8("Unknown"));

        layoutBans->setWidget(1, QFormLayout::FieldRole, labelVacBansValue);

        label_19 = new QLabel(collapsableWidgetBans);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        layoutBans->setWidget(2, QFormLayout::LabelRole, label_19);

        labelCommunityBanValue = new LabelLight(collapsableWidgetBans);
        labelCommunityBanValue->setObjectName(QString::fromUtf8("labelCommunityBanValue"));
        labelCommunityBanValue->setText(QString::fromUtf8("Unknown"));

        layoutBans->setWidget(2, QFormLayout::FieldRole, labelCommunityBanValue);

        label_21 = new QLabel(collapsableWidgetBans);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        layoutBans->setWidget(3, QFormLayout::LabelRole, label_21);

        labelTradeBanValue = new LabelLight(collapsableWidgetBans);
        labelTradeBanValue->setObjectName(QString::fromUtf8("labelTradeBanValue"));
        labelTradeBanValue->setText(QString::fromUtf8("Unknown"));

        layoutBans->setWidget(3, QFormLayout::FieldRole, labelTradeBanValue);


        verticalLayout->addWidget(collapsableWidgetBans);

        collapsableWidgetBadges = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetBadges->setObjectName(QString::fromUtf8("collapsableWidgetBadges"));
        layoutBadges = new QFormLayout(collapsableWidgetBadges);
        layoutBadges->setObjectName(QString::fromUtf8("layoutBadges"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelSpecialBadges = new QLabel(collapsableWidgetBadges);
        labelSpecialBadges->setObjectName(QString::fromUtf8("labelSpecialBadges"));
        labelSpecialBadges->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout->addWidget(labelSpecialBadges);

        labelSpecialBadgesValue = new LabelValue(collapsableWidgetBadges);
        labelSpecialBadgesValue->setObjectName(QString::fromUtf8("labelSpecialBadgesValue"));
        labelSpecialBadgesValue->setText(QString::fromUtf8("Unknown"));

        horizontalLayout->addWidget(labelSpecialBadgesValue);


        layoutBadges->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(534, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutBadges->setItem(0, QFormLayout::FieldRole, horizontalSpacer_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelNormalBadges = new QLabel(collapsableWidgetBadges);
        labelNormalBadges->setObjectName(QString::fromUtf8("labelNormalBadges"));
        labelNormalBadges->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_3->addWidget(labelNormalBadges);

        labelNormalBadgesValue = new LabelValue(collapsableWidgetBadges);
        labelNormalBadgesValue->setObjectName(QString::fromUtf8("labelNormalBadgesValue"));
        labelNormalBadgesValue->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_3->addWidget(labelNormalBadgesValue);


        horizontalLayout_14->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelNormalLvl1 = new QLabel(collapsableWidgetBadges);
        labelNormalLvl1->setObjectName(QString::fromUtf8("labelNormalLvl1"));
        labelNormalLvl1->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_5->addWidget(labelNormalLvl1);

        labelNormalLvl1Value = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl1Value->setObjectName(QString::fromUtf8("labelNormalLvl1Value"));
        labelNormalLvl1Value->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_5->addWidget(labelNormalLvl1Value);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelNormalLvl2 = new QLabel(collapsableWidgetBadges);
        labelNormalLvl2->setObjectName(QString::fromUtf8("labelNormalLvl2"));
        labelNormalLvl2->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_8->addWidget(labelNormalLvl2);

        labelNormalLvl2Value = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl2Value->setObjectName(QString::fromUtf8("labelNormalLvl2Value"));
        labelNormalLvl2Value->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_8->addWidget(labelNormalLvl2Value);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelNormalLvl3 = new QLabel(collapsableWidgetBadges);
        labelNormalLvl3->setObjectName(QString::fromUtf8("labelNormalLvl3"));
        labelNormalLvl3->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_10->addWidget(labelNormalLvl3);

        labelNormalLvl3Value = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl3Value->setObjectName(QString::fromUtf8("labelNormalLvl3Value"));
        labelNormalLvl3Value->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_10->addWidget(labelNormalLvl3Value);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        labelNormalLvl4 = new QLabel(collapsableWidgetBadges);
        labelNormalLvl4->setObjectName(QString::fromUtf8("labelNormalLvl4"));
        labelNormalLvl4->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_11->addWidget(labelNormalLvl4);

        labelNormalLvl4Value = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl4Value->setObjectName(QString::fromUtf8("labelNormalLvl4Value"));
        labelNormalLvl4Value->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_11->addWidget(labelNormalLvl4Value);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        labelNormalLvl5 = new QLabel(collapsableWidgetBadges);
        labelNormalLvl5->setObjectName(QString::fromUtf8("labelNormalLvl5"));
        labelNormalLvl5->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_12->addWidget(labelNormalLvl5);

        labelNormalLvl5Value = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl5Value->setObjectName(QString::fromUtf8("labelNormalLvl5Value"));
        labelNormalLvl5Value->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_12->addWidget(labelNormalLvl5Value);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        labelNormalLvl5plus = new QLabel(collapsableWidgetBadges);
        labelNormalLvl5plus->setObjectName(QString::fromUtf8("labelNormalLvl5plus"));
        labelNormalLvl5plus->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_13->addWidget(labelNormalLvl5plus);

        labelNormalLvl5plusValue = new LabelValue(collapsableWidgetBadges);
        labelNormalLvl5plusValue->setObjectName(QString::fromUtf8("labelNormalLvl5plusValue"));
        labelNormalLvl5plusValue->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_13->addWidget(labelNormalLvl5plusValue);


        verticalLayout_4->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);


        layoutBadges->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_14);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelFoilBadges = new QLabel(collapsableWidgetBadges);
        labelFoilBadges->setObjectName(QString::fromUtf8("labelFoilBadges"));
        labelFoilBadges->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_4->addWidget(labelFoilBadges);

        labelFoilBadgesValue = new LabelValue(collapsableWidgetBadges);
        labelFoilBadgesValue->setObjectName(QString::fromUtf8("labelFoilBadgesValue"));
        labelFoilBadgesValue->setText(QString::fromUtf8("Unknown"));

        horizontalLayout_4->addWidget(labelFoilBadgesValue);


        layoutBadges->setLayout(2, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(562, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutBadges->setItem(2, QFormLayout::FieldRole, horizontalSpacer_3);


        verticalLayout->addWidget(collapsableWidgetBadges);

        collapsableWidgetPlayTime = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetPlayTime->setObjectName(QString::fromUtf8("collapsableWidgetPlayTime"));
        layoutPlayTime = new QFormLayout(collapsableWidgetPlayTime);
        layoutPlayTime->setObjectName(QString::fromUtf8("layoutPlayTime"));
        labelWindowsPlayTime = new QLabel(collapsableWidgetPlayTime);
        labelWindowsPlayTime->setObjectName(QString::fromUtf8("labelWindowsPlayTime"));
        labelWindowsPlayTime->setText(QString::fromUtf8("Windows"));

        layoutPlayTime->setWidget(0, QFormLayout::LabelRole, labelWindowsPlayTime);

        labelWindowsPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelWindowsPlayTimeValue->setObjectName(QString::fromUtf8("labelWindowsPlayTimeValue"));
        labelWindowsPlayTimeValue->setText(QString::fromUtf8("Unknown"));

        layoutPlayTime->setWidget(0, QFormLayout::FieldRole, labelWindowsPlayTimeValue);

        labelLinuxPlayTime = new QLabel(collapsableWidgetPlayTime);
        labelLinuxPlayTime->setObjectName(QString::fromUtf8("labelLinuxPlayTime"));
        labelLinuxPlayTime->setText(QString::fromUtf8("Linux"));

        layoutPlayTime->setWidget(1, QFormLayout::LabelRole, labelLinuxPlayTime);

        labelLinuxPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelLinuxPlayTimeValue->setObjectName(QString::fromUtf8("labelLinuxPlayTimeValue"));
        labelLinuxPlayTimeValue->setText(QString::fromUtf8("Unknown"));

        layoutPlayTime->setWidget(1, QFormLayout::FieldRole, labelLinuxPlayTimeValue);

        labelMacOsPlayTime = new QLabel(collapsableWidgetPlayTime);
        labelMacOsPlayTime->setObjectName(QString::fromUtf8("labelMacOsPlayTime"));
        labelMacOsPlayTime->setText(QString::fromUtf8("MacOS"));

        layoutPlayTime->setWidget(2, QFormLayout::LabelRole, labelMacOsPlayTime);

        labelMacOsPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelMacOsPlayTimeValue->setObjectName(QString::fromUtf8("labelMacOsPlayTimeValue"));
        labelMacOsPlayTimeValue->setText(QString::fromUtf8("Unknown"));

        layoutPlayTime->setWidget(2, QFormLayout::FieldRole, labelMacOsPlayTimeValue);

        labelTotalPlayTime = new QLabel(collapsableWidgetPlayTime);
        labelTotalPlayTime->setObjectName(QString::fromUtf8("labelTotalPlayTime"));
        labelTotalPlayTime->setText(QString::fromUtf8("Total"));

        layoutPlayTime->setWidget(3, QFormLayout::LabelRole, labelTotalPlayTime);

        labelTotalPlayTimeValue = new LabelValue(collapsableWidgetPlayTime);
        labelTotalPlayTimeValue->setObjectName(QString::fromUtf8("labelTotalPlayTimeValue"));
        labelTotalPlayTimeValue->setText(QString::fromUtf8("Unknown"));

        layoutPlayTime->setWidget(3, QFormLayout::FieldRole, labelTotalPlayTimeValue);


        verticalLayout->addWidget(collapsableWidgetPlayTime);

        collapsableWidgetGamesPlayTime = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetGamesPlayTime->setObjectName(QString::fromUtf8("collapsableWidgetGamesPlayTime"));
        layoutGamesPlayTime = new QFormLayout(collapsableWidgetGamesPlayTime);
        layoutGamesPlayTime->setObjectName(QString::fromUtf8("layoutGamesPlayTime"));
        label_46 = new QLabel(collapsableWidgetGamesPlayTime);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        layoutGamesPlayTime->setWidget(0, QFormLayout::LabelRole, label_46);

        labelPlayTime0Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime0Value->setObjectName(QString::fromUtf8("labelPlayTime0Value"));
        labelPlayTime0Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(0, QFormLayout::FieldRole, labelPlayTime0Value);

        label_50 = new QLabel(collapsableWidgetGamesPlayTime);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        layoutGamesPlayTime->setWidget(1, QFormLayout::LabelRole, label_50);

        labelPlayTime0_1Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime0_1Value->setObjectName(QString::fromUtf8("labelPlayTime0_1Value"));
        labelPlayTime0_1Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(1, QFormLayout::FieldRole, labelPlayTime0_1Value);

        label_48 = new QLabel(collapsableWidgetGamesPlayTime);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        layoutGamesPlayTime->setWidget(2, QFormLayout::LabelRole, label_48);

        labelPlayTime1_10Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime1_10Value->setObjectName(QString::fromUtf8("labelPlayTime1_10Value"));
        labelPlayTime1_10Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(2, QFormLayout::FieldRole, labelPlayTime1_10Value);

        label_44 = new QLabel(collapsableWidgetGamesPlayTime);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        layoutGamesPlayTime->setWidget(3, QFormLayout::LabelRole, label_44);

        labelPlayTime10_24Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime10_24Value->setObjectName(QString::fromUtf8("labelPlayTime10_24Value"));
        labelPlayTime10_24Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(3, QFormLayout::FieldRole, labelPlayTime10_24Value);

        label_47 = new QLabel(collapsableWidgetGamesPlayTime);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        layoutGamesPlayTime->setWidget(4, QFormLayout::LabelRole, label_47);

        labelPlayTime24_240Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime24_240Value->setObjectName(QString::fromUtf8("labelPlayTime24_240Value"));
        labelPlayTime24_240Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(4, QFormLayout::FieldRole, labelPlayTime24_240Value);

        label_41 = new QLabel(collapsableWidgetGamesPlayTime);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        layoutGamesPlayTime->setWidget(5, QFormLayout::LabelRole, label_41);

        labelPlayTime240_500Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime240_500Value->setObjectName(QString::fromUtf8("labelPlayTime240_500Value"));
        labelPlayTime240_500Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(5, QFormLayout::FieldRole, labelPlayTime240_500Value);

        label_45 = new QLabel(collapsableWidgetGamesPlayTime);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        layoutGamesPlayTime->setWidget(6, QFormLayout::LabelRole, label_45);

        labelPlayTime500_1000Value = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime500_1000Value->setObjectName(QString::fromUtf8("labelPlayTime500_1000Value"));
        labelPlayTime500_1000Value->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(6, QFormLayout::FieldRole, labelPlayTime500_1000Value);

        label_43 = new QLabel(collapsableWidgetGamesPlayTime);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        layoutGamesPlayTime->setWidget(7, QFormLayout::LabelRole, label_43);

        labelPlayTime1000plusValue = new LabelValue(collapsableWidgetGamesPlayTime);
        labelPlayTime1000plusValue->setObjectName(QString::fromUtf8("labelPlayTime1000plusValue"));
        labelPlayTime1000plusValue->setText(QString::fromUtf8("Unknown"));

        layoutGamesPlayTime->setWidget(7, QFormLayout::FieldRole, labelPlayTime1000plusValue);


        verticalLayout->addWidget(collapsableWidgetGamesPlayTime);

        collapsableWidgetCustomizations = new CollapsableWidget(scrollAreaWidgetContents);
        collapsableWidgetCustomizations->setObjectName(QString::fromUtf8("collapsableWidgetCustomizations"));
        layoutCustomizations = new QFormLayout(collapsableWidgetCustomizations);
        layoutCustomizations->setObjectName(QString::fromUtf8("layoutCustomizations"));
        label_55 = new QLabel(collapsableWidgetCustomizations);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        layoutCustomizations->setWidget(0, QFormLayout::LabelRole, label_55);

        labelCustomizationBackgroundValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationBackgroundValue->setObjectName(QString::fromUtf8("labelCustomizationBackgroundValue"));
        labelCustomizationBackgroundValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(0, QFormLayout::FieldRole, labelCustomizationBackgroundValue);

        label_56 = new QLabel(collapsableWidgetCustomizations);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        layoutCustomizations->setWidget(1, QFormLayout::LabelRole, label_56);

        label_57 = new QLabel(collapsableWidgetCustomizations);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        layoutCustomizations->setWidget(2, QFormLayout::LabelRole, label_57);

        label_58 = new QLabel(collapsableWidgetCustomizations);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        layoutCustomizations->setWidget(3, QFormLayout::LabelRole, label_58);

        label_59 = new QLabel(collapsableWidgetCustomizations);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        layoutCustomizations->setWidget(4, QFormLayout::LabelRole, label_59);

        label_60 = new QLabel(collapsableWidgetCustomizations);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        layoutCustomizations->setWidget(5, QFormLayout::LabelRole, label_60);

        labelCustomizationMiniProfileValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationMiniProfileValue->setObjectName(QString::fromUtf8("labelCustomizationMiniProfileValue"));
        labelCustomizationMiniProfileValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(1, QFormLayout::FieldRole, labelCustomizationMiniProfileValue);

        labelCustomizationAvatarFrameValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationAvatarFrameValue->setObjectName(QString::fromUtf8("labelCustomizationAvatarFrameValue"));
        labelCustomizationAvatarFrameValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(2, QFormLayout::FieldRole, labelCustomizationAvatarFrameValue);

        labelCustomizationAnimatedAvatarValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationAnimatedAvatarValue->setObjectName(QString::fromUtf8("labelCustomizationAnimatedAvatarValue"));
        labelCustomizationAnimatedAvatarValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(3, QFormLayout::FieldRole, labelCustomizationAnimatedAvatarValue);

        labelCustomizationPointsPurchasesValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationPointsPurchasesValue->setObjectName(QString::fromUtf8("labelCustomizationPointsPurchasesValue"));
        labelCustomizationPointsPurchasesValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(4, QFormLayout::FieldRole, labelCustomizationPointsPurchasesValue);

        labelCustomizationPointsUpgradesValue = new LabelValue(collapsableWidgetCustomizations);
        labelCustomizationPointsUpgradesValue->setObjectName(QString::fromUtf8("labelCustomizationPointsUpgradesValue"));
        labelCustomizationPointsUpgradesValue->setText(QString::fromUtf8("Unknown"));

        layoutCustomizations->setWidget(5, QFormLayout::FieldRole, labelCustomizationPointsUpgradesValue);


        verticalLayout->addWidget(collapsableWidgetCustomizations);

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
        progressBarXp->setFormat(QCoreApplication::translate("FormProfile", "%v/%m", nullptr));
        labelVanityUrl->setText(QCoreApplication::translate("FormProfile", "Vanity URL:", nullptr));
        label_6->setText(QCoreApplication::translate("FormProfile", "Account ID:", nullptr));
        labelAccountCreated->setText(QCoreApplication::translate("FormProfile", "Account created:", nullptr));
        labelLanguage->setText(QCoreApplication::translate("FormProfile", "Language:", nullptr));
        label_14->setText(QCoreApplication::translate("FormProfile", "Game Bans:", nullptr));
        label_16->setText(QCoreApplication::translate("FormProfile", "VAC Bans:", nullptr));
        label_19->setText(QCoreApplication::translate("FormProfile", "Community Ban:", nullptr));
        label_21->setText(QCoreApplication::translate("FormProfile", "Trade Ban:", nullptr));
#if QT_CONFIG(tooltip)
        labelSpecialBadges->setToolTip(QCoreApplication::translate("FormProfile", "Spetials Badges", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalBadges->setToolTip(QCoreApplication::translate("FormProfile", "Normal Badges", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl1->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl 1", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl2->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl 2", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl3->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl 3", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl4->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl 4", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl5->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl 5", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelNormalLvl5plus->setToolTip(QCoreApplication::translate("FormProfile", "Badges lvl more than 5", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        labelFoilBadges->setToolTip(QCoreApplication::translate("FormProfile", "Foil Badges", nullptr));
#endif // QT_CONFIG(tooltip)
        label_46->setText(QCoreApplication::translate("FormProfile", "Never play:", nullptr));
        label_50->setText(QCoreApplication::translate("FormProfile", "0-1h:", nullptr));
        label_48->setText(QCoreApplication::translate("FormProfile", "1-10h:", nullptr));
        label_44->setText(QCoreApplication::translate("FormProfile", "10-24h:", nullptr));
        label_47->setText(QCoreApplication::translate("FormProfile", "24-240h:", nullptr));
        label_41->setText(QCoreApplication::translate("FormProfile", "240-500h:", nullptr));
        label_45->setText(QCoreApplication::translate("FormProfile", "500-1000h:", nullptr));
        label_43->setText(QCoreApplication::translate("FormProfile", "1000+h:", nullptr));
        label_55->setText(QCoreApplication::translate("FormProfile", "Background:", nullptr));
        label_56->setText(QCoreApplication::translate("FormProfile", "MiniProfile:", nullptr));
        label_57->setText(QCoreApplication::translate("FormProfile", "Avatar frame:", nullptr));
        label_58->setText(QCoreApplication::translate("FormProfile", "Animated avatar:", nullptr));
        label_59->setText(QCoreApplication::translate("FormProfile", "Purchases in the Points Store:", nullptr));
        label_60->setText(QCoreApplication::translate("FormProfile", "Upgrades in the Points Store:", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
