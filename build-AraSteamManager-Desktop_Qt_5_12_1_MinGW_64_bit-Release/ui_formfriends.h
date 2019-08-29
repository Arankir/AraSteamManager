/********************************************************************************
** Form generated from reading UI file 'formfriends.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
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
    QLabel *FormFriendsLLogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *FormFriendsBReturn;
    QGroupBox *FormFriendsGBFilter;
    QGridLayout *gridLayout_2;
    QComboBox *FormFriendsCBStatus;
    QPushButton *FormFriendsBFind;
    QCheckBox *FormFriendsChBOpenProfile;
    QCheckBox *FormFriendsChBFavorites;
    QLineEdit *FormFriendsLineEditName;
    QTableWidget *FormFriendsTWFriends;

    void setupUi(QWidget *FormFriends)
    {
        if (FormFriends->objectName().isEmpty())
            FormFriends->setObjectName(QString::fromUtf8("FormFriends"));
        FormFriends->resize(825, 536);
        gridLayout_3 = new QGridLayout(FormFriends);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FormFriendsLLogo = new QLabel(FormFriends);
        FormFriendsLLogo->setObjectName(QString::fromUtf8("FormFriendsLLogo"));

        gridLayout_3->addWidget(FormFriendsLLogo, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        FormFriendsBReturn = new QPushButton(FormFriends);
        FormFriendsBReturn->setObjectName(QString::fromUtf8("FormFriendsBReturn"));

        gridLayout_3->addWidget(FormFriendsBReturn, 0, 2, 1, 1);

        FormFriendsGBFilter = new QGroupBox(FormFriends);
        FormFriendsGBFilter->setObjectName(QString::fromUtf8("FormFriendsGBFilter"));
        gridLayout_2 = new QGridLayout(FormFriendsGBFilter);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FormFriendsCBStatus = new QComboBox(FormFriendsGBFilter);
        FormFriendsCBStatus->setObjectName(QString::fromUtf8("FormFriendsCBStatus"));

        gridLayout_2->addWidget(FormFriendsCBStatus, 1, 0, 1, 1);

        FormFriendsBFind = new QPushButton(FormFriendsGBFilter);
        FormFriendsBFind->setObjectName(QString::fromUtf8("FormFriendsBFind"));

        gridLayout_2->addWidget(FormFriendsBFind, 0, 3, 1, 1);

        FormFriendsChBOpenProfile = new QCheckBox(FormFriendsGBFilter);
        FormFriendsChBOpenProfile->setObjectName(QString::fromUtf8("FormFriendsChBOpenProfile"));

        gridLayout_2->addWidget(FormFriendsChBOpenProfile, 1, 1, 1, 1);

        FormFriendsChBFavorites = new QCheckBox(FormFriendsGBFilter);
        FormFriendsChBFavorites->setObjectName(QString::fromUtf8("FormFriendsChBFavorites"));

        gridLayout_2->addWidget(FormFriendsChBFavorites, 1, 2, 1, 1);

        FormFriendsLineEditName = new QLineEdit(FormFriendsGBFilter);
        FormFriendsLineEditName->setObjectName(QString::fromUtf8("FormFriendsLineEditName"));

        gridLayout_2->addWidget(FormFriendsLineEditName, 0, 0, 1, 3);


        gridLayout_3->addWidget(FormFriendsGBFilter, 5, 0, 1, 3);

        FormFriendsTWFriends = new QTableWidget(FormFriends);
        if (FormFriendsTWFriends->columnCount() < 8)
            FormFriendsTWFriends->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        FormFriendsTWFriends->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        FormFriendsTWFriends->setObjectName(QString::fromUtf8("FormFriendsTWFriends"));
        FormFriendsTWFriends->setSortingEnabled(true);
        FormFriendsTWFriends->setColumnCount(8);

        gridLayout_3->addWidget(FormFriendsTWFriends, 6, 0, 1, 3);


        retranslateUi(FormFriends);

        QMetaObject::connectSlotsByName(FormFriends);
    } // setupUi

    void retranslateUi(QWidget *FormFriends)
    {
        FormFriends->setWindowTitle(QCoreApplication::translate("FormFriends", "SteamAchievementsStatistic", nullptr));
        FormFriendsLLogo->setText(QCoreApplication::translate("FormFriends", "Logo", nullptr));
        FormFriendsBReturn->setText(QCoreApplication::translate("FormFriends", "Return", nullptr));
        FormFriendsGBFilter->setTitle(QCoreApplication::translate("FormFriends", "Filter", nullptr));
        FormFriendsBFind->setText(QCoreApplication::translate("FormFriends", "Find", nullptr));
        FormFriendsChBOpenProfile->setText(QCoreApplication::translate("FormFriends", "Open profile", nullptr));
        FormFriendsChBFavorites->setText(QCoreApplication::translate("FormFriends", "Favorites", nullptr));
        QTableWidgetItem *___qtablewidgetitem = FormFriendsTWFriends->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FormFriends", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = FormFriendsTWFriends->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FormFriends", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = FormFriendsTWFriends->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FormFriends", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = FormFriendsTWFriends->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("FormFriends", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = FormFriendsTWFriends->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("FormFriends", "\320\237\321\200\320\270\320\262\320\260\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = FormFriendsTWFriends->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("FormFriends", "\320\260\320\271\320\264\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = FormFriendsTWFriends->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("FormFriends", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = FormFriendsTWFriends->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("FormFriends", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFriends: public Ui_FormFriends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRIENDS_H
