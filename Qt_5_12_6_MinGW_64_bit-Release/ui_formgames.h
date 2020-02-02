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
#include <QtWidgets/QGroupBox>
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
    QVBoxLayout *verticalLayout_3;
    QScrollArea *ScrollAreaGame;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
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
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonCreateGroup;
    QPushButton *ButtonChangeGroup;
    QGroupBox *GroupBoxGroup;
    QTableWidget *TableWidgetGames;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(603, 577);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout_3 = new QVBoxLayout(FormGames);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ScrollAreaGame = new QScrollArea(FormGames);
        ScrollAreaGame->setObjectName(QString::fromUtf8("ScrollAreaGame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrollAreaGame->sizePolicy().hasHeightForWidth());
        ScrollAreaGame->setSizePolicy(sizePolicy);
        ScrollAreaGame->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 601, 113));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelIconGame = new QLabel(scrollAreaWidgetContents);
        LabelIconGame->setObjectName(QString::fromUtf8("LabelIconGame"));

        horizontalLayout_2->addWidget(LabelIconGame);

        LabelTitleGame = new QLabel(scrollAreaWidgetContents);
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


        verticalLayout_2->addLayout(horizontalLayout_2);

        ProgressBarSelectedGame = new QProgressBar(scrollAreaWidgetContents);
        ProgressBarSelectedGame->setObjectName(QString::fromUtf8("ProgressBarSelectedGame"));
        ProgressBarSelectedGame->setValue(0);

        verticalLayout_2->addWidget(ProgressBarSelectedGame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ButtonAchievements = new QPushButton(scrollAreaWidgetContents);
        ButtonAchievements->setObjectName(QString::fromUtf8("ButtonAchievements"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonAchievements->sizePolicy().hasHeightForWidth());
        ButtonAchievements->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(ButtonAchievements);

        ButtonFavorite = new QPushButton(scrollAreaWidgetContents);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));

        horizontalLayout_3->addWidget(ButtonFavorite);

        ButtonHide = new QPushButton(scrollAreaWidgetContents);
        ButtonHide->setObjectName(QString::fromUtf8("ButtonHide"));

        horizontalLayout_3->addWidget(ButtonHide);


        verticalLayout_2->addLayout(horizontalLayout_3);

        ScrollAreaGame->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(ScrollAreaGame);

        ProgressBarLoading = new QProgressBar(FormGames);
        ProgressBarLoading->setObjectName(QString::fromUtf8("ProgressBarLoading"));
        ProgressBarLoading->setValue(0);

        verticalLayout_3->addWidget(ProgressBarLoading);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(FormGames);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(FormGames);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ebrima"));
        font2.setPointSize(8);
        ButtonFind->setFont(font2);

        horizontalLayout->addWidget(ButtonFind);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonCreateGroup = new QPushButton(FormGames);
        ButtonCreateGroup->setObjectName(QString::fromUtf8("ButtonCreateGroup"));

        horizontalLayout_4->addWidget(ButtonCreateGroup);

        ButtonChangeGroup = new QPushButton(FormGames);
        ButtonChangeGroup->setObjectName(QString::fromUtf8("ButtonChangeGroup"));

        horizontalLayout_4->addWidget(ButtonChangeGroup);


        verticalLayout->addLayout(horizontalLayout_4);

        GroupBoxGroup = new QGroupBox(FormGames);
        GroupBoxGroup->setObjectName(QString::fromUtf8("GroupBoxGroup"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(GroupBoxGroup->sizePolicy().hasHeightForWidth());
        GroupBoxGroup->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(10);
        GroupBoxGroup->setFont(font3);
        GroupBoxGroup->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(GroupBoxGroup);


        horizontalLayout_5->addLayout(verticalLayout);

        TableWidgetGames = new QTableWidget(FormGames);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(TableWidgetGames);


        verticalLayout_3->addLayout(horizontalLayout_5);

        QWidget::setTabOrder(LineEditGame, ButtonFind);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        LabelIconGame->setText(QApplication::translate("FormGames", "Icon", nullptr));
        LabelTitleGame->setText(QApplication::translate("FormGames", "Title", nullptr));
        ProgressBarSelectedGame->setFormat(QApplication::translate("FormGames", "%v/%m (%p%)", nullptr));
        ButtonAchievements->setText(QApplication::translate("FormGames", "Achievements", nullptr));
        ButtonFavorite->setText(QApplication::translate("FormGames", "Favorite", nullptr));
        ButtonHide->setText(QApplication::translate("FormGames", "Hide", nullptr));
        ProgressBarLoading->setFormat(QApplication::translate("FormGames", "%v/%m", nullptr));
        LineEditGame->setPlaceholderText(QApplication::translate("FormGames", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\203", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        ButtonCreateGroup->setText(QApplication::translate("FormGames", "Create", nullptr));
        ButtonChangeGroup->setText(QApplication::translate("FormGames", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
