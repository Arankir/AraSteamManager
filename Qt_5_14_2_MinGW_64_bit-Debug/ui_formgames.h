/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMES_H
#define UI_FORMGAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *FrameGame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelIconGame;
    QLabel *LabelTitleGame;
    QProgressBar *ProgressBarSelectedGame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ButtonAchievements;
    QPushButton *ButtonFavorite;
    QPushButton *ButtonHide;
    QProgressBar *ProgressBarLoading;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;
    QFrame *FrameGames;
    QTableWidget *TableWidgetGames;
    QFrame *FrameGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonChangeGroup;
    QPushButton *ButtonCreateGroup;
    QScrollArea *ScrollAreaGroup;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(564, 493);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout_2 = new QVBoxLayout(FormGames);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        FrameGame = new QFrame(FormGames);
        FrameGame->setObjectName(QString::fromUtf8("FrameGame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrameGame->sizePolicy().hasHeightForWidth());
        FrameGame->setSizePolicy(sizePolicy);
        FrameGame->setFrameShape(QFrame::StyledPanel);
        FrameGame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameGame);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelIconGame = new QLabel(FrameGame);
        LabelIconGame->setObjectName(QString::fromUtf8("LabelIconGame"));
        LabelIconGame->setText(QString::fromUtf8("Icon"));

        horizontalLayout_2->addWidget(LabelIconGame);

        LabelTitleGame = new QLabel(FrameGame);
        LabelTitleGame->setObjectName(QString::fromUtf8("LabelTitleGame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelTitleGame->sizePolicy().hasHeightForWidth());
        LabelTitleGame->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        LabelTitleGame->setFont(font1);
        LabelTitleGame->setText(QString::fromUtf8("Title"));
        LabelTitleGame->setWordWrap(true);

        horizontalLayout_2->addWidget(LabelTitleGame);


        verticalLayout_3->addLayout(horizontalLayout_2);

        ProgressBarSelectedGame = new QProgressBar(FrameGame);
        ProgressBarSelectedGame->setObjectName(QString::fromUtf8("ProgressBarSelectedGame"));
        ProgressBarSelectedGame->setValue(0);
        ProgressBarSelectedGame->setFormat(QString::fromUtf8("%v/%m (%p%)"));

        verticalLayout_3->addWidget(ProgressBarSelectedGame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ButtonAchievements = new QPushButton(FrameGame);
        ButtonAchievements->setObjectName(QString::fromUtf8("ButtonAchievements"));
        sizePolicy1.setHeightForWidth(ButtonAchievements->sizePolicy().hasHeightForWidth());
        ButtonAchievements->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ButtonAchievements);

        ButtonFavorite = new QPushButton(FrameGame);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));
        ButtonFavorite->setText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(ButtonFavorite);

        ButtonHide = new QPushButton(FrameGame);
        ButtonHide->setObjectName(QString::fromUtf8("ButtonHide"));
        ButtonHide->setText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(ButtonHide);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(FrameGame);

        ProgressBarLoading = new QProgressBar(FormGames);
        ProgressBarLoading->setObjectName(QString::fromUtf8("ProgressBarLoading"));
        ProgressBarLoading->setValue(0);
        ProgressBarLoading->setFormat(QString::fromUtf8("%v/%m"));

        verticalLayout_2->addWidget(ProgressBarLoading);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(FormGames);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        sizePolicy1.setHeightForWidth(LineEditGame->sizePolicy().hasHeightForWidth());
        LineEditGame->setSizePolicy(sizePolicy1);
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(FormGames);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonFind->sizePolicy().hasHeightForWidth());
        ButtonFind->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(8);
        ButtonFind->setFont(font2);

        horizontalLayout->addWidget(ButtonFind);


        verticalLayout_2->addLayout(horizontalLayout);

        FrameGames = new QFrame(FormGames);
        FrameGames->setObjectName(QString::fromUtf8("FrameGames"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FrameGames->sizePolicy().hasHeightForWidth());
        FrameGames->setSizePolicy(sizePolicy3);
        FrameGames->setFrameShape(QFrame::StyledPanel);
        FrameGames->setFrameShadow(QFrame::Raised);
        TableWidgetGames = new QTableWidget(FrameGames);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->setGeometry(QRect(184, 10, 256, 192));
        TableWidgetGames->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetGames->setShowGrid(false);
        TableWidgetGames->horizontalHeader()->setStretchLastSection(true);
        TableWidgetGames->verticalHeader()->setVisible(false);
        FrameGroup = new QFrame(FrameGames);
        FrameGroup->setObjectName(QString::fromUtf8("FrameGroup"));
        FrameGroup->setGeometry(QRect(10, 40, 168, 100));
        verticalLayout = new QVBoxLayout(FrameGroup);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonChangeGroup = new QPushButton(FrameGroup);
        ButtonChangeGroup->setObjectName(QString::fromUtf8("ButtonChangeGroup"));

        horizontalLayout_4->addWidget(ButtonChangeGroup);

        ButtonCreateGroup = new QPushButton(FrameGroup);
        ButtonCreateGroup->setObjectName(QString::fromUtf8("ButtonCreateGroup"));

        horizontalLayout_4->addWidget(ButtonCreateGroup);


        verticalLayout_4->addLayout(horizontalLayout_4);

        ScrollAreaGroup = new QScrollArea(FrameGroup);
        ScrollAreaGroup->setObjectName(QString::fromUtf8("ScrollAreaGroup"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ScrollAreaGroup->sizePolicy().hasHeightForWidth());
        ScrollAreaGroup->setSizePolicy(sizePolicy4);
        ScrollAreaGroup->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 142, 61));
        ScrollAreaGroup->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(ScrollAreaGroup);


        horizontalLayout_5->addLayout(verticalLayout_4);

        label = new QLabel(FrameGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(20, 0));
        label->setMaximumSize(QSize(20, 16777215));
        label->setPixmap(QPixmap(QString::fromUtf8(":/white/widgets/scrollbar_right.png")));
        label->setScaledContents(true);

        horizontalLayout_5->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(FrameGames);


        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QCoreApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        ButtonAchievements->setText(QCoreApplication::translate("FormGames", "Achievements", nullptr));
        LineEditGame->setPlaceholderText(QCoreApplication::translate("FormGames", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\203", nullptr));
        ButtonFind->setText(QCoreApplication::translate("FormGames", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        ButtonChangeGroup->setText(QCoreApplication::translate("FormGames", "Change", nullptr));
        ButtonCreateGroup->setText(QCoreApplication::translate("FormGames", "Create", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
