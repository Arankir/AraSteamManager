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
    QPushButton *ButtonUpdate;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelProfileUrl;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
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
    QLabel *label;
    QLabel *label_2;
    QLabel *LabelBans;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonGames;
    QPushButton *ButtonFriends;
    QPushButton *ButtonStatistics;
    QPushButton *ButtonFavorites;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonGoToMyProfile;

    void setupUi(QWidget *FormProfile)
    {
        if (FormProfile->objectName().isEmpty())
            FormProfile->setObjectName(QString::fromUtf8("FormProfile"));
        FormProfile->resize(441, 150);
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

        ButtonUpdate = new QPushButton(FormProfile);
        ButtonUpdate->setObjectName(QString::fromUtf8("ButtonUpdate"));

        horizontalLayout_6->addWidget(ButtonUpdate);


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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Labellvl = new QLabel(FormProfile);
        Labellvl->setObjectName(QString::fromUtf8("Labellvl"));
        Labellvl->setFont(font1);
        Labellvl->setText(QString::fromUtf8("lvl"));

        horizontalLayout_2->addWidget(Labellvl);

        line = new QFrame(FormProfile);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        LabelTimeCreated = new QLabel(FormProfile);
        LabelTimeCreated->setObjectName(QString::fromUtf8("LabelTimeCreated"));
        LabelTimeCreated->setFont(font1);
        LabelTimeCreated->setText(QString::fromUtf8("TimeCreated"));

        horizontalLayout_2->addWidget(LabelTimeCreated);

        line_2 = new QFrame(FormProfile);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        LabelLocCountryCode = new QLabel(FormProfile);
        LabelLocCountryCode->setObjectName(QString::fromUtf8("LabelLocCountryCode"));
        LabelLocCountryCode->setFont(font1);
        LabelLocCountryCode->setText(QString::fromUtf8("CountryCode"));

        horizontalLayout_2->addWidget(LabelLocCountryCode);

        line_3 = new QFrame(FormProfile);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        LabelRealName = new QLabel(FormProfile);
        LabelRealName->setObjectName(QString::fromUtf8("LabelRealName"));
        LabelRealName->setFont(font1);
        LabelRealName->setText(QString::fromUtf8("RealName"));

        horizontalLayout_2->addWidget(LabelRealName);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LabelProfileVisibility = new QLabel(FormProfile);
        LabelProfileVisibility->setObjectName(QString::fromUtf8("LabelProfileVisibility"));
        LabelProfileVisibility->setFont(font1);

        horizontalLayout_3->addWidget(LabelProfileVisibility);

        label = new QLabel(FormProfile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(FormProfile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        LabelBans = new QLabel(FormProfile);
        LabelBans->setObjectName(QString::fromUtf8("LabelBans"));
        LabelBans->setFont(font1);
        LabelBans->setText(QString::fromUtf8("Bans"));

        horizontalLayout_3->addWidget(LabelBans);


        verticalLayout->addLayout(horizontalLayout_3);

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

        ButtonGoToMyProfile = new QPushButton(FormProfile);
        ButtonGoToMyProfile->setObjectName(QString::fromUtf8("ButtonGoToMyProfile"));

        horizontalLayout->addWidget(ButtonGoToMyProfile);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormProfile);

        QMetaObject::connectSlotsByName(FormProfile);
    } // setupUi

    void retranslateUi(QWidget *FormProfile)
    {
        FormProfile->setWindowTitle(QCoreApplication::translate("FormProfile", "Form", nullptr));
        ButtonSetProfile->setText(QCoreApplication::translate("FormProfile", "\320\255\321\202\320\276 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        ButtonUpdate->setText(QCoreApplication::translate("FormProfile", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        LabelProfileVisibility->setText(QCoreApplication::translate("FormProfile", "Visibility", nullptr));
        label->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("FormProfile", "TextLabel", nullptr));
        ButtonStatistics->setText(QCoreApplication::translate("FormProfile", " \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        ButtonFavorites->setText(QCoreApplication::translate("FormProfile", " \320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        ButtonGoToMyProfile->setText(QCoreApplication::translate("FormProfile", "\320\235\320\260 \320\274\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProfile: public Ui_FormProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROFILE_H
