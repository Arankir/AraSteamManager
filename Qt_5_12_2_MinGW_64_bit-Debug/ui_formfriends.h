/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
    QLabel *LabelLogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonReturn;
    QGroupBox *GroupBoxFilter;
    QGridLayout *gridLayout_2;
    QComboBox *ComboBoxStatus;
    QPushButton *ButtonFind;
    QCheckBox *CheckBoxOpenProfile;
    QCheckBox *CheckBoxFavorites;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *LineEditName;
    QTableWidget *TableWidgetFriends;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(825, 536);
        gridLayout_3 = new QGridLayout(FormFriends);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LabelLogo = new QLabel(FormFriends);
        LabelLogo->setObjectName(QString::fromUtf8("LabelLogo"));

        gridLayout_3->addWidget(LabelLogo, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        ButtonReturn = new QPushButton(FormFriends);
        ButtonReturn->setObjectName(QString::fromUtf8("ButtonReturn"));

        gridLayout_3->addWidget(ButtonReturn, 0, 2, 1, 1);

        GroupBoxFilter = new QGroupBox(FormFriends);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        gridLayout_2 = new QGridLayout(GroupBoxFilter);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ComboBoxStatus = new QComboBox(GroupBoxFilter);
        ComboBoxStatus->setObjectName(QString::fromUtf8("ComboBoxStatus"));

        gridLayout_2->addWidget(ComboBoxStatus, 1, 0, 1, 1);

        ButtonFind = new QPushButton(GroupBoxFilter);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));

        gridLayout_2->addWidget(ButtonFind, 0, 4, 1, 1);

        CheckBoxOpenProfile = new QCheckBox(GroupBoxFilter);
        CheckBoxOpenProfile->setObjectName(QString::fromUtf8("CheckBoxOpenProfile"));

        gridLayout_2->addWidget(CheckBoxOpenProfile, 1, 1, 1, 1);

        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        gridLayout_2->addWidget(CheckBoxFavorites, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        LineEditName = new QLineEdit(GroupBoxFilter);
        LineEditName->setObjectName(QString::fromUtf8("LineEditName"));

        gridLayout_2->addWidget(LineEditName, 0, 0, 1, 4);


        gridLayout_3->addWidget(GroupBoxFilter, 5, 0, 1, 3);

        TableWidgetFriends = new QTableWidget(FormFriends);
        if (TableWidgetFriends->columnCount() < 8)
            TableWidgetFriends->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        TableWidgetFriends->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        TableWidgetFriends->setObjectName(QString::fromUtf8("TableWidgetFriends"));
        TableWidgetFriends->setSortingEnabled(true);
        TableWidgetFriends->setColumnCount(8);

        gridLayout_3->addWidget(TableWidgetFriends, 6, 0, 1, 3);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        LabelLogo->setText(QApplication::translate("FormFriends", "Logo", nullptr));
        ButtonReturn->setText(QApplication::translate("FormFriends", "Return", nullptr));
        GroupBoxFilter->setTitle(QApplication::translate("FormFriends", "Filter", nullptr));
        ButtonFind->setText(QApplication::translate("FormFriends", "Find", nullptr));
        CheckBoxOpenProfile->setText(QApplication::translate("FormFriends", "Open profile", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormFriends", "Favorites", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableWidgetFriends->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormFriends", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableWidgetFriends->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormFriends", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableWidgetFriends->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FormFriends", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TableWidgetFriends->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FormFriends", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TableWidgetFriends->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FormFriends", "\320\237\321\200\320\270\320\262\320\260\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TableWidgetFriends->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FormFriends", "\320\260\320\271\320\264\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TableWidgetFriends->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FormFriends", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = TableWidgetFriends->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("FormFriends", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFriends: public Ui_FormFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDS_H
