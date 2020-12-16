/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFriends
{
public:
    QVBoxLayout *verticalLayout;
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
    QTableView *TableFriends;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(825, 536);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormFriends->setFont(font);
        verticalLayout = new QVBoxLayout(FormFriends);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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
        ComboBoxStatus->setCurrentText(QString::fromUtf8(""));

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


        verticalLayout->addWidget(GroupBoxFilter);

        TableFriends = new QTableView(FormFriends);
        TableFriends->setObjectName(QString::fromUtf8("TableFriends"));

        verticalLayout->addWidget(TableFriends);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QCoreApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        GroupBoxFilter->setTitle(QCoreApplication::translate("FormFriends", "     \320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        LineEditName->setPlaceholderText(QCoreApplication::translate("FormFriends", "\320\235\320\260\320\271\321\202\320\270 \320\264\321\200\321\203\320\263\320\260", nullptr));
        ButtonFind->setText(QCoreApplication::translate("FormFriends", "  \320\237\320\276\320\270\321\201\320\272", nullptr));
        CheckBoxOpenProfile->setText(QCoreApplication::translate("FormFriends", "\320\237\321\203\320\261\320\273\320\270\321\207\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        CheckBoxFavorites->setText(QCoreApplication::translate("FormFriends", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFriends: public Ui_FormFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDS_H
