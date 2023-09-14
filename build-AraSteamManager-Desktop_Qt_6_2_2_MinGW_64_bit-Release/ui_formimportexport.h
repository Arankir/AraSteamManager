/********************************************************************************
** Form generated from reading UI file 'formimportexport.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMPORTEXPORT_H
#define UI_FORMIMPORTEXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormImportExport
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidgetExport;
    QPushButton *ButtonExport;
    QPushButton *ButtonImport;

    void setupUi(QWidget *FormImportExport)
    {
        if (FormImportExport->objectName().isEmpty())
            FormImportExport->setObjectName(QString::fromUtf8("FormImportExport"));
        FormImportExport->resize(400, 417);
        verticalLayout = new QVBoxLayout(FormImportExport);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidgetExport = new QTreeWidget(FormImportExport);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetExport->setHeaderItem(__qtreewidgetitem);
        treeWidgetExport->setObjectName(QString::fromUtf8("treeWidgetExport"));
        treeWidgetExport->header()->setVisible(false);

        verticalLayout->addWidget(treeWidgetExport);

        ButtonExport = new QPushButton(FormImportExport);
        ButtonExport->setObjectName(QString::fromUtf8("ButtonExport"));

        verticalLayout->addWidget(ButtonExport);

        ButtonImport = new QPushButton(FormImportExport);
        ButtonImport->setObjectName(QString::fromUtf8("ButtonImport"));

        verticalLayout->addWidget(ButtonImport);


        retranslateUi(FormImportExport);

        QMetaObject::connectSlotsByName(FormImportExport);
    } // setupUi

    void retranslateUi(QWidget *FormImportExport)
    {
        FormImportExport->setWindowTitle(QCoreApplication::translate("FormImportExport", "Form", nullptr));
        ButtonExport->setText(QCoreApplication::translate("FormImportExport", "Export", nullptr));
        ButtonImport->setText(QCoreApplication::translate("FormImportExport", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormImportExport: public Ui_FormImportExport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMPORTEXPORT_H
