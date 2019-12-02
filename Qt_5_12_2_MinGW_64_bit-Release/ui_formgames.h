/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMES_H
#define UI_FORMGAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;
    QTableWidget *TableWidgetGames;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(603, 577);
        QFont font;
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout = new QVBoxLayout(FormGames);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(FormGames);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(FormGames);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        QFont font1;
        font1.setPointSize(8);
        ButtonFind->setFont(font1);

        horizontalLayout->addWidget(ButtonFind);


        verticalLayout->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(FormGames);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));

        verticalLayout->addWidget(TableWidgetGames);

        QWidget::setTabOrder(LineEditGame, ButtonFind);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
