/********************************************************************************
** Form generated from reading UI file 'formhiddengames.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMHIDDENGAMES_H
#define UI_FORMHIDDENGAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormHiddenGames
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidgetHiddenGames;

    void setupUi(QWidget *FormHiddenGames)
    {
        if (FormHiddenGames->objectName().isEmpty())
            FormHiddenGames->setObjectName(QString::fromUtf8("FormHiddenGames"));
        FormHiddenGames->resize(400, 300);
        verticalLayout = new QVBoxLayout(FormHiddenGames);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidgetHiddenGames = new QTreeWidget(FormHiddenGames);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetHiddenGames->setHeaderItem(__qtreewidgetitem);
        treeWidgetHiddenGames->setObjectName(QString::fromUtf8("treeWidgetHiddenGames"));
        treeWidgetHiddenGames->header()->setVisible(false);

        verticalLayout->addWidget(treeWidgetHiddenGames);


        retranslateUi(FormHiddenGames);

        QMetaObject::connectSlotsByName(FormHiddenGames);
    } // setupUi

    void retranslateUi(QWidget *FormHiddenGames)
    {
        FormHiddenGames->setWindowTitle(QCoreApplication::translate("FormHiddenGames", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormHiddenGames: public Ui_FormHiddenGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMHIDDENGAMES_H
