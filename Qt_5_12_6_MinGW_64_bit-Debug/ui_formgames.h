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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *GroupBoxGame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelIconGame;
    QLabel *LabelTitleGame;
    QProgressBar *ProgressBarSelectedGame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ButtonAchievements;
    QPushButton *ButtonFavorite;
    QPushButton *ButtonHide;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;
    QTableWidget *TableWidgetGames;
    QProgressBar *ProgressBarLoading;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(603, 577);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout = new QVBoxLayout(FormGames);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        GroupBoxGame = new QGroupBox(FormGames);
        GroupBoxGame->setObjectName(QString::fromUtf8("GroupBoxGame"));
        GroupBoxGame->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border: 1px solid #13657b;\n"
"	background-color: #262626;\n"
"	border-radius: 1px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(GroupBoxGame);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelIconGame = new QLabel(GroupBoxGame);
        LabelIconGame->setObjectName(QString::fromUtf8("LabelIconGame"));

        horizontalLayout_2->addWidget(LabelIconGame);

        LabelTitleGame = new QLabel(GroupBoxGame);
        LabelTitleGame->setObjectName(QString::fromUtf8("LabelTitleGame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelTitleGame->sizePolicy().hasHeightForWidth());
        LabelTitleGame->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        LabelTitleGame->setFont(font1);
        LabelTitleGame->setWordWrap(true);

        horizontalLayout_2->addWidget(LabelTitleGame);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ProgressBarSelectedGame = new QProgressBar(GroupBoxGame);
        ProgressBarSelectedGame->setObjectName(QString::fromUtf8("ProgressBarSelectedGame"));
        ProgressBarSelectedGame->setValue(0);

        verticalLayout_2->addWidget(ProgressBarSelectedGame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ButtonAchievements = new QPushButton(GroupBoxGame);
        ButtonAchievements->setObjectName(QString::fromUtf8("ButtonAchievements"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonAchievements->sizePolicy().hasHeightForWidth());
        ButtonAchievements->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ButtonAchievements);

        ButtonFavorite = new QPushButton(GroupBoxGame);
        ButtonFavorite->setObjectName(QString::fromUtf8("ButtonFavorite"));

        horizontalLayout_3->addWidget(ButtonFavorite);

        ButtonHide = new QPushButton(GroupBoxGame);
        ButtonHide->setObjectName(QString::fromUtf8("ButtonHide"));

        horizontalLayout_3->addWidget(ButtonHide);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(GroupBoxGame);

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


        verticalLayout->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(FormGames);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(TableWidgetGames);

        ProgressBarLoading = new QProgressBar(FormGames);
        ProgressBarLoading->setObjectName(QString::fromUtf8("ProgressBarLoading"));
        ProgressBarLoading->setValue(0);

        verticalLayout->addWidget(ProgressBarLoading);

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
        LineEditGame->setPlaceholderText(QApplication::translate("FormGames", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\203", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", " \320\235\320\260\320\271\321\202\320\270", nullptr));
        ProgressBarLoading->setFormat(QApplication::translate("FormGames", "%v/%m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
