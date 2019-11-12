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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGames
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelLogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonReturn;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGame;
    QPushButton *ButtonFind;
    QTableWidget *TableWidgetGames;

    void setupUi(QWidget *FormGames)
    {
        if (FormGames->objectName().isEmpty())
            FormGames->setObjectName(QString::fromUtf8("FormGames"));
        FormGames->resize(552, 577);
        QFont font;
        font.setPointSize(10);
        FormGames->setFont(font);
        verticalLayout = new QVBoxLayout(FormGames);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabelLogo = new QLabel(FormGames);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));
        LabelLogo->setFont(font);

        horizontalLayout_2->addWidget(LabelLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ButtonReturn = new QPushButton(FormGames);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));
        QFont font1;
        font1.setPointSize(8);
        ButtonReturn->setFont(font1);

        horizontalLayout_2->addWidget(ButtonReturn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGame = new QLineEdit(FormGames);
        LineEditGame->setObjectName(QString::fromUtf8("LineEditGame"));
        LineEditGame->setFont(font);

        horizontalLayout->addWidget(LineEditGame);

        ButtonFind = new QPushButton(FormGames);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));
        ButtonFind->setEnabled(true);
        ButtonFind->setFont(font1);

        horizontalLayout->addWidget(ButtonFind);


        verticalLayout->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(FormGames);
        if (TableWidgetGames->columnCount() < 4)
            TableWidgetGames->setColumnCount(4);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));
        TableWidgetGames->setColumnCount(4);

        verticalLayout->addWidget(TableWidgetGames);

        QWidget::setTabOrder(LineEditGame, ButtonFind);
        QWidget::setTabOrder(ButtonFind, ButtonReturn);

        retranslateUi(FormGames);

        QMetaObject::connectSlotsByName(FormGames);
    } // setupUi

    void retranslateUi(QWidget *FormGames)
    {
        FormGames->setWindowTitle(QApplication::translate("FormGames", "SteamAchievementsStatistic", nullptr));
        LabelLogo->setText(QApplication::translate("FormGames", "Logo", nullptr));
        ButtonReturn->setText(QApplication::translate("FormGames", "Return", nullptr));
        ButtonFind->setText(QApplication::translate("FormGames", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGames: public Ui_FormGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMES_H
