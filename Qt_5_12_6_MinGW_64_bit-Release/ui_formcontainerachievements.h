/********************************************************************************
** Form generated from reading UI file 'formcontainerachievements.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCONTAINERACHIEVEMENTS_H
#define UI_FORMCONTAINERACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormContainerAchievements
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *TabWidgetAchievements;

    void setupUi(QWidget *FormContainerAchievements)
    {
        if (FormContainerAchievements->objectName().isEmpty())
            FormContainerAchievements->setObjectName(QString::fromUtf8("FormContainerAchievements"));
        FormContainerAchievements->resize(738, 753);
        QFont font;
        font.setFamily(QString::fromUtf8("Ebrima"));
        FormContainerAchievements->setFont(font);
        verticalLayout = new QVBoxLayout(FormContainerAchievements);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TabWidgetAchievements = new QTabWidget(FormContainerAchievements);
        TabWidgetAchievements->setObjectName(QString::fromUtf8("TabWidgetAchievements"));
        TabWidgetAchievements->setDocumentMode(true);
        TabWidgetAchievements->setTabsClosable(true);
        TabWidgetAchievements->setMovable(true);

        verticalLayout->addWidget(TabWidgetAchievements);


        retranslateUi(FormContainerAchievements);

        TabWidgetAchievements->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FormContainerAchievements);
    } // setupUi

    void retranslateUi(QWidget *FormContainerAchievements)
    {
        FormContainerAchievements->setWindowTitle(QApplication::translate("FormContainerAchievements", "AraSteamManager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormContainerAchievements: public Ui_FormContainerAchievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCONTAINERACHIEVEMENTS_H
