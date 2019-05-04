/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDS_H
#define UI_FORMFRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFriends
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QTableWidget *tableWidget;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(758, 536);
        gridLayout_3 = new QGridLayout(FormFriends);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(FormFriends);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton = new QPushButton(FormFriends);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 2, 1, 1);

        groupBox = new QGroupBox(FormFriends);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 2, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 5, 0, 1, 3);

        tableWidget = new QTableWidget(FormFriends);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setColumnCount(7);

        gridLayout_3->addWidget(tableWidget, 6, 0, 1, 3);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        label->setText(QApplication::translate("FormFriends", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("FormFriends", "PushButton", nullptr));
        groupBox->setTitle(QApplication::translate("FormFriends", "GroupBox", nullptr));
        pushButton_2->setText(QApplication::translate("FormFriends", "PushButton", nullptr));
        checkBox->setText(QApplication::translate("FormFriends", "CheckBox", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormFriends", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormFriends", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FormFriends", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FormFriends", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FormFriends", "\320\237\321\200\320\270\320\262\320\260\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FormFriends", "\320\260\320\271\320\264\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FormFriends", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFriends: public Ui_FormFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDS_H
