/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
    QFrame *FrameGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonChangeGroup;
    QPushButton *ButtonCreateGroup;
    QScrollArea *ScrollAreaGroup;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget;
    QVBoxLayout *mainLayout;
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
    QTableWidget *TableWidgetGames;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(564, 493);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        font.setPointSize(10);
        FormGames->setFont(font);
        FrameGroup = new QFrame(FormGames);
        FrameGroup->setObjectName(QString::fromUtf8("FrameGroup"));
        FrameGroup->setGeometry(QRect(270, 20, 168, 100));
        verticalLayout = new QVBoxLayout(FrameGroup);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonChangeGroup = new QPushButton(FrameGroup);
        ButtonChangeGroup->setObjectName(QString::fromUtf8("ButtonChangeGroup"));

        horizontalLayout_4->addWidget(ButtonChangeGroup);

        ButtonCreateGroup = new QPushButton(FrameGroup);
        ButtonCreateGroup->setObjectName(QString::fromUtf8("ButtonCreateGroup"));

        horizontalLayout_4->addWidget(ButtonCreateGroup);


        verticalLayout->addLayout(horizontalLayout_4);

        ScrollAreaGroup = new QScrollArea(FrameGroup);
        ScrollAreaGroup->setObjectName(QString::fromUtf8("ScrollAreaGroup"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrollAreaGroup->sizePolicy().hasHeightForWidth());
        ScrollAreaGroup->setSizePolicy(sizePolicy);
        ScrollAreaGroup->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 166, 68));
        ScrollAreaGroup->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(ScrollAreaGroup);

        widget = new QWidget(FormGames);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 260, 355));
        mainLayout = new QVBoxLayout(widget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        FrameGame = new QFrame(widget);
        FrameGame->setObjectName(QString::fromUtf8("FrameGame"));
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

        horizontalLayout_2->addWidget(LabelIconGame);

        LabelTitleGame = new QLabel(FrameGame);
        LabelTitleGame->setObjectName(QString::fromUtf8("LabelTitleGame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabelTitleGame->sizePolicy().hasHeightForWidth());
        LabelTitleGame->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        LabelTitleGame->setFont(font1);
        LabelTitleGame->setWordWrap(true);

        horizontalLayout_2->addWidget(LabelTitleGame);


        verticalLayout_3->addLayout(horizontalLayout_2);

        ProgressBarSelectedGame = new QProgressBar(FrameGame);
        ProgressBarSelectedGame->setObjectName(QString::fromUtf8("ProgressBarSelectedGame"));
        ProgressBarSelectedGame->setValue(0);

        verticalLayout_3->addWidget(ProgressBarSelectedGame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ButtonAchievements = new QPushButton(FrameGame);
        ButtonAchievements->setObjectName(QString::fromUtf8("ButtonAchievements"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonAchievements->sizePolicy().hasHeightForWidth());
        ButtonAchievements->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(ButtonAchievements);

        ButtonFavorite = new QPushButton(FrameGame);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));

        horizontalLayout_3->addWidget(ButtonFavorite);

        ButtonHide = new QPushButton(FrameGame);
        ButtonHide->setObjectName(QString::fromUtf8("ButtonHide"));

        horizontalLayout_3->addWidget(ButtonHide);


        verticalLayout_3->addLayout(horizontalLayout_3);


        mainLayout->addWidget(FrameGame);

        ProgressBarLoading = new QProgressBar(widget);
        ProgressBarLoading->setObjectName(QString::fromUtf8("ProgressBarLoading"));
        ProgressBarLoading->setValue(0);

        mainLayout->addWidget(ProgressBarLoading);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(widget);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(widget);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(8);
        ButtonFind->setFont(font2);

        horizontalLayout->addWidget(ButtonFind);


        mainLayout->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(widget);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetGames->horizontalHeader()->setStretchLastSection(true);
        TableWidgetGames->verticalHeader()->setVisible(false);

        mainLayout->addWidget(TableWidgetGames);

        QWidget::setTabOrder(LineEditGame, ButtonFind);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        ButtonChangeGroup->setText(QApplication::translate("FormGames", "Change", nullptr));
        ButtonCreateGroup->setText(QApplication::translate("FormGames", "Create", nullptr));
        LabelIconGame->setText(QApplication::translate("FormGames", "Icon", nullptr));
        LabelTitleGame->setText(QApplication::translate("FormGames", "Title", nullptr));
        ProgressBarSelectedGame->setFormat(QApplication::translate("FormGames", "%v/%m (%p%)", nullptr));
        ButtonAchievements->setText(QApplication::translate("FormGames", "Achievements", nullptr));
        ButtonFavorite->setText(QApplication::translate("FormGames", "Favorite", nullptr));
        ButtonHide->setText(QApplication::translate("FormGames", "Hide", nullptr));
        ProgressBarLoading->setFormat(QApplication::translate("FormGames", "%v/%m", nullptr));
        LineEditGame->setPlaceholderText(QApplication::translate("FormGames", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\203", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", " \320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
