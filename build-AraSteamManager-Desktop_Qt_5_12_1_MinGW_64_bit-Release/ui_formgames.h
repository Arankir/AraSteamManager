/********************************************************************************
** Form generated from reading UI file 'formgames.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QTableWidget *TableWidgetGames;
    QPushButton *ButtonReturn;
    QLabel *LabelLogo;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(552, 577);
        QFont font;
        font.setPointSize(10);
        FormGames->setFont(font);
        gridLayout = new QGridLayout(FormGames);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TableWidgetGames = new QTableWidget(FormGames);
        if (TableWidgetGames->columnCount() < 4)
            TableWidgetGames->setColumnCount(4);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->setColumnCount(4);

        gridLayout->addWidget(TableWidgetGames, 2, 0, 1, 2);

        ButtonReturn = new QPushButton(FormGames);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));
        QFont font1;
        font1.setPointSize(8);
        ButtonReturn->setFont(font1);

        gridLayout->addWidget(ButtonReturn, 0, 1, 1, 1);

        LabelLogo = new QLabel(FormGames);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));
        LabelLogo->setFont(font);

        gridLayout->addWidget(LabelLogo, 0, 0, 1, 1);

        LineEditGame = new QLineEdit(FormGames);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        LineEditGame->setFont(font);

        gridLayout->addWidget(LineEditGame, 1, 0, 1, 1);

        ButtonFind = new QPushButton(FormGames);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        ButtonFind->setFont(font1);

        gridLayout->addWidget(ButtonFind, 1, 1, 1, 1);

        QWidget::setTabOrder(LineEditGame, ButtonFind);
        QWidget::setTabOrder(ButtonFind, ButtonReturn);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        ButtonReturn->setText(QApplication::translate("FormGames", "Return", nullptr));
        LabelLogo->setText(QApplication::translate("FormGames", "Logo", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
