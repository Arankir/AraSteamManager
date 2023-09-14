/********************************************************************************
** Form generated from reading UI file 'formfavorites.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFAVORITES_H
#define UI_FORMFAVORITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
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
    QTableView *TableViewGames;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *TableViewFriends;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidgetAchievements;

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
        TableViewGames = new QTableView(tab);
        TableViewGames->setObjectName(QString::fromUtf8("TableViewGames"));

        verticalLayout_2->addWidget(TableViewGames);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TableViewFriends = new QTableView(tab_2);
        TableViewFriends->setObjectName(QString::fromUtf8("TableViewFriends"));

        verticalLayout_3->addWidget(TableViewFriends);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        treeWidgetAchievements = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetAchievements->setHeaderItem(__qtreewidgetitem);
        treeWidgetAchievements->setObjectName(QString::fromUtf8("treeWidgetAchievements"));

        verticalLayout_4->addWidget(treeWidgetAchievements);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(FormFavorites);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(FormFavorites);
    } // setupUi

    void retranslateUi(QWidget *FormFavorites)
    {
        FormFavorites->setWindowTitle(QCoreApplication::translate("FormFavorites", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormFavorites", "  Games  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormFavorites", "  Profiles  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FormFavorites", "  Achievements  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFavorites: public Ui_FormFavorites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFAVORITES_H
