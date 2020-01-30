/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDS_H
#define UI_FORMFRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFriends
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *GroupBoxFilter;
    QVBoxLayout *_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LineEditName;
    QPushButton *ButtonFind;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *ComboBoxStatus;
    QCheckBox *CheckBoxOpenProfile;
    QCheckBox *CheckBoxFavorites;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *TableWidgetFriends;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(825, 536);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormFriends->setFont(font);
        verticalLayout_2 = new QVBoxLayout(FormFriends);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        GroupBoxFilter = new QGroupBox(FormFriends);
        GroupBoxFilter->setObjectName(QString::fromUtf8("GroupBoxFilter"));
        _2 = new QVBoxLayout(GroupBoxFilter);
        _2->setObjectName(QString::fromUtf8("_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LineEditName = new QLineEdit(GroupBoxFilter);
        LineEditName->setObjectName(QString::fromUtf8("LineEditName"));

        horizontalLayout_2->addWidget(LineEditName);

        ButtonFind = new QPushButton(GroupBoxFilter);
        ButtonFind->setObjectName(QString::fromUtf8("ButtonFind"));

        horizontalLayout_2->addWidget(ButtonFind);


        _2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ComboBoxStatus = new QComboBox(GroupBoxFilter);
        ComboBoxStatus->setObjectName(QString::fromUtf8("ComboBoxStatus"));

        horizontalLayout_3->addWidget(ComboBoxStatus);

        CheckBoxOpenProfile = new QCheckBox(GroupBoxFilter);
        CheckBoxOpenProfile->setObjectName(QString::fromUtf8("CheckBoxOpenProfile"));

        horizontalLayout_3->addWidget(CheckBoxOpenProfile);

        CheckBoxFavorites = new QCheckBox(GroupBoxFilter);
        CheckBoxFavorites->setObjectName(QString::fromUtf8("CheckBoxFavorites"));

        horizontalLayout_3->addWidget(CheckBoxFavorites);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        _2->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(GroupBoxFilter);

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

        verticalLayout_2->addWidget(TableWidgetFriends);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        GroupBoxFilter->setTitle(QApplication::translate("FormFriends", "      \320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        LineEditName->setPlaceholderText(QApplication::translate("FormFriends", "\320\235\320\260\320\271\321\202\320\270 \320\264\321\200\321\203\320\263\320\260", nullptr));
        ButtonFind->setText(QApplication::translate("FormFriends", "  \320\237\320\276\320\270\321\201\320\272", nullptr));
        CheckBoxOpenProfile->setText(QApplication::translate("FormFriends", "\320\237\321\203\320\261\320\273\320\270\321\207\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        CheckBoxFavorites->setText(QApplication::translate("FormFriends", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
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
