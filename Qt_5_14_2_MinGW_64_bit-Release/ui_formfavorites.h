/********************************************************************************
** Form generated from reading UI file 'formfavorites.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFAVORITES_H
#define UI_FORMFAVORITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFavorites
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditGamesFind;
    QPushButton *ButtonGamesFind;
    QTableWidget *TableWidgetGames;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LineEditFriendsFind;
    QPushButton *ButtonFriendsFind;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *ComboBoxFriendsStatus;
    QCheckBox *CheckBoxFriendsOpenProfile;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *TableWidgetFriends;
    QWidget *tab_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *FormFavorites)
    {
        if (FormFavorites->objectName().isEmpty())
            FormFavorites->setObjectName(QString::fromUtf8("FormFavorites"));
        FormFavorites->resize(635, 662);
        verticalLayout = new QVBoxLayout(FormFavorites);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FormFavorites);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditGamesFind = new QLineEdit(tab);
        LineEditGamesFind->setObjectName(QString::fromUtf8("LineEditGamesFind"));

        horizontalLayout->addWidget(LineEditGamesFind);

        ButtonGamesFind = new QPushButton(tab);
        ButtonGamesFind->setObjectName(QString::fromUtf8("ButtonGamesFind"));

        horizontalLayout->addWidget(ButtonGamesFind);


        verticalLayout_2->addLayout(horizontalLayout);

        TableWidgetGames = new QTableWidget(tab);
        TableWidgetGames->setObjectName(QString::fromUtf8("TableWidgetGames"));

        verticalLayout_2->addWidget(TableWidgetGames);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LineEditFriendsFind = new QLineEdit(tab_2);
        LineEditFriendsFind->setObjectName(QString::fromUtf8("LineEditFriendsFind"));

        horizontalLayout_2->addWidget(LineEditFriendsFind);

        ButtonFriendsFind = new QPushButton(tab_2);
        ButtonFriendsFind->setObjectName(QString::fromUtf8("ButtonFriendsFind"));

        horizontalLayout_2->addWidget(ButtonFriendsFind);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ComboBoxFriendsStatus = new QComboBox(tab_2);
        ComboBoxFriendsStatus->setObjectName(QString::fromUtf8("ComboBoxFriendsStatus"));

        horizontalLayout_3->addWidget(ComboBoxFriendsStatus);

        CheckBoxFriendsOpenProfile = new QCheckBox(tab_2);
        CheckBoxFriendsOpenProfile->setObjectName(QString::fromUtf8("CheckBoxFriendsOpenProfile"));

        horizontalLayout_3->addWidget(CheckBoxFriendsOpenProfile);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        TableWidgetFriends = new QTableWidget(tab_2);
        TableWidgetFriends->setObjectName(QString::fromUtf8("TableWidgetFriends"));

        verticalLayout_3->addWidget(TableWidgetFriends);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 10, 80, 21));
        pushButton->setText(QString::fromUtf8("\320\226\320\274\320\270"));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 113, 21));
        lineEdit->setText(QString::fromUtf8("0,0,0"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 90, 151, 16));
        label->setText(QString::fromUtf8("\320\237\320\276\321\202\320\276\320\274 \320\264\320\276\320\261\320\260\320\262\320\273\321\216 \321\201\321\216\320\264\320\260 \320\260\321\207\320\270\320\262\320\272\320\270"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 180, 611, 371));
        label_2->setText(QString::fromUtf8("\320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201"
                        "\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272"
                        "\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265"
                        "\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202"
                        "\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271"
                        " \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213"
                        "\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275"
                        "\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275"
                        "\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270"
                        "\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273"
                        "\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264"
                        "\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214"
                        " \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275"
                        "\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265"
                        "\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207"
                        "\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276"
                        "\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257"
                        " \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202"
                        " \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\257 \320\276\321\207\320\265\320\275\321\214 \320\264\320\273\320\270\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202"));
        label_2->setWordWrap(true);
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(90, 120, 113, 21));
        lineEdit_2->setText(QString::fromUtf8(""));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 10, 161, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(125,126,128);"));
        label_3->setText(QString::fromUtf8("\320\221\321\213\320\273 \320\262 \321\201\320\265\321\202\320\270 125,126,128"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 30, 161, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(87,203,222);"));
        label_4->setText(QString::fromUtf8("\320\222 \321\201\320\265\321\202\320\270 87,203,222"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 50, 161, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(129,85,96);"));
        label_5->setText(QString::fromUtf8("\320\235\320\265 \320\261\320\265\321\201\320\277\320\276\320\272\320\276\320\270\321\202\321\214 129,85,96"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 70, 161, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(70,120,142);"));
        label_6->setText(QString::fromUtf8("\320\235\320\265\321\202 \320\275\320\260 \320\274\320\265\321\201\321\202\320\265 70,120,142"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 90, 161, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(125,126,128);"));
        label_7->setText(QString::fromUtf8("\320\241\320\277\320\270\321\202 70,120,142"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 110, 161, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));
        label_8->setText(QString::fromUtf8("\320\236\320\266\320\270\320\264\320\260\320\265\321\202 \320\276\320\261\320\274\320\265\320\275\320\260 0,0,0"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(FormFavorites);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormFavorites);
    } // setupUi

    void retranslateUi(QWidget *FormFavorites)
    {
        FormFavorites->setWindowTitle(QCoreApplication::translate("FormFavorites", "Form", nullptr));
        ButtonGamesFind->setText(QCoreApplication::translate("FormFavorites", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormFavorites", "  Games  ", nullptr));
        LineEditFriendsFind->setPlaceholderText(QCoreApplication::translate("FormFavorites", "\320\235\320\260\320\271\321\202\320\270 \320\264\321\200\321\203\320\263\320\260", nullptr));
        ButtonFriendsFind->setText(QCoreApplication::translate("FormFavorites", "  \320\237\320\276\320\270\321\201\320\272", nullptr));
        CheckBoxFriendsOpenProfile->setText(QCoreApplication::translate("FormFavorites", "\320\237\321\203\320\261\320\273\320\270\321\207\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormFavorites", "  Friends  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FormFavorites", "  Achievements  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFavorites: public Ui_FormFavorites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFAVORITES_H
