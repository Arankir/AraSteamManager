/********************************************************************************
** Form generated from reading UI file 'formfavorites.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFAVORITES_H
#define UI_FORMFAVORITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFavorites
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioButton;
    QWidget *tab_2;
    QCheckBox *checkBox;
    QWidget *tab_3;
    QPushButton *pushButton;

    void setupUi(QWidget *FormFavorites)
    {
        if (FormFavorites->objectName().isEmpty())
            FormFavorites->setObjectName(QString::fromUtf8("FormFavorites"));
        FormFavorites->resize(639, 381);
        verticalLayout = new QVBoxLayout(FormFavorites);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FormFavorites);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 84, 19));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 10, 72, 19));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 80, 21));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(FormFavorites);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormFavorites);
    } // setupUi

    void retranslateUi(QWidget *FormFavorites)
    {
        FormFavorites->setWindowTitle(QApplication::translate("FormFavorites", "Form", nullptr));
        radioButton->setText(QApplication::translate("FormFavorites", "RadioButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormFavorites", "Games", nullptr));
        checkBox->setText(QApplication::translate("FormFavorites", "CheckBox", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormFavorites", "Friends", nullptr));
        pushButton->setText(QApplication::translate("FormFavorites", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FormFavorites", "Achievements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFavorites: public Ui_FormFavorites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFAVORITES_H
