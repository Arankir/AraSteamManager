/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRIENDS_H
#define UI_FORMFRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subWidgets/lineEdit/mylineedit.h"
#include "subWidgets/tables/mytable.h"

QT_BEGIN_NAMESPACE

class Ui_FormFriends
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QFrame *frameFilter;
    QVBoxLayout *_2;
    QHBoxLayout *horizontalLayout_2;
    MyLineEdit *lineEditName;
    QPushButton *buttonFind;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxStatus;
    QCheckBox *checkBoxOpenProfile;
    QCheckBox *checkBoxFavorites;
    QSpacerItem *horizontalSpacer_2;
    MyTable *tableFriends;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(366, 292);
        verticalLayout = new QVBoxLayout(FormFriends);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(FormFriends);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        frameFilter = new QFrame(splitter);
        frameFilter->setObjectName(QString::fromUtf8("frameFilter"));
        _2 = new QVBoxLayout(frameFilter);
        _2->setObjectName(QString::fromUtf8("_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditName = new MyLineEdit(frameFilter);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        horizontalLayout_2->addWidget(lineEditName);

        buttonFind = new QPushButton(frameFilter);
        buttonFind->setObjectName(QString::fromUtf8("buttonFind"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonFind->sizePolicy().hasHeightForWidth());
        buttonFind->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(buttonFind);


        _2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBoxStatus = new QComboBox(frameFilter);
        comboBoxStatus->setObjectName(QString::fromUtf8("comboBoxStatus"));
        comboBoxStatus->setCurrentText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(comboBoxStatus);

        checkBoxOpenProfile = new QCheckBox(frameFilter);
        checkBoxOpenProfile->setObjectName(QString::fromUtf8("checkBoxOpenProfile"));

        horizontalLayout_3->addWidget(checkBoxOpenProfile);

        checkBoxFavorites = new QCheckBox(frameFilter);
        checkBoxFavorites->setObjectName(QString::fromUtf8("checkBoxFavorites"));

        horizontalLayout_3->addWidget(checkBoxFavorites);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        _2->addLayout(horizontalLayout_3);

        splitter->addWidget(frameFilter);
        tableFriends = new MyTable(splitter);
        tableFriends->setObjectName(QString::fromUtf8("tableFriends"));
        splitter->addWidget(tableFriends);

        verticalLayout->addWidget(splitter);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QCoreApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        lineEditName->setPlaceholderText(QCoreApplication::translate("FormFriends", "LuckyGuy1337", nullptr));
        buttonFind->setText(QCoreApplication::translate("FormFriends", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        checkBoxOpenProfile->setText(QCoreApplication::translate("FormFriends", "\320\237\321\203\320\261\320\273\320\270\321\207\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        checkBoxFavorites->setText(QCoreApplication::translate("FormFriends", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFriends: public Ui_FormFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDS_H
