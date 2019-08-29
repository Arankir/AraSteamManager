/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMES_H
#define UI_FORMGAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QGridLayout *gridLayout;
    QTableWidget *FormGamesTableWidgetGames;
    QPushButton *FormGamesButtonReturn;
    QLabel *FormGamesLabelLogo;
    QLineEdit *FormGamesLineEditGame;
    QPushButton *FormGamesButtonFind;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(588, 577);
        QFont font;
        font.setPointSize(10);
        FormGames->setFont(font);
        gridLayout = new QGridLayout(FormGames);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FormGamesTableWidgetGames = new QTableWidget(FormGames);
        if (FormGamesTableWidgetGames->columnCount() < 4)
            FormGamesTableWidgetGames->setColumnCount(4);
        FormGamesTableWidgetGames->setObjectName(QString::fromUtf8("FormGamesTableWidgetGames"));
        FormGamesTableWidgetGames->setColumnCount(4);

        gridLayout->addWidget(FormGamesTableWidgetGames, 2, 0, 1, 2);

        FormGamesButtonReturn = new QPushButton(FormGames);
        FormGamesButtonReturn->setObjectName(QString::fromUtf8("FormGamesButtonReturn"));
        QFont font1;
        font1.setPointSize(8);
        FormGamesButtonReturn->setFont(font1);

        gridLayout->addWidget(FormGamesButtonReturn, 0, 1, 1, 1);

        FormGamesLabelLogo = new QLabel(FormGames);
        FormGamesLabelLogo->setObjectName(QString::fromUtf8("FormGamesLabelLogo"));
        FormGamesLabelLogo->setFont(font);

        gridLayout->addWidget(FormGamesLabelLogo, 0, 0, 1, 1);

        FormGamesLineEditGame = new QLineEdit(FormGames);
        FormGamesLineEditGame->setObjectName(QString::fromUtf8("FormGamesLineEditGame"));
        FormGamesLineEditGame->setFont(font);

        gridLayout->addWidget(FormGamesLineEditGame, 1, 0, 1, 1);

        FormGamesButtonFind = new QPushButton(FormGames);
        FormGamesButtonFind->setObjectName(QString::fromUtf8("FormGamesButtonFind"));
        FormGamesButtonFind->setEnabled(true);
        FormGamesButtonFind->setFont(font1);

        gridLayout->addWidget(FormGamesButtonFind, 1, 1, 1, 1);

        QWidget::setTabOrder(FormGamesLineEditGame, FormGamesButtonFind);
        QWidget::setTabOrder(FormGamesButtonFind, FormGamesButtonReturn);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QCoreApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        FormGamesButtonReturn->setText(QCoreApplication::translate("FormGames", "Return", nullptr));
        FormGamesLabelLogo->setText(QCoreApplication::translate("FormGames", "Logo", nullptr));
        FormGamesButtonFind->setText(QCoreApplication::translate("FormGames", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
